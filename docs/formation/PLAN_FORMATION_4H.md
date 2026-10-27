<!-- Plan détaillé issu du document pédagogique fourni pour la formation de quatre heures. -->

# Formation AlexTech Academy : concevoir un compteur électrique intelligent connecté
> **Titre commercial proposé :** « Compteur électrique intelligent avec ATmega328P, GSM/GPRS et Python — De la mesure au tableau de bord IoT »

La contrainte de durée change profondément la conception pédagogique : tu souhaites une formation complète sur un projet qui mobilise l'électronique, les microcontrôleurs, les communications, la conception de circuits et le développement web, tout en limitant la durée totale à 4 heures maximum.

Il faut donc distinguer deux objectifs :
- Formation vidéo de 4 heures : apprendre les principes essentiels, suivre les démonstrations et reproduire une architecture fonctionnelle guidée.
- Maîtrise autonome du projet : réaliser, tester, sécuriser et dépanner chaque partie sans aide. Cela demandera du travail pratique supplémentaire en dehors des vidéos.
Je recommande de conserver les technologies que tu as imposées, de ne supprimer aucune étape technique essentielle et de limiter la durée vidéo en séparant les explications des exercices autonomes.
## Fiche de conception pédagogique
Durée maximale
4 h
240 minutes de vidéo

Organisation proposée
16 modules
Du débutant au prototype connecté

Format
Vidéos courtes
Environ 5 à 12 minutes

Évaluation
80 %
Seuil de réussite des quiz

Positionnement recommandé : une formation pratique accélérée, avec des codes sources fournis, un montage de référence, des tests guidés et des exercices complémentaires téléchargeables.

## Partie A — Analyse pédagogique du projet
A1. Difficulté globale
Projet multidisciplinaire
Le projet rassemble six domaines qui demandent normalement plusieurs formations distinctes.

1. Électronique et électricité

Tension, courant, puissance, énergie, composants, alimentation et sécurité du secteur.

2. Systèmes embarqués

C/C++, Arduino IDE, UART, I2C, Modbus RTU, interruptions, EEPROM/FRAM et ISP.

3. Communication IoT

Commandes AT, carte SIM, réseau 2G, connexion GPRS, API et reprise après coupure.

4. Développement logiciel et web

Python, Flask, SQLite, HTML, CSS, JavaScript, Jinja2 et Chart.js.

5. Conception électronique

Schémas, implantation PCB, alimentation, découplage, connecteurs et protections.

La difficulté n'est pas seulement de comprendre chaque composant. Elle consiste surtout à faire communiquer correctement toutes les parties, sans perte de données ni danger électrique.
A2. Public cible et prérequis
- Débutants absolus en électronique et en programmation.
- Étudiants en électronique, électrotechnique et informatique.
- Techniciens souhaitant découvrir l'IoT.
- Développeurs souhaitant comprendre les systèmes embarqués.
Prérequis : savoir utiliser un ordinateur, gérer des fichiers et naviguer sur Internet. Aucun prérequis en programmation n'est exigé.

Le cours de quatre heures doit cependant s'appuyer sur des ressources préparées à l'avance : firmware de référence, projet Flask de démonstration, schémas, jeux de données et exercices corrigés. Les apprenants ne peuvent pas raisonnablement construire chaque élément depuis zéro en quatre heures.
A3. Objectifs généraux
À la fin des vidéos, l'apprenant devra pouvoir :
1. Expliquer le fonctionnement général du compteur connecté.
2. Identifier les composants et leurs fonctions.
3. Programmer un ATmega328P avec Arduino IDE.
4. Lire les mesures du PZEM-004T et les afficher sur LCD.
5. Comprendre le calcul des consommations journalières et mensuelles.
6. Expliquer la programmation autonome par ISP.
7. Comprendre les échanges avec le SIM800L.
8. Suivre les données jusqu'à leur stockage dans SQLite.
9. Consulter les historiques sur une interface web.
10. Tester les scénarios de panne, de reprise et de synchronisation.
A4. Risques pédagogiques
| Risque | Mesure préventive |
| --- | --- |
| Trop de notions nouvelles | Une notion principale par vidéo |
| Code difficile à comprendre | Partir d'un exemple simple et le modifier progressivement |
| Confusion entre puissance et énergie | Exercices numériques avant le firmware complet |
| Pertes de données | Introduire les identifiants uniques et la persistance avant la synchronisation |
| Difficultés de câblage | Fournir des schémas annotés et des tests par étapes |
| Danger du 230 V | Démonstrations secteur réservées à une personne qualifiée |
| Absence de réseau 2G | Simulateur de modem et tests de transmission reproductibles |

A5. Stratégie pédagogique
Chaque vidéo suivra cette séquence :
1. Problème concret : ce que nous cherchons à résoudre.
2. Explication : définition des nouveaux termes.
3. Illustration : schéma ou exemple de la vie quotidienne.
4. Démonstration : code, montage ou manipulation logicielle.
5. Vérification : résultat attendu et erreurs à éviter.
6. Exercice : une tâche courte pour vérifier la compréhension.
Les vidéos ne contiendront pas systématiquement une longue séance de programmation en direct. Les projets complets seront fournis en fichiers téléchargeables et expliqués progressivement.

## Partie B — Architecture générale de la formation
B1. Durée et découpage
Durée des leçons techniques
230 min

Accueil et conclusion
10 min

Total : 240 minutes, soit exactement 4 heures de vidéo, hors pauses, exercices autonomes et quiz réalisés par l'apprenant.

Je recommande 32 vidéos techniques courtes, réparties dans 16 modules, avec une durée moyenne de 7 à 8 minutes. L'accueil et la conclusion occupent cinq minutes chacun.

Cette durée ne comprend pas le temps personnel nécessaire pour réaliser les exercices, installer les logiciels ou fabriquer le circuit.
B2. Vue d'ensemble des modules
| Module | Thème | Durée |
| --- | --- | --- |
| M01 | Découverte du projet et bases électriques | 10 min |
| M02 | Composants, alimentation et sécurité | 10 min |
| M03 | Arduino IDE et premier programme | 14 min |
| M04 | Bases du C/C++ pour microcontrôleurs | 14 min |
| M05 | Entrées, sorties et communications série | 18 min |
| M06 | PZEM-004T et mesures électriques | 16 min |
| M07 | DS3231 et LCD I2C | 14 min |
| M08 | Calcul fiable des consommations | 16 min |
| M09 | ATmega328P autonome et ISP | 16 min |
| M10 | SIM800L et commandes AT | 14 min |
| M11 | FRAM, stockage local et synchronisation | 16 min |
| M12 | Fondamentaux Python | 14 min |
| M13 | Flask, SQLite et API de réception | 16 min |
| M14 | Tableau de bord web et graphiques | 16 min |
| M15 | Conception électronique et KiCad | 12 min |
| M16 | Intégration, tests et déploiement | 14 min |
| Total technique |  | 230 min |
| Accueil et conclusion |  | 10 min |
| Total général |  | 240 min |

