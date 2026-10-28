# Chapitre 1 — Découvrir le compteur et comprendre l'électricité

> **Correspondance exacte avec les vidéos :** M01-V01 « Du réseau électrique au tableau de bord IoT » (5 min), puis M01-V02 « Comprendre volts, ampères, watts et kilowattheures » (5 min).  
> **Niveau :** débutant absolu. **État du manuscrit :** première relecture technique, pédagogique et éditoriale effectuée ; validation finale de l'auteur et mise en page à réaliser.  
> **Activités :** 25 à 40 minutes de travail personnel, indépendamment des dix minutes de vidéos.  
> **Sécurité :** aucune manipulation du secteur ni aucun câblage 230 V.

## Ce que vous saurez faire après ce chapitre

À la fin de cette lecture, vous pourrez :

1. décrire le trajet d'un relevé entre un module de mesure et un navigateur web ;
2. expliquer le rôle de l'ATmega328P, du PZEM-004T, du DS3231, de l'écran LCD, de la FRAM, du SIM800L et du serveur ;
3. distinguer **tension (V)**, **courant (A)**, **puissance active (W)** et **énergie (Wh, kWh)** ;
4. calculer une consommation simple lorsque la puissance active est constante ;
5. expliquer pourquoi on ne peut pas connaître l'énergie consommée pendant une journée à partir d'une unique valeur de puissance instantanée.

Aucun bagage préalable en programmation n'est nécessaire. Une feuille, un crayon et une calculatrice facultative suffisent.

---

## Partie A — Vidéo M01-V01 : du réseau électrique au tableau de bord IoT

### 1.1. Pourquoi surveiller sa consommation d'énergie ?

Imaginez une maison dans laquelle plusieurs appareils électriques fonctionnent : éclairage, téléviseur, réfrigérateur ou ventilateur. Une mesure de la consommation peut répondre à des questions pratiques :

- Quelle quantité d'énergie a été consommée **aujourd'hui** ?
- Quelle quantité a été consommée **depuis le début du mois** ?
- Quelle était la **tension mesurée** au moment du dernier relevé ?
- Peut-on consulter ces informations sur un téléphone, sans se déplacer devant le compteur ?

Un appareil « intelligent » ne se résume pas à un écran. Pour répondre à ces questions, il lui faut **obtenir des mesures**, **les traiter**, **leur associer une date**, éventuellement **les conserver** et **les rendre consultables**.

C'est le but pédagogique de notre projet : réaliser un **prototype de suivi énergétique connecté**, construit progressivement avec un microcontrôleur ATmega328P et une application web.

**Limite importante.** Un prototype qui calcule et affiche des kWh n'est pas automatiquement un compteur réglementaire certifié. Ce livre n'enseigne pas la fabrication d'un instrument de facturation homologué.

### 1.2. Une lecture fictive de notre futur compteur

Considérons l'affichage d'exemple suivant :

~~~text
+--------------------+
| DATE : JJ/MM/AAAA  |
| TENSION : 230,5 V  |
| JOUR : 4,25 kWh    |
| MOIS : 125,48 kWh  |
+--------------------+
~~~

**Toutes ces valeurs sont fictives.** Elles servent uniquement à découvrir ce que l'utilisateur pourra lire sur l'écran LCD I2C 20×4. Elles ne proviennent pas d'un montage branché au secteur.

À quoi correspondent les trois nombres ?

- **230,5 V** représente une valeur de tension à un instant de mesure ;
- **4,25 kWh** représente l'énergie attribuée à une journée de consommation ;
- **125,48 kWh** représente l'énergie attribuée au mois considéré, jusqu'au dernier relevé.

Les deux dernières valeurs sont des **cumuls sur des périodes**. Elles ne sont pas obtenues en multipliant aveuglément la puissance actuellement affichée par 24 heures ou par 30 jours.

Le module M08 expliquera le calcul de ces cumuls à partir d'un index d'énergie et de dates suffisamment fiables. Dans le prototype réel, lorsqu'une frontière de période n'est pas connue précisément, une consommation partielle ne doit pas être présentée comme une mesure complète.

### 1.3. L'architecture du compteur : suivre un relevé

Voici le **synoptique fonctionnel** de l'architecture visée :

