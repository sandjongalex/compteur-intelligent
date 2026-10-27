# M05 — Câblage exclusivement basse tension

## Matériel

- 1 Arduino Uno Rev3 / ATmega328P.
- 1 bouton-poussoir momentanée (4 broches possible), quelques fils et une breadboard basse tension.
- 1 câble USB de données et un ordinateur avec Arduino IDE 2.
- Utiliser la **LED intégrée L** de la Uno : aucun montage LED externe requis.

## Connexion du bouton

```text
Arduino Uno Rev3                     Bouton-poussoir
      D2  -------------------------- contact A
      GND -------------------------- contact B
```

Le contact A et le contact B ne doivent être reliés électriquement **que pendant l'appui**.

**Important avec les boutons à quatre pattes :** certaines paires de pattes sont reliées en permanence à l'intérieur du composant. Choisir deux pattes qui ne se touchent électriquement qu'à l'appui, et vérifier la documentation ou un contrôle hors tension. Éviter les liaisons directes 5 V–GND.

Le code utilise `pinMode(2, INPUT_PULLUP)` : **HIGH = relâché**, **LOW = appuyé**. Pas de résistance externe de rappel nécessaire pour cette démonstration.

## Écran/moniteur série

- Le moniteur série du PC utilise l'USB et le port matériel `Serial` de la Uno.
- `Serial.begin(9600)` implique **9600 bauds** côté PC.
- Envoyer `1`, `0`, `?` ; les retours chariot et sauts de ligne éventuels sont ignorés.
- Les broches D0/RX et D1/TX sont utilisées par le port série matériel : **ne pas les relier au SIM800L ou au PZEM pendant cet apprentissage via USB**.
- Ce module **n'enseigne pas encore** le raccordement physique du PZEM/SIM800L ou l'adaptation des niveaux logiques.

## Sécurité

- Débrancher le câble USB avant de déplacer les fils.
- N'utiliser que l'alimentation USB normale de l'Uno.
- **Aucun secteur 230 V**, aucune alimentation AC/DC ouverte, aucun PZEM alimenté, aucun modem GSM relié à l'USB durant le Module 05.
