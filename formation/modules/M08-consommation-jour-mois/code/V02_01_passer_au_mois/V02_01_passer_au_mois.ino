/*
 * M08-V02-01 : 31 janvier -> 1er fevrier, SANS PZEM NI RTC.
 * Les dates et index sont fictifs. Source de verite : date + index Wh.
 * Le moteur indique COMPLET seulement si la base a 00:00:00 existe.
 */
#include <Arduino.h>
#include "EnergieM08.h"
SuiviEnergieM08 suivi;
const ReleveM08 echantillons[]={
 {{2026,1,31,23,58,0},120400UL,true},
 {{2026,1,31,23,59,0},120650UL,true}, // delta Jan 250 Wh
 {{2026,2,1,0,0,0},120660UL,true},   // nouveau mois base exacte a minuit
 {{2026,2,1,0,5,0},120700UL,true},   // fevrier 40 Wh
 {{2026,2,1,0,6,0},120740UL,true}    // fevrier 80 Wh
};
const char *status(ResultatM08 s) {
 switch(s){
 case M08_INITIALISE:return "BASE"; case M08_NOUVEAU_MOIS:return "MOIS";
 case M08_NOUVEAU_JOUR:return "JOUR"; case M08_AJOUT:return "OK";
 case M08_DOUBLON:return "DOUBLON"; case M08_INDEX_REINITIALISE:return "RESET INDEX";
 case M08_TEMPS_INCOHERENT:return "HEURE INVALIDE"; default:return "ERREUR";
 }
}
void setup(){
 Serial.begin(9600);
 Serial.println(F("SIMULATION frontiere 31/01 -> 01/02"));
 for(byte i=0;i<sizeof(echantillons)/sizeof(echantillons[0]);i++){
   ResultatM08 r=suivi.ajouter(echantillons[i]);
   Serial.print(F("Etat="));Serial.print(status(r));
   Serial.print(F(" | jour="));Serial.print(suivi.etat().jourWh);
   Serial.print(F(" Wh | mois="));Serial.print(suivi.etat().moisWh);
   Serial.print(F(" Wh | completJ="));Serial.print(suivi.etat().jourComplet);
   Serial.print(F(" completM="));Serial.println(suivi.etat().moisComplet);
 }
}
void loop(){}
