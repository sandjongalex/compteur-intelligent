/*
 * AlexTech Academy - FIL ROUGE M07 (etend M06, sans regression).
 * Conserve : bouton D2-GND, LED integree, commandes UART USB, millis().
 * AJOUT M06 : 6 grandeurs et erreur de lecture.
 * AJOUT M07 : DS3231 + LCD I2C 20x4 sur bus partage.
 *
 * 0 = SIMULATION : Uno USB SEULE, aucun secteur ou module PZEM.
 * 1 = REEL : UNIQUEMENT banc securise prepare par personne qualifiee.
 */
#include <Arduino.h>
#include <math.h>
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

struct Mesures {
  float tensionV, courantA, puissanceW, energieKWh, frequenceHz, facteurPuissance;
};

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
  m = {230.5f, 0.500f, 92.2f, 12.345f, 50.0f, 0.80f};
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
  for (uint8_t i = 0; i < 20 && texte[i]; ++i) ligne[i] = texte[i];
  lcd.setCursor(0, num);
  lcd.print(ligne);
}
void mettreAJourLCD(const Mesures &m) {
  if (!lcdPret) return;
  if (rtcFiable && rtc.lostPower()) rtcFiable = false;
  char tampon[21];
  if (rtcFiable) {
    DateTime dt = rtc.now();
    if (!dt.isValid()) rtcFiable = false;
    else {
      snprintf(tampon, sizeof(tampon), "DATE: %02u/%02u/%04u",
        (unsigned)dt.day(), (unsigned)dt.month(), (unsigned)dt.year());
      ligneLCD(0, tampon);
    }
  }
  if (!rtcFiable) ligneLCD(0, "DATE: A REGLER");
  const uint16_t v10 = (uint16_t)(m.tensionV * 10.0f + 0.5f);
  snprintf(tampon, sizeof(tampon), "TENSION: %u.%u V",
    (unsigned)(v10 / 10), (unsigned)(v10 % 10));
  ligneLCD(1, tampon);
  ligneLCD(2, "JOUR: NON CALCULE");
  ligneLCD(3, "MOIS: NON CALCULE");
}
#endif

void afficherMesures(const Mesures &m) {
  Serial.print(F("Tension : ")); Serial.print(m.tensionV,1); Serial.println(F(" V"));
  Serial.print(F("Courant : ")); Serial.print(m.courantA,3); Serial.println(F(" A"));
  Serial.print(F("Puissance active : ")); Serial.print(m.puissanceW,1); Serial.println(F(" W"));
  Serial.print(F("Index : ")); Serial.print(m.energieKWh,3); Serial.println(F(" kWh"));
  Serial.print(F("Frequence : ")); Serial.print(m.frequenceHz,1); Serial.println(F(" Hz"));
  Serial.print(F("Facteur de puissance : ")); Serial.println(m.facteurPuissance,2);
#if ALEXTECH_RTC_LCD_REELS
  mettreAJourLCD(m);
#endif
}

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  appliquerLED();
  Serial.begin(9600);
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
  Serial.println(F("M07 - PZEM REEL : BANC QUALIFIE UNIQUEMENT"));
#else
  Serial.println(F("M07 - SIX GRANDEURS SIMULEES - AUCUN PZEM"));
#endif
  Serial.println(F("Bouton D2-GND, commandes 1/0/?")); 
#if !ALEXTECH_RTC_LCD_REELS
  Serial.println(F("RTC et LCD desactives : demo USB seule"));
#endif
}
void loop() {
  const unsigned long maintenant = millis();
  traiterBouton(maintenant);
  traiterCommandes();
  if ((unsigned long)(maintenant - dernierAffichage) >= AFFICHAGE_MS) {
    dernierAffichage = maintenant;
    Mesures m;
    if (lireMesures(m)) afficherMesures(m);
    else Serial.println(F("LECTURE INVALIDE : aucun nouveau releve"));
  }
}
