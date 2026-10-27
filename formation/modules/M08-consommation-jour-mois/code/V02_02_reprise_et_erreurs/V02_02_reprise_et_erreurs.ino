/*
 * M08-V02-02 : simulation de redemarrage ET erreurs.
 * Snapshot en RAM conserve volontairement pour la demonstration ;
 * apres une VRAIE coupure RAM, ce snapshot est PERDU (FRAM = M11).
 */
#include <Arduino.h>
#include "EnergieM08.h"
SuiviEnergieM08 avant, apres;
void afficher(const char *nom, const SuiviEnergieM08 &s){
 Serial.print(nom);Serial.print(F(": JOUR "));
 Serial.print(s.etat().jourWh);Serial.print(F(" Wh, MOIS "));
 Serial.print(s.etat().moisWh);Serial.print(F(" Wh, complet="));
 Serial.println(s.etat().jourComplet ? F("oui"):F("partiel"));
}
void setup(){
 Serial.begin(9600);
 Serial.println(F("DEMO REDEMARRAGE : copie RAM uniquement"));
 avant.ajouter(ReleveM08{{2026,2,1,0,0,0},120660UL,true});
 avant.ajouter(ReleveM08{{2026,2,1,0,5,0},120700UL,true});
 EtatM08 sauvegardeRAM=avant.etat(); // pas de memoire persistante !
 if(!apres.restaurerEtatRAM(sauvegardeRAM)){
   Serial.println(F("ERREUR ETAT RAM"));return;
 }
 ResultatM08 dup=apres.ajouter(ReleveM08{{2026,2,1,0,5,0},120700UL,true});
 Serial.print(F("Repetition identique, code="));Serial.println((int)dup);
 apres.ajouter(ReleveM08{{2026,2,1,0,6,0},120740UL,true});
 afficher("Apres reprise",apres); // 80 Wh
 ResultatM08 recul=apres.ajouter(ReleveM08{{2026,2,1,0,7,0},20UL,true});
 Serial.print(F("Index descendu, code="));Serial.println((int)recul);
 afficher("Base invalidee",apres); // 0 partiel
 apres.ajouter(ReleveM08{{2026,2,1,0,8,0},35UL,true});
 afficher("Nouvelle progression",apres); // 15 partiel
 ResultatM08 heure=apres.ajouter(ReleveM08{{2026,1,31,23,59,0},100UL,true});
 Serial.print(F("Heure reculee, code="));Serial.println((int)heure);
}
void loop(){}
