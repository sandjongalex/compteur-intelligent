# Script complet M08-V02 — Minuit, nouveau mois, reboot et périodes incomplètes

**Objectif vidéo : 8 min · exemples simulés puis DS3231 + LCD basse tension.**  
Les phrases entre « » sont à prononcer. Les annotations **[ÉCRAN]** sont des gestes de tournage. Aucune démonstration secteur.

## 00:00–00:55 — Le passage critique du calendrier

[ÉCRAN] Tableau : `31/01 23:59 → 01/02 00:00`, index fictifs en Wh.

« Imaginons que notre compteur fonctionne le trente et un janvier à vingt-trois heures cinquante-neuf. Dans une minute, la date sera le premier février.

Le PZEM ne doit pas être remis à zéro. Son index représente un cumul continu. En revanche, notre application doit démarrer un nouveau compteur du jour et un nouveau compteur du mois.

Il faut aussi réfléchir à une situation moins évidente : si la dernière mesure a été faite le trente et un janvier à vingt-trois heures cinquante-neuf et que la suivante arrive à minuit cinq, nous ne pouvons pas savoir quelle partie de l'énergie a été consommée avant et après minuit.

Une bonne application doit le reconnaître au lieu de répartir les kilowattheures au hasard. »

## 00:55–02:10 — Date du DS3231 et index PZEM

[ÉCRAN] Montrer un relevé logique `{année, mois, jour, heure, minute, seconde, indexWh, valide}`.

« Notre unité de travail ne sera plus simplement un nombre. Ce sera un **relevé daté** : une date, une heure, un index cumulatif et un indicateur de validité.

La date vient normalement du DS3231. L'énergie vient du PZEM. Mais, pour comprendre la logique en toute sécurité, nous allons créer des valeurs fictives dans un tableau.

Nous distinguons deux compteurs logiciels : celui du jour et celui du mois. Ils ne remplacent pas l'index du PZEM, qui garde sa valeur globale.

Quand la date reste dans la même journée, la différence d'index contribue à la journée et au mois. Quand la date change, nous commençons une nouvelle journée. Et lorsque le mois change également, nous commençons un nouveau mois. »

## 02:10–03:20 — Étape 1 : coder janvier → février

[ÉCRAN] Ouvrir `V02_01_passer_au_mois.ino` et son petit moteur `EnergieM08.h`.

« Voici notre première simulation du changement de mois. Le trente et un janvier à vingt-trois heures cinquante-huit, notre index vaut cent vingt mille quatre cents wattheures. À vingt-trois heures cinquante-neuf, il vaut cent vingt mille six cent cinquante : nous avons observé un delta de deux cent cinquante wattheures.

Le premier février, à minuit exactement dans notre scénario, l'index vaut cent vingt mille six cent soixante. Nous conservons cet index comme nouvelle base de février.

À minuit cinq, l'index vaut cent vingt mille sept cents. Le mois et le jour enregistrent quarante wattheures supplémentaires. À minuit six, l'index vaut cent vingt mille sept cent quarante : les deux cumuls valent quatre-vingts wattheures.

Le moteur ne compte pas les dix wattheures qui séparent vingt-trois heures cinquante-neuf de minuit. Sans mesure à l'instant exact de consommation, ils appartiennent à une frontière de période et nous ne les attribuons pas arbitrairement. »

## 03:20–04:30 — Gérer les périodes partielles

[ÉCRAN] Montrer les indicateurs `jourComplet` et `moisComplet`.

« Voici deux variables importantes : jourComplet et moisComplet. Elles indiquent si nous disposons d'une base de référence exactement à l'ouverture de la période et si aucun problème connu n'a rompu le suivi.

Si notre première lecture du premier février arrive à zéro heure zéro cinq, la consommation entre minuit et zéro heure zéro cinq n'est pas connue pour cette journée. Notre cumul du jour est donc marqué **partiel**.

