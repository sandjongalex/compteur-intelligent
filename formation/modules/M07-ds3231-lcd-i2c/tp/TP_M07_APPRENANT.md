# M07 — Travaux pratiques (version apprenant)

**Deux TP autonomes, hors des 14 minutes de vidéo. Durée conseillée : 35 à 55 minutes.**  
Arduino Uno Rev3, DS3231 et LCD I2C 20×4 **compatibles**, câble USB. Ne travailler **qu'en basse tension**, débrancher l'USB pour modifier les connexions.

## TP01 — Afficher une date et une heure fiables

**Objectif :** lire et formater une date depuis une RTC DS3231 **réellement configurée**, sans la remettre à l'heure à chaque redémarrage.

1. Consulter le [schéma fonctionnel du bus](../ressources/BUS_I2C_SECURITE.md).
2. Ouvrir le [scanner I2C](../code/V01_01_scanner_i2c/V01_01_scanner_i2c.ino) ; repérer **0x68** dans le moniteur série (si votre module fonctionne).
3. Ouvrir [V01-02 — lire la RTC](../code/V01_02_lire_ds3231/V01_02_lire_ds3231.ino).
4. Vérifier la présence du DS3231 et le résultat de `rtc.lostPower()`. Si l'heure est invalide, **ne pas inventer de date**. Utiliser, après contrôle de la pile/module, l'[utilitaire volontaire](../code/V01_03_regler_ds3231_une_fois/V01_03_regler_ds3231_une_fois.ino) une seule fois.
5. Modifier l'affichage du moniteur pour obtenir le format **`JJ/MM/AAAA HH:MM:SS`**, avec des zéros devant les nombres inférieurs à dix.
6. Redémarrer l'Arduino après le réglage ; vérifier que l'horloge progresse et que le sketch **de lecture seul** ne contient pas de réglage automatique.

**Résultat attendu :** une ligne au format `07/11/2026 08:05:03` *uniquement comme exemple de forme*, suivie de valeurs de l'horloge réellement configurée. La date d'exemple ne doit pas être présentée comme la date effectivement mesurée.

**Livrables :** sketch modifié, une sortie série réelle (date de votre essai) et une explication de `rtc.begin()`, `lostPower()`, `now()` et `adjust()`.

**Question :** quel risque court-on si on remplace `rtc.adjust()` dans la boucle `loop()` ?

## TP02 — Afficher quatre lignes et ajouter une page

**Objectif :** utiliser le LCD I2C sans dépassement de 20 caractères et créer une seconde page d'informations fictives.

1. Scanner le bus ; constater que le DS3231 et l'adaptateur LCD peuvent partager SDA/SCL, à des adresses distinctes.
2. Ouvrir [V02-01 — Premier LCD](../code/V02_01_lcd_bonjour/V02_01_lcd_bonjour.ino), tester l'initialisation `lcd.begin(20,4)`.
3. Ouvrir [V02-03 — LCD avec RTC](../code/V02_03_rtc_lcd_integres/V02_03_rtc_lcd_integres.ino).
4. Vérifier que la page affiche les quatre champs **date, tension, énergie du jour, énergie du mois**. Les valeurs électriques sont **fictives** ; la date peut venir de la RTC si elle est fiable.
5. Créer une seconde page montrant **`COURANT: 0.500 A`** et **`PUISSANCE: 92.2 W`**, ainsi que la mention `DONNEES FICTIVES`.
6. Réutiliser le bouton sur **D2–GND** du Module 05 pour changer de page sur un seul appui validé, sans `delay()`.
7. Vérifier qu'aucune ligne ne dépasse **20 caractères** et que le programme n'efface pas tout l'écran à chaque passage dans `loop()`.

**Livrables :** sketch, une vidéo/photo du LCD en fonctionnement, explication de `setCursor(colonne,ligne)`, des mises à jour et de l'anti-rebond.

## Auto-évaluation

- [ ] Je peux vérifier physiquement la présence des appareils I2C.
- [ ] Je sais reconnaître et signaler une date non fiable.
- [ ] Je peux afficher sans effacer inutilement tout le LCD.
- [ ] Je peux distinguer une mesure fictive d'une mesure provenant réellement du PZEM.
- [ ] Je peux changer d'écran grâce à un bouton avec anti-rebond.

[Corrigés et barèmes formateur](CORRIGE_M07_FORMATEUR.md).