~~~mermaid
flowchart TD
  P["PZEM-004T V3.0 : mesures et index d'énergie"] --> M["ATmega328P : contrôle et calcul"]
  R["DS3231 : date et heure"] --> M
  M <--> F["FRAM I2C : enregistrements conservés"]
  M --> L["LCD I2C 20×4 : affichage local"]
  M --> G["SIM800L : transmission GSM/GPRS"]
  G --> A["API Python Flask : réception"]
  A --> B["SQLite : relevés et historiques"]
  B --> W["Jinja2 / HTML / CSS / JavaScript : tableau de bord"]
~~~

**Figure 1.1 — Trajet des données prévu pour le compteur intelligent.** Ce dessin montre des échanges d'informations ; **ce n'est pas un schéma de raccordement électrique**. Les alimentations, interfaces, protections et éventuelles barrières d'isolation ne sont pas représentées. Les flèches indiquent des fonctions prévues, et non la validation d'une chaîne GSM–serveur déjà opérationnelle.

Nous pouvons lire le synoptique comme une petite histoire :

**Étape 1 — Mesurer.** Le PZEM-004T V3.0 est un module spécialisé qui fournit notamment la tension, le courant, la puissance active et un index d'énergie cumulée. Il ne remplace pas à lui seul l'application complète de suivi.

**Étape 2 — Traiter.** L'ATmega328P lit les informations, vérifie les données disponibles et organise les calculs. C'est le microcontrôleur : une petite puce qui exécute un programme embarqué, aussi appelé *firmware*.

**Étape 3 — Dater.** Le DS3231 est une horloge temps réel, ou **RTC** (*Real-Time Clock*). Elle apporte une référence de date et d'heure, utile pour rattacher un relevé à la bonne journée et au bon mois.

**Étape 4 — Afficher sur place.** Le LCD 20×4 présente quatre lignes de vingt caractères. L'utilisateur peut lire les données essentielles sans ouvrir de page web.

**Étape 5 — Conserver en local.** Une mémoire **FRAM** est prévue pour stocker durablement des informations et des relevés en attente de transmission. Contrairement à une mémoire vive ordinaire, elle peut conserver ses données sans alimentation ; il faudra néanmoins vérifier que le programme les y écrit effectivement et gère correctement les interruptions d'alimentation.

**Étape 6 — Transmettre.** Le SIM800L est le modem GSM/GPRS retenu. Lorsque le réseau, la carte SIM, l'alimentation et le service de données sont compatibles et disponibles, il doit permettre l'envoi des relevés. **La disponibilité du GPRS ne garantit pas à elle seule la confidentialité ni l'authenticité des messages** : une solution de transport protégée, compatible avec le modem et le serveur (au besoin avec passerelle), devra être vérifiée avant l'envoi de données réelles.

**Étape 7 — Enregistrer sur le serveur.** Une application Python construite avec **Flask** doit recevoir et contrôler les messages, puis utiliser **SQLite** pour conserver les informations dans une base de données.

**Étape 8 — Consulter.** Une interface générée avec **Jinja2** et du HTML, enrichie de CSS et de JavaScript, doit montrer les derniers relevés et leur historique.

En résumé, le trajet principal est :

**PZEM → ATmega328P → SIM800L → Flask → SQLite → navigateur.**

Le DS3231, la FRAM et le LCD sont des branches utiles du système, pas des étapes obligatoires dans le trajet d'un paquet GSM.

#### Tableau 1.1 — Rôles sans confusion

| Élément | Son rôle | Ce qu'il ne fait pas à lui seul |
|---|---|---|
| PZEM-004T V3.0 | Acquérir les grandeurs électriques | Héberger une page web |
| ATmega328P | Exécuter les règles du compteur | Fournir une connectivité GSM sans modem |
| DS3231 | Fournir une date et une heure | Mesurer des kWh |
| LCD I2C 20×4 | Présenter des informations localement | Sauvegarder l'historique distant |
| FRAM | Conserver localement des données | Transmettre sur un réseau mobile |
| SIM800L | Communiquer sur un réseau GSM/GPRS compatible | Mesurer la tension secteur |
| Flask | Recevoir et traiter les messages | Réaliser lui-même l'acquisition physique |
| SQLite | Organiser les relevés sauvegardés | Piloter directement le PZEM |
| Navigateur | Afficher les informations à l'utilisateur | Remplacer le serveur et la chaîne d'acquisition |

