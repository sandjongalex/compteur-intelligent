/*
 * M07-V02/1 : premier texte sur LCD 20x4 avec adaptateur I2C.
 * Librairie hd44780 par Bill Perry / duinoWitchery.
 * Classe I2Cexp : detection auto de l'adresse et du mapping.
 * Aucune mesure secteur.
 */
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;
bool ecranPret = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  const int resultat = lcd.begin(20, 4);
  if (resultat != 0) {
    Serial.print(F("ERREUR LCD I2C, code="));
    Serial.println(resultat);
    return;
  }
  lcd.backlight();
  ecranPret = true;
  lcd.setCursor(0, 0); lcd.print(F("AlexTech Academy"));
  lcd.setCursor(0, 1); lcd.print(F("Compteur intelligent"));
  lcd.setCursor(0, 2); lcd.print(F("LCD 20 x 4 - I2C"));
  lcd.setCursor(0, 3); lcd.print(F("Aucune mesure reelle"));
}
void loop() {
  if (!ecranPret) return; // le texte reste affiche sans clignotement
}
