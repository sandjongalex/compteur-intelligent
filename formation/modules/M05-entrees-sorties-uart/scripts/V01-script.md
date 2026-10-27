# Script formateur — M05-V01 : Un bouton qui commande une LED (9 min)

**Format : vraie Uno Rev3 + prise de vue de la LED L + Arduino IDE 2. Pas de PowerPoint.**  
**Durée visée : 9 min, à vérifier à la répétition.** Les phrases entre « » sont prononcées ; les instructions **[À L'ÉCRAN]** / **[MANIP]** ne le sont pas.

## 00:00–00:55 · Montrer le résultat avant de coder

[MANIP] Uno avec bouton entre D2 et GND, sketch final `V01_03_bascule_antirebond.ino` déjà téléversé, uniquement USB.

« Regardez cette carte. Quand j'appuie une première fois sur le bouton, la LED s'allume. J'appuie encore, elle s'éteint. Un appui, un changement d'état. C'est exactement le type de fonction que nous utiliserons plus tard pour changer les pages du compteur sur son écran LCD.

Bonjour et bienvenue dans le Module 05 d'AlexTech Academy ! Aujourd'hui, nous allons découvrir comment lire une entrée numérique, agir sur une sortie et surtout éviter qu'un seul appui sur un bouton soit pris pour plusieurs appuis.

La meilleure façon d'apprendre est de construire cette fonction en plusieurs étapes : d'abord une lecture simple, puis un changement d'état, enfin la version fiable. »

## 00:55–02:10 · Comprendre le bouton et INPUT_PULLUP

[MANIP] Montrer D2, GND, le bouton et les 4 pattes éventuelles ; **débrancher l'USB avant tout changement de fil**.

« Une entrée numérique nous dit si un signal est à l'état haut, HIGH, ou bas, LOW. Mais lorsque rien n'impose de niveau électrique à la broche, elle peut devenir flottante : on ne sait plus très bien ce que le programme va lire.

Pour éviter cela, nous activons la résistance de rappel interne grâce à `pinMode(2, INPUT_PULLUP)`. Sur notre montage, un côté du contact du bouton rejoint D2, l'autre rejoint GND.

Tant qu'on ne touche pas au bouton, la résistance interne maintient D2 à HIGH. Lorsque l'on appuie, le bouton relie D2 à GND et la broche devient LOW. Notre logique est donc inversée : LOW signifie appuyé.

Si votre bouton a quatre broches, repérez bien les deux contacts qui ne sont reliés entre eux **que lorsque vous appuyez**. Certains boutons présentent des broches déjà reliées deux à deux. N'improvisez pas le câblage : vérifiez-le hors tension. »

## 02:10–03:20 · Étape 1 : allumer seulement pendant l'appui

[À L'ÉCRAN] Ouvrir `code/V01_01_bouton_niveau/V01_01_bouton_niveau.ino` ; zoomer sur `pinMode` et la ligne `digitalRead`.

« Premier sketch. Nous déclarons `BROCHE_BOUTON` égale deux et `BROCHE_LED` égale `LED_BUILTIN`. Sur l'Uno Rev3, cette constante désigne la LED intégrée à la broche D13. Nous n'avons donc pas besoin d'une deuxième LED.

Dans `setup`, nous mettons le bouton en `INPUT_PULLUP` et la LED en `OUTPUT`. Ensuite, dans `loop`, `digitalRead` lit le bouton.

Nous écrivons `digitalRead(BROCHE_BOUTON) == LOW`. Les deux signes égal signifient : comparer. Si le bouton est appuyé, la variable booléenne devient vraie. `digitalWrite` utilise cette valeur pour allumer la LED.

[MANIP] Vérifier, téléverser, puis appuyer et relâcher.

Vous voyez : la LED est allumée tant que j'appuie, mais s'éteint lorsque je relâche. Il ne s'agit pas encore d'une bascule permanente. »

## 03:20–04:45 · Étape 2 : changer d'état à chaque appui

[À L'ÉCRAN] Ouvrir `V01_02_bascule_sans_antirebond.ino`, montrer seulement le test de transition.

« Pour obtenir un changement d'état à chaque nouvel appui, nous devons distinguer l'état actuel de l'état précédent.

Nous créons deux variables booléennes : `ancienEtatAppuye` et `ledAllumee`. Dans la boucle, si le bouton est maintenant appuyé mais qu'il ne l'était pas juste avant, nous considérons que c'est le début d'un nouvel appui.

La ligne `ledAllumee = !ledAllumee` inverse le booléen : si la LED était éteinte, elle devient allumée ; si elle était allumée, elle devient éteinte.

Nous appliquons ensuite cet état à la LED et mémorisons l'état du bouton pour le tour suivant.

[MANIP] Téléverser et observer.

Sur certains boutons, le résultat paraît correct. Mais il reste un défaut : un contact mécanique ne passe pas toujours proprement de ouvert à fermé. Il peut rebondir très rapidement et provoquer plusieurs changements pendant un seul appui. Nous allons le corriger. »

## 04:45–06:25 · Comprendre le rebond et l'attente non bloquante

[À L'ÉCRAN] Petite illustration d'une suite brève HIGH/LOW/HIGH/LOW, puis même signal stabilisé.

« Le rebond mécanique ressemble à cela : quand le contact se ferme, le signal peut osciller quelques millisecondes avant de se stabiliser. Si notre programme surveille simplement chaque transition, un appui peut être compté deux ou trois fois.

On pourrait être tenté d'ajouter un long `delay`, mais cela arrête temporairement l'avancement du programme. Or notre futur compteur devra à la fois lire des mesures, actualiser un écran et transmettre des données.

Nous préférons donc attendre **sans bloquer**, en utilisant `millis()`. Cette fonction donne le nombre de millisecondes écoulées depuis le démarrage de la carte.

À chaque changement brut du bouton, nous mémorisons le moment. Puis, si l'état reste stable au moins trente-cinq millisecondes, nous acceptons le nouvel état.

C'est la différence entre : « j'ai vu un signal changer » et « je confirme que cet état est stable ». »

## 06:25–07:45 · Étape 3 : la version corrigée

[À L'ÉCRAN] Ouvrir `V01_03_bascule_antirebond.ino` ; montrer les trois blocs : lecture, durée, validation.

« Voici notre version corrigée. Trois éléments sont importants.

D'abord, `dernierNiveauBrut` permet de repérer un changement. Nous mémorisons dans `debutChangementMs` le moment de ce changement.

Ensuite, nous calculons : temps actuel moins temps du dernier changement. Si au moins trente-cinq millisecondes se sont écoulées et que le nouveau niveau est différent du niveau stable, nous validons l'état.

Enfin, nous ne basculons la LED que lorsque le **niveau stable devient LOW**. Autrement dit, au début d'un appui reconnu. Quand on relâche le bouton, on actualise l'état stable, mais on ne rebascule pas la LED.

Le temps est stocké dans un `unsigned long`, un type adapté à `millis` sur Arduino Uno. La soustraction des temps permet aussi de gérer correctement le retour du compteur de millisecondes à zéro, selon cette technique.

[MANIP] Téléverser, appuyer trois fois lentement, puis plusieurs fois plus rapidement. »

## 07:45–08:25 · Vérifier et diagnostiquer

[MANIP] Tester cinq appuis, sans prétendre avoir fait les tests si la carte n'est pas réellement filmée.

« Avec cinq appuis distincts, nous attendons cinq changements de LED, pas davantage. Si la LED reste toujours allumée, contrôlez d'abord le vrai contact du bouton et sa liaison D2–GND.

Si elle s'allume seulement pendant l'appui, vous avez probablement laissé le programme de la première étape. Et si vous constatez plusieurs changements sur un seul appui, relisez la partie anti-rebond, notamment la détection de l'état stable.

Un bon développeur ne regarde pas seulement le code : il compare ce que le programme fait à ce qu'il devrait faire. »

## 08:25–09:00 · Mini-défi et transition

« Voici votre défi : à la place d'une LED, imaginez deux pages sur notre futur afficheur. Le premier appui sélectionne la page zéro, le suivant la page un, et ainsi de suite.

La correction est fournie dans le TP du module. Ne recopiez pas directement la solution : essayez d'abord d'utiliser ce que nous venons de construire.

Dans la prochaine vidéo, nous passerons aux communications série UART et aux temporisations avec `millis()`. Ce sera indispensable pour envoyer les données de notre compteur, sans bloquer toutes ses autres tâches. »

---

## Contrôles du formateur

- [ ] Montrer la LED et le bouton en fonctionnement **réel**, pas une simulation présentée comme test.
- [ ] Faire apparaître les fichiers `V01_01`, `V01_02`, `V01_03` dans cet ordre ; ne pas dicter toute la version finale.
- [ ] Débrancher l'USB avant les modifications de câblage, aucun montage secteur.
- [ ] Répéter et chronométrer pour tenir 9 minutes de vidéo finale.
- [ ] Vérifier que les trois versions compilent sur Arduino Uno Rev3.
