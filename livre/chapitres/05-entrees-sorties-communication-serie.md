# Chapitre 5 — Entrées, sorties et communication série : un compteur plus réactif

> **Niveau :** débutant, après les chapitres 3 et 4.  
> **Matériel nécessaire aux essais :** Arduino Uno Rev3, câble USB de données, ordinateur équipé d'Arduino IDE 2, bouton-poussoir momentanément fermé, fils et breadboard réservés à la basse tension. La LED intégrée de l'Uno suffit.  
> **Pratique personnelle :** 40 à 60 minutes, hors lecture.  
> **Sécurité :** ne jamais raccorder le secteur 230 V, le PZEM-004T ou le SIM800L pour ces exercices. Débrancher le câble USB avant de modifier le montage. Les tensions présentées dans le moniteur série sont **fictives**.

Au chapitre 3, nous avons fait clignoter une LED. Au chapitre 4, nous avons appris à organiser notre programme avec des variables, des conditions, des boucles et des fonctions, puis à afficher un calcul d'énergie théorique.

Mais un vrai système embarqué ne doit pas uniquement exécuter une suite d'attentes. Il doit pouvoir réagir **à un bouton**, recevoir **une commande** et effectuer **une tâche périodique** sans immobiliser toutes les autres.

Nous allons donc faire évoluer la LED : au lieu de clignoter toute seule, elle deviendra un **indicateur commandé par l'utilisateur**. C'est un changement volontaire de fonction, pas une suppression accidentelle. Plus tard, le même principe permettra notamment de choisir une page de l'écran LCD.

Ce chapitre traite les deux sujets fondamentaux suivants : **les entrées et sorties numériques** puis **les échanges série UART et les temporisations avec millis()**. Nous commencerons par de très petits exemples pour comprendre, puis nous examinerons une version intégrée du programme du compteur.

## Objectifs du chapitre

À la fin de ce chapitre, vous pourrez :

1. configurer une entrée en `INPUT_PULLUP` et une sortie en `OUTPUT` ;
2. comprendre pourquoi un bouton relié entre D2 et GND donne **HIGH au repos** et **LOW à l'appui** ;
3. distinguer une action maintenue d'un **événement de nouvel appui** ;
4. réduire les doubles déclenchements dus aux **rebonds mécaniques** ;
5. utiliser `Serial.begin()`, `Serial.available()`, `Serial.read()` et le moniteur série ;
6. commander la LED avec les caractères `'1'`, `'0'` et `'?'` ;
7. utiliser `millis()` pour effectuer des tâches périodiques sans `delay()` ;
8. expliquer la différence entre les programmes d'exercice et la version intégrée du compteur.

---

## Partie A — Entrées, sorties et bouton avec anti-rebond

### 5.1. Une entrée lit, une sortie agit

Une **entrée numérique** permet au microcontrôleur de connaître un état électrique interprété comme **HIGH** ou **LOW**. Une **sortie numérique** permet au programme de commander un niveau logique, dans les limites électriques des broches.

Notre nouveau montage utilise seulement :

- la broche **D2** comme entrée du bouton ;
- la LED intégrée **L** de l'Arduino Uno Rev3, associée à **D13**, comme sortie ;
- la borne **GND** comme référence du bouton ;
- l'alimentation USB normale de la carte.

Le bouton est un **contact**, pas une source d'alimentation. Quand nous l'actionnons, il relie momentanément les deux points de son circuit.

Avant de poser les fils, **débranchons l'USB**. Le chemin prévu est le suivant :

~~~text
  Arduino Uno Rev3         Bouton-poussoir
        D2  -------------  Contact A
        GND -------------  Contact B

  Contact ouvert :  D2 n'est pas reliée à GND
  Contact fermé :  D2 est reliée à GND
~~~

**Figure 5.1 — Principe de connexion du bouton entre D2 et GND.** Il s'agit uniquement d'un montage en basse tension. Aucune alimentation externe ni aucun branchement secteur n'est nécessaire.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.1
Type : schéma électrique et dessin pédagogique basse tension.
Contenu et annotations : représenter une Arduino Uno Rev3, D2, GND et un bouton-poussoir momentanément fermé entre ces deux broches, sans branchement au 5 V ni au secteur ; identifier la LED L déjà intégrée sur D13.
Légende finale : Figure 5.1 — Un bouton commande une entrée D2 par contact avec GND.
Texte alternatif : La broche numérique D2 de la carte Uno est reliée à GND uniquement lorsque le bouton se ferme ; la LED L est intégrée à la carte.
Contraintes : ne montrer ni PZEM ni secteur ; connexions vérifiées ; photo/schéma sous droits utilisables pour un ouvrage commercial.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.1]** Schéma : bouton entre D2 et GND, LED intégrée D13.

**Attention aux boutons à quatre pattes :** certains contacts sont déjà reliés deux à deux à l'intérieur du composant. Il faut identifier les deux bornes dont la liaison se ferme **seulement pendant l'appui**. Ne pas supposer que deux pattes voisines sont forcément celles à employer. Consulter la documentation ou vérifier hors tension avec un instrument approprié.

### 5.2. Pourquoi INPUT_PULLUP inverse-t-il l'interprétation ?

Une entrée laissée sans référence électrique peut **flotter** : sa lecture devient incertaine. L'ATmega328P peut activer une **résistance interne de rappel** qui maintient notre entrée au niveau haut lorsque le bouton est relâché.

