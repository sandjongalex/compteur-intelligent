# Avant-propos — Apprendre en construisant

## Pourquoi ce livre ?

Regarder une démonstration est utile. La comprendre, l'expliquer et la reproduire est encore mieux.

Lorsqu'on découvre les microcontrôleurs et l'Internet des objets (IoT), les ressources sont nombreuses, mais souvent dispersées. Une vidéo explique l'Arduino ; une autre présente un module GSM ; une troisième montre une page web. Le débutant réussit parfois chaque exercice séparément sans savoir comment réunir les composants dans **un système unique et cohérent**.

Ce livre propose une autre méthode : partir d'une question concrète — *comment observer la consommation électrique d'une installation et consulter son historique à distance ?* — puis construire progressivement les éléments de la réponse. Chaque fonction vient enrichir le même compteur intelligent.

Nous allons découvrir les grandeurs électriques, programmer un ATmega328P, interpréter les mesures d'un PZEM-004T, lire la date d'une horloge DS3231, afficher des informations sur un LCD I2C, préparer la conservation des relevés en FRAM, communiquer grâce au GSM/GPRS et concevoir une application web avec Python Flask, SQLite et Jinja2. La conception électronique avec KiCad et la validation finale complèteront le parcours.

Le résultat recherché n'est pas seulement un montage qui affiche des chiffres. C'est la capacité à comprendre **d'où vient chaque donnée**, comment elle circule, comment vérifier sa cohérence et quelles erreurs peuvent la rendre trompeuse.

## À qui s'adresse cet ouvrage ?

Ce livre est rédigé pour les personnes qui débutent dans l'électronique et la programmation, mais aussi pour celles qui connaissent déjà Arduino et souhaitent réaliser un projet complet. Aucun prérequis en C++ ou en Python n'est nécessaire pour commencer. Il faut toutefois prévoir du temps pour répéter les expériences : une lecture seule ne remplace pas une pratique sérieuse.

Pour les débutants, nous suivrons quatre réflexes :

1. **Comprendre les mots** avant de mémoriser le code.
2. **Observer un résultat attendu** avant d'écrire le programme.
3. **Tester chaque fonction isolément**, puis l'intégrer au projet commun.
4. **Expliquer les erreurs**, et pas seulement présenter les cas où tout fonctionne.

Les exemples chiffrés et les écrans d'illustration porteront la mention **« données fictives »** lorsqu'ils ne proviennent pas d'un essai instrumenté.

## Un livre et des vidéos : deux supports complémentaires

La formation AlexTech Academy est organisée en **16 modules** et **32 vidéos techniques**, pour un total de **230 minutes**, auxquels s'ajoutent 10 minutes d'accueil et de conclusion. Les vidéos montrent les étapes essentielles dans un format volontairement court.

Le présent ouvrage suit exactement ces 16 modules, dans le même ordre. Chaque chapitre approfondit les sujets de deux vidéos : définitions, exemples résolus, schémas de principe, points de vigilance, applications pratiques et questions d'autoévaluation. **Le livre peut être étudié seul** : les explications, les exercices et leurs solutions sont conçus pour être consultés dans l'ouvrage, sans dépendre d'une plateforme ou d'un hébergement des vidéos. Les TP et les quiz supplémentaires de la formation sont proposés à part.

**Un projet fil rouge, pas seize projets différents :** les programmes des premières leçons sont des exercices d'apprentissage ; le firmware principal évolue d'un module au suivant. Lorsque nous aborderons le serveur et la carte électronique, nous continuerons à enrichir le *même* compteur.

## Ce que nous construirons — et ce que nous ne promettons pas

À terme, le prototype visé est capable de :

- lire des grandeurs électriques fournies par un module de mesure approprié ;
- dater ses relevés et calculer des consommations sur des périodes civiles ;
- afficher localement les informations essentielles ;
- conserver les relevés en attente puis les transmettre, sous réserve de l'implémentation et des essais requis ;
- recevoir, archiver et présenter ces données dans une application web.

Cette liste décrit **les fonctions que nous chercherons à construire et à valider** tout au long de l'ouvrage. Chaque étape sera étudiée selon ses exigences propres, et les exemples fictifs ne seront jamais présentés comme des essais réels.

La mesure électrique réelle, la fiabilité des relevés, la disponibilité de la connectivité mobile, la sécurité des transmissions et la conformité d'un appareil demandent des vérifications spécifiques. Un prototype pédagogique ne doit pas être utilisé comme un instrument homologué pour facturer l'électricité.

## Une règle de sécurité non négociable

Le projet touche à la mesure de l'énergie sur un réseau électrique potentiellement dangereux. **Les débutants ne raccordent pas eux-mêmes un montage au réseau 230 V** dans le cadre de ce livre. Les premières activités se font sur papier, en simulation ou avec des circuits basse tension sûrs.

Tout raccordement au secteur, essai d'isolation, choix de protections ou intervention sur une installation réelle doit être réalisé par une personne qualifiée, avec l'équipement adapté et selon les exigences réglementaires locales. Le schéma fonctionnel d'un chapitre n'est jamais une autorisation de câblage secteur.

## La promesse pédagogique

À chaque étape, nous distinguerons :

- **ce que nous savons** grâce aux définitions et aux lois physiques ;
- **ce que nous prévoyons** dans l'architecture ;
- **ce qui fonctionne en simulation** ;
- **ce qui a été vérifié par logiciel** ;
- **ce qui a réellement été testé sur matériel**.

C'est ainsi que se construit un projet reproductible. Ne cherchons pas seulement à faire fonctionner l'écran : apprenons à justifier les valeurs qu'il présente.

**Bonne lecture et bienvenue dans le projet Compteur intelligent d'AlexTech Academy.**

*Sandjong Tchoungong Alex*  
*Auteur — AlexTech Academy*

---

**Pour commencer :** rendez-vous au **chapitre 1 — Découvrir le compteur et comprendre l'électricité**.
