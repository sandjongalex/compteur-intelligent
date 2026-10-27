# Version M07 — Fil rouge

Cette version reprend **M06** (bouton, LED, commandes UART, six grandeurs et gestion de lecture invalide) et ajoute le **DS3231 et le LCD 20×4**.

- Par défaut `ALEXTECH_RTC_LCD_REELS 0`, le sketch tourne sur une Uno USB seule : aucun capteur et aucun secteur.
- Pour essayer le LCD et la RTC : installer Adafruit **RTClib** (+ BusIO), **hd44780** de Bill Perry, vérifier les cartes, les alimentations et le bus I2C (**Uno SDA=A4, SCL=A5**), puis activer `ALEXTECH_RTC_LCD_REELS 1`.
- Les lignes JOUR/MOIS affichent **NON CALCULE** : ce n'est pas encore une fonction du M07.
- La date ne s'affiche que si `rtc.begin()`, `!rtc.lostPower()` et `now().isValid()` ; le programme ne règle **jamais** l'horloge automatiquement.
- `ALEXTECH_PZEM_REEL` reste à **0** : toute lecture secteur réelle exige un banc et un professionnel qualifiés.

Ouvrir [le sketch M07](Compteur_M07/Compteur_M07.ino) puis [la version M08](../M08/Compteur_M08/Compteur_M08.ino).
