# M04 — Mémo C/C++ pour débutants (ATmega328P)

## Variables et types

```cpp
int compteur = 3;             // entier
float tensionV = 230.5f;      // nombre décimal approximatif
bool liaisonOk = false;       // vrai ou faux
const float FACTEUR = 1000.0f; // constante
```

Une variable est un emplacement nommé qui conserve une valeur. Le signe `=` **affecte** une valeur, alors que `==` **compare** deux valeurs.

Sur Uno R3, un `int` est sur **16 bits** ; sa plage signée va de **-32768 à 32767**. Le `float` est sur **32 bits** et sa précision est limitée. Ces tailles peuvent différer selon la carte.

## Opérations

```cpp
int q = 5 / 2;           // 2
float q2 = 5.0f / 2.0f;  // 2.5
```

**Formule de cours :** si la puissance active est **constante**, `energieKWh = (puissanceW / 1000.0f) * dureeHeures;`.

Par exemple, 500 W pendant 2 h → 1 kWh ; 200 W pendant 5 h → 1 kWh.

## Conditions

```cpp
if (tensionV > 240.0f) {
  Serial.println("Alerte fictive");
} else {
  Serial.println("Plage de l'exercice");
}
```

Le `240.0f` est un **seuil pédagogique fictif**, pas un seuil de protection électrique.

## Boucles

```cpp
for (int i = 1; i <= 3; i++) {
  Serial.println(i);
}

int essais = 0;
while (essais < 3) {
  essais++; // important : la condition finit par devenir fausse
}
```

## Fonctions

```cpp
float wattsVersKilowatts(float watts) {
  return watts / 1000.0f;
}
```

Le nom identifie la fonction, les **paramètres** apportent des valeurs et `return` en renvoie une.

## Moniteur série

```cpp
void setup() {
  Serial.begin(9600);     // même débit dans le moniteur série
  Serial.println("Bonjour");
}
```

Références : [langage Arduino](https://docs.arduino.cc/language-reference/) et [Uno Rev3](https://docs.arduino.cc/hardware/uno-rev3).
