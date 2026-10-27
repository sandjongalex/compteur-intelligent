/*
 * M05-V02 | Etape 2 : commandes serie courtes.
 * '1' allume la LED integree, '0' l'eteint, '?' affiche l'aide.
 * Pas de module branche sur RX0/TX0 (D0/D1) pendant la demo USB.
 */
bool ledAllumee = false;

void afficherAide() {
  Serial.println("1=allumer, 0=eteindre, ?=aide");
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  afficherAide();
}

void loop() {
  while (Serial.available() > 0) {
    const char commande = (char)Serial.read();
    if (commande == '\r' || commande == '\n') continue;
    if (commande == '1') {
      ledAllumee = true;
    } else if (commande == '0') {
      ledAllumee = false;
    } else if (commande == '?') {
      afficherAide();
      continue;
    } else {
      Serial.println("Commande inconnue ; entrer 1, 0 ou ?.");
      continue;
    }
    digitalWrite(LED_BUILTIN, ledAllumee ? HIGH : LOW);
    Serial.println(ledAllumee ? "LED ON" : "LED OFF");
  }
}
