# Chapitre 4 — Les bases du C/C++ pour les microcontrôleurs

> **Niveau :** débutant, après les chapitres 1 à 3.  
> **Matériel conseillé :** Arduino Uno Rev3, ordinateur, câble USB de données et Arduino IDE 2.  
> **Pratique personnelle :** 40 à 60 minutes.  
> **Sécurité :** tous les exemples de tension, de puissance et d'énergie sont **fictifs**. La seule carte utilisée est une Arduino Uno alimentée de manière adaptée par USB, sans raccordement au secteur, au PZEM ou au modem GSM.

Dans le chapitre 3, notre compteur a acquis sa première fonction : faire clignoter la LED intégrée de l'Arduino Uno. Le programme était court, mais nous avons déjà rencontré les notions d'instruction, de fonction et de boucle.

Un compteur intelligent devra ensuite manipuler des **valeurs** : tension, puissance, durée et consommation. Il devra aussi **prendre des décisions**, **répéter des opérations** et **réutiliser des calculs**. C'est précisément le rôle des constructions fondamentales du langage C++ que nous allons apprendre.

Nous utiliserons deux approches complémentaires : de petits programmes pour comprendre chaque notion, puis une version améliorée de **notre programme principal**, qui conservera la LED et ajoutera un calcul pédagogique affiché sur l'ordinateur.

## Objectifs d'apprentissage

À la fin de ce chapitre, vous saurez :

1. distinguer une variable, son type, sa valeur et une constante ;
2. déclarer des valeurs `int`, `float`, `bool` et `const` ;
3. effectuer des opérations simples et éviter le piège de la division entière ;
4. calculer une énergie **théorique** lorsque la puissance active est constante ;
5. utiliser le moniteur série d'Arduino IDE à **9 600 bauds** ;
6. interpréter `if`, `else`, `for`, `while` et `return` ;
7. écrire une fonction réutilisable avec des paramètres ;
8. lire et expliquer une nouvelle version du programme du compteur, **sans perdre le clignotement précédent**.

---

## Partie A — Variables, types et calculs en C++

### 4.1. À quoi sert une variable ?

Imaginez une boîte portant une étiquette. On peut y déposer une valeur, puis retrouver cette valeur en utilisant le nom écrit sur l'étiquette.

En programmation, cette image correspond à une **variable**. Une variable possède notamment un **nom**, un **type** et une **valeur**. Dans un compteur énergétique, nous pourrions utiliser des noms comme `tensionV`, `puissanceW` ou `dureeHeures`.

~~~cpp
int compteur = 3;
float tensionV = 230.5f;
bool liaisonOk = false;
~~~

Dans ce code, les valeurs électriques éventuelles ne proviennent d'aucun capteur : elles servent seulement à apprendre le langage.

Voici comment lire la première ligne :

- `int` : type choisi pour stocker un entier ;
- `compteur` : nom de la variable ;
- `=` : affectation d'une valeur ;
- `3` : valeur initiale ;
- `;` : fin de l'instruction.

La deuxième ligne contient un nombre à décimales. **Dans le code C++, on utilise un point**, même lorsque le texte du livre écrit « 230,5 V » avec une virgule française.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.1
Type : infographie pédagogique.
Contenu et annotations : représenter trois boîtes étiquetées « compteur », « tensionV » et « liaisonOk » contenant respectivement 3, 230.5 et false ; distinguer nom, type et valeur.
Légende finale : Figure 4.1 — Une variable associe un nom, un type et une valeur.
Texte alternatif : Trois variables C++ sont illustrées comme des boîtes : un entier compteur égal à 3, un décimal tensionV égal à 230.5 et un booléen liaisonOk égal à false.
Contraintes : données fictives, aucun visuel prétendant montrer un relevé réel, libellés français lisibles en impression.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.1]** Infographie : trois variables représentées par des boîtes avec leurs noms, types et valeurs.

**Figure 4.1 — Une variable associe un nom, un type et une valeur.**

### 4.2. Choisir le bon type de donnée

Nous allons utiliser trois types de base dans nos premiers programmes.

| Type C++ | Valeurs adaptées | Exemple |
|---|---|---|
| `int` | Nombres entiers | `int essais = 3;` |
| `float` | Nombres décimaux, représentés de façon approximative | `float puissanceW = 500.0f;` |
| `bool` | États vrai/faux | `bool alarme = false;` |

