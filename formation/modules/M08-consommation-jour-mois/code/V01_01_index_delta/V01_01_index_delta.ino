/*
 * M08-V01-01 : deltas a partir d'index fictifs en Wh.
 * Aucune RTC, aucun PZEM, aucun secteur.
 */
#include <Arduino.h>
const uint32_t indexWh[]={120400UL,120650UL,120650UL,120900UL,121100UL};
const uint8_t N=sizeof(indexWh)/sizeof(indexWh[0]);
void setup() {
  Serial.begin(9600);
  Serial.println(F("SIMULATION M08 : calcul delta Wh"));
  uint32_t precedent=indexWh[0],total=0;
  for(uint8_t i=1;i<N;i++){
    if(indexWh[i]<precedent) {
      Serial.println(F("ERREUR : index descendu"));
      break;
    }
    uint32_t delta=indexWh[i]-precedent;
    total+=delta; precedent=indexWh[i];
    Serial.print(F("deltaWh="));Serial.print(delta);
    Serial.print(F(" totalWh="));Serial.println(total);
  }
  Serial.print(F("Energie depuis debut, kWh="));
  Serial.println(total/1000.0f,3); // 0.700 kWh
}
void loop() {}
