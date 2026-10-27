/*
 * AlexTech Academy — M04 : exercice corrigé.
 * Puissance active fictive CONSTANTE. Aucune lecture secteur.
 */
float calculerEnergieKWh(float puissanceW, float dureeHeures) {
  return (puissanceW / 1000.0f) * dureeHeures;
}

void setup() {
  Serial.begin(9600);

  const float puissanceW = 200.0f;
  const float dureeHeures = 5.0f;

  float energieKWh = calculerEnergieKWh(puissanceW, dureeHeures);
  Serial.print("Energie : ");
  Serial.print(energieKWh, 3);
  Serial.println(" kWh"); // 1.000 kWh
}

void loop() {}