~~~cpp
pinMode(2, INPUT_PULLUP);
~~~

Pour notre montage **D2–bouton–GND**, les états attendus sont :

| Position du bouton | Connexion vers GND | `digitalRead(2)` |
|---|---|---|
| Relâché | Contact ouvert | **HIGH** |
| Appuyé | Contact fermé | **LOW** |

L'utilisation de `INPUT_PULLUP` évite d'ajouter une résistance de rappel externe pour cette démonstration.

Ce résultat surprend parfois : **LOW signifie ici « appuyé »**. Ce n'est pas une règle valable pour tous les circuits, mais une conséquence de **notre montage et de la résistance de rappel**.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.2
Type : double schéma de principe annoté.
Contenu et annotations : comparer bouton ouvert et bouton fermé, avec résistance de rappel interne vers le domaine 5 V, D2 et GND ; HIGH au repos, LOW à l'appui ; mention « schéma de principe », pas représentation détaillée d'un contact réel.
Légende finale : Figure 5.2 — Avec INPUT_PULLUP, l'appui fait passer D2 de HIGH à LOW.
Texte alternatif : Deux états du bouton montrent la résistance interne maintenant D2 à HIGH au repos puis la liaison à GND entraînant LOW à l'appui.
Contraintes : pas de connexion directe 5 V–GND via bouton ; différencier résistance interne et contact ; montage Uno basse tension.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.2]** Schéma comparatif : HIGH quand le bouton est relâché, LOW pendant l'appui.

**Figure 5.2 — Avec INPUT_PULLUP, l'appui fait passer D2 de HIGH à LOW.**

### 5.3. Première version : la LED suit le bouton

Commençons par un programme très simple :

~~~cpp
const byte BROCHE_BOUTON = 2;
const byte BROCHE_LED = LED_BUILTIN;

void setup() {
  pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  pinMode(BROCHE_LED, OUTPUT);
}

void loop() {
  bool boutonAppuye =
      (digitalRead(BROCHE_BOUTON) == LOW);

  digitalWrite(BROCHE_LED,
               boutonAppuye ? HIGH : LOW);
}
~~~

**Programme 5.1 — La LED est allumée uniquement pendant l'appui.**

Nous retrouvons plusieurs constructions du chapitre précédent :

- `const byte` nomme une broche dont le numéro ne change pas ;
- `pinMode(..., INPUT_PULLUP)` prépare l'entrée ;
- `digitalRead()` lit le niveau de D2 ;
- `== LOW` vérifie l'égalité avec l'état bas ;
- `bool boutonAppuye` conserve le résultat vrai/faux ;
- l'opérateur `? :` sélectionne l'état de la LED.

**Résultat attendu :** maintenir le bouton allume la LED ; relâcher le bouton l'éteint.

Il ne s'agit pas encore de ce que nous cherchons pour un changement de page : nous voulons que **chaque nouvel appui** produise **un seul changement** et que le résultat reste visible après le relâchement.

### 5.4. Détecter un nouvel appui plutôt qu'un niveau maintenu

Pour reconnaître le début d'un appui, nous pouvons comparer **l'état actuel** à **l'état mémorisé précédemment**.

~~~cpp
bool ancienEtatAppuye = false;
bool ledAllumee = false;

void loop() {
  bool appuye =
      (digitalRead(BROCHE_BOUTON) == LOW);

  if (appuye && !ancienEtatAppuye) {
    ledAllumee = !ledAllumee;
    digitalWrite(BROCHE_LED,
                 ledAllumee ? HIGH : LOW);
  }

  ancienEtatAppuye = appuye;
}
~~~

Il s'agit ici du **corps de la fonction loop() à insérer** dans le sketch précédent, avec les deux variables déclarées globalement. La configuration des broches dans `setup()` est conservée.

La condition `appuye && !ancienEtatAppuye` signifie : « le bouton est appuyé maintenant, mais il ne l'était pas lors de la lecture précédente ».

L'instruction `ledAllumee = !ledAllumee;` inverse le booléen : `true` devient `false`, et inversement. C'est la **bascule**.

Ce programme est utile pour comprendre la logique d'événement, mais il comporte une faiblesse : le contact d'un bouton mécanique ne change pas toujours d'état une seule fois, proprement.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.3
Type : chronogramme comparatif.
Contenu et annotations : montrer LED « suit le bouton » allumée seulement pendant l'appui, puis LED « bascule » changeant une fois au premier front et restant dans son nouvel état pendant le relâchement.
Légende finale : Figure 5.3 — Le niveau maintenu et l'événement d'appui ne donnent pas le même comportement.
Texte alternatif : Deux chronogrammes montrent d'abord une LED active uniquement lorsque le bouton est pressé, puis une LED qui conserve son nouvel état après l'appui.
Contraintes : modèles de comportement attendus ; ne pas présenter la bascule sans anti-rebond comme garantie de fiabilité réelle.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.3]** Chronogramme : LED maintenue pendant l'appui ou basculée une fois.

**Figure 5.3 — Niveau maintenu et événement d'appui.**

### 5.5. Les rebonds mécaniques : un appui peut produire plusieurs transitions

Lorsqu'un contact métallique se ferme, il peut se fermer et se rouvrir très rapidement plusieurs fois avant de se stabiliser. On appelle cela le **rebond mécanique**.

Une représentation simplifiée d'un appui peut ressembler à ceci :

~~~text
Temps  ------->

