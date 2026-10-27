/*
 * AlexTech Academy - FIL ROUGE M09 (reprend M08, pour ATmega328P autonome).
 * Conserve : bouton D2-GND, LED integree, commandes UART USB, millis().
 * AJOUT M06 : 6 grandeurs et erreur de lecture.
 * AJOUT M07 : DS3231 + LCD I2C 20x4 sur bus partage.
 * AJOUT M08 : energie jour/mois en Wh entiers, marqueur PARTIEL.
 * AJOUT M09 : cible ATmega328P PDIP 28 autonome, 16 MHz via ISP,
 * diagnostic du brochage, configuration explicite de l'horloge.
 * ATTENTION : circuit externe 5 V stable et quartz selon les fuses.
 * Default : source ET date SIMULEES ; AUCUN PZEM SECTEUR.
 *
 * 0 = SIMULATION : Uno USB SEULE, aucun secteur ou module PZEM.
 * 1 = REEL : UNIQUEMENT banc securise prepare par personne qualifiee.
 */
#include <Arduino.h>
#include <math.h>
#include "EnergieM08.h"
// 0 = Uno USB ; 1 = ATmega328P DIP-28 autonome 16 MHz / ISP.
// Le mode autonome ne change PAS les fonctions de comptage M08.
#define ALEXTECH_ATMEGA_AUTONOME 0
#if ALEXTECH_ATMEGA_AUTONOME
  #if !defined(__AVR_ATmega328P__)
    #error "Selectionner une cible ATmega328P compatible avec le firmware M09"
  #endif
  #if F_CPU != 16000000UL
    #error "M09 autonome : choisir le profil 16 MHz ET fournir une horloge compatible"
  #endif
#endif
#define ALEXTECH_PZEM_REEL 0
// 0 : comportement demonstration Arduino Uno USB seule.
// 1 : DS3231 et LCD compatible, en BASSE TENSION et apres validation.
#define ALEXTECH_RTC_LCD_REELS 0
#if ALEXTECH_RTC_LCD_REELS
  #include <Wire.h>
  #include <RTClib.h>
  #include <hd44780.h>
  #include <hd44780ioClass/hd44780_I2Cexp.h>
  #include <stdio.h>
  #include <string.h>
  RTC_DS3231 rtc;
  hd44780_I2Cexp lcd;
  bool rtcFiable = false, lcdPret = false;
#endif
#if ALEXTECH_PZEM_REEL
  #include <SoftwareSerial.h>
  #include <PZEM004Tv30.h>
  SoftwareSerial portPzem(10, 11); // RX/TX Arduino Uno, verifier interface
  PZEM004Tv30 pzem(portPzem);
#endif

const uint8_t PIN_BOUTON = 2;
const unsigned long REBOND_MS = 35UL;
const unsigned long AFFICHAGE_MS = 2000UL;
bool ledAllumee = false;
int derniereLecture = HIGH, boutonStable = HIGH;
unsigned long dernierChangement = 0, dernierAffichage = 0;
SuiviEnergieM08 suivi;
uint32_t dernierIndexSimuleWh = 12345UL; // source fictive seulement


struct Mesures {
  float tensionV, courantA, puissanceW, energieKWh, frequenceHz, facteurPuissance;
};

void afficherBrochageCible() {
#if ALEXTECH_ATMEGA_AUTONOME
  Serial.println(F("CIBLE: ATmega328P PDIP 28 / 16 MHz / ISP"));
  Serial.println(F("LED D13=PB5 broche 19, LED+resistance externe"));
  Serial.println(F("BOUTON D2=PD2 broche 4 vers GND"));
  Serial.println(F("UART RX=D0 pin2, TX=D1 pin3, USB-TTL 5V compatible"));
  Serial.println(F("ISP: RESET1, MOSI17, MISO18, SCK19, GND commun"));
#else
  Serial.println(F("CIBLE: Arduino Uno Rev3 / USB, simulation"));
#endif
  Serial.print(F("F_CPU (MHz)="));
  Serial.println((unsigned long)(F_CPU / 1000000UL));
}

