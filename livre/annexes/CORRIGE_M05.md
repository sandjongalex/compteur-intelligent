# Annexe E — Corrigés des exercices du chapitre 5

> **À consulter après avoir effectué les exercices.** Les montages utilisent seulement une Arduino Uno Rev3 alimentée de façon adaptée par USB. Débrancher l'USB avant de modifier un fil. Toutes les valeurs de tension sont **simulées**.

## E1. TP 1 — Changer de page avec un bouton

### Rappel du comportement recherché

Le compteur simulera deux pages :

- **Page 0** : la page de tension ; LED intégrée éteinte.
- **Page 1** : la page d'énergie ; LED intégrée allumée.

Chaque nouvel appui **validé après anti-rebond** doit effectuer la transition \`0 → 1\` ou \`1 → 0\`. Le relâchement seul ne change rien. Une pression maintenue ne doit pas provoquer une succession de changements.

### Programme corrigé

~~~cpp
const byte BROCHE_BOUTON = 2;
const unsigned long ANTIREBOND_MS = 35UL;

int brutPrecedent = HIGH;
int stable = HIGH;
unsigned long changementMs = 0;
byte page = 0;

void setup() {
  pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Page initiale : 0");
}

void loop() {
  const unsigned long maintenant = millis();
  const int brut = digitalRead(BROCHE_BOUTON);

  if (brut != brutPrecedent) {
    changementMs = maintenant;
  }

  if ((unsigned long)(maintenant - changementMs)
          >= ANTIREBOND_MS &&
      brut != stable) {
    stable = brut;

    if (stable == LOW) {
      page = (byte)(1 - page);
      digitalWrite(LED_BUILTIN, page ? HIGH : LOW);
      Serial.print("Page : ");
      Serial.println(page);
    }
  }

  brutPrecedent = brut;
}
~~~

**Ce qui produit un seul événement :** le changement de \`page\` est situé **à l'intérieur** du test \`stable == LOW\`, déclenché après confirmation du nouvel état stable. Une fois le niveau LOW enregistré, maintenir le bouton ne crée pas un nouvel événement, puisque \`brut != stable\` devient faux.

**Exemple de sortie attendue** après cinq appuis distincts :

~~~text
Page initiale : 0
Page : 1
Page : 0
Page : 1
Page : 0
Page : 1
~~~

Cette sortie est **un exemple attendu**, et non le compte rendu d'un test physique réalisé pour le livre.

### Pièges à éviter

- Choisir les mauvaises pattes d'un bouton à quatre contacts peut provoquer des lectures permanentes ou inattendues. Les vérifier **hors tension**.
- Faire évoluer \`page\` à chaque tour de \`loop()\` lorsque D2 est LOW ferait changer la page de façon répétée tant que l'appui dure.
- Changer la page dès la première variation brute peut compter plusieurs rebonds comme plusieurs appuis.
- **35 ms** est un paramètre pédagogique ; les conditions réelles du contact peuvent imposer d'autres vérifications.

**Barème indicatif /10 :** bouton correctement raccordé en basse tension (2), traitement anti-rebond et événement unique (3), alternance 0/1 (2), sortie série correcte (2), explication de la logique (1).

## E2. TP 2 — Produire un relevé fictif toutes les 500 ms

### Version de départ : exercice série

La leçon série présente une période d'affichage de **1 000 ms** :

~~~cpp
const unsigned long PERIODE_MS = 1000UL;
~~~

Pour demander environ deux lignes par seconde, la modification centrale est :

~~~cpp
const unsigned long PERIODE_MS = 500UL;
~~~

Les commandes série restent traitées à chaque passage de \`loop()\`. La tâche périodique est lancée seulement si la période est atteinte :

~~~cpp
void loop() {
  traiterCommandes();

  const unsigned long maintenant = millis();

  if ((unsigned long)(maintenant - dernierEnvoiMs)
          >= PERIODE_MS) {
    dernierEnvoiMs = maintenant;

    Serial.print("Tension SIMULEE : ");
    Serial.print(TENSION_SIMULEE_V, 1);
    Serial.println(" V");
  }
}
~~~

Ce bloc suppose que la constante \`TENSION_SIMULEE_V = 230.5f\`, la variable \`dernierEnvoiMs\`, la fonction \`traiterCommandes()\` et \`Serial.begin(9600)\` ont été définies dans le sketch, comme expliqué dans le chapitre.

**Dans le programme principal 5.4**, la valeur de départ est différente :

~~~cpp
const unsigned long AFFICHAGE_MS = 2000UL;
~~~

Pour le même défi, remplacer cette ligne par :

~~~cpp
const unsigned long AFFICHAGE_MS = 500UL;
~~~

**Il ne faut pas confondre ces deux constantes** ni conclure que le programme principal affichait déjà une fois par seconde.

### Résultat attendu

Un exemple de sortie possible, avec des commandes saisies entre les affichages :

~~~text
Tension SIMULEE : 230.5 V
Tension SIMULEE : 230.5 V
LED ON
Tension SIMULEE : 230.5 V
LED OFF
Tension SIMULEE : 230.5 V
~~~

La position exacte de \`LED ON\` et \`LED OFF\` dépend du moment où l'apprenant envoie les commandes. L'absence d'une commande \`'1'\` ou \`'0'\` signifie qu'aucun de ces messages n'est attendu spontanément.

### Pourquoi utiliser millis() ?

Avec \`millis()\`, nous examinons régulièrement si 500 ms se sont écoulées depuis la dernière émission. Entre deux échéances, la boucle peut traiter les caractères déjà reçus.

Avec \`delay(500)\`, l'exécution normale du sketch est suspendue pendant environ une demi-seconde et la prise en compte des nouvelles commandes peut être retardée.

**Barème indicatif /10 :** sélection correcte de la carte et du moniteur série (2), période ramenée à 500 ms (3), commandes \`1/0/?\` toujours utilisables (3), explication du calcul non bloquant (2).

## E3. Défi facultatif — Que se passe-t-il avec delay(5000) ?

L'instruction \`delay(5000)\` bloque l'avancement ordinaire de \`loop()\` pendant environ **5 secondes**.

Des caractères peuvent arriver par l'interface matérielle pendant cette période grâce aux mécanismes de réception, mais le programme ne les **traite pas immédiatement**. Si beaucoup de données arrivent, le tampon de réception peut finir par être saturé.

La solution n'est pas de multiplier les boucles d'attente : il faut organiser les tâches avec des conditions et les durées mesurées par \`millis()\`, tout en gardant les traitements assez courts.

## E4. Quiz — Dix bonnes réponses argumentées

| Question | Réponse | Justification |
|---|---|---|
| 1 | **B** | \`INPUT_PULLUP\` configure une entrée et sa résistance interne de rappel. |
| 2 | **A** | Dans le montage D2–bouton–GND, l'appui produit le niveau LOW. |
| 3 | **C** | Le programme initial allume la LED seulement pendant l'appui maintenu. |
| 4 | **D** | \`Serial.begin(9600)\` initialise l'UART à 9 600 bauds. |
| 5 | **B** | Le rebond mécanique produit plusieurs transitions rapides. |
| 6 | **C** | La bascule survient lorsque l'état stable confirmé devient LOW. |
| 7 | **A** | \`Serial.available()>0\` permet de lire un octet seulement lorsqu'il est disponible. |
| 8 | **D** | Le caractère \`'0'\` éteint la LED ; \`'1'\` l'allume. |
| 9 | **C** | La soustraction de temps non signés permet un déclenchement périodique sans pause et gère le retour de \`millis()\` à zéro dans ce cadre. |
| 10 | **B** | Les commandes sont traitées dans chaque \`loop()\` avant la vérification du temps avec \`millis()\`. |

**Seuil de validation : 8/10.** Toute erreur relative aux dangers du secteur ou aux connexions série doit être corrigée avant les manipulations suivantes.

## E5. Deux précisions importantes pour continuer le compteur

### La LED change de rôle

Dans le chapitre 4, la LED clignotait automatiquement. Dans le chapitre 5, elle devient **commandable** : un nouvel appui ou un message série détermine son état.

La disparition du clignotement automatique est donc **une décision fonctionnelle expliquée**, pas l'oubli d'une fonctionnalité.

### Le calcul énergétique du chapitre 4

La version intégrée étudiée au chapitre 5 n'affiche plus la fonction de calcul énergétique fictif du chapitre 4. Cette fonction reste une **connaissance acquise**, mais elle n'est pas exécutée par ce code tel qu'il est présenté.

La suite de la formation devra réintroduire et vérifier le calcul énergétique dans les étapes où les relevés réels et les cumuls journaliers et mensuels seront développés. Il serait incorrect de dire que le programme 5.4 calcule actuellement des kWh.

### Le port série matériel

Pendant ce chapitre, \`Serial\` utilise l'interface USB de l'Arduino Uno et l'UART matérielle de l'ATmega328P. Dans la configuration finale du compteur, cette UART est réservée au **SIM800L**. Un modem réel ne doit jamais être raccordé en parallèle de l'interface USB de test sans conception, isolation et adaptation adaptées.

## E6. Auto-contrôle des acquis

Avant le chapitre 6, vous devez savoir expliquer de mémoire :

- pourquoi LOW signifie « appuyé » dans **ce** montage ;
- pourquoi le rebond empêche un changement fiable au premier front brut ;
- la différence entre \`Serial.available()\` et \`Serial.read()\` ;
- les rôles de \`'1'\`, \`'0'\` et \`'?'\` ;
- la différence entre \`delay()\` et une tâche planifiée avec \`millis()\` ;
- pourquoi le programme intégré affiche toutes les **2 secondes** alors que l'exercice série affiche toutes les **1 seconde** ;
- pourquoi une valeur **230,5 V simulée** n'est jamais une mesure du secteur.
