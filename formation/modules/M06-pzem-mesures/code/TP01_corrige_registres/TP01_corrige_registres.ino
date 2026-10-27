/*
 * CORRIGE TP01 M06, sans PZEM ni secteur.
 * Modifie les donnees brutes puis confirme la conversion des unites.
 */
const uint16_t registres[10] = {
  2312, // tension 231.2 V
  750, 0, // courant 0.750 A
  1388, 0, // puissance 138.8 W (valeurs fictives)
  15300, 0, // index 15.300 kWh
  501, // frequence 50.1 Hz
  80, // facteur 0.80
  0  // aucune alarme
};
uint32_t composer32(uint16_t bas, uint16_t haut) {
  return ((uint32_t)haut << 16) | bas;
}
void setup() {
  Serial.begin(9600);
  Serial.println(F("REGISTRES FICTIFS, TP01"));
  Serial.print(F("V=")); Serial.println(registres[0] / 10.0f, 1);
  Serial.print(F("I=")); Serial.println(composer32(registres[1],registres[2])/1000.0f,3);
  Serial.print(F("P=")); Serial.println(composer32(registres[3],registres[4])/10.0f,1);
  Serial.print(F("E kWh=")); Serial.println(composer32(registres[5],registres[6])/1000.0f,3);
  Serial.print(F("f=")); Serial.println(registres[7]/10.0f,1);
  Serial.print(F("PF=")); Serial.println(registres[8]/100.0f,2);
}
void loop() {}
