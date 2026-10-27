# M08 — Firmware fil rouge et programme principal

Cette version conserve **toutes les fonctions M05/M06/M07** : bouton avec anti-rebond, LED, commandes USB série, acquisition des six grandeurs et affichage optionnel DS3231 + LCD. **Elle ajoute les kWh journaliers et mensuels**, basés sur un index en Wh entiers et une date.

## Par défaut : exécutable sans secteur

`ALEXTECH_PZEM_REEL 0` et `ALEXTECH_RTC_LCD_REELS 0` : une Arduino Uno branchée uniquement en USB peut simuler la tension, le courant, l'index et la date. Le code n'a besoin que des fichiers `.ino` et `EnergieM08.h` du **même dossier**. Le moniteur série est à 9600 bauds. Aucun composant secteur.

## Brancher uniquement les périphériques basse tension

Pour utiliser DS3231 et LCD avec des cartes électriquement compatibles et vérifiées, installer Adafruit **RTClib** (+ BusIO) et **hd44780** (Bill Perry) ; activer `ALEXTECH_RTC_LCD_REELS 1` sur banc basse tension. La date est alors réellement lue et sa validité contrôlée ; aucune fonction `rtc.adjust()` n'est invoquée dans ce firmware normal.

**Le PZEM réel :** `ALEXTECH_PZEM_REEL 1` exige bibliothèque `PZEM004Tv30` et banc secteur conçu, monté et utilisé **par une personne qualifiée**. La simple activation n'autorise pas un montage novice sur 230 V. Avec la bibliothèque qui renvoie des `float` en kWh, la conversion en Wh peut perdre de la précision sur de grands index : l'interface de production devra accéder aux registres bruts/être validée (M16).

## Qualité et limites

- `~` sur LCD = **période PARTIELLE** ; démarrer à midi ne veut pas dire « 0 kWh consommé depuis minuit ».
- Une date incohérente et une lecture invalide sont rejetées ; un index qui diminue entraîne un réancrage.
- **Pas de persistance** : le moteur conserve son état en RAM ; une vraie coupure perd les cumuls. La FRAM sera ajoutée au M11.
- `horlogeDemo()` est un calendrier fictif lié à `millis()`, limité à des démonstrations courtes ; **pas une RTC de remplacement**.
- Le code affiche les six grandeurs M06 mais ne prétend pas encore communiquer par GSM, sauvegarder durablement ou faire de la facturation certifiée.

[Sketch M08](Compteur_M08.ino) · [Version courante](../../../courant/CompteurIntelligent/CompteurIntelligent.ino) · [Plan du fil rouge](../../../README.md)