HIGH  -------+  +--+--------------------
             |  |  |
LOW          +--+  +--------------------
             rebonds     état stable
~~~

Cette représentation est **conceptuelle**, pas une capture d'oscilloscope réelle. Les rebonds observés dépendent du bouton et des conditions physiques.

Si nous activons une bascule à chaque transition détectée, un seul geste peut commander la LED plusieurs fois. Le résultat final pourrait sembler aléatoire.

La solution enseignée ici est l'**anti-rebond logiciel** : nous attendons que le nouvel état soit resté suffisamment stable avant de le confirmer.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.4
Type : chronogramme de contact.
Contenu et annotations : représenter un appui avec plusieurs oscillations HIGH/LOW pendant quelques millisecondes, puis un LOW stable ; indiquer la différence entre signal brut et décision validée.
Légende finale : Figure 5.4 — Le rebond mécanique peut simuler plusieurs appuis.
Texte alternatif : Un contact mécanique change rapidement plusieurs fois de niveau avant de se stabiliser à LOW, tandis que le logiciel ne doit compter qu'un seul appui.
Contraintes : chronogramme pédagogique fictif, pas de prétention à une acquisition instrumentale réelle.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.4]** Chronogramme : transitions parasites du bouton puis stabilisation.

**Figure 5.4 — Le rebond mécanique peut simuler plusieurs appuis.**

### 5.6. Introduire millis() pour confirmer un état stable

La fonction `millis()` indique le nombre de millisecondes écoulées depuis le démarrage du programme sur l'Arduino. Elle ne donne ni l'heure civile, ni la date : ces informations proviendront plus tard d'une **horloge DS3231**.

Nous allons retenir une période pédagogique d'anti-rebond :

~~~cpp
const unsigned long ANTIREBOND_MS = 35UL;
~~~

**35 ms** est un choix de démonstration, pas une valeur universelle valable pour tous les boutons.

Pour rendre la décision fiable, notre programme doit distinguer :

1. le **niveau brut** lu immédiatement sur D2 ;
2. le **dernier niveau brut** pour repérer un changement ;
3. l'**instant du dernier changement** ;
4. le **niveau stable confirmé** ;
5. un événement seulement lorsque le **niveau stable devient LOW**.

Voici une version complète pour la LED intégrée :

~~~cpp
const byte BROCHE_BOUTON = 2;
const byte BROCHE_LED = LED_BUILTIN;
const unsigned long ANTIREBOND_MS = 35UL;

int dernierNiveauBrut = HIGH;
int niveauStable = HIGH;
unsigned long debutChangementMs = 0;
bool ledAllumee = false;

void setup() {
  pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  pinMode(BROCHE_LED, OUTPUT);
  digitalWrite(BROCHE_LED, LOW);
}

void loop() {
  const unsigned long maintenant = millis();
  const int niveauBrut = digitalRead(BROCHE_BOUTON);

  if (niveauBrut != dernierNiveauBrut) {
    debutChangementMs = maintenant;
  }

  if ((unsigned long)(maintenant - debutChangementMs)
          >= ANTIREBOND_MS &&
      niveauBrut != niveauStable) {

    niveauStable = niveauBrut;

    if (niveauStable == LOW) {
      ledAllumee = !ledAllumee;
      digitalWrite(BROCHE_LED,
                   ledAllumee ? HIGH : LOW);
    }
  }

  dernierNiveauBrut = niveauBrut;
}
~~~

**Programme 5.2 — Bascule de LED après stabilisation du bouton.**

Prenons le temps de lire les blocs essentiels.

**Détecter un changement brut :** si `niveauBrut` diffère de `dernierNiveauBrut`, nous mémorisons l'instant actuel. Un nouveau rebond remet donc à zéro notre période d'observation.

**Confirmer la stabilité :** nous vérifions qu'au moins 35 ms se sont écoulées depuis le dernier changement brut, et que ce niveau diffère du niveau stable précédemment enregistré.

**Déclencher au bon moment :** le changement de `ledAllumee` a lieu uniquement si le nouveau niveau stable vaut **LOW**. Au relâchement, l'état stable redevient HIGH, mais la LED ne rebascule pas.

Le type `unsigned long` est adapté à `millis()` sur notre carte. La formule **`maintenant - debutChangementMs`** utilise l'arithmétique non signée et peut rester correcte lors du retour à zéro du compteur de millisecondes, tant que l'intervalle testé demeure dans sa plage.

**Résultat attendu :** chaque appui distinct et stabilisé inverse **une fois** la LED. Une pression maintenue ne provoque pas de bascules successives.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.5
Type : schéma de traitement et frise temporelle.
Contenu et annotations : niveau brut change → mémoriser millis → attendre 35 ms de stabilité → accepter état stable → si LOW, basculer LED une fois ; distinguer rebond et front confirmé.
Légende finale : Figure 5.5 — La validation de 35 ms transforme les lectures brutes en événement d'appui.
Texte alternatif : Organigramme de l'anti-rebond montrant un changement brut, une attente de stabilité de 35 millisecondes et une bascule de LED seulement sur un appui stable LOW.
Contraintes : les 35 ms sont un choix de cours et non une garantie absolue, logique du code Arduino cohérente.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.5]** Organigramme : lecture brute, validation après 35 ms et changement de LED.

**Figure 5.5 — De la lecture brute à un appui stable.**

### 5.7. Pourquoi cette fonction servira à l'écran LCD

