# Firmware fil rouge — Compteur intelligent AlexTech Academy

Ce dossier contient le **même projet Arduino qui gagne des fonctions à chaque module**. Il complète, mais ne remplace pas, les petits sketches d'apprentissage des modules M03 à M08.

**Règle obligatoire :** [contrat de progression continue](../docs/formation/REGLE_EVOLUTION_CONTINUE.md). Chaque nouvel ajout firmware part du courant, conserve ou explique les transformations des fonctions, synchronise le snapshot et le courant, actualise le [manifeste](manifest.json), puis passe les tests. Les exercices séparés ne remplacent pas le programme principal.

## Parcours de construction (code conservé d'une étape à l'autre)

| Étape | Programme autonome à ouvrir dans Arduino IDE | Acquisition | Acquisition date / écran | Calcul de période |
|---|---|---|---|---|
| [M03](etapes/M03/Compteur_M03/Compteur_M03.ino) | **Début du projet :** LED intégrée, `setup()`, `loop()`, clignotement avec `delay()` | Aucun module de mesure | Non | Non |
| [M04](etapes/M04/Compteur_M04/Compteur_M04.ino) | **M03 structuré :** constantes, fonctions et calcul énergétique fictif, moniteur série | Valeurs purement fictives | Non | Non |
| [M05](etapes/M05/Compteur_M05/Compteur_M05.ino) | Bouton D2, LED, UART USB `1/0/?`, `millis()` | Tension fictive | Non | Non |
| [M06](etapes/M06/Compteur_M06/Compteur_M06.ino) | **Tout M05** + six valeurs et échec explicite | Simulation (défaut), option PZEM V3 qualifiée | Non | Non |
| [M07](etapes/M07/Compteur_M07/Compteur_M07.ino) | **Tout M06** + DS3231 et LCD 20×4 | Identique à M06 | Simulation USB par défaut, RTC + LCD optionnels | **Non calculé** |
| [M08](etapes/M08/Compteur_M08/Compteur_M08.ino) | **Tout M07** + `SuiviEnergieM08` | Index simulé en Wh entiers (ou lecture qualifiée) | Date simulée par défaut ; option vraie RTC/LCD | Jour et mois **partiels ou complets** |
| [M09](etapes/M09/Compteur_M09/Compteur_M09.ino) | **Tout M08** + option de cible ATmega328P PDIP28 autonome, diagnostic des broches, horloge 16 MHz et programmation ISP | Source inchangée (simulation par défaut, option PZEM qualifiée) | RTC/LCD optionnels comme M08 | Cumuls jour/mois préservés |

Le programme de travail actuel est [**courant/CompteurIntelligent/CompteurIntelligent.ino**](courant/CompteurIntelligent/CompteurIntelligent.ino). Il est désormais **la même source que le snapshot M09**, le M08 restant archivé pour les apprenants. Il continuera d'évoluer aux M10 et M11. **Les snapshots déjà publiés restent figés** pour que chaque vidéo renvoie au bon code.

## Installation (mode débutant, sans matériel de mesure)

1. Installer Arduino IDE 2 et sélectionner **Arduino Uno Rev3** et le port USB.
2. Ouvrir **le fichier `.ino` directement dans son dossier homonyme**, par exemple `firmware/etapes/M03/Compteur_M03/Compteur_M03.ino`.
3. À partir de M04, le moniteur série affiche des explications ; à partir de M05, la LED se commande par bouton/UART au lieu de clignoter automatiquement. Garder les options `ALEXTECH_PZEM_REEL 0` (M06+) et `ALEXTECH_RTC_LCD_REELS 0` (M07+).
4. **Vérifier**, puis **Téléverser**. La version M03 se vérifie en regardant la LED ; à partir de M04, ouvrir le moniteur série à **9600 bauds**.
5. Brancher éventuellement un bouton entre **D2 et GND**, hors tension, pour essayer un changement d'état de la LED intégrée. Le bouton n'est pas obligatoire pour voir les sorties série.
6. **À partir de M05**, envoyer un caractère `1` (LED ON), `0` (LED OFF) ou `?` (aide). Vérifier que les relevés simulés continuent.
7. À partir de l'étape M08, observer la date fictive, les kWh **partiels**, ainsi que l'évolution de l'index Wh.

**En simulation, une Arduino Uno USB seule suffit. Aucun PZEM, secteur, modem GSM, RTC ou LCD n'est requis par défaut.**

