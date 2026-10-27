# M07 — Ajouter l'horloge DS3231 et l'écran LCD I2C 20×4

**AlexTech Academy · 14 minutes (2 vidéos de 7 min) · Prérequis M05 et M06.**

**État : supports pédagogiques, code et évaluations rédigés, encore à vérifier sur matériel.** Le formateur conserve l'enregistrement et la publication. **Aucun PowerPoint.**

## Objectifs observables

Au terme du module, l'apprenant pourra :
1. Identifier un périphérique sur un bus I2C avec le scanner Arduino et expliquer les lignes SDA/SCL.
2. Lire le DS3231 avec RTClib, reconnaître l'état `lostPower`, et régler l'horloge **une seule fois volontairement**.
3. Afficher quatre lignes sur un LCD 20×4 avec `hd44780_I2Cexp` et éviter les textes résiduels ou le scintillement excessif.
4. Partager un bus I2C entre la RTC et le LCD lorsque les cartes sont électriquement compatibles.
5. Présenter **la date réelle** de la RTC lorsqu'elle est fiable et des **mesures encore simulées**, en attendant le calcul des kWh jour/mois au M08.
6. Modifier un sketch et expliquer les comportements observés.

## Deux vidéos pratiques

| Vidéo | Durée cible | Script intégral | Ordre des sketches |
|---|---:|---|---|
| [M07-V01 — Comprendre et utiliser le DS3231](videos/V01-plan.md) | 7 min | [Script V01](scripts/V01-script.md) | [Scanner I2C](code/V01_01_scanner_i2c/V01_01_scanner_i2c.ino) → [Lecture RTC](code/V01_02_lire_ds3231/V01_02_lire_ds3231.ino) → [Réglage ponctuel](code/V01_03_regler_ds3231_une_fois/V01_03_regler_ds3231_une_fois.ino) |
| [M07-V02 — Afficher le compteur sur LCD I2C 20×4](videos/V02-plan.md) | 7 min | [Script V02](scripts/V02-script.md) | [Bonjour LCD](code/V02_01_lcd_bonjour/V02_01_lcd_bonjour.ino) → [4 lignes fictives](code/V02_02_lcd_4_lignes_simulees/V02_02_lcd_4_lignes_simulees.ino) → [LCD + RTC](code/V02_03_rtc_lcd_integres/V02_03_rtc_lcd_integres.ino) |

## Documents destinés aux apprenants

- [Guide des huit programmes Arduino et des dépendances](code/README.md).
- [Fiche des broches I2C, de l'alimentation et de la sauvegarde RTC](ressources/BUS_I2C_SECURITE.md).
- [Mémo des fonctions RTC/LCD](ressources/MEMO_RTC_LCD.md).
- [Guide de diagnostic](ressources/DEPANNAGE.md).
- [Travaux pratiques TP01 et TP02, sans corrigés](tp/TP_M07_APPRENANT.md).
- [Quiz M07, dix questions sans réponses](quiz/QUIZ_M07_APPRENANT.md).

## Documents réservés au formateur

- [Corrigés et barèmes des deux TP](tp/CORRIGE_M07_FORMATEUR.md).
- [Corrigé argumenté des dix QCM](quiz/CORRIGE_M07_FORMATEUR.md).
- [Banque JSON du quiz](quiz/quiz_m07.json).
- [Plan de tests réels T01–T10](ressources/PLAN_TESTS.md).
- [Checklist de préparation et de tournage](production/README.md).

**Évaluation :** 8/10 minimum au quiz et compréhension des deux TP. Les exercices sont réalisés **hors des 14 minutes vidéo**.

## Maquette affichée

```text
DATE: 27/10/2026
TENSION: 230.5 V
JOUR:    4.250 kWh
MOIS:  125.480 kWh
```

Cette illustration contient **des valeurs fictives**. Le programme final de ce module remplace la première ligne par la date lue sur le DS3231 **uniquement si elle est fiable**. L'énergie du jour et du mois ne sera calculée qu'en M08.

## Sécurité

- Raccordements en **basse tension uniquement**, aucun secteur 230 V, aucun PZEM alimenté.
- Contrôler la référence et la tension de chaque carte. Une carte DS3231 avec circuit de charge ne doit pas recevoir de pile primaire incompatible.
- Débrancher l'USB avant tout changement de fils.
- La compilation Arduino réelle et les essais sur DS3231/LCD n'ont pas encore été confirmés.

[Guide pédagogique général](../../GUIDE_PEDAGOGIQUE.md) · [Plan validé 4 h](../../../docs/formation/PLAN_FORMATION_4H.md)


## Continuité : programme fil rouge

Cette leçon est aussi intégrée à un **firmware cumulatif unique**, où les fonctions des modules précédents restent présentes.

- [**Version M07 du firmware fil rouge**](../../../firmware/etapes/M07/Compteur_M07/Compteur_M07.ino) : retrouver et tester les fonctions conservées et ajoutées.
- [Matrice de progression de M05 à M08](../../../firmware/PROGRESSION.md) : voir les différences pédagogiques et les tests.
- [Programme principal actuel](../../../firmware/courant/CompteurIntelligent/CompteurIntelligent.ino) : base qui sera enrichie en M09.

Les petits exercices `.ino` du module restent **inchangés** et utiles pour les débutants ; ne pas commencer par la totalité du firmware final.
