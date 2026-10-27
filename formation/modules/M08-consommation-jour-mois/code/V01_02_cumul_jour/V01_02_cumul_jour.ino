/*
 * M08-V01-02 : une JOURNEE fictive du 27/10/2026.
 * 00:00 120400 Wh puis 01h 120650 puis doublon, 02h 120900, 03h 121100.
 * Un doublon ne doit pas ajouter de consommation.
 */
#include <Arduino.h>
const uint32_t indexWh[]={120400UL,120650UL,120650UL,120900UL,121100UL};
uint32_t baseJourWh=0,precedentWh=0;
uint32_t totalJourWh=0;
void setup() {
 Serial.begin(9600);
 Serial.println(F("SIMULATION jour 27/10, debut a 00:00"));
 baseJourWh=indexWh[0]; precedentWh=indexWh[0];
 for(byte i=1;i<5;i++){
   if(indexWh[i]<precedentWh){Serial.println(F("INDEX ANORMAL"));return;}
   if(indexWh[i]==precedentWh){Serial.println(F("DOUBLON/INDEX IDENTIQUE : +0 Wh"));}
   totalJourWh+=indexWh[i]-precedentWh;
   precedentWh=indexWh[i];
   Serial.print(F("JOUR = "));
   Serial.print(totalJourWh);
   Serial.println(F(" Wh"));
 }
 Serial.print(F("Controle index final - base = "));
 Serial.print(precedentWh-baseJourWh);
 Serial.println(F(" Wh"));
}
void loop(){}
