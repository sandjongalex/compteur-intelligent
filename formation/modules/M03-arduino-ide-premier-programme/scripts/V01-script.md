# M03-V01 — Installer Arduino IDE et comprendre la compilation

**Cible vidéo : 7 minutes** · **Format : capture d'écran Arduino IDE 2 + carte Arduino Uno R3** · **Statut : script rédigé, à répéter et chronométrer.**

Les passages entre « guillemets » sont à prononcer ; les mentions **[ÉCRAN]** sont des consignes de production.

## 00:00–00:50 — Accroche

[ÉCRAN : une Arduino Uno, le logiciel Arduino IDE et une flèche « programme → carte ».]

« Jusqu'ici, nous avons vu les composants de notre compteur et les précautions pour travailler en sécurité. Il est temps de passer à la programmation.

Notre microcontrôleur ATmega328P ne comprend pas directement les phrases que nous écrivons. Nous allons utiliser un logiciel appelé Arduino IDE pour préparer, vérifier et envoyer des instructions à notre carte. Dans cette vidéo, je vous montre les étapes une par une, même si vous n'avez jamais écrit une seule ligne de code.

Notre objectif est simple : installer le logiciel, reconnaître ses outils, choisir la bonne carte et réussir notre premier téléversement. »

## 00:50–01:50 — Télécharger et installer

[ÉCRAN : navigateur ouvert sur https://www.arduino.cc/en/software ; montrer l'adresse officielle et les options système.]

« Ouvrez votre navigateur et rendez-vous sur le site officiel Arduino, dans la rubrique Software. Téléchargez Arduino IDE 2 correspondant à votre système : Windows, macOS ou Linux. Nous utiliserons la version 2, dont l'interface réunit l'éditeur, la compilation et les messages.

Sous Windows, lancez l'installateur et suivez les instructions. Sur un autre système, les étapes diffèrent ; les liens officiels sont fournis dans les ressources du module.

Une fois installé, ouvrez Arduino IDE. Au centre, vous voyez la zone où nous allons écrire le programme. En haut, vous trouverez une coche pour vérifier et une flèche pour téléverser. En bas, une console affichera les messages de compilation. Pas besoin de connaître toutes les fonctions du logiciel dès aujourd'hui. »

## 01:50–02:45 — Connecter l'Arduino Uno

[ÉCRAN : brancher une Uno R3 avec un câble USB de données. Montrer le sélecteur de carte et de port.]

« Prenez une carte Arduino Uno R3 et un câble USB permettant de transférer des données. Certains câbles ne servent qu'à la recharge et empêchent l'ordinateur de communiquer avec la carte.

Connectez la carte. Dans Arduino IDE, sélectionnez Arduino Uno : pour notre cours, c'est le modèle utilisé. Choisissez ensuite le port qui correspond à votre carte. Sous Windows, il peut être appelé COM suivi d'un numéro ; sous Linux ou macOS, le nom sera différent.

Si le port n'apparaît pas, vérifiez le câble, le branchement et, selon le matériel, les pilotes ou autorisations nécessaires. Ne choisissez pas un port au hasard : débranchez et rebranchez la carte pour observer celui qui apparaît. »

## 02:45–03:45 — Comprendre un sketch

[ÉCRAN : fichier `00_premier_sketch/00_premier_sketch.ino`. Mettre en évidence `setup` puis `loop`.]

« Un programme Arduino est souvent appelé un sketch. Regardez celui-ci : il contient deux fonctions. Une fonction, c'est une partie de programme qui rassemble des instructions.

La fonction setup sera appelée une seule fois après le démarrage ou un redémarrage. La fonction loop sera répétée tant que la carte est alimentée.

Pour notre premier test, nous allons laisser ces deux fonctions vides. Le programme ne fera rien de visible : c'est normal. L'objectif est d'abord de comprendre le passage du texte écrit vers un programme accepté par le microcontrôleur.

Vous remarquez les accolades et les parenthèses. Leur présence est importante : en programmation, un seul caractère oublié peut empêcher la compilation. »

## 03:45–04:50 — Vérifier ≠ téléverser

[ÉCRAN : cliquer d'abord sur la coche « Vérifier », puis sur la flèche « Téléverser ».]

« Première étape : cliquez sur Vérifier. Le logiciel analyse le code et le compile. Compiler signifie transformer nos instructions en une forme qui pourra être exécutée par le microcontrôleur. Quand cette opération réussit, la console affiche des informations sur la taille du programme.

À ce stade, le programme n'a pas nécessairement été envoyé sur la carte. La vérification n'est pas le téléversement.

Deuxième étape : cliquez sur Téléverser. Arduino IDE compile le programme, puis l'envoie à la carte sélectionnée à travers le port choisi. Attendez la confirmation de la fin du téléversement.

Si tout se passe bien, notre première étape est réussie, même si aucune LED ne clignote encore. Nous avons installé et transféré un programme valide. »

## 04:50–05:55 — Diagnostiquer une erreur simple

[ÉCRAN : afficher une copie d'un sketch avec une accolade manquante, puis corriger la copie et relancer Vérifier.]

« Voyons maintenant ce qui se passe lorsqu'un programme contient une erreur. Je retire volontairement une accolade sur une copie du fichier, puis je clique sur Vérifier.

La compilation échoue. Ce n'est pas une panne de la carte, mais une erreur dans le texte du programme. Les messages de la console peuvent indiquer la ligne ou la structure concernée. Je remets l'accolade, puis je relance la vérification : le programme est accepté.

Autre problème fréquent : la compilation réussit, mais le téléversement échoue. Dans ce cas, vérifiez d'abord la carte choisie, le port, le câble USB et l'éventuelle utilisation du port par un autre logiciel. Distinguer ces deux types d'erreurs vous fera gagner beaucoup de temps. »

## 05:55–07:00 — Récapitulatif et exercice

[ÉCRAN : afficher cinq étapes numérotées ; proposer une petite question.]

« Résumons ensemble. Un : télécharger et ouvrir Arduino IDE. Deux : brancher l'Arduino Uno à l'aide d'un câble de données. Trois : sélectionner la carte et le port. Quatre : vérifier le code. Cinq : téléverser le programme.

Votre exercice consiste à ouvrir le sketch minimal fourni avec ce module et à cliquer sur Vérifier. Ensuite, si vous disposez d'une Arduino Uno, sélectionnez-la et téléversez ce programme. Notez la différence entre les deux actions.

Dans la prochaine vidéo, nous allons enfin écrire un programme qui produit un effet visible : allumer puis éteindre une LED. Et vous verrez que quelques lignes de code suffisent pour donner vie à notre carte Arduino. »

---

## Contrôle et précisions

- Le parcours se fonde sur **Arduino IDE 2** et **Arduino Uno R3**, pas sur une autre version de carte.
- Les noms et positions exacts de menus peuvent évoluer ; revoir les captures lors du tournage.
- Le sketch minimal doit être compilé réellement sur une Uno avant publication ; ne pas confondre rédaction de code et validation matérielle.
- Aucun composant secteur n'est connecté.
- **La durée de 7 minutes est une cible** : la répétition orale et les manipulations seront chronométrées.
- Documentation : https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing et https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-uploading-a-sketch/