Imaginons notre futur LCD capable de montrer deux pages :

- **page 0** : tension et date ;
- **page 1** : énergie du jour et du mois.

Nous pouvons utiliser un octet pour mémoriser le numéro de page :

~~~cpp
byte page = 0;

// Dans le traitement d'un nouvel appui STABLE :
page = (byte)(1 - page);  // 0 devient 1 ; 1 devient 0
~~~

Le calcul `1 - page` est correct ici **parce que page vaut uniquement 0 ou 1**.

Pour le moment, nous ne pilotons pas réellement le LCD. Nous simulons son changement de page avec la LED intégrée et, lors du TP, avec un message envoyé au moniteur série.

---

## Partie B — Échanger des commandes UART et programmer sans délai bloquant

### 5.8. Qu'est-ce qu'une communication série UART ?

Jusqu'ici, le microcontrôleur prenait surtout des décisions à partir d'un bouton. Il peut aussi recevoir des **données** sous forme de caractères envoyés depuis l'ordinateur.

Une liaison **UART** (*Universal Asynchronous Receiver/Transmitter*) transporte des données en série. Dans un échange entre deux appareils compatibles, on rencontre généralement :

- **TX** : signal d'émission ;
- **RX** : signal de réception ;
- une vitesse de communication et un format communs ;
- une référence électrique et des niveaux logiques compatibles.

Sur notre **Arduino Uno Rev3**, l'interface matérielle `Serial` utilise notamment les broches **D0/RX** et **D1/TX** et communique avec l'ordinateur à travers l'interface USB de la carte.

Pour ce chapitre, **nous utilisons exclusivement le câble USB et le moniteur série**. Aucun modem, convertisseur série externe ou PZEM ne doit être branché sur D0/D1.

Plus tard, la liaison série matérielle sera dédiée au **SIM800L**, avec adaptation électrique appropriée. Les essais pédagogiques par le moniteur USB **ne doivent pas être supposés disponibles simultanément** aux échanges GSM réels sur ce même port.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.6
Type : schéma conceptuel de liaison série.
Contenu et annotations : Uno Rev3 → interface USB de la carte → ordinateur/moniteur série ; agrandir le rôle de D0/RX et D1/TX ; à côté, principe TX vers RX avec avertissement sur compatibilité des niveaux, sans câblage du SIM800L.
Légende finale : Figure 5.6 — L'UART transporte des caractères entre équipements compatibles.
Texte alternatif : Diagramme de l'Uno reliée à l'ordinateur par USB pour l'échange de caractères et explication des rôles TX/RX de son port matériel.
Contraintes : aucun schéma de branchement direct du modem nu 2,8 V à l'ATmega 5 V ; ne pas proposer de connexion sur D0/D1 pendant l'essai USB.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.6]** Schéma : UART, TX/RX et chemin USB vers le moniteur série.

**Figure 5.6 — L'UART transporte des caractères entre équipements compatibles.**

### 5.9. Recevoir un caractère avec available() et read()

Initialisons d'abord le port série :

~~~cpp
void setup() {
  Serial.begin(9600);
  Serial.println("Pret : saisir un caractere.");
}
~~~

Dans `loop()`, nous allons seulement lire **si un caractère est disponible** :

~~~cpp
void loop() {
  if (Serial.available() > 0) {
    char recu = (char)Serial.read();

    if (recu != '\r' && recu != '\n') {
      Serial.print("Recu : ");
      Serial.println(recu);
    }
  }
}
~~~

**Programme 5.3 — Lecture d'un caractère dans le moniteur série.** Utiliser les deux blocs `setup()` et `loop()` ci-dessus dans le même sketch.

`Serial.available()` indique combien d'octets attendent dans le tampon de réception. Le test `> 0` permet de **ne pas lire dans le vide**.

`Serial.read()` récupère le prochain octet disponible. Nous le convertissons ici en `char` pour l'interpréter comme un caractère.

Les caractères spéciaux `'\r'` et `'\n'` correspondent aux fins de ligne que le moniteur série peut ajouter suivant son réglage. Notre exemple les ignore.

Si vous envoyez le caractère `A`, la sortie **attendue** est :

~~~text
Recu : A
~~~

Le débit du moniteur doit être réglé à **9 600 bauds**. Le traitement d'un caractère ne constitue pas encore un protocole complet pour transmettre des nombres, des relevés horodatés ou des messages complexes ; cette étape sera étudiée plus tard.

### 5.10. Donner un sens aux caractères 1, 0 et ?

Nous voulons maintenant utiliser les caractères reçus pour commander la LED :

| Caractère reçu | Action |
|---|---|
| `'1'` | Allumer la LED |
| `'0'` | Éteindre la LED |
| `'?'` | Afficher l'aide |

**Différence importante :** `'1'` est le **caractère** un, alors que `1` est un **nombre entier**. Les deux ne sont pas interchangeables dans une comparaison de caractères.

Le traitement peut être organisé ainsi :

~~~cpp
void traiterCommandes() {
  while (Serial.available() > 0) {
    const char commande = (char)Serial.read();

    if (commande == '\r' || commande == '\n') {
      continue;
    }

    if (commande == '1') {
      ledAllumee = true;
    } else if (commande == '0') {
      ledAllumee = false;
    } else if (commande == '?') {
      Serial.println("1=ON 0=OFF ?=aide");
      continue;
    } else {
      Serial.println("Commande inconnue");
      continue;
    }

    digitalWrite(LED_BUILTIN,
                 ledAllumee ? HIGH : LOW);
    Serial.println(ledAllumee ? "LED ON"
                             : "LED OFF");
  }
}
~~~

