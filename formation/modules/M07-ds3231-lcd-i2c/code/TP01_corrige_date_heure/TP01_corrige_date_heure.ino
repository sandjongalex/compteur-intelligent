/*
 * M07 TP01 : afficher JJ/MM/AAAA HH:MM:SS depuis DS3231.
 * Ne pas regler l'horloge automatiquement. RTC non fiable = erreur.
 */
#include <Wire.h>
#include <RTClib.h>
RTC_DS3231 rtc;
bool fiable = false;
unsigned long precedent = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  fiable = rtc.begin() && !rtc.lostPower();
  if (!fiable) Serial.println(F("RTC ABSENTE OU NON REGLEE"));
}
void loop() {
  if (!fiable) return;
  unsigned long maintenant = millis();
  if (maintenant - precedent < 1000UL) return;
  precedent = maintenant;
  DateTime dt = rtc.now();
  if (!dt.isValid()) {
    Serial.println(F("Date invalide"));
    fiable = false;
    return;
  }
  char ligne[25];
  snprintf(ligne, sizeof(ligne), "%02u/%02u/%04u %02u:%02u:%02u",
    (unsigned)dt.day(), (unsigned)dt.month(), (unsigned)dt.year(),
    (unsigned)dt.hour(), (unsigned)dt.minute(), (unsigned)dt.second());
  Serial.println(ligne);
}
