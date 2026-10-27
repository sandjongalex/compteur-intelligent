/*
 * AlexTech Academy - COMPTEUR INTELLIGENT, version fil rouge M04.
 *
 * CONSERVE M03 : LED L de l'Arduino Uno qui clignote.
 * AJOUT M04 : constantes, variables, calcul energetique FICTIF,
 * fonctions avec parametres, condition et moniteur serie.
 * M05 remplacera les delay() par millis() pour lire un bouton
 * et des commandes UART sans attente bloquante.
 *
 * Aucun PZEM, aucune tension secteur, aucune mesure reelle.
 */
#include <Arduino.h>

const unsigned long TEMPS_ALLUME_MS = 1000UL;
const unsigned long TEMPS_ETEINT_MS = 1000UL;
const float PUISSANCE_SIMULEE_W = 500.0f;
const float DUREE_SIMULEE_H = 2.0f;
const float WATTS_PAR_KILOWATT = 1000.0f;

float calculerEnergieKWh(float puissanceW, float heures) {
  // Puissance constante FICTIVE pendant l'intervalle choisi.
  return (puissanceW / WATTS_PAR_KILOWATT) * heures;
}

void commanderLED(bool allumer) {
  digitalWrite(LED_BUILTIN, allumer ? HIGH : LOW);
}

void afficherCalcul() {
  const float energie = calculerEnergieKWh(PUISSANCE_SIMULEE_W,
                                           DUREE_SIMULEE_H);
  Serial.print(F("Puissance SIMULEE : "));
  Serial.print(PUISSANCE_SIMULEE_W, 1);
  Serial.println(F(" W"));
  Serial.print(F("Duree SIMULEE : "));
  Serial.print(DUREE_SIMULEE_H, 1);
  Serial.println(F(" h"));
  Serial.print(F("Energie THEORIQUE fictive : "));
  Serial.print(energie, 3);
  Serial.println(F(" kWh")); // Attendu : 1.000 kWh
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // meme broche que M03
  Serial.begin(9600);          // nouvelle sortie pedagogique en M04
  Serial.println(F("FIL ROUGE M04 - LED M03 conservee"));
  afficherCalcul();            // exemple de fonction et de return
}

void loop() {
  commanderLED(true);  // l'ancienne LED est toujours utilisee
  delay(TEMPS_ALLUME_MS);
  commanderLED(false);
  delay(TEMPS_ETEINT_MS);
}