Par contre, si nous traversons seulement minuit sans changer de mois, la totalité du delta observé entre les deux relevés reste dans le même mois, tant que l'index n'a pas été réinitialisé. On peut donc conserver le cumul mensuel même si le journalier devient partiel.

Ces indicateurs empêchent le tableau de bord d'afficher un faux zéro comme s'il représentait une journée complète. »

## 04:30–05:55 — Étape 2 : reprendre après redémarrage

[ÉCRAN] Ouvrir `V02_02_reprise_et_erreurs.ino`.

« Une autre difficulté est le redémarrage du microcontrôleur. Dans cette démonstration, nous copions notre état dans une variable appelée sauvegardeRAM, puis nous créons un nouvel objet de suivi et restaurons cette copie.

Une fois restauré, si le même relevé arrive encore, il est reconnu comme doublon et ne compte pas deux fois. Puis un nouvel index augmente les cumuls normalement.

Mais attention à la distinction : **une copie dans la RAM n'est pas une sauvegarde durable**. Lors d'une vraie coupure complète, la RAM de l'ATmega perd cet état.

Nous préparerons dans le Module 11 le stockage en FRAM avec protection contre les données incomplètes ou corrompues. Le code d'aujourd'hui explique la logique de reprise, sans prétendre résister déjà à une coupure électrique. »

## 05:55–06:55 — Anomalies : compteur et horloge

[ÉCRAN] Montrer les messages `INDEX REINITIALISE`, `TEMPS INCOHERENT`, `DOUBLON`.

« Voyons enfin trois erreurs. Si un relevé possède exactement la même date, la même heure et le même index, c'est un doublon : nous ne l'ajoutons pas.

Si l'index diminue, le PZEM a peut-être été réinitialisé ou remplacé. Nous créons alors une nouvelle base et marquons les périodes comme incomplètes, au lieu d'afficher une soustraction absurde.

Si l'horloge revient en arrière, nous rejetons le relevé tant que la date n'est pas redevenue cohérente. Une mauvaise date pourrait attribuer la consommation au mauvais jour ou au mauvais mois.

Il peut aussi manquer un relevé pendant une coupure : ce n'est pas la même chose qu'une consommation nulle. »

## 06:55–07:35 — Voir les cumuls sur un vrai LCD sans secteur

[ÉCRAN] Ouvrir `V02_03_ds3231_lcd_fictif.ino`. Montrer LCD basse tension si disponible.

« Nous pouvons maintenant réutiliser notre DS3231 et notre LCD du module précédent. Dans cet exemple, **la date vient de la vraie horloge**, mais la tension et l'index énergétique restent entièrement simulés.

Le code affiche la date, une tension fictive et les cumuls du jour et du mois. Le symbole tilde, ce petit signe ondulé, indique que la période est **partielle**, par exemple si le programme a démarré bien après minuit.

Nous n'avons donc besoin d'aucune prise secteur pour expliquer l'algorithme et son affichage. »

## 07:35–08:00 — Défi et transition

« Voici votre défi : observez les index de janvier et de février, calculez vous-mêmes les deltas et expliquez pourquoi un premier relevé à zéro heure cinq ne constitue pas une base exacte de minuit.

Nous avons construit la logique des consommations par jour et par mois. Dans le prochain module, nous programmerons l'ATmega328P en mode autonome. Et plus tard, nous rendrons ces cumuls persistants avec la FRAM, même après une vraie coupure de l'alimentation. »

## Avant d'enregistrer

- [ ] Vérifier les scénarios du moteur et les affichages attendus.
- [ ] Ne jamais confondre **copie RAM** avec **sauvegarde FRAM effective**.
- [ ] Relevés fictifs explicitement identifiés ; DS3231/LCD seulement en basse tension.
- [ ] Vérifier la vraie carte Arduino et les dépendances RTClib/hd44780.
- [ ] Chronométrer narration et manipulation pour **8 minutes**.
