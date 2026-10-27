/*
 * M05-V01 | Etape 3 finale : bascule de LED avec anti-rebond.
 * Bouton D2 -> GND, LED integree sur Uno Rev3.
 * Anti-rebond logiciel de 35 ms, non bloquant.
 */
const byte BROCHE_BOUTON = 2;
const byte BROCHE_LED = LED_BUILTIN;
const unsigned long ANTIREBOND_MS = 35UL;

int dernierNiveauBrut = HIGH;
int niveauStable = HIGH;
unsigned long debutChangementMs = 0;
bool ledAllumee = false;

void setup() {
  pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  pinMode(BROCHE_LED, OUTPUT);
  digitalWrite(BROCHE_LED, LOW);
}

void loop() {
  const unsigned long maintenant = millis();
  const int niveauBrut = digitalRead(BROCHE_BOUTON);

  if (niveauBrut != dernierNiveauBrut) {
    debutChangementMs = maintenant; // nouveau changement mecanique
  }
  if ((unsigned long)(maintenant - debutChangementMs) >= ANTIREBOND_MS &&
      niveauBrut != niveauStable) {
    niveauStable = niveauBrut;
    if (niveauStable == LOW) { // un seul evenement par appui valide
      ledAllumee = !ledAllumee;
      digitalWrite(BROCHE_LED, ledAllumee ? HIGH : LOW);
    }
  }
  dernierNiveauBrut = niveauBrut;
}
