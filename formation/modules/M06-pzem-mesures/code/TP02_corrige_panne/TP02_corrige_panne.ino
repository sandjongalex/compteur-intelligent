/*
 * CORRIGE TP02 M06 : succes -> echec -> retour.
 * Un echec de lecture ne doit pas devenir 0 V ou 0 kWh.
 * Donnees de simulation uniquement, sans PZEM ni secteur.
 */
unsigned int essai = 0;
unsigned long precedent = 0;
const unsigned long PERIODE = 2000UL;

bool lireTensionSimulee(float &valeur) {
  if (essai % 3 == 2) return false;
  valeur = 230.5f;
  return true;
}

void setup() {
  Serial.begin(9600);
  precedent = millis();
  Serial.println(F("TP02 SIMULATION : pas de releve invente"));
}
void loop() {
  const unsigned long maintenant = millis();
  if ((unsigned long)(maintenant - precedent) < PERIODE) return;
  precedent = maintenant;
  ++essai;
  float tension; // la valeur n'est utilisee qu'en cas de succes
  if (!lireTensionSimulee(tension)) {
    Serial.println(F("ERREUR : mesure indisponible"));
    return;
  }
  Serial.print(F("Mesure SIMULEE : "));
  Serial.print(tension, 1);
  Serial.println(F(" V"));
}
