# M08 — Calculer les consommations journalières et mensuelles

**AlexTech Academy · 16 minutes (2 leçons de 8 min) · prérequis : M06 (PZEM) et M07 (DS3231/LCD).**

**État : scripts, code, quiz et exercices rédigés ; compilations Arduino et essais matériels restant à confirmer. Aucun PowerPoint.**

## Compétences attendues

1. Distinguer la puissance en W, l'énergie cumulée en Wh/kWh et un **delta d'index énergétique**.
2. Calculer `index nouveau - index précédent`, éviter les doublons et contrôler une diminution du compteur.
3. Utiliser la date du DS3231 pour séparer les kWh du jour et du mois.
4. Gérer correctement le passage à minuit, le changement de mois et les périodes **partielles**.
5. Expliquer pourquoi une copie d'état en RAM n'est **pas** une sauvegarde réelle après coupure.
6. Afficher une date de RTC et des cumuls **simulés** sur LCD 20×4, sans raccordement secteur.

## Vidéos (programmation progressive, aucun PowerPoint)

| Leçon | Durée | Script | Étapes du code |
|---|---:|---|---|
| [M08-V01 — Calculer l'énergie et comprendre les index](videos/V01-plan.md) | 8 min | [Script intégral](scripts/V01-script.md) | [Deltas fictifs](code/V01_01_index_delta/V01_01_index_delta.ino) → [Cumul du jour](code/V01_02_cumul_jour/V01_02_cumul_jour.ino) |
| [M08-V02 — Minuit, mois et redémarrages](videos/V02-plan.md) | 8 min | [Script intégral](scripts/V02-script.md) | [Passage janvier/février](code/V02_01_passer_au_mois/V02_01_passer_au_mois.ino) → [Reprise RAM simulée](code/V02_02_reprise_et_erreurs/V02_02_reprise_et_erreurs.ino) → [DS3231 + LCD fictif](code/V02_03_ds3231_lcd_fictif/V02_03_ds3231_lcd_fictif.ino) |

## Ressources de l'apprenant

- [Guide des exemples et limites techniques](code/README.md)
- [Mémo Wh, kWh, frontières de périodes](ressources/MEMO_INDEX_PERIODES.md)
- [TP01 et TP02, sans réponses](tp/TP_M08_APPRENANT.md)
- [Quiz de 10 QCM, sans réponses](quiz/QUIZ_M08_APPRENANT.md)
- [Dépannage et erreurs fréquentes](ressources/DEPANNAGE.md)

## Ressources du formateur

- [Corrigés et barèmes des TP](tp/CORRIGE_M08_FORMATEUR.md)
- [Correction détaillée des 10 QCM](quiz/CORRIGE_M08_FORMATEUR.md)
- [Banque de questions JSON](quiz/quiz_m08.json)
- [Plan de tests, passages de mois, doublons et redémarrages](ressources/PLAN_TESTS.md)
- [Tests C++ du moteur (sans Arduino)](code/tests/test_m08.cpp)
- [Intégration M06/M07/M08 et limites de précision](code/INTEGRATION_M06_M07_M08.md)
- [Suivi de préparation vidéo](production/README.md)

**Validation proposée :** quiz ≥ 8/10 et deux TP corrigés. Travail pratique effectué **en dehors des 16 minutes vidéo**.

## Interprétation honnête des valeurs

- Les sketchs envoient des **index PZEM fictifs** ; **aucun relevé secteur réel** n'est réalisé dans ce module.
- Le programme final utilise la **date réelle DS3231** si elle est fiable, mais sa tension et son index restent entièrement simulés. Le signe `~` sur LCD signale un cumul **partiel**.
- Un premier relevé après minuit ne suffit pas à connaître l'énergie depuis 00:00. Un delta traversant une frontière de date ne peut pas être réparti exactement entre les deux jours sans information supplémentaire.
- Le moteur teste la restauration d'une **copie RAM préservée pour l'exercice** ; le vrai stockage FRAM et l'anti-corruption arriveront au **M11**.
- La remise à zéro quotidienne via `pzem.resetEnergy()` est **interdite par la logique retenue** ; conserver l'index cumulatif.

[Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md) · [Plan de formation 4 h](../../../docs/formation/PLAN_FORMATION_4H.md)
