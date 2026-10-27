/*
 * CORRIGE TP02 : mesure SIMULEE toutes les 500 ms sans delay.
 * Commandes '1'=ON, '0'=OFF, '?'=aide toujours reactives.
 * Uno Rev3 USB, moniteur serie 9600 bauds.
 */
const unsigned long PERIODE_MS = 500UL;
const float TENSION_SIMULEE_V = 230.5f;
unsigned long precedentMs = 0;
bool ledAllumee = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  precedentMs = millis();
  Serial.println("TP02: 1=ON 0=OFF ?=aide");
}

void loop() {
  while (Serial.available() > 0) {
    const char c = (char)Serial.read();
    if (c == '\r' || c == '\n') continue;
    if (c == '1' || c == '0') {
      ledAllumee = (c == '1');
      digitalWrite(LED_BUILTIN, ledAllumee ? HIGH : LOW);
      Serial.println(ledAllumee ? "LED ON" : "LED OFF");
    } else if (c == '?') {
      Serial.println("1=ON 0=OFF ?=aide");
    } else {
      Serial.println("Commande inconnue");
    }
  }
  const unsigned long maintenant = millis();
  if ((unsigned long)(maintenant - precedentMs) >= PERIODE_MS) {
    precedentMs = maintenant;
    Serial.print("Tension SIMULEE : ");
    Serial.print(TENSION_SIMULEE_V, 1);
    Serial.println(" V");
  }
}
