/*
 * M09-V01 : verifier une carte ATmega328P 16 MHz en basse tension.
 * Si UNO : LED_BUILTIN = LED L de la carte.
 * Si PDIP28 seule : LED_BUILTIN = PB5 / broche 19 -> R 330 ohm -> LED -> GND.
 * Programme PEDAGOGIQUE autonome, distinct du firmware cumulatif M09.
 */
#include <Arduino.h>
const unsigned long INTERVALLE = 500UL;
unsigned long precedent=0;
bool etat=false;
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  Serial.begin(9600);
  Serial.println(F("M09 diagnostic : LED D13/PB5, basse tension uniquement"));
  Serial.print(F("F_CPU MHz="));
  Serial.println((unsigned long)(F_CPU/1000000UL));
}
void loop() {
  unsigned long maintenant=millis();
  if ((unsigned long)(maintenant-precedent)>=INTERVALLE) {
    precedent=maintenant;
    etat=!etat;
    digitalWrite(LED_BUILTIN,etat?HIGH:LOW);
    Serial.println(etat?F("LED ON"):F("LED OFF"));
  }
}
