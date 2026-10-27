// Tests de maintenance M09 : valeurs fictives, provenance et dates.
// Ces tests n'attestent pas une validation physique sur le secteur.
#include "../courant/CompteurIntelligent/SimulationM09.h"
#include "../courant/CompteurIntelligent/EnergieM08.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
static ReleveM08 r(int y,int m,int d,int h,int mn,int s,uint32_t idx){
  ReleveM08 a={{(uint16_t)y,(uint8_t)m,(uint8_t)d,(uint8_t)h,(uint8_t)mn,(uint8_t)s},idx,true};
  return a;
}
int main(){
  SimulateurEnergieM09 sim;
  assert(sim.indexWh(0)==12345);
  assert(sim.indexWh(200)==12345); // Ancienne simulation : +1Wh, maintenant faux
  assert(sim.indexWh(3600000UL)==12437); // 92,2 Wh par heure
  assert(sim.indexWh(7200000UL)==12529); // 184,4 Wh en deux heures
  assert(sim.indexWh(36000000UL)==13267); // 922 Wh en dix heures

  // La difference non signee reste valide meme autour de millis() == 2^32.
  SimulateurEnergieM09 wrap;
  uint32_t avant=wrap.indexWh(UINT32_MAX-1000UL);
  uint32_t apres=wrap.indexWh(1000UL);
  assert(apres>=avant && apres-avant<=1UL);

  // Premiere observation tardive : pas de jour/mois marques complets.
  SuiviEnergieM08 t;
  assert(t.ajouter(r(2026,10,27,12,0,0,12345))==M08_INITIALISE);
  assert(!t.etat().jourComplet && !t.etat().moisComplet);
  assert(t.ajouter(r(2026,10,27,12,1,0,12347))==M08_AJOUT);
  assert(t.etat().jourWh==2 && t.etat().moisWh==2);

  // Changement de jour sans echantillon exact a minuit : jour partiel,
  // mais l'index du mois conserve les Wh franchissant minuit.
  assert(t.ajouter(r(2026,10,28,0,5,0,12387))==M08_NOUVEAU_JOUR);
  assert(t.etat().jourWh==0 && !t.etat().jourComplet);
  assert(t.etat().moisWh==42);
  assert(t.ajouter(r(2026,10,28,0,6,0,12390))==M08_AJOUT);
  assert(t.etat().jourWh==3 && t.etat().moisWh==45);

  // Premier index du mois pris en retard : jour et mois partiels.
  assert(t.ajouter(r(2026,11,1,0,2,0,12500))==M08_NOUVEAU_MOIS);
  assert(t.etat().jourWh==0 && t.etat().moisWh==0);
  assert(!t.etat().jourComplet && !t.etat().moisComplet);

  // Observation exacte a 00:00 => ancrage sans perte pour le NOUVEAU jour.
  assert(t.ajouter(r(2026,11,2,0,0,0,12540))==M08_NOUVEAU_JOUR);
  assert(t.etat().jourComplet && !t.etat().moisComplet);

  // Reset PZEM: apres nouvelle base, aucun total mensuel fiable.
  assert(t.ajouter(r(2026,11,2,0,5,0,5))==M08_INDEX_REINITIALISE);
  assert(!t.etat().jourComplet && !t.etat().moisComplet);

  // Heure incoherente : n'ecrase jamais l'etat valide.
  assert(t.ajouter(r(2026,11,2,0,4,0,6))==M08_TEMPS_INCOHERENT);
  assert(t.etat().dernierIndexWh==5);

  puts("PASS M09: 92.2W, rollover, jours/mois partiels, index reset, RTC time order");
  return 0;
}
