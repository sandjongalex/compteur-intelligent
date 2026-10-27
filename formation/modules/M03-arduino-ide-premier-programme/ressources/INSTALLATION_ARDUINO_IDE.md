# M03 — Guide d'installation Arduino IDE 2

## Prérequis

- Ordinateur sous Windows/macOS/Linux pris en charge par l'éditeur téléchargé.
- Une Arduino Uno Rev3 pour le téléversement réel.
- Câble USB **de données** adapté au connecteur de la carte.
- Aucune installation ou connexion au secteur 230 V nécessaire.

## Procédure apprenant

1. Ouvrir https://www.arduino.cc/en/software et choisir la version d'Arduino IDE 2 compatible avec le système d'exploitation.
2. Installer et ouvrir l'éditeur.
3. Brancher l'Arduino Uno Rev3 en USB.
4. Dans le menu déroulant en haut, choisir la carte Arduino Uno et le port correspondant ; au besoin : **Tools > Board** et **Tools > Port**.
5. Ouvrir le fichier `00_premier_sketch/00_premier_sketch.ino`.
6. Cliquer sur **Vérifier (✓)** ; lire les messages en bas de l'IDE.
7. Cliquer sur **Téléverser (→)** ; observer la confirmation.
8. Ouvrir `01_blink_interne/01_blink_interne.ino`, vérifier/téléverser et observer la LED intégrée.

## À retenir : Vérifier et Téléverser

- **Vérifier** : contrôle le code, le compile, n'envoie pas obligatoirement le programme à la carte.
- **Téléverser** : compile puis transmet le programme au microcontrôleur de la carte sélectionnée.

## Captures recommandées pour la vidéo

- L'adresse officielle du téléchargement.
- Sélecteur de carte et de port.
- Code minimal : fonctions `setup()` et `loop()`.
- Console indiquant que la **compilation** a réussi.
- Console indiquant que le **téléversement** a réussi.

Les captures **doivent provenir d'un vrai test** ; les supports PowerPoint sont des explications graphiques, pas des preuves de téléversement.

## Aide

En cas de problème, voir [Guide de dépannage](DEPANNAGE.md) et la documentation :
- https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing
- https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-uploading-a-sketch/
