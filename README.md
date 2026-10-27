# Compteur intelligent — Formation AlexTech Academy

**Formation vidéo de 4 h (240 minutes)** : concevoir un compteur électrique monophasé de suivi énergétique connecté, avec un **ATmega328P**, un **PZEM-004T**, un écran **LCD I2C 20×4** et une transmission **GSM/GPRS**.

> Parcours accéléré guidé destiné aux débutants. Les exercices, quiz et travaux pratiques se font en supplément des quatre heures de vidéo.

## Consulter le plan

- [Plan pédagogique complet de la formation](docs/formation/PLAN_FORMATION_4H.md)
- [Document original de référence (texte intégral)](docs/formation/plan_original.txt)

## Organisation de la formation

| Module | Sujet | Vidéos techniques | Durée |
|---|---|---:|---:|
| M01 | Découverte du projet et bases électriques | 2 | 10 min |
| M02 | Composants, alimentation et sécurité | 2 | 10 min |
| M03 | Arduino IDE et premier programme | 2 | 14 min |
| M04 | Bases du C/C++ pour microcontrôleurs | 2 | 14 min |
| M05 | Entrées, sorties et communications série | 2 | 18 min |
| M06 | PZEM-004T et mesures électriques | 2 | 16 min |
| M07 | DS3231 et LCD I2C | 2 | 14 min |
| M08 | Calcul fiable des consommations | 2 | 16 min |
| M09 | ATmega328P autonome et ISP avec Arduino Uno | 2 | 16 min |
| M10 | SIM800L et commandes AT | 2 | 14 min |
| M11 | FRAM, stockage local et synchronisation | 2 | 16 min |
| M12 | Fondamentaux Python | 2 | 14 min |
| M13 | Flask, SQLite et API de réception | 2 | 16 min |
| M14 | Interface Jinja2, HTML, CSS, JavaScript et graphiques | 2 | 16 min |
| M15 | Conception électronique et KiCad | 2 | 12 min |
| M16 | Intégration, tests et déploiement PythonAnywhere | 2 | 14 min |
| **Cours techniques** | | **32** | **230 min** |
| **Accueil + conclusion** | | | **10 min** |
| **Total** | | | **240 min** |

## Objectifs du prototype

Le LCD 20×4 affiche la **date**, la **tension secteur**, les **kWh du jour** et les **kWh du mois**. Le microcontrôleur acquiert les données du PZEM, les horodate avec le DS3231, les conserve temporairement en FRAM et les transmet via le SIM800L à l'API Flask. Les mesures sont stockées dans **SQLite** et visualisées sur une interface **Jinja2 + HTML/CSS/JavaScript**, hébergée sur PythonAnywhere selon la compatibilité réseau à valider.

## Technologies retenues

- **Microcontrôleur** : ATmega328P 16 MHz, firmware C/C++ avec Arduino IDE.
- **Programmation autonome** : Arduino Uno R3 utilisée comme programmateur ISP.
- **Mesure** : PZEM-004T V3.0 avec tore 100 A.
- **Horloge et mémoire** : DS3231 et FRAM.
- **Affichage** : LCD I2C 20×4, bouton, LED et buzzer.
- **Communication** : SIM800L GSM/GPRS (vérifier 2G et sécurité TLS).
- **Web** : Python Flask, SQLite, Jinja2, HTML/CSS, JavaScript, Chart.js.
- **Schéma et PCB** : KiCad.

## Évaluation

Un **quiz de 10 questions par module**, soit **160 questions**, puis une **évaluation finale de 20 questions**. Le seuil de réussite visé est de 80 %. Le détail des objectifs, exercices et quiz figure dans le plan complet.

## Sécurité

Le projet est un **système de suivi énergétique**, pas un compteur certifié pour la facturation. Les manipulations secteur 230 V et les essais de sécurité sont réservés à un banc adapté et à une personne qualifiée. Les débutants commencent par des simulations et des montages basse tension.

## Statut

La documentation et le plan de formation constituent le point de départ du dépôt. Les scripts vidéo, quiz complets, programmes Arduino, fichiers KiCad et application Flask seront ajoutés progressivement, après validation technique.


---

## Espace de production par module

L'ensemble des **16 dossiers pédagogiques** est organisé dans [`formation/`](formation/README.md). Chaque module contient les plans de ses deux vidéos et des espaces dédiés aux scripts oraux, slides, TP, quiz, ressources, code et suivi de tournage.

**[Ouvrir l'index des 16 modules](formation/README.md)** · [Lire le guide pédagogique](formation/GUIDE_PEDAGOGIQUE.md)

> Les plans vidéo sont renseignés ; les scripts, PowerPoint, quiz corrigés et programmes finalisés restent à produire et tester. Le programme général original reste conservé sans modification.
