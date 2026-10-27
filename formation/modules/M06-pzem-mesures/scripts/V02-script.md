# Script intégral M06-V02 — Lire, valider et diagnostiquer les relevés PZEM

**Vidéo cible : 8 minutes · Capture de l'IDE, de la console et démonstration fictive.**  
**Démonstration réelle uniquement sur banc mis en service par une personne qualifiée.** Les phrases entre « » sont prononcées ; les indications **[ÉCRAN]** sont des gestes de tournage.

## 00:00–00:55 — Résultat final et objectif

[ÉCRAN] Comparer « OK : 230.5 V » à « ERREUR : relevé absent », étiqueter « simulation ».

« Un compteur intelligent doit faire plus que recevoir des nombres. Il doit savoir si le relevé est valable et signaler les problèmes de communication.

Regardez les trois résultats fictifs à l'écran : première lecture réussie, deuxième lecture indisponible et troisième lecture réussie. En cas de panne, nous n'inventons pas une valeur et nous ne prétendons pas que l'ancienne mesure est une mesure nouvelle.

Dans cette vidéo, nous allons programmer cette logique avec Arduino, puis voir comment l'appliquer à la bibliothèque du PZEM-004T version 3.0. »

## 00:55–02:10 — Créer une source de mesure simulée

[ÉCRAN] Ouvrir `V02_01_lecture_simulee.ino`; zoomer sur `struct Mesures` puis `lireSimulation`.

« Commençons sans matériel de mesure. Notre programme possède une structure Mesures, avec les six grandeurs vues dans la vidéo précédente.

Nous créons une fonction lireSimulation. Elle remplit la structure avec des nombres fictifs et renvoie la valeur true. Ce booléen signifie que la lecture a réussi.

Dans loop, nous vérifions régulièrement le temps avec millis. Toutes les deux secondes environ, nous appelons lireSimulation, puis la fonction d'affichage.

Voilà une architecture simple : une fonction fournit les données, une autre les présente. Cette séparation est très utile. Lorsque nous remplacerons la simulation par une vraie lecture, le reste du programme pourra garder la même logique. »

## 02:10–03:25 — Simuler une panne de communication

[ÉCRAN] Ouvrir `V02_02_detection_panne_simulee.ino` ; montrer le `return false` à la deuxième tentative.

« Une lecture réelle peut échouer. Le module peut ne pas répondre, la liaison peut être défaillante ou certaines valeurs peuvent être invalides.

Dans notre deuxième sketch, nous simulons volontairement une panne toutes les trois tentatives : la deuxième tentative échoue. La fonction renvoie false sans fournir un nouveau relevé.

Le programme affiche alors ERREUR : relevé absent, et ne publie pas de nombres comme s'ils provenaient du capteur.

C'est important : **une mesure égale à zéro peut être parfaitement valide**. Par exemple, un courant nul peut simplement signifier qu'aucune charge ne consomme à cet instant. Nous ne devons donc pas utiliser zéro comme synonyme d'erreur. »

## 03:25–04:40 — Installer et comprendre la bibliothèque

[ÉCRAN] Page du dépôt `mandulaj/PZEM-004T-v30`, gestionnaire de bibliothèques Arduino IDE.

« Nous pouvons maintenant examiner le code destiné à la lecture réelle. Pour le PZEM-004T V3, nous choisissons une bibliothèque adaptée à cette version, appelée PZEM004Tv30.

La bibliothèque prépare les requêtes Modbus et interprète les réponses. Au lieu de composer nous-mêmes les octets et de calculer le CRC, nous pouvons appeler des méthodes telles que voltage, current, power, energy, frequency et pf.

Sur Arduino Uno, la communication USB de débogage utilise déjà le port série matériel. Notre exemple utilise donc SoftwareSerial pour réserver une autre interface série au PZEM.

Attention : le script de lecture réelle ne constitue pas un tutoriel de raccordement secteur. Il exige que le PZEM, sa variante exacte, la partie mesure, les protections et l'interface électronique aient été préalablement contrôlés par une personne qualifiée. »

## 04:40–06:10 — Lecture réelle et validation

[ÉCRAN] Ouvrir `V02_03_pzem_reel_qualifie.ino`, mettre en évidence `lireMesures` et `valeursValides`. Ne pas donner d'instructions pour brancher le 230 V.

« Dans le code, nous créons un objet PZEM associé à une liaison SoftwareSerial. Notre fonction lireMesures appelle les six méthodes de la bibliothèque et range les résultats dans notre structure.

Nous devons ensuite vérifier les nombres reçus. En cas d'absence de réponse, une bibliothèque peut signaler l'échec par une valeur spéciale, par exemple NaN, qui signifie que ce n'est pas un nombre valide.

La fonction valeursValides refuse les nombres non finis et vérifie quelques bornes élémentaires : tension, courant, puissance et énergie ne doivent pas être négatifs ; le facteur de puissance reste entre zéro et un.

Ce contrôle ne certifie pas que les mesures sont exactes. Il sert seulement à éviter de traiter une réponse manifestement incorrecte comme un relevé normal.

Si tout est valide, le programme affiche les six grandeurs. Sinon, il signale LECTURE INVALIDE et attend le prochain essai. Aucune ancienne valeur n'est publiée comme nouvelle. »

## 06:10–07:05 — Dépanner correctement

[ÉCRAN] Tableau court « panne → vérification », puis capture du message d'erreur prévu.

« Que faire si les données ne s'affichent pas ? Commençons par lire le message d'erreur et confirmer la bonne version de la bibliothèque. Vérifions la sélection de carte, la vitesse de la console et la configuration de l'interface prévue par le code.

Avec un matériel réel, une absence de réponse peut aussi provenir d'une mauvaise adresse Modbus, d'une alimentation inadaptée, d'une interface incorrecte ou d'une partie métrologique qui n'est pas en fonctionnement.

Mais les vérifications physiques liées au secteur relèvent du professionnel responsable du banc sécurisé. Nous ne cherchons jamais à corriger cette panne en manipulant nous-mêmes des conducteurs secteur sous tension. »

## 07:05–08:00 — Exercice et conclusion

[ÉCRAN] Afficher « 230.5 V → panne → 230.5 V » et demander ce qui doit apparaître.

« Votre défi consiste à améliorer le programme de simulation : sur une lecture correcte, afficher les valeurs ; sur une panne, afficher un message d'erreur, sans inventer zéro et sans conserver un relevé ancien comme s'il était nouveau.

Vous pouvez également modifier les registres fictifs et vérifier les six conversions. Les corrigés sont disponibles dans les travaux pratiques.

Nous avons désormais compris comment lire et vérifier les données du PZEM V3, sans confondre simulation et mesure physique.

Dans le prochain module, nous ajouterons l'horloge DS3231 et l'écran LCD vingt colonnes sur quatre lignes. Notre compteur saura alors présenter ses informations avec une date et une heure. »

## Checklist formateur

- [ ] Tester les exemples fictifs sur Uno USB avant la vidéo.
- [ ] Garder les données clairement signalées « SIMULÉES ».
- [ ] Si une mesure réelle est montrée, elle provient d'un banc isolé/protégé installé et exploité par un professionnel qualifié.
- [ ] Vérifier version de bibliothèque, logique des six méthodes et retour d'erreur.
- [ ] Ne pas enseigner l'utilisation de `resetEnergy()` pour le cumul journalier.
- [ ] Respecter 8 minutes après répétition.
