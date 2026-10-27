/*
 * M06-V02, etape 1 : une source de donnees fictives.
 * Aucun capteur, aucun raccordement 230 V, aucune bibliotheque.
 */
const unsigned long INTERVALLE_MS = 2000UL;
unsigned long dernierEnvoi = 0;

struct Mesures {
  float tensionV, courantA, puissanceW;
  float energieKWh, frequenceHz, facteurPuissance;
};

bool lireSimulation(Mesures &m) {
  m = {230.5f, 0.500f, 92.2f, 12.345f, 50.0f, 0.80f};
  return true;
}

void afficher(const Mesures &m) {
  Serial.print(F("V=")); Serial.print(m.tensionV, 1);
  Serial.print(F(" V | I=")); Serial.print(m.courantA, 3);
  Serial.print(F(" A | P=")); Serial.print(m.puissanceW, 1);
  Serial.print(F(" W | E=")); Serial.print(m.energieKWh, 3);
  Serial.print(F(" kWh | f=")); Serial.print(m.frequenceHz, 1);
  Serial.print(F(" Hz | PF=")); Serial.println(m.facteurPuissance, 2);
}

void setup() {
  Serial.begin(9600);
  dernierEnvoi = millis();
  Serial.println(F("SOURCE SIMULEE : aucune mesure secteur"));
}
void loop() {
  const unsigned long maintenant = millis();
  if ((unsigned long)(maintenant - dernierEnvoi) >= INTERVALLE_MS) {
    dernierEnvoi = maintenant;
    Mesures m;
    if (lireSimulation(m)) afficher(m);
  }
}