### 1.4. Qu'arrive-t-il si Internet ou le réseau mobile n'est plus disponible ?

Un compteur de suivi énergétique doit continuer à remplir ses fonctions locales autant que son architecture le permet. Le **LCD** n'a pas besoin d'une connexion Internet pour afficher une mesure locale disponible.

Pour l'envoi distant, le projet prévoit la stratégie suivante :

1. Un relevé est créé avec un identifiant et une référence temporelle.
2. Si le réseau mobile est indisponible, le relevé est conservé dans une file locale persistante.
3. Lors du retour du réseau, les relevés non transmis sont renvoyés.
4. Le serveur doit reconnaître les duplications éventuelles afin de ne pas compter deux fois la même consommation.

C'est une **architecture prévue**, pas une fonction déjà démontrée par le prototype actuel. La FRAM et la synchronisation seront développées dans **M11** ; les échanges GSM/GPRS dans **M10**. Une coupure de courant ou une absence de date fiable présente des difficultés supplémentaires, étudiées dans les chapitres correspondants.

### 1.5. Ce qui existe dans le dépôt aujourd'hui

Le projet logiciel suit une progression cumulative. Au moment de cette première rédaction :

- des étapes du firmware allant de **M03 à M09** sont publiées ;
- la simulation reste le mode de démonstration par défaut ;
- des calculs d'énergie, des dates et un affichage optionnel sont introduits au fil des étapes ;
- l'intégration réelle du **SIM800L**, de la **FRAM** et de l'application web finale n'est pas encore démontrée dans le firmware courant ;
- les validations sur montage physique ne doivent pas être supposées.

Le matériel de référence documente déjà les choix de communication : **SIM800L sur UART matériel D0/D1**, **PZEM sur D10/D11 par SoftwareSerial**, **DS3231/LCD/FRAM sur I2C A4/A5** à partir de M10. Nous ne les câblons pas dans ce chapitre introductif.

#### Pause de compréhension

Sans regarder le schéma, répondez oralement :

- Quel composant produit les mesures ?
- Quel composant exécute le programme ?
- Quel composant permet l'affichage sans navigateur ?
- Où l'historique doit-il être enregistré ?
- Quel équipement fait le lien avec le réseau mobile ?

Si l'une de ces réponses vous échappe, relisez les étapes 1 à 8. Le but n'est pas de retenir des sigles par cœur, mais d'identifier **qui fait quoi**.

---

## Partie B — Vidéo M01-V02 : volts, ampères, watts et kilowattheures

### 1.6. Quatre mots pour comprendre un relevé électrique

Un compteur reçoit des nombres. Mais un nombre isolé, par exemple « 230 », ne nous apprend presque rien. Il faut savoir **ce que l'on mesure** et **avec quelle unité**.

#### La tension électrique : U, en volts (V)

La tension entre deux points est une **différence de potentiel électrique**. Pour débuter, on peut l'imaginer comme une différence de pression qui aide à faire circuler un fluide dans un tuyau. Cette image facilite l'intuition, sans décrire complètement le comportement de l'électricité.

Une indication de **5 V** sur un circuit électronique et une indication de **230 V** sur une installation n'ont pas la même portée pratique. Dans les deux cas, le symbole **V** indique des volts ; dans le second, le danger électrique rend toute manipulation réservée à des personnes qualifiées.

Le symbole de grandeur utilisé dans ce livre est **U** ; celui de l'unité est **V**.

#### Le courant électrique : I, en ampères (A)

Le courant représente le **débit de charges électriques** traversant une section d'un conducteur. Son symbole de grandeur est **I** et son unité est l'**ampère (A)**.

Dans l'analogie du circuit d'eau, le courant ressemble au débit : combien passe pendant une durée donnée. Une tension n'est donc pas un courant, tout comme une pression n'est pas un débit.

#### La puissance active : P, en watts (W)

La puissance décrit un **rythme de transfert ou d'utilisation de l'énergie**. Pour nos calculs de consommation, nous nous intéressons à la puissance **active**, notée **P**, mesurée en **watts (W)**.

