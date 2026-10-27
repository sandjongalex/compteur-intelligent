# M06 — Lire les mesures du PZEM-004T V3.0

**AlexTech Academy · 16 minutes de vidéo (deux leçons de 8 min) · Prérequis : M01–M05.**  
**Pas de PowerPoint.** Démonstrations par captures Arduino IDE, sorties série, progression du code et matériels **hors tension**.

## Objectif pédagogique

Le débutant doit reconnaître et interpréter les **six grandeurs** du PZEM, expliquer un échange **UART/Modbus RTU**, convertir des **registres fictifs**, puis écrire une routine qui **signale un échec** au lieu de publier des données inventées.

## Les deux leçons

| Vidéo | Durée | Script du formateur | Code à ouvrir dans cet ordre |
|---|---:|---|---|
| [M06-V01 — Comprendre PZEM et Modbus RTU](videos/V01-plan.md) | 8 min | [Script intégral](scripts/V01-script.md) | [V01-01 simulation](code/V01_01_six_grandeurs_simulees/V01_01_six_grandeurs_simulees.ino) → [V01-02 registres](code/V01_02_registres_decodes/V01_02_registres_decodes.ino) |
| [M06-V02 — Lire et valider des mesures](videos/V02-plan.md) | 8 min | [Script intégral](scripts/V02-script.md) | [V02-01 relevés fictifs](code/V02_01_lecture_simulee/V02_01_lecture_simulee.ino) → [V02-02 panne fictive](code/V02_02_detection_panne_simulee/V02_02_detection_panne_simulee.ino) → [V02-03 bibliothèque V3, banc qualifié seulement](code/V02_03_pzem_reel_qualifie/V02_03_pzem_reel_qualifie.ino) |

## Documents pour l'apprenant

- [Guide complet des 7 sketches](code/README.md) (cinq étapes de code, deux corrigés).
- [Mémo PZEM V3, registres et unités](ressources/MEMO_PZEM_V3.md).
- [Deux travaux pratiques, sans réponses](tp/TP_M06_APPRENANT.md).
- [Quiz de dix questions, sans réponses](quiz/QUIZ_M06_APPRENANT.md).
- [Guide de dépannage](ressources/DEPANNAGE.md).

## Documents pour le formateur

- [Corrigés des TP et barèmes](tp/CORRIGE_M06_FORMATEUR.md).
- [Corrigé expliqué du quiz](quiz/CORRIGE_M06_FORMATEUR.md).
- [Banque JSON du quiz](quiz/quiz_m06.json).
- [Plan de tests et relevé des vérifications](ressources/PLAN_TESTS.md).
- [Suivi de conception et de tournage](production/README.md).

**Validation :** 8/10 au quiz, compréhension des six unités, réussite des deux TP. Les exercices sont **hors durée vidéo**.

## Sécurité et périmètre

- Les débutants ne réalisent **aucune manipulation du secteur 230 V** ; les simulations fonctionnent sur **Uno USB seule**.
- Un PZEM réel et l'interface associée ne doivent être utilisés que sur un banc protégé, préalablement installé et exploité par **une personne qualifiée**.
- **L'énergie est un index cumulatif**, pas une consommation quotidienne. Ne pas remettre l'index à zéro à chaque changement de date.
- Une lecture invalide doit rester invalide ; ne pas la remplacer par zéro.
- Le code est rédigé, **les compilations réelles Arduino et les essais sur banc ne sont pas encore attestés**.

[Plan général 4 h](../../../docs/formation/PLAN_FORMATION_4H.md) · [Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md)


## Continuité : programme fil rouge

Cette leçon est aussi intégrée à un **firmware cumulatif unique**, où les fonctions des modules précédents restent présentes.

- [**Version M06 du firmware fil rouge**](../../../firmware/etapes/M06/Compteur_M06/Compteur_M06.ino) : retrouver et tester les fonctions conservées et ajoutées.
- [Matrice de progression de M05 à M08](../../../firmware/PROGRESSION.md) : voir les différences pédagogiques et les tests.
- [Programme principal actuel](../../../firmware/courant/CompteurIntelligent/CompteurIntelligent.ino) : base qui sera enrichie en M09.

Les petits exercices `.ino` du module restent **inchangés** et utiles pour les débutants ; ne pas commencer par la totalité du firmware final.
