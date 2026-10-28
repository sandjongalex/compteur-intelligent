# Annexe D — Corrigés du chapitre 4

> **Consultez cette annexe après votre propre tentative.** Tous les calculs de puissance, tension et énergie de cette annexe utilisent des **valeurs fictives**. Les exemples ne demandent aucun câblage au secteur et n'impliquent pas de mesure réelle du PZEM.

## D1. TP 1 — Variables et calculs d'énergie

### Premier calcul : 500 W pendant 2 heures

La puissance active constante choisie est **500 W**, soit **0,5 kW**. Pour une durée de **2 heures** :

**E = 0,5 kW × 2 h = 1 kWh.**

Le programme d'exercice est :

~~~cpp
const float puissanceW = 500.0f;  // FICTIF
const float dureeHeures = 2.0f;   // FICTIF

void setup() {
  Serial.begin(9600);
  float energieKWh =
      (puissanceW / 1000.0f) * dureeHeures;
  Serial.print("Energie fictive : ");
  Serial.print(energieKWh, 3);
  Serial.println(" kWh");
}

void loop() {
}
~~~

**Sortie attendue :**

~~~text
Energie fictive : 1.000 kWh
~~~

Il faut vérifier et téléverser sur une vraie carte avant de présenter la sortie comme une **observation matérielle**. Le moniteur série doit être réglé sur **9 600 bauds**.

### Deuxième calcul : 200 W pendant 5 heures

**E = (200 / 1 000) × 5 = 1 kWh.**

Les deux exemples donnent la même énergie, car un appareil moins puissant peut consommer autant lorsqu'il est utilisé plus longtemps.

~~~cpp
const float puissanceW = 200.0f;
const float dureeHeures = 5.0f;
~~~

Ces valeurs remplacent celles du premier exemple ; il ne faut pas déclarer une seconde fois les mêmes constantes dans un même fichier.

### Division entière

~~~cpp
int resultatEntier = 5 / 2;           // 2
float resultatDecimal = 5.0f / 2.0f;  // 2.5
~~~

La première opération utilise des entiers : la fraction disparaît. La seconde utilise des flottants et conserve la partie fractionnaire avec la précision disponible.

**Erreur fréquente :** écrire `float x = 5 / 2;` ne suffit pas, parce que `5 / 2` est évalué avant son rangement dans `x`.

### Barème pédagogique sur 10

| Critère | Points |
|---|---:|
| Conversion 500 W → 0,5 kW et calcul 1 kWh | 2 |
| Modification 200 W / 5 h et calcul correct | 2 |
| Configuration et compréhension du moniteur série | 2 |
| Explication de la division entière et flottante | 2 |
| Usage exact des unités W, kW, h, kWh | 2 |

Sans Arduino physique, l'absence d'essai est mentionnée : un résultat calculé sur papier ne devient pas une observation matérielle.

## D2. TP 2 — Conditions, boucles et fonction

### 1. Test de condition avec une tension fictive

~~~cpp
const float tensionFictiveV = 245.0f;
const float seuilPedagogiqueV = 240.0f;
~~~

La comparaison `245 > 240` est **vraie** : le code situé dans `if` est exécuté.

Si l'on remplace la tension par **230.0f**, la comparaison `230 > 240` devient **fausse** et le code de `else` doit être exécuté.

**Rappel de sécurité :** 240 V est un nombre pour apprendre les opérateurs. Il n'est pas un seuil de sécurité réelle.

### 2. Boucle for de 1 à 4

~~~cpp
for (int i = 1; i <= 4; i++) {
  Serial.println(i);
}
~~~

**Sortie attendue :**

~~~text
1
2
3
4
~~~

La variable `i` commence à 1, la comparaison `i <= 4` autorise la dernière valeur 4 et `i++` augmente le compteur après chaque passage.

### 3. Boucle while bornée

~~~cpp
int essais = 0;

while (essais < 3) {
  essais++;
}
~~~

**Valeur finale : 3.** La boucle termine parce que `essais` augmente et finit par rendre la condition fausse.

Sans `essais++`, ce code ne ferait plus évoluer la condition et pourrait bloquer la suite du sketch.

### 4. Fonction de conversion

~~~cpp
float wattsVersKilowatts(float watts) {
  return watts / 1000.0f;
}
~~~

Pour `wattsVersKilowatts(1250.0f)`, le résultat vaut **1,25 kW**.

