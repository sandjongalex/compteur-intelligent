/*
 * AlexTech Academy - FIL ROUGE M06 (etend M05, sans regression).
 * Conserve : bouton D2-GND, LED integree, commandes UART USB, millis().
 * AJOUT M06 : 6 grandeurs, source de mesure, erreur explicite.
 *
 * 0 = SIMULATION : Uno USB SEULE, aucun secteur ou module PZEM.
 * 1 = REEL : UNIQUEMENT banc securise prepare par personne qualifiee.
 */
#include <Arduino.h>
#include <math.h>
#define ALEXTECH_PZEM_REEL 0
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
  dernierAffichage = millis();
#if ALEXTECH_PZEM_REEL
  Serial.println(F("M06 - PZEM REEL : BANC QUALIFIE UNIQUEMENT"));
#else
  Serial.println(F("M06 - SIX GRANDEURS SIMULEES - AUCUN PZEM"));
#endif
  Serial.println(F("Bouton D2-GND, commandes 1/0/?"));
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