Ce bloc suppose que la variable globale `bool ledAllumee = false;` a été déclarée et que la LED a été configurée en sortie dans `setup()`.

La boucle `while` ne tourne **que tant qu'il existe des caractères déjà disponibles**. Elle n'attend pas qu'un caractère nouveau arrive. Lorsqu'il n'y a plus rien dans le tampon, le programme peut poursuivre ses autres tâches.

En envoyant `1`, la LED doit s'allumer. `0` doit l'éteindre. `?` doit afficher les commandes disponibles.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.7
Type : capture authentique d'Arduino IDE 2, avec annotations.
Contenu et annotations : moniteur série à 9600 bauds, exemple d'envoi des caractères '1', '0', '?' et réponses LED ON, LED OFF, aide ; comparer caractère numérique et nombre entier.
Légende finale : Figure 5.7 — Trois caractères suffisent pour commander et interroger la LED.
Texte alternatif : Moniteur série affichant les commandes un, zéro et point d'interrogation et leurs réponses associées de commande LED.
Contraintes : capture réelle à réaliser après test sur carte ; ne pas fabriquer une sortie prétendument mesurée ; masquer les données personnelles.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.7]** Capture : caractères envoyés au moniteur série et réponses de la LED.

**Figure 5.7 — Trois caractères suffisent pour commander et interroger la LED.**

### 5.11. Le défaut de delay() pour plusieurs tâches

Souvenons-nous du premier clignotement :

~~~cpp
digitalWrite(LED_BUILTIN, HIGH);
delay(1000);
digitalWrite(LED_BUILTIN, LOW);
delay(1000);
~~~

Pendant chaque `delay(1000)`, le déroulement normal du code attend environ une seconde. Si une commande arrive alors, son traitement dans la boucle principale est **retardé**.

La fonction `delay()` ne signifie pas que tous les périphériques matériels cessent de fonctionner : des interruptions peuvent encore intervenir et des caractères peuvent être reçus dans un tampon. Mais la **logique de notre programme n'avance pas** comme elle le ferait dans une boucle libre.

Notre compteur devra lire un bouton, afficher une valeur et gérer des communications. La technique des pauses bloquantes n'est pas adaptée à toutes ces tâches concurrentes.

### 5.12. Déclencher une tâche avec millis()

Au lieu d'attendre une seconde en restant bloqués, nous allons **vérifier périodiquement le temps écoulé**.

~~~cpp
const unsigned long PERIODE_MS = 1000UL;
unsigned long dernierEnvoiMs = 0;

void setup() {
  Serial.begin(9600);
  dernierEnvoiMs = millis();
}

void loop() {
  const unsigned long maintenant = millis();

  if ((unsigned long)(maintenant - dernierEnvoiMs)
      >= PERIODE_MS) {

    dernierEnvoiMs = maintenant;
    Serial.println("Releve fictif periodique");
  }

  // D'autres instructions peuvent continuer ici.
}
~~~

Les trois éléments sont :

1. **`PERIODE_MS`** : durée souhaitée entre deux actions ;
2. **`dernierEnvoiMs`** : instant mémorisé de la dernière action ;
3. **`maintenant - dernierEnvoiMs`** : temps écoulé depuis cette action.

La comparaison `>= PERIODE_MS` déclenche la tâche **quand le temps est atteint**, sans immobiliser la boucle entre deux échéances.

Le calcul de différence entre valeurs `unsigned long` est également la technique appropriée sur Uno lorsque `millis()` repasse à zéro, pour des intervalles raisonnablement courts par rapport à la plage du compteur.

Il s'agit d'un **cadencement approximatif** : si une autre tâche prend du temps, l'exécution peut être légèrement retardée. `millis()` n'est pas une horloge calendrier et ne remplace pas le DS3231.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.8
Type : diagramme temporel comparatif.
Contenu et annotations : comparer delay(1000) qui retarde la prise en compte des commandes et millis() avec plusieurs tours loop entre deux émissions fictives espacées d'environ 1000 ms.
Légende finale : Figure 5.8 — Avec millis(), le programme continue d'écouter entre deux affichages.
Texte alternatif : Deux frises comparent une attente bloquante d'une seconde et une boucle qui surveille l'heure écoulée tout en traitant les commandes reçues.
Contraintes : représenter des intervalles approximatifs, aucune précision temps réel garantie ; code et unités cohérents.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.8]** Chronogramme : attente bloquante et traitement continu des tâches avec millis().

**Figure 5.8 — Avec millis(), le programme continue d'écouter entre deux affichages.**

### 5.13. Exercice : une valeur fictive toutes les 1 000 ms avec commandes

Dans le **programme d'entraînement** consacré à la liaison série, nous fixons :

~~~cpp
const unsigned long PERIODE_MS = 1000UL;
const float TENSION_SIMULEE_V = 230.5f;
~~~

La fonction `loop()` traite d'abord les commandes `'1'`, `'0'`, `'?'`, puis vérifie le temps écoulé. Si la période est atteinte, elle affiche :

~~~text
Tension SIMULEE : 230.5 V
~~~

Aucun capteur n'est connecté. La valeur 230,5 est **une constante du programme** ; ce n'est pas une tension mesurée.

