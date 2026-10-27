# M07-V02 — Script intégral : afficher les données sur LCD I2C 20×4 (7 minutes)

**AlexTech Academy · Démonstration directe sur Arduino IDE et LCD · cible 7 minutes.**  
Les passages entre « » sont à prononcer ; **[ÉCRAN]** et **[MANIP]** guident le tournage. Aucun PowerPoint.

## 00:00–00:45 — Le résultat attendu en premier

[MANIP] LCD 20×4 de démonstration, alimentation basse tension validée. Montrer les quatre lignes prévues.

« Regardez maintenant notre compteur : quatre lignes apparaissent directement sur l'écran. En haut, la date ; ensuite, la tension ; sur la troisième ligne, la consommation de la journée ; et sur la dernière, celle du mois.

Les valeurs d'énergie et de tension que vous voyez sont **fictives**. Elles servent à apprendre l'affichage. La consommation réelle du jour et du mois sera calculée dans le module suivant, à partir de l'index cumulatif du PZEM.

Aujourd'hui, nous allons faire fonctionner l'écran, organiser les quatre lignes et afficher la date fournie par le DS3231. »

## 00:45–01:50 — Comprendre LCD 20×4 et adresse I2C

[ÉCRAN] Photo hors tension du LCD et de sa petite carte adaptatrice ; annotation « 20 colonnes, 4 lignes ».

« Notre LCD peut afficher vingt caractères sur chacune de ses quatre lignes. Dans le programme, la première colonne porte le numéro zéro ; les colonnes vont donc de zéro à dix-neuf. Pour les lignes, les numéros vont de zéro à trois.

Le petit module à l'arrière de l'écran utilise I2C. Nous retrouvons SDA et SCL, partagés avec l'horloge DS3231 lorsque les composants et leurs niveaux électriques sont compatibles.

L'adresse du LCD dépend de son adaptateur : elle n'est pas toujours identique d'un fabricant à l'autre. Nous utiliserons la bibliothèque `hd44780`, avec sa classe `hd44780_I2Cexp`, capable de détecter automatiquement l'adresse et le mappage de nombreux adaptateurs compatibles.

Si l'écran ne répond pas, nous utiliserons l'exemple de diagnostic `I2CexpDiag` de cette bibliothèque plutôt que de deviner une adresse. »

## 01:50–02:50 — Étape 1 : afficher un premier texte

[ÉCRAN] Ouvrir `V02_01_lcd_bonjour.ino`, surligner `lcd.begin(20,4)`, `backlight()`, `setCursor`.

« Dans notre premier sketch, nous initialisons le bus avec `Wire.begin()` et l'écran avec `lcd.begin(20,4)`.

La bibliothèque renvoie un code d'état. Si elle ne peut pas initialiser l'écran, nous affichons un message d'erreur dans le moniteur série au lieu d'agir comme si tout fonctionnait.

Lorsqu'elle réussit, `lcd.backlight()` active le rétroéclairage si notre carte le permet.

Avec `lcd.setCursor(0,0)`, nous plaçons le curseur au début de la première ligne. Puis `lcd.print()` écrit le texte. Nous répétons pour les lignes un, deux et trois.

[MANIP] Téléverser et lire le résultat réel sur l'écran. Si les lettres sont invisibles, vérifier également le contraste de l'adaptateur, sans manipuler de partie secteur. »

## 02:50–04:00 — Étape 2 : organiser les quatre valeurs

[ÉCRAN] Ouvrir `V02_02_lcd_4_lignes_simulees.ino`. Zoomer sur la maquette de l'écran et les appels `ligneComplete`.

« Nous remplaçons les messages de bienvenue par les quatre informations de notre compteur.

Première ligne : DATE, avec un exemple de date fixe. Deuxième : TENSION, deux cent trente virgule cinq volts. Troisième : JOUR, quatre virgule deux cinq kilowattheures. Quatrième : MOIS, cent vingt-cinq virgule quatre huit kilowattheures.

