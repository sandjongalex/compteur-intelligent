# M03 — Code Arduino et fichiers techniques

**Cible : Arduino Uno R3 avec Arduino IDE 2**. Les sketches sont prêts à **compiler et tester sur une vraie carte**. **Aucune validation matérielle par le formateur n'est encore déclarée.**

## Dossiers et résultats

| Dossier | Résultat attendu |
|---|---|
| [00_premier_sketch](00_premier_sketch/00_premier_sketch.ino) | Compile et se téléverse, sans action visible |
| [01_blink_interne](01_blink_interne/01_blink_interne.ino) | LED intégrée L : 1 s ON / 1 s OFF |
| [02_blink_externe](02_blink_externe/02_blink_externe.ino) | LED externe sur D8 : 1 s ON / 1 s OFF |
| [03_exercice_correction](03_exercice_correction/03_exercice_correction.ino) | LED externe sur D8 : 250 ms ON / 750 ms OFF |

## Installation et exécution

1. Télécharger/installer Arduino IDE 2 via le site Arduino officiel.
2. Ouvrir **le fichier .ino dans le dossier portant le même nom**.
3. Brancher une Arduino Uno R3 au PC avec un câble USB de données.
4. Sélectionner **Arduino Uno** et le **port** correspondant.
5. Cliquer **Vérifier** pour compiler, puis **Téléverser** pour envoyer le programme.
6. Pour la LED externe, débrancher l'USB avant le câblage. Vérifier le [schéma D8–résistance–LED–GND](../ressources/SCHEMA_LED.md) avant de rebrancher.

## Notes

- `LED_BUILTIN` correspond à **D13 sur Uno Rev3**. Son numéro peut différer sur une autre carte.
- `delay` bloque le déroulement du programme pendant l'attente ; les temporisations non bloquantes seront étudiées au module M05.
- Le sketch `00_premier_sketch` ne produit **aucune sortie visible**, c'est normal.
- Aucun module secteur, GSM ni PZEM à connecter pendant M03.

**Documentation officielle :**
- https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-uploading-a-sketch/
- https://docs.arduino.cc/built-in-examples/basics/Blink