Sur notre **ATmega328P équipant l'Arduino Uno Rev3**, `int` utilise **16 bits**, soit une plage signée de **−32 768 à +32 767**. Le type `float` occupe **32 bits** sur cette plateforme AVR ; il possède une précision limitée et ne représente pas exactement toutes les fractions décimales.

Ces tailles ne sont pas identiques sur toutes les cartes Arduino. C'est pourquoi il faut toujours préciser **la plateforme concernée** lorsqu'on parle de taille mémoire ou de limites numériques.

Les limites ont une conséquence pratique : si nous utilisons un petit entier pour accumuler sans contrôle des valeurs toujours croissantes, il peut finir par **déborder**. Et si nous employons des nombres flottants pour des cumuls énergétiques, nous devons comprendre les effets de la précision et des arrondis.

Dans ce chapitre, nos petits nombres conviennent à un **apprentissage**, pas à une stratégie complète de comptage ou de facturation. Les mécanismes fiables d'index énergétique et de persistance seront étudiés plus loin.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.2
Type : infographie comparative de types et mémoire.
Contenu et annotations : comparer int 16 bits, float 32 bits et bool comme état vrai/faux sur Uno AVR ; montrer la plage de int et la précision approximative de float ; éviter d'inventer un coût mémoire universel pour bool.
Légende finale : Figure 4.2 — Les types de données ont des usages et des limites.
Texte alternatif : Illustration comparant un entier sur 16 bits, un nombre décimal approximatif sur 32 bits et un état vrai ou faux.
Contraintes : préciser explicitement « Arduino Uno Rev3 / ATmega328P AVR », ne pas généraliser à toutes les cartes Arduino ; valeurs exactes.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.2]** Infographie : comparaison des types int, float et bool sur Arduino Uno Rev3.

**Figure 4.2 — Les types de données ont des usages et des limites.**

### 4.3. Pourquoi utiliser const ?

Certaines valeurs représentent un réglage qui ne doit pas changer pendant l'exécution ordinaire de notre programme. Nous pouvons les déclarer avec `const` :

~~~cpp
const float WATTS_PAR_KILOWATT = 1000.0f;
const unsigned long TEMPS_ALLUME_MS = 1000UL;
~~~

La première constante contient le facteur de conversion entre watts et kilowatts. La deuxième représente la durée d'allumage de la LED du chapitre 3.

Le mot `const` signifie que notre code ne doit pas réaffecter une autre valeur à cet objet après son initialisation.

Pourquoi donner des noms explicites ? Parce que la phrase `puissanceW / WATTS_PAR_KILOWATT` décrit mieux l'intention du calcul qu'une multiplication ou une division par un nombre mystérieux.

La notation `1000.0f` désigne un littéral de type `float`. La notation `1000UL` désigne un entier non signé de type `unsigned long`, utile pour certaines durées. Nous expliquerons plus profondément les types entiers non signés lors de l'étude des temporisations.

**À retenir :** une constante bien nommée rend le programme plus lisible, mais ne dispense pas de vérifier les unités et le domaine autorisé de ses valeurs.

### 4.4. Les opérations mathématiques courantes

Le langage C++ propose les opérateurs suivants :

| Opérateur | Action | Exemple | Résultat |
|---|---|---|---|
| `+` | Addition | `5 + 2` | 7 |
| `-` | Soustraction | `5 - 2` | 3 |
| `*` | Multiplication | `5 * 2` | 10 |
| `/` | Division | `6 / 2` | 3 |
| `%` | Reste de division entière | `5 % 2` | 1 |

Le piège le plus courant pour un débutant concerne la **division de deux entiers**.

~~~cpp
int resultatEntier = 5 / 2;          // 2
float resultatDecimal = 5.0f / 2.0f; // 2.5
~~~

Dans la première ligne, `5` et `2` sont des entiers : la partie fractionnaire est perdue. Pour des nombres positifs, `5 / 2` donne **2**, et non 2,5.

Dans la deuxième ligne, la division utilise des valeurs flottantes. Le résultat peut donc représenter la partie décimale.

