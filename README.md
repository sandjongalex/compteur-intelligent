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

Les modules pédagogiques **M01–M09** disposent de supports de cours préparés. Les essais sur Arduino, l'enregistrement des vidéos, ainsi que les modules M10–M16 restent à réaliser ou à compléter.


---

## Espace de production par module

L'ensemble des **16 dossiers pédagogiques** est organisé dans [`formation/`](formation/README.md). Chaque module contient les plans de ses deux vidéos et des espaces dédiés aux scripts oraux, slides, TP, quiz, ressources, code et suivi de tournage.

**[Ouvrir l'index des 16 modules](formation/README.md)** · [Lire le guide pédagogique](formation/GUIDE_PEDAGOGIQUE.md)

> Depuis M05, les modules de programmation privilégient scripts de démonstration, code par étapes et TP **sans PowerPoint**. Les essais physiques et vidéos doivent encore être validés.


## Firmware fil rouge (nouveau)

Pour construire **un seul compteur qui évolue d'une vidéo à l'autre**, utiliser le [firmware évolutif M03 → M09](firmware/README.md) : snapshots M03/M04/M05/M06/M07/M08/M09, [programme Arduino actuel](firmware/courant/CompteurIntelligent/CompteurIntelligent.ino), [journal de progression](firmware/PROGRESSION.md) et [tests](firmware/tests/README.md).

Les petits sketches pédagogiques **restent disponibles** ; le firmware fil rouge les complète. Par défaut, le code fonctionne en simulation sur Uno USB sans secteur. **Les versions futures M10–M16 ne sont pas encore implémentées dans ce programme.**


## Principe obligatoire de progression continue

**Chaque module réutilise le même compteur intelligent : le code précédent est la base, et la nouvelle fonctionnalité s'y ajoute sans perte silencieuse des acquis.** Les exemples isolés sont pédagogiques ; la solution finale reste un projet unique. L'obligation couvre également Python, Flask, l'interface web et KiCad. [Règle officielle et critères de validation](docs/formation/REGLE_EVOLUTION_CONTINUE.md).