En changeant uniquement `PERIODE_MS` de `1000UL` à `500UL`, nous obtenons **environ deux lignes par seconde**, tandis que les commandes demeurent disponibles entre les affichages.

Le fait de modifier la **période en millisecondes** ne demande pas de changer le débit de la communication série. Ce sont deux paramètres différents : les **bauds** règlent la transmission des caractères, les **millisecondes** règlent la fréquence des tâches.

### 5.14. Programme principal : bouton, LED, UART et tâches périodiques

Nous arrivons maintenant à l'évolution du **même compteur**. Pour ce chapitre, la LED ne clignote plus automatiquement comme au chapitre 4 : elle devient un indicateur **commandable par le bouton ou par le moniteur série**.

Nous conservons l'utilisation d'`Arduino IDE`, de `setup()`, de `loop()`, des variables, des conditions et des fonctions. Nous remplaçons les longues attentes par un traitement continu.

La version intégrée étudiée ici utilise **une période d'affichage de 2 000 ms**, et non les 1 000 ms de l'exercice précédent. Cette différence est volontaire et nous devons la lire dans les constantes.

~~~cpp
#include <Arduino.h>

const uint8_t PIN_BOUTON = 2;
const unsigned long REBOND_MS = 35UL;
const unsigned long AFFICHAGE_MS = 2000UL;
const float TENSION_FICTIVE = 230.5f;

bool ledAllumee = false;
int derniereLecture = HIGH;
int boutonStable = HIGH;
unsigned long dernierChangement = 0;
unsigned long dernierAffichage = 0;

void appliquerLED() {
  digitalWrite(LED_BUILTIN,
               ledAllumee ? HIGH : LOW);
}

void traiterBouton(unsigned long maintenant) {
  const int brut = digitalRead(PIN_BOUTON);

  if (brut != derniereLecture) {
    dernierChangement = maintenant;
  }

  if ((unsigned long)(maintenant - dernierChangement)
          >= REBOND_MS &&
      brut != boutonStable) {
    boutonStable = brut;

    if (boutonStable == LOW) {
      ledAllumee = !ledAllumee;
      appliquerLED();
      Serial.println(F("Bouton : bascule de la LED"));
    }
  }

  derniereLecture = brut;
}

void traiterCommandes() {
  while (Serial.available() > 0) {
    const char commande = (char)Serial.read();

    if (commande == '\r' || commande == '\n') {
      continue;
    }

    if (commande == '1') {
      ledAllumee = true;
    } else if (commande == '0') {
      ledAllumee = false;
    } else if (commande == '?') {
      Serial.println(F("Aide : 1=ON 0=OFF ?=aide"));
      continue;
    } else {
      Serial.println(F("Commande inconnue"));
      continue;
    }

    appliquerLED();
    Serial.println(ledAllumee ? F("LED ON")
                             : F("LED OFF"));
  }
}

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  appliquerLED();
  Serial.begin(9600);
  dernierAffichage = millis();

  Serial.println(
      F("FIL ROUGE M05 - TENSION SIMULEE - 9600 bauds"));
  Serial.println(F("Bouton D2-GND, commandes 1/0/?"));
}

void loop() {
  const unsigned long maintenant = millis();

  traiterBouton(maintenant);
  traiterCommandes();

  if ((unsigned long)(maintenant - dernierAffichage)
          >= AFFICHAGE_MS) {
    dernierAffichage = maintenant;

    Serial.print(F("Tension SIMULEE : "));
    Serial.print(TENSION_FICTIVE, 1);
    Serial.println(F(" V"));
  }
}
~~~

**Programme 5.4 — Programme intégré du compteur après le chapitre 5.**

Lisons ses trois tâches distinctes :

**Tâche 1 — Bouton :** `traiterBouton(maintenant)` lit D2, confirme la stabilité et change la LED lors d'un nouvel appui valide.

**Tâche 2 — Commandes :** `traiterCommandes()` lit uniquement les octets déjà reçus et réagit aux caractères `'1'`, `'0'` et `'?'`.

**Tâche 3 — Affichage :** toutes les **2 secondes environ**, le programme imprime une valeur constante **simulée**, identifiée comme telle.

Ces tâches ne s'exécutent pas réellement en parallèle sur plusieurs processeurs. Elles sont **traitées successivement et fréquemment**, ce qui rend l'application réactive tant que chacune reste suffisamment courte.

**Exemple d'affichage attendu :**

~~~text
FIL ROUGE M05 - TENSION SIMULEE - 9600 bauds
Bouton D2-GND, commandes 1/0/?
Tension SIMULEE : 230.5 V
Tension SIMULEE : 230.5 V
LED ON
Tension SIMULEE : 230.5 V
~~~

Le message `LED ON` n'apparaît que si une commande ou un événement le provoque. Son **placement exact** parmi les relevés dépend du moment où l'utilisateur agit.

**Précision sur notre progression :** le chapitre 4 avait introduit un calcul d'énergie théorique. Dans le programme intégré ci-dessus, l'affichage de ce calcul n'est **pas repris** : nous consacrons cette étape aux entrées/sorties et à la gestion des tâches. Les principes de calcul appris restent valables et serviront à la suite du projet. Nous ne devons pas prétendre que toutes les fonctions précédentes sont actives alors qu'elles ne figurent pas dans le code montré.

