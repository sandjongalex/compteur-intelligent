# Charte éditoriale du livre — AlexTech Academy (production interne)

**Titre de travail :** *Concevez votre compteur électrique intelligent IoT*  
**Référence principale :** [plan de formation validé (16 modules / 32 vidéos / 4 h)](../docs/formation/PLAN_FORMATION_4H.md).  
**Document vivant :** cette charte guide la rédaction et la validation de chaque chapitre.

## 1. Principe éditorial fondamental

**Un seul compteur, un seul parcours, trois supports cohérents : livre, vidéos et code de référence.**

**GitHub est exclusivement notre outil de préparation.** Les références aux dossiers, branches, commits, scripts de tournage et états temporaires du projet n'appartiennent pas au livre publié. Le lecteur doit recevoir un ouvrage autonome, sans lien vers le dépôt de développement. Voir [PRODUCTION_INTERNE.md](PRODUCTION_INTERNE.md).

Chaque chapitre du livre correspond à **un module pédagogique** et contient deux grandes sections, une pour chaque vidéo de ce module. Le livre est volontairement plus riche et plus détaillé que les vidéos : approfondissement, schémas, calculs, questions et pratiques réalisables.

Le livre ne doit ni modifier silencieusement l'ordre du cours, ni décrire une fonctionnalité encore prévue comme si elle était déjà testée ou déployée.

Les documents suivants prévalent en cas de divergence :

