# Chapitre 3 — Installer Arduino IDE et programmer sa première LED

> **Niveau :** débutant. Avoir lu les chapitres 1 et 2 est recommandé.  
> **Matériel essentiel :** ordinateur, Arduino Uno Rev3 et câble USB de données adapté.  
> **Matériel facultatif pour la deuxième expérience :** une LED standard, une résistance de 330 Ω, une petite breadboard et quelques fils de connexion.  
> **Sécurité :** tous les essais utilisent uniquement la basse tension d'une carte Arduino alimentée de manière adaptée par USB. **Aucune manipulation du secteur 230 V, du PZEM ou du SIM800L n'est nécessaire.**

Nous avons appris à reconnaître les composants du compteur intelligent et à respecter leurs contraintes électriques. Il est temps de faire exécuter des instructions à notre microcontrôleur.

Le premier objectif peut paraître modeste : allumer et éteindre une LED. Pourtant, cette expérience permettra de découvrir les étapes essentielles de la programmation embarquée. Nous apprendrons à écrire un programme, à comprendre les messages du logiciel, à l'envoyer sur la carte et à observer une action matérielle.

**Ce clignotement est aussi la première fonction du compteur que nous construirons progressivement.** Nous ne commencerons pas un nouveau système indépendant à chaque chapitre : la LED deviendra plus tard un indicateur d'état de notre appareil, tandis que son logiciel gagnera de nouvelles fonctions.

## Ce que vous saurez faire à la fin du chapitre

Vous serez capable de :

1. installer et ouvrir Arduino IDE sur un ordinateur compatible ;
2. reconnaître les zones principales de l'éditeur et sélectionner une Arduino Uno Rev3 ;
3. distinguer **vérification/compilation** et **téléversement** ;
4. comprendre les fonctions **setup()** et **loop()** ;
5. programmer la LED intégrée de la carte avec **pinMode()**, **digitalWrite()** et **delay()** ;
6. adapter le temps d'allumage et d'extinction ;
7. réaliser, si vous disposez du matériel adapté, un montage simple avec LED externe et résistance ;
8. diagnostiquer une erreur de syntaxe ou un problème courant de communication USB.

---

## Partie A — Installer Arduino IDE et comprendre la compilation

### 3.1. Quelle différence entre Arduino, ATmega328P et Arduino IDE ?

Ces trois noms ne désignent pas la même chose.

L'**ATmega328P** est un microcontrôleur : c'est la puce qui exécutera le programme de notre compteur. La **carte Arduino Uno Rev3** regroupe un microcontrôleur, des circuits d'alimentation et de communication, des connecteurs et des éléments pratiques pour l'apprentissage.

**Arduino IDE** est le logiciel que nous utilisons sur l'ordinateur pour écrire le code et préparer son transfert vers la carte. Le sigle **IDE** signifie *Integrated Development Environment*, ou « environnement de développement intégré ».

On peut résumer leurs rôles dans un tableau :

| Élément | Rôle |
|---|---|
| Ordinateur | Permet de rédiger et d'enregistrer le programme |
| Arduino IDE | Édite, vérifie, compile et téléverse le programme |
| Arduino Uno Rev3 | Facilite le développement et les premiers essais |
| ATmega328P | Exécute les instructions à bord du système |
| LED intégrée | Rend visible le résultat de notre premier programme |

Le programme écrit pour Arduino est souvent appelé un **sketch**. Son fichier possède normalement l'extension **.ino**. Nous allons comprendre l'essentiel de cette structure, sans exiger de connaissances préalables en C++.

### 3.2. Télécharger Arduino IDE

Pour cet apprentissage, nous utilisons **Arduino IDE 2**, disponible sur le **site officiel Arduino**, dans la rubrique **Software**. Les étapes exactes d'installation peuvent évoluer avec les versions du logiciel et les systèmes d'exploitation.

Procédure générale :

1. Sur votre ordinateur, ouvrez un navigateur et accédez à la rubrique *Software* du site officiel Arduino.
2. Choisissez une version d'**Arduino IDE 2** compatible avec votre système d'exploitation : Windows, macOS ou Linux, selon les versions proposées.
3. Téléchargez le programme depuis l'éditeur officiel, en évitant les installateurs provenant de sources inconnues.
4. Lancez l'installation en suivant les indications prévues pour votre système.
5. Ouvrez Arduino IDE et vérifiez que la fenêtre de programmation s'affiche.

Une fois le logiciel installé, **l'écriture et la lecture des exemples de ce chapitre peuvent être pratiquées sans connexion Internet permanente**. Certaines installations initiales de plateformes, de cartes ou de composants logiciels peuvent néanmoins nécessiter des téléchargements.

