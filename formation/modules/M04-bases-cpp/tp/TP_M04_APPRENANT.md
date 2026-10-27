# M04 — Travaux pratiques : version apprenant

**Durée hors vidéo : 25 à 40 minutes.** Aucun raccordement secteur. Arduino Uno Rev3 + ordinateur + Arduino IDE 2, moniteur série à **9600 bauds**.

## TP01 — Variables, types et calcul d'énergie

**Objectif :** utiliser des variables `float` et calculer une énergie fictive.

**À faire :**

1. Ouvrir [01_variables_calculs.ino](../code/01_variables_calculs/01_variables_calculs.ino).
2. Lire les valeurs initiales `puissanceW = 500.0f` et `dureeHeures = 2.0f`.
3. Prévoir l'énergie affichée : ........... kWh.
4. Vérifier et téléverser, puis observer le moniteur série à 9600 bauds.
5. Modifier les valeurs pour `puissanceW = 200.0f` et `dureeHeures = 5.0f`. Quelle nouvelle valeur est affichée ?
6. Ouvrir [02_division_types.ino](../code/02_division_types/02_division_types.ino) et expliquer pourquoi `5 / 2` et `5.0 / 2.0` ne donnent pas le même résultat.

**Livrable :** code modifié, capture de la console et deux réponses expliquées.

## TP02 — Conditions, boucles et fonction de conversion

**Objectif :** lire une condition, modifier une boucle finie, appeler une fonction.

**À faire :**

1. Ouvrir [03_conditions_boucles.ino](../code/03_conditions_boucles/03_conditions_boucles.ino).
2. Avec tension fictive `245.0f` et seuil pédagogique `240.0f`, prédire le message de `if / else`.
3. Modifier **uniquement la donnée fictive** pour `230.0f`, observer quelle branche est exécutée.
4. Modifier la boucle `for` pour afficher **1 à 4**, puis expliquer les trois parties du `for`.
5. Vérifier que la boucle `while` termine bien : ne jamais effacer l'incrémentation sans comprendre les conséquences.
6. Ouvrir [04_fonctions.ino](../code/04_fonctions/04_fonctions.ino) et appeler `wattsVersKilowatts(1250.0f)`.
7. Modifier l'[exercice corrigé](../code/05_exercice_corrige/05_exercice_corrige.ino) en utilisant `400 W` pendant `2.5 h`.

**Livrable :** sketch modifié, valeurs attendues et explication du rôle de `return`.

**Sécurité :** les tensions utilisées sont **simulées** ; 240 V ne représente pas un seuil de protection électrique réelle.

## Validation

- L'apprenant explique les différences `int` / `float` / `bool`, `=` / `==` et `for` / `while`.
- Il calcule une énergie en kWh à partir d'une puissance active constante.
- Il peut identifier une erreur de calcul même lorsque le programme compile.
