/*
 * AlexTech Academy - FIL ROUGE M05
 * Bouton D2->GND + LED L + commandes USB + affichage periodique.
 * AUCUN PZEM, RTC, LCD ni branchement secteur.
 * Etape suivante M06 : une fonction de mesure remplacerait la valeur fictive.
 */
#include <Arduino.h>

const uint8_t PIN_BOUTON = 2;
const unsigned long REBOND_MS = 35UL;
const unsigned long AFFICHAGE_MS = 2000UL;
const float TENSION_FICTIVE = 230.5f;
bool ledAllumee = false;
int derniereLecture = HIGH, boutonStable = HIGH;
unsigned long dernierChangement = 0, dernierAffichage = 0;

void appliquerLED() {
  digitalWrite(LED_BUILTIN, ledAllumee ? HIGH : LOW);
}

void traiterBouton(unsigned long maintenant) {
  const int brut = digitalRead(PIN_BOUTON);
  if (brut != derniereLecture) dernierChangement = maintenant;
  if ((unsigned long)(maintenant - dernierChangement) >= REBOND_MS
      && brut != boutonStable) {
    boutonStable = brut;
    if (boutonStable == LOW) {
      ledAllumee = !ledAllumee;
      appliquerLED();
      Serial.println(F("Bouton : bascule de la LED"));
    }
  }
  derniereLecture = brut;
}

void traiterCommandes() {
  while (Serial.available() > 0) {
    const char commande = (char)Serial.read();
    if (commande == '\r' || commande == '\n') continue;
    if (commande == '1') ledAllumee = true;
    else if (commande == '0') ledAllumee = false;
    else if (commande == '?') {
      Serial.println(F("Aide : 1=ON 0=OFF ?=aide"));
      continue;
    } else {
      Serial.println(F("Commande inconnue"));
      continue;
    }
    appliquerLED();
    Serial.println(ledAllumee ? F("LED ON") : F("LED OFF"));
  }
}

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  appliquerLED();
  Serial.begin(9600);
  dernierAffichage = millis();
  Serial.println(F("FIL ROUGE M05 - TENSION SIMULEE - 9600 bauds"));
  Serial.println(F("Bouton D2-GND, commandes 1/0/?"));
}

void loop() {
  const unsigned long maintenant = millis();
  traiterBouton(maintenant);
  traiterCommandes();
  if ((unsigned long)(maintenant - dernierAffichage) >= AFFICHAGE_MS) {
    dernierAffichage = maintenant;
    Serial.print(F("Tension SIMULEE : "));
    Serial.print(TENSION_FICTIVE, 1);
    Serial.println(F(" V"));
  }
}