Si vous utilisez un ordinateur partagé, respectez les autorisations d'installation en vigueur. Une erreur de téléchargement ou un logiciel incompatible n'est pas une erreur de programmation : il faut d'abord résoudre la configuration de l'ordinateur.

### 3.3. Reconnaître les principaux outils d'Arduino IDE

L'interface d'Arduino IDE comporte plusieurs zones utiles :

| Zone | Fonction |
|---|---|
| Éditeur de code | Écrire et modifier les instructions du sketch |
| **Vérifier** (symbole de coche) | Contrôler et compiler le programme |
| **Téléverser** (symbole de flèche) | Compiler puis envoyer le programme vers la carte |
| Sélecteur de carte | Indiquer le modèle sur lequel le programme doit fonctionner |
| Sélecteur de port | Choisir la connexion utilisée pour dialoguer avec la carte |
| Zone de messages | Afficher les informations et les erreurs de compilation ou de téléversement |

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.1
Type : capture d'écran réelle annotée.
Contenu et annotations : Montrer IDE 2 avec zone de code, Vérifier, Téléverser, carte, port, console ; annotations en français.
Légende finale : Figure 3.1 — Les outils essentiels de l'interface Arduino IDE 2.
Texte alternatif : L'éditeur Arduino IDE 2 avec ses outils et la zone de messages.
Contraintes : Capturer un logiciel réel et version vérifiée ; masquer les informations privées, droits à documenter.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.1 — Les outils essentiels de l'interface Arduino IDE 2.**

La position précise des boutons peut changer suivant la version d'Arduino IDE. Retenez d'abord **leur fonction**, qui importe davantage que leur emplacement exact.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.2
Type : infographie de processus.
Contenu et annotations : Vectoriser l'organigramme écrit ci-dessous : code → compilation, retour en cas d'erreur, téléversement puis LED observée.
Légende finale : Figure 3.2 — Du code écrit au résultat visible sur Arduino Uno.
Texte alternatif : Programme compilé, erreur éventuelle corrigée, transfert sur la carte et observation de la LED.
Contraintes : Une compilation ne prouve pas un fonctionnement matériel ; schéma vectoriel.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.2 — Parcours d'un programme Arduino**

~~~text
  Programme écrit dans Arduino IDE
                 |
                 v
       [Vérifier / Compiler]
                 |
        erreurs ? -------- oui ------> Corriger le code
                 |
                non
                 |
                 v
       [Téléverser vers Uno]
                 |
                 v
       Programme sur ATmega
                 |
                 v
      Résultat observable (LED)
~~~

Ce synoptique simplifié distingue deux opérations souvent confondues : **produire un programme compilé** et **le transférer sur une carte réelle**.

### 3.4. Relier correctement l'Arduino Uno à l'ordinateur

Nous utiliserons une **Arduino Uno Rev3** et un **câble USB de données** adapté au connecteur de votre carte.

Attention : certains câbles USB sont conçus principalement pour la recharge et ne permettent pas l'échange de données. Une carte qui s'allume lorsqu'on la branche ne prouve donc pas nécessairement que l'ordinateur peut lui téléverser un programme.

Pour commencer :

1. Placez la carte sur une surface sèche et non conductrice.
2. Assurez-vous qu'aucun fil externe ni module de mesure secteur n'est raccordé.
3. Reliez la carte à l'ordinateur avec le câble USB de données.
4. Dans Arduino IDE, sélectionnez **Arduino Uno** comme modèle de carte.
5. Choisissez le port associé à l'Arduino.

Sous Windows, ce port porte souvent un nom comme **COM3** ou **COM5**. Sous Linux et macOS, les noms peuvent différer. Ces exemples sont des illustrations ; le numéro ou le chemin réel dépend de votre ordinateur.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.3
Type : photo Uno + capture réelle.
Contenu et annotations : Uno Rev3 connectée par câble USB de données ; sélecteur Arduino Uno et port réellement détecté dans l'IDE 2.
Légende finale : Figure 3.3 — Connexion USB et sélection correcte de la carte et de son port.
Texte alternatif : Uno raccordée au port USB de l'ordinateur et Arduino IDE montrant carte et port choisis.
Contraintes : Aucun câble secteur ni module PZEM ; capture réelle et données personnelles floutées.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.3 — Connexion USB et sélection correcte de la carte et de son port.**

Si plusieurs ports apparaissent, vous pouvez observer la liste **avant** puis **après** avoir connecté la carte. Le nouveau port affiché peut aider à identifier le bon périphérique. Selon votre matériel et votre système, des pilotes ou des autorisations peuvent également être nécessaires.

**À retenir :** choisir correctement la carte et son port est indispensable pour le téléversement, mais un problème de port n'explique pas nécessairement une erreur de syntaxe du code.

