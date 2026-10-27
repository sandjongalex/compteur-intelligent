/*
 * AlexTech Academy — M03-V02
 * Arduino Uno Rev3 : LED intégrée L, broche LED_BUILTIN (D13).
 * Aucune LED externe nécessaire.
 */
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // LED intégrée allumée
  delay(1000);                      // 1 seconde
  digitalWrite(LED_BUILTIN, LOW);   // LED intégrée éteinte
  delay(1000);                      // 1 seconde
}
