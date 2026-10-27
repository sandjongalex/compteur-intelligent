# M07 — Plan de tests avant tournage

**Aucun essai matériel ou compilation Arduino réelle n'est revendiqué dans cette première livraison.** Cochez seulement après un test mesuré sur une Uno Rev3 et les modules effectivement choisis.

## Préparer le banc basse tension

- Arduino IDE 2, Arduino Uno Rev3, DS3231, LCD 20×4 et backpack I2C compatible, câble USB.
- Bibliothèques Adafruit **RTClib** (et dépendances) et **hd44780** par Bill Perry / duinoWitchery.
- Vérifier **SDA=A4, SCL=A5**, niveaux logiques, alimentation, pull-ups et type de pile.
- Aucun PZEM, aucun SIM800L, aucun branchement secteur.

## Tests à effectuer

| ID | Sketch | Action | Résultat attendu | Réalisé |
|---|---|---|---|---|
| T01 | V01-01 | Scanner uniquement la RTC | `0x68` trouvé si RTC fonctionnelle ; éventuellement `0x57` EEPROM | [ ] |
| T02 | V01-02 | Lire RTC valide | Date/heure mises à jour ~1 fois par seconde | [ ] |
| T03 | V01-02 | RTC non réglée / perte d'oscillateur connue | Message **HEURE NON FIABLE**, pas de date inventée | [ ] |
| T04 | V01-03 | Vérifier valeur par défaut `false` | Aucun réglage de RTC | [ ] |
| T05 | V01-03 | Régler date/heure **réelles** une fois | Nouvelle heure définie ; retour au sketch de lecture | [ ] |
| T06 | V02-01 | LCD seul | Quatre lignes textes lisibles | [ ] |
| T07 | V02-02 | LCD avec données fictives | Maquette date, tension, jour/mois, aucun débordement 20 colonnes | [ ] |
| T08 | V02-03 | RTC + LCD partage I2C | Date DS3231 si fiable, 3 valeurs fictives ; écran stable | [ ] |
| T09 | TP01 | Afficher format complet | `JJ/MM/AAAA HH:MM:SS` depuis RTC réelle | [ ] |
| T10 | TP02 | 5 appuis sur bouton D2–GND | 5 changements de page, aucune bascule indue après relâchement | [ ] |

## Tests de compilation uniquement

Avec Arduino CLI installé et les bibliothèques présentes :

```bash
arduino-cli core install arduino:avr
arduino-cli lib install "RTClib"
arduino-cli lib install "hd44780"
arduino-cli compile --fqbn arduino:avr:uno code/V01_02_lire_ds3231
arduino-cli compile --fqbn arduino:avr:uno code/V02_03_rtc_lcd_integres
```

Ces commandes servent de point de départ ; compiler également les six autres fichiers et vérifier les dépendances installées. **Compiler n'est pas tester le LCD, la RTC, la pile ou la liaison I2C.**

## Journal à compléter

- Date :
- Modèle exact DS3231 et son type de sauvegarde :
- Modèle LCD/backpack et alimentation :
- Version Arduino IDE / RTClib / hd44780 :
- Captures scanner I2C / RTC / écran LCD :
- Résultats T01–T10 :
- Anomalies et corrections :
- Temps réel vidéo V01 / V02 :
- Décision : prêt à filmer / à corriger.

**Les dates de démonstration doivent être les dates effectivement configurées, pas les dates d'exemple figurant dans les scripts.**
