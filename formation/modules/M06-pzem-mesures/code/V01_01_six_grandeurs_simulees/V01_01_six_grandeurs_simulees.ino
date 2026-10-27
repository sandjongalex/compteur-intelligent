/*
 * M06-V01, etape 1 : six grandeurs FICTIVES.
 * Arduino Uno R3 / USB uniquement : aucun PZEM ni secteur.
 */
struct Releve {
  float tensionV;
  float courantA;
  float puissanceW;
  float energieTotaleKWh;
  float frequenceHz;
  float facteurPuissance;
};

const Releve EXEMPLE = {230.5f, 0.500f, 92.2f, 12.345f, 50.0f, 0.80f};

void afficherReleve(const Releve &r) {
  Serial.print(F("Tension : ")); Serial.print(r.tensionV, 1); Serial.println(F(" V"));
  Serial.print(F("Courant : ")); Serial.print(r.courantA, 3); Serial.println(F(" A"));
  Serial.print(F("Puissance active : ")); Serial.print(r.puissanceW, 1); Serial.println(F(" W"));
  Serial.print(F("Energie CUMULEE : ")); Serial.print(r.energieTotaleKWh, 3); Serial.println(F(" kWh"));
  Serial.print(F("Frequence : ")); Serial.print(r.frequenceHz, 1); Serial.println(F(" Hz"));
  Serial.print(F("Facteur de puissance : ")); Serial.println(r.facteurPuissance, 2);
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("SIMULATION PZEM V3 - aucune mesure reelle"));
  afficherReleve(EXEMPLE);
}
void loop() {}
