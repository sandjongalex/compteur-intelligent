# M07 — Guide du bus I2C, matériel et sécurité

**Ce document concerne uniquement les circuits basse tension, pas la partie secteur du compteur.**

## Broches Arduino Uno Rev3

```text
                        Arduino Uno Rev3
                               |
    A4 / SDA  -----------------+------ SDA DS3231
                               +------ SDA adaptateur LCD I2C
    A5 / SCL  -----------------+------ SCL DS3231
                               +------ SCL adaptateur LCD I2C
    GND ----------------------+------ GND DS3231
                               +------ GND LCD
    Alimentation regulée ------+------ VCC modules si compatibles
```

**Avant d'alimenter :** vérifier les tensions réellement acceptées par les cartes complètes, ainsi que les résistances de tirage (pull-up) du bus. Certaines interfaces I2C fonctionnent en 3,3 V, d'autres en 5 V, et il ne faut pas relier directement des circuits incompatibles. Ne pas supposer qu'une inscription « DS3231 » ou « LCD I2C » garantit un module 5 V.

- **DS3231 :** adresse I2C habituelle **0x68**.
- **EEPROM additionnelle sur certains modules RTC :** peut répondre à **0x57**.
- **Backpack LCD :** souvent **0x27** ou **0x3F**, sans garantie ; relever l'adresse réelle ou utiliser la bibliothèque auto-détectrice.
- Pour un LCD de type HD44780 avec adaptateur PCF8574/MCP23008, employer `hd44780_I2Cexp` de la bibliothèque **hd44780**. Un écran natif I2C d'un autre type peut nécessiter un autre pilote.

## Précautions sur la pile DS3231

Certaines cartes **ZS-042** sont équipées d'un circuit qui tente de recharger la pile bouton. Une pile **CR2032 non rechargeable** ne doit pas être placée dans un circuit de charge. Il faut identifier le modèle et choisir une solution de sauvegarde et une carte sûres, conformément à la documentation du fabricant.

Le DS3231 garde l'heure seulement si ses conditions d'alimentation de secours sont respectées. `rtc.lostPower()` signale l'arrêt de l'oscillateur ; ne pas se contenter d'afficher une date potentiellement fausse.

## Méthode de branchement pour le tournage

1. **Débrancher l'USB.**
2. Examiner la référence précise du DS3231 et du LCD, leurs tensions et leur pile.
3. Relier SDA/SCL en parallèle, GND commun, alimentation basse tension compatible.
4. Contrôler le montage et rebrancher l'USB.
5. Lancer d'abord le [scanner I2C](../code/V01_01_scanner_i2c/V01_01_scanner_i2c.ino).
6. Ouvrir le moniteur à **9600 bauds**, vérifier les adresses réellement détectées.
7. Tester ensuite RTC puis LCD séparément, avant l'intégration.

**Interdit :** raccorder le 230 V, le PZEM ou le SIM800L pour ces exercices.