**Attention :** écrire `float resultat = 5 / 2;` ne répare pas le problème. La division entière a lieu **avant** que son résultat soit rangé dans `resultat`.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.3
Type : infographie de calcul.
Contenu et annotations : montrer côte à côte « 5 / 2 → 2 » et « 5.0f / 2.0f → 2.5 », avec étape « type des opérandes → type du calcul ».
Légende finale : Figure 4.3 — La division entière ne conserve pas la partie décimale.
Texte alternatif : Comparaison entre 5 divisé par 2 avec des entiers, résultat 2, et la même division avec des flottants, résultat 2,5.
Contraintes : syntaxe C++ exacte, virgule française seulement dans les explications en prose et point dans le code.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.3]** Infographie : pourquoi 5 / 2 donne 2 et 5.0f / 2.0f donne 2,5.

**Figure 4.3 — La division entière ne conserve pas la partie décimale.**

### 4.5. Calculer une consommation fictive

Nous retrouvons le principe présenté au chapitre 1 : si la **puissance active est constante** pendant la durée étudiée,

**Énergie (kWh) = Puissance active (kW) × Durée (h).**

Puisque nos données sont exprimées en watts, nous devons les convertir en kilowatts avant la multiplication.

~~~cpp
const float puissanceW = 500.0f;   // FICTIF
const float dureeHeures = 2.0f;    // FICTIF

float energieKWh =
    (puissanceW / 1000.0f) * dureeHeures;
~~~

Calculons à la main :

1. `500 W / 1 000 = 0,5 kW` ;
2. `0,5 kW × 2 h = 1 kWh`.

Le **résultat théorique** attendu est donc **1,000 kWh**. Cela ne signifie pas que le microcontrôleur a réellement mesuré cette consommation : les nombres ont été inscrits directement dans le programme.

Essayons avec **200 W pendant 5 heures** : `(200 / 1000) × 5 = 1 kWh`. Deux situations différentes peuvent conduire à la même énergie.

Un calcul vrai sur le papier doit encore être correctement exprimé dans le programme. C'est pourquoi la division utilise `1000.0f`, et non une division entière dont on ignorerait les conséquences.

### 4.6. Afficher un résultat grâce au moniteur série

Dans le chapitre 3, notre résultat était visible sur une LED. Pour afficher des nombres et des messages, nous allons utiliser la **communication série** entre l'Arduino Uno et l'ordinateur.

Pour ce premier exemple, il suffit d'écrire :

~~~cpp
void setup() {
  Serial.begin(9600);
  Serial.println("Bonjour depuis le compteur");
}

void loop() {
}
~~~

- `Serial.begin(9600);` initialise ici la liaison série à **9 600 bauds**, débit également à régler dans le moniteur série.
- `Serial.print(...);` affiche un élément **sans passer automatiquement à la ligne suivante**.
- `Serial.println(...);` affiche un élément et termine la ligne.

Ouvrez le **moniteur série** dans Arduino IDE et choisissez la même vitesse. Le message est destiné à l'ordinateur ; il n'est ni envoyé par GSM ni enregistré dans un serveur.

Voici un programme complet d'exercice :

~~~cpp
const float WATTS_PAR_KW = 1000.0f;
const float puissanceW = 500.0f;  // FICTIF
const float dureeHeures = 2.0f;   // FICTIF

void setup() {
  Serial.begin(9600);

  float energieKWh =
      (puissanceW / WATTS_PAR_KW) * dureeHeures;

  Serial.print("Energie fictive : ");
  Serial.print(energieKWh, 3);
  Serial.println(" kWh");
}

void loop() {
}
~~~

**Programme 4.1 — Calcul pédagogique isolé et affichage série.**

La notation `Serial.print(energieKWh, 3)` demande un affichage avec **trois chiffres après le point décimal**. Pour nos données, l'affichage **attendu**, si compilation et téléversement fonctionnent, est :

~~~text
Energie fictive : 1.000 kWh
~~~

C'est **un résultat calculé**, et non une capture de mesure. Le code est une démonstration de langage indépendante ; un peu plus loin, nous intégrerons les mêmes idées dans **le programme principal** sans abandonner la LED.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.4
Type : capture d'écran réelle annotée.
Contenu et annotations : Arduino IDE 2 sur Uno Rev3, montrer la zone Moniteur série et le réglage à 9600 bauds ; programme pédagogique affichant « Energie fictive : 1.000 kWh » si réellement observé.
Légende finale : Figure 4.4 — Le moniteur série permet d'observer un résultat calculé.
Texte alternatif : Fenêtre Arduino IDE et moniteur série réglé sur 9600 bauds présentant une ligne d'énergie fictive calculée.
Contraintes : capture réelle à produire seulement après essai, version logicielle vérifiée, mention explicite « données fictives » ; ne pas créer un faux compte rendu matériel.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.4]** Capture : moniteur série à 9 600 bauds et affichage d'un calcul fictif.

