/*
 * CORRIGE TP01 : simuler deux pages d'un futur LCD avec une LED.
 * D2 vers GND, INPUT_PULLUP, anti-rebond 35 ms non bloquant.
 * Une pression valide change de page 0 <-> 1 ; affichage Serie.
 * Aucun LCD reel n'est necessaire pendant ce TP.
 */
const byte BROCHE_BOUTON = 2;
const unsigned long ANTIREBOND_MS = 35UL;
int brutPrecedent = HIGH;
int stable = HIGH;
unsigned long changementMs = 0;
byte page = 0;

void setup() {
  pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Page initiale : 0");
}

void loop() {
  const unsigned long maintenant = millis();
  const int brut = digitalRead(BROCHE_BOUTON);
  if (brut != brutPrecedent) changementMs = maintenant;
  if ((unsigned long)(maintenant - changementMs) >= ANTIREBOND_MS && brut != stable) {
    stable = brut;
    if (stable == LOW) {
      page = (byte)(1 - page);
      digitalWrite(LED_BUILTIN, page ? HIGH : LOW);
      Serial.print("Page : ");
      Serial.println(page);
    }
  }
  brutPrecedent = brut;
}
