# Production de la formation — Compteur intelligent

**AlexTech Academy** · **16 modules** · **32 vidéos techniques** · **230 min de cours + 10 min d'accueil/conclusion = 4 h**.

Ce dossier est l'espace de production pédagogique du cours. Chaque module possède **son propre dossier** contenant les plans vidéo, scripts, storyboards, exercices, quiz, ressources, code et suivi de production.

## Accès aux modules

| Module | Durée | Vidéos | Statut |
|---|---:|---:|---|
| [M01 — Découvrir le compteur et comprendre l'électricité](modules/M01-decouverte-electricite/) | 10 min | 2 | Scripts + storyboards + quiz + TP rédigés, tournage à faire |
| [M02 — Identifier les composants et travailler en sécurité](modules/M02-composants-securite/) | 10 min | 2 | Scripts, slides, TP et quiz produits ; tournage à faire |
| [M03 — Installer Arduino IDE et programmer sa première LED](modules/M03-arduino-ide-premier-programme/) | 14 min | 2 | Scripts, PowerPoint, codes Arduino, TP et quiz prêts ; tests matériels et tournage à faire |
| [M04 — Comprendre les bases du C/C++ embarqué](modules/M04-bases-cpp/) | 14 min | 2 | Scripts, PPTX, 5 sketches, TP et quiz préparés ; tests Uno et tournage à faire |
| [M05 — Entrées, sorties et communications série](modules/M05-entrees-sorties-uart/) | 18 min | 2 | Scripts, 8 sketches, TP, quiz, tests documentés ; essais Uno et tournage à faire |
| [M06 — Lire les mesures du PZEM-004T V3.0](modules/M06-pzem-mesures/) | 16 min | 2 | Scripts, 7 sketches, deux TP, quiz, mémo et tests prêts ; validation réelle et tournage à faire |
| [M07 — Ajouter l'heure et l'écran LCD I2C](modules/M07-ds3231-lcd-i2c/) | 14 min | 2 | Scripts, 8 sketches, TP, quiz et tests documentés ; essais physiques et tournage à faire |
| [M08 — Calculer les consommations journalières et mensuelles](modules/M08-consommation-jour-mois/) | 16 min | 2 | Plans présents, production à faire |
| [M09 — Programmer l'ATmega328P autonome par ISP](modules/M09-atmega328p-isp/) | 16 min | 2 | Plans présents, production à faire |
| [M10 — Communiquer avec le SIM800L par GSM/GPRS](modules/M10-sim800l-gsm-gprs/) | 14 min | 2 | Plans présents, production à faire |
| [M11 — Sauvegarder les relevés et synchroniser après une panne](modules/M11-fram-synchronisation/) | 16 min | 2 | Plans présents, production à faire |
| [M12 — Apprendre les bases de Python](modules/M12-bases-python/) | 14 min | 2 | Plans présents, production à faire |
| [M13 — Construire le backend Flask et la base SQLite](modules/M13-flask-sqlite-api/) | 16 min | 2 | Plans présents, production à faire |
| [M14 — Créer le tableau de bord web](modules/M14-dashboard-jinja-html-css-js/) | 16 min | 2 | Plans présents, production à faire |
| [M15 — Concevoir le schéma électronique avec KiCad](modules/M15-kicad-schema-pcb/) | 12 min | 2 | Plans présents, production à faire |
| [M16 — Intégration, tests et déploiement](modules/M16-integration-tests-deploiement/) | 14 min | 2 | Plans présents, production à faire |

## Pédagogie des modules de programmation

À partir de **M05**, produire des scripts synchronisés à l'écran, du code testé, des défis et des corrigés ; **aucun PowerPoint à créer**. Voir le [guide pédagogique](GUIDE_PEDAGOGIQUE.md) et le [modèle de démonstration programmée](modeles/SCRIPT_DEMONSTRATION_CODE.md). Les modules antérieurs conservent leurs supports existants.

## Structure d'un module

```text
Mxx-theme/
├── README.md                 # Objectifs, prérequis, ressources, navigation
├── videos/                   # Fiches pédagogiques V01 et V02
│   ├── V01-plan.md
│   └── V02-plan.md
├── scripts/                  # Trames des textes à prononcer
│   ├── V01-script.md
│   └── V02-script.md
├── slides/                   # Briefs PowerPoint/storyboards des deux vidéos
│   ├── V01-storyboard.md
│   └── V02-storyboard.md
├── tp/README.md              # Travaux pratiques, exercices et corrigés
├── quiz/README.md            # Plan de 10 questions, réponses à produire
├── ressources/README.md      # Fichiers à télécharger et contrôles
├── code/README.md            # Sketches, schémas ou projets applicables
└── production/README.md      # Checklist et statuts de production
```

## Ressources transversales

- [Guide pédagogique et statut des livrables](GUIDE_PEDAGOGIQUE.md)
- [Modèle de fiche pour une vidéo](modeles/FICHE_VIDEO.md)
- [Modèle de script intégral](modeles/SCRIPT_VIDEO.md)
- [Modèle de quiz corrigé](modeles/QUIZ.md)
- [Modèle de TP](modeles/TP.md)
- [Plan original complet et détaillé](../docs/formation/PLAN_FORMATION_4H.md)

**Important :** les dossiers sont créés et les **plans des 32 vidéos** ont été repris du programme validé. Les scripts intégralement rédigés, présentations PPTX, quiz corrigés, schémas et programmes finalisés nécessitent encore une production et une validation par module.
