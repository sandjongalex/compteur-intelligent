# M09 — Procédure ArduinoISP : un programmateur, une cible

**Objectif : programmer le même firmware M08 enrichi pour M09 sur une puce ATmega328P PDIP28 autonome, sans bootloader nécessaire lors de `Upload Using Programmer`.** Ne pas utiliser le secteur.

## Préparation

1. Vérifier la **référence exacte ATmega328P** (pas ATmega328 non-P), boîtier **PDIP28**, et le circuit minimal 5 V / horloge 16 MHz adapté aux fuses.
2. Préparer une **Arduino Uno R3** comme **programmateur** USB, une breadboard basse tension, une cible ATmega328P et les composants de [brochage](BROCHAGE_ISP_PU28.md).
3. Arduino IDE 2 : sélectionner **Arduino Uno** comme carte **programmateur**, son port série USB, ouvrir **File → Examples → 11.ArduinoISP → ArduinoISP**, puis téléverser normalement **sur la Uno programmateur**. Le numéro de catégorie d'exemple peut varier : chercher « ArduinoISP ».
4. Après téléversement du sketch ArduinoISP, mettre l'Uno hors tension pour câbler la cible. Selon la révision/modèle de la Uno, **un condensateur 10 µF entre RESET et GND côté Uno programmateur** (polarité électrolytique : + sur RESET, − sur GND) peut limiter les resets USB intempestifs. Ne pas l'ajouter sans vérifier la documentation du modèle.
5. Brancher les six signaux ISP dans l'ordre du [tableau](BROCHAGE_ISP_PU28.md) et vérifier la masse commune / source 5 V unique, hors tension.

## Configuration carte cible et horloge

6. Dans Arduino IDE, sélectionner **Arduino Uno** comme **profil cible 16 MHz** pour conserver la correspondance des broches du firmware, même si la cible est physiquement une puce nue. Le port sélectionné reste celui de l'Uno **programmateur**.
7. Dans **Tools → Programmer**, sélectionner **Arduino as ISP** (et non **ArduinoISP** si celui-ci représente un dispositif USB différent dans l'IDE). Le terme exact dépend des plateformes installées.
8. Si les **fuses actuels de la cible** ne correspondent pas au mode 16 MHz externe, réaliser une configuration cohérente en suivant l'option adaptée du cœur Arduino (souvent **Burn Bootloader**, qui écrit aussi les fuses). **Installer un quartz/horloge fonctionnelle avant d'écrire des fuses exigeant une horloge externe** ; des fuses mal choisis peuvent rendre la puce non accessible sans récupération adaptée. Ce n'est **pas** obligatoire de répéter « Burn Bootloader » à chaque chargement.
9. Sur une puce dont les fuses sont déjà configurés correctement, l'étape précédente peut être inutile. Ne pas deviner ses fuses à partir du nom commercial de la puce.

## Charger le programme puis reprendre le projet principal

10. Vérifier la communication ISP avec le [programme LED minimal](../code/V01_01_diagnostic_led/V01_01_diagnostic_led.ino), puis **Sketch → Upload Using Programmer**, pas l'icône de téléversement normal. Cette action charge directement la Flash via ISP et peut écraser un bootloader précédemment présent.
11. Débrancher le montage pour modifier les connexions ; alimenter ensuite la cible dans ses conditions autonomes prévues, **sans dépendre physiquement de l'Uno programmateur**. Ajouter la LED et la résistance sur **PB5 / pin 19**, si ce n'est déjà fait, puis observer le clignotement.
12. Si un contrôle série est souhaité, utiliser un **adaptateur USB–TTL 5 V compatible** (TX adaptateur → RX cible broche 2 ; RX adaptateur ← TX cible broche 3 ; GND commun). Un adaptateur USB–RS232 à niveaux ±12 V ne convient pas.
13. Revenir au **firmware fil rouge M09**, conserver `ALEXTECH_PZEM_REEL 0` et `ALEXTECH_RTC_LCD_REELS 0`, puis activer `ALEXTECH_ATMEGA_AUTONOME 1` ; compiler pour Uno / 16 MHz et **Upload Using Programmer**. Le firmware n'a **pas été réécrit** : les commandes `1/0/?`, les six valeurs fictives, la date fictive et le calcul jour/mois fonctionnent encore en théorie comme sur M08, à vérifier physiquement.
14. Si le programme semble fonctionner mais que les durées sont fausses, suspecter une discordance **F_CPU/fuses/quartz** ; la macro F_CPU vérifie la compilation mais **ne mesure pas l'horloge réelle**.

## Pannes courantes

| Symptôme | Vérification sans risque |
|---|---|
| `avrdude: device signature = 0x000000` ou communication impossible | Débrancher avant de contrôler RESET, MOSI, MISO, SCK, masse, alimentation et horloge |
| Une erreur `stk500` survient | Vérifier « Arduino as ISP », port de la Uno programmateur, sketch ArduinoISP chargé et auto-reset du programmateur |
| La LED clignote sur Uno, pas sur puce nue | La puce nue n'a **pas** de LED intégrée ; ajouter LED + résistance sur PDIP28 broche 19 |
| Fuse 16 MHz choisi mais puce inerte | Vérifier quartz 16 MHz et condensateurs de charge, configuration de fuses et disponibilité de l'horloge |
| `Upload` normal échoue | Utiliser **Upload Using Programmer** en ISP, pas le transfert série bootloader |
| Aucun message dans le moniteur de la Uno programmateur après transfert | Le firmware s'exécute sur la **puce cible** ; connecter un USB–TTL compatible sur les broches série de cette puce |

**Sécurité :** aucun raccordement 230 V, alimentation 5 V régulée, pas d'alimentations en parallèle sans dispositif prévu et aucune modification de câblage sous tension.

## Sources de référence

- <https://docs.arduino.cc/retired/getting-started-guides/ArduinoISP>
- <https://support.arduino.cc/hc/en-us/articles/6125080065820-Select-programmer-in-Arduino-IDE>
- <https://docs.arduino.cc/resources/datasheets/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf>