**Précision sur l'interface série :** `Serial` sert ici à l'exercice USB sur Uno. Lorsque le SIM800L utilisera l'UART matérielle, les messages de diagnostic USB, les commandes `1/0/?` et le modem ne pourront pas se partager librement D0/D1. La conception et le débogage devront être adaptés, sans raccorder directement des niveaux logiques incompatibles.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 5.9
Type : synoptique fonctionnel du programme évolutif.
Contenu et annotations : comparer chapitre 4 LED clignotante + calcul fictif série et chapitre 5 LED commandée par bouton ou UART, tâche périodique 2 s, anti-rebond 35 ms ; signaler explicitement que le calcul M04 n'est pas affiché dans ce code.
Légende finale : Figure 5.9 — Le compteur transforme sa LED en indicateur commandé et reste réactif.
Texte alternatif : Schéma d'évolution du programme : bouton D2 et commandes USB pilotent la LED tandis qu'une tâche déclenchée toutes les deux secondes affiche une tension fictive.
Contraintes : distinction 1 000 ms (exercice) / 2 000 ms (programme intégré), ne pas annoncer l'intégration du PZEM/GSM ou la conservation du calcul M04 absent.
Statut : À PRODUIRE.
-->
> **[ILLUSTRATION À INSÉRER — Figure 5.9]** Synoptique : bouton + commandes UART + tâches périodiques intégrés au compteur.

**Figure 5.9 — Le compteur transforme sa LED en indicateur commandé et reste réactif.**

---

## Partie C — Travaux pratiques

### 5.15. TP 1 — Un bouton pour changer de page

**Objectif :** préparer la logique de deux pages d'affichage, sans avoir besoin du vrai LCD.

**Matériel :** Uno Rev3, bouton D2–GND, câble USB et moniteur série à 9 600 bauds.

**Consignes :**

1. Débranchez l'USB et vérifiez les contacts du bouton avant de relier **D2** et **GND**.
2. Utilisez le programme anti-rebond de la section 5.6.
3. Déclarez `byte page = 0;` : la page 0 symbolise la tension, la page 1 symbolise l'énergie.
4. À chaque **appui stabilisé LOW**, faites alterner `page` de 0 à 1 ou de 1 à 0.
5. Affichez `Page : 0` ou `Page : 1` dans le moniteur série.
6. Utilisez la LED intégrée : **éteinte pour 0**, **allumée pour 1**.
7. Vérifiez que **cinq appuis distincts donnent cinq changements**, et qu'un appui maintenu n'en produit qu'un.

Ne remplacez pas l'anti-rebond par un `delay()` long. Le but est d'apprendre à reconnaître **un événement fiable**.

**Résultats attendus :** état initial page 0 puis pages 1, 0, 1, 0, 1 après cinq appuis successifs. Aucun LCD réel n'est requis pour cette simulation.

### 5.16. TP 2 — Afficher plus souvent sans perdre les commandes

**Objectif :** modifier une période de travail sans bloquer la réception UART.

**Matériel :** Arduino Uno Rev3 et ordinateur par USB, sans périphérique externe.

**Consignes :**

1. Écrivez le petit programme de la section 5.13 ou adaptez le programme intégré.
2. Dans la version d'exercice, partez de **1 000 ms**.
3. Remplacez la période par **500 ms**.
4. Envoyez successivement `'1'`, `'0'` et `'?'` depuis le moniteur série.
5. Vérifiez que la LED obéit aux commandes entre les relevés fictifs.
6. Assurez-vous qu'aucun `delay()` n'a été introduit dans la boucle principale.

**Attention :** si vous partez du programme intégré 5.4, la constante à modifier est **`AFFICHAGE_MS = 2000UL`** ; la passer à `500UL` donne aussi une période de 500 ms. Les deux programmes n'ont donc pas la même valeur de départ, mais le même objectif final.

**Résultat attendu :** deux lignes de tension fictive par seconde environ et une LED toujours commandable.

### 5.17. Défi facultatif — Identifier une attente bloquante

Que se passe-t-il si l'on ajoute `delay(5000)` au début de `loop()` ?

Expliquez pourquoi les commandes envoyées pendant cette attente ne sont pas traitées immédiatement, et pourquoi un tampon de réception peut finir par se remplir si les caractères arrivent continuellement.

### 5.18. Tableau de dépannage

| Symptôme | Cause possible | Première vérification |
|---|---|---|
| Le bouton semble toujours appuyé | Mauvaise paire de contacts sur un bouton à quatre pattes | Débrancher l'USB, identifier les contacts hors tension |
| La LED ne change que pendant l'appui | Programme à lecture de niveau, pas bascule | Vérifier `ancienEtatAppuye` ou le front stable |
| Plusieurs bascules par appui | Rebond mal filtré | Vérifier la fenêtre de 35 ms et le test de niveau stable |
| Commandes `1`/`0` sans effet | Mauvais port, mauvais sketch ou caractère non reconnu | Vérifier téléversement, port et commande envoyée |
| Caractères illisibles | Débit incompatible | Mettre le moniteur à 9 600 bauds |
| Lignes fictives espacées de 2 s | Utilisation du programme intégré avec `AFFICHAGE_MS=2000UL` | C'est le fonctionnement prévu de cette version |
| Lignes espacées d'environ 0,5 s | Période à 500 ms | Vérifier la constante sans modifier les bauds |
| Le programme répond lentement | `delay()` ou boucle d'attente inutile | Revenir au contrôle avec `millis()` |
| Le logiciel affiche 230,5 V | Constante fictive du code | Ne pas interpréter cette valeur comme mesure réelle |

