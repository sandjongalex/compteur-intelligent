/*
 * AlexTech Academy — M04-V02
 * Données de démonstration fictives. Le seuil est pédagogique :
 * il ne s'agit PAS d'une protection électrique réelle.
 */
const float TENSION_FICTIVE_V = 245.0f;
const float SEUIL_PEDAGOGIQUE_V = 240.0f;

void setup() {
  Serial.begin(9600);

  if (TENSION_FICTIVE_V > SEUIL_PEDAGOGIQUE_V) {
    Serial.println("Alerte pedagogique : mesure fictive elevee");
  } else {
    Serial.println("Mesure fictive dans la plage de l'exercice");
  }

  for (int i = 1; i <= 3; i++) {
    Serial.print("Releve simule ");
    Serial.println(i);
  }

  int essais = 0;
  while (essais < 3) {
    essais++; // L'incrément garantit la fin de la boucle.
  }
  Serial.print("Essais termines : ");
  Serial.println(essais);
}

void loop() {}
