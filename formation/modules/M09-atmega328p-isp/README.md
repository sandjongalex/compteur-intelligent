# M09 — Programmer l'ATmega328P autonome par ISP

**16 minutes de vidéo : M09-V01 = 8 min et M09-V02 = 8 min.**  
**Objectif : transférer le même firmware du compteur sur un ATmega328P PDIP28 en basse tension.** Les scripts, exercices, quiz, ressources et code sont rédigés ; essais physiques ISP et tournage à effectuer. Aucun PowerPoint.

## Continuité du projet obligatoire

La version M09 est **construite depuis M08**, pas un programme indépendant. Elle conserve le bouton, la LED, l'Uart `1/0/?`, les six grandeurs, le DS3231/LCD optionnels et les cumuls journaliers/mensuels. Seules la **configuration de la cible ATmega328P autonome** et le diagnostic de brochage ont été ajoutés.

[Comparer M08](../../../firmware/etapes/M08/Compteur_M08/Compteur_M08.ino) → [Ouvrir le firmware M09](../../../firmware/etapes/M09/Compteur_M09/Compteur_M09.ino) → [Programme courant](../../../firmware/courant/CompteurIntelligent/CompteurIntelligent.ino).

## Deux leçons de programmation et montage

| Vidéo | Durée | Script de narration | Démonstration |
|---|---:|---|---|
| [M09-V01 — Construire le circuit minimal](videos/V01-plan.md) | 8 min | [Script V01](scripts/V01-script.md) | Orientation DIP28, VCC/AVCC/GND, RESET, quartz 16 MHz, condensateurs, LED et [diagnostic](code/V01_01_diagnostic_led/V01_01_diagnostic_led.ino) |
| [M09-V02 — ArduinoISP et firmware fil rouge](videos/V02-plan.md) | 8 min | [Script V02](scripts/V02-script.md) | Uno programmateur, ISP MOSI/MISO/SCK/RESET, `Upload Using Programmer`, port série cible et [firmware M09](../../../firmware/etapes/M09/Compteur_M09/Compteur_M09.ino) |

## Documents pour l'apprenant

- [Guide du brochage physique ATmega328P PDIP28 et de la liaison ISP](ressources/BROCHAGE_ISP_PU28.md)
- [Procédure détaillée ArduinoISP](ressources/PROGRAMMATION_ISP.md)
- [Code de diagnostic et guide](code/README.md)
- [Deux TP sans corrigés](tp/TP_M09_APPRENANT.md)
- [Quiz de 10 questions](quiz/QUIZ_M09_APPRENANT.md)
- [Fiche de dépannage](ressources/DEPANNAGE.md)

## Documents pour le formateur

- [Corrections et barèmes TP](tp/CORRIGE_M09_FORMATEUR.md)
- [Corrigé des dix QCM](quiz/CORRIGE_M09_FORMATEUR.md)
- [Banque JSON](quiz/quiz_m09.json)
- [Plan de tests et journal d'essai](ressources/PLAN_TESTS.md)
- [Suivi des étapes de réalisation/tournage](production/README.md)

## Sécurité et limites

- Le circuit pédagogique est **uniquement basse tension 5 V**, avec alimentation et horloge conformes. Aucun novice ne manipule le secteur 230 V.
- La puce autonome **n'a ni USB intégré ni LED intégrée**. L'affichage série nécessite un adaptateur USB–TTL compatible et la LED nécessite une résistance série.
- **Firmware M09 en simulation par défaut** : ni PZEM réel ni horloge RTC/LCD active par défaut. Les fuses et l'horloge réelle de la cible doivent correspondre au profil 16 MHz.
- **Compiler ne signifie pas programmer physiquement la puce**. Les tests matériels restent à consigner avant de présenter ce module comme prêt à filmer.

**Évaluation :** TP en dehors des 16 minutes vidéo et quiz ≥ 8/10. [Règle obligatoire de progression continue](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md).
