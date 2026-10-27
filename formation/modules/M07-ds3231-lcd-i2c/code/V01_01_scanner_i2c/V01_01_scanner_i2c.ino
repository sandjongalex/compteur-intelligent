/*
 * AlexTech Academy M07-V01/1 : detecter les adresses I2C.
 * Arduino Uno Rev3 : SDA=A4, SCL=A5. Basse tension uniquement.
 * Relier les modules apres verification des tensions et hors USB.
 */
#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println(F("Scanner I2C - uniquement basse tension"));
}

void loop() {
  byte trouves = 0;
  for (byte adresse = 0x08; adresse <= 0x77; ++adresse) {
    Wire.beginTransmission(adresse);
    byte resultat = Wire.endTransmission();
    if (resultat == 0) {
      Serial.print(F("Appareil I2C a 0x"));
      if (adresse < 0x10) Serial.print('0');
      Serial.println(adresse, HEX);
      ++trouves;
    }
  }
  if (trouves == 0) Serial.println(F("Aucun appareil detecte."));
  Serial.println(F("--- Nouveau balayage dans 3 s ---"));
  delay(3000); // uniquement dans cet outil de diagnostic
}
