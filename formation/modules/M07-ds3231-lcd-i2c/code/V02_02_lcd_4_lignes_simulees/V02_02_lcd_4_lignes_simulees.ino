/*
 * M07-V02/2 : quatre lignes avec valeurs FICTIVES.
 * N'utilise ni RTC ni PZEM ; sert a apprendre le formatage.
 * Valeurs "jour" / "mois" simulees : calcul reel au M08.
 */
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <stdio.h>
#include <string.h>

hd44780_I2Cexp lcd;

void ligneComplete(uint8_t rang, const char *contenu) {
  char tampon[21];
  memset(tampon, ' ', 20);
  tampon[20] = '\0';
  for (byte i = 0; i < 20 && contenu[i] != '\0'; ++i) tampon[i] = contenu[i];
  lcd.setCursor(0, rang);
  lcd.print(tampon); // remplace exactement une ligne sans lcd.clear()
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (lcd.begin(20, 4) != 0) {
    Serial.println(F("LCD absent : lancer I2CexpDiag"));
    return;
  }
  lcd.backlight();
  ligneComplete(0, "DATE: 27/10/2026");
  ligneComplete(1, "TENSION: 230.5 V");
  ligneComplete(2, "JOUR:    4.250 kWh");
  ligneComplete(3, "MOIS:  125.480 kWh");
  Serial.println(F("LCD: donnees entierement SIMULEES"));
}
void loop() {}
