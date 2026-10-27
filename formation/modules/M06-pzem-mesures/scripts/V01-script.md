# Script intégral M06-V01 — Comprendre le PZEM-004T V3 et Modbus RTU

**Vidéo cible : 8 minutes · Sans PowerPoint · Apprendre par simulation avant toute mesure réelle.**  
Les phrases entre guillemets français sont à prononcer. Les annotations **[ÉCRAN]** ne sont pas prononcées. **Durée à chronométrer au tournage.**

## 00:00–00:55 — Montrer le résultat attendu

[ÉCRAN] Moniteur série d'une Uno utilisant `V01_01_six_grandeurs_simulees.ino`. Afficher explicitement « SIMULATION ».

« Nous allons franchir une étape essentielle dans la conception de notre compteur : comprendre d'où viennent les valeurs électriques que nous voulons afficher.

Regardez le moniteur série. Nous voyons une tension, un courant, une puissance, une énergie, une fréquence et un facteur de puissance. Ces valeurs sont **fictives** : je ne suis connecté à aucune installation électrique.

Dans notre appareil final, elles viendront d'un module de mesure spécialisé appelé PZEM-004T, version 3.0. Aujourd'hui, nous allons découvrir ces informations, puis construire leur lecture logicielle sans manipuler le secteur. »

## 00:55–02:05 — Identifier le module et ses six grandeurs

[ÉCRAN] Photo du PZEM hors tension, puis six libellés à côté du moniteur.

« Le PZEM-004T V3 permet de mesurer six grandeurs principales. La tension, en volts, indique la différence de potentiel. Le courant, en ampères, représente le débit de charges. La puissance active, en watts, indique le rythme réel de transfert d'énergie. L'énergie cumulée, en kilowattheures, représente ce qui a été mesuré au fil du temps.

Il nous donne également la fréquence en hertz, et le facteur de puissance. Ce dernier sert à comprendre pourquoi, en courant alternatif, la puissance active ne correspond pas toujours simplement à la tension multipliée par le courant.

Sur certaines variantes, le courant est mesuré au moyen d'un transformateur de courant compatible. Il ne faut pas mélanger les spécifications ou les accessoires d'un PZEM dix ampères et d'un modèle cent ampères.

La version 3.0 n'est pas identique aux anciennes versions : nous utiliserons sa documentation et sa bibliothèque spécifiques. »

## 02:05–03:15 — Expliquer UART et Modbus

[ÉCRAN] Schéma fonctionnel : ATmega ⇄ UART ⇄ PZEM ; flèches « demande » puis « réponse ». Pas de branchement électrique de puissance.

« Comment le microcontrôleur récupère-t-il ces six nombres ? Par une interface série de type UART, avec un protocole de communication appelé Modbus RTU.

Vous connaissez déjà les broches TX et RX du module précédent. Mais une liaison série seule ne définit pas le sens des octets échangés. Modbus ajoute des règles : un appareil qui interroge, un appareil qui répond, une adresse, une commande, des données et une vérification d'intégrité appelée CRC.

Imaginez une bibliothèque. Vous demandez un livre à une adresse précise, le bibliothécaire consulte le bon emplacement et vous remet l'information. Ici, l'ATmega demande des registres au PZEM, et le module renvoie les nombres associés.

Nous ne programmerons pas aujourd'hui le détail du CRC : la bibliothèque pourra gérer cette partie plus tard. »

## 03:15–04:35 — Lire les registres sans se tromper d'unité

[ÉCRAN] Tableau des registres de 0x0000 à 0x0009, puis afficher seulement 0x0000, 0x0001–02, 0x0005–06.

« Un registre est une case numérotée dans laquelle le module fournit une information. Par exemple, pour le PZEM V3, le registre zéro contient la tension, exprimée en dixièmes de volt.

Cela signifie que le nombre brut deux mille trois cent cinq correspond à deux cent trente virgule cinq volts. Nous divisons par dix.

