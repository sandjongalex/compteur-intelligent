/*
 * M05-V01 | Etape 1 : une entree pilote directement une sortie.
 * Arduino Uno R3. Bouton-poussoir entre D2 et GND.
 * INPUT_PULLUP: relache=HIGH ; appuye=LOW.
 * La LED integree suit le maintien du bouton.
 */
const byte BROCHE_BOUTON = 2;
const byte BROCHE_LED = LED_BUILTIN;

void setup() {
  pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  pinMode(BROCHE_LED, OUTPUT);
}

void loop() {
  bool boutonAppuye = (digitalRead(BROCHE_BOUTON) == LOW);
  digitalWrite(BROCHE_LED, boutonAppuye ? HIGH : LOW);
}
