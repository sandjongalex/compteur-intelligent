# M04-V01 — Script intégral : Variables, types et calculs en C++

**Durée cible : 7 minutes** · **Public : débutant ayant suivi M03** · **Support : Arduino IDE 2 + moniteur série**.
**Statut : script intégral rédigé, à lire et chronométrer avant l'enregistrement.** Les mentions [ÉCRAN] ne sont pas prononcées.

## 00:00–00:50 — Pourquoi les variables ?

[ÉCRAN : icônes tension, puissance, énergie et une boîte étiquetée « tensionV ».]

« Dans notre futur compteur, le microcontrôleur devra retenir des nombres : une tension, une puissance ou une consommation. Comment conserver ces nombres dans le programme ? Avec des variables.

Bonjour et bienvenue dans ce nouveau module AlexTech Academy. Dans les vidéos précédentes, nous avons créé un sketch et fait clignoter une LED. Maintenant, nous allons apprendre à stocker et à manipuler des valeurs en C et C++ pour notre ATmega328P.

À la fin de cette leçon, vous saurez créer une variable, choisir un type, réaliser un calcul et afficher son résultat. Nous utiliserons des valeurs inventées : aucun raccordement au secteur n'est nécessaire. »

## 00:50–02:00 — Une variable : une boîte étiquetée

[ÉCRAN : `int compteur = 3;`, `float tensionV = 230.5;`, `bool alarme = false;`.]

« Imaginez une boîte sur laquelle vous collez une étiquette. L'étiquette est le nom de la variable et son contenu est la valeur. Par exemple, nous écrivons int compteur égale trois, suivi d'un point-virgule. Ici, int indique que nous voulons un nombre entier.

Pour une mesure avec des décimales, nous écrivons float tensionV égale deux cent trente virgule cinq. Dans le code, on écrit les décimales avec **un point**, et non une virgule. Le type float permet de représenter approximativement un nombre décimal.

Enfin, bool alarme égale false sert à mémoriser une information vraie ou fausse. Ces trois types sont très utiles : int pour les entiers, float pour les décimaux et bool pour les états logiques.

Remarquez également la différence entre déclaration et affectation. La déclaration crée une variable avec un type ; le signe égal, dans cette instruction, lui attribue une valeur. »

## 02:00–03:00 — Constantes et limites du microcontrôleur

[ÉCRAN : `const float MILLE = 1000.0f;`, mémoire RAM représentée comme une jauge.]

« Certaines valeurs ne doivent pas changer pendant le programme. Nous pouvons écrire const float MILLE égale mille. Le mot const indique que nous ne voulons pas modifier cette valeur.

Sur une Arduino Uno Rev3 avec ATmega328P, la mémoire est limitée. Un int utilise deux octets et se limite à une plage d'environ moins trente-deux mille à plus trente-deux mille ; un float utilise quatre octets et n'est pas exact pour toutes les décimales.

Cela veut dire qu'un compteur d'impulsions ou un calcul d'énergie peut déborder si nous choisissons un type trop petit. Pour ce premier exercice, nos petites valeurs conviennent. Plus tard, nous utiliserons des types et des méthodes adaptés pour conserver des relevés précis et fiables. »

## 03:00–04:30 — Calculer une énergie simulée

[ÉCRAN : fichier `01_variables_calculs.ino`, mise en évidence des lignes, puis moniteur série.]

« Ouvrons notre premier programme. Nous définissons une puissance active fictive de cinq cents watts et une durée de deux heures. Nous voulons connaître l'énergie consommée dans cet exemple.

La formule est la suivante : énergie en kilowattheures égale puissance en kilowatts multipliée par durée en heures. Nous divisons donc cinq cents par mille, puis nous multiplions par deux. Résultat : un kilowattheure.

Dans le code, nous créons une variable float energieKWh. Nous lui donnons le résultat de l'expression puissanceW divisée par mille, multipliée par dureeHeures.

Pour voir cette valeur, nous utilisons Serial.begin avec neuf mille six cents dans setup : cela initialise la communication série avec l'ordinateur. Puis Serial.print affiche un texte et Serial.println affiche le nombre. En ouvrant le moniteur série au même débit, nous devons voir une valeur proche de un virgule zéro zéro zéro.

Ce sont des calculs fictifs. Le PZEM réel n'est pas encore connecté. »

## 04:30–05:40 — Le piège de la division entière

[ÉCRAN : tableau `5 / 2 = 2` / `5.0 / 2.0 = 2.5`.]

« Voici une erreur très importante : les divisions entre deux entiers. Si vous écrivez cinq divisé par deux, avec deux nombres entiers, le résultat entier est deux. La partie décimale est perdue.

Si vous voulez deux virgule cinq, vous devez réaliser la division avec des valeurs décimales, par exemple cinq point zéro divisé par deux point zéro.

La même prudence s'applique lorsqu'on convertit des watts en kilowatts. Écrivez mille point zéro ou assurez-vous qu'un opérande est de type float. Sinon, vous risquez d'obtenir zéro dans certains calculs qui devraient contenir des décimales.

Le compilateur peut accepter votre programme même lorsqu'un calcul est faux. Il faut donc aussi vérifier le résultat attendu. »

## 05:40–07:00 — Exercice et transition

[ÉCRAN : 200 W, 5 heures, résultat masqué puis révélé.]

« À vous de jouer ! Modifiez le programme pour utiliser deux cents watts pendant cinq heures. Quelle énergie le moniteur série doit-il afficher ?

Mettez la vidéo en pause. Deux cents watts représentent zéro virgule deux kilowatt. Multipliez par cinq heures et vous trouverez un kilowattheure. La valeur affichée doit donc être proche de un virgule zéro zéro zéro.

Retenez trois idées : une variable conserve une valeur, un type précise la nature de cette valeur, et un calcul doit toujours être vérifié, même si le sketch compile sans erreur.

Dans la prochaine vidéo, nous allons apprendre à prendre des décisions avec if et else, à répéter des instructions avec des boucles et à organiser nos calculs dans des fonctions. Ces bases serviront ensuite pour contrôler les capteurs et envoyer les données de notre compteur intelligent. »

## Note au formateur

- Les durées sont des objectifs de montage ; faire une répétition chronométrée.
- Toutes les valeurs sont simulées et jamais présentées comme des mesures réelles.
- Les limites `int` 16 bits et `float` 32 bits valent pour **Uno Rev3 / AVR ATmega328P**, pas toutes les cartes Arduino.
- Les projets `.ino` doivent être compilés dans Arduino IDE et leurs sorties série vérifiées avant le tournage.
