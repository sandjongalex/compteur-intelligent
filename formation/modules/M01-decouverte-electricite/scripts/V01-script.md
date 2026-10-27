# M01-V01 — Script intégral : Du réseau électrique au tableau de bord IoT

**Durée cible : 5 minutes** · **Format : voix + synoptique animé + démonstration simulée** · **Statut : rédigé, à chronométrer à l'enregistrement**

> Tout passage entre guillemets dans les sections minutées est un texte à prononcer. Les indications **[VISUEL]** ne sont pas prononcées.

## 00:00–00:40 — Accroche : pourquoi ce compteur ?

[VISUEL : image d'une maison, puis d'un téléphone montrant une consommation fictive.]

« Imaginez que vous puissiez consulter à distance la consommation électrique de votre maison, connaître votre consommation de la journée et comparer les mois entre eux. Vous n'auriez pas besoin d'être devant votre installation pour lire les informations.

Bonjour et bienvenue chez AlexTech Academy ! Dans cette formation, nous allons construire, étape par étape, un compteur électrique intelligent avec un microcontrôleur ATmega328P. Même si vous débutez, vous pourrez comprendre le rôle de chaque élément avant de passer au montage et à la programmation. »

## 00:40–01:25 — Ce que nous allons construire

[VISUEL : synoptique complet, éclairer une zone à la fois.]

« Regardons d'abord notre objectif final. Le compteur devra connaître la tension électrique, la puissance et la quantité d'énergie consommée. Cette énergie sera exprimée en kilowattheures, ou kWh. Il affichera aussi la date, l'énergie consommée aujourd'hui et celle consommée depuis le début du mois.

Ces informations seront visibles sur un écran LCD. Elles pourront aussi être envoyées à un serveur pour que vous consultiez leur historique depuis un navigateur web, sur ordinateur ou sur téléphone.

Notre système comporte donc plusieurs étapes. D'abord mesurer. Ensuite traiter. Puis afficher, transmettre et conserver les données. »

## 01:25–02:45 — Les composants, un par un

[VISUEL : surligner les blocs PZEM, ATmega, LCD, SIM800L et serveur.]

« Pour effectuer la mesure, nous utilisons un module appelé PZEM-004T. Ce module spécialisé nous fournit des données comme la tension, le courant, la puissance et l'index d'énergie cumulée.

Ces mesures sont lues par l'ATmega328P. Qu'est-ce qu'un microcontrôleur ? C'est un petit circuit électronique capable d'exécuter des instructions, c'est-à-dire un programme. Dans notre compteur, il reçoit les mesures, vérifie les données et calcule les consommations de la journée et du mois.

L'écran LCD vingt colonnes sur quatre lignes est notre afficheur local. Il montre les informations essentielles sans qu'il soit nécessaire de se connecter à Internet.

Une horloge DS3231 permet de connaître la date et l'heure. Une mémoire FRAM conserve les informations importantes, par exemple des relevés qui attendent d'être envoyés lorsque la connexion mobile n'est plus disponible.

Enfin, le module SIM800L sert à communiquer par le réseau GSM et GPRS, quand un réseau compatible est disponible. C'est notre lien entre le compteur et le serveur. »

## 02:45–03:40 — Du compteur au tableau de bord

[VISUEL : animer des flèches depuis le PZEM jusqu'au navigateur.]

« Prenons une valeur fictive : le PZEM nous indique une tension de deux cent trente virgule cinq volts. L'ATmega328P reçoit ce nombre. Il peut l'afficher directement sur le LCD.

Pour le suivi à distance, le microcontrôleur prépare un relevé et le confie au modem SIM800L. À travers le réseau mobile, ce relevé atteint notre application Python Flask.

Le serveur vérifie les informations et les enregistre dans SQLite, notre base de données. Une base de données est un endroit où l'on organise des informations pour pouvoir les retrouver plus tard. Enfin, notre page web, réalisée avec HTML, CSS et Jinja2, présente les derniers relevés et les graphiques de consommation.

Retenez bien cet ordre : mesure, traitement, communication, stockage et consultation. »

## 03:40–04:25 — Démonstration sans secteur

[VISUEL : afficher côte à côte un LCD illustré et la page HTML de démonstration ; mention « Données fictives ».]

« Voici un exemple. Sur l'écran, nous lisons une date, une tension de deux cent trente virgule cinq volts, quatre virgule deux cinq kilowattheures pour la journée et cent vingt-cinq virgule quatre huit pour le mois.

Sur la page web, nous retrouvons ces mêmes valeurs. Aujourd'hui, elles sont simulées : aucun branchement au secteur n'est nécessaire pour comprendre le principe. Plus tard, nous testerons chaque fonction séparément avant l'intégration, et toute manipulation du réseau deux cent trente volts sera réservée à une personne qualifiée.

Il ne faut pas confondre le module qui mesure, le microcontrôleur qui traite et le serveur qui archive. Chacun a un rôle différent. »

## 04:25–05:00 — Vérification et transition

[VISUEL : cinq cartes à remettre dans l'ordre ; laisser un bref silence.]

« À vous maintenant ! Mettez ces cinq blocs dans le bon ordre : navigateur, PZEM, serveur Flask et SQLite, ATmega328P et communication GSM. Faites une pause de quelques secondes avant d'afficher la réponse.

La bonne chaîne est : PZEM, ATmega328P, GSM, serveur, puis navigateur. L'écran LCD reste relié localement au microcontrôleur.

Vous connaissez maintenant l'architecture générale du projet. Dans la prochaine vidéo, nous allons découvrir les volts, les ampères, les watts et les kilowattheures. C'est indispensable pour comprendre les mesures de notre compteur. À tout de suite ! »

---

## Instructions de tournage

- Parler calmement, expliquer les acronymes en première occurrence et afficher leurs noms.
- Montrer le chemin des données sans dessiner de branchement secteur exploitable pour une manipulation débutante.
- Utiliser le [synoptique](../ressources/SYNOPTIQUE.md) et la [maquette web hors ligne](../ressources/demo_dashboard_fictif.html).
- Le minutage est une **cible de montage** : vérifier la durée réelle pendant la répétition et raccourcir les pauses/animations si nécessaire.
