/*
 * AlexTech Academy — M04-V01
 * Démonstration de la division entière sur Arduino Uno Rev3 (AVR).
 */
void setup() {
  Serial.begin(9600);
  int resultatEntier = 5 / 2;          // 2 : division entre entiers
  float resultatDecimal = 5.0f / 2.0f; // 2.5 : division flottante

  Serial.print("5 / 2 = ");
  Serial.println(resultatEntier);
  Serial.print("5.0 / 2.0 = ");
  Serial.println(resultatDecimal, 1);
}

void loop() {}
