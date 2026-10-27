/*
 * M05-V02 | Etape 3 finale : envoi periodique + commandes.
 * Une mesure 230.5 V est SIMULEE. AUCUN branchement au secteur.
 * UART USB a 9600 bauds ; commandes '1', '0', '?' disponibles
 * pendant que les relevés continuent toutes les ~1000 ms.
 */
const unsigned long PERIODE_MS = 1000UL;
const float TENSION_SIMULEE_V = 230.5f;
unsigned long dernierEnvoiMs = 0;
bool ledAllumee = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  dernierEnvoiMs = millis();
  Serial.println("M05: 1=ON, 0=OFF, ?=aide. Mesure fictive.");
}

void traiterCommandes() {
  while (Serial.available() > 0) {
    const char commande = (char)Serial.read();
    if (commande == '\r' || commande == '\n') continue;
    switch (commande) {
      case '1': ledAllumee = true; break;
      case '0': ledAllumee = false; break;
      case '?':
        Serial.println("1=ON 0=OFF ?=aide");
        continue;
      default:
        Serial.println("Commande inconnue");
        continue;
    }
    digitalWrite(LED_BUILTIN, ledAllumee ? HIGH : LOW);
    Serial.println(ledAllumee ? "LED ON" : "LED OFF");
  }
}

void loop() {
  traiterCommandes();
  const unsigned long maintenant = millis();
  if ((unsigned long)(maintenant - dernierEnvoiMs) >= PERIODE_MS) {
    dernierEnvoiMs = maintenant;
    Serial.print("Tension SIMULEE : ");
    Serial.print(TENSION_SIMULEE_V, 1);
    Serial.println(" V");
  }
}
