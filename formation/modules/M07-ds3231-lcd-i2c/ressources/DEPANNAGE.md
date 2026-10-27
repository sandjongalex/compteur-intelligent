# M07 — Dépannage pas à pas

| Symptôme | Cause probable | Vérification |
|---|---|---|
| Aucun appareil dans le scanner | SDA/SCL mal câblés, GND absent, alimentation ou niveaux incompatibles | Couper l'USB, vérifier Uno A4/A5, GND et tensions avant de reprendre |
| Scanner montre 0x57 mais pas 0x68 | Une EEPROM peut répondre sans que la RTC soit accessible | Revoir la carte et sa documentation ; 0x57 n'est pas le DS3231 |
| RTC détectée mais heure absurde | Horloge jamais réglée, pile épuisée/inadaptée ou perte de l'oscillateur | Signaler l'erreur, vérifier le module, régler volontairement une fois |
| Heure revient à la compilation | `rtc.adjust(DateTime(F(__DATE__),F(__TIME__)))` exécuté à chaque redémarrage | Retirer l'ajustement du firmware normal et utiliser le réglage ponctuel |
| Scanner détecte une adresse LCD mais aucun texte | Contraste, adaptateur, pilote LCD incompatible | Essayer **hd44780 → ioClass → hd44780_I2Cexp → I2CexpDiag**, vérifier le contraste |
| Message `lcd.begin` en échec | LCD absent, mauvais adaptateur, problème électrique | Analyser le code d'état et la documentation du matériel |
| Texte résiduel lorsque la valeur raccourcit | Ancienne ligne partiellement écrasée | Écrire une ligne complète de 20 caractères avec espaces |
| LCD clignote en permanence | `lcd.clear()` ou réinitialisation répétée dans `loop()` | Initialiser une seule fois ; rafraîchir au rythme utile |
| Deux appareils ne marchent pas ensemble | Adresses en conflit ou mauvais niveaux électriques/pull-ups | Scanner séparément et conjointement, vérifier fiches techniques |
| kWh du jour ou du mois ne changent pas | Données fixes du module M07 | C'est normal : **SIMULATION** jusqu'au calcul du M08 |

**Sécurité :** aucune manipulation du secteur, aucune alimentation de pile incompatible, aucune modification des fils lorsque l'USB est branché.
