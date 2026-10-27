# M04 — Sketches Arduino C/C++ (Uno Rev3)

**Statut : exemples rédigés, compilation et téléversement sur vraie Uno à confirmer par le formateur.** Tous les nombres électriques sont des **données fictives**.

| Dossier | Sujet | Sortie attendue sur moniteur série |
|---|---|---|
| [01_variables_calculs](01_variables_calculs/01_variables_calculs.ino) | `float`, `const`, calcul d'énergie | `Energie fictive : 1.000 kWh` |
| [02_division_types](02_division_types/02_division_types.ino) | division entière / décimale | `2` puis `2.5` |
| [03_conditions_boucles](03_conditions_boucles/03_conditions_boucles.ino) | `if/else`, `for`, `while` finie | alerte fictive, relevés 1–3, essais terminés : 3 |
| [04_fonctions](04_fonctions/04_fonctions.ino) | paramètre, `return` | `0.50 kW`, `1.25 kW` |
| [05_exercice_corrige](05_exercice_corrige/05_exercice_corrige.ino) | énergie fictive, fonction réutilisable | `1.000 kWh` |

## Comment utiliser

1. Ouvrir Arduino IDE 2 ; choisir la **carte Arduino Uno Rev3** et le bon port.
2. Ouvrir le fichier `.ino` qui porte le même nom que son dossier.
3. Cliquer sur **Vérifier** pour compiler ; corriger si nécessaire.
4. Téléverser vers une Uno Rev3 branchée en USB.
5. Ouvrir **Moniteur série** à **9600 bauds**, observer les sorties attendues.
6. Modifier une valeur et vérifier qu'un changement cohérent apparaît.

**Aucun câble relié au secteur, au PZEM ou au SIM800L n'est requis.**

## Précautions sur les types

- Sur **ATmega328P (Arduino Uno Rev3, architecture AVR)**, `int` fait **16 bits** ; `float` fait **32 bits** et ne représente pas toutes les fractions exactement.
- Une division entre deux entiers élimine la partie fractionnaire : `5 / 2` vaut `2`.
- Utiliser `1000.0f` et des `float` pour les conversions de cette initiation ; pour le compteur réel, il faudra vérifier les plages, débordements, précision et persistance des cumuls.
- Les paramètres du prototype commercial/secteur ne sont pas déduits de ces valeurs fictives.

Référence officielle : https://docs.arduino.cc/language-reference/
