# M05 — Aide-mémoire de programmation

## Entrées / sorties numériques

```cpp
pinMode(2, INPUT_PULLUP); // D2 en entrée rappelée HIGH
pinMode(LED_BUILTIN, OUTPUT); // LED « L »
int niveau = digitalRead(2);
digitalWrite(LED_BUILTIN, HIGH);
```

Sur Uno, le bouton **D2–GND** lu avec `INPUT_PULLUP` renvoie **HIGH lorsqu'il est relâché**, **LOW lorsqu'il est pressé**.

## Anti-rebond et front

Il faut distinguer :
1. Le **niveau brut** du bouton, qui peut rebondir.
2. Le **niveau stable** confirmé après environ **35 ms**.
3. Le **front d'appui confirmé** (stable devient LOW), qui déclenche l'action **une seule fois**.

Voir le code final [V01-03](../code/V01_03_bascule_antirebond/V01_03_bascule_antirebond.ino).

## UART

- `Serial.begin(9600)` : initialise le port matériel.
- `Serial.available() > 0` : un octet est disponible.
- `Serial.read()` : retire un octet de la réception.
- `Serial.print()` et `Serial.println()` : écrivent du texte.
- `'1'` est le **caractère** 1, différent de l'entier 1.
- Pour la liaison UART entre deux équipements compatibles : généralement TX de l'un vers RX de l'autre, et vice-versa ; vérifier le domaine électrique et le GND, en plus du débit. **Ne pas câbler de périphérique externe sur D0/D1 pendant les tests USB de la Uno.**

## Temporisations

```cpp
const unsigned long PERIODE_MS = 1000UL;
unsigned long precedentMs = 0;

void loop() {
  unsigned long maintenant = millis();
  if ((unsigned long)(maintenant - precedentMs) >= PERIODE_MS) {
    precedentMs = maintenant;
    // Executer une tache periodique
  }
  // Les autres taches restent accessibles entre deux periodes.
}
```

- `delay()` met l'exécution principale en attente ; cela retarde la prise en compte des commandes.
- `millis()` fournit une valeur en millisecondes ; **ne pas convertir son nombre brut en calendrier ou kWh**.
- La soustraction avec un `unsigned long` gère le retour du compteur, pour des intervalles dans sa plage et suffisamment courts.
- Ne pas interpréter `1000UL` comme une garantie de précision au millième de seconde : la charge du programme influe sur le moment exact de traitement.

Sources officielles : [exemples Arduino](https://docs.arduino.cc/built-in-examples/), [Serial.read()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/read/), [delay()](https://docs.arduino.cc/language-reference/en/functions/time/delay/).