Pour le courant, la documentation utilise deux registres : un mot bas et un mot haut qui forment une valeur plus grande. Les unités sont alors au millième d'ampère.

Même idée pour l'énergie : deux registres forment un index exprimé en wattheures. Si l'index brut vaut douze mille trois cent quarante-cinq, cela représente douze virgule trois quatre cinq kilowattheures après division par mille.

Il ne faut donc jamais afficher un registre brut sans effectuer la conversion adaptée. Et notre tableau ne décrit **que la version 3.0**, pas tous les compteurs existants. »

## 04:35–05:55 — Construire une première lecture simulée

[ÉCRAN] Ouvrir `code/V01_01_six_grandeurs_simulees`, puis `V01_02_registres_decodes`.

« Ouvrons notre premier programme. Il contient une structure appelée Releve. Elle regroupe les six nombres utiles dans un seul objet logiciel. Nous saisissons des valeurs entièrement fictives, puis une fonction les affiche clairement avec leurs unités.

Dans le moniteur série, la tension affichée sera deux cent trente virgule cinq volts ; la puissance, quatre-vingt-douze virgule deux watts ; l'énergie, douze virgule trois quatre cinq kilowattheures. Ces nombres illustrent le format du résultat.

Passons au deuxième programme : cette fois, nous commençons par un tableau de dix registres, comme si nous avions reçu une réponse correcte du module. Mais aucun octet n'est réellement transmis sur les fils : le tableau est défini dans notre code.

Nous divisons la tension par dix, recomposons les valeurs sur trente-deux bits pour le courant, la puissance et l'énergie, puis appliquons les unités. Nous obtenons les mêmes résultats compréhensibles. »

## 05:55–06:55 — Vérifier sans mesurer le secteur

[ÉCRAN] Comparer tableau des valeurs brutes, calculs et sortie attendue ; montrer la colonne « unité ».

« Pour apprendre efficacement, prenons le temps de prévoir le résultat avant de cliquer sur Téléverser.

Le registre tension contient deux mille trois cent cinq. Que doit afficher le programme ? Deux cent trente virgule cinq volts. L'énergie contient douze mille trois cent quarante-cinq wattheures. Cela donne douze virgule trois quatre cinq kilowattheures.

Vérifiez maintenant le programme sur une carte Arduino Uno reliée seulement à votre ordinateur, avec le moniteur série à neuf mille six cents bauds. Vous pouvez comprendre le protocole et les conversions sans approcher un câble secteur.

Plus tard, le raccordement réel de la partie mesure sera réservé à un banc préparé par une personne qualifiée. »

## 06:55–08:00 — Pièges et défi

[ÉCRAN] Trois cartes : « version erronée », « unité erronée », « index cumulatif ».

« Retenez trois pièges. Premier piège : utiliser une bibliothèque de l'ancienne version du PZEM avec un modèle V3. Deuxième piège : afficher une valeur brute en oubliant son facteur d'échelle. Troisième piège : croire que l'énergie cumulée représente automatiquement l'énergie du jour.

L'index d'énergie du PZEM est **cumulatif**. Nous apprendrons à déterminer les consommations journalières et mensuelles plus tard, avec notre horloge DS3231 et la sauvegarde des index.

À vous de jouer : changez la valeur brute de tension de deux mille trois cent cinq à deux mille trois cent douze. Quel affichage attendez-vous ? Deux cent trente et un virgule deux volts.

Dans la prochaine vidéo, nous allons organiser les lectures, apprendre à reconnaître une valeur invalide et voir comment le logiciel interrogera le vrai PZEM sur un banc sécurisé. »

## Checklist formateur

- [ ] Montrer d'abord la sortie fictive attendue, puis le code et la conversion.
- [ ] Ne jamais filmer un apprenant en train de câbler le secteur.
- [ ] Vérifier dans l'IDE le débit 9600 bauds et les unités du tableau.
- [ ] Chronométrer la narration et les démonstrations pour **8 minutes**.
