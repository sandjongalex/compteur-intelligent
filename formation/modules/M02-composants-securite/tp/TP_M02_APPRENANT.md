# M02 — Travaux pratiques : version apprenant

**Aucune manipulation secteur : uniquement inspection hors tension, simulation et vérification des documents.**

## TP 01 — Associer les composants à leur mission

**Durée conseillée :** 12 minutes hors vidéos.  
**Matériel :** photos des composants ou éléments posés sur une table **hors tension**, [nomenclature du module](../ressources/BOM_PRELIMINAIRE.md).

### Travail demandé

1. Associer chacun des composants suivants à sa fonction : ATmega328P, PZEM-004T, DS3231, LCD 20×4 I2C, FRAM, SIM800L, LED, bouton, buzzer.
2. Parmi ces éléments, identifier celui qui **n'est pas chargé de la mesure électrique**, mais de la communication GSM.
3. Identifier celui qui permet de disposer de la **date** et celui qui conserve des **données non volatiles**.
4. Trouver sur une photo ou un module réel son numéro de référence exact. Expliquer pourquoi cette référence doit être vérifiée avant un câblage.

**Livrable :** tableau « composant / mission / informations à vérifier ».

## TP 02 — Diagnostic de trois erreurs de sécurité

**Durée conseillée :** 15 minutes hors vidéos.  
**Matériel :** [fiche de sécurité](../ressources/CHECKLIST_SECURITE.md), trois situations écrites ci-dessous.

### Scénarios (NE PAS LES REPRODUIRE)

- **A :** un apprenant propose d'appliquer directement **5 V sur VBAT** d'un SIM800L nu.
- **B :** un apprenant veut faire des essais de **230 V sur une breadboard**.
- **C :** un apprenant raccorde une sortie UART **5 V directement** à une entrée de modem dont les niveaux ne sont pas confirmés.

### Travail demandé

1. Pour chaque scénario, identifier le risque et expliquer la raison.
2. Proposer une **action sûre** qui ne nécessite **aucun raccordement au secteur**.
3. Choisir l'exercice suivant que le débutant peut effectuer : mesurer la phase secteur, manipuler une alimentation secteur ouverte, ou faire clignoter une LED sur Arduino Uno avec une alimentation basse tension sûre.

**Livrable :** tableau « erreur / risque / correction / autorisé au débutant ? ».

## Auto-évaluation

- [ ] Je reconnais tous les composants.
- [ ] Je distingue 5 V logique et environ 4 V modem.
- [ ] Je sais que le 230 V est réservé à une personne qualifiée.
- [ ] Je comprends que les tests de programmation peuvent commencer en basse tension.

[Corrigé du formateur](CORRIGE_M02_FORMATEUR.md) · [Quiz M02](../quiz/QUIZ_M02_APPRENANT.md)