void appliquerLED() { digitalWrite(LED_BUILTIN, ledAllumee ? HIGH : LOW); }

void traiterBouton(unsigned long maintenant) {
  const int brut = digitalRead(PIN_BOUTON);
  if (brut != derniereLecture) dernierChangement = maintenant;
  if ((unsigned long)(maintenant - dernierChangement) >= REBOND_MS && brut != boutonStable) {
    boutonStable = brut;
    if (boutonStable == LOW) {
      ledAllumee = !ledAllumee; appliquerLED();
      Serial.println(F("Bouton : bascule de la LED"));
    }
  }
  derniereLecture = brut;
}
void traiterCommandes() {
  while (Serial.available() > 0) {
    const char c = (char)Serial.read();
    if (c == '\r' || c == '\n') continue;
    if (c == '1') ledAllumee = true;
    else if (c == '0') ledAllumee = false;
    else if (c == '?') {
      Serial.println(F("Aide : 1=ON 0=OFF ?=aide"));
      continue;
    } else { Serial.println(F("Commande inconnue")); continue; }
    appliquerLED();
    Serial.println(ledAllumee ? F("LED ON") : F("LED OFF"));
  }
}

bool lireMesures(Mesures &m) {
#if ALEXTECH_PZEM_REEL
  m.tensionV = pzem.voltage();
  m.courantA = pzem.current();
  m.puissanceW = pzem.power();
  m.energieKWh = pzem.energy();
  m.frequenceHz = pzem.frequency();
  m.facteurPuissance = pzem.pf();
#else
  // Ces chiffres viennent UNIQUEMENT du programme, pas d'un capteur.
  dernierIndexSimuleWh = 12345UL + millis() / 200UL;
  m = {230.5f, 0.500f, 92.2f, dernierIndexSimuleWh / 1000.0f, 50.0f, 0.80f};
#endif
  return isfinite(m.tensionV) && isfinite(m.courantA) &&
         isfinite(m.puissanceW) && isfinite(m.energieKWh) &&
         isfinite(m.frequenceHz) && isfinite(m.facteurPuissance) &&
         m.tensionV >= 0 && m.courantA >= 0 && m.puissanceW >= 0 &&
         m.energieKWh >= 0 && m.frequenceHz >= 0 &&
         m.facteurPuissance >= 0 && m.facteurPuissance <= 1;
}
#if ALEXTECH_RTC_LCD_REELS
void ligneLCD(uint8_t num, const char *texte) {
  if (!lcdPret) return;
  char ligne[21];
  memset(ligne, ' ', 20);
  ligne[20] = '\0';
  for (uint8_t i=0; i<20 && texte[i]; ++i) ligne[i]=texte[i];
  lcd.setCursor(0, num);
  lcd.print(ligne);
}
void afficherCumulLCD(uint8_t rang, const char *nom, uint32_t wh, bool complet) {
  char texte[21];
  snprintf(texte, sizeof(texte), "%s%lu.%03lu kWh%c",
    nom, (unsigned long)(wh/1000UL), (unsigned long)(wh%1000UL),
    complet ? ' ' : '~'); // ~ = PARTIEL
  ligneLCD(rang, texte);
}
void mettreAJourLCD(const Mesures &m, const DateM08 &d, bool mesureValide) {
  if (!lcdPret) return;
  char texte[21];
  snprintf(texte, sizeof(texte), "DATE: %02u/%02u/%04u",
    (unsigned)d.jour, (unsigned)d.mois, (unsigned)d.annee);
  ligneLCD(0, texte);
  const uint16_t v10=(uint16_t)(m.tensionV * 10.0f + 0.5f);
  snprintf(texte, sizeof(texte), "TENSION: %u.%u V",
    (unsigned)(v10/10U), (unsigned)(v10%10U));
  ligneLCD(1, texte);
  if (!mesureValide) {
    ligneLCD(2, "JOUR: INDISPONIBLE");
    ligneLCD(3, "MOIS: INDISPONIBLE");
    return;
  }
  afficherCumulLCD(2, "JOUR: ", suivi.etat().jourWh, suivi.etat().jourComplet);
  afficherCumulLCD(3, "MOIS: ", suivi.etat().moisWh, suivi.etat().moisComplet);
}
#endif