`return` sert à **renvoyer la valeur calculée** vers l'appelant de la fonction.

### 5. Calcul d'énergie avec une fonction

~~~cpp
float calculerEnergieKWh(float puissanceW,
                         float dureeHeures) {
  return (puissanceW / 1000.0f) * dureeHeures;
}
~~~

Le résultat de `calculerEnergieKWh(400.0f, 2.5f)` est :

**(400 / 1 000) × 2,5 = 0,4 × 2,5 = 1 kWh.**

### 6. Conserver la LED lors de l'évolution

Dans une **copie du programme 4.2**, les deux constantes de données deviennent :

~~~cpp
const float PUISSANCE_SIMULEE_W = 400.0f;
const float DUREE_SIMULEE_H = 2.5f;
~~~

La fonction `calculerEnergieKWh()` continue de produire **1,000 kWh** dans cet exercice. Les fonctions `commanderLED()` et `loop()` restent présentes : le clignotement de la LED est **conservé**.

Ce point est fondamental : on n'apprend pas à structurer un projet embarqué en supprimant les fonctions des étapes précédentes sans raison.

### Barème pédagogique sur 10

| Critère | Points |
|---|---:|
| Choix de branche `if/else` pour 245 V fictifs | 2 |
| Nouvelle branche pour 230 V fictifs | 2 |
| `for` correct et borné de 1 à 4 | 2 |
| `while` correctement bornée | 1 |
| Fonction paramétrée et `return` compris | 2 |
| Calcul 400 W pendant 2,5 h = 1 kWh | 1 |

## D3. Réponses du quiz de dix questions

| Question | Bonne réponse | Justification |
|---|---|---|
| 1 | **C** | `int` convient pour mémoriser un petit entier. |
| 2 | **A** | `false` représente ici l'état faux ou inactif d'un booléen. |
| 3 | **D** | `const` interdit de modifier normalement la valeur après son initialisation. |
| 4 | **B** | `==` compare deux valeurs ; `=` affecte une valeur. |
| 5 | **C** | `5 / 2` entre entiers vaut 2, sans partie fractionnaire. |
| 6 | **A** | 245 est supérieur à 240 : la branche `if` est choisie. |
| 7 | **C** | La boucle affiche successivement 1, 2 et 3. |
| 8 | **D** | L'incrément rend la condition de `while` fausse après trois passages. |
| 9 | **B** | 1 250 W ÷ 1 000 = 1,25 kW. |
| 10 | **D** | (200 W ÷ 1 000) × 5 h = 1 kWh. |

**Seuil conseillé : 8/10.** Une erreur sur la division entière ou le risque de boucle infinie mérite une correction, même si le score total est suffisant.

## D4. Difficultés fréquentes

**« Mon programme compile : mes calculs sont donc corrects ? »**  
Non. Un code syntaxiquement correct peut réaliser le mauvais calcul, par exemple une division entière imprévue ou une conversion d'unités incorrecte.

**« Un résultat avec trois décimales est forcément précis ? »**  
Non. L'affichage `Serial.print(x, 3)` formate le nombre ; il ne rend pas plus précise une mesure ni un calcul `float`.

**« La fonction `calculerEnergieKWh` mesure-t-elle la consommation du réseau ? »**  
Non. Dans ce chapitre, elle traite des paramètres fictifs. Une mesure physique et un suivi par périodes nécessiteront des composants et des contrôles supplémentaires.

**« Pourquoi ne pas conserver le moniteur série USB en même temps que le SIM800L ? »**  
Notre architecture finale réserve la liaison série matérielle au modem GSM. Les messages de formation de ce chapitre ne doivent pas être considérés comme une communication USB disponible simultanément lors d'échanges modem réels.

## D5. Vérification des acquis avant le chapitre 5

Vous devez pouvoir :

- expliquer `int`, `float`, `bool`, `const` ;
- distinguer `=` et `==` ;
- prédire `5 / 2` et `5.0f / 2.0f` ;
- construire un `if/else`, un `for` et un `while` borné ;
- lire une fonction avec paramètres et `return` ;
- expliquer pourquoi le programme du compteur **continue de faire clignoter la LED**, tout en affichant un calcul fictif.

Si l'un de ces points reste flou, reprenez les sections correspondantes du chapitre 4 avant de travailler sur les entrées/sorties et les temporisations non bloquantes.