- **1 kW = 1 000 W**.
- Un appareil utilisant 500 W de puissance active utilise une puissance de **0,5 kW**.
- Le watt est une unité de **puissance** ; ce n'est pas une unité d'énergie consommée pendant une journée.

**Attention au courant alternatif.** Dans un circuit continu simple, la relation P = U × I est souvent utilisable. Sur un réseau alternatif, le produit des valeurs efficaces de tension et de courant donne la **puissance apparente**, exprimée en **voltampères (VA)**. La puissance active (W) fait intervenir les caractéristiques de la charge et notamment son **facteur de puissance**. Nous ne remplacerons donc pas systématiquement une mesure de puissance active par U × I.

Le module PZEM-004T fournit directement une mesure de puissance active, sous réserve de son exactitude, de son câblage correct et des vérifications nécessaires.

#### L'énergie : E, en wattheures ou kilowattheures

L'énergie répond à une question différente : **quelle quantité a été consommée pendant une durée ?**

L'énergie peut s'exprimer en **Wh** ou en **kWh** :

- **1 kWh = 1 000 Wh** ;
- **1 kWh** correspond, par exemple, à **1 kW de puissance active constante pendant 1 heure** ;
- deux appareils de puissances différentes peuvent consommer la même énergie s'ils fonctionnent pendant des durées différentes.

#### Tableau 1.2 — La fiche à mémoriser

| Grandeur | Symbole | Unité | Symbole de l'unité | Question à se poser |
|---|---|---|---|---|
| Tension | U | Volt | V | Quelle différence de potentiel ? |
| Courant | I | Ampère | A | Quel débit de charges ? |
| Puissance active | P | Watt | W | À quel rythme l'énergie est-elle utilisée ? |
| Énergie | E | Wattheure, kilowattheure | Wh, kWh | Quelle quantité sur une durée ? |

### 1.7. Calculer l'énergie d'un appareil à puissance constante

Lorsque la **puissance active reste constante** pendant l'intervalle étudié :

**Énergie (kWh) = Puissance active (kW) × Durée (h).**

Écrit avec des symboles :

**E = P × t**, en choisissant des unités cohérentes.

Avant de calculer, appliquez toujours cette méthode :

1. Identifiez la puissance **active**.
2. Convertissez les watts en **kilowatts** : divisez par 1 000.
3. Convertissez la durée en **heures** : divisez les minutes par 60.
4. Multipliez puissance en kW × durée en h.
5. Vérifiez que la réponse est bien exprimée en **kWh**.

#### Exemple 1 — Une charge de 500 W pendant 4 heures

La charge utilise une puissance active constante de **500 W**.

- Conversion : 500 ÷ 1 000 = **0,5 kW**.
- Durée : **4 h**.
- Calcul : 0,5 × 4 = **2 kWh**.

**Résultat : 2 kWh.** Le nombre de kilowattheures est ici différent du nombre de kilowatts.

#### Exemple 2 — Une charge de 2 000 W pendant 30 minutes

- Puissance : 2 000 W = **2 kW**.
- Durée : 30 ÷ 60 = **0,5 h**.
- Énergie : 2 × 0,5 = **1 kWh**.

**Résultat : 1 kWh.**

Cet exemple montre pourquoi la conversion des minutes est indispensable : utiliser « 30 » au lieu de « 0,5 » serait une erreur majeure.

#### Exemple 3 — Une charge de 200 W pendant 5 heures

- 200 W = **0,2 kW**.
- E = 0,2 × 5 = **1 kWh**.

Une petite puissance utilisée longtemps peut donc conduire à la même énergie qu'une puissance élevée utilisée brièvement.

#### Exemple 4 — Une charge de 100 W pendant 15 minutes

- 100 W = **0,1 kW**.
- 15 minutes = **0,25 h**.
- E = 0,1 × 0,25 = **0,025 kWh** = **25 Wh**.

Les deux dernières valeurs expriment la même énergie avec deux unités différentes.

### 1.8. Et si la puissance varie pendant l'utilisation ?

La formule précédente suppose **une puissance active constante** pendant toute la durée. Dans une maison, les appareils s'allument, s'arrêtent et changent parfois de régime : la puissance n'est donc pas toujours constante.

