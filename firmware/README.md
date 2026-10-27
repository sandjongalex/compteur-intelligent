# Firmware fil rouge — Compteur intelligent AlexTech Academy

Ce dossier contient le **même projet Arduino qui gagne des fonctions à chaque module**. Il complète, mais ne remplace pas, les petits sketches d'apprentissage des modules M03 à M08.

## Parcours de construction (code conservé d'une étape à l'autre)

| Étape | Programme autonome à ouvrir dans Arduino IDE | Acquisition | Acquisition date / écran | Calcul de période |
|---|---|---|---|---|
| [M03](etapes/M03/Compteur_M03/Compteur_M03.ino) | **Début du projet :** LED intégrée, `setup()`, `loop()`, clignotement avec `delay()` | Aucun module de mesure | Non | Non |
| [M04](etapes/M04/Compteur_M04/Compteur_M04.ino) | **M03 structuré :** constantes, fonctions et calcul énergétique fictif, moniteur série | Valeurs purement fictives | Non | Non |
| [M05](etapes/M05/Compteur_M05/Compteur_M05.ino) | Bouton D2, LED, UART USB `1/0/?`, `millis()` | Tension fictive | Non | Non |
| [M06](etapes/M06/Compteur_M06/Compteur_M06.ino) | **Tout M05** + six valeurs et échec explicite | Simulation (défaut), option PZEM V3 qualifiée | Non | Non |
| [M07](etapes/M07/Compteur_M07/Compteur_M07.ino) | **Tout M06** + DS3231 et LCD 20×4 | Identique à M06 | Simulation USB par défaut, RTC + LCD optionnels | **Non calculé** |
| [M08](etapes/M08/Compteur_M08/Compteur_M08.ino) | **Tout M07** + `SuiviEnergieM08` | Index simulé en Wh entiers (ou lecture qualifiée) | Date simulée par défaut ; option vraie RTC/LCD | Jour et mois **partiels ou complets** |

Le programme de travail actuel est [**courant/CompteurIntelligent/CompteurIntelligent.ino**](courant/CompteurIntelligent/CompteurIntelligent.ino). Il est la **même source que le snapshot M08** au moment de la création de cette base et deviendra progressivement M09, M10, M11, etc. **Les snapshots déjà publiés restent figés** pour que chaque vidéo renvoie au bon code.

## Installation (mode débutant, sans matériel de mesure)

1. Installer Arduino IDE 2 et sélectionner **Arduino Uno Rev3** et le port USB.
2. Ouvrir **le fichier `.ino` directement dans son dossier homonyme**, par exemple `firmware/etapes/M03/Compteur_M03/Compteur_M03.ino`.
3. À partir de M04, le moniteur série affiche des explications ; à partir de M05, la LED se commande par bouton/UART au lieu de clignoter automatiquement. Garder les options `ALEXTECH_PZEM_REEL 0` (M06+) et `ALEXTECH_RTC_LCD_REELS 0` (M07+).
4. **Vérifier**, puis **Téléverser**. La version M03 se vérifie en regardant la LED ; à partir de M04, ouvrir le moniteur série à **9600 bauds**.
5. Brancher éventuellement un bouton entre **D2 et GND**, hors tension, pour essayer un changement d'état de la LED intégrée. Le bouton n'est pas obligatoire pour voir les sorties série.
6. **À partir de M05**, envoyer un caractère `1` (LED ON), `0` (LED OFF) ou `?` (aide). Vérifier que les relevés simulés continuent.
7. À l'étape M08, observer la date fictive, les kWh **partiels**, ainsi que l'évolution de l'index Wh.

**En simulation, une Arduino Uno USB seule suffit. Aucun PZEM, secteur, modem GSM, RTC ou LCD n'est requis par défaut.**

## Pour les essais matériels (à ne pas confondre avec la simulation)

- **RTC + LCD** : option `ALEXTECH_RTC_LCD_REELS 1`, bibliothèque Adafruit `RTClib` et `hd44780` (Bill Perry) installées, tension I2C et alimentation des modules contrôlées, câblage Uno SDA=A4 et SCL=A5. Ne jamais reprogrammer systématiquement l'heure dans le firmware normal.
- **PZEM réel** : option `ALEXTECH_PZEM_REEL 1`, bibliothèque `PZEM004Tv30` adaptée à la V3 ; **réservé à un banc électrique conçu, monté et exploité par un professionnel qualifié**. Ne pas enseigner un raccordement au 230 V aux débutants.
- **Calcul M08** : nécessite **un index Wh continu et une date fiable**. La valeur `energy()` de la bibliothèque PZEM V3 est un `float` kWh. Sur AVR, convertir un grand index flottant en Wh peut perdre de la précision ; pour la version de production il faudra lire ou reconstruire les registres bruts avec précision suffisante.
- **FRAM non intégrée** : les cumuls du firmware M08 restent en RAM et sont **perdus après une vraie coupure**. La persistance sûre sera ajoutée au M11.
- Le projet n'est pas un compteur homologué pour la facturation.

## Deux chemins pour apprendre

**1. Petits projets d'une leçon** : dans `formation/modules/Mxx.../code`, une seule notion à la fois, avec exercices et corrections.

**2. Firmware fil rouge** : dans `firmware/etapes/Mxx`, l'apprenant retrouve toutes les fonctions antérieures plus la nouveauté du module.

Il est recommandé de **regarder d'abord la vidéo et de réaliser le petit TP**, puis d'ouvrir la version fil rouge, d'identifier les lignes ajoutées et de vérifier que les anciennes commandes fonctionnent toujours.

## Tests et limites

[**Plan et commandes de vérification**](tests/README.md) · [Journal de progression pédagogique](PROGRESSION.md)

- Validation statique : `python3 firmware/tests/test_progression.py`.
- Moteur énergie C++ portable : `g++ -std=c++11 -Wall -Wextra -pedantic firmware/tests/test_m08.cpp -o /tmp/test_m08 && /tmp/test_m08`.
- Compilation Arduino Uno : demander à Arduino IDE 2 ou Arduino CLI de compiler **chaque version** en mode simulation.
- Les essais du DS3231, du LCD et d'un PZEM réel doivent être enregistrés séparément ; une compilation ne démontre pas un résultat physique.

## Suite prévue

- **M09** : déploiement de ce même firmware sur un ATmega328P autonome via ISP, après vérification des broches, horloge et protections.
- **M10** : pilote SIM800L / commandes AT, avec alimentation correcte et interface de transmission.
- **M11** : FRAM, persistance, journal des mesures et synchronisation après interruption.
- **M12–M14** : programme Python, API Flask/SQLite et tableau de bord, branchés progressivement sur les données envoyées.
- **M15–M16** : schéma/PCB KiCad, tests d'intégration et déploiement.

**Aucun de ces ajouts futurs n'est déclaré développé dans ce dossier tant que le code correspondant n'existe pas.**

**Principe retenu :** M01/M02 préparent l'électricité et la sécurité sans firmware ; **M03 est la première version du projet réel**. M04, M05, M06, M07 et M08 font tous évoluer cette même base. Le changement de mode LED en M05 (clignotement → commande) est une évolution explicite, non une suppression accidentelle.