**Figure 4.4 — Le moniteur série permet d'observer un résultat calculé.**

---

## Partie B — Conditions, boucles et fonctions

### 4.7. Prendre une décision avec if et else

Un appareil connecté ne peut pas tout faire de manière identique en toute circonstance. Il doit parfois choisir une action suivant un résultat ou un état.

En C++, cette logique s'écrit avec `if` (« si ») et `else` (« sinon »).

~~~cpp
const float tensionFictiveV = 245.0f;
const float seuilPedagogiqueV = 240.0f;

void setup() {
  Serial.begin(9600);

  if (tensionFictiveV > seuilPedagogiqueV) {
    Serial.println("Alerte pedagogique fictive");
  } else {
    Serial.println("Valeur dans la plage de l'exercice");
  }
}

void loop() {
}
~~~

Pour l'exemple donné, **245 est supérieur à 240**, donc la première branche doit s'exécuter.

Si nous remplaçons uniquement `245.0f` par `230.0f`, la condition devient fausse et le second message est attendu.

**Attention à la sécurité :** le nombre **240 V** est ici un **seuil fictif choisi uniquement pour apprendre la syntaxe**. Ce n'est **pas** un seuil réglementaire, un réglage de protection du réseau ni une valeur à employer telle quelle dans un équipement réel.

### 4.8. Comparer ou affecter : = et ==

Ces deux écritures ont des rôles différents :

~~~cpp
int essais = 3;        // Affectation : donner la valeur 3

if (essais == 3) {     // Comparaison : est-ce égal à 3 ?
  Serial.println("Trois essais");
}
~~~

Le symbole **`=`** attribue une valeur. Le symbole **`==`** vérifie l'égalité de deux expressions.

Écrire accidentellement `if (essais = 3)` peut être accepté par le compilateur, mais cela **affecte** la valeur 3 à `essais` et utilise ensuite cette valeur dans la condition. C'est un bug logique fréquent.

La compilation peut donc réussir alors que le programme ne réalise pas ce que nous pensions. **Tester des sorties attendues est aussi important que vérifier la syntaxe.**

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.5
Type : organigramme de décision et comparaison de symboles.
Contenu et annotations : représenter « tensionFictiveV > 240 ? » puis branche if avec 245 et else avec 230 ; ajouter un encart « = affecter / == comparer ».
Légende finale : Figure 4.5 — Une condition sélectionne une branche selon le résultat d'un test.
Texte alternatif : Un losange compare une tension fictive à un seuil fictif et oriente l'exécution vers if ou else ; un rappel distingue les symboles égal et double égal.
Contraintes : toutes les valeurs explicitement fictives ; 240 V n'est pas un seuil de sécurité.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.5]** Organigramme : condition if/else et différence entre = et ==.

**Figure 4.5 — Une condition sélectionne une branche selon le résultat d'un test.**

### 4.9. Répéter un nombre connu de fois avec for

Supposons que nous voulions afficher les numéros de trois relevés fictifs. Inutile de recopier trois fois l'instruction : une **boucle for** convient mieux.

~~~cpp
for (int i = 1; i <= 3; i++) {
  Serial.print("Releve simule numero ");
  Serial.println(i);
}
~~~

L'expression `for (int i = 1; i <= 3; i++)` contient trois parties :

1. **Initialisation :** `int i = 1` démarre le compteur à 1.
2. **Condition :** `i <= 3` autorise la répétition tant que `i` est inférieur ou égal à 3.
3. **Évolution :** `i++` augmente `i` de 1 après chaque passage.

La sortie attendue, si ce bloc est exécuté avec une liaison série correctement initialisée, est :

~~~text
Releve simule numero 1
Releve simule numero 2
Releve simule numero 3
~~~

Lorsque `i` vaut 4, la condition `i <= 3` est fausse : la boucle s'arrête.

Pour afficher quatre relevés, il suffit de modifier la borne finale et de remplacer `i <= 3` par `i <= 4`.

### 4.10. Utiliser while sans bloquer le programme

La boucle **while** répète un ensemble d'instructions **tant qu'une condition reste vraie**.

~~~cpp
int essais = 0;

