/*
 * M06-V02, adaptation REELLE reservee a un banc securise qualifie.
 * NE PAS alimenter ni raccorder le secteur soi-meme en tant que debutant.
 *
 * Necessite la bibliotheque "PZEM004Tv30" de mandulaj pour V3.0,
 * ainsi que SoftwareSerial sur l'Arduino Uno Rev3.
 * Liaisons LOGIQUES uniquement, a verifier par un professionnel :
 * SoftwareSerial RX Uno D10 <--- TX PZEM
 * SoftwareSerial TX Uno D11 ---> RX PZEM
 * Connexions d'alimentation/interface, isolation, modele exact,
 * et partie secteur : verification et mise en service QUALIFIEES.
 *
 * La partie metrologie PZEM ne fonctionne pas avec le seul USB :
 * ne pas diagnostiquer systematiquement une absence de mesure
 * comme une erreur logicielle lorsqu'on n'a pas de banc adapte.
 * Ne jamais appeler resetEnergy() dans cet exemple.
 */
#include <SoftwareSerial.h>
#include <PZEM004Tv30.h>
#include <math.h>

SoftwareSerial lienPzem(10, 11); // RX, TX sur UNO
PZEM004Tv30 pzem(lienPzem);

const unsigned long PERIODE_MS = 2000UL;
unsigned long dernierEssaiMs = 0;

struct Mesures {
  float tensionV, courantA, puissanceW, energieKWh, frequenceHz, facteurPuissance;
};

bool valeursValides(const Mesures &m) {
  return isfinite(m.tensionV) && isfinite(m.courantA) &&
         isfinite(m.puissanceW) && isfinite(m.energieKWh) &&
         isfinite(m.frequenceHz) && isfinite(m.facteurPuissance) &&
         m.tensionV >= 0.0f && m.courantA >= 0.0f &&
         m.puissanceW >= 0.0f && m.energieKWh >= 0.0f &&
         m.frequenceHz >= 0.0f &&
         m.facteurPuissance >= 0.0f && m.facteurPuissance <= 1.0f;
}

bool lireMesures(Mesures &m) {
  m.tensionV = pzem.voltage();
  m.courantA = pzem.current();
  m.puissanceW = pzem.power();
  m.energieKWh = pzem.energy();
  m.frequenceHz = pzem.frequency();
  m.facteurPuissance = pzem.pf();
  return valeursValides(m);
}

void setup() {
  Serial.begin(9600);
  dernierEssaiMs = millis();
  Serial.println(F("PZEM V3 : banc qualifie uniquement"));
}

void loop() {
  unsigned long maintenant = millis();
  if ((unsigned long)(maintenant - dernierEssaiMs) < PERIODE_MS) return;
  dernierEssaiMs = maintenant;

  Mesures m;
  if (!lireMesures(m)) {
    Serial.println(F("LECTURE INVALIDE : verifier banc, version, liaison, adresse"));
    return; // aucune valeur fausse ni precedente renvoyee comme nouvelle
  }
  Serial.print(F("Tension : ")); Serial.print(m.tensionV, 1); Serial.println(F(" V"));
  Serial.print(F("Courant : ")); Serial.print(m.courantA, 3); Serial.println(F(" A"));
  Serial.print(F("Puissance active : ")); Serial.print(m.puissanceW, 1); Serial.println(F(" W"));
  Serial.print(F("Index energie : ")); Serial.print(m.energieKWh, 3); Serial.println(F(" kWh"));
  Serial.print(F("Frequence : ")); Serial.print(m.frequenceHz, 1); Serial.println(F(" Hz"));
  Serial.print(F("Facteur de puissance : ")); Serial.println(m.facteurPuissance, 2);
  // La periode est indicative : les lectures serie de bibliotheque
  // peuvent prendre un certain temps et bloquer temporairement.
}
