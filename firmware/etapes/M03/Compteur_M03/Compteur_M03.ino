/*
 * AlexTech Academy - COMPTEUR INTELLIGENT, version fil rouge M03.
 *
 * PREMIERE FONCTION : faire clignoter la LED L integree de l'Arduino Uno.
 * C'est le point de depart du MEME firmware, enrichi ensuite en M04, M05...
 *
 * Matériel : Uno Rev3 + USB ; aucun secteur ni composant externe.
 */
#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   // D13 sur Uno, voyant de demonstration
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // voyant allume
  delay(1000);                     // attendre une seconde
  digitalWrite(LED_BUILTIN, LOW);  // voyant eteint
  delay(1000);                     // attendre une seconde
}
