/*
 * M07-V02/3 : DS3231 REELLE + valeurs electriques SIMULEES.
 * Deux appareils sur le meme bus I2C : RTC 0x68 + LCD autodetecte.
 * Aucun PZEM et aucun branchement au secteur.
 *
 * Date non fiable ? afficher A REGLER, jamais une fausse date.
 * Pas de lcd.clear() dans loop : remplace seulement la ligne modifiee.
 * Jour et mois : VALEURS FICTIVES jusqu'au calcul du M08.
 */
#include <Wire.h>
#include <RTClib.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <stdio.h>
#include <string.h>

RTC_DS3231 rtc;
hd44780_I2Cexp lcd;
bool lcdPret = false;
bool rtcFiable = false;
unsigned long dernierRafraichissement = 0;

void ligneComplete(uint8_t rang, const char *contenu) {
  char tampon[21];
  memset(tampon, ' ', 20);
  tampon[20] = '\0';
  for (byte i = 0; i < 20 && contenu[i] != '\0'; ++i) tampon[i] = contenu[i];
  lcd.setCursor(0, rang);
  lcd.print(tampon);
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcdPret = (lcd.begin(20, 4) == 0);
  if (!lcdPret) {
    Serial.println(F("LCD introuvable : tester I2CexpDiag"));
    return;
  }
  lcd.backlight();
  rtcFiable = rtc.begin() && !rtc.lostPower();
  if (!rtcFiable) Serial.println(F("RTC ABSENTE OU HEURE PERDUE : date non fiable"));

  ligneComplete(0, "DATE: A REGLER");
  ligneComplete(1, "TENSION: 230.5 V");
  ligneComplete(2, "JOUR:    4.250 kWh");
  ligneComplete(3, "MOIS:  125.480 kWh");
  Serial.println(F("V / JOUR / MOIS : DONNEES FICTIVES"));
}

void loop() {
  if (!lcdPret || !rtcFiable) return;
  const unsigned long maintenant = millis();
  if (maintenant - dernierRafraichissement < 1000UL) return;
  dernierRafraichissement = maintenant;
  DateTime dt = rtc.now();
  if (!dt.isValid()) {
    rtcFiable = false;
    ligneComplete(0, "DATE: INVALIDE");
    Serial.println(F("RTC: date invalide"));
    return;
  }
  char dateLigne[21];
  snprintf(dateLigne, sizeof(dateLigne), "DATE: %02u/%02u/%04u",
           (unsigned)dt.day(), (unsigned)dt.month(), (unsigned)dt.year());
  ligneComplete(0, dateLigne); // seule la ligne date est mise a jour
}
