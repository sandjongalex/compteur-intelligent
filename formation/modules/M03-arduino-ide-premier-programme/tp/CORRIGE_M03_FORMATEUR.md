# Module 03 — Corrigés du formateur

## TP 01

Le sketch minimal contient une fonction `setup()` vide et une fonction `loop()` vide. Une compilation réussie confirme que la syntaxe et la configuration sont suffisantes. Le téléversement réussi confirme que le programme a été transmis. **Aucune LED clignotante n'est attendue pour le sketch minimal.**

Une accolade fermante manquante provoque une erreur de syntaxe. La correction consiste à rétablir l'accolade, puis à recommencer par **Vérifier**.

**Barème /10** : installation et carte 2 ; sélection du port 2 ; vérifier 2 ; téléverser 2 ; identifier et corriger l'erreur 2.

## TP 02

| Étape | Réponse attendue |
|---|---|
| LED intégrée | `LED_BUILTIN`, broche D13 sur Uno Rev3 ; HIGH puis LOW |
| LED externe | D8 → résistance 330 Ω → anode LED → cathode LED → GND |
| Configuration | `pinMode(LED_PIN, OUTPUT);` dans `setup()` |
| Clignotement de base | `delay(1000)` après HIGH puis LOW |
| Exercice modifié | `delay(250)` après HIGH ; `delay(750)` après LOW |

Le corrigé complet et prêt à être téléversé est [03_exercice_correction.ino](../code/03_exercice_correction/03_exercice_correction.ino).

**Barème /10** : résistance et polarité 3 ; câblage D8–GND 2 ; code correct 3 ; explication claire et résultat observé 2.

**Attention :** si la LED est reliée sans résistance, faire corriger le câblage **USB débranché** avant une nouvelle tentative.

## Références

- https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-uploading-a-sketch/
- https://docs.arduino.cc/built-in-examples/basics/Blink