while (essais < 3) {
  essais++;
}
~~~

La variable commence à 0, puis passe successivement à 1, 2 et 3. Quand elle atteint 3, le test `essais < 3` devient faux et la boucle se termine.

Supposons au contraire que nous supprimions `essais++` :

~~~cpp
int essais = 0;

// Exemple incorrect : ne pas utiliser ainsi dans le compteur.
while (essais < 3) {
  // essais ne change jamais : la condition reste vraie.
}
~~~

Ce deuxième exemple montre une **boucle non terminante** : avec `essais` inchangé, le programme principal peut rester bloqué sur cette instruction.

Dans un système embarqué qui doit surveiller des événements et communiquer, cette erreur est problématique. Nous privilégierons des boucles à condition d'arrêt explicite et, dans les futures étapes, des techniques de programmation non bloquantes.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.6
Type : organigramme comparatif.
Contenu et annotations : comparer for avec i=1,2,3 puis arrêt, et while avec essais=0 puis incrément jusqu'à 3 ; faire apparaître un avertissement contre une condition qui ne devient jamais fausse.
Légende finale : Figure 4.6 — Les boucles for et while doivent posséder une fin contrôlée.
Texte alternatif : Deux parcours de répétition montrent un compteur incrémenté jusqu'à sa limite ; une variante sans incrément mène à une boucle qui ne se termine pas.
Contraintes : représenter uniquement des boucles bornées comme exemples recommandés, avertissement pédagogique clair, aucun essai dangereux.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.6]** Organigramme : boucles for/while et risque de boucle infinie.

**Figure 4.6 — Les boucles for et while doivent posséder une fin contrôlée.**

### 4.11. Écrire une fonction avec paramètres et return

Une **fonction** regroupe des instructions sous un nom réutilisable. Elle permet d'écrire un calcul une fois et de l'appeler avec différentes valeurs.

Commençons par convertir des watts en kilowatts :

~~~cpp
float wattsVersKilowatts(float watts) {
  return watts / 1000.0f;
}
~~~

Explication :

- le premier mot `float` annonce le **type de valeur renvoyée** ;
- `wattsVersKilowatts` est le nom de la fonction ;
- `float watts` est le **paramètre** reçu par la fonction ;
- `return` renvoie le résultat du calcul.

Nous pouvons écrire :

~~~cpp
float a = wattsVersKilowatts(500.0f);   // 0.5 kW
float b = wattsVersKilowatts(1250.0f);  // 1.25 kW
~~~

Une fonction ne connaît pas automatiquement l'unité de son paramètre. C'est à nous de documenter que `watts` représente une **puissance active en W**.

Pour calculer l'énergie théorique, nous pouvons aussi créer une fonction qui reçoit deux paramètres :

~~~cpp
float calculerEnergieKWh(float puissanceW,
                         float dureeHeures) {
  return (puissanceW / 1000.0f) * dureeHeures;
}
~~~

Exemple : `calculerEnergieKWh(400.0f, 2.5f)` donne **1,0 kWh**. Là encore, le résultat repose sur une puissance active constante et des données d'exercice.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.7
Type : infographie de circulation des paramètres.
Contenu et annotations : deux nombres d'entrée 400 W et 2,5 h → boîte calculerEnergieKWh(puissanceW,dureeHeures) → opération (400/1000)×2,5 → sortie 1 kWh via return.
Légende finale : Figure 4.7 — Une fonction reçoit des paramètres et renvoie un résultat.
Texte alternatif : Une fonction reçoit une puissance fictive de 400 watts et une durée de deux heures et demie, puis retourne une énergie théorique de un kilowattheure.
Contraintes : représenter 400 W, 2,5 h et 1 kWh correctement ; données fictives, puissance constante.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.7]** Infographie : paramètres, calcul et valeur retournée par une fonction.

**Figure 4.7 — Une fonction reçoit des paramètres et renvoie un résultat.**

### 4.12. Conserver la LED : faire évoluer le même compteur

Nous savons maintenant calculer et afficher des valeurs. Mais notre objectif n'est **pas** de remplacer le programme du chapitre 3 par un exemple complètement différent.

Nous allons conserver sa fonction visible : **la LED intégrée continue de clignoter**. Nous ajouterons un **calcul fictif** présenté dans le moniteur série lors de l'initialisation.

**Ce qui était déjà présent :**

~~~cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
~~~

Dans la nouvelle étape, nous allons :

