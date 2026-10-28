# Annexe B — Corrigés des exercices du chapitre 2

> **À consulter après avoir terminé les exercices.** Toutes les situations décrites sont pédagogiques. Aucune ne demande d'examiner sous tension ni de raccorder une installation secteur.

## B1. Activité 1 — Identifier les composants

### Tableau corrigé

| Élément | Fonction principale | Vérification nécessaire avant utilisation |
|---|---|---|
| **ATmega328P** | Exécuter le programme et traiter les relevés | Référence, tension, fréquence d'horloge, brochage |
| **PZEM-004T V3.0** | Fournir des grandeurs électriques et un index d'énergie | Variante, capteur compatible, isolation, documentation, intervention qualifiée pour le secteur |
| **DS3231** | Fournir la date et l'heure | Tension, interface I2C, pile adaptée et éventuel circuit de charge du module |
| **LCD I2C 20×4** | Présenter des informations sur quatre lignes de vingt caractères | Tension, adaptateur et adresse I2C |
| **FRAM** | Conserver des données en mémoire non volatile | Tension, interface, capacité, adresse et compatibilité des niveaux |
| **SIM800L** | Assurer la communication GSM/GPRS avec un réseau compatible | Référence exacte, VBAT, courant de pointe, niveaux UART, réseau et antenne |
| **LED** | Indiquer visuellement un état | Résistance de limitation du courant et polarité |
| **Bouton** | Permettre une commande | Configuration de l'entrée et anti-rebond |
| **Buzzer** | Signaler un événement par le son | Tension, courant et étage de commande éventuel |

### Phrases complétées

1. « L'horloge DS3231 indique **la date et l'heure**, alors que la FRAM conserve **des valeurs et des enregistrements**, si le logiciel les y écrit. »
2. « Le SIM800L sert à **transmettre des données sur un réseau mobile compatible** et non à mesurer directement **les grandeurs électriques**. »

### Ce qu'il fallait surtout comprendre

Le **DS3231** ne remplace pas la mémoire de relevés ; la **FRAM** ne remplace pas l'horloge ; le **SIM800L** ne remplace pas le module de mesure. Confondre ces rôles peut conduire à une architecture qui semble complète sur le papier mais ne répond pas à ses objectifs.

Par ailleurs, deux modules de la même famille peuvent différer par leur carte d'adaptation, leur tension et leur connectique. L'identification d'une référence est un véritable travail technique, pas une formalité.

## B2. Activité 2 — Reconnaître les situations dangereuses

### Situation A — Appliquer 5 V directement au VBAT d'un SIM800L nu

**Risque :** dépasser la plage d'alimentation spécifiée et endommager le modem. Dans notre étude, un module SIM800L nu nécessite généralement une tension autour de 4,0 V, sous réserve de sa fiche technique exacte, et peut demander des pointes proches de 2 A lors de l'émission.

**À vérifier :** la référence précise du modem ou de la carte commerciale, la présence d'un éventuel régulateur, la plage de tension de l'entrée concernée, les courants et le besoin de découplage.

**Décision sûre :** ne pas effectuer le branchement proposé ; utiliser une alimentation adaptée **uniquement après vérification de la documentation et de la conception**.

### Situation B — Introduire le secteur 230 V sur une breadboard

**Risque :** contact avec une tension dangereuse, échauffement, défaut d'isolation, électrisation, électrocution ou incendie. Une plaque d'essai pédagogique n'est pas destinée aux circuits secteur.

**À vérifier :** les exigences de sécurité du système, les protections, les distances d'isolement, le boîtier et les méthodes d'essai encadrées.

**Décision sûre :** abandonner cette expérience sur breadboard. Pour apprendre, utiliser la simulation ou des circuits basse tension appropriés ; réserver toute validation de la partie secteur à une personne qualifiée.

### Situation C — Connecter directement une sortie UART 5 V à un modem dont les niveaux sont inconnus

**Risque :** appliquer un niveau électrique non autorisé à une entrée du modem, provoquer une dégradation ou des communications erratiques.

**À vérifier :** les seuils logiques autorisés à chaque entrée et les niveaux produits à chaque sortie, **dans les deux directions de la liaison**, ainsi que les conditions de référence électrique et d'isolation.