### 5.19. Autoévaluation — Dix questions

Choisissez **une réponse** à chaque question. Les solutions détaillées sont dans **l'annexe E**.

**1. Que fait `pinMode(2, INPUT_PULLUP);` ?**  
A. Transforme D2 en sortie analogique — B. Active une entrée et sa résistance interne de rappel — C. Fait clignoter automatiquement la LED — D. Applique le secteur à D2

**2. Dans le montage D2–bouton–GND, quelle valeur indique l'appui ?**  
A. `LOW` — B. `HIGH` — C. `230.5` — D. `9600`

**3. Que fait la première version de lecture du bouton ?**  
A. Mesure le réseau — B. Bascule définitivement la LED après l'appui — C. Allume la LED uniquement tant que le bouton est pressé — D. Envoie un message GSM

**4. À quoi sert `Serial.begin(9600)` ?**  
A. Régler l'anti-rebond à 9 600 ms — B. Redémarrer la carte — C. Configurer D2 en sortie — D. Initialiser la liaison série à 9 600 bauds

**5. Pourquoi un bouton sans anti-rebond peut-il provoquer plusieurs bascules ?**  
A. La LED est raccordée au secteur — B. Le contact produit plusieurs transitions rapides — C. Le modem est nécessaire — D. D2 est forcément une sortie

**6. Quand la LED doit-elle basculer dans notre programme avec anti-rebond ?**  
A. Dès le premier LOW fugitif — B. À chaque tour de boucle pendant LOW — C. Lorsque le niveau confirmé après stabilisation devient LOW — D. À chaque appui et relâchement

**7. Comment lire correctement un caractère série sans attendre indéfiniment ?**  
A. Tester `Serial.available()>0` avant `Serial.read()` — B. Attendre dans une boucle vide tant qu'aucun caractère n'arrive — C. Faire `delay(5000)` avant toute lecture — D. Lire la LED avec `digitalRead(13)`

**8. Quel caractère éteint la LED dans notre exemple de commandes ?**  
A. `'1'` — B. `'?'` — C. `'L'` — D. `'0'`

**9. Quel est l'intérêt du test `maintenant - precedentMs >= 1000UL` avec des valeurs non signées adaptées ?**  
A. Attendre bloqué une seconde — B. Éliminer tout débordement de toute variable — C. Déclencher périodiquement une action sans attente bloquante et gérer le retour de `millis()` à zéro dans ce cadre — D. Convertir les bauds en énergie

**10. Comment recevoir des commandes entre deux relevés fictifs ?**  
A. Placer `delay(1000)` avant chaque lecture — B. Traiter les caractères disponibles à chaque passage de `loop()`, puis vérifier le temps avec `millis()` — C. Attendre indéfiniment une commande avant chaque relevé — D. Raccorder la broche RX au secteur

**Objectif : 8/10**, avec correction systématique de toute erreur de sécurité.

---

## Partie D — Synthèse et transition

### 5.20. Six notions indispensables

1. Une entrée configurée en **`INPUT_PULLUP`** et reliée par bouton à GND est **HIGH au repos** et **LOW à l'appui**.
2. Un **niveau maintenu** est différent d'un **événement d'appui**.
3. L'anti-rebond logiciel valide un **état stable**, ici après une fenêtre pédagogique de 35 ms.
4. L'UART permet d'échanger des **caractères**, mais il faut respecter les broches, les débits et les niveaux électriques compatibles.
5. `millis()` aide à déclencher des tâches à intervalles réguliers **sans interrompre inutilement le reste de la boucle**.
6. Notre programme évolue : sa LED devient commandable, il gère plusieurs tâches et affiche toujours **une donnée fictive**, pas une mesure électrique réelle.

### 5.21. Petit lexique

| Terme | Signification |
|---|---|
| **GPIO** | Broche d'entrée ou de sortie du microcontrôleur |
| **INPUT_PULLUP** | Entrée utilisant une résistance interne de rappel vers HIGH |
| **Front d'appui** | Transition permettant de reconnaître un nouvel appui |
| **Anti-rebond** | Méthode pour éviter de compter plusieurs fois un contact instable |
| **UART** | Interface de communication série asynchrone |
| **TX / RX** | Émission / réception de données |
| **Baud** | Unité de rapidité de symboles d'une communication série |
| **millis()** | Temps écoulé depuis le démarrage, en millisecondes, sur Arduino |
| **Temporisation non bloquante** | Vérification du temps sans attente fixe qui immobilise la boucle |
| **Événement** | Situation détectée qui déclenche un traitement |
| **Simulation** | Valeurs ou comportements pédagogiques non issus d'une mesure réelle |

### 5.22. Vers le chapitre 6 : mesurer au lieu de simuler

Notre moniteur série affiche pour le moment **230,5 V fictifs** parce que nous avons inscrit ce nombre dans le programme. Nous savons néanmoins organiser plusieurs fonctions autour de cette valeur sans attendre inutilement.

Au **chapitre 6**, nous découvrirons comment le **PZEM-004T V3.0** fournit des grandeurs électriques et comment le microcontrôleur peut les exploiter **dans un cadre de sécurité approprié**, en séparant les exercices basse tension de toute intervention secteur réservée à un professionnel qualifié.

Nous conserverons le principe du même compteur enrichi étape après étape, en vérifiant systématiquement ce que le programme intègre réellement.
