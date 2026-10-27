# M07 — Corrigés formateur et barèmes

## TP01 — Date complète

**Code corrigé :** [TP01_corrige_date_heure.ino](../code/TP01_corrige_date_heure/TP01_corrige_date_heure.ino).

Étapes attendues :
1. Scanner le bus : le DS3231 apparaît normalement à `0x68` ; l'adresse `0x57` peut venir d'une EEPROM additionnelle sur certains modules.
2. `rtc.begin()` indique si la RTC répond.
3. `rtc.lostPower()` indique qu'une interruption de l'oscillateur peut avoir rendu l'heure non fiable.
4. Si nécessaire, réglage **volontaire et ponctuel**, puis retour immédiat au sketch de lecture.
5. `rtc.now()` et `DateTime` donnent les valeurs à afficher ; `snprintf` les met dans le format `%02u/%02u/%04u %02u:%02u:%02u`.

La sortie de l'apprenant contient la **date réelle configurée sur son banc**. Ne pas utiliser une date d'exemple comme preuve.

**Barème /10 :** identification I2C (2), contrôle de l'heure fiable (2), format exact (3), conservation après redémarrage (2), explication pédagogique (1).

## TP02 — LCD quatre lignes et page alternative

**Code corrigé :** [TP02_corrige_page_lcd.ino](../code/TP02_corrige_page_lcd/TP02_corrige_page_lcd.ino).

Page principale (les valeurs hors date sont **fictives**) :

```text
DATE: 27/10/2026
TENSION: 230.5 V
JOUR:    4.250 kWh
MOIS:  125.480 kWh
```

La ligne de date doit être remplacée par la vraie date **si la RTC est initialisée et fiable** ; sinon afficher `DATE: A REGLER`.

Page secondaire :

```text
PAGE 2: DETAILS
COURANT: 0.500 A
PUISSANCE: 92.2 W
DONNEES FICTIVES
```

**Pourquoi une ligne complète ?** Elle est rembourrée à 20 caractères pour écraser les résidus d'un texte plus long. Le rafraîchissement avec `millis()` évite une attente bloquante ; le bouton utilise une validation stable après ~35 ms.

**Barème /10 :** détection du LCD et adressage (2), bonne page principale (2), seconde page (2), un seul changement par appui (2), absence de clignotement excessif/explication des mises à jour (2).

## Points de remédiation

- Si aucune adresse n'apparaît : vérifier les connexions et niveaux **hors tension**, l'alimentation du module et le câble USB.
- Si le LCD est allumé mais sans texte : essayer `I2CexpDiag` et vérifier le contraste du backpack.
- Si une page montre des résidus de caractères : supprimer l'ancien texte par écriture de la ligne entière avec espaces, pas en appelant `lcd.clear()` à chaque tour.
- Si la date « saute » après un redémarrage : vérifier le **sketch de réglage**, la RTC, sa sauvegarde et la configuration de l'heure, au lieu de forcer `adjust` à chaque boot.

**Seuil conseillé : 8/10 par TP**, les manipulations restent basse tension uniquement.
