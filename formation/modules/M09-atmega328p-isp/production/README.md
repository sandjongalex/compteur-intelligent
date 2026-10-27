# M09 — Suivi pédagogique et production

**16 minutes (2 vidéos de 8 min), sans PowerPoint.** Les sources pédagogiques et le code sont rédigés ; le formateur assure vidéo, montage et publication.

## Livrables produits

- [x] Deux scripts détaillés alignés sur les manipulations et la continuité du firmware M08.
- [x] Deux programmes diagnostiques Arduino basse tension.
- [x] Snapshot firmware **M09** et courant synchronisés, moteur énergétique M08 inchangé.
- [x] Registre `firmware/manifest.json`, matrice de progression et contrôle non-régression actualisés.
- [x] Brochage ATmega328P **PDIP28**, tableau ISP et étapes ArduinoISP.
- [x] Deux TP apprenant et corrigés séparés.
- [x] Dix QCM corrigés avec JSON, difficulté 4/4/2.
- [x] Dépannage, ressources et plan de tests.

## Règle de continuité

[Contrat obligatoire](../../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md). **Le firmware M09 part de M08 : aucune fonction antérieure supprimée.** L'exercice de clignotement teste seulement le banc ; il ne remplace pas le compteur principal.

## Vérifications automatisées

- [ ] Tests sur GitHub Actions : contrat de progression et compilations M03–M09 ; reporter le lien/état après exécution.
- [ ] Taille Flash/RAM du firmware M09 en mode simulation sur `arduino:avr:uno`.
- [ ] Vérifier compilation `ALEXTECH_ATMEGA_AUTONOME 1` sur le profil Uno/16 MHz (séparément du mode défaut).
- [ ] Vérifier les programmes de diagnostic sur Uno.
- [ ] Contrôle des chemins/liens et cohérence quiz.

## Vérifications physiques encore nécessaires

- [ ] Vérifier les références matérielles et niveaux 5 V / masse / condensateurs / quartz.
- [ ] Charger ArduinoISP sur la Uno programmateur.
- [ ] Vérifier les six fils ISP et les fuses sans improvisation.
- [ ] Programmer une vraie puce ATmega328P PDIP28 par **Upload Using Programmer**.
- [ ] Vérifier LED extérieure sur PB5 broche19 et autonomie sans Uno programmateur.
- [ ] Vérifier UART via adaptateur USB–TTL compatible.
- [ ] Charger ensuite le même **firmware fil rouge M09** et retester LED, bouton, commandes, six valeurs fictives, cumuls jour/mois.
- [ ] Photographier les essais effectifs et noter résultats dans le [plan de tests](../ressources/PLAN_TESTS.md).
- [ ] Répéter et chronométrer 8 + 8 min avant enregistrement.

## À réaliser par le formateur

- [ ] Capturer les démonstrations réelles sur matériel vérifié, sans 230 V.
- [ ] Enregistrer les deux vidéos, monter et sous-titrer.
- [ ] Publier vidéos, TP et quiz sur AlexTech Academy.

**Statut : documents créés, compilation/tests automatiques à contrôler après CI, essais physiques et tournage non réalisés.**
