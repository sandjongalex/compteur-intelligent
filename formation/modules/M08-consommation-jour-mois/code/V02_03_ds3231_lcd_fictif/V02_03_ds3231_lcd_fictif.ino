/*
 * M08-V02/3 : DS3231 (DATE REELLE) + LCD 20x4.
 * INDEX PZEM et tension : SIMULATIONS, AUCUN SECTEUR !
 * RTC adaptee/reglee et LCD compatible en basse tension uniquement.
 * Le signe ~ signifie "periode incomplete" (demarrage apres minuit).
 *
 * RTClib (Adafruit) et hd44780 (Bill Perry / duinoWitchery).
 * Header EnergieM08.h dans CE dossier.
 */
#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <stdio.h>
#include <string.h>
#include "EnergieM08.h"

RTC_DS3231 rtc;
hd44780_I2Cexp lcd;
SuiviEnergieM08 suivi;
bool rtcFiable=false, lcdPret=false;
uint32_t indexFictifWh=120400UL;
unsigned long dernierEssaiMs=0;
const unsigned long PERIODE_MS=5000UL;

void ligne(uint8_t n,const char *message) {
  char tampon[21];
  memset(tampon,' ',20); tampon[20]='\0';
  for(byte i=0;i<20 && message[i];i++) tampon[i]=message[i];
  lcd.setCursor(0,n);lcd.print(tampon);
}
void afficherWh(uint8_t n,const char *nom,uint32_t wh,bool complet) {
  char tampon[21];
  snprintf(tampon,sizeof(tampon),"%s%lu.%03lu kWh%c",
    nom,(unsigned long)(wh/1000UL),(unsigned long)(wh%1000UL),
    complet?' ':'~');
  ligne(n,tampon);
}
void setup(){
  Serial.begin(9600);
  Wire.begin();
  lcdPret=(lcd.begin(20,4)==0);
  if(!lcdPret){
    Serial.println(F("ERREUR LCD I2C"));return;
  }
  lcd.backlight();
  rtcFiable=rtc.begin() && !rtc.lostPower();
  ligne(0,rtcFiable?"DATE: lecture RTC":"DATE: A REGLER");
  ligne(1,"TENSION: 230.5 V");
  ligne(2,"JOUR: INDISPONIBLE");
  ligne(3,"MOIS: INDISPONIBLE");
  if(!rtcFiable) Serial.println(F("RTC ABSENTE/INVALIDE : pas de calcul"));
  Serial.println(F("IMPORTANT: tension/index SIMULES. ~ = partiel"));
  dernierEssaiMs=millis();
}
void loop(){
  if(!rtcFiable || !lcdPret) return;
  unsigned long maintenant=millis();
  if((unsigned long)(maintenant-dernierEssaiMs)<PERIODE_MS) return;
  dernierEssaiMs=maintenant;
  if(rtc.lostPower()){
    rtcFiable=false;ligne(0,"DATE: INVALIDE");
    ligne(2,"JOUR: INDISPONIBLE");ligne(3,"MOIS: INDISPONIBLE");
    Serial.println(F("RTC a perdu l'heure"));return;
  }
  DateTime dt=rtc.now();
  if(!dt.isValid()){
    rtcFiable=false;ligne(0,"DATE: INVALIDE");
    ligne(2,"JOUR: INDISPONIBLE");ligne(3,"MOIS: INDISPONIBLE");
    return;
  }
  // Simuler la consommation qui augmente ; RIEN n'est lu sur le PZEM.
  indexFictifWh+=10UL;
  ReleveM08 r={{dt.year(),dt.month(),dt.day(),
                dt.hour(),dt.minute(),dt.second()},indexFictifWh,true};
  ResultatM08 code=suivi.ajouter(r);
  if(code==M08_TEMPS_INCOHERENT || code==M08_INDEX_REINITIALISE){
    Serial.println(F("ANOMALIE : heure ou index, cumuls non fiables"));
  }
  char date[21];
  snprintf(date,sizeof(date),"DATE: %02u/%02u/%04u",
    (unsigned)dt.day(),(unsigned)dt.month(),(unsigned)dt.year());
  ligne(0,date);
  afficherWh(2,"JOUR: ",suivi.etat().jourWh,suivi.etat().jourComplet);
  afficherWh(3,"MOIS: ",suivi.etat().moisWh,suivi.etat().moisComplet);
  Serial.print(F("Index fictif Wh="));Serial.print(indexFictifWh);
  Serial.print(F(" code="));Serial.println((int)code);
}
