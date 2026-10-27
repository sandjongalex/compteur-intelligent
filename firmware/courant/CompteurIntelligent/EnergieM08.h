#ifndef ALEXTECH_M08_H
#define ALEXTECH_M08_H
#include <stdint.h>
/* M08 : index PZEM en Wh ENTIERS et horodatage local fiable.
 * Aucune allocation dynamique, aucun IO. La persistance FRAM vient en M11.
 * Convention : un delta traversant minuit n'est PAS invente/reparti entre jours.
 */
struct DateM08 { uint16_t annee; uint8_t mois, jour, heure, minute, seconde; };
struct ReleveM08 { DateM08 date; uint32_t indexWh; bool valide; };
enum ResultatM08 {
  M08_INVALIDE, M08_INITIALISE, M08_AJOUT, M08_NOUVEAU_JOUR,
  M08_NOUVEAU_MOIS, M08_DOUBLON, M08_TEMPS_INCOHERENT, M08_INDEX_REINITIALISE,
  M08_CUMUL_SATURE
};
struct EtatM08 {
  bool initialise;
  DateM08 derniereDate;
  uint32_t dernierIndexWh, jourWh, moisWh;
  bool jourComplet, moisComplet;
};
class SuiviEnergieM08 {
  EtatM08 e_;
  static bool bissextile(uint16_t a) {
    return (a%4==0) && (a%100!=0 || a%400==0);
  }
  static uint8_t joursMois(uint16_t a,uint8_t m) {
    const uint8_t j[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(m<1||m>12) return 0;
    return (m==2 && bissextile(a)) ? 29 : j[m-1];
  }
  static bool dateOK(const DateM08 &d) {
    return d.annee>=2000 && d.annee<=2099 &&
      d.mois>=1 && d.mois<=12 && d.jour>=1 &&
      d.jour<=joursMois(d.annee,d.mois) &&
      d.heure<24 && d.minute<60 && d.seconde<60;
  }
  static uint32_t jourCle(const DateM08 &d) {
    return (uint32_t)d.annee*10000UL+(uint32_t)d.mois*100UL+d.jour;
  }
  static uint32_t heureCle(const DateM08 &d) {
    return (uint32_t)d.heure*3600UL+(uint32_t)d.minute*60UL+d.seconde;
  }
  static bool minuit(const DateM08 &d) {
    return d.heure==0 && d.minute==0 && d.seconde==0;
  }
  void ancrer(const ReleveM08 &r,bool completAutorise) {
    e_.initialise=true; e_.derniereDate=r.date; e_.dernierIndexWh=r.indexWh;
    e_.jourWh=0; e_.moisWh=0;
    e_.jourComplet=completAutorise && minuit(r.date);
    e_.moisComplet=completAutorise && minuit(r.date) && r.date.jour==1;
  }
public:
  SuiviEnergieM08() { reinitialiserRAM(); }
  void reinitialiserRAM() {
    e_.initialise=false; e_.derniereDate=DateM08{2000,1,1,0,0,0};
    e_.dernierIndexWh=0; e_.jourWh=0; e_.moisWh=0;
    e_.jourComplet=false; e_.moisComplet=false;
  }
  const EtatM08 &etat() const {return e_;}
  // DEMONSTRATION DE REPRISE : une copie RAM n'est pas une ecriture FRAM.
  // En M11 : ajouter version, CRC, journal atomique et idempotence.
  bool restaurerEtatRAM(const EtatM08 &s) {
    if(!s.initialise || !dateOK(s.derniereDate) ||
       s.jourWh > s.moisWh || s.moisWh > s.dernierIndexWh) return false;
    e_=s; return true;
  }
  ResultatM08 ajouter(const ReleveM08 &r) {
    if(!r.valide || !dateOK(r.date)) return M08_INVALIDE;
    if(!e_.initialise) {ancrer(r,true);return M08_INITIALISE;}
    uint32_t avant=jourCle(e_.derniereDate), apres=jourCle(r.date);
    if(apres<avant || (apres==avant && heureCle(r.date)<heureCle(e_.derniereDate)))
      return M08_TEMPS_INCOHERENT;
    if(apres==avant && heureCle(r.date)==heureCle(e_.derniereDate))
      return r.indexWh==e_.dernierIndexWh ? M08_DOUBLON : M08_TEMPS_INCOHERENT;
    if(r.indexWh<e_.dernierIndexWh) {
      ancrer(r,false); // remise a zero du capteur : ancienne base perdue
      return M08_INDEX_REINITIALISE;
    }
    uint32_t deltaWh=r.indexWh-e_.dernierIndexWh;
    bool changeJour=apres!=avant;
    bool changeMois=r.date.annee!=e_.derniereDate.annee ||
                    r.date.mois!=e_.derniereDate.mois;
    // Aucun retour silencieux a zero des totaux uint32_t.
    if((!changeJour && deltaWh > UINT32_MAX-e_.jourWh) ||
       (!changeMois && deltaWh > UINT32_MAX-e_.moisWh)) {
      ancrer(r,false);
      return M08_CUMUL_SATURE;
    }
    if(changeJour) {
      // Sans releve precis a 00:00:00, nouveau jour PARTIEL.
      e_.jourWh=0; e_.jourComplet=minuit(r.date);
    } else e_.jourWh+=deltaWh;
    if(changeMois) {
      e_.moisWh=0; e_.moisComplet=(r.date.jour==1 && minuit(r.date));
    } else e_.moisWh+=deltaWh; // passage de JOUR dans le MEME mois : OK
    e_.derniereDate=r.date; e_.dernierIndexWh=r.indexWh;
    if(changeMois) return M08_NOUVEAU_MOIS;
    if(changeJour) return M08_NOUVEAU_JOUR;
    return M08_AJOUT;
  }
};
#endif
