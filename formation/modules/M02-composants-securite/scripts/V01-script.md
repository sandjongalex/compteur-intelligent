# M02-V01 — Script intégral : Reconnaître les composants du compteur intelligent

**Objectif :** l'apprenant identifie les principaux éléments et sait expliquer leur rôle.
**Durée vidéo cible : 5 min.**
**Statut : texte prêt pour répétition et chronométrage.**
Les indications **[À l'écran]** sont des consignes de mise en scène, non prononcées.

## 00:00–00:40 — Introduction
[À l'écran : tous les composants disposés sur une table, entièrement hors tension.]

« Avant de construire un circuit, nous devons savoir à quoi sert chaque composant et pourquoi il est présent. Bienvenue dans ce deuxième module d'AlexTech Academy. Dans la vidéo précédente, nous avons découvert comment notre compteur envoie ses informations vers une application web. Maintenant, nous allons mettre des noms sur les différents éléments du système.

Pensez à notre compteur comme à une petite équipe : certains éléments mesurent, d'autres réfléchissent, mémorisent, affichent ou transmettent des informations. Aucun composant ne peut à lui seul remplir toutes ces fonctions. »

## 00:40–01:35 — ATmega328P et PZEM-004T
[À l'écran : photographies ou gros plans des deux pièces avec leurs noms.]

« Commençons par l'ATmega328P. C'est notre microcontrôleur. Un microcontrôleur est un circuit intégré programmable : il exécute les instructions que nous lui donnons. Ici, il va lire les mesures, effectuer des calculs et commander les autres éléments.

Pendant le développement, nous écrirons nos programmes dans Arduino IDE et nous utiliserons une carte Arduino Uno pour apprendre et programmer notre ATmega. Le produit final pourra ensuite fonctionner avec la puce seule, sur son propre circuit.

À côté, voici le PZEM-004T, version 3.0. C'est lui qui fournit les mesures électriques : tension, courant, puissance et énergie. Le microcontrôleur ne remplace pas le PZEM. Il utilise ses données pour calculer les consommations du jour et du mois. Le PZEM et son capteur de courant ne doivent être associés au secteur que dans un montage conçu et vérifié par une personne qualifiée. »

## 01:35–02:35 — Date, mémoire et LCD
[À l'écran : trois cartes DS3231, FRAM, LCD ; puis un exemple d'affichage.]

« Pour connaître le jour et le mois, il nous faut une horloge. Nous utiliserons le DS3231, un module d'horloge temps réel. Grâce à une pile de sauvegarde adaptée, il peut conserver la date et l'heure lorsqu'on coupe l'alimentation principale.

Mais une horloge ne mémorise pas nos historiques de consommation. Pour cela, nous ajouterons une mémoire FRAM. C'est une mémoire non volatile : elle garde les données importantes, même quand le courant est coupé. Elle aidera aussi à conserver les relevés qui n'ont pas encore été transmis.

Enfin, pour afficher les valeurs, nous utiliserons un LCD de vingt colonnes sur quatre lignes, avec une interface I2C. Il pourra présenter quatre informations essentielles : la date, la tension, l'énergie consommée aujourd'hui et celle du mois. Les échanges I2C seront expliqués plus tard, pas besoin de les maîtriser maintenant. »

## 02:35–03:20 — SIM800L
[À l'écran : SIM800L, icône réseau mobile, serveur Flask.]

« Le module SIM800L est notre modem. Un modem est un équipement qui échange des données avec un réseau de communication. Dans notre projet, il servira à envoyer les relevés par GSM et GPRS vers un serveur Python Flask. Ce serveur les enregistrera dans une base SQLite et les mettra à disposition sur une interface web.

Le SIM800L utilise les réseaux mobiles 2G compatibles : nous devrons vérifier que cette technologie est disponible là où le compteur sera installé. Il faudra aussi lui fournir une alimentation spécifique, différente du cinq volts de la carte Arduino. Nous verrons cela dans quelques instants. »

## 03:20–04:20 — Les petits composants
[À l'écran : résistance, LED, bouton, buzzer, condensateur et quartz.]

« Nous aurons aussi des composants plus petits, mais indispensables. Une LED pourra indiquer l'état du compteur. Un buzzer pourra signaler certaines alertes. Un bouton permettra de changer la page de l'écran.

Les résistances servent notamment à limiter le courant ou à définir un niveau électrique. Les condensateurs contribuent au filtrage et au découplage des alimentations, ce qui réduit certaines perturbations. Enfin, un quartz adapté aidera notre ATmega328P à fonctionner à seize mégahertz, selon sa configuration.

Retenez ceci : le rôle d'un composant compte plus que sa taille. Et avant de le raccorder, vérifiez toujours la référence exacte et le brochage de votre modèle. Deux modules visuellement proches ne sont pas forcément identiques. »

## 04:20–05:00 — Vérification
[À l'écran : associations de mots, puis correction.]

« Petit exercice. Quel composant garde la date : le PZEM ou le DS3231 ? Réponse : le DS3231. Quel composant assure la communication GSM : la FRAM ou le SIM800L ? Réponse : le SIM800L. Et qui réalise les calculs ? Notre ATmega328P.

Nous savons maintenant identifier les pièces du compteur. Dans la prochaine vidéo, nous allons comprendre leurs tensions d'alimentation et surtout les précautions indispensables pour ne pas endommager les modules ni nous mettre en danger. »

### Notes au formateur
- Montrer les références réelles des modules **hors tension** ; pas de montage 230 V.
- Les noms de broches détaillés sont reportés aux modules de programmation.
- Le rythme doit être validé par une répétition chronométrée, les 5 minutes sont une **cible de montage**, pas un temps déjà mesuré.
