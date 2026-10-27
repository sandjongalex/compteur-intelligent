/*
 * AlexTech Academy — M03-V02
 * Arduino Uno Rev3, basse tension uniquement.
 * D8 -> résistance 330 ohms -> anode LED -> cathode LED -> GND.
 * Couper l'alimentation USB avant chaque modification des fils.
 */
const byte LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);       // D8 devient une sortie
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // Allumer
  delay(1000);                   // Garder allumé 1 s
  digitalWrite(LED_PIN, LOW);    // Éteindre
  delay(1000);                   // Garder éteint 1 s
}
