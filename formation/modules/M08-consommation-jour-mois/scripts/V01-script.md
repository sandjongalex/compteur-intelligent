# Script complet M08-V01 — De l'index aux kWh du jour et du mois

**Objectif vidéo : 8 min · Arduino Uno Rev3 + moniteur série à 9600 bauds · aucune mesure secteur.**  
La narration est entre « » ; les mentions **[ÉCRAN]** indiquent les gestes du formateur. Durées **cibles à répéter et chronométrer**.

## 00:00–01:00 — Le problème et le résultat à produire

[ÉCRAN] Montrer un tableau de mesures **SIMULÉES** : 120,400 kWh, 120,650 kWh, 120,650 kWh, 120,900 kWh.

« Bonjour et bienvenue dans le Module 08. Nous avons appris à lire l'index du PZEM, à connaître la date avec le DS3231 et à afficher des valeurs sur un LCD. Mais une question très importante reste ouverte : comment afficher la quantité d'énergie consommée **aujourd'hui** et **ce mois-ci** ?

Voici quatre nombres fictifs. Ils représentent l'index cumulatif du compteur. Le second est plus grand que le premier. Mais lorsque le troisième est identique au second, avons-nous consommé une nouvelle quantité d'énergie ? Non : aucun nouveau delta n'a été observé.

Dans cette vidéo, nous allons transformer des index cumulatifs en petites variations d'énergie, puis cumuler ces variations sans compter la même chose plusieurs fois. »

## 01:00–02:00 — Distinguer W, Wh et kWh

[ÉCRAN] Tableau simple « Puissance : 500 W » / « Index énergie : 120,400 kWh ».

« Reprenons deux grandeurs que nous avons étudiées : la puissance active, exprimée en watts, et l'énergie, exprimée en wattheures ou en kilowattheures.

La puissance représente un rythme de consommation à un instant donné. L'énergie cumulée représente la quantité accumulée depuis un repère du compteur. Nous ne devons donc pas additionner les puissances comme si c'étaient des kilowattheures.

Le PZEM fournit précisément un **index d'énergie active cumulée**. Avec la bibliothèque Arduino choisie, la méthode `energy()` le renvoie en kilowattheures. Pour notre algorithme pédagogique, nous travaillerons en **wattheures entiers** : douze mille wattheures représentent douze kilowattheures.

Cette représentation évite les additions répétées de nombres décimaux à précision limitée sur notre ATmega328P. Nous reparlerons de la conversion et de ses limites pour les très grands index. »

## 02:00–03:15 — La formule fondamentale

[ÉCRAN] Écrire : `delta = index_nouveau - index_precedent`, puis exemple `120650 - 120400 = 250 Wh`.

« Notre calcul repose sur une soustraction très simple : l'énergie supplémentaire est égale au nouvel index moins le précédent.

Prenons un index fictif de cent vingt mille quatre cents wattheures. Une heure plus tard, il est à cent vingt mille six cent cinquante wattheures. La différence est de deux cent cinquante wattheures, soit zéro virgule deux cinq kilowattheure.

Un autre relevé annonce à nouveau cent vingt mille six cent cinquante. La différence est zéro. Ce n'est pas un nouveau paquet de deux cent cinquante wattheures.

Le principe essentiel est donc celui-ci : nous ne faisons **jamais** la somme de tous les index. Nous additionnons seulement leurs **différences successives valides**. »

## 03:15–04:45 — Construire notre premier sketch

[ÉCRAN] Ouvrir `V01_01_index_delta.ino`. Faire apparaître le tableau d'index, `precedent`, `total` et la boucle `for`, une ligne à la fois.

« Commençons à coder. Nous créons un petit tableau d'index fictifs : cent vingt mille quatre cents, cent vingt mille six cent cinquante, encore cent vingt mille six cent cinquante, cent vingt mille neuf cents, puis cent vingt et un mille cent.

Nous conservons le premier index dans la variable précédent. Pour chaque nouveau relevé, nous vérifions d'abord qu'il n'a pas diminué. S'il a diminué, nous n'appliquons pas une soustraction aveugle : le compteur a pu être réinitialisé ou remplacé.

Sinon, nous calculons la différence et l'ajoutons à notre total. Puis nous déplaçons le repère : le nouvel index devient le précédent pour le prochain passage.

[MANIP] Compiler, téléverser et montrer réellement le moniteur série, si la Uno a été testée.

Les différences attendues sont deux cent cinquante, zéro, deux cent cinquante et deux cents wattheures. Au total : sept cents wattheures, soit zéro virgule sept kilowattheure. »

## 04:45–05:55 — Associer les deltas à la journée

[ÉCRAN] Ouvrir `V01_02_cumul_jour.ino` et indiquer que tous les relevés fictifs appartiennent au **27 octobre 2026**.

« Dans notre deuxième sketch, nous faisons le même travail, mais nous expliquons maintenant le rôle de la journée.

Nous démarrons avec un index de référence pris à minuit dans notre scénario inventé. Chaque nouvelle différence valable pendant cette journée est ajoutée au compteur journalier.

Regardez le relevé dupliqué : il reste présent dans le tableau, mais il ne change pas la consommation parce que la différence est nulle. Le résultat final est toujours sept cents wattheures.

Le code compare également le dernier index à celui de départ. Cette seconde vérification permet de confirmer que la somme des deltas est cohérente lorsque l'index est continu et tous les relevés sont correctement attribués. »

## 05:55–07:05 — Deux erreurs fréquentes et limite importante

[ÉCRAN] Deux exemples incorrects barrés : `total += index` et `dernier - precedent` sur compteur réinitialisé.

« Première erreur : ajouter directement l'index total à chaque mesure. Cela compterait encore et encore toute l'énergie passée.

Deuxième erreur : laisser un index plus petit produire une valeur incohérente. Avec des entiers non signés, une soustraction à l'envers peut provoquer un nombre énorme à cause d'un débordement.

Il reste une précision importante. Même si nous calculons des différences justes, nous ne connaîtrons pas forcément **toute** la consommation de la journée si notre premier relevé arrive seulement à midi. Nous connaîtrons ce qui a été mesuré depuis ce premier relevé. Pour avoir un total depuis minuit, il faut un repère fiable au début de la période ou une méthode de réconciliation adaptée.

Nous allons apprendre à signaler clairement cette limite. »

## 07:05–08:00 — Mini-défi et transition

[ÉCRAN] Question : `120400 → 120650 → 120650 → 120900 → 121100 Wh`.

« À vous de jouer. Recopiez les cinq index, calculez les quatre différences successives et donnez le résultat en kilowattheures. Mettez la vidéo en pause avant de regarder les réponses de nos travaux pratiques.

Le résultat est sept cents wattheures, soit zéro virgule sept kilowattheure.

Nous savons maintenant calculer une consommation à partir d'un index cumulatif sans double comptage. Mais comment fait-on lorsque la date passe du trente et un janvier au premier février ? Et que devient l'état du programme après un redémarrage ?

Dans la prochaine vidéo, nous allons construire ces scénarios, reconnaître les périodes incomplètes et préparer la sauvegarde qui sera développée plus tard en FRAM. »

## Vérifications avant tournage

- [ ] Faire réellement compiler et téléverser `V01_01` et `V01_02`.
- [ ] Vérifier les deltas **250, 0, 250, 200 Wh**, total **700 Wh**.
- [ ] Expliquer la différence `W`, `Wh` et `kWh`.
- [ ] Afficher explicitement « données simulées », **aucun secteur**.
- [ ] Respecter la cible de 8 minutes après répétition.
