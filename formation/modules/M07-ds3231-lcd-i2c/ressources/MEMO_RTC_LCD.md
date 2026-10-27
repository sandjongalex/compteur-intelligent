# M07 — Mémo du débutant : DS3231, I2C, LCD

| Terme / fonction | Signification |
|---|---|
| **I2C** | Bus permettant à plusieurs périphériques de partager des lignes de données **SDA** et d'horloge **SCL** |
| **Wire.begin()** | Démarre la communication I2C sur l'Arduino |
| **Scanner I2C** | Interroge des adresses pour repérer les périphériques qui répondent |
| **0x68** | Adresse habituelle de l'horloge DS3231 |
| **rtc.begin()** | Vérifie la présence du DS3231 |
| **rtc.lostPower()** | Signale que l'oscillateur de la RTC a été arrêté : heure potentiellement invalide |
| **rtc.now()** | Obtient un objet DateTime contenant date et heure |
| **rtc.adjust(...)** | Règle l'horloge ; à utiliser volontairement, pas systématiquement à chaque démarrage |
| **lcd.begin(20,4)** | Initialise 20 colonnes sur 4 lignes avec bibliothèque **hd44780** |
| **lcd.setCursor(0,2)** | Place le curseur colonne 0, **troisième** ligne |
| **lcd.print(...)** | Écrit des caractères sur l'écran |
| **millis()** | Permet de déclencher un rafraîchissement à intervalles sans `delay()` |

## Trois questions à se poser avant de filmer

1. **La date est-elle réelle et fiable ?** Une RTC non réglée ne doit pas fournir de base pour les calculs jour/mois.
2. **Les kWh présentés sont-ils fictifs ?** Dans ce module **oui** : la différence d'index énergétique est étudiée en M08.
3. **L'écran est-il stable ?** On remplace la ligne utile et évite `lcd.clear()` dans `loop()`.

## Maquette 20×4

```text
DATE: 27/10/2026
TENSION: 230.5 V
JOUR:    4.250 kWh
MOIS:  125.480 kWh
```

La maquette indique une **date d'exemple et des mesures fictives**. Le premier champ peut ensuite être remplacé par la date réelle du DS3231.

## Formats

- `%02u` : entier avec au moins deux chiffres, zéro de tête.
- `%04u` : entier avec au moins quatre chiffres.
- `char tampon[21]` : 20 caractères LCD plus le caractère terminal `'\0'`.
- Une bibliothèque LCD peut proposer d'autres noms de méthodes : utiliser **hd44780** choisie, et ne pas copier sans adaptation des exemples `LiquidCrystal_I2C`.

Sources :
- https://github.com/adafruit/RTClib
- https://github.com/duinoWitchery/hd44780