Si elle varie, l'énergie totale correspond à l'accumulation de l'énergie sur toute la période. On peut approximer cette énergie en additionnant de petits intervalles successifs, ou exploiter un **index cumulatif** mesuré par un module approprié.

#### Exemple fictif : suivre un index d'énergie

Imaginons les valeurs d'index suivantes, **entièrement simulées** :

| Relevé | Index d'énergie cumulée |
|---|---:|
| Au début de la journée | 1 250,50 kWh |
| À la fin de cette journée | 1 254,75 kWh |

**Consommation de la journée = 1 254,75 − 1 250,50 = 4,25 kWh.**

Pour le mois, supposons qu'un index **1 129,27 kWh** ait été enregistré au début de la période et que l'index courant soit toujours **1 254,75 kWh** :

**Consommation depuis le début du mois = 1 254,75 − 1 129,27 = 125,48 kWh.**

Nous retrouvons volontairement les valeurs de notre exemple d'écran LCD. Cette démonstration explique **l'idée mathématique**, pas la fiabilité d'un calcul réel en cas de coupure, de remise à zéro de l'index ou de date manquante.

Dans le chapitre 8, nous traiterons précisément les passages à minuit, les changements de mois, les redémarrages et la distinction entre **période complète** et **période partielle**.

### 1.9. Les erreurs fréquentes que nous devons éviter

**Erreur 1 — « 1 kW est égal à 1 kWh ».** Non : le premier exprime une puissance, le second une énergie. Il faut une durée pour passer de l'une à l'autre dans notre exemple à puissance constante.

**Erreur 2 — « 500 W pendant une heure font 500 kWh ».** Non : cela fait **500 Wh**, soit **0,5 kWh**.

**Erreur 3 — « Tension × courant fournit toujours la puissance active ».** Non : sur un réseau alternatif, il faut distinguer les puissances active et apparente et tenir compte du facteur de puissance approprié.

**Erreur 4 — « Une seule mesure de puissance instantanée donne la consommation exacte du jour ».** Non : cette puissance peut varier. L'index d'énergie et l'horodatage permettent de construire une méthode plus adaptée.

**Erreur 5 — « Il faut remettre le PZEM à zéro chaque minuit ».** Non : pour notre architecture, les consommations journalières et mensuelles sont construites à partir des index et de références de période. Modifier l'index global peut compromettre le suivi ; nous expliquerons les précautions dans le module M08.

**Erreur 6 — « Un écran avec des nombres prouve qu'on a mesuré le secteur ».** Non : une maquette peut montrer exactement ces nombres. Une **donnée simulée** reste une donnée simulée.

---

## Partie C — Mettre ses connaissances en pratique

### 1.10. Activité 1 — Reconstituer le trajet d'un relevé

**Durée indicative :** 10 minutes. **Matériel :** papier et crayon. **Aucun équipement sous tension.**

Les cinq cartes suivantes sont présentées dans le désordre :

- Navigateur web
- ATmega328P
- Serveur Flask / base SQLite
- PZEM-004T
- Modem SIM800L

**Travail demandé :**

1. Dessinez cinq rectangles et replacez-les dans l'ordre de circulation d'un relevé.
2. Reliez chaque rectangle au verbe qui lui correspond : **mesurer**, **traiter**, **transmettre**, **enregistrer**, **consulter**.
3. Ajoutez sur votre dessin, à côté de l'ATmega328P, les éléments **DS3231**, **LCD** et **FRAM**. Précisez leur rôle sans les insérer artificiellement dans le trajet du réseau GSM.

**Critère de réussite :** vous savez expliquer votre dessin à une personne qui n'a jamais utilisé Arduino.

### 1.11. Activité 2 — Calculer quatre consommations

**Durée indicative :** 15 minutes. **Matériel :** feuille et calculatrice facultative.

Toutes les puissances ci-dessous sont des **puissances actives supposées constantes**.

| Cas | Puissance | Durée | Votre résultat en kWh |
|---|---:|---:|---|
| A | 200 W | 5 h | … |
| B | 500 W | 4 h | … |
| C | 2 000 W | 30 min | … |
| D | 100 W | 15 min | … |

Pour chaque ligne, écrivez les conversions et le calcul. Ne vous contentez pas d'inscrire le résultat.