1. [Plan officiel des modules](../docs/formation/PLAN_FORMATION_4H.md) pour le **contenu et l'ordre des apprentissages**.
2. [Règle d'évolution continue](../docs/formation/REGLE_EVOLUTION_CONTINUE.md) et [instructions du dépôt](../AGENTS.md) pour la **continuité technique**.
3. [Journal du firmware](../firmware/PROGRESSION.md) et les fichiers effectivement publiés pour le **niveau de réalisation**.
4. [Tableau des broches ATmega328P](../docs/hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md) pour les **affectations matérielles prévues M10–M16**.
5. Scripts, TP, quiz et ressources du module pour les **objectifs de chaque vidéo**.

## 2. Correspondance exacte des vidéos et des chapitres

| Chapitre | Section vidéo 1 | Section vidéo 2 |
|---|---|---|
| 01 | M01-V01 — Du réseau électrique au tableau de bord IoT | M01-V02 — Comprendre volts, ampères, watts et kilowattheures |
| 02 | M02-V01 — Reconnaître les composants du compteur intelligent | M02-V02 — Alimentations, protections et sécurité du 230 V |
| 03 | M03-V01 — Installer Arduino IDE et comprendre la compilation | M03-V02 — Faire clignoter une LED avec Arduino Uno |
| 04 | M04-V01 — Variables, types et calculs en C++ | M04-V02 — Conditions, boucles et fonctions |
| 05 | M05-V01 — Lire un bouton et commander une sortie | M05-V02 — Comprendre l'UART et les temporisations non bloquantes |
| 06 | M06-V01 — Comprendre le PZEM et Modbus RTU | M06-V02 — Lire et vérifier les mesures avec Arduino IDE |
| 07 | M07-V01 — Comprendre et utiliser le DS3231 | M07-V02 — Afficher les mesures sur un LCD 20×4 I2C |
| 08 | M08-V01 — Calculer l'énergie et comprendre les index | M08-V02 — Gérer minuit, les mois, les années et les redémarrages |
| 09 | M09-V01 — Construire le circuit minimal de l'ATmega328P | M09-V02 — Charger ArduinoISP et téléverser le firmware par ISP |
| 10 | M10-V01 — Tester le SIM800L et comprendre les commandes AT | M10-V02 — Transmettre une mesure par GPRS et traiter les erreurs |
| 11 | M11-V01 — Utiliser une FRAM pour conserver les relevés | M11-V02 — Reprendre les envois sans doublons |
| 12 | M12-V01 — Variables, types, conditions et fonctions Python | M12-V02 — JSON, dates, erreurs et fichiers Python |
| 13 | M13-V01 — Créer une application Flask et comprendre HTTP | M13-V02 — Créer SQLite et sécuriser l'API de réception |
| 14 | M14-V01 — Créer une interface avec Jinja2, HTML et CSS | M14-V02 — Utiliser Fetch API et Chart.js pour les historiques |
| 15 | M15-V01 — Créer le schéma et choisir les empreintes | M15-V02 — Préparer un PCB et vérifier les contraintes de sécurité |
| 16 | M16-V01 — Intégrer le firmware et tester les scénarios de panne | M16-V02 — Déployer Flask sur PythonAnywhere et valider le projet |

**Source du tableau :** [Partie C du plan officiel](../docs/formation/PLAN_FORMATION_4H.md).

Les leçons peuvent recevoir dans le livre des sous-sections supplémentaires, mais leurs thèmes doivent rester identifiables.

## 3. Gabarit de rédaction pour un chapitre

**En-tête du chapitre destiné au lecteur :** numéro, titre, niveau, estimation de la pratique autonome et consignes de sécurité. Les références vidéo sont facultatives ; les statuts de relecture restent dans les documents internes.

**Corps recommandé :**

1. Introduction par un problème concret ou une question utile.
2. Objectifs mesurables, prérequis et place dans le projet.
3. **Partie A — Vidéo V01** : explication, exemples et illustration.
4. **Partie B — Vidéo V02** : explication, exemples et illustration.
5. Synthèse : ce qui a été appris et ce qui sera réutilisé.
6. Une ou plusieurs **activités réalisables** sans improviser des manipulations dangereuses.
7. Quiz et questions de contrôle autonomes, avec corrigés dans une annexe du livre ; TP supplémentaires de formation facultatifs.
8. Dépannage / erreurs fréquentes, lorsque pertinent.
9. Renvois pérennes aux chapitres, figures et annexes du livre, sans dépendance à GitHub ou à des scripts de production.

**Exigence particulière pour les chapitres de programmation :** donner un résultat attendu, montrer le code précédent, introduire de petites modifications compréhensibles, justifier chaque nouvelle instruction, comparer aux sorties attendues et documenter les essais exécutés ou restant à faire. Les extraits indispensables figurent dans l'ouvrage. Les programmes complets nécessaires à sa compréhension sont inclus dans les annexes appropriées. Des fichiers téléchargeables complémentaires pourront être proposés par un canal distinct, sans imposer GitHub au lecteur.

## 4. Langue, notations et exemples

- Écrire en **français clair** pour un public débutant, sans supprimer la rigueur des unités et du vocabulaire technique.
- Introduire chaque acronyme à sa première occurrence : RTC, UART, I2C, ISP, GSM, GPRS, API, etc.
- Écrire `230,5 V`, `0,5 kW`, `1 kWh` dans la prose française ; conserver les valeurs et séparateurs syntaxiques nécessaires dans les exemples de code.
- Distinguer **puissance active (W)**, **puissance apparente (VA)**, **énergie (Wh/kWh)** et **index cumulatif**.
- Préciser les **hypothèses** : puissance constante, données simulées, date de référence connue, composant réellement alimenté ou non.
- Dater le **statut de validation** lorsque cela modifie l'interprétation ; ne pas convertir « prévu », « simulé », « compilé » et « testé sur matériel » en synonymes.
- Prévoir des figures numérotées, des légendes informatives, des textes alternatifs pour les futures images et la provenance/droits des illustrations externes.
- Les codes sources ne doivent **jamais** contenir de secrets, identifiants ou clés réelles. Les exemples du livre n'exposent ni adresses privées ni liens vers notre espace de développement.

## 5. Règles techniques et de sécurité

- **Secteur 230 V :** aucune procédure de câblage sous tension pour les débutants. Les travaux réels sur le secteur sont réservés à un personnel qualifié avec protections adaptées.
- **SIM800L :** futur UART matériel D0/D1, conversion de niveaux dans les deux sens et alimentation adaptée à la carte réelle ; ne jamais affirmer qu'un modem nu accepte directement 5 V sur VBAT.
- **PZEM :** `SoftwareSerial` D10/D11 ; D11/MOSI partage la programmation ISP et nécessite une stratégie d'isolation pendant les opérations concernées.
- **RTC DS3231 / LCD / FRAM :** bus I2C sur A4/A5 ; adresses, tensions et résistances de rappel à vérifier sur les modules physiques.
- **Énergie jour/mois :** ne pas déduire un total exact si l'index est remis à zéro, si la date est absente ou si une frontière de période manque. Signaler les périodes partielles.
- **Communication et stockage :** ne pas promettre une reprise sans doublon ni un transfert sécurisé tant que les implémentations et tests correspondants ne sont pas disponibles.
- **Diffusion :** prototype éducatif de suivi énergétique, pas compteur de facturation homologué.

## 6. Relectures et validation

Un chapitre doit passer successivement par les états suivants :

1. **Brouillon** : texte et illustrations provisoires.
2. **Relecture technique** : unités, schémas, brochage, statut réel du code, sécurité et cohérence avec la référence du dépôt.
3. **Relecture pédagogique** : clarté pour débutants, exercices vérifiables et progression sans saut injustifié.
4. **Révision éditoriale** : orthographe, titres, illustrations et homogénéité.
5. **Bon à composer** : mise en page et création de la version PDF / impression.
6. **Publié** : édition datée, errata et traçabilité des changements.

**Aucun chapitre n'est considéré validé uniquement parce qu'il se trouve sur GitHub.**

### Contrôle rapide avant de fusionner une rédaction

- [ ] Un chapitre = un module ; les deux vidéos sont représentées.
- [ ] Les définitions, exemples et résultats numériques ont été vérifiés.
- [ ] Les exemples fictifs sont signalés.
- [ ] La sécurité n'est pas sous-estimée.
- [ ] Les liens internes renvoient aux bons fichiers.
- [ ] Le chapitre respecte la progression du **même compteur**.
- [ ] Aucune nouveauté future n'est décrite comme matériellement validée.
- [ ] La navigation et le statut du sommaire ont été actualisés.

## 7. Organisation dans le dépôt

~~~text
livre/
├── README.md             # Page d'accueil, sommaire, avancement
├── PLAN_EDITORIAL.md     # Présente charte
├── 00-avant-propos.md    # Introduction générale
└── chapitres/
    ├── 01-decouvrir-le-compteur-et-comprendre-l-electricite.md
    └── ...               # M02 à M16 créés au fur et à mesure
~~~

Les figures sources et les futurs exports pourront être ajoutés plus tard sans modifier le plan. **Ne pas générer quinze faux chapitres vides.** Rédiger et contrôler module par module.

[← Revenir au sommaire](README.md)