Attention : ici, ces quatre nombres et cette date sont écrits dans le sketch. Ce sont des **données fictives** ; aucune valeur ne provient encore du PZEM ou du DS3231.

Pourquoi utilisons-nous une fonction appelée `ligneComplete` ? Pour produire exactement vingt caractères, en ajoutant des espaces à la fin si nécessaire. Ainsi, quand une valeur plus courte remplace une valeur longue, il ne reste pas de vieux caractères sur l'écran.

Ce petit choix de programmation évite plusieurs défauts visuels. »

## 04:00–05:25 — Étape 3 : date DS3231 et rafraîchissement propre

[ÉCRAN] Ouvrir `V02_03_rtc_lcd_integres.ino`. Montrer les deux objets `rtc` et `lcd`, puis la logique `millis()`.

« Dans la dernière étape, nous réunissons les deux périphériques. L'horloge DS3231 et l'écran LCD partagent SDA et SCL. Chacun possède une adresse différente.

Le programme vérifie d'abord la présence de l'écran. Il vérifie ensuite l'horloge. Si sa date est fiable, `rtc.now()` nous fournit l'année, le mois et le jour, que nous affichons sur la première ligne.

Si la date est invalide, nous indiquons DATE A REGLER ou DATE INVALIDE. Nous préférons ce message à une date inventée, car plus tard une mauvaise date entraînerait de mauvais cumuls journaliers.

Nous actualisons la date à intervalles réguliers grâce à `millis()`. Nous n'utilisons pas `lcd.clear()` dans la boucle principale. Effacer entièrement l'écran à chaque tour pourrait provoquer un scintillement visible. Nous réécrivons plutôt la ligne concernée, en laissant les autres lignes intactes.

La tension, le jour et le mois restent simulés jusqu'au prochain module. »

## 05:25–06:15 — Tester et diagnostiquer l'affichage

[MANIP] Montrer successivement un écran fonctionnel puis le guide de diagnostic.

« Pour vérifier notre système, nous observons d'abord si les quatre lignes sont lisibles et tiennent dans vingt colonnes.

Si rien ne s'affiche, nous vérifions l'alimentation, le contraste et le diagnostic I2C ; si la date ne s'affiche pas, nous vérifions l'horloge, sans forcer son réglage à chaque démarrage.

Si des caractères restent sur une ligne après modification, cela signifie souvent que nous n'avons pas remplacé les caractères de l'ancienne valeur.

Et si l'écran clignote, nous cherchons d'abord un `lcd.clear()` exécuté trop souvent, ou une actualisation inutile de toutes les lignes. »

## 06:15–07:00 — Exercice et transition

[ÉCRAN] Présenter deux pages fictives : page 1 date/tension/énergies, page 2 courant/puissance.

« Votre défi consiste à ajouter une deuxième page, sans modifier le calcul des mesures. Sur cette nouvelle page, affichez un courant fictif de zéro virgule cinq ampère et une puissance fictive de quatre-vingt-douze virgule deux watts.

Vous pouvez réutiliser le bouton étudié au Module 05 pour passer d'une page à l'autre. Un corrigé complet est disponible séparément.

Nous savons maintenant récupérer la date, la vérifier et afficher quatre lignes lisibles sur notre LCD. Il reste une étape essentielle : transformer l'index énergétique cumulatif en consommations réelles du jour et du mois. C'est exactement ce que nous apprendrons au Module 08. »

## Contrôles de production

- [ ] Chronométrer pour obtenir 7 minutes.
- [ ] Vérifier physiquement la compatibilité I2C et les niveaux avant raccordement USB.
- [ ] Vérifier fonctionnement de `hd44780_I2Cexp`, initialisation 20×4 et contraste.
- [ ] Tester comportement RTC absente / heure perdue.
- [ ] Indiquer à l'écran les **mesures fictives** sans laisser entendre qu'il s'agit de données du PZEM.
- [ ] Ne pas annoncer les kWh jour/mois comme calculés avant M08.