1. nommer les durées de clignotement avec des constantes ;
2. créer une fonction `calculerEnergieKWh()` ;
3. créer une fonction `commanderLED()` qui reçoit un booléen ;
4. créer une fonction `afficherCalcul()` ;
5. initialiser la liaison série dans `setup()` et afficher une fois l'énergie fictive ;
6. conserver le clignotement dans `loop()`.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 4.8
Type : schéma comparatif d'évolution du programme.
Contenu et annotations : deux colonnes M03 « LED clignote » puis M04 « LED clignote + variables + fonction de calcul fictif + moniteur série », avec flèche indiquant le même firmware enrichi.
Légende finale : Figure 4.8 — Le chapitre 4 enrichit le programme du chapitre 3 sans perdre la LED.
Texte alternatif : Une première version fait clignoter la LED ; la version suivante conserve cette fonction et ajoute des constantes, fonctions et un calcul d'énergie fictive affiché en série.
Contraintes : ne pas présenter le PZEM, le GSM ou la FRAM comme déjà fonctionnels ; image du logiciel, pas preuve de test matériel.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 4.8]** Comparaison : même programme, avec LED préservée et calcul fictif ajouté.

**Figure 4.8 — Le chapitre 4 enrichit le programme du chapitre 3 sans perdre la LED.**

### 4.13. Le programme principal, expliqué

Voici la version intégrée que nous étudions. Les nombres de puissance et de durée sont **entièrement fictifs**.

~~~cpp
#include <Arduino.h>

// Durées de la LED du chapitre précédent.
const unsigned long TEMPS_ALLUME_MS = 1000UL;
const unsigned long TEMPS_ETEINT_MS = 1000UL;

// Valeurs de démonstration : AUCUNE MESURE RÉELLE.
const float PUISSANCE_SIMULEE_W = 500.0f;
const float DUREE_SIMULEE_H = 2.0f;
const float WATTS_PAR_KILOWATT = 1000.0f;

float calculerEnergieKWh(float puissanceW, float heures) {
  return (puissanceW / WATTS_PAR_KILOWATT) * heures;
}

void commanderLED(bool allumer) {
  digitalWrite(LED_BUILTIN, allumer ? HIGH : LOW);
}

void afficherCalcul() {
  const float energie = calculerEnergieKWh(
      PUISSANCE_SIMULEE_W, DUREE_SIMULEE_H);

  Serial.print(F("Puissance SIMULEE : "));
  Serial.print(PUISSANCE_SIMULEE_W, 1);
  Serial.println(F(" W"));

  Serial.print(F("Duree SIMULEE : "));
  Serial.print(DUREE_SIMULEE_H, 1);
  Serial.println(F(" h"));

  Serial.print(F("Energie THEORIQUE fictive : "));
  Serial.print(energie, 3);
  Serial.println(F(" kWh"));
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println(F("FIL ROUGE M04 - LED M03 conservee"));
  afficherCalcul();
}

void loop() {
  commanderLED(true);
  delay(TEMPS_ALLUME_MS);
  commanderLED(false);
  delay(TEMPS_ETEINT_MS);
}
~~~

**Programme 4.2 — Programme principal du compteur à la fin du chapitre 4.**

Examinons ce que nous avons ajouté.

**Les constantes de durée** évitent de répéter les valeurs `1000` sans explication. `TEMPS_ALLUME_MS` et `TEMPS_ETEINT_MS` portent un nom qui précise leur unité : les millisecondes.

**Les constantes de calcul** définissent un exemple : **500 W pendant 2 h**, soit **1 kWh** théorique. Aucune liaison avec le PZEM n'est utilisée.

**La fonction `calculerEnergieKWh()`** ne lit pas un capteur ; elle applique une formule à des valeurs reçues comme paramètres.

**La fonction `commanderLED(bool allumer)`** rend la commande de LED plus explicite. Le signe `?` suivi de `:` forme l'opérateur conditionnel : `allumer ? HIGH : LOW` signifie « si allumer est vrai, choisir HIGH, sinon choisir LOW ». C'est une écriture courte équivalente, pour cette expression, à un choix `if/else`.

**La fonction `afficherCalcul()`** affiche le résultat avec la liaison série. La construction `F("texte")`, utilisée sur Arduino AVR, permet de conserver ces chaînes constantes en mémoire programme plutôt que d'occuper inutilement la mémoire vive.

