/*
 * M07 TP02 : ajouter une page "courant/puissance" fictive.
 * Bouton D2 -> GND, INPUT_PULLUP, anti-rebond 35 ms.
 * Pages 0/1 sur LCD 20x4, date rtc verifiee si disponible.
 * Aucune mesure reelle.
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
const byte BOUTON = 2;
const unsigned long ANTIREBOND = 35UL;
int dernierBrut = HIGH;
int stable = HIGH;
unsigned long changementMs = 0;
unsigned long prochainAffichageMs = 0;
byte page = 0;
byte pageDessinee = 255;

void ligne(uint8_t n, const char *t) {
  char tampon[21];
  memset(tampon, ' ', 20);
  tampon[20] = '\0';
  for (byte i=0; i<20 && t[i]; ++i) tampon[i] = t[i];
  lcd.setCursor(0, n); lcd.print(tampon);
}

void afficherPage() {
  if (page == 1) {
    ligne(0, "PAGE 2: DETAILS");
    ligne(1, "COURANT: 0.500 A");
    ligne(2, "PUISSANCE: 92.2 W");
    ligne(3, "DONNEES FICTIVES");
  } else {
    if (rtcFiable) {
      DateTime dt = rtc.now();
      if (dt.isValid()) {
        char titre[21];
        snprintf(titre, sizeof(titre), "DATE: %02u/%02u/%04u",
                 (unsigned)dt.day(), (unsigned)dt.month(), (unsigned)dt.year());
        ligne(0, titre);
      } else {
        rtcFiable = false;
        ligne(0, "DATE: INVALIDE");
      }
    } else ligne(0, "DATE: A REGLER");
    ligne(1, "TENSION: 230.5 V");
    ligne(2, "JOUR:    4.250 kWh");
    ligne(3, "MOIS:  125.480 kWh");
  }
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(BOUTON, INPUT_PULLUP);
  lcdPret = (lcd.begin(20,4) == 0);
  if (!lcdPret) {
    Serial.println(F("ERREUR LCD"));
    return;
  }
  lcd.backlight();
  rtcFiable = rtc.begin() && !rtc.lostPower();
  if (!rtcFiable) Serial.println(F("RTC NON FIABLE : date non affichee"));
  afficherPage();
  pageDessinee = page;
  prochainAffichageMs = millis();
}
void loop() {
  if (!lcdPret) return;
  unsigned long maintenant = millis();
  int brut = digitalRead(BOUTON);
  if (brut != dernierBrut) changementMs = maintenant;
  if ((unsigned long)(maintenant-changementMs) >= ANTIREBOND && brut != stable) {
    stable=brut;
    if (stable==LOW) page=(byte)(1-page);
  }
  dernierBrut=brut;
  if (page != pageDessinee || (unsigned long)(maintenant - prochainAffichageMs)>=1000UL) {
    afficherPage();
    pageDessinee=page;
    prochainAffichageMs=maintenant;
  }
}
