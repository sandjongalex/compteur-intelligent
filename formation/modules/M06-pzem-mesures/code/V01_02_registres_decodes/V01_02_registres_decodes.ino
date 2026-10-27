/*
 * M06-V01, etape 2 : registre fictif compatible avec la carte
 * de registres d'entree PZEM-004T V3.0.
 * Ces mots sont DEFINIS DANS LE PROGRAMME, pas recus par UART.
 * 0x0000 V/10, 1-2 I/1000, 3-4 P/10,
 * 5-6 E en Wh, 7 Hz/10, 8 PF/100, 9 alarme.
 * Les quantites 32 bits utilisent un mot bas avant un mot haut.
 */
const uint16_t REGISTRES[10] = {
  2305,  // 0: 230.5 V
  500,   // 1: courant partie basse = 500 milliampere
  0,     // 2: courant partie haute
  922,   // 3: puissance partie basse = 92.2 W
  0,     // 4: puissance partie haute
  12345, // 5: energie partie basse = 12345 Wh
  0,     // 6: energie partie haute
  500,   // 7: frequence 50.0 Hz
  80,    // 8: facteur de puissance 0.80
  0      // 9: pas d'alarme
};

uint32_t assembler32(uint16_t bas, uint16_t haut) {
  return ((uint32_t)haut << 16) | (uint32_t)bas;
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("REGISTRES SIMULES - sans PZEM"));
  float tensionV = REGISTRES[0] / 10.0f;
  float courantA = assembler32(REGISTRES[1], REGISTRES[2]) / 1000.0f;
  float puissanceW = assembler32(REGISTRES[3], REGISTRES[4]) / 10.0f;
  float energieKWh = assembler32(REGISTRES[5], REGISTRES[6]) / 1000.0f;
  float frequenceHz = REGISTRES[7] / 10.0f;
  float facteurPuissance = REGISTRES[8] / 100.0f;

  Serial.print(F("Tension : ")); Serial.print(tensionV, 1); Serial.println(F(" V"));
  Serial.print(F("Courant : ")); Serial.print(courantA, 3); Serial.println(F(" A"));
  Serial.print(F("Puissance : ")); Serial.print(puissanceW, 1); Serial.println(F(" W"));
  Serial.print(F("Energie cumulee : ")); Serial.print(energieKWh, 3); Serial.println(F(" kWh"));
  Serial.print(F("Frequence : ")); Serial.print(frequenceHz, 1); Serial.println(F(" Hz"));
  Serial.print(F("Facteur de puissance : ")); Serial.println(facteurPuissance, 2);
}
void loop() {}
