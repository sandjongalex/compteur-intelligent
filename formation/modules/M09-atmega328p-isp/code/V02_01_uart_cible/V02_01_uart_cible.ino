/*
 * M09-V02 : diagnostic liaison serie de la PUCE CIBLE apres ISP.
 * Cette puce n'a pas de port USB integre.
 * D0/PD0 (pin2 DIP28) <- TX adaptateur USB-TTL 5V compatible
 * D1/PD1 (pin3 DIP28) -> RX adaptateur USB-TTL
 * GND commun. Ne JAMAIS brancher de signaux RS-232 +/-12V directement.
 * Pour essayer ? / 1 / 0, utiliser le firmware fil rouge M09, pas ce test.
 */
#include <Arduino.h>
unsigned long tPrecedent=0;
void setup(){
  Serial.begin(9600);
  Serial.println(F("M09: serie UART cible, pas le port USB de la Uno ISP"));
}
void loop(){
  const unsigned long maintenant=millis();
  if((unsigned long)(maintenant-tPrecedent)>=2000UL){
    tPrecedent=maintenant;
    Serial.println(F("PUCE ATmega328P ACTIVE, HORLOGE ET TX A VERIFIER"));
  }
}