// Si la RTC n'est pas activee : horloge logicielle FICTIVE pour apprendre.
// BASE DEMO 27/10/2026 12:00:00, avance avec millis et passe en novembre.
// Cette horloge n'est PAS FIABLE apres reboot, ni une sauvegarde durable.
DateM08 horlogeDemo(unsigned long tempsMs) {
  uint32_t sec=12UL*3600UL + tempsMs/1000UL;
  uint32_t jours=sec/86400UL;
  uint32_t reste=sec%86400UL;
  DateM08 d={2026,10,27,0,0,0};
  while (jours > 0) {
    --jours;
    ++d.jour;
    uint8_t finMois=(d.mois==10 || d.mois==12) ? 31U : 30U;
    if (d.jour > finMois) {
      d.jour=1; ++d.mois;
      if(d.mois>12){d.mois=1;++d.annee;}
    }
  }
  d.heure=(uint8_t)(reste/3600UL);
  d.minute=(uint8_t)((reste%3600UL)/60UL);
  d.seconde=(uint8_t)(reste%60UL);
  return d;
}
bool lireDate(DateM08 &d, unsigned long tempsMs) {
#if ALEXTECH_RTC_LCD_REELS
  (void)tempsMs;
  if (!rtcFiable || rtc.lostPower()) return false;
  DateTime t=rtc.now();
  if (!t.isValid()) return false;
  d=DateM08{(uint16_t)t.year(), (uint8_t)t.month(),(uint8_t)t.day(),
    (uint8_t)t.hour(),(uint8_t)t.minute(),(uint8_t)t.second()};
  return true;
#else
  d=horlogeDemo(tempsMs);
  return true; // date de simulation, PAS une heure physique
#endif
}
bool lireIndexWh(const Mesures &m, uint32_t &wh) {
#if ALEXTECH_PZEM_REEL
  // Approximation pour l'enseignement : precision float AVR limitee !
  // Production : privilegiers les registres d'index bruts en Wh.
  if (!isfinite(m.energieKWh) || m.energieKWh<0.0f ||
      m.energieKWh > 4294966.0f) return false;
  wh=(uint32_t)(m.energieKWh*1000.0f+0.5f);
#else
  (void)m;
  wh=dernierIndexSimuleWh;
#endif
  return true;
}

void afficherMesures(const Mesures &m) {
  Serial.print(F("Tension : ")); Serial.print(m.tensionV,1); Serial.println(F(" V"));
  Serial.print(F("Courant : ")); Serial.print(m.courantA,3); Serial.println(F(" A"));
  Serial.print(F("Puissance active : ")); Serial.print(m.puissanceW,1); Serial.println(F(" W"));
  Serial.print(F("Index : ")); Serial.print(m.energieKWh,3); Serial.println(F(" kWh"));
  Serial.print(F("Frequence : ")); Serial.print(m.frequenceHz,1); Serial.println(F(" Hz"));
  Serial.print(F("Facteur de puissance : ")); Serial.println(m.facteurPuissance,2);
}

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  appliquerLED();
  Serial.begin(9600);
  afficherBrochageCible();
  dernierAffichage = millis();
#if ALEXTECH_RTC_LCD_REELS
  Wire.begin();
  lcdPret = (lcd.begin(20, 4) == 0);
  if (lcdPret) lcd.backlight();
  else Serial.println(F("LCD I2C absent : affichage serie conserve"));
  rtcFiable = rtc.begin() && !rtc.lostPower();
  if (!rtcFiable) Serial.println(F("DS3231 absente/heure non fiable"));
