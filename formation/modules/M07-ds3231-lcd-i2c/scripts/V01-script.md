# M07-V01 — Script intégral : utiliser l'horloge DS3231 (7 minutes)

**AlexTech Academy · Vidéo de programmation pratique · 7 minutes cible, à chronométrer.**  
**Matériel :** Arduino Uno Rev3, DS3231 basse tension compatible, câble USB ; aucun secteur.  
Le texte entre « » est lu par le formateur ; les indications **[ÉCRAN]** et **[MANIP]** décrivent les actions de tournage. Aucun PowerPoint.

## 00:00–00:45 — Montrer le résultat final

[ÉCRAN] Moniteur série affichant une date et une heure qui changent, obtenues d'une DS3231 correctement réglée.

« Voici ce que nous voulons réaliser : afficher la date et l'heure sur notre Arduino. Lorsque je redémarre la carte, l'horloge continue à fonctionner, grâce à son dispositif de sauvegarde adapté.

Pourquoi cette étape est-elle importante pour notre compteur intelligent ? Parce que la consommation d'énergie d'aujourd'hui dépend du jour auquel nous sommes. Pour distinguer les consommations du jour et du mois, il nous faut une date fiable.

Nous allons donc utiliser le module DS3231, découvrir la communication I2C et écrire trois petits programmes progressifs. »

## 00:45–01:55 — Comprendre le bus I2C

[MANIP] Présenter les modules **hors tension** : Uno et DS3231. Montrer les repères SDA/SCL et les fils sur banc basse tension.

« Le DS3231 est une horloge temps réel, souvent appelée RTC. Ce n'est pas un compteur électrique et il ne remplace pas notre PZEM. Son rôle est de conserver la date et l'heure.

Pour le lire, nous utiliserons I2C. Ce protocole possède deux lignes principales : SDA pour les données et SCL pour l'horloge de communication. Sur notre Arduino Uno Rev3, SDA correspond à A4 et SCL à A5.

Plusieurs périphériques peuvent partager ces deux lignes, à condition que leurs adresses soient distinctes, qu'ils fonctionnent à des niveaux électriques compatibles et que le bus soit correctement câblé.

Pour la DS3231, l'adresse I2C habituelle est 0x68. Un module peut aussi posséder d'autres circuits, par exemple une EEPROM détectée à 0x57. Ne confondons pas l'adresse du module d'horloge avec celle d'un accessoire de la carte. »

## 01:55–02:55 — Étape 1 : scanner les appareils I2C

[ÉCRAN] Ouvrir `V01_01_scanner_i2c.ino`. Surligner `Wire.begin()`, la boucle d'adresses et `Wire.endTransmission()`.

« Avant d'utiliser une bibliothèque, nous voulons vérifier que notre Arduino voit bien le module. Dans le premier sketch, `Wire.begin()` démarre le bus I2C.

Le programme examine différentes adresses. Pour chaque adresse, il lance une communication et demande si un appareil a répondu. Lorsqu'il reçoit une réponse positive, il l'affiche en hexadécimal sur le moniteur série.

Sur une DS3231 fonctionnelle, nous attendons notamment 0x68. Si rien n'apparaît, il faut revoir les connexions **après avoir débranché l'USB**, l'alimentation adaptée et l'état des modules.

[MANIP] Téléverser, ouvrir le moniteur série à 9600 bauds et montrer les adresses réellement détectées. Ne pas présenter une adresse dessinée comme un essai réel. »

## 02:55–04:15 — Étape 2 : lire la date avec RTClib

[ÉCRAN] Ouvrir `V01_02_lire_ds3231.ino` et la bibliothèque Adafruit RTClib dans le gestionnaire de bibliothèques.

« Maintenant, installons la bibliothèque RTClib d'Adafruit et ses dépendances demandées par Arduino IDE. Nous créons un objet `RTC_DS3231` qui représente notre horloge.

