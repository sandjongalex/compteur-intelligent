# M04 — Corrigés formateur des TP

## TP01

- Données 500 W pendant 2 h → `(500/1000) * 2 = 1.000 kWh`.
- Nouvelles données 200 W pendant 5 h → `(200/1000) * 5 = 1.000 kWh`.
- `5 / 2` avec des entiers vaut `2` ; `5.0f / 2.0f` vaut `2.5`. Il faut utiliser une division décimale si l'on souhaite la partie fractionnaire.

**Barème /10 :** calcul d'origine (2), changement des variables (2), moniteur série (2), division entière (2), explication des unités (2).

## TP02

- `245.0f > 240.0f` est vrai : affiche une **alerte pédagogique fictive**.
- `230.0f > 240.0f` est faux : affiche « Mesure fictive dans la plage de l'exercice ».
- Une boucle pour afficher de 1 à 4 utilise `for (int i = 1; i <= 4; i++)`.
- `while` doit modifier `essais` pour finir après les trois passages.
- `wattsVersKilowatts(1250.0f)` renvoie **1.25**.
- 400 W pendant 2.5 h → `0.4 * 2.5 = 1.000 kWh`.

**Barème /10 :** choix condition (2), modification tension (2), for bornée (2), while bornée (1), retour de fonction (2), calcul énergie (1).

## Points de vigilance

Le moniteur série doit être réglé à **9600 bauds** et les exemples restent simulés. On ne valide pas une compétence de programmation par une capture de PowerPoint : le formateur fera réellement compiler et téléverser le code sur une Uno Rev3.
