# M03 — Dépannage : installation et LED

| Symptomatique | Cause probable | Vérification non dangereuse |
|---|---|---|
| Le port n'apparaît pas | Câble USB de recharge uniquement, pilote/permission, mauvaise prise | Tester un câble **de données**, changer de prise USB, vérifier les autorisations |
| « Board not found » ou carte absente | Carte non sélectionnée | Sélectionner **Arduino Uno** explicitement |
| Compilation échoue | Accolade ou point-virgule manquant ; faute de syntaxe | Lire le premier message d'erreur, comparer au code corrigé |
| Compilation OK, téléversement échoue | Port incorrect, câble, autre application utilisant le port | Vérifier carte, port et connexion USB |
| Téléversement OK, sketch minimal ne fait rien | Normal ! aucune instruction d'affichage | Passer au sketch LED_BUILTIN |
| LED intégrée L ne clignote pas | Mauvais sketch / carte ou téléversement réellement non abouti | Refaire une vérification et un téléversement, observer les messages |
| LED externe ne s'allume pas | Polarité inversée, résistance/fils, mauvais numéro de broche | **Débrancher l'USB**, contrôler le circuit D8–R–LED–GND |
| LED externe reste allumée | Sketch ou connexion incohérents | Vérifier HIGH/LOW, delay et câblage hors tension |

## Exemple d'erreur volontaire à montrer en vidéo

**Ne pas recopier comme un programme final :** manque le point-virgule après une instruction.

```cpp
digitalWrite(LED_BUILTIN, HIGH)  // Erreur : « ; » manquant
```

Correction :

```cpp
digitalWrite(LED_BUILTIN, HIGH);
```

## Vérification finale

Le formateur doit montrer les messages **réels** d'Arduino IDE et un clignotement **réel** de la LED, non une animation présentée comme un test matériel.