**Décision sûre :** ne pas relier les signaux avant d'avoir vérifié la documentation et prévu une adaptation appropriée.

### Quel premier exercice choisir ?

**Réponse correcte :** **faire clignoter la LED intégrée d'une Arduino Uno alimentée correctement par USB**.

C'est un exercice basse tension utile pour apprendre la programmation. Il ne nécessite aucun raccordement au secteur. Les deux autres propositions impliquent une intervention dangereuse et ne conviennent pas aux débutants.

### Barème proposé

Pour chacune des trois situations : 1 point pour le risque identifié et 2 points pour une décision sûre justifiée (soit 9 points). Le choix correct de l'exercice basse tension ajoute 1 point. Un résultat de **8/10** est souhaitable ; toutefois, toute incompréhension concernant le secteur ou la tension du modem doit être corrigée avant les travaux pratiques.

## B3. Quiz — Réponses et explications

| Question | Bonne réponse | Pourquoi ? |
|---|---|---|
| 1 | **B** | L'ATmega328P est le microcontrôleur qui exécute le programme. |
| 2 | **C** | Le PZEM-004T fournit des grandeurs électriques et l'index d'énergie. |
| 3 | **A** | Le DS3231 fournit la date et l'heure. |
| 4 | **D** | Notre configuration pédagogique d'ATmega328P utilise 5 V et 16 MHz. |
| 5 | **B** | Un SIM800L nu demande typiquement environ 4 V et une alimentation capable de supporter ses pointes de courant. |
| 6 | **C** | Une LED sur Arduino Uno correctement alimentée par USB est un exercice basse tension adapté. |
| 7 | **A** | Un synoptique montre les fonctions, pas les protections et les détails d'un câblage secteur validé. |
| 8 | **D** | Une isolation électrique appropriée contribue à séparer les parties dangereuses des parties accessibles. |
| 9 | **C** | Un modem qui redémarre lors de l'émission peut signaler une alimentation instable ou insuffisamment dimensionnée. |
| 10 | **A** | Des signaux de communication doivent avoir des niveaux électriques compatibles dans les deux sens. |

### Explications complémentaires sur les questions critiques

**Question 5 :** « environ 4 V » ne s'applique pas aveuglément à toutes les cartes vendues comme SIM800L. Certaines possèdent une régulation intégrée. Il faut toujours identifier l'entrée d'alimentation du modèle réel. Il ne faut **jamais** tester arbitrairement le 5 V sur le VBAT d'un module nu.

**Question 6 :** l'alimentation USB sûre d'une carte d'apprentissage ne donne pas le droit de manipuler une alimentation secteur ouverte ou de raccorder une plaque d'essai au réseau domestique.

**Question 7 :** une figure fonctionnelle ne précise pas les distances d'isolement, les fusibles, les câbles appropriés, la qualification des éléments ni les essais de sécurité.

**Question 8 :** une séparation d'isolement est nécessaire dans certaines architectures, mais la sécurité dépend également de l'ensemble : alimentation, boîtier, protections, implantation et validation.

**Question 9 :** un redémarrage pendant une émission radio peut avoir plusieurs causes. La première hypothèse étudiée ici est l'alimentation, **pas** une permission d'augmenter sa tension au-delà de la plage nominale.

**Question 10 :** le croisement des lignes TX/RX, quand il est applicable, ne suffit pas. L'alimentation, les seuils des entrées/sorties, l'adaptation logique et les conditions de référence des signaux doivent être vérifiés.

## B4. Contrôle final des acquis

Avant de commencer le chapitre 3, assurez-vous de pouvoir dire, sans aide :

- pourquoi la puce ATmega328P et le module PZEM ne remplissent pas le même rôle ;
- pourquoi une RTC ne suffit pas à enregistrer un historique ;
- pourquoi on ne donne pas systématiquement 5 V à tous les modules ;
- pourquoi une source capable de fournir des pointes de courant est importante pour le modem ;
- pourquoi une breadboard ne doit pas recevoir le réseau secteur ;
- comment commencer à programmer en basse tension, sans tester le secteur.

Si une de ces réponses n'est pas claire, reprenez la partie correspondante du chapitre 2 avant la première manipulation.
