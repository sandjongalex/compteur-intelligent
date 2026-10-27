/*
 * M05-V02 | Etape 1 : lire un caractere depuis le moniteur serie.
 * Carte Uno Rev3 USB; ouvrir le moniteur serie a 9600 bauds.
 * Envoyer un seul caractere avec "No line ending" pour commencer.
 */
void setup() {
  Serial.begin(9600);
  Serial.println("Pret : saisir un caractere.");
}

void loop() {
  if (Serial.available() > 0) {
    char recu = (char)Serial.read();
    if (recu != '\r' && recu != '\n') {
      Serial.print("Recu : ");
      Serial.println(recu);
    }
  }
}
