/*
 * AlexTech Academy — M04-V01
 * Les données électriques ci-dessous sont entièrement FICTIVES.
 * Arduino Uno Rev3 ; moniteur série à 9600 bauds.
 */
const float WATTS_PAR_KW = 1000.0f;
const float puissanceW = 500.0f;
const float dureeHeures = 2.0f;

void setup() {
  Serial.begin(9600);

  float energieKWh = (puissanceW / WATTS_PAR_KW) * dureeHeures;
  Serial.print("Energie fictive : ");
  Serial.print(energieKWh, 3);
  Serial.println(" kWh");  // Attendu : 1.000 kWh
}

void loop() {
  // Rien à répéter dans cet exemple.
}