**Questions supplémentaires :**

- Pourquoi une puissance instantanée ne suffit-elle pas toujours à déterminer l'énergie d'une journée ?
- Pourquoi « 500 W » et « 500 Wh » ne désignent-ils pas la même chose ?
- Dans le tableau, quel cas présente la plus faible énergie ?

### 1.12. Autoévaluation — Six questions essentielles

Répondez sans revenir aux sections précédentes :

1. Quelle différence y a-t-il entre le PZEM et l'ATmega328P ?
2. À quoi sert le DS3231 lorsqu'on calcule une consommation mensuelle ?
3. À quoi sert le SIM800L dans l'architecture prévue ?
4. Une puissance active de 400 W maintenue pendant 2 h 30 représente quelle énergie ?
5. Quelles unités sont associées à la tension, au courant, à la puissance active et à l'énergie ?
6. Pourquoi ne faut-il pas présenter une capture d'écran de données fictives comme une mesure réelle ?

Pour le **quiz officiel de dix questions du module M01**, consulter la [version apprenant](../../formation/modules/M01-decouverte-electricite/quiz/QUIZ_M01_APPRENANT.md). Le seuil de réussite fixé par la formation est de **8 bonnes réponses sur 10**.

Les **corrigés détaillés des activités et de l'autoévaluation** sont fournis dans une [annexe de correction distincte](../annexes/CORRIGE_M01.md) : consultez-la seulement après avoir effectué les exercices. Les [TP et quiz officiels pour les apprenants](../../formation/modules/M01-decouverte-electricite/README.md#documents-pour-les-apprenants) restent les références du module.


---

## Partie D — Retenir l'essentiel et poursuivre

### 1.13. La synthèse du chapitre en cinq phrases

1. Notre compteur intelligent est une **chaîne fonctionnelle**, pas un seul capteur.
2. Le PZEM mesure, l'ATmega328P traite et le LCD affiche localement.
3. Le DS3231 fournit une date de référence ; la FRAM et le SIM800L ajouteront conservation et transmission lorsqu'ils seront intégrés et validés.
4. Le **watt (W)** mesure une puissance ; le **kilowattheure (kWh)** mesure une quantité d'énergie.
5. Les consommations d'une journée ou d'un mois nécessitent des **informations temporelles et énergétiques cohérentes** ; une simulation ne vaut jamais preuve de mesure réelle.

### 1.14. Petit lexique de fin de chapitre

| Terme | Définition rapide |
|---|---|
| **IoT** | Internet des objets : équipements physiques capables d'échanger des informations |
| **Microcontrôleur** | Puce programmable qui exécute un programme embarqué |
| **Firmware** | Programme installé dans un équipement électronique |
| **RTC** | Horloge temps réel fournissant date et heure |
| **Index d'énergie** | Valeur cumulative d'énergie permettant des différences entre relevés |
| **GSM/GPRS** | Technologies mobiles utilisées pour établir une transmission de données compatible |
| **API** | Interface de communication entre programmes |
| **SQLite** | Base de données utilisable dans une application serveur |

### 1.15. Pour aller plus loin

Les documents techniques et pédagogiques suivants sont les **références vivantes du projet** :

- [Script de la vidéo M01-V01](../../formation/modules/M01-decouverte-electricite/scripts/V01-script.md)
- [Script de la vidéo M01-V02](../../formation/modules/M01-decouverte-electricite/scripts/V02-script.md)
- [Fiche des grandeurs électriques](../../formation/modules/M01-decouverte-electricite/ressources/FICHE_UNITES.md)
- [Synoptique fonctionnel](../../formation/modules/M01-decouverte-electricite/ressources/SYNOPTIQUE.md)
- [Démonstration web fictive](../../formation/modules/M01-decouverte-electricite/ressources/demo_dashboard_fictif.html)
- [Journal d'évolution du firmware](../../firmware/PROGRESSION.md)
- [Plan officiel des 16 modules](../../docs/formation/PLAN_FORMATION_4H.md)

**Chapitre suivant — M02 :** nous identifierons les composants, les alimentations et les règles de sécurité. Nous ne réaliserons toujours **aucun essai secteur pour débutant**.

[← Retour au sommaire](../README.md)
