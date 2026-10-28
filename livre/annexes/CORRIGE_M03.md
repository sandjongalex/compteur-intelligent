# Annexe C — Corrigés du chapitre 3

> **À consulter après les exercices.** Les programmes sont destinés à une Arduino Uno Rev3 correctement alimentée par USB. La réalisation des montages doit se faire hors tension, sans secteur ni module de mesure raccordé.

## C1. TP 1 — Installer, vérifier et téléverser

### Les étapes attendues

1. Installer et ouvrir Arduino IDE 2 sur un ordinateur compatible.
2. Connecter une Arduino Uno Rev3 avec un câble USB capable de transmettre des données.
3. Sélectionner la carte **Arduino Uno** et le port de communication correspondant.
4. Créer le programme minimal :

~~~cpp
void setup() {
}

void loop() {
}
~~~

5. Cliquer sur **Vérifier** : une compilation réussie signifie que la syntaxe et les outils de compilation acceptent le code pour la carte choisie.
6. Cliquer sur **Téléverser** : si la connexion fonctionne et que la procédure aboutit, le programme est transféré vers la carte.
7. Sur une **copie du code**, retirer volontairement une accolade de fermeture : la vérification doit alors échouer.
8. Rétablir l'accolade et vérifier à nouveau.

**Réponse à la question « Pourquoi le programme minimal ne fait-il rien de visible ? »**  
Parce que `setup()` et `loop()` ne contiennent aucune instruction de commande de LED. Une structure de programme valide n'a pas besoin de produire un changement visible.

**Différence fondamentale :**

- **Vérifier :** compiler et signaler les erreurs du code sans le transférer obligatoirement sur la carte.
- **Téléverser :** compiler puis transférer le programme à la carte sélectionnée.

**Ne pas confondre les preuves :** on peut étudier la compilation sans carte, mais on ne peut pas affirmer avoir téléversé un programme sans transfert effectif.

### Exemple d'erreur de syntaxe volontaire

~~~cpp
void setup() {
}

void loop() {
  // Accolade fermante manquante : programme incorrect
~~~

La correction consiste à remettre `}`, puis à relancer **Vérifier**.

**Barème indicatif sur 10 :** installation et sélection de la carte (2), sélection du port (2), vérification du programme (2), téléversement effectif (2), identification et correction de l'erreur (2). Si la carte n'est pas disponible, l'étape de téléversement reste « non effectuée » plutôt que d'être déclarée réussie.

## C2. TP 2 — Clignotement de la LED intégrée

### Programme de base : 1 s allumée / 1 s éteinte

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

`LED_BUILTIN` désigne la LED intégrée de la Uno Rev3, reliée à **D13**. `pinMode()` prépare la sortie ; `digitalWrite()` commande son état ; `delay()` fixe l'attente en **millisecondes**.

### Programme modifié : 250 ms allumée / 750 ms éteinte

~~~cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(750);
}
~~~

**Résultat attendu :** clignotement avec un temps allumé plus court que le temps éteint. Un cycle vaut **250 + 750 = 1 000 ms**, soit **1 seconde**.

**Mini-défi du chapitre 3 :** pour **500 ms allumée / 1 500 ms éteinte**, utiliser `delay(500);` après `HIGH`, puis `delay(1500);` après `LOW`. Le cycle dure **2 secondes**.

## C3. TP 2 — LED externe sur D8

### Vérifications de sécurité

L'USB doit être **débranché** avant de placer ou déplacer les fils.

Chemin de connexion basse tension du montage pédagogique :

**D8 → résistance 330 Ω → anode LED → cathode LED → GND.**

La résistance est **obligatoire** pour limiter le courant dans le circuit de cette LED standard. Vérifier la polarité de la LED. Ne jamais relier une breadboard au secteur domestique.

### Programme de base sur D8

~~~cpp
const byte LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
~~~

### Programme corrigé : LED externe, 250 ms / 750 ms

~~~cpp
const byte LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
  delay(750);
}
~~~

Le code conserve la **même organisation** que le premier programme. La différence principale est l'utilisation de la broche `D8` pour la LED externe et les nouvelles durées.

**Barème indicatif sur 10 :** polarité et résistance correctes (3 points), connexion D8–GND correcte (2), adaptation du programme (3), capacité à expliquer et observer le comportement (2). Aucun point d'observation réelle ne doit être attribué si l'essai n'a pas eu lieu.

## C4. Quiz — Dix réponses expliquées

| Question | Réponse | Explication |
|---|---|---|
| 1 | **B** | Arduino IDE sert à écrire, compiler et téléverser des programmes Arduino. |
| 2 | **D** | Les démonstrations sont conçues pour une Arduino Uno Rev3. |
| 3 | **A** | Il faut sélectionner le modèle de carte et le port utilisé. |
| 4 | **C** | `loop()` est répétée après l'exécution initiale de `setup()`. |
| 5 | **B** | Le bouton Vérifier compile le programme ; le transfert n'est pas son objectif. |
| 6 | **A** | Une accolade manquante est une erreur de syntaxe détectable par le compilateur. |
| 7 | **D** | Après une compilation réussie, examiner d'abord le câble USB de données, la carte et le port. |
| 8 | **C** | Les fonctions du sketch minimal sont vides et ne commandent aucun résultat visible. |
| 9 | **B** | La résistance en série limite le courant de la LED externe et de la sortie numérique. |
| 10 | **A** | Les attentes `delay(250)` et `delay(750)` sont placées respectivement après `HIGH` et `LOW`. |

### Trois difficultés à comprendre

**Pourquoi compiler ne prouve-t-il pas que le programme fonctionne ?** Parce que la compilation ne vérifie pas tous les aspects du matériel : liaison USB, carte, circuit externe et comportement réel.

**Pourquoi une LED externe a-t-elle besoin d'une résistance, même avec une broche 5 V ?** La broche et la diode ne doivent pas être sollicitées au-delà de leurs capacités. La résistance choisie en fonction de la LED et de la sortie contribue à limiter le courant.

**Pourquoi `delay()` n'est-il pas une solution universelle ?** Le programme principal attend au lieu d'effectuer librement d'autres opérations. Le compteur devra plus tard lire des mesures et gérer plusieurs tâches : nous apprendrons des temporisations non bloquantes au chapitre 5.

## C5. Vérifier que vous maîtrisez le chapitre 3

Avant de passer à la suite, vous devez pouvoir expliquer à une autre personne :

- ce qu'est un sketch Arduino ;
- les rôles respectifs de `setup()` et `loop()` ;
- la différence entre vérifier et téléverser ;
- les fonctions de `pinMode()`, `digitalWrite()` et `delay()` ;
- pourquoi la résistance d'une LED externe est indispensable dans notre exemple ;
- pourquoi le premier clignotement fait partie du **même programme fil rouge** qui sera amélioré au chapitre 4.

**La priorité reste la compréhension du code et la sécurité des essais**, non la vitesse à laquelle on termine les exercices.