### 3.5. Écrire le premier sketch : deux fonctions essentielles

Créons un nouveau sketch et recopions ce programme minimal :

~~~cpp
void setup() {
}

void loop() {
}
~~~

Il ne commande aucun composant. Et c'est volontaire.

Regardons les lignes une par une.

**Ligne 1 — \`void setup() {\`**

Le mot \`void\` indique ici que la fonction ne renvoie pas de valeur. Le nom \`setup\` est réservé, dans la structure habituelle des sketches Arduino, à l'initialisation du programme. Les parenthèses \`()\` font partie de la déclaration de fonction ; l'accolade ouvrante \`{\` annonce le début de son contenu.

**Ligne 2 — \`}\`**

Cette accolade ferme la fonction \`setup()\`. Pour le moment, il n'y a aucune instruction à exécuter au démarrage.

**Ligne 4 — \`void loop() {\`**

La fonction \`loop()\` est appelée de manière répétée après \`setup()\`. Elle accueillera plus tard les instructions de notre programme principal.

**Ligne 5 — \`}\`**

La deuxième accolade ferme la fonction \`loop()\`. Nous avons donc un programme structurellement valide qui ne produit **aucune action visible**.

La figure suivante aide à comprendre la chronologie :

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.4
Type : organigramme pédagogique.
Contenu et annotations : Tracer démarrage → setup() une fois → loop() répétée, avec flèche de retour ; partir du schéma textuel suivant.
Légende finale : Figure 3.4 — La fonction setup() précède la répétition de loop().
Texte alternatif : L'Arduino commence par setup une fois, puis répète loop.
Contraintes : Schéma simple sans suggestion que les fonctions sont parallèles.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->
~~~text
       Mise sous tension ou RESET
                  |
                  v
              setup()
           (initialisation)
                  |
                  v
              loop() <----+
                  |       |
                  +-------+
             se répète
~~~

**Figure 3.4 — Organisation des deux fonctions principales d'un sketch.**

Pour notre apprentissage, retenez : **\`setup()\` sert à préparer le fonctionnement ; \`loop()\` exécute la partie répétitive.**

### 3.6. Vérifier un programme : que signifie « compiler » ?

Lorsque nous cliquons sur **Vérifier**, Arduino IDE tente d'analyser et de compiler le programme pour la carte sélectionnée.

**Compiler**, c'est notamment transformer les instructions écrites dans un langage lisible par le programmeur en code exécutable par le microcontrôleur ciblé. Avant d'obtenir ce résultat, des contrôles permettent de détecter des erreurs comme les fautes de syntaxe ou l'utilisation de certaines fonctions inconnues.

Un message de compilation réussie signifie que cette étape logicielle a abouti dans l'environnement utilisé. **Cela ne prouve pas** que le programme fonctionne correctement sur un montage réel.

Une fois le sketch minimal ouvert :

1. sélectionnez **Arduino Uno** ;
2. cliquez sur **Vérifier** ;
3. examinez les messages affichés dans l'interface ;
4. notez si le programme est accepté ou s'il nécessite une correction.

L'éditeur peut également indiquer la quantité de mémoire utilisée par le programme. Nous reviendrons sur les contraintes de mémoire des microcontrôleurs lorsque les programmes deviendront plus complets.

### 3.7. Téléverser : transférer le programme sur la carte

**Téléverser** est une opération différente : l'IDE prépare le programme puis le transmet vers la carte sélectionnée, en utilisant la connexion appropriée.

Pour notre Arduino Uno Rev3 :

1. connectez la carte par USB ;
2. confirmez le modèle de carte ;
3. choisissez le port correct ;
4. cliquez sur **Téléverser** ;
5. attendez le message de fin ou de réussite de l'opération.

Lorsque le sketch minimal a bien été téléversé, **il est normal que la LED ne clignote pas** : nous n'avons encore écrit aucune instruction pour la commander. Il est également normal que le téléversement modifie le comportement d'un ancien programme stocké sur la carte.

| Observation | Signification |
|---|---|
| Vérifier réussit | Le programme a été compilé pour la cible sélectionnée |
| Téléverser réussit | Le transfert du programme vers la carte a abouti |
| Sketch minimal sans action visible | Comportement normal : aucune instruction de commande n'a été écrite |
| Vérifier échoue | Le code ou sa configuration doit être examiné |
| Vérifier réussit mais Téléverser échoue | Il faut examiner la connexion, la carte et le port |

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.5
Type : deux captures réelles de messages.
Contenu et annotations : Comparer une compilation réussie et un téléversement réussi du même programme, avec messages réellement obtenus.
Légende finale : Figure 3.5 — Vérifier n'est pas téléverser : deux messages différents.
Texte alternatif : Deux écrans montrent une compilation valide et le transfert réel à une Uno Rev3.
Contraintes : Ne pas simuler un succès matériel et le qualifier de réel ; version IDE vérifiée.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.5 — Vérifier n'est pas téléverser : deux messages différents.**

### 3.8. Première erreur volontaire : une accolade manquante

Les erreurs font partie de l'apprentissage, à condition de les provoquer sans risque matériel.

Prenez **une copie** du sketch minimal et retirez volontairement la dernière accolade :

~~~cpp
void setup() {
}

void loop() {
  // Il manque ici l'accolade de fermeture.
~~~

Cliquez sur **Vérifier**. Cette copie est **volontairement incorrecte** : le compilateur doit signaler un problème de syntaxe. Le texte exact du message peut varier selon la version du compilateur.

Remettez l'accolade :

~~~cpp
void setup() {
}

void loop() {
  // Le corps de loop est maintenant correctement fermé.
}
~~~

Relancez **Vérifier**. Le programme est redevenu structurellement valide.

**Méthode de diagnostic :** repérez le premier message d'erreur utile, examinez les lignes proches de l'endroit indiqué, cherchez les parenthèses ou accolades manquantes, corrigez, puis vérifiez à nouveau.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.6
Type : capture contrôlée d'erreur.
Contenu et annotations : Montrer le sketch avec accolade manquante et le message réel du compilateur, puis la correction de l'accolade.
Légende finale : Figure 3.6 — Corriger une accolade manquante dans Arduino IDE.
Texte alternatif : Comparaison du sketch incomplet et du résultat de sa compilation, puis version corrigée.
Contraintes : Message issu d'une vraie compilation, non inventé ; protéger données personnelles.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.6 — Corriger une accolade manquante dans Arduino IDE.**

N'accusez pas immédiatement le microcontrôleur : un problème de syntaxe peut empêcher la compilation avant même qu'un programme ne soit envoyé à la carte.

---

## Partie B — Faire clignoter une LED avec Arduino Uno

### 3.9. Pourquoi commencer par une LED ?

Une **LED** (*Light-Emitting Diode*, ou diode électroluminescente) produit de la lumière lorsqu'elle est parcourue par un courant approprié dans le sens prévu.

Elle constitue un excellent premier indicateur pour trois raisons :

1. son état est **visible** ;
2. son fonctionnement est simple à décrire : allumée ou éteinte ;
3. elle nous permet de vérifier une commande numérique sans utiliser le PZEM, le GSM ou le secteur.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.7
Type : photographie annotée de la Uno.
Contenu et annotations : Photographier la carte Uno Rev3 et repérer la LED L et la broche D13, sans composant externe.
Légende finale : Figure 3.7 — Repérer la LED intégrée L sur l'Arduino Uno Rev3.
Texte alternatif : Vue de la carte Uno avec voyant L et broche numérique D13 mis en évidence.
Contraintes : Photo d'une vraie carte autorisée, sécurité USB.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.7 — Repérer la LED intégrée L sur l'Arduino Uno Rev3.**

Notre Arduino Uno Rev3 possède déjà une petite LED intégrée, souvent repérée par la lettre **L**. Dans cette configuration, elle est associée à la broche numérique **D13**.

Le nom \`LED_BUILTIN\` permet d'indiquer cette LED de manière lisible dans les programmes Arduino. Pour commencer, nous allons utiliser la LED intégrée : **aucun fil ni composant externe n'est nécessaire**.

### 3.10. Comprendre les états numériques HIGH et LOW

Les sorties numériques de l'ATmega328P peuvent être commandées avec des états logiques.

- **HIGH** : demande de placer la sortie à son état logique haut ;
- **LOW** : demande de placer la sortie à son état logique bas.

Dans le circuit de la LED intégrée à la Uno Rev3 utilisé ici, passer la sortie à \`HIGH\` l'allume et revenir à \`LOW\` l'éteint.

**Important :** une sortie d'un microcontrôleur n'est pas une source d'alimentation universelle. Elle possède des limites de tension et de courant. On ne lui connecte pas arbitrairement un appareil de forte puissance. Pour notre exercice, nous utilisons uniquement la LED intégrée de la carte.

### 3.11. Configurer une sortie avec pinMode()

La première instruction utile de notre programme est :

~~~cpp
pinMode(LED_BUILTIN, OUTPUT);
~~~

Elle signifie : « Configure la broche associée à la LED intégrée en **sortie**. »

Cette opération se place dans \`setup()\`, car nous voulons préparer la broche au démarrage :

~~~cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
}
~~~

Le point-virgule \`;\` termine l'instruction. Son oubli est une cause fréquente d'erreur de compilation.

Une fois cette instruction ajoutée, la broche est configurée, mais nous n'avons pas encore décrit la séquence de clignotement.

### 3.12. Allumer la LED avec digitalWrite()

Nous allons maintenant compléter \`loop()\` :

~~~cpp
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
}
~~~

La fonction \`digitalWrite()\` définit l'état logique de la sortie. Son premier argument précise la broche ; son second indique l'état demandé.

Dans notre configuration, ce code demande **l'allumage** de la LED intégrée. Cependant, il ne crée pas encore de clignotement : il n'y a aucune instruction pour éteindre la LED après un intervalle.

Nous venons d'introduire un principe essentiel de la programmation : **une instruction doit exprimer le comportement souhaité**. Si nous voulons un changement d'état, il faut le programmer.

### 3.13. Faire une pause avec delay()

La fonction \`delay()\` permet de demander une attente exprimée en **millisecondes**.

- \`delay(1000);\` représente une attente d'environ **1 seconde** ;
- \`delay(500);\` représente une attente d'environ **0,5 seconde** ;
- \`delay(250);\` représente une attente d'environ **0,25 seconde**.

Ajoutons cette attente après l'allumage :

~~~cpp
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
~~~

L'ATmega328P allume alors la LED, attend environ une seconde, puis recommence la boucle et redemande de l'allumer. Ce code ne fait toujours pas clignoter la LED : il lui manque l'instruction d'extinction.

### 3.14. Premier programme de clignotement complet

Ajoutons les deux dernières instructions :

~~~cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Allumer la LED
  delay(1000);                      // Attendre 1 seconde
  digitalWrite(LED_BUILTIN, LOW);   // Éteindre la LED
  delay(1000);                      // Attendre 1 seconde
}
~~~

**Programme 3.1 — Première fonction du compteur intelligent : le clignotement de sa LED de diagnostic.**

Ce code est volontairement court : nous allons le lire de haut en bas.

| Instruction | Explication |
|---|---|
| \`pinMode(LED_BUILTIN, OUTPUT);\` | Préparer la broche comme sortie |
| \`digitalWrite(LED_BUILTIN, HIGH);\` | Activer la LED |
| \`delay(1000);\` | Attendre environ 1 seconde |
| \`digitalWrite(LED_BUILTIN, LOW);\` | Désactiver la LED |
| \`delay(1000);\` | Attendre environ 1 seconde avant la répétition |

À la fin de la deuxième attente, la fonction \`loop()\` est appelée à nouveau. Le programme recommence la même séquence.

**Résultat attendu après compilation, téléversement et fonctionnement correct sur une Uno Rev3 :** la LED intégrée reste allumée environ une seconde, éteinte environ une seconde, puis recommence.

Il s'agit d'un **résultat attendu à vérifier sur votre propre carte** ; le texte de ce livre ne constitue pas un compte rendu d'essai physique.

### 3.15. Modifier la cadence de clignotement

Nous allons demander un comportement différent :

- LED **allumée pendant 250 millisecondes** ;
- LED **éteinte pendant 750 millisecondes**.

La modification ne concerne que deux nombres :

~~~cpp
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(750);
}
~~~

La durée d'un cycle est maintenant :

**250 ms + 750 ms = 1 000 ms**, soit **1 seconde**.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.8
Type : chronogramme.
Contenu et annotations : Représenter HIGH 250 ms, LOW 750 ms, une période 1 000 ms, répétition de l'état.
Légende finale : Figure 3.8 — Chronogramme de la LED : 250 ms allumée et 750 ms éteinte.
Texte alternatif : L'état LED est haut pendant 250 ms puis bas pendant 750 ms pour une période de 1 seconde.
Contraintes : Respecter les proportions de temps et les unités ; ne pas affirmer une mesure physique.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.8 — Chronogramme de la LED : 250 ms allumée et 750 ms éteinte.**

Le rythme attendu est donc **une impulsion lumineuse courte suivie d'une extinction plus longue**. Le programme recommence ensuite.

Remarquez ce que nous venons d'apprendre : **la structure du programme reste la même, seuls les paramètres changent**. Nous pouvons faire évoluer une fonction sans reconstruire tout le projet.

**Mini-défi :** sans consulter les corrigés, trouvez les deux valeurs à utiliser pour obtenir **500 ms allumée et 1 500 ms éteinte**.

### 3.16. Monter une LED externe sur D8, sans danger

L'exercice avec LED intégrée suffit à apprendre les instructions. Nous pouvons cependant aller plus loin avec une **LED externe**, afin de comprendre le rôle d'une résistance et la différence entre une sortie sur la carte et un composant extérieur.

Pour cette partie, vous avez besoin :

- d'une Arduino Uno Rev3 ;
- d'une LED standard ;
- d'une **résistance de 330 Ω** en série avec la LED, valeur pédagogique courante pour une LED visible standard sur une Uno 5 V ;
- de fils et d'une breadboard **réservée à la basse tension** ;
- d'un câble USB de données et d'un ordinateur.

**Débranchez toujours l'USB avant de modifier les fils.** N'utilisez ni le PZEM, ni une alimentation ouverte, ni aucun raccordement au secteur.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.9
Type : schéma électrique pédagogique basse tension.
Contenu et annotations : Vectoriser le schéma texte : D8 → 330 Ω → anode LED → cathode → GND, repères des pôles et résistance.
Légende finale : Figure 3.9 — Principe du circuit basse tension de la LED externe.
Texte alternatif : D8 relié en série à une résistance de 330 ohms et une diode LED vers la masse GND.
Contraintes : Aucun 230 V, polarité correcte, résistance obligatoire, vérifier la carte utilisée.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.9 — Principe du circuit basse tension de la LED externe**

~~~text
        Arduino Uno Rev3
           (D8)
             |
          [330 Ω]
             |
         Anode LED (+)
             |
            LED
             |
       Cathode LED (-)
             |
           (GND)
~~~

La résistance et la LED sont **en série** : le courant doit traverser la résistance avant de passer par la LED. La résistance sert à **limiter ce courant** et à contribuer à protéger la diode ainsi que la sortie du microcontrôleur.

Une LED possède une **anode** et une **cathode**. Sur beaucoup de modèles, la patte la plus longue correspond à l'anode, mais ce repère n'est pas universel après découpe des pattes : reportez-vous aussi au marquage et à la documentation du composant.

**À ne pas faire :** raccorder une LED standard directement entre D8 et GND sans résistance de limitation de courant.

Avant de rebrancher l'USB, vérifiez hors tension le chemin complet :

**D8 → résistance de 330 Ω → anode de LED → cathode de LED → GND.**

<!-- ILLUSTRATION À PRODUIRE — FIGURE 3.10
Type : photographie du montage validé.
Contenu et annotations : Vraie photo Uno Rev3, breadboard, LED externe et résistance 330 Ω ; légender D8, anode, cathode, GND ; faire la photo USB débranché.
Légende finale : Figure 3.10 — Montage pédagogique de la LED externe, contrôlé hors tension.
Texte alternatif : Une Uno relie D8 à la LED externe au moyen d'une résistance sur breadboard, vers GND.
Contraintes : Ne pas montrer de 230 V, photographie seulement après vérification du montage et de ses droits.
Statut : À PRODUIRE. Aucune image définitive n'a encore été insérée.
-->

**Figure 3.10 — Montage pédagogique de la LED externe, contrôlé hors tension.**

### 3.17. Programmer la LED externe

Sur ce montage basse tension, la LED est reliée à la broche **D8**, et non à la LED intégrée D13.

Nous allons utiliser une constante :

~~~cpp
const byte LED_PIN = 8;
~~~

Ce code déclare un nom facile à reconnaître, \`LED_PIN\`, associé au numéro **8**. \`const\` indique que nous ne souhaitons pas modifier cette valeur dans le programme ; \`byte\` convient ici pour mémoriser un petit numéro de broche.

Notre programme devient :

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

**Programme 3.2 — Clignotement d'une LED externe, sur une Arduino Uno Rev3.**

La logique est identique à celle du programme 3.1 : nous avons conservé les mêmes fonctions et le même comportement, mais la broche commandée a changé.

Après avoir **vérifié le câblage hors tension**, rebranché l'USB puis réalisé la compilation et le téléversement, le **résultat attendu** est le clignotement de la LED externe avec une seconde d'allumage et une seconde d'extinction.

Nous avons écrit le numéro de broche une seule fois, dans \`LED_PIN\`. Cette pratique simplifiera la maintenance du programme lorsque le compteur accueillera davantage de composants.

### 3.18. Comprendre la limite de delay()

Notre premier programme fonctionne suivant une succession d'instructions simples :

~~~text
  Allumer → Attendre → Éteindre → Attendre → Recommencer
~~~

La fonction \`delay()\` crée une **attente bloquante pour l'exécution normale du sketch**. Pendant cette attente, notre logique principale ne peut pas poursuivre librement ses autres tâches. Certaines opérations matérielles, comme des interruptions, peuvent néanmoins exister ; \`delay()\` ne signifie pas que tous les périphériques de la puce s'arrêtent.

Cela ne pose pas de problème pour apprendre le clignotement d'une LED. Mais notre futur compteur devra accomplir plusieurs missions : consulter un capteur, mettre à jour un écran, traiter un bouton et préparer des communications.

Nous devrons donc remplacer progressivement les longues attentes bloquantes par des méthodes plus adaptées, notamment avec **millis()**. Ce sujet sera approfondi au chapitre 5.

C'est un excellent exemple de notre démarche : **le programme du chapitre 3 est une première étape, pas un système final figé**.

---

## Partie C — Exercices et diagnostic

### 3.19. TP 1 — Installer, vérifier et téléverser

**Durée indicative :** 20 à 30 minutes.  
**Matériel :** ordinateur, Arduino IDE 2, Arduino Uno Rev3 et câble USB de données.  
**Sécurité :** aucun composant secteur n'est utilisé.

**Travail demandé :**

1. Installez et ouvrez Arduino IDE 2.
2. Branchez l'Arduino Uno Rev3 avec un câble USB de données.
3. Sélectionnez **Arduino Uno** et le port détecté.
4. Créez le sketch minimal contenant uniquement \`setup()\` et \`loop()\`.
5. Cliquez sur **Vérifier** et notez le résultat.
6. Cliquez sur **Téléverser** et notez le résultat.
7. Sur **une copie distincte**, retirez une accolade fermante, puis relancez la vérification.
8. Corrigez l'erreur, vérifiez à nouveau et expliquez la différence entre compilation et téléversement.

**Travail écrit :** décrivez en cinq phrases le chemin parcouru par le programme entre l'éditeur et la carte.

**Important :** sans carte Arduino à disposition, il est possible d'étudier le code et la compilation dans un environnement compatible, mais vous ne devez pas annoncer de **téléversement réussi** sans transfert réel vers une carte.

### 3.20. TP 2 — Faire clignoter la LED intégrée puis externe

**Durée indicative :** 20 à 30 minutes.  
**Matériel :** Arduino Uno Rev3 et câble USB de données ; LED, 330 Ω et breadboard facultatifs pour l'étape externe.

**Étape A — LED intégrée :**

1. Recopiez le **programme 3.1**.
2. Vérifiez et téléversez-le.
3. Observez la LED **L** de votre carte.
4. Remplacez les attentes par **250 ms allumée** et **750 ms éteinte**.
5. Vérifiez et téléversez le nouveau programme. Notez le résultat observé.

**Étape B — LED externe, si le matériel est disponible :**

1. Débranchez l'USB.
2. Réalisez, uniquement en basse tension, le montage décrit à la figure 3.9.
3. Contrôlez la présence de la résistance et le sens de la LED.
4. Rebranchez l'USB.
5. Utilisez le **programme 3.2** puis adaptez les durées à **250 ms** et **750 ms**.
6. Si l'essai ne fonctionne pas, débranchez d'abord l'USB, puis inspectez le câblage avant de recommencer.

**Livrable :** le programme modifié et une courte description du rythme obtenu. Une photo du montage **hors tension**, si vous disposez d'une LED externe, pourra compléter votre compte rendu.

### 3.21. Tableau de dépannage — Observer avant de modifier

| Symptôme | Cause possible | Contrôle recommandé |
|---|---|---|
| Aucun port Arduino visible | Câble de recharge seulement, autorisations ou pilote manquant | Utiliser un câble USB de données ; vérifier les paramètres du système |
| Compilation impossible | Faute de syntaxe, accolade ou point-virgule absent | Lire les premiers messages d'erreur utiles et comparer au programme |
| Compilation réussie, téléversement impossible | Mauvais modèle/port, câble, port occupé | Vérifier la carte et le port puis la liaison USB |
| Sketch minimal sans effet visible | Aucune action programmée | C'est normal : utiliser ensuite le programme 3.1 |
| LED intégrée ne clignote pas | Mauvais sketch ou téléversement non confirmé | Vérifier que le programme 3.1 est bien chargé |
| LED externe éteinte | Polarité, résistance, connexion D8 ou GND incorrectes | Débrancher l'USB et examiner le circuit basse tension |
| Clignotement trop rapide ou trop lent | Valeurs de \`delay()\` inadaptées | Vérifier que les durées sont exprimées en millisecondes |

Pour distinguer les erreurs, posez-vous toujours les questions dans cet ordre : **le code compile-t-il ? Le téléversement aboutit-il ? Le résultat observable correspond-il au programme ?**

### 3.22. Autoévaluation — Dix questions

Choisissez **une seule bonne réponse** par question. Le corrigé détaillé se trouve dans **l'annexe C**.

**1. À quoi sert principalement Arduino IDE ?**  
A. Calculer les factures d'énergie — B. Écrire, compiler et téléverser des sketches — C. Alimenter une LED sans carte — D. Remplacer le microcontrôleur

**2. Quelle carte utilisons-nous pour les premières démonstrations ?**  
A. Arduino Mega — B. ESP32 — C. Raspberry Pi — D. Arduino Uno Rev3

**3. Quels réglages sont essentiels avant de téléverser ?**  
A. La carte et son port de connexion — B. La couleur de l'éditeur — C. Le navigateur par défaut — D. Le nom de l'ordinateur

**4. Quelle fonction est répétée après l'initialisation du sketch ?**  
A. \`install()\` — B. \`compile()\` — C. \`loop()\` — D. \`resetBoard()\`

**5. Que fait le bouton Vérifier ?**  
A. Il envoie toujours le programme à la carte — B. Il contrôle et compile le programme sans exiger un téléversement — C. Il active le modem GSM — D. Il mesure le courant de la LED

**6. Quel défaut peut empêcher une compilation avant même qu'une carte soit connectée ?**  
A. Une accolade manquante dans le programme — B. Une LED inversée — C. Un fil GND débranché — D. L'absence de carte SIM

**7. Le programme compile, mais le téléversement échoue. Que faut-il contrôler en priorité ?**  
A. Le disjoncteur du logement — B. La puissance du PZEM — C. La date de l'horloge RTC — D. Le câble USB de données, le modèle de carte et le port

**8. Pourquoi le programme minimal du début du chapitre ne produit-il rien de visible ?**  
A. L'Arduino n'accepte pas les programmes courts — B. \`loop()\` est interdite — C. \`setup()\` et \`loop()\` ne contiennent aucune action — D. Le secteur doit être connecté

**9. Quel est le rôle de la résistance de 330 Ω dans notre expérience avec LED externe ?**  
A. Créer une connexion GSM — B. Limiter le courant et protéger la LED et la sortie — C. Remplacer un câble USB — D. Ajouter une alimentation secteur

**10. Pour allumer la LED pendant 250 ms, puis l'éteindre pendant 750 ms, quelles instructions conviennent ?**  
A. \`delay(250)\` après HIGH et \`delay(750)\` après LOW — B. Supprimer la résistance — C. Relier D8 au 230 V — D. Garder \`delay(1000)\` après chaque état

**Objectif de maîtrise : au moins 8 bonnes réponses sur 10**, en comprenant les précautions de sécurité avant de modifier le montage réel.

---

## Partie D — Synthèse et suite du projet

### 3.23. Les sept idées essentielles

1. **Arduino IDE** permet d'écrire, de vérifier et de téléverser un programme vers une carte compatible.
2. Sur notre Arduino Uno Rev3, nous choisissons le **modèle de carte** et le **port de connexion** avant de téléverser.
3. **Vérifier** signifie compiler ; **téléverser** signifie transmettre le programme à la carte.
4. \`setup()\` prépare le fonctionnement ; \`loop()\` répète les instructions.
5. \`pinMode()\` configure une broche ; \`digitalWrite()\` fixe son état numérique ; \`delay()\` introduit une attente.
6. Une LED externe exige une **limitation de courant**, une polarité correcte et un montage **hors tension**.
7. Le clignotement constitue la **première fonction du même compteur intelligent** que nous enrichirons ensuite.

### 3.24. Vocabulaire pratique

| Terme | Définition |
|---|---|
| **IDE** | Environnement intégré de développement |
| **Sketch** | Programme Arduino, généralement enregistré dans un fichier \`.ino\` |
| **Compiler** | Transformer le programme source en code utilisable par la cible |
| **Téléverser** | Envoyer le programme vers le microcontrôleur de la carte |
| **Syntaxe** | Règles d'écriture du langage de programmation |
| **GPIO** | Broche d'entrée/sortie programmable |
| **HIGH / LOW** | États logiques haut et bas d'une sortie |
| **Milliseconde** | Un millième de seconde ; 1 000 ms = 1 s |
| **LED_BUILTIN** | Nom associé à la LED intégrée sur les cartes concernées |
| **Programme fil rouge** | Programme principal que l'on améliore sans repartir de zéro à chaque chapitre |

### 3.25. Ce que nous ferons au chapitre 4

Nous avons maintenant un programme capable de produire un signal visible. Au chapitre suivant, nous découvrirons **les variables, les types, les calculs, les conditions, les boucles et les fonctions en C/C++**.

Nous reprendrons **ce même programme de LED** comme point de départ, nous l'organiserons mieux et nous introduirons des valeurs pédagogiques utiles à la suite du compteur.

C'est ainsi que les fonctionnalités de notre système se construiront progressivement, jusqu'à la mesure énergétique, à l'affichage local et à la communication distante.