B3. Dépendances pédagogiques
\`\`\`mermaid
flowchart TD
  A["M01–M02 : Bases et sécurité"] --> B["M03–M05 : Programmation"]
  B --> C["M06–M08 : Mesure et énergie"]
  C --> D["M09 : ATmega328P autonome"]
  D --> E["M10–M11 : GSM et fiabilité"]
  E --> F["M12–M14 : Python et plateforme web"]
  F --> G["M15 : Schéma et PCB"]
  G --> H["M16 : Intégration et validation"]
\`\`\`

Important : ce parcours enseigne une architecture complète, mais le cours accéléré ne remplace pas les séances de validation physique. La version finale du compteur doit être testée par étapes, particulièrement pour le secteur, les alimentations et les communications.

## Partie C — Programme complet et détaillé
### Module M01 — Découvrir le compteur et comprendre l'électricité

Objectif : comprendre ce que le système mesure et comment les grandeurs électriques sont liées.

Prérequis : aucun. Durée : 10 minutes. Support : présentation illustrée et simulation numérique.


#### Vidéo M01-V01 — Du réseau électrique au tableau de bord IoT (5 min)
- Objectif pédagogique : comprendre le trajet d'une mesure depuis le circuit électrique jusqu'au navigateur.
- Introduction à prononcer : « Imaginez que vous puissiez consulter à distance la consommation électrique d'une installation, connaître son historique et détecter une anomalie. Nous allons construire un système qui rend cela possible. »
- Plan détaillé :
  1. Définir un compteur et un système de supervision.
  2. Distinguer mesure, calcul, stockage et affichage.
  3. Présenter le rôle du PZEM, de l'ATmega328P, du SIM800L et du serveur.
  4. Montrer le parcours des données : mesure → microcontrôleur → réseau → base de données → navigateur.
- Analogie : le PZEM est le capteur, l'ATmega328P est le gestionnaire, le réseau est le transporteur et le serveur est l'archiviste.
- Visuels : synoptique animé et photo des principaux modules.
- Démonstration : afficher une mesure fictive de 230,5 V et suivre son parcours jusqu'à une page web.
- Erreurs à expliquer : confondre capteur, calculateur et serveur.
- Résultat attendu : l'apprenant peut expliquer le rôle de chaque bloc.
- Mini-exercice : remettre les cinq blocs du système dans le bon ordre.
- Transition : avant de mesurer, il faut comprendre ce que signifient les valeurs électriques.
#### Vidéo M01-V02 — Comprendre volts, ampères, watts et kilowattheures (5 min)
- Objectif : distinguer tension, courant, puissance et énergie.
- Niveau : débutant absolu.
- Introduction : « Un appareil peut consommer beaucoup de puissance pendant quelques minutes ou peu de puissance pendant plusieurs heures. Pour comprendre sa consommation, nous devons distinguer puissance et énergie. »
- Plan :
  1. Définir la tension en volts (V).
  2. Définir le courant en ampères (A).
  3. Définir la puissance en watts (W).
  4. Définir l'énergie en Wh et kWh.
  5. Présenter l'énergie comme une puissance accumulée au cours du temps.
- Exemple : une charge consommant 1 000 W pendant deux heures utilise 2 kWh.
- Visuels : analogie du débit d'eau et calcul animé.
- Démonstration : calculer 500 W pendant 4 h, puis 2 000 W pendant 30 min.
- Erreurs fréquentes : confondre kW et kWh, multiplier les watts par des secondes sans conversion.
- Résultat : calculer une énergie simple.
- Mini-exercice : calculer l'énergie consommée par un appareil de 200 W pendant 5 h.
- Transition : découvrons maintenant les composants qui effectueront ces opérations.
**Ressources du module :** glossaire électrique, fiche des unités, synoptique du projet et quiz M01.

**Validation :** score de quiz d'au moins 80 %, avec correction des erreurs avant de poursuivre.

### Module M02 — Identifier les composants et travailler en sécurité
Objectif : reconnaître les éléments du projet, leur rôle et les limites de manipulation. Prérequis : M01. Durée : 10 minutes.
#### Vidéo M02-V01 — Reconnaître les composants du compteur intelligent (5 min)
- Introduction : « Avant de construire un circuit, nous devons savoir à quoi sert chaque composant et pourquoi il est présent. »
- Plan :
  1. ATmega328P : exécuter le programme.
  2. PZEM-004T : fournir des mesures électriques.
  3. DS3231 : conserver la date et l'heure.
  4. LCD I2C : présenter les informations.
  5. SIM800L : transmettre les données par réseau mobile.
  6. FRAM : conserver les relevés en mémoire non volatile.
  7. Buzzer, LED, bouton, quartz, résistances et condensateurs.
- Illustrations : photos annotées et tableau des fonctions.
- Démonstration : identifier les composants sur la table et leurs marquages.
- À souligner : une référence de module ne suffit pas à garantir le brochage ou les caractéristiques de toutes ses variantes.
- Exercice : associer chaque composant à sa fonction.
- Transition : voyons comment alimenter et protéger ces composants.
#### Vidéo M02-V02 — Alimentations, protections et sécurité du 230 V (5 min)
- Introduction : « Le secteur peut provoquer une électrocution ou un incendie. Nous allons apprendre à séparer les essais basse tension des opérations réservées aux personnes qualifiées. »
- Plan :
  1. Expliquer l'alimentation et la différence entre alternatif et continu.
  2. Présenter le rôle du découplage.
  3. Distinguer l'alimentation logique 5 V et celle du SIM800L.
  4. Présenter isolation, fusibles, distances d'isolement et boîtier.
  5. Définir les tests autorisés à basse tension et ceux réservés à un banc adapté.
- Visuels : schéma des alimentations et exemples de mauvais raccordements.
- Démonstration : contrôle hors tension d'un montage basse tension.
- Erreurs fréquentes : alimenter le SIM800L en 5 V directement, mélanger des masses sans vérifier l'isolation, travailler sur secteur sous tension.
- Résultat : savoir reconnaître une situation dangereuse.
- Exercice : repérer trois erreurs sur un schéma de principe.
- Transition : commencer le développement avec une carte Arduino et une LED.
**Ressources :** BOM préliminaire, fiches composants, checklist de sécurité.

**Quiz M02 :** symboles, fonctions, tensions d'alimentation, découplage, isolation et procédures de sécurité.

**Validation :** 80 % et aucune erreur critique non corrigée sur les règles de sécurité.

### Module M03 — Installer Arduino IDE et programmer sa première LED
Objectif : compiler et téléverser un premier programme. Prérequis : M01-M02. Durée : 14 minutes.
#### Vidéo M03-V01 — Installer Arduino IDE et comprendre la compilation (7 min)
- Introduction : « Un microcontrôleur ne comprend pas directement nos instructions écrites en C++. Arduino IDE nous aide à transformer le programme en instructions exécutables. »
- Plan :
  1. Installer Arduino IDE.
  2. Connecter une Arduino Uno R3.
  3. Sélectionner la carte et le port.
  4. Présenter le code source et le compilateur.
  5. Distinguer compilation et téléversement.
  6. Interpréter les messages d'erreur courants.
- Démonstration : compiler et téléverser un exemple vide, puis vérifier le résultat.
- Supports : capture d'écran, projet de départ.
- Erreurs : mauvais port, câble USB de charge uniquement, carte mal sélectionnée.
- Exercice : compiler un programme fourni.
- Transition : créer un programme qui produit un résultat visible.
#### Vidéo M03-V02 — Faire clignoter une LED avec Arduino Uno (7 min)
- Introduction : « Notre première application va allumer et éteindre une LED. Nous allons ainsi vérifier le lien entre le code et le circuit réel. »
- Plan :
  1. Définir une sortie numérique.
  2. Identifier l'anode et la cathode de la LED.
  3. Expliquer la limitation du courant par une résistance.
  4. Présenter setup() et loop().
  5. Expliquer pinMode(), digitalWrite() et delay().
- Démonstration : montage basse tension, compilation et téléversement.
- Erreur : LED inversée, absence de résistance ou mauvais numéro de broche.
- Résultat : LED clignotante.
- Exercice : modifier la durée d'allumage.
- Transition : apprendre à organiser et modifier le programme.
**Ressources :** installation Arduino IDE, code LED, schéma et guide de dépannage.

**Quiz M03 :** environnement, compilation, téléversement, LED et fonctions principales.

**Validation :** compiler et modifier un programme sans erreur.

### Module M04 — Comprendre les bases du C/C++ embarqué
Objectif : lire et modifier un programme simple. Prérequis : M03. Durée : 14 minutes.
#### Vidéo M04-V01 — Variables, types et calculs en C++ (7 min)
- Introduction : « Pour afficher une tension ou mémoriser une consommation, le microcontrôleur doit conserver des valeurs. C'est le rôle des variables. »
- Plan : variable, déclaration, affectation, int, float, bool, constantes, opérateurs et conversion d'unités.
- Analogie : une variable est une boîte étiquetée qui contient une valeur.
- Démonstration : calculer une puissance fictive et afficher le résultat sur le moniteur série.
- Erreurs : division entière involontaire, dépassement de capacité, précision insuffisante.
- Exercice : calculer une énergie à partir d'une puissance et d'une durée.
- Transition : rendre le programme capable de choisir entre plusieurs actions.
#### Vidéo M04-V02 — Conditions, boucles et fonctions (7 min)
- Introduction : « Un programme utile doit prendre des décisions, répéter certaines tâches et réutiliser du code. »
- Plan :
  1. if, else et comparaisons.
  2. Boucles for et while.
  3. Création et appel d'une fonction.
  4. Passage de paramètres et valeur de retour.
  5. Décomposition d'un programme en tâches.
- Démonstration : afficher un avertissement si une valeur simulée dépasse une limite.
- Erreurs : confusion entre = et ==, boucle infinie, fonction appelée au mauvais endroit.
- Exercice : créer une fonction de conversion watts vers kilowatts.
- Transition : appliquer ces bases aux entrées et aux communications.
**Ressources :** mémo C++, exercices corrigés et code commenté.

**Quiz M04 :** types, variables, conditions, boucles, fonctions et lecture de code.

**Validation :** modifier un programme fourni et expliquer son fonctionnement.

### Module M05 — Entrées, sorties et communications série
Objectif : comprendre les interactions entre microcontrôleur et périphériques. Prérequis : M04. Durée : 18 minutes.
#### Vidéo M05-V01 — Lire un bouton et commander une sortie (9 min)
- Introduction : « Un compteur ne doit pas seulement mesurer. Il doit aussi réagir à une action de l'utilisateur, par exemple pour changer de page sur l'écran. »
- Plan : entrée numérique, résistance de rappel, INPUT_PULLUP, logique inversée, rebond mécanique et anti-rebond.
- Démonstration : bouton qui change l'état d'une LED.
- Erreurs : entrée flottante, câblage incorrect, détection multiple d'un seul appui.
- Exercice : faire alterner deux états à chaque appui.
- Transition : apprendre à échanger des données avec un autre appareil.
#### Vidéo M05-V02 — Comprendre l'UART et les temporisations non bloquantes (9 min)
- Introduction : « Le microcontrôleur doit communiquer avec plusieurs modules. Nous allons découvrir comment les appareils échangent des caractères et des données. »
- Plan :
  1. Communication série et transmission bit par bit.
  2. TX, RX, débit en bauds et format des trames.
  3. Serial.begin(), Serial.print() et Serial.available().
  4. Lecture progressive des caractères.
  5. Limites de delay() et principe de millis().
  6. Gestion du temps et des tâches périodiques.
- Démonstration : envoyer une valeur simulée et la lire sur le moniteur série.
- Erreurs : TX/RX inversés, débits différents, attente bloquante.
- Exercice : afficher une mesure toutes les secondes sans bloquer le programme.
- Transition : remplacer la mesure fictive par une mesure du PZEM.
**Ressources :** tableau des broches, code bouton, code UART et fiche des temporisations.

**Quiz M05 :** GPIO, anti-rebond, UART, débit, TX/RX et millis().

**Validation :** réussir un test d'entrée/sortie et expliquer une communication série.

### Module M06 — Lire les mesures du PZEM-004T V3.0
Objectif : récupérer et interpréter les mesures électriques. Prérequis : M05. Durée : 16 minutes.
#### Vidéo M06-V01 — Comprendre le PZEM et Modbus RTU (8 min)
- Introduction : « Plutôt que de construire nous-mêmes un circuit de mesure du secteur, nous utilisons un module spécialisé qui fournit des valeurs numériques. »
- Plan :
  1. Présenter le PZEM-004T V3.0 et son transformateur de courant compatible.
  2. Expliquer mesure de tension, courant, puissance, fréquence, facteur de puissance et énergie.
  3. Présenter UART et Modbus RTU.
  4. Expliquer requête, adresse, registre et réponse.
  5. Distinguer la mesure physique de son interprétation logicielle.
- Visuels : architecture Modbus et exemple de trame.
- Démonstration : lecture d'une trame simulée.
- Erreurs : utiliser la documentation d'une autre version du PZEM, confondre données brutes et unités.
- Exercice : associer chaque registre documenté à sa grandeur.
- Transition : lire les valeurs avec le firmware.
#### Vidéo M06-V02 — Lire et vérifier les mesures avec Arduino IDE (8 min)
- Introduction : « Nous allons maintenant afficher les valeurs reçues et apprendre à reconnaître une mesure valide ou une erreur de communication. »
- Plan : installation de la bibliothèque adaptée à la version, raccordement logique documenté, lecture des grandeurs, validation, valeurs absentes et erreurs de communication.
- Démonstration : utiliser d'abord un jeu de données simulées, puis une lecture réelle sur un banc approprié.
- Sécurité : aucun montage secteur sous tension à réaliser par un débutant.
- Erreurs : incompatibilité de bibliothèque, alimentation incorrecte, absence de réponse.
- Exercice : détecter une valeur de mesure manquante.
- Transition : ajouter la date et l'affichage local.
**Ressources :** fiche PZEM, extrait de documentation constructeur, exemple de lecture, jeu de mesures simulées.

**Quiz M06 :** registres, Modbus, unités, lecture des mesures et diagnostic.

**Validation :** lire ou simuler correctement les six grandeurs et identifier une erreur de communication.

### Module M07 — Ajouter l'heure et l'écran LCD I2C
Objectif : afficher des données lisibles et datées. Prérequis : M05-M06. Durée : 14 minutes.
#### Vidéo M07-V01 — Comprendre et utiliser le DS3231 (7 min)
- Introduction : « Pour calculer la consommation de chaque jour, le compteur doit connaître la date, même lorsqu'il est redémarré. »
- Plan : rôle d'une horloge temps réel, bus I2C, SDA/SCL, alimentation, pile de sauvegarde et lecture de la date.
- Démonstration : lire une date de test et régler l'horloge.
- Erreurs : date initiale incorrecte, pile absente ou épuisée, mauvaise adresse I2C.
- Exercice : afficher la date au format JJ/MM/AAAA.
- Transition : rendre cette information visible sur un écran.
#### Vidéo M07-V02 — Afficher les mesures sur un LCD 20×4 I2C (7 min)
- Introduction : « Un écran permet de consulter l'état du compteur sans ordinateur ni téléphone. »
- Plan : principe du LCD, adaptateur I2C, bibliothèque, adresse, positionnement du curseur et formatage des nombres.
- Démonstration : afficher une date, une tension et les consommations journalières et mensuelles simulées.
- Exemple : TENSION: 230.5 V.
- Erreurs : adresse incorrecte, écran vide, débordement de ligne et rafraîchissement excessif.
- Exercice : ajouter une page affichant courant et puissance.
- Transition : calculer correctement les consommations cumulées.
**Ressources :** schéma I2C, code DS3231, code LCD et maquette des écrans.

**Quiz M07 :** I2C, DS3231, LCD, adresses et formatage.

**Validation :** afficher des données datées sur quatre lignes sans clignotement excessif.

### Module M08 — Calculer les consommations journalières et mensuelles
Objectif : élaborer une logique de calcul fiable et résistante aux redémarrages. Prérequis : M06-M07. Durée : 16 minutes.
#### Vidéo M08-V01 — Calculer l'énergie et comprendre les index (8 min)
- Introduction : « Une mesure instantanée ne suffit pas pour connaître l'énergie consommée pendant une journée. Il faut exploiter un index énergétique et ses variations. »
- Plan :
  1. Différence entre puissance instantanée et énergie cumulée.
  2. Lire l'index énergétique du PZEM.
  3. Calculer un delta entre deux index successifs.
  4. Cumuler les deltas pour la journée et le mois.
  5. Éviter les doubles comptages.
  6. Détecter un index réinitialisé ou devenu incohérent.
- Exemple : index initial de 120,400 kWh, puis 120,650 kWh : différence de 0,250 kWh.
- Démonstration : calcul sur des relevés fictifs.
- Erreurs : additionner plusieurs fois l'index total, accepter aveuglément un index qui diminue.
- Exercice : calculer les deltas sur cinq relevés.
- Transition : traiter les changements de date et les interruptions.
#### Vidéo M08-V02 — Gérer minuit, les mois, les années et les redémarrages (8 min)
- Introduction : « Un compteur fiable doit continuer à calculer correctement après une coupure de courant ou un changement de mois. »
- Plan :
  1. Associer chaque relevé à un horodatage.
  2. Détecter le changement de jour et de mois.
  3. Clôturer une période sans effacer l'index global du PZEM.
  4. Sauvegarder les derniers index et les cumuls.
  5. Traiter une coupure où aucune mesure n'est disponible.
  6. Repartir d'un état sauvegardé après redémarrage.
- Démonstration : simulation du passage du 31 janvier au 1er février.
- Erreurs : remise à zéro de l'index total, confusion entre absence de mesure et consommation nulle.
- Exercice : compléter une table de consommation quotidienne.
- Transition : conserver cette logique sur un microcontrôleur autonome.
**Ressources :** algorithme de cumul, jeux de données, exercices corrigés et scénarios de panne.

**Quiz M08 :** delta énergétique, changements de période, persistance, réinitialisation et doublons.

**Validation :** calculer un cumul exact sur une série de relevés comprenant un redémarrage et un changement de mois.

### Module M09 — Programmer l'ATmega328P autonome par ISP
Objectif : comprendre le passage de l'Arduino Uno au microcontrôleur autonome. Prérequis : M03-M08. Durée : 16 minutes.
#### Vidéo M09-V01 — Construire le circuit minimal de l'ATmega328P (8 min)
- Introduction : « La carte Arduino Uno simplifie le développement, mais notre produit final peut utiliser directement le microcontrôleur. »
- Plan :
  1. Différence entre carte de développement et microcontrôleur.
  2. Identifier le boîtier et la référence exacte.
  3. Expliquer VCC, AVCC, GND et RESET.
  4. Présenter quartz 16 MHz et condensateurs adaptés.
  5. Présenter les condensateurs de découplage et le connecteur ISP.
- Démonstration : circuit basse tension sur schéma et breadboard.
- Erreurs : orientation du boîtier, alimentation oubliée, RESET mal câblé.
- Exercice : annoter le schéma minimal.
- Transition : utiliser l'Arduino Uno pour programmer cette puce.
#### Vidéo M09-V02 — Charger ArduinoISP et téléverser le firmware par ISP (8 min)
- Introduction : « Nous allons utiliser une Arduino Uno comme programmateur pour envoyer un programme à un ATmega328P externe. »
- Plan :
  1. Charger l'exemple ArduinoISP sur la carte programmateur.
  2. Câbler MOSI, MISO, SCK, RESET, alimentation et masse.
  3. Sélectionner la cible, le programmateur et la configuration d'horloge.
  4. Expliquer les options de bootloader et les fusibles.
  5. Programmer le microcontrôleur par ISP.
  6. Retirer la carte de développement du montage cible.
  7. Tester le programme autonome.
  8. Distinguer cette méthode du retrait d'une puce DIP amovible d'une Uno compatible.
- Démonstration : programmer un firmware LED.
- Erreurs : mauvais RESET, configuration d'horloge incorrecte, mauvaise sélection du programmateur.
- Exercice : diagnostiquer un échec ISP.
- Transition : ajouter la communication distante.
**Ressources :** brochage exact du boîtier, schéma ISP, checklist de programmation et firmware de test.

**Quiz M09 :** rôle des broches, ArduinoISP, fusibles, horloge et bootloader.

**Validation :** programmer et tester la puce externe sans supposer que toutes les cartes Uno ont une puce amovible.

### Module M10 — Communiquer avec le SIM800L par GSM/GPRS
Objectif : comprendre le modem et les commandes AT. Prérequis : M05 et M09. Durée : 14 minutes.
#### Vidéo M10-V01 — Tester le SIM800L et comprendre les commandes AT (7 min)
- Introduction : « Le SIM800L est un modem : il reçoit des commandes, communique avec le réseau mobile et retourne des réponses. »
- Plan : GSM, GPRS, carte SIM, antenne, UART, commandes AT, réponses et états du modem.
- Démonstration : simulation de AT, AT+CPIN?, AT+CSQ et AT+CREG?.
- Point critique : le SIM800L nécessite une alimentation adaptée, généralement autour de 4 V selon le module, avec une capacité suffisante pour ses pointes de courant pouvant approcher 2 A. Vérifier la fiche exacte du fabricant.
- Erreurs : alimentation 5 V directe non autorisée, mauvais débit série, SIM verrouillée.
- Exercice : interpréter une réponse réseau.
- Transition : préparer l'envoi de données au serveur.
#### Vidéo M10-V02 — Transmettre une mesure par GPRS et traiter les erreurs (7 min)
- Introduction : « Une connexion mobile peut échouer ou disparaître. Nous allons organiser la transmission pour que l'application détecte les erreurs. »
- Plan : APN, session GPRS, requête HTTP de laboratoire, code de réponse, délai d'attente, nouvelle tentative et fermeture de session.
- Démonstration : requête vers un serveur de test et lecture de la réponse.
- Sécurité : HTTP non chiffré uniquement dans un environnement de laboratoire isolé. Ne jamais transmettre de secrets par HTTP sur Internet en production.
- Limites : le SIM800L est un modem 2G ancien ; la disponibilité du réseau dépend de l'opérateur. Ses capacités TLS sont limitées et doivent être vérifiées.
- Exercice : interpréter un échec de connexion.
- Transition : préparer une transmission qui ne perde pas les relevés.
**Ressources :** catalogue de commandes AT, fiche d'alimentation, APN fictif de test et scripts de simulation.

**Quiz M10 :** UART, SIM, APN, réponses AT, GPRS et sécurité.

**Validation :** expliquer le cycle de connexion et identifier une panne sans mettre le modem en danger.

### Module M11 — Sauvegarder les relevés et synchroniser après une panne
Objectif : assurer la continuité des données. Prérequis : M08-M10. Durée : 16 minutes.
#### Vidéo M11-V01 — Utiliser une FRAM pour conserver les relevés (8 min)
- Introduction : « Si le réseau disparaît, le compteur doit continuer à enregistrer les relevés au lieu de les perdre. »
- Plan :
  1. Différence entre RAM et mémoire non volatile.
  2. Présenter la FRAM externe et son interface.
  3. Expliquer les adresses, enregistrements et versions de données.
  4. Définir un identifiant unique pour chaque relevé.
  5. Prévoir capacité, durée de conservation et stratégie de mémoire pleine.
- Démonstration : écrire puis relire des relevés simulés.
- Erreurs : débordement de mémoire, format de données instable, écrasement d'enregistrements non envoyés.
- Exercice : estimer l'espace nécessaire pour une journée de relevés.
- Transition : retransmettre les enregistrements en attente.
#### Vidéo M11-V02 — Reprendre les envois sans doublons (8 min)
- Introduction : « Une réponse du serveur peut être perdue alors que la mesure a bien été enregistrée. Il faut donc rendre les envois répétables sans créer de doublons. »
- Plan :
  1. Créer une file d'attente locale.
  2. Marquer les relevés en attente, envoyés ou confirmés.
  3. Retenter une transmission avec temporisation.
  4. Utiliser un identifiant unique de mesure.
  5. Faire vérifier cet identifiant par le serveur.
  6. Supprimer ou libérer un enregistrement seulement après confirmation.
- Démonstration : couper artificiellement la connexion dans un simulateur.
- Erreurs : effacer un relevé avant l'accusé de réception, confondre succès HTTP et insertion effective.
- Exercice : prévoir le résultat de trois tentatives de transmission.
- Transition : développer le serveur qui reçoit ces données.
**Ressources :** format d'enregistrement, simulateur réseau, diagramme de synchronisation et scénarios de panne.

**Quiz M11 :** FRAM, identifiants uniques, file d'attente, confirmation et idempotence.

**Validation :** réussir une simulation de perte réseau puis de synchronisation sans doublon.

### Module M12 — Apprendre les bases de Python
Objectif : comprendre le langage nécessaire au backend. Prérequis : notions générales de programmation. Durée : 14 minutes.
#### Vidéo M12-V01 — Variables, types, conditions et fonctions Python (7 min)
- Introduction : « Le microcontrôleur collecte les mesures, mais un programme Python peut les recevoir, les vérifier et les organiser. »
- Plan : interpréteur, variables, chaînes, nombres, listes, dictionnaires, conditions et fonctions.
- Démonstration : traiter un dictionnaire représentant une mesure.
- Erreurs : indentation, types incompatibles et clés absentes.
- Exercice : extraire la tension d'un objet de mesure.
- Transition : manipuler des données structurées.
#### Vidéo M12-V02 — JSON, dates, erreurs et fichiers Python (7 min)
- Introduction : « Les données échangées entre le compteur et le serveur doivent suivre un format convenu. Nous allons utiliser JSON. »
- Plan : objets et tableaux JSON, sérialisation, dates ISO 8601, exceptions, fichiers et journaux.
- Démonstration : lire un exemple JSON et rejeter une mesure mal formée.
- Erreurs : JSON invalide, date ambiguë, valeur manquante.
- Exercice : corriger un objet JSON incorrect.
- Transition : construire une application web avec Flask.
**Ressources :** aide-mémoire Python, exercices et exemples JSON.

**Quiz M12 :** types, dictionnaires, fonctions, JSON et exceptions.

**Validation :** lire et valider un petit objet de mesure.

### Module M13 — Construire le backend Flask et la base SQLite
Objectif : créer une API de réception et enregistrer les mesures. Prérequis : M12. Durée : 16 minutes.
#### Vidéo M13-V01 — Créer une application Flask et comprendre HTTP (8 min)
- Introduction : « Un serveur web attend des requêtes, exécute un traitement et renvoie une réponse. Flask nous permet de construire ce mécanisme. »
- Plan : client/serveur, URL, requête, réponse, GET, POST, codes HTTP, routes Flask et JSON.
- Démonstration : créer une route de test et envoyer une requête.
- Erreurs : route incorrecte, méthode HTTP non autorisée, serveur de développement exposé publiquement.
- Exercice : créer une route de statut.
- Transition : enregistrer les mesures dans SQLite.
#### Vidéo M13-V02 — Créer SQLite et sécuriser l'API de réception (8 min)
- Introduction : « Pour conserver l'historique, nous avons besoin d'une base de données. Nous allons stocker chaque mesure de manière structurée. »
- Plan :
  1. Tables, colonnes, clés primaires et index.
  2. Concevoir les tables des appareils et des mesures.
  3. Utiliser SQLite avec des requêtes paramétrées.
  4. Valider les unités, types, dates et limites.
  5. Authentifier les équipements et protéger les secrets.
  6. Gérer les doublons avec une contrainte d'unicité.
  7. Enregistrer les erreurs.
- Démonstration : envoyer une mesure et la retrouver dans SQLite.
- Erreurs : insertion de données non validées, SQL construit par concaténation, clé d'appareil exposée.
- Exercice : rejeter une mesure invalide et une répétition de la même mesure.
- Transition : afficher ces données sur le tableau de bord.
**Ressources :** squelette Flask, script SQL, exemple JSON, guide d'authentification.

**Quiz M13 :** routes, HTTP, schéma SQL, validation, authentification et idempotence.

**Validation :** recevoir et stocker une mesure, puis traiter correctement une requête répétée.

### Module M14 — Créer le tableau de bord web
Objectif : consulter les données sans recharger inutilement la page. Prérequis : M13. Durée : 16 minutes.
#### Vidéo M14-V01 — Créer une interface avec Jinja2, HTML et CSS (8 min)
- Introduction : « Une base de données est utile seulement si l'utilisateur peut comprendre les informations qu'elle contient. »
- Plan : HTML, structure de page, CSS, responsive design, templates Jinja2, variables, boucles et conditions.
- Démonstration : afficher la dernière mesure dans une page.
- Erreurs : mélanger traitement métier et présentation, afficher directement du contenu non échappé.
- Exercice : afficher une liste de relevés.
- Transition : actualiser les mesures et dessiner les graphiques.
#### Vidéo M14-V02 — Utiliser Fetch API et Chart.js pour les historiques (8 min)
- Introduction : « Nous allons créer un tableau de bord qui récupère les nouvelles données et présente les consommations sous forme graphique. »
- Plan : requête Fetch, réponse JSON, traitement d'erreur, actualisation périodique, Chart.js, filtres journaliers et mensuels.
- Démonstration : courbe de consommation simulée et sélection d'une période.
- Erreurs : actualisations trop fréquentes, graphiques incohérents avec les données, absence de gestion d'erreur.
- Exercice : afficher les données d'une journée choisie.
- Transition : préparer le circuit électronique documenté.
**Ressources :** templates HTML, CSS responsive, JavaScript, données d'exemple et tableau de bord.

**Quiz M14 :** Jinja2, HTML, CSS, Fetch, JSON et Chart.js.

**Validation :** afficher des mesures et un graphique sur ordinateur et smartphone.

### Module M15 — Concevoir le schéma électronique avec KiCad
Objectif : produire une documentation électronique cohérente. Prérequis : M02-M09. Durée : 12 minutes.
#### Vidéo M15-V01 — Créer le schéma et choisir les empreintes (6 min)
- Introduction : « Un montage qui fonctionne sur breadboard doit ensuite être documenté pour pouvoir être reproduit et maintenu. »
- Plan : projet KiCad, symboles, références, alimentation, connecteurs, annotations, vérification électrique et empreintes.
- Démonstration : créer le schéma basse tension autour de l'ATmega328P et des interfaces.
- Erreurs : symbole mal choisi, broche non connectée, empreinte incompatible.
- Exercice : compléter un schéma fourni.
- Transition : préparer le circuit imprimé.
#### Vidéo M15-V02 — Préparer un PCB et vérifier les contraintes de sécurité (6 min)
- Introduction : « Le circuit imprimé doit être fabriqué selon les caractéristiques des composants et les contraintes de sécurité de l'installation. »
- Plan : implantation, pistes, règles de conception, connecteurs, découplage et contrôle du PCB.
- Démonstration : routage d'une partie basse tension et export des fichiers.
- Limite : la section secteur n'est pas à reproduire par un débutant ; son dessin et sa validation nécessitent une conception professionnelle adaptée aux normes applicables.
- Exercice : vérifier une liste de contrôle PCB.
- Transition : assembler les sous-systèmes et valider le projet.
**Ressources :** projet KiCad, symboles, empreintes, schéma annoté et checklist de conception.

**Quiz M15 :** symboles, empreintes, vérification électrique, routage et sécurité.

**Validation :** produire un schéma basse tension vérifié et documenté.

### Module M16 — Intégration, tests et déploiement
Objectif : valider le fonctionnement de bout en bout. Prérequis : modules précédents. Durée : 14 minutes.
#### Vidéo M16-V01 — Intégrer le firmware et tester les scénarios de panne (7 min)
- Introduction : « Un projet complet ne se valide pas uniquement parce que chaque module fonctionne séparément. Nous allons tester leurs interactions. »
- Plan :
  1. Vérifier les mesures.
  2. Vérifier la date et l'heure.
  3. Tester les calculs journaliers et mensuels.
  4. Simuler un redémarrage.
  5. Simuler une perte de réseau.
  6. Vérifier la synchronisation et les doublons.
  7. Vérifier les alarmes et l'état du système.
- Démonstration : jeu de tests automatisés et valeurs simulées.
- Erreurs : tests uniquement en fonctionnement normal, absence de journal d'erreurs.
- Exercice : établir un rapport de test.
- Transition : publier le backend et présenter le résultat final.
#### Vidéo M16-V02 — Déployer Flask sur PythonAnywhere et valider le projet (7 min)
- Introduction : « Nous allons rendre le tableau de bord accessible en ligne et vérifier les conditions de son exploitation. »
- Plan : préparer l'application, configurer l'environnement, déployer Flask, configurer les variables secrètes, vérifier les journaux, tester SQLite et les requêtes.
- Démonstration : déploiement d'une application de test et consultation du tableau de bord.
- Points critiques : vérifier les restrictions réseau du forfait PythonAnywhere, les possibilités de connexion sortante, le HTTPS, les limites de stockage et les règles d'exécution. Ne pas supposer qu'un forfait donné autorise toutes les connexions nécessaires.
- Erreurs : dépendance manquante, mauvais chemin WSGI, secrets dans le code source, base de données inaccessible.
- Exercice : remplir une checklist de mise en production.
- Résultat final : architecture comprise, serveur de test accessible et plan de validation documenté.
**Ressources :** guide PythonAnywhere, checklist de déploiement, scripts de test, grille de projet final.

**Quiz M16 :** intégration, tests, déploiement, journaux, sécurité et diagnostic.

**Validation :** réussir les tests fonctionnels et expliquer les limites restantes du prototype.
## Partie D — Parcours des réalisations pratiques
Le parcours pratique doit éviter de commencer directement par le compteur complet. L'apprenant construit progressivement des sous-systèmes indépendants, puis les assemble.
D1. Ordre exact des réalisations

Étape 1 — LED et bouton

Résultat : une LED clignote et un bouton change son état. Vérification du câblage, des entrées et des sorties.

Étape 2 — Mesures simulées

Résultat : tension, courant, puissance et énergie fictifs sont affichés sur le moniteur série. Les calculs sont vérifiés indépendamment du secteur.

Étape 3 — Sous-système de mesure

Résultat : lecture des données PZEM et gestion des erreurs. La validation électrique réelle est réservée à un banc approprié et à une personne qualifiée.

Étape 4 — Affichage daté

Résultat : l'écran affiche la date, la tension et les cumuls du jour et du mois, avec navigation entre les pages.

Étape 5 — Circuit autonome

Résultat : l'ATmega328P exécute le firmware sans carte Arduino Uno dans le montage final.

Étape 6 — Communication distante

Résultat : le modem transmet une mesure de test, interprète la réponse du serveur et détecte les échecs.

Étape 7 — Serveur et stockage

Résultat : Flask reçoit les données, les valide et les enregistre dans SQLite, en rejetant les doublons.

Étape 8 — Tableau de bord IoT

Résultat : consultation des mesures récentes, des historiques, des statistiques et des graphiques.

D2. Contrat de données entre le compteur et le serveur
Pour que les deux parties fonctionnent ensemble, il faut définir le format de transmission avant de filmer les modules GSM et Flask.

Exemple de structure JSON de référence :
{
  "device_id": "COMPTEUR-001",
  "sequence": 125,
  "timestamp": "2026-10-27T12:00:00Z",
  "voltage_v": 230.5,
  "current_a": 2.15,
  "active_power_w": 495.0,
  "energy_total_kwh": 125.480,
  "frequency_hz": 50.0,
  "power_factor": 0.98
}


Ces valeurs sont fictives. Le firmware et le serveur doivent utiliser exactement les mêmes noms de champs, unités et règles de validation.

L'horodatage doit être accompagné d'une règle claire concernant le fuseau horaire. Une option simple consiste à stocker les dates côté serveur en UTC et à les convertir pour l'affichage local.
D3. Règles de fiabilité indispensables
- Utiliser l'index énergétique total du PZEM comme référence lorsqu'il est valide, sans le remettre à zéro à chaque changement de jour ou de mois.
- Calculer les consommations par différence entre index successifs, avec un traitement explicite des réinitialisations et des valeurs incohérentes.
- Sauvegarder les derniers index acceptés et l'état de la période courante en mémoire non volatile.
- Enregistrer les relevés non transmis dans la FRAM, avec un identifiant unique.
- Ne supprimer un relevé de la file d'attente qu'après confirmation du serveur.
- Rendre l'insertion SQLite idempotente grâce à une contrainte d'unicité.
- Si une coupure électrique empêche toute mesure, signaler cette période comme inconnue ou non mesurée : ne pas inventer une consommation.
- Si le PZEM est réinitialisé ou remplacé, détecter le changement d'index et définir une procédure de reprise, au lieu d'ajouter aveuglément une différence négative.
Limite matérielle à anticiper : l'ATmega328P possède peu de mémoire vive et de mémoire programme. Il faut utiliser des structures compactes, éviter de construire de grandes chaînes JSON en RAM et tester la taille maximale de la file FRAM. Le format d'enregistrement devra être choisi après avoir défini la capacité de mémoire et la fréquence d'échantillonnage.

## Partie E — Plan des quiz et des évaluations
E1. Organisation des évaluations
Je recommande un quiz de 10 questions par module, soit 160 questions pour les 16 modules, plus une évaluation finale de 20 questions.

Pour chaque module, le quiz sera disponible à la fin du module, avec une correction explicative. L'apprenant pourra le recommencer sans pénalité.

Le seuil de réussite sera de 80 %, soit 8 bonnes réponses sur 10.
E2. Thèmes et difficultés des quiz
| Module | Répartition indicative des 10 questions |
| --- | --- |
| M01 | 4 fondamentaux, 3 unités, 2 calculs, 1 lecture de situation |
| M02 | 3 composants, 2 alimentation, 3 sécurité, 2 diagnostic |
| M03 | 3 environnement, 3 compilation, 2 téléversement, 2 erreurs |
| M04 | 3 variables/types, 2 opérateurs, 3 logique, 2 lecture de code |
| M05 | 3 GPIO, 2 anti-rebond, 3 UART, 2 temporisations |
| M06 | 3 PZEM, 3 Modbus, 2 unités, 2 diagnostic |
| M07 | 3 DS3231/I2C, 3 LCD, 2 formatage, 2 diagnostic |
| M08 | 3 énergie, 3 cumuls, 2 dates, 2 reprise après panne |
| M09 | 3 ATmega autonome, 3 ISP, 2 horloge/fusibles, 2 diagnostic |
| M10 | 2 GSM/GPRS, 3 commandes AT, 2 alimentation, 3 erreurs/sécurité |
| M11 | 3 FRAM, 3 file d'attente, 2 identifiants, 2 synchronisation |
| M12 | 3 types, 2 structures, 3 fonctions, 2 JSON/erreurs |
| M13 | 3 HTTP/Flask, 3 SQLite, 2 validation, 2 sécurité |
| M14 | 2 HTML/CSS, 2 Jinja2, 3 Fetch, 3 graphiques |
| M15 | 3 schéma, 2 empreintes, 3 PCB, 2 sécurité |
| M16 | 3 intégration, 3 tests, 2 déploiement, 2 diagnostic |

Pour chaque banque, viser environ 4 questions faciles, 4 intermédiaires et 2 difficiles. Les questions de sécurité doivent être obligatoires, même si le score global atteint 80 %.
E3. Exemple complet : quiz du module M01
Thème : découverte du compteur et unités électriques.
Quiz M01 — 10 questions
0/10 répondues

Choisis une seule réponse par question. Après correction, les explications pédagogiques s'affichent pour toutes les questions.
1. Quelle grandeur électrique s'exprime en volts ?

Facile · Objectif : Reconnaître les unités

A. L'énergie

B. La tension

C. La puissance

D. La fréquence

2. Quelle unité mesure le courant électrique ?

Facile · Objectif : Reconnaître les unités

A. Ampère

B. Watt

C. Volt

D. Kilowattheure

3. Que représente une puissance de 1 000 W ?

Facile · Objectif : Distinguer puissance et énergie

A. Une énergie de 1 kWh

B. Une puissance de 1 kW

C. Une tension de 1 kV

D. Un courant de 1 A

4. Un appareil de 500 W fonctionne pendant 2 heures. Quelle énergie consomme-t-il ?

Intermédiaire · Objectif : Calculer l'énergie

A. 0,25 kWh

B. 1 kWh

C. 2 kWh

D. 1 000 kWh

5. Quel est le rôle principal du PZEM dans le projet ?

Facile · Objectif : Identifier le rôle du PZEM

A. Héberger la base de données

B. Mesurer des grandeurs électriques

C. Afficher une page web

D. Fournir la date

6. Quel composant exécute le programme du compteur ?

Facile · Objectif : Identifier le microcontrôleur

A. Le LCD

B. Le transformateur de courant seul

C. L'ATmega328P

D. Le câble USB

7. Quel est le rôle du serveur Flask ?

Intermédiaire · Objectif : Comprendre l'architecture client/serveur

A. Mesurer directement le courant secteur

B. Remplacer le PZEM

C. Recevoir et traiter les données envoyées

D. Fournir l'alimentation du modem

8. Quelle affirmation décrit correctement le kWh ?

Facile · Objectif : Distinguer les grandeurs

A. C'est une unité de tension

B. C'est une unité d'énergie

C. C'est une unité de courant

D. C'est une unité de fréquence

9. Un appareil de 2 kW fonctionne pendant 30 minutes. Quelle énergie consomme-t-il ?

Intermédiaire · Objectif : Convertir les durées

A. 2 kWh

B. 1 kWh

C. 0,5 kWh

D. 4 kWh

10. Dans le synoptique du projet, quel ordre décrit correctement le trajet des données ?

Difficile · Objectif : Comprendre l'architecture globale

A. Navigateur → LCD → PZEM → serveur

B. PZEM → ATmega328P → communication GSM/GPRS → serveur → tableau de bord

C. FRAM → alimentation → capteur → écran

D. SQLite → PZEM → navigateur → ATmega328P


Corriger mes réponses
E4. Évaluation finale — 20 questions
L'évaluation finale doit couvrir l'ensemble du système, et non seulement la programmation.
| Domaine | Questions |
| --- | --- |
| Grandeurs électriques et sécurité | 3 |
| ATmega328P, C++ et ISP | 4 |
| PZEM, RTC et calcul énergétique | 4 |
| GSM/GPRS et synchronisation | 3 |
| Python, Flask et SQLite | 3 |
| Interface web et déploiement | 3 |
| Total | 20 |

Le seuil recommandé est de 16/20. Les erreurs critiques de sécurité ou de gestion des données doivent être corrigées même si le score global est atteint.
E5. Grille d'évaluation du projet final
| Critère | Points |
| --- | --- |
| Mesures et interprétation des données | 15 |
| Calcul journalier et mensuel fiable | 15 |
| Firmware ATmega328P et programmation ISP | 15 |
| Affichage LCD et gestion du temps | 10 |
| Transmission GSM/GPRS | 10 |
| Stockage FRAM et reprise sans doublons | 10 |
| API Flask et base SQLite | 10 |
| Tableau de bord et historiques | 5 |
| Tests, sécurité et documentation | 10 |
| Total | 100 |

La réussite pratique est fixée à 80/100, sans défaut critique de sécurité. Le rapport doit indiquer clairement les fonctions testées en matériel réel, celles testées en simulation et celles qui restent à valider.
## Partie F — Ressources téléchargeables
Les ressources sont essentielles pour rendre possible une formation de quatre heures. L'apprenant ne doit pas perdre une grande partie du temps vidéo à saisir des fichiers, rechercher des références ou résoudre des problèmes d'installation évitables.
F1. Bibliothèque pédagogique à préparer
| Code | Ressource | Contenu | Livraison |
| --- | --- | --- | --- |
| R01 | Guide de démarrage | Prérequis, organisation, installation et parcours de formation | M01 |
| R02 | BOM complète | Référence, quantité, fonction, caractéristiques à vérifier et fournisseur indicatif | M02 |
| R03 | Fiche des unités électriques | V, A, W, Wh, kWh, Hz et facteur de puissance | M01 |
| R04 | Fiches composants | ATmega328P, PZEM, DS3231, SIM800L, FRAM, LCD et alimentation | M02 |
| R05 | Synoptique du compteur | Circulation des mesures, données et commandes | M01 |
| R06 | Schémas de raccordement | Tableaux des broches et connexions basse tension | M03-M09 |
| R07 | Projet Arduino IDE | LED, bouton, UART, LCD, RTC et modules séparés | M03-M09 |
| R08 | Code du firmware de référence | Architecture modulaire et gestion des erreurs | M06-M11 |
| R09 | Projet ISP | ArduinoISP, câblage et procédures de programmation | M09 |
| R10 | Catalogue de commandes AT | Commandes, réponses attendues et erreurs | M10 |
| R11 | Simulateur de mesures | Jeux de données normaux, incohérents et interruptions | M06-M11 |
| R12 | Spécification JSON | Format, unités, horodatage et identifiants | M10-M13 |
| R13 | Projet Flask | Application, routes et validation des données | M13 |
| R14 | Scripts SQLite | Tables, index, contraintes d'unicité et exemples | M13 |
| R15 | Templates Jinja2 | Pages du tableau de bord et historiques | M14 |
| R16 | CSS et JavaScript | Interface responsive, Fetch API et graphiques | M14 |
| R17 | Projet KiCad | Schéma basse tension, symboles, empreintes et PCB de référence | M15 |
| R18 | Guide PythonAnywhere | Déploiement, configuration et dépannage | M16 |
| R19 | Fiches de dépannage | Erreurs fréquentes et procédure de diagnostic | Tous les modules |
| R20 | Quiz et corrections | 160 questions de module et 20 questions finales | Tous les modules |
| R21 | Grille du projet final | Critères de test, notation et preuves à fournir | M16 |
| R22 | Glossaire technique | Termes électroniques, réseau, programmation et web | M01-M16 |

F2. Organisation des fichiers
Je recommande de livrer une archive principale avec une arborescence claire :
AlexTech_Compteur_IoT/
├── 00_Guide_Demarrage/
├── 01_Electronique_Securite/
├── 02_Arduino_Cpp/
├── 03_PZEM_Mesures/
├── 04_RTC_LCD_Energie/
├── 05_ATmega328P_ISP/
├── 06_SIM800L_GPRS/
├── 07_FRAM_Synchronisation/
├── 08_Python_Flask/
├── 09_SQLite_API/
├── 10_Dashboard_Web/
├── 11_KiCad/
├── 12_PythonAnywhere/
├── 13_Exercices_Corrections/
├── 14_Quiz_Evaluations/
└── 15_Projet_Final/


Chaque projet logiciel doit contenir un fichier README expliquant son objectif, les dépendances, les étapes de lancement et le résultat attendu.

Règle de production : les fichiers fournis doivent être testés dans leur version exacte avant publication. Un code qui fonctionne uniquement sur l'ordinateur du formateur n'est pas une ressource pédagogique prête à commercialiser.

## Partie G — Planning de production de la formation
L'objectif est de préparer les supports et de tester le projet avant de filmer. Il ne faut pas commencer l'enregistrement avec un firmware instable.
G1. Planning recommandé sur quatre semaines
S1
Jours 1–7

Architecture et préparation technique
- Définir le matériel exact et les versions de bibliothèques.
- Vérifier les fiches techniques du PZEM, de l'ATmega328P, du DS3231 et du SIM800L.
- Établir le format JSON et le schéma SQLite.
- Préparer les scénarios de mesure et de panne.
- Réaliser le synoptique et les schémas de raccordement.
  
  Livrables : architecture validée, BOM, premiers scripts de test et spécification des données.

S2
Jours 8–14

Développement et validation du prototype
- Tester séparément les fonctions du firmware.
- Vérifier les calculs énergétiques et les reprises après redémarrage.
- Développer la file d'attente FRAM et les transmissions simulées.
- Construire l'application Flask, la base SQLite et les routes.
- Tester le tableau de bord avec des données fictives.
  
  Livrables : firmware de référence, backend de test et tableau de bord fonctionnel sur données simulées.

S3
Jours 15–21

Préparation pédagogique et tournage
- Écrire les fiches de réalisation des 32 vidéos.
- Produire les présentations, schémas animés et jeux de données.
- Filmer les démonstrations basse tension.
- Enregistrer les captures d'écran Arduino IDE, Python, Flask et KiCad.
- Filmer les tests sur banc secteur sécurisé avec une personne qualifiée, si cette démonstration est prévue.
  
  Livrables : enregistrements bruts, illustrations et premières ressources téléchargeables.

S4
Jours 22–28

Montage, contrôle qualité et publication
- Monter les vidéos et ajouter les titres, schémas et sous-titres.
- Préparer les quiz et leurs corrections.
- Tester les archives et les codes sur un environnement propre.
- Vérifier la durée totale de 240 minutes.
- Faire suivre la formation à un testeur débutant.
- Corriger les explications ambiguës et publier la version finale.
  
  Livrables : formation finalisée, ressources validées et grille de certification du projet.

Ce calendrier est un objectif de production, pas une garantie. Si le modem, les alimentations ou le calcul énergétique présentent des défauts, il faut prolonger la validation plutôt que filmer une démonstration non reproductible.
G2. Méthode de tournage par type de contenu
| Type de vidéo | Support principal | Durée de préparation indicative |
| --- | --- | --- |
| Théorie électrique | Présentation et schémas animés | 20–40 min |
| Câblage basse tension | Caméra au-dessus de la table et gros plans | 30–60 min |
| Arduino IDE et C++ | Capture d'écran avec zoom sur le code | 20–40 min |
| ISP | Capture d'écran et démonstration physique | 30–60 min |
| GSM/GPRS | Capture série, schéma et simulateur | 30–60 min |
| Python et Flask | Capture d'écran et tests en direct | 20–45 min |
| SQLite et graphiques | Capture d'écran et démonstration du résultat | 20–45 min |
| KiCad | Capture d'écran avec annotations | 20–40 min |
| Sécurité électrique | Schémas, procédures et démonstration qualifiée | Selon le banc et les validations nécessaires |

Ces durées concernent la préparation de chaque type de tournage ; elles ne comprennent pas nécessairement le montage final.
G3. Stratégie de montage
Pour conserver une bonne qualité pédagogique :
- Afficher le résultat attendu dans les premières secondes.
- Introduire chaque nouveau terme à l'écran.
- Zoomer sur les broches, les lignes de code et les messages d'erreur.
- Montrer le câblage réel en complément du schéma.
- Insérer des pauses visuelles avant les calculs complexes.
- Afficher les unités sur chaque valeur numérique.
- Terminer chaque vidéo par un test ou une question.
- Ajouter des sous-titres et un rappel des ressources associées.
Pour AlexTech Academy, il est préférable d'avoir des vidéos courtes, un sommaire consultable et des fichiers de départ plutôt qu'un unique enregistrement de quatre heures.

## Partie H — Critères de qualité pédagogique
H1. Grille de contrôle avant publication
Chaque vidéo doit être évaluée avant d'être mise en ligne.
Checklist de validation vidéo
0/12

[ ] Le résultat attendu est annoncé dès le début.
[ ] Les prérequis sont rappelés ou accessibles dans une vidéo antérieure.
[ ] Chaque terme technique nouveau est défini.
[ ] Les unités et les valeurs utilisées sont cohérentes.
[ ] Le schéma correspond exactement au montage montré.
[ ] Le code présenté a été compilé ou testé.
[ ] Les erreurs probables et leur diagnostic sont expliqués.
[ ] Les règles de sécurité sont respectées.
[ ] Un exercice ou une question vérifie la compréhension.
[ ] Une transition claire prépare la prochaine vidéo.
[ ] Les fichiers téléchargeables correspondent à la version filmée.
[ ] Le son, les captures et les sous-titres sont lisibles.
Réinitialiser la checklist
H2. Barème qualité
Je recommande une notation sur 100 points :
| Critère | Points |
| --- | --- |
| Clarté des explications | 20 |
| Exactitude technique | 20 |
| Progression et prérequis | 15 |
| Qualité des démonstrations | 15 |
| Exercices et validation | 10 |
| Lisibilité audiovisuelle | 10 |
| Ressources et cohérence des versions | 5 |
| Sécurité et bonnes pratiques | 5 |
| Total | 100 |

Le seuil interne recommandé est de 85/100. Une erreur technique importante ou un problème de sécurité bloque la publication, quel que soit le score.
H3. Les trois niveaux de validation du cours
Niveau 1 — Compréhension

L'apprenant peut expliquer les concepts, interpréter les unités, lire les schémas et répondre aux quiz.


Niveau 2 — Réalisation logicielle

L'apprenant sait compiler le firmware, tester les interfaces, calculer les consommations, envoyer des mesures simulées et faire fonctionner l'application Flask.


Niveau 3 — Validation du système

L'apprenant présente les preuves de fonctionnement, les tests de panne, la synchronisation, la documentation et la validation électrique réalisée dans des conditions appropriées.

H4. Point technique à régler avant la production
Le projet doit avoir une configuration matérielle de référence unique avant que tu écrives les scripts définitifs. Il faut notamment confirmer :
- La variante exacte du PZEM-004T V3.0 et son interface de communication.
- Le boîtier de l'ATmega328P, son mode d'horloge et sa configuration de programmation.
- La référence et la capacité de la FRAM.
- La carte SIM800L, sa plage d'alimentation et ses pointes de courant.
- La stratégie de transmission sécurisée compatible avec le modem et l'hébergement choisi.
- La disponibilité effective du réseau 2G et les possibilités réseau du compte PythonAnywhere.
- Les exigences applicables à l'isolation, au boîtier et aux protections du circuit secteur.
La partie GSM doit être conçue avec une solution de production chiffrée et compatible avec le matériel réel. Si le SIM800L ne permet pas une connexion TLS satisfaisante dans la configuration retenue, il faudra étudier une passerelle sécurisée intermédiaire plutôt que d'exposer une API en HTTP non chiffré.
## Conclusion et recommandation
Ce programme respecte la limite de quatre heures tout en conservant les 16 étapes pédagogiques et les 32 vidéos techniques proposées. Il constitue un cours accéléré guidé, pas une promesse de maîtrise complète du matériel et du développement web en quatre heures.

Pour commercialiser la formation sérieusement, je te conseille de préparer d'abord les ressources et le prototype de référence, puis de filmer les vidéos dans l'ordre du programme. Les apprenants disposeront ainsi d'un parcours cohérent, de fichiers testés et d'une méthode de diagnostic reproductible.

Le meilleur critère de réussite pour AlexTech Academy ne sera pas le nombre de vidéos, mais la capacité de l'apprenant à expliquer le fonctionnement du système, reproduire les tests, reconnaître les limites du prototype et justifier ses choix techniques.