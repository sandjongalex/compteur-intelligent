/*
 * M07-V01/3 : REGLAGE MANUEL et VOLONTAIRE d'une RTC DS3231.
 * DANGER DE LOGIQUE : ne PAS utiliser ce sketch comme
 * firmware principal; le televersement suivant re-reglerait l'heure.
 * Renseigner une date/heure locale REELLE au moment de l'essai.
 * Verifier la pile ET la securite du module avant insertion.
 */
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;
// Par defaut : PROTECTION, ce sketch NE MODIFIE PAS L'HORLOGE.
const bool AUTORISER_REGLAGE_UNIQUE = false;
// Ces valeurs sont des EXEMPLES. A remplacer par l'heure locale
// correcte au moment du reglage. Ne pas les utiliser telles quelles.
const uint16_t ANNEE = 2026;
const uint8_t MOIS = 10, JOUR = 27;
const uint8_t HEURE = 12, MINUTE = 0, SECONDE = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println(F("ERREUR : DS3231 absent"));
    return;
  }
  if (!AUTORISER_REGLAGE_UNIQUE) {
    Serial.println(F("Reglage BLOQUE. Configurer l'heure, activer le drapeau, televerser une fois."));
    return;
  }
  DateTime voulue(ANNEE, MOIS, JOUR, HEURE, MINUTE, SECONDE);
  if (!voulue.isValid()) {
    Serial.println(F("Date invalide. Aucun reglage."));
    return;
  }
  rtc.adjust(voulue); // une fois lors de ce setup seulement
  Serial.println(F("Horloge reglee. TELEVERSER ensuite V01_02."));
}
void loop() {}
