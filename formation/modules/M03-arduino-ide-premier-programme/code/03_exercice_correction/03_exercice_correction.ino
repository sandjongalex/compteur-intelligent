/*
 * AlexTech Academy — M03 TP02, correction.
 * LED externe sur D8 avec résistance 330 ohms en série.
 * Une période complète dure 1 seconde : 250 ms allumée, 750 ms éteinte.
 */
const byte LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(250);                      // LED allumée 0,25 seconde
  digitalWrite(LED_PIN, LOW);
  delay(750);                      // LED éteinte 0,75 seconde
}