**La fonction `setup()`** configure la LED et le moniteur série à 9 600 bauds, puis affiche le calcul **une seule fois au démarrage**.

**La fonction `loop()`** continue de faire clignoter la LED exactement comme au chapitre précédent. Nous n'avons donc **pas supprimé** le comportement existant.

**Affichage série attendu :**

~~~text
FIL ROUGE M04 - LED M03 conservee
Puissance SIMULEE : 500.0 W
Duree SIMULEE : 2.0 h
Energie THEORIQUE fictive : 1.000 kWh
~~~

Ces lignes décrivent le résultat **attendu du programme**, et non un essai matériel confirmé par ce livre. L'affichage peut dépendre de la synchronisation du moniteur série avec le démarrage ; si vous ne voyez pas les lignes initiales, vérifiez le port, le débit et relancez le programme de manière appropriée.

**Une limitation temporaire est volontaire :** le clignotement utilise encore `delay()`, donc il bloque l'exécution normale pendant les attentes. Au chapitre 5, nous apprendrons à faire évoluer ce comportement.

**Une autre évolution importante viendra avec le modem GSM :** la liaison série matérielle de notre ATmega328P sera alors réservée au SIM800L. Les messages de diagnostic envoyés à l'ordinateur dans ce chapitre sont **un outil de formation**, pas une communication série à conserver simultanément sur les mêmes broches lors des échanges réels avec le modem.

---

## Partie C — Travaux pratiques et autoévaluation

### 4.14. TP 1 — Déclarer, convertir et afficher

**Objectif :** calculer une énergie fictive avec des variables `float`, puis reconnaître une division entière.

**Durée conseillée :** 15 à 25 minutes.

1. Recopiez le **programme 4.1** dans Arduino IDE.
2. Prédisez le résultat obtenu avec **500 W pendant 2 h**.
3. Vérifiez le code ; si vous disposez d'une Uno, téléversez-le.
4. Ouvrez le moniteur série à **9 600 bauds** et comparez les résultats affichés aux valeurs théoriques.
5. Remplacez la puissance par **200 W** et la durée par **5 h**.
6. Expliquez pourquoi les deux exemples produisent **1 kWh**.
7. Prédisez les résultats de `5 / 2` et `5.0f / 2.0f`, puis vérifiez-les dans un petit sketch.

**Travail à remettre :** un programme, les deux calculs et une explication de la division entière. Si aucun essai matériel n'a eu lieu, indiquez « résultats attendus, non observés ».

### 4.15. TP 2 — Conditions, boucles et fonctions

**Objectif :** choisir une branche, limiter une répétition et réutiliser une fonction.

**Durée conseillée :** 20 à 30 minutes.

1. Prédisez le message d'un `if/else` avec la tension **fictive de 245 V** et le seuil **purement pédagogique de 240 V**.
2. Remplacez la tension fictive par **230 V**. Quelle branche est choisie ?
3. Écrivez un `for` qui affiche les nombres **1, 2, 3 et 4**.
4. Écrivez un `while` qui incrémente un nombre d'essais de 0 à 3, puis **s'arrête**.
5. Appelez `wattsVersKilowatts(1250.0f)`. Quel résultat obtenez-vous ?
6. Appelez `calculerEnergieKWh(400.0f, 2.5f)`. Justifiez le résultat.
7. Sur une **copie de travail** du programme 4.2, remplacez la puissance fictive par **400 W** et la durée par **2,5 h**, sans retirer la LED.

**Important :** ces exercices n'impliquent **aucune intervention électrique**. La valeur de 240 V n'est pas un seuil de protection et ne doit pas servir au réglage d'une installation réelle.

### 4.16. Erreurs courantes à diagnostiquer

| Problème | Cause probable | Bonne démarche |
|---|---|---|
| `5 / 2` donne 2 au lieu de 2,5 | Division entre entiers | Employer au moins un opérande décimal |
| Le moniteur série n'affiche rien | Port, débit, démarrage, programme non envoyé | Vérifier la Uno, le téléversement et les **9 600 bauds** |
| Une condition produit le mauvais message | `=` au lieu de `==`, ou comparaison incorrecte | Relire les opérateurs et tester des cas connus |
| Une boucle reste bloquée | Condition qui ne devient jamais fausse | Prévoir l'évolution du compteur et la condition d'arrêt |
| Le calcul affiche une valeur incohérente | Unités mal converties ou hypothèse fausse | Refaire le calcul en W, kW, h et kWh |
| La LED ne clignote plus après modification | `loop()` supprimée ou commande changée | Comparer à la version du chapitre 3 |
| L'énergie est présentée comme mesurée | Valeurs inscrites directement dans le sketch | La qualifier explicitement de **simulation** |

