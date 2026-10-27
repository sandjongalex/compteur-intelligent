/*
 * M05-V01 | Etape 2 : detecter le front d'appui.
 * DEMONSTRATION VOLONTAIREMENT INCOMPLETE: un bouton mecanique
 * peut rebondir et faire basculer plusieurs fois la LED.
 * La correction est dans V01_03_bascule_antirebond.
 */
const byte BROCHE_BOUTON = 2;
const byte BROCHE_LED = LED_BUILTIN;
bool ancienEtatAppuye = false;
bool ledAllumee = false;

void setup() {
  pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  pinMode(BROCHE_LED, OUTPUT);
  digitalWrite(BROCHE_LED, LOW);
}

void loop() {
  bool appuye = (digitalRead(BROCHE_BOUTON) == LOW);
  if (appuye && !ancienEtatAppuye) { // transition relache -> appuye
    ledAllumee = !ledAllumee;
    digitalWrite(BROCHE_LED, ledAllumee ? HIGH : LOW);
  }
  ancienEtatAppuye = appuye;
}
