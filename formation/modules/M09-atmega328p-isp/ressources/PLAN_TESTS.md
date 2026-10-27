# M09 — Plan de validation et preuves de non-régression

**Supports et tests automatisés possibles sans matériel, mais aucune validation physique ISP n'est revendiquée tant qu'elle n'est pas documentée.**

## Vérifications automatisées

- Contrat fil rouge : `python3 firmware/tests/test_contrat_evolution.py`. Doit reconnaître le nouveau snapshot M09 et le courant identique.
- Régression historique M03–M08 : `python3 firmware/tests/test_progression.py`.
- Moteur énergétique : `g++ -std=c++11 -Wall -Wextra -pedantic firmware/tests/test_m08.cpp -o /tmp/test_m08 && /tmp/test_m08`.
- Compilation cible AVR Uno 16 MHz **mode simulation** via GitHub Actions.
- Vérification de la compilation M09 avec option autonome `1` à réaliser séparément après bascule contrôlée, sans toucher aux snapshots distribués.

## Essais à noter

| ID | Opération | Résultat attendu | Effectué ? |
|---|---|---|---|
| T01 | Vérifier brochage DIP28 sur table et absence de court-circuit | Alimentation, horloge, RESET et ISP corrects | [ ] |
| T02 | Charger ArduinoISP sur la **Uno programmateur** | Téléversement normal réussi | [ ] |
| T03 | Programmer sketch diagnostic sur la **puce cible** avec ISP | Upload Using Programmer réussi | [ ] |
| T04 | Alimenter la cible de façon autonome | LED externe PB5 clignote à rythme attendu | [ ] |
| T05 | Programmer le **firmware cumulatif M09** sur cible | Téléversement ISP terminé, même code M08 enrichi | [ ] |
| T06 | Vérifier série **via USB–TTL adapté** | Commandes `1/0/?`, diagnostics M09, six valeurs simulées | [ ] |
| T07 | Bouton D2 et LED extérieure | Une bascule par appui ; commandes UART toujours fonctionnelles | [ ] |
| T08 | Laisser le compteur fonctionner plusieurs périodes | Index simulé et cumuls jour/mois marqués partiels si base tardive | [ ] |
| T09 | Diagnostic d'une erreur ISP sûre | Cause identifiée sans manipulation sous tension | [ ] |
| T10 | Vérifier fuses et horloge | Paramètres effectivement concordants, sans hypothèse non vérifiée | [ ] |

## Informations à archiver

- Date, référence exacte de l'ATmega328P (boîtier), provenance, identité de la carte Uno programmateur :
- Arduino IDE / AVR core / version du sketch ArduinoISP :
- Quartz, condensateurs de charge, tension mesurée et configuration fuse (si connue) :
- Log du téléversement via ISP (ou message d'erreur exact) :
- Photos des connexions et fonctionnement sur cible :
- Résultats T01–T10 :
- Simulation PZEM/RTC/LCD effectivement laissée à 0 ? :
- Bibliothèques, carte et paramètres :
- Tests avant/après M08/M09 et conclusion :
- Statut : compilation seulement / transfert confirmé / fonctionnement autonome confirmé / à corriger.

## Limites volontaires du module

- Le fonctionnement réel du PZEM secteur ne fait **pas** partie du TP ISP.
- Ni le GSM ni la sauvegarde FRAM ne sont disponibles au M09.
- Un ATmega328P nu ne fournit pas d'interface USB native ni une LED intégrée.
- Les TP utilisent le niveau basse tension et les protections adaptées, jamais une prise secteur.