Dans `setup`, `rtc.begin()` vérifie que l'appareil répond. Ensuite, `rtc.lostPower()` permet de savoir si l'oscillateur a été arrêté. Si la date n'est plus fiable, le programme affiche un avertissement : il ne doit pas inventer une date valide.

Lorsque l'horloge fonctionne et a été initialisée, `rtc.now()` nous renvoie un objet `DateTime`. Nous utilisons `day()`, `month()`, `year()`, `hour()`, `minute()` et `second()` pour lire les éléments de la date et de l'heure.

Nous avons volontairement ajouté un zéro devant les nombres d'un seul chiffre, pour obtenir par exemple zéro huit heures, zéro cinq minutes et zéro trois secondes. Ce format est plus lisible. »

## 04:15–05:20 — Régler l'horloge une seule fois

[ÉCRAN] Afficher `V01_03_regler_ds3231_une_fois.ino` avec `AUTORISER_REGLAGE_UNIQUE = false`.

« Mais que faire lorsque l'horloge n'est pas réglée ? Il existe une fonction `rtc.adjust()` pour lui donner une date.

C'est une opération importante, car il ne faut pas la répéter à chaque démarrage. Sinon, notre compteur risquerait de revenir constamment à une ancienne date.

Dans notre utilitaire, le réglage est donc bloqué par défaut. Pour le faire volontairement, je prépare les véritables valeurs de date et d'heure locale, puis j'active la ligne d'autorisation uniquement pour le téléversement de réglage.

Immédiatement après, je téléverse à nouveau le programme de lecture, qui ne contient aucun réglage automatique.

[MANIP] Montrer la valeur de protection, la date à saisir et la confirmation attendue. Ne pas modifier l'horloge réelle si les données ne sont pas vérifiées. »

## 05:20–06:10 — Date correcte, pile et diagnostic

[ÉCRAN] Montrer les messages « DS3231 absent » et « HEURE NON FIABLE ».

« Si le scanner ne trouve pas l'adresse 0x68, ce n'est pas un problème de calcul de date. Nous devons d'abord résoudre la communication.

Si l'appareil répond mais indique que l'horloge a perdu sa référence, nous devons vérifier le module et son dispositif de sauvegarde avant de lui faire confiance.

Attention aux cartes DS3231 vendues sous différents noms : certaines ont un circuit de recharge pour pile rechargeable. Il faut vérifier que le type de pile correspond au circuit de la carte. Ne mettez pas une pile primaire non rechargeable dans un circuit qui tente de la recharger.

Enfin, la DS3231 ne connaît pas automatiquement notre fuseau horaire : c'est à nous de définir si nous enregistrons l'heure locale ou UTC, puis de rester cohérents dans le projet. »

## 06:10–07:00 — Défi et conclusion

[ÉCRAN] Afficher une date « 07/11/2026 08:05:03 » avec les éléments à identifier.

« Voici votre exercice : modifiez l'affichage pour obtenir le format jour, mois, année, suivi de l'heure, des minutes et des secondes.

Avant de copier un corrigé, cherchez où sont utilisées les méthodes de `DateTime` et comment ajouter des zéros devant les nombres inférieurs à dix.

Retenez l'essentiel : I2C transporte nos demandes, RTClib nous simplifie la lecture du DS3231, et une date doit toujours être vérifiée avant d'être utilisée pour calculer une période de consommation.

Dans la deuxième vidéo, nous allons partager le bus I2C avec notre écran LCD vingt colonnes sur quatre lignes, afin que les informations soient visibles directement sur le compteur. »

## Contrôles de production

- [ ] Répéter narration + manipulation en 7 minutes.
- [ ] Tester physiquement les programmes **dans leur ordre**, montrer 0x68 uniquement si vraiment trouvé.
- [ ] Vérifier la carte exacte DS3231, sa pile et ses circuits avant alimentation.
- [ ] Vérifier le comportement avec RTC non initialisée **sans la régler par erreur**.
- [ ] Aucune manipulation secteur ni PZEM.
