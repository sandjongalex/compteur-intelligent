/*
 * M06-V02, etape 2 : simulation succes / absence de reponse.
 * Ne PAS reafficher un ancien releve comme s'il etait nouveau.
 */
const unsigned long INTERVALLE_MS = 2000UL;
unsigned long precedent = 0;
unsigned int tentative = 0;

struct Mesures {
  float tensionV, courantA, puissanceW;
  float energieKWh, frequenceHz, facteurPuissance;
};

bool lireSimulation(Mesures &m, unsigned int numero) {
  if (numero % 3 == 2) return false; // panne fictive a la 2e tentative
  m = {230.5f, 0.500f, 92.2f, 12.345f, 50.0f, 0.80f};
  return true;
}

void setup() {
  Serial.begin(9600);
  precedent = millis();
  Serial.println(F("SIMULATION : OK, PANNE, OK ..."));
}
void loop() {
  unsigned long maintenant = millis();
  if ((unsigned long)(maintenant - precedent) < INTERVALLE_MS) return;
  precedent = maintenant;
  ++tentative;

  Mesures m; // ne pas reutiliser des donnees precedentes
  if (!lireSimulation(m, tentative)) {
    Serial.println(F("ERREUR : releve absent, valeurs non actualisees"));
    return;
  }
  Serial.print(F("OK : ")); Serial.print(m.tensionV, 1);
  Serial.print(F(" V, ")); Serial.print(m.puissanceW, 1);
  Serial.print(F(" W, E cumul : ")); Serial.print(m.energieKWh, 3);
  Serial.println(F(" kWh"));
}
