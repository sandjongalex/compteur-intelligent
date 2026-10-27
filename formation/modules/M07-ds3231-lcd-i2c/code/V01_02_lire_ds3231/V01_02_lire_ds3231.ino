/*
 * M07-V01/2 : lecture DS3231 sans reinitialiser l'heure.
 * Librairie "RTClib" d'Adafruit + dependance BusIO.
 * Une horloge non initialisee doit etre REGLEE volontairement
 * avec l'autre sketch : ne pas fabriquer une date valide.
 */
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;
bool horlogeValide = false;
unsigned long dernierAffichage = 0;

void afficherDeuxChiffres(uint8_t n) {
  if (n < 10) Serial.print('0');
  Serial.print(n);
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println(F("ERREUR: DS3231 absent. Verifier I2C."));
    return;
  }
  if (rtc.lostPower()) {
    Serial.println(F("HEURE NON FIABLE. Executer V01_03 une seule fois."));
    return;
  }
  horlogeValide = true;
  Serial.println(F("DS3231 OK - heure locale configuree manuellement"));
}

void loop() {
  if (!horlogeValide) return;
  const unsigned long maintenant = millis();
  if (maintenant - dernierAffichage < 1000UL) return;
  dernierAffichage = maintenant;

  DateTime date = rtc.now();
  afficherDeuxChiffres(date.day()); Serial.print('/');
  afficherDeuxChiffres(date.month()); Serial.print('/');
  Serial.print(date.year()); Serial.print(' ');
  afficherDeuxChiffres(date.hour()); Serial.print(':');
  afficherDeuxChiffres(date.minute()); Serial.print(':');
  afficherDeuxChiffres(date.second());
  Serial.println();
}