### 4.17. Quiz — Dix questions

Pour chaque question, choisissez **une seule réponse**. Les explications figurent dans **l'annexe D** du livre.

**1. Quel type convient à un petit nombre entier de tentatives sur Uno Rev3 ?**  
A. `float` — B. `bool` — C. `int` — D. `char`

**2. Que représente `false` dans `bool alarme = false;` ?**  
A. Un état faux ou inactif — B. Une erreur de compilation — C. Un décimal — D. Un message série

**3. Que signifie `const` pour une valeur initialisée ?**  
A. Attendre un délai — B. Convertir en entier — C. Afficher en série — D. Empêcher sa modification ordinaire après initialisation

**4. Quel opérateur sert à tester l'égalité entre deux valeurs ?**  
A. `=` — B. `==` — C. `++` — D. `!=`

**5. Que donne `int resultat = 5 / 2;` sur notre Uno Rev3 ?**  
A. 2,5 — B. 3 — C. 2 — D. 0

**6. Pour `tensionFictiveV = 245.0f`, que fait `if (tensionFictiveV > 240.0f)` ?**  
A. Exécute la branche `if` — B. Exécute toujours `else` — C. N'exécute rien — D. Exécute les deux branches

**7. Quelle séquence produit `for (int i = 1; i <= 3; i++)` avec affichage de `i` ?**  
A. 0, 1, 2 — B. 1, 2 — C. 1, 2, 3 — D. 3 seulement

**8. Comment garantir l'arrêt de `while (essais < 3)` avec `essais` initialisé à 0 ?**  
A. Retirer les accolades — B. Ne rien modifier — C. Attendre sans changement — D. Incrémenter `essais` dans la boucle

**9. Que renvoie `wattsVersKilowatts(1250.0f)` ?**  
A. 1250 — B. 1,25 — C. 0,125 — D. 125

**10. Combien représente `(200.0f / 1000.0f) * 5.0f` en kWh, pour une puissance active constante ?**  
A. 1 000 — B. 0,2 — C. 5 — D. 1

Seuil de réussite proposé : **8 bonnes réponses sur 10**, avec correction des erreurs de typage, de calcul et de boucles avant d'aller plus loin.

---

## Partie D — Synthèse et prochaine évolution

### 4.18. Ce que nous avons réellement appris

Nous savons désormais utiliser :

- **une variable** pour conserver une valeur ;
- **un type** pour déterminer la nature de cette valeur ;
- **une constante** pour nommer un paramètre fixe ;
- **un calcul** pour convertir des unités et calculer une énergie théorique ;
- **une condition** pour choisir un comportement ;
- **une boucle bornée** pour répéter une action sans rester bloqué indéfiniment ;
- **une fonction** pour organiser et réutiliser notre code ;
- **le moniteur série** pour observer des résultats pédagogiques.

Nous avons aussi enrichi **le même programme du compteur** : la LED du chapitre 3 reste active ; une nouvelle fonction calcule une énergie fictive, et une autre l'affiche à l'ordinateur.

### 4.19. La limite de notre prototype à ce stade

Notre programme sait calculer une valeur à partir de nombres fournis par le code, mais il **n'a encore acquis aucune mesure électrique réelle**. Nous n'avons pas utilisé le PZEM ni connecté le secteur. Les valeurs affichées en série ne sont ni des relevés certifiés ni des preuves de fonctionnement d'une future liaison GSM.

De plus, la LED utilise toujours une attente bloquante `delay()`. Cette solution convient au présent exercice, mais devra évoluer lorsque plusieurs actions devront coexister.

### 4.20. Transition vers le chapitre 5

Au chapitre 5, nous apprendrons à **lire un bouton**, **commander une sortie** et **mieux utiliser les communications série**. Nous découvrirons aussi comment réaliser des temporisations moins bloquantes grâce à `millis()`.

Nous ne repartirons pas de zéro. Nous prendrons la version actuelle du compteur et nous ferons évoluer ses fonctions pour préparer les prochaines étapes de mesure et de supervision.
