# M03-V02 — Faire clignoter une LED avec Arduino Uno

**Cible vidéo : 7 minutes** · **Format : caméra au-dessus du montage + capture de l'IDE** · **Statut : script rédigé, à répéter et chronométrer.**

Les passages entre « guillemets » sont à prononcer. Les indications **[CAMÉRA]** / **[ÉCRAN]** servent à préparer le montage.

## 00:00–00:45 — Promesse pratique

[CAMÉRA : Arduino Uno R3 alimentée uniquement en USB ; LED intégrée « L » visible.]

« Dans la vidéo précédente, nous avons installé Arduino IDE et envoyé notre premier programme. Cette fois, nous voulons voir un résultat concret : une LED qui s'allume, s'éteint et recommence sans intervention.

Pourquoi commencer par une LED ? Parce qu'elle nous permet de vérifier une sortie du microcontrôleur avec un exemple très simple. C'est aussi un premier pas vers les voyants d'état de notre futur compteur intelligent.

Nous ferons d'abord clignoter la LED intégrée de l'Arduino Uno, puis nous raccorderons une LED externe en basse tension. »

## 00:45–01:40 — Comprendre la LED et la sortie numérique

[CAMÉRA : montrer LED et résistance séparées ; deux flèches « anode + » et « cathode – ».]

« Une LED est une diode électroluminescente : c'est un composant qui produit de la lumière lorsqu'un courant circule dans le bon sens. Elle possède une anode et une cathode. En général, la patte la plus longue correspond à l'anode sur une LED neuve, mais il faut aussi vérifier sa forme et sa fiche technique.

Il faut limiter le courant dans la LED à l'aide d'une résistance adaptée. Sans cette résistance, vous risquez d'endommager la LED ou la sortie du microcontrôleur.

Une sortie numérique possède deux états logiques : HIGH, que nous utiliserons pour activer la sortie, et LOW, pour la désactiver. Sur notre Arduino Uno, la LED intégrée appelée L est reliée à la broche numérique 13 ; nous pouvons la commander grâce à la constante LED_BUILTIN. »

## 01:40–02:45 — Premier programme avec LED_BUILTIN

[ÉCRAN : ouvrir `01_blink_interne/01_blink_interne.ino`, zoom sur les lignes.]

« Ouvrons le premier sketch. Dans setup, nous écrivons pinMode avec LED_BUILTIN et OUTPUT. Cela signifie que cette broche sera utilisée comme sortie.

Puis, dans loop, nous écrivons digitalWrite avec HIGH pour activer la LED. La fonction delay suivie de mille indique une attente de mille millisecondes, c'est-à-dire une seconde.

Ensuite, digitalWrite avec LOW éteint la LED ; une nouvelle attente de mille millisecondes marque une seconde d'extinction.

Comme loop se répète, nous obtenons une seconde allumée, une seconde éteinte, puis le même cycle. Vérifiez le programme, choisissez l'Arduino Uno et le bon port, puis cliquez sur Téléverser. »

## 02:45–03:35 — Observer et modifier la cadence

[CAMÉRA : LED L clignotante ; capture d'un chronomètre.]

« Regardez la petite LED marquée L sur la carte : elle doit alterner entre allumé et éteint. Si le programme a été téléversé correctement, ce résultat est visible sans composant externe.

Essayons une modification. Nous pouvons remplacer mille par deux cent cinquante pour la durée d'allumage et par sept cent cinquante pour la durée d'extinction. Cela donne un quart de seconde allumée, puis trois quarts de seconde éteinte.

C'est votre première vraie modification de comportement logiciel. Les nombres du programme changent la vitesse et le rythme observés sur notre carte. »

## 03:35–04:40 — Raccorder la LED externe

[CAMÉRA : Arduino débranchée, breadboard, résistance de 330 ohms, LED.]

« Passons à une LED externe. Débranchez d'abord le câble USB pour modifier le montage hors tension. Prenez une LED, une résistance d'environ trois cent trente ohms et une petite breadboard destinée aux circuits basse tension.

Nous allons utiliser la broche numérique D8. La liaison part de D8 vers la résistance, puis vers l'anode de la LED. La cathode rejoint une broche GND de l'Arduino. La résistance et la LED sont en série : la résistance limite le courant.

Vérifiez bien le sens de la LED et la présence de la résistance. Ne reliez pas le secteur au montage : l'Arduino est simplement alimentée par USB, et cette expérience reste en basse tension.

Lorsque les connexions sont prêtes, rebranchez le câble USB. »

## 04:40–05:45 — Téléverser et expliquer les fonctions

[ÉCRAN : ouvrir `02_blink_externe/02_blink_externe.ino`. Montrer `LED_PIN = 8` et les lignes de commande.]

« Pour commander cette nouvelle LED, nous remplaçons la LED intégrée par une broche externe. Dans le code, nous utilisons une constante appelée LED_PIN, qui vaut huit. Cela facilite la lecture : si nous changeons un jour la broche, nous savons où modifier le numéro.

Dans setup, nous déclarons la broche huit comme sortie. Dans loop, digitalWrite met cette broche à HIGH, delay attend une seconde, digitalWrite remet la broche à LOW et nous attendons encore une seconde.

Vérifiez le code, puis téléversez-le. Maintenant, la LED externe doit clignoter. Si elle reste éteinte, contrôlez l'anode, la cathode, la résistance, la connexion D8 et le câble USB. Ne touchez pas au montage tant qu'il est alimenté. »

## 05:45–07:00 — Exercice, erreurs et transition

[CAMÉRA : montrer une LED qui clignote rapidement, puis le code correspondant.]

« Votre exercice consiste à faire clignoter cette LED pendant deux cent cinquante millisecondes d'allumage, puis sept cent cinquante millisecondes d'extinction. Vous trouverez un code corrigé dans les ressources si vous souhaitez comparer.

Retenez les quatre outils essentiels que nous venons d'utiliser. pinMode définit le rôle d'une broche. digitalWrite fixe son état à HIGH ou LOW. delay crée une attente en millisecondes. Et loop recommence les instructions en permanence.

Il existe une limite : pendant delay, notre programme attend et ne peut pas réagir librement à d'autres événements. Dans un module suivant, nous apprendrons à gérer plusieurs tâches sans ces attentes bloquantes.

Vous venez de faire fonctionner votre premier montage électronique programmé. Dans le prochain module, nous approfondirons les variables, les types, les conditions et les fonctions C et C++. »

---

## Notes de sécurité et préparation

- **Arduino Uno Rev3 uniquement** pour cette démonstration ; le repère `LED_BUILTIN` dépend de la carte.
- **LED externe et résistance en série** ; ne jamais connecter directement une LED entre D8 et GND sans limitation de courant.
- Faire toutes les connexions externes USB débranché. Aucun montage secteur n'est utilisé.
- Vérifier physiquement le câblage et le comportement des sketches avant tournage.
- Le `delay()` est volontairement simplifié ; ses limites seront traitées au Module 05.
- Référence officielle : https://docs.arduino.cc/built-in-examples/basics/Blink