## Pour les essais matériels (à ne pas confondre avec la simulation)

- **RTC + LCD** : option `ALEXTECH_RTC_LCD_REELS 1`, bibliothèque Adafruit `RTClib` et `hd44780` (Bill Perry) installées, tension I2C et alimentation des modules contrôlées, câblage Uno SDA=A4 et SCL=A5. Ne jamais reprogrammer systématiquement l'heure dans le firmware normal.
- **PZEM réel** : option `ALEXTECH_PZEM_REEL 1`, bibliothèque `PZEM004Tv30` adaptée à la V3 ; **réservé à un banc électrique conçu, monté et exploité par un professionnel qualifié**. Ne pas enseigner un raccordement au 230 V aux débutants.
- **Calcul M08** : nécessite **un index Wh continu et une date fiable**. La valeur `energy()` de la bibliothèque PZEM V3 est un `float` kWh. Sur AVR, convertir un grand index flottant en Wh peut perdre de la précision ; pour la version de production il faudra lire ou reconstruire les registres bruts avec précision suffisante.
- **FRAM non intégrée** : les cumuls du firmware M08 restent en RAM et sont **perdus après une vraie coupure**. La persistance sûre sera ajoutée au M11.
- Le projet n'est pas un compteur homologué pour la facturation.

## Décision de brochage pour la prochaine étape M10

À partir de M10, **SIM800L = UART matériel `Serial` D0/RX et D1/TX** sur ATmega328P ; **PZEM-004T = `SoftwareSerial` D10/RX et D11/TX** ; **RTC DS3231, LCD I2C et future FRAM I2C = SDA A4 / SCL A5**. D2 reste le bouton et D13 la LED. Les changements de débogage nécessaires pour libérer `Serial`, les protections d'alimentation/logic levels et l'isolation pendant l'ISP sont définis dans la [règle obligatoire](../docs/formation/REGLE_EVOLUTION_CONTINUE.md#attribution-des-interfaces-matérielles-à-partir-de-m10).

**Attention :** le firmware courant est encore M09 et conserve volontairement sa console série pédagogique. Le brochage GSM est une **décision pour la future implémentation M10**, pas une fonctionnalité déjà développée ni un résultat matériel validé.

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

- **M09 : préparé** pour le déploiement du même firmware sur ATmega328P autonome via ISP ; essais réels sur cible à effectuer et documenter.
- **M10** : pilote SIM800L / commandes AT, avec alimentation correcte et interface de transmission.
- **M11** : FRAM, persistance, journal des mesures et synchronisation après interruption.
- **M12–M14** : programme Python, API Flask/SQLite et tableau de bord, branchés progressivement sur les données envoyées.
- **M15–M16** : schéma/PCB KiCad, tests d'intégration et déploiement.

**Aucun de ces ajouts futurs n'est déclaré développé dans ce dossier tant que le code correspondant n'existe pas.**

**Principe retenu :** M01/M02 préparent l'électricité et la sécurité sans firmware ; **M03 est la première version du projet réel**. M04, M05, M06, M07 et M08 font tous évoluer cette même base. Le changement de mode LED en M05 (clignotement → commande) est une évolution explicite, non une suppression accidentelle.

## Maintenance P1/P2 du firmware M09 (avant M10)

La dernière étape M09 a reçu une maintenance corrective documentée :
la simulation des kWh correspond désormais à 92,2 W, la provenance de l'heure
est explicite (DS3231 ou démo), et un PZEM réel sans DS3231 activé est interdit.
Les périodes traversant minuit restent partielles si aucun relevé n'est fait
exactement à la frontière. Les tests C++ M09 et les compilations des bibliothèques
matérielles ont été ajoutés à la CI.

**Validation du matériel encore en attente :** les compilations AVR des modes
PZEM/RTC/LCD n'attestent ni un câblage correct, ni les fuses/ISP, ni une
lecture réelle de la tension secteur. Le stockage FRAM viendra en M11.
Les sketches M03–M08 ne sont pas modifiés ; l'erratum M09 synchronise
son snapshot avec le firmware de travail.

**Ressources M09 :** la compilation avec `PZEM+RTC+LCD` demande actuellement
19 456 octets de Flash (60 %) et 918 octets de RAM globale (44 %), soit 1 130
octets restant pour pile et allocations sur ATmega328P 2 Kio RAM.
L'ajout du SIM800L en M10 exigera une nouvelle mesure d'occupation mémoire
et des tests des pertes de liaison.