#endif
#if ALEXTECH_PZEM_REEL
  Serial.println(F("M08 - PZEM REEL : BANC QUALIFIE UNIQUEMENT"));
#else
  Serial.println(F("M08 - GRANDEURS/INDEX SIMULES - AUCUN PZEM"));
#endif
  Serial.println(F("Bouton D2-GND, commandes 1/0/?"));
#if !ALEXTECH_RTC_LCD_REELS
  Serial.println(F("Date 27/10/2026 + millis = SIMULEE; JOUR/MOIS PARTIELS"));
#endif 
#if !ALEXTECH_RTC_LCD_REELS
  Serial.println(F("RTC et LCD desactives : demo USB seule"));
#endif
}
void loop() {
  const unsigned long maintenant=millis();
  traiterBouton(maintenant);
  traiterCommandes();
  if ((unsigned long)(maintenant-dernierAffichage)<AFFICHAGE_MS) return;
  dernierAffichage=maintenant;

  Mesures m;
  if (!lireMesures(m)) {
    Serial.println(F("LECTURE INVALIDE : aucun relevé ajouté aux cumuls"));
#if ALEXTECH_RTC_LCD_REELS
    ligneLCD(1,"MESURE INDISPONIBLE");
    ligneLCD(2,"JOUR: INDISPONIBLE");
    ligneLCD(3,"MOIS: INDISPONIBLE");
#endif
    return;
  }
  afficherMesures(m); // six grandeurs conservees depuis M06

  DateM08 date;
  if (!lireDate(date,maintenant)) {
    Serial.println(F("RTC ABSENTE/HEURE NON FIABLE : pas de calcul"));
#if ALEXTECH_RTC_LCD_REELS
    ligneLCD(0,"DATE: A REGLER");
    ligneLCD(2,"JOUR: INDISPONIBLE");
    ligneLCD(3,"MOIS: INDISPONIBLE");
#endif
    return;
  }
  uint32_t wh;
  if (!lireIndexWh(m,wh)) {
    Serial.println(F("INDEX NON CONVERTIBLE EN Wh : pas de calcul"));
#if ALEXTECH_RTC_LCD_REELS
    ligneLCD(2,"JOUR: INDISPONIBLE");
    ligneLCD(3,"MOIS: INDISPONIBLE");
#endif
    return;
  }
  ReleveM08 r={date,wh,true};
  ResultatM08 resultat=suivi.ajouter(r);
  if (resultat==M08_TEMPS_INCOHERENT || resultat==M08_INVALIDE) {
    Serial.println(F("DATE/INDEX INVALIDES : pas de nouveau cumul"));
#if ALEXTECH_RTC_LCD_REELS
    ligneLCD(0,"DATE: INCOHERENTE");
    ligneLCD(2,"JOUR: INDISPONIBLE");
    ligneLCD(3,"MOIS: INDISPONIBLE");
#endif
    return;
  }
  if(resultat==M08_INDEX_REINITIALISE)
    Serial.println(F("INDEX REINITIALISE : periodes marquees PARTIELLES"));

  Serial.print(F("Date : "));
  Serial.print(date.jour);Serial.print('/');Serial.print(date.mois);
  Serial.print('/');Serial.println(date.annee);
  Serial.print(F("Jour Wh="));Serial.print(suivi.etat().jourWh);
  Serial.print(suivi.etat().jourComplet ? F(" COMPLET") : F(" PARTIEL"));
  Serial.print(F(" | Mois Wh="));Serial.print(suivi.etat().moisWh);
  Serial.println(suivi.etat().moisComplet?F(" COMPLET"):F(" PARTIEL"));
#if ALEXTECH_RTC_LCD_REELS
  mettreAJourLCD(m,date,true);
#endif
}
