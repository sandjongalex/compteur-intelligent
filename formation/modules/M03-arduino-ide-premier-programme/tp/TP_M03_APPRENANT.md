# Module 03 — TP apprenant (hors 14 min de vidéo)

## TP 01 — Installer, vérifier et téléverser

**Durée indicative : 20 à 30 min** · **Niveau : débutant.**

### Matériel

- Ordinateur, Arduino IDE 2, câble USB de données.
- Arduino Uno Rev3 pour l'étape de téléversement.

### Consignes

1. Télécharger Arduino IDE 2 depuis https://www.arduino.cc/en/software.
2. Brancher l'Arduino Uno à l'ordinateur.
3. Sélectionner **Arduino Uno** et le port de la carte.
4. Ouvrir le sketch [00_premier_sketch.ino](../code/00_premier_sketch/00_premier_sketch.ino).
5. Cliquer sur **Vérifier** et noter les messages de compilation.
6. Cliquer sur **Téléverser**, puis noter les messages de confirmation.
7. Sur une **copie**, retirer la dernière accolade et noter l'erreur après vérification ; remettre l'accolade avant de reprendre.

**Livrable :** captures du code, du résultat de compilation, de la confirmation de téléversement et d'une erreur volontaire.

**À expliquer :** quelle différence existe entre Vérifier et Téléverser ? Pourquoi le programme minimal ne fait-il rien de visible ?

## TP 02 — Première LED interne puis externe

**Durée indicative : 20 à 30 min** · **Aucune connexion au secteur autorisée.**

### Matériel

- Arduino Uno Rev3 alimentée par USB.
- Une LED standard + **résistance 330 Ω** en série + breadboard pour l'exercice externe.
- Le [schéma basse tension](../ressources/SCHEMA_LED.md).

### Consignes

1. Ouvrir [01_blink_interne.ino](../code/01_blink_interne/01_blink_interne.ino), vérifier et téléverser.
2. Observer la LED **L** de la Uno, allumée 1 seconde puis éteinte 1 seconde.
3. Débrancher l'USB, placer le circuit **D8 → R 330 Ω → LED → GND** avec polarité correcte.
4. Rebrancher l'USB, ouvrir et téléverser [02_blink_externe.ino](../code/02_blink_externe/02_blink_externe.ino).
5. Modifier le programme pour avoir **250 ms ON** et **750 ms OFF**.
6. Vérifier et téléverser, puis décrire le résultat. Ne jamais modifier les fils avec USB branché.

**Livrable :** photo du montage **hors tension**, code modifié et courte description du clignotement. Les tests matériels doivent être réels, pas simulés.

## Évaluation

- TP01 : sélection correcte, compilation, téléversement, diagnostic d'une erreur.
- TP02 : résistance obligatoire, polarité LED correcte, rythme obtenu et code expliqué.
- Ne pas passer au montage matériel si une erreur de sécurité n'a pas été corrigée.

[Corrigés et barèmes](CORRIGE_M03_FORMATEUR.md)
