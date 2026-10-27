#include "EnergieM08.h"
#include <assert.h>
#include <stdio.h>
static ReleveM08 R(int a,int m,int j,int h,int mn,int s,uint32_t wh,bool ok=true){
  ReleveM08 r={{(uint16_t)a,(uint8_t)m,(uint8_t)j,(uint8_t)h,(uint8_t)mn,(uint8_t)s},wh,ok};
  return r;
}
int main(){
 SuiviEnergieM08 t;
 assert(t.ajouter(R(2026,1,31,23,58,0,120400))==M08_INITIALISE);
 assert(!t.etat().jourComplet && !t.etat().moisComplet);
 assert(t.ajouter(R(2026,1,31,23,59,0,120650))==M08_AJOUT);
 assert(t.etat().jourWh==250 && t.etat().moisWh==250);
 assert(t.ajouter(R(2026,2,1,0,0,0,120660))==M08_NOUVEAU_MOIS);
 assert(t.etat().jourWh==0 && t.etat().moisWh==0);
 assert(t.etat().jourComplet && t.etat().moisComplet);
 assert(t.ajouter(R(2026,2,1,0,5,0,120700))==M08_AJOUT);
 assert(t.etat().jourWh==40 && t.etat().moisWh==40);
 EtatM08 etatRAM=t.etat();
 SuiviEnergieM08 reprise;
 assert(reprise.restaurerEtatRAM(etatRAM));
 assert(reprise.ajouter(R(2026,2,1,0,5,0,120700))==M08_DOUBLON);
 assert(reprise.etat().jourWh==40);
 assert(reprise.ajouter(R(2026,2,1,0,6,0,120740))==M08_AJOUT);
 assert(reprise.etat().jourWh==80 && reprise.etat().moisWh==80);
 assert(reprise.ajouter(R(2026,2,1,0,7,0,20))==M08_INDEX_REINITIALISE);
 assert(reprise.etat().jourWh==0 && !reprise.etat().jourComplet);
 assert(reprise.ajouter(R(2026,2,1,0,8,0,35))==M08_AJOUT);
 assert(reprise.etat().jourWh==15);
 assert(reprise.ajouter(R(2026,2,30,1,0,0,40))==M08_INVALIDE);
 assert(reprise.ajouter(R(2026,2,1,0,7,59,36))==M08_TEMPS_INCOHERENT);
 assert(reprise.ajouter(R(2026,2,1,0,9,0,36,false))==M08_INVALIDE);
 SuiviEnergieM08 b;
 b.ajouter(R(2026,2,1,0,0,0,1000));
 b.ajouter(R(2026,2,1,23,59,0,1500));
 assert(b.ajouter(R(2026,2,2,0,5,0,1530))==M08_NOUVEAU_JOUR);
 assert(b.etat().jourWh==0 && !b.etat().jourComplet);
 assert(b.etat().moisWh==530 && b.etat().moisComplet);
 assert(b.ajouter(R(2026,2,2,0,6,0,1540))==M08_AJOUT);
 assert(b.etat().jourWh==10 && b.etat().moisWh==540);
 SuiviEnergieM08 c;
 assert(c.ajouter(R(2028,2,29,23,59,0,200))==M08_INITIALISE);
 assert(c.ajouter(R(2028,3,1,0,0,0,220))==M08_NOUVEAU_MOIS);
 assert(c.etat().moisComplet);
 assert(c.ajouter(R(2028,3,1,0,0,0,220))==M08_DOUBLON);
 assert(c.ajouter(R(2028,3,1,0,0,0,221))==M08_TEMPS_INCOHERENT);
 assert(c.ajouter(R(2027,2,29,0,0,0,300))==M08_INVALIDE);
 puts("PASS M08: mois, jour, 29/02, doublons, reset, restauration RAM");
 return 0;
}
