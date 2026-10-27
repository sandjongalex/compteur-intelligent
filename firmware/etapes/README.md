# Versions progressives du même compteur

Ces fichiers constituent le **fil rouge** de la formation, distinct des micro-exercices des modules.

| Version | Ce que le même programme sait faire | Pré-requis |
|---|---|---|
| [M05](M05/Compteur_M05/Compteur_M05.ino) | Bouton D2, LED, UART USB, timer `millis()`, mesure fictive | Uno + USB |
| [M06](M06/Compteur_M06/Compteur_M06.ino) | **Toutes les fonctions M05**, plus les 6 mesures PZEM et un statut d'échec | Uno USB par défaut ; banc qualifié pour PZEM réel |
| M07 | Conservation M06, ajout date DS3231 et affichage LCD 20×4 | RTC/LCD optionnels |
| M08 | Conservation M07, calcul des kWh jour/mois, statut partiel et anomalies | Moteur `EnergieM08.h` |

Chaque version est un **snapshot autonome** : ouvrir le `.ino` à l'intérieur de son dossier homonyme Arduino, et observer le comportement avant de passer à l'étape suivante. Ne pas fusionner mécaniquement tous les sketches de travaux pratiques.

Par défaut, le firmware est toujours en **simulation sur Uno USB seule** ; basculer les options de matériel uniquement sur un banc basse tension compatible, avec secteur **strictement réservé au personnel qualifié**.

[Voir le dossier du programme principal évolutif](../courant/CompteurIntelligent/) · [Guide général](../README.md)
