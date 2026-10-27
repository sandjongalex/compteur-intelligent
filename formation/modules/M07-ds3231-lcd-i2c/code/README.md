# Code Arduino — Module M07 (DS3231 + LCD I2C 20×4)

**Carte : Arduino Uno Rev3 · IDE 2 · USB uniquement pour Arduino · Composants I2C basse tension.**

## Progression des vidéos

| Étape | Programme | Résultat |
|---|---|---|
| V01-01 | [Scanner I2C](V01_01_scanner_i2c/V01_01_scanner_i2c.ino) | Voir adresses DS3231 **0x68**, éventuellement EEPROM **0x57**, et LCD souvent **0x27/0x3F** selon adaptateur |
| V01-02 | [Lire DS3231](V01_02_lire_ds3231/V01_02_lire_ds3231.ino) | Date/heure sur Serial, mais **pas de date inventée** si horloge non fiable |
| V01-03 | [Régler une seule fois](V01_03_regler_ds3231_une_fois/V01_03_regler_ds3231_une_fois.ino) | Par défaut bloqué ; date locale réglée uniquement sur action explicite |
| V02-01 | [Premier affichage LCD](V02_01_lcd_bonjour/V02_01_lcd_bonjour.ino) | 4 lignes texte sur LCD |
| V02-02 | [Quatre lignes fictives](V02_02_lcd_4_lignes_simulees/V02_02_lcd_4_lignes_simulees.ino) | Date, tension fictive, kWh jour/mois fictifs |
| V02-03 | [DS3231 + LCD](V02_03_rtc_lcd_integres/V02_03_rtc_lcd_integres.ino) | Date réelle de la RTC ; **tension/énergies fictives** ; rafraîchissement partiel |
| Corrigé | [TP01 : JJ/MM/AAAA HH:MM:SS](TP01_corrige_date_heure/TP01_corrige_date_heure.ino) | Date/heure complète en série |
| Corrigé | [TP02 : 2 pages](TP02_corrige_page_lcd/TP02_corrige_page_lcd.ino) | Bouton D2, pages 0/1, état stable et anti-rebond |

## Dépendances précises

- **RTClib** (Adafruit) : `RTC_DS3231`, `rtc.begin()`, `rtc.lostPower()`, `rtc.now()`, `rtc.adjust()`. Installer ses dépendances proposées (notamment Adafruit BusIO) avec le gestionnaire de bibliothèques.
- **hd44780** (Bill Perry / duinoWitchery), interface **`hd44780_I2Cexp`** pour LCD HD44780 avec adaptateur I2C de type expander PCF8574/MCP23008. Cette bibliothèque détecte l'adresse et le brochage du backpack compatible. Elle diffère de plusieurs bibliothèques homonymes `LiquidCrystal_I2C`.
- **Wire** : fourni par le cœur Arduino AVR.

**À confirmer sur le matériel choisi :** 5 V uniquement si chaque *carte complète* LCD/RTC est compatible avec l'alimentation, les résistances de rappel et les niveaux logiques. Les broches SDA/SCL sont partagées sur les appareils I2C compatibles : **Uno SDA=A4, SCL=A5**.

## Comment régler l'horloge sans créer de fausses données

1. Commencer par le scanner et `V01_02` ; si `lostPower()` signale une heure non fiable, **ne pas la supposer correcte**.
2. Vérifier la pile de sauvegarde et le circuit de la **carte DS3231 exacte** (certains modules ZS-042 ont un circuit de charge inadapté à une pile primaire CR2032).
3. Dans `V01_03`, remplacer les constantes d'exemple par la **date/heure locale réelle** au moment de l'essai et passer `AUTORISER_REGLAGE_UNIQUE` à `true` de façon intentionnelle. Téléverser **une fois**.
4. Ensuite **revenir immédiatement à V01_02** (ou un autre sketch sans `rtc.adjust()`) ; ne pas garder l'utilitaire de réglage comme firmware du compteur.
5. Couper/rebrancher l'USB pour vérifier que la date avance et se conserve. Le DS3231 ne connaît **pas automatiquement le fuseau horaire** : choisir et documenter l'heure locale.

**Ne jamais exécuter `rtc.adjust(DateTime(F(__DATE__), F(__TIME__)))` à chaque redémarrage** ; cela remettrait la RTC à l'heure de compilation (parfois obsolète).

## Maquette d'écran (20 caractères × 4 lignes)

```text
DATE: 27/10/2026
TENSION: 230.5 V
JOUR:    4.250 kWh
MOIS:  125.480 kWh
```

Toutes les valeurs des lignes 2 à 4 sont **SIMULÉES**. Le calcul réel des consommations jour/mois dépend des index énergétiques et de la RTC ; il est prévu en **M08**. La date de la première ligne peut venir du DS3231 si elle est fiable.

## Prévention des clignotements

Le code réécrit uniquement les positions utiles (ou la ligne complète rembourrée de 20 caractères), **sans `lcd.clear()` dans `loop()`**, à intervalles raisonnables. Il vérifie `lcd.begin(20,4)` avant d'écrire.

**Statut : contenu de code rédigé ; compilation officielle Arduino et essais I2C/LCD physiques restant à effectuer et tracer dans [PLAN_TESTS.md](../ressources/PLAN_TESTS.md).**

Sources :
- https://github.com/adafruit/RTClib
- https://github.com/duinoWitchery/hd44780
