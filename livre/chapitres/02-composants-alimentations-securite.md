# Chapitre 2 — Identifier les composants et travailler en sécurité

> **Niveau :** débutant, après le chapitre 1.  
> **Temps de pratique conseillé :** 30 à 45 minutes, sans compter la lecture.  
> **Règle de sécurité :** toutes les activités de ce chapitre se font **hors tension, sur papier ou en basse tension sûre**. Aucun raccordement au secteur 230 V n'est demandé.

Au chapitre précédent, nous avons découvert le chemin suivi par une mesure électrique, depuis son acquisition jusqu'à son affichage sur une page web. Nous avons aussi distingué la tension, le courant, la puissance et l'énergie.

Mais un schéma fonctionnel ne nous dit pas encore **comment reconnaître les composants**, **comment leur fournir l'énergie dont ils ont besoin** ni **comment éviter les situations dangereuses**.

Dans ce chapitre, nous apprendrons à poser les bonnes questions *avant* de brancher un fil. Cette démarche est aussi importante que l'écriture d'un programme : un composant bien programmé peut être détruit par une alimentation incorrecte.

## Les objectifs du chapitre

Après cette lecture, vous pourrez :

1. identifier les principaux composants de notre compteur intelligent et décrire leur fonction ;
2. distinguer le circuit de mesure, le traitement, la mémoire, l'affichage et la communication ;
3. expliquer la différence entre le courant alternatif (AC) et le courant continu (DC) ;
4. reconnaître les principaux domaines d'alimentation, notamment **5 V pour notre logique ATmega328P** et **environ 4,0 V pour un SIM800L nu** ;
5. expliquer les rôles de l'isolation, du découplage, des protections et du boîtier ;
6. choisir une activité d'apprentissage réalisable sans intervention sur le réseau électrique.

---

## Partie A — Reconnaître les composants du compteur intelligent

### 2.1. Un compteur composé de plusieurs fonctions

Un dispositif électronique complet fonctionne rarement avec une seule pièce. Notre compteur intelligent associe plusieurs sous-ensembles, comme les membres d'une équipe.

| Fonction | Composant principal | Question à laquelle il répond |
|---|---|---|
| Mesurer | PZEM-004T V3.0 et capteur de courant compatible | Que se passe-t-il électriquement ? |
| Traiter | ATmega328P | Que doit faire le système de ces mesures ? |
| Dater | DS3231 | Quand le relevé a-t-il été effectué ? |
| Afficher localement | LCD I2C 20×4 | Que peut lire l'utilisateur devant l'appareil ? |
| Conserver | FRAM non volatile | Que faut-il garder même sans alimentation ? |
| Communiquer | SIM800L | Comment envoyer un relevé à distance ? |
| Recevoir et présenter | Application Flask, SQLite et interface web | Comment consulter l'historique ? |

Le tableau présente des **fonctions**. Il ne constitue ni un schéma de câblage ni une preuve que tous les sous-ensembles sont déjà intégrés et testés.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.1
Type : planche photographique annotée.
Contenu et annotations : Présentation visuelle des principaux composants ATmega328P, Uno Rev3, PZEM V3, DS3231, LCD I2C, FRAM et SIM800L, regroupés par fonction, chaque nom lisible.
Légende finale : Figure 2.1 — Les composants principaux du compteur intelligent, regroupés par fonction.
Texte alternatif : Planche de cartes électroniques et de modules identifiés comme acquisition, traitement, date, affichage, mémoire et transmission.
Contraintes : Photos réelles de références vérifiées et hors tension ; pas d'illustration de câblage secteur ; droits à documenter.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.1]** *planche photographique annotée.* : Présentation visuelle des principaux composants ATmega328P, Uno Rev3, PZEM V3, DS3231, LCD I2C, FRAM et SIM800L, regroupés par fonction, chaque nom…


**Figure 2.1 — Les composants principaux du compteur intelligent, regroupés par fonction.**

Pour apprendre à reconnaître le matériel, commencez par examiner les inscriptions imprimées sur les cartes : nom, référence, révision, fabricant et indications de tension. La photographie d'un composant peut aider, mais elle ne suffit pas à déterminer toutes ses caractéristiques.

**Réflexe à adopter :** avant de raccorder un module, identifier sa **référence exacte** et trouver une documentation technique correspondant à cette référence. Deux cartes commerciales portant presque le même nom peuvent posséder des régulateurs, des connexions ou des niveaux logiques différents.

### 2.2. L'ATmega328P : le cerveau programmable


L'**ATmega328P** est un microcontrôleur : un circuit intégré capable d'exécuter les instructions d'un programme. Il dispose de mémoire, de broches d'entrée/sortie et de périphériques de communication.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.2
Type : photo comparative annotée.
Contenu et annotations : Placer côte à côte un ATmega328P PDIP-28 et une carte Arduino Uno Rev3, indiquer la puce sur la carte et légender les deux objets.
Légende finale : Figure 2.2 — Le microcontrôleur ATmega328P et sa carte d'apprentissage Arduino Uno.
Texte alternatif : Une puce ATmega328P à vingt-huit broches est présentée à côté d'une carte Arduino Uno Rev3, avec identification de la puce sur la carte.
Contraintes : Matériel photographié hors tension ; modèle réel identifiable et photo autorisée.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.2]** *photo comparative annotée.* : Placer côte à côte un ATmega328P PDIP-28 et une carte Arduino Uno Rev3, indiquer la puce sur la carte et légender les deux objets.


**Figure 2.2 — Le microcontrôleur ATmega328P et sa carte d'apprentissage Arduino Uno.**

Dans notre projet, il assure notamment les tâches suivantes :

- recevoir les mesures acquises par le PZEM ;
- associer une date à chaque relevé ;
- organiser les calculs de consommation du jour et du mois ;
- préparer les données à afficher et à transmettre ;
- piloter des indications locales, comme une LED ou un écran.

Au début de notre apprentissage, nous utiliserons une **Arduino Uno**. Cette carte est pratique pour écrire, charger et tester les premiers programmes dans **Arduino IDE**, l'environnement de développement que nous découvrirons au chapitre 3.

Plus tard, nous apprendrons à placer l'ATmega328P dans un montage autonome et à le programmer au moyen de la technique **ISP** (*In-System Programming*). La présence d'une Arduino Uno pendant l'apprentissage ne signifie donc pas que la carte entière doit rester à l'intérieur du dispositif final.

Notre configuration pédagogique du microcontrôleur utilise **5 V et une horloge de 16 MHz**. Ces valeurs décrivent **ce choix de conception** ; elles ne signifient pas que tous les microcontrôleurs fonctionnent avec la même tension ou la même fréquence.

**À retenir :** l'ATmega328P exécute les instructions. Il ne mesure pas à lui seul toutes les grandeurs que fournit le PZEM, et ne possède pas de modem GSM intégré.

### 2.3. Le PZEM-004T : acquérir les grandeurs électriques

Le **PZEM-004T V3.0** est le module de mesure retenu pour notre prototype de suivi énergétique. Il permet d'obtenir des informations telles que la tension, le courant, la puissance active et un index d'énergie cumulée. D'autres informations, comme la fréquence et le facteur de puissance, peuvent être disponibles selon la variante et le protocole.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.3
Type : photographie annotée de matériel.
Contenu et annotations : Montrer la carte PZEM-004T V3.0 et son transformateur de courant correspondant, séparés et hors tension ; nommer les pièces sans détailler de raccordement secteur.
Légende finale : Figure 2.3 — Le module de mesure PZEM-004T et son capteur de courant compatible.
Texte alternatif : Photographie du PZEM-004T version 3.0 et du capteur de courant compatible, tous deux non raccordés.
Contraintes : Aucune phase ou borne 230 V accessible, aucun branchement secteur représenté ; référence du capteur et droits vérifiés.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.3]** *photographie annotée de matériel.* : Montrer la carte PZEM-004T V3.0 et son transformateur de courant correspondant, séparés et hors tension ; nommer les pièces sans détailler de racco…


**Figure 2.3 — Le module de mesure PZEM-004T et son capteur de courant compatible.**

Pour mesurer le courant, notre solution prévoit un **capteur de courant compatible** avec la variante sélectionnée. La forme exacte du capteur et les modalités de connexion dépendent du module.

**Attention :** le PZEM est associé à la mesure sur une installation potentiellement dangereuse. Sa présence dans un kit pédagogique n'autorise pas un débutant à le raccorder au réseau domestique.

Dans les premières activités, nous pouvons apprendre la structure des mesures à partir d'exemples fictifs :

| Donnée fictive | Valeur illustrative | Unité |
|---|---:|---|
| Tension | 230,5 | V |
| Courant | 1,20 | A |
| Puissance active | 250 | W |
| Index d'énergie | 1 254,75 | kWh |

Ces nombres sont seulement des **valeurs d'exercice**, pas un relevé cohérent certifié issu d'un appareil réel. En particulier, ne déduisez pas systématiquement la puissance active en multipliant tension et courant : sur le réseau alternatif, le facteur de puissance intervient.

Le chapitre 6 expliquera comment organiser et vérifier les données issues du PZEM. La manipulation de la partie secteur restera réservée à une personne qualifiée.

### 2.4. Le DS3231 : donner une date aux relevés

Le **DS3231** est une horloge temps réel, appelée **RTC** (*Real-Time Clock*). Elle peut fournir une date et une heure même lorsque le microcontrôleur ne calcule rien pendant un certain temps.

Pourquoi cette fonction est-elle importante ? Parce que pour afficher une consommation **du jour**, il faut savoir à quel jour appartiennent les mesures. Pour afficher une consommation **du mois**, il faut aussi reconnaître les changements de mois et d'année.

Une horloge RTC munie d'une **source de sauvegarde adaptée** peut conserver l'heure lorsque l'alimentation principale est coupée. Mais cela ne signifie pas qu'elle enregistre automatiquement tous les historiques : **l'horloge fournit la date, tandis qu'une mémoire ou une base de données conserve les relevés**.

Certaines cartes DS3231 possèdent un logement de pile ou un circuit de charge. Le type de pile et la compatibilité de ce circuit doivent être vérifiés sur la carte réelle. **Ne placez pas une pile non rechargeable dans un support susceptible de la recharger sans avoir vérifié le montage et sa documentation.**

Le DS3231 communique avec le microcontrôleur par un bus appelé **I2C**, que nous étudierons au chapitre 7.

### 2.5. Le LCD 20×4 : lire les informations directement sur place

Un écran **LCD 20×4** peut afficher jusqu'à **20 caractères sur chacune de ses quatre lignes**. Nous lui associerons un adaptateur **I2C**, permettant de limiter le nombre de fils de communication nécessaires avec le microcontrôleur.

Notre objectif d'affichage sera de présenter :

1. la date ;
2. la tension mesurée ;
3. l'énergie du jour ;
4. l'énergie du mois.

Ces valeurs correspondent à des informations très différentes : une valeur de tension est une mesure électrique ; les deux consommations en kWh sont des **cumuls énergétiques associés à une période**.

L'adresse I2C, la tension et le comportement de l'adaptateur dépendent du modèle. Il faut donc vérifier le module réellement acheté avant de choisir les paramètres du programme.

Un écran local n'est pas une base de données : il affiche une information préparée par le microcontrôleur. Il ne garantit pas non plus qu'une mesure soit exacte simplement parce qu'elle est lisible.

### 2.6. La mémoire FRAM : conserver les données importantes

La **FRAM** (*Ferroelectric Random-Access Memory*) est une mémoire **non volatile** : les informations qui y ont été correctement enregistrées peuvent être conservées même après une perte d'alimentation.

Imaginons une mesure prête à être envoyée au serveur alors que le réseau mobile est indisponible. La mémoire peut faire partie de la solution permettant de stocker ce relevé pour une transmission ultérieure.

Cependant, une mémoire non volatile n'accomplit pas automatiquement toutes les tâches du système. Le programme doit lui demander **quoi enregistrer, quand l'enregistrer et comment relire les données**. Il faudra aussi protéger la cohérence des enregistrements en cas de coupure ou de redémarrage.

Notre projet prévoit une **FRAM à interface I2C**. Son modèle exact, son alimentation, sa capacité, son adressage et sa compatibilité avec le bus devront être vérifiés avant le montage.

**Ne confondez pas :** la RTC dit *quand* ; la FRAM conserve *quoi*.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.4
Type : planche photos et pictogrammes.
Contenu et annotations : Juxtaposer un module DS3231, un LCD I2C 20×4 et une carte FRAM I2C, avec trois verbes « dater », « afficher », « sauvegarder ». Repérer l'adaptateur I2C du LCD.
Légende finale : Figure 2.4 — Trois composants complémentaires : horloge, écran et mémoire.
Texte alternatif : DS3231 étiqueté date/heure ; écran LCD étiqueté affichage ; FRAM étiquetée conservation durable des données.
Contraintes : Modules de variantes réellement identifiées ; pile RTC compatible ; éviter toute suggestion que la FRAM produit l'heure.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.4]** *planche photos et pictogrammes.* : Juxtaposer un module DS3231, un LCD I2C 20×4 et une carte FRAM I2C, avec trois verbes « dater », « afficher », « sauvegarder ». Repérer l'adaptateu…


**Figure 2.4 — Trois composants complémentaires : horloge, écran et mémoire.**

### 2.7. Le SIM800L : la communication à distance

Le **SIM800L** est un modem de communication mobile. Il doit permettre au compteur de transmettre des informations en utilisant les services **GSM/GPRS** d'un réseau 2G compatible.

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.5
Type : photographie annotée du modem.
Contenu et annotations : Gros plan du SIM800L réellement retenu, antenne et identification des zones d'alimentation sur la carte ; mention « vérifier modèle et entrée d'alimentation » sans branchement.
Légende finale : Figure 2.5 — Le modem SIM800L, sa variante et ses accessoires de communication.
Texte alternatif : Photo d'une carte SIM800L hors tension, avec antenne et avertissement sur le modèle exact et l'alimentation.
Contraintes : Ne pas généraliser une entrée 5 V d'une carte commerciale au VBAT d'un modem nu ; photo autorisée et matériel réel identifié.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.5]** *photographie annotée du modem.* : Gros plan du SIM800L réellement retenu, antenne et identification des zones d'alimentation sur la carte ; mention « vérifier modèle et entrée d'ali…


**Figure 2.5 — Le modem SIM800L, sa variante et ses accessoires de communication.**

Pour fonctionner réellement, le modem aura besoin de plusieurs conditions réunies : une alimentation adaptée, une carte SIM et un service de données appropriés, une antenne, une couverture radio et un logiciel capable d'établir les échanges.

Le SIM800L **n'est pas un capteur de consommation**. Il ne remplace ni le microcontrôleur, ni la mémoire, ni le serveur.

Notre architecture utilise l'interface série matérielle de l'ATmega328P pour dialoguer avec le modem. Les détails des commandes AT, des échanges série, de la sécurité des données et des erreurs réseau seront expliqués au chapitre 10.

**Avertissement important :** les exigences électriques d'un **SIM800L nu** ne sont pas les mêmes que celles de l'ATmega328P de notre montage. Nous les détaillerons dans la partie B.

### 2.8. Les petits composants qui assurent les fonctions essentielles

Les composants moins spectaculaires sont tout aussi importants que les modules principaux.

| Composant | Fonction habituelle | Point de vigilance |
|---|---|---|
| Résistance | Limiter un courant, établir un niveau électrique, former un réseau | Valeur, tolérance, puissance dissipée |
| Condensateur | Découpler une alimentation, filtrer, fournir une réserve de courte durée | Valeur, tension nominale, polarité éventuelle |
| LED | Fournir un signal lumineux de diagnostic | Limitation de courant adaptée |
| Bouton | Permettre une commande utilisateur | Polarisation de l'entrée et anti-rebond |
| Quartz | Fournir une référence d'horloge | Fréquence, condensateurs et configuration du microcontrôleur |
| Buzzer | Produire un signal sonore d'alerte | Tension, courant et éventuel circuit de commande |
| Connecteur ISP | Permettre la programmation et la maintenance | Repérage des broches et absence de conflit avec les périphériques |
| Boîtier | Protéger le circuit et les personnes | Accès, fixation, isolation et ventilation selon la conception |

**Un buzzer n'est pas indispensable au fonctionnement de base du compteur.** C'est une fonction additionnelle éventuelle. Nous ne devons pas multiplier les composants sans raison : chaque ajout exige un rôle, un dimensionnement et une vérification.

### 2.9. Préparer une liste de matériel sans acheter au hasard

En électronique, une **nomenclature** (ou **BOM**, *Bill of Materials*) est la liste des éléments nécessaires à un projet. Une première liste pédagogique peut inclure :

- une carte Arduino Uno, pour apprendre la programmation ;
- un ATmega328P en boîtier adapté au futur montage autonome ;
- un PZEM-004T V3.0 avec le capteur de courant correspondant à sa variante ;
- un DS3231 et une source de sauvegarde compatible ;
- un LCD 20×4 avec interface I2C ;
- une carte FRAM I2C ;
- un SIM800L avec antenne et carte SIM adaptée ;
- des composants de faible puissance : LED, bouton, résistances, condensateurs et connecteurs ;
- une solution d'alimentation et un boîtier **conçus et validés selon les exigences électriques applicables**.

Cette liste **ne constitue pas encore un plan de montage**. Pour chaque élément, il faut relever la référence précise, les tensions autorisées, les courants nécessaires, le brochage, les protections et le rôle attendu.

Pour le chapitre 3, une **Arduino Uno, un câble USB de données et la LED intégrée à la carte** suffisent pour découvrir un premier programme. Une LED externe et sa résistance pourront être ajoutées dans les exercices basse tension. Il n'est pas nécessaire d'acheter ou de raccorder immédiatement tous les modules du compteur.

---

## Partie B — Comprendre les alimentations, les protections et la sécurité électrique

### 2.10. La tension d'alimentation : une condition de fonctionnement, pas un détail

Un composant électronique a besoin d'une alimentation compatible pour fonctionner correctement. Une tension trop élevée peut l'endommager. Une tension trop faible, instable ou une alimentation incapable de fournir le courant nécessaire peut provoquer des erreurs et des redémarrages.

Deux idées sont à distinguer :

- **La tension**, exprimée en volts (V), doit respecter la plage spécifiée pour l'appareil.
- **La capacité en courant de l'alimentation**, exprimée en ampères (A), doit être suffisante lorsque l'appareil en demande. Une alimentation annoncée « 2 A » ne force pas normalement 2 A dans un appareil ; elle indique une capacité de fourniture dans ses conditions nominales.

Il ne suffit donc pas de repérer « un fil rouge et un fil noir ». Il faut connaître la **tension, la polarité, les courants de fonctionnement et de pointe, la qualité de régulation et les contraintes de la carte réelle**.

### 2.11. Courant alternatif et courant continu : AC et DC

Dans une installation électrique domestique monophasée, on rencontre généralement une alimentation en **courant alternatif**, notée **AC** (*Alternating Current*). Sa tension change au cours du temps suivant la forme d'onde du réseau.

La plupart des circuits numériques de notre compteur sont alimentés en **courant continu**, noté **DC** (*Direct Current*). Une alimentation continue correctement régulée maintient sa tension dans les limites nécessaires au fonctionnement des composants.

Nous pouvons représenter les domaines fonctionnels **sans montrer de câblage dangereux** :

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.6
Type : synoptique de sécurité à vectoriser.
Contenu et annotations : Réinterpréter le dessin ci-après : frontière entre zone secteur dangereuse et électronique basse tension ; alimentation AC/DC isolée et deux domaines régulés logique/modem, sans détails exploitables de branchement.
Légende finale : Figure 2.6 — Séparation fonctionnelle de la zone secteur et des alimentations basse tension.
Texte alternatif : Diagramme présentant l'arrivée secteur, une barrière isolée et les branches basse tension vers microcontrôleur et modem.
Contraintes : Schéma conceptuel uniquement, non destiné au câblage ; protection, normes et distances non dimensionnées ; examen technique obligatoire.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.6]** *synoptique de sécurité à vectoriser.* : Réinterpréter le dessin ci-après : frontière entre zone secteur dangereuse et électronique basse tension ; alimentation AC/DC isolée et deux domain…

~~~text
    ZONE SECTEUR DANGEREUSE                 ZONE ÉLECTRONIQUE
    (intervention qualifiée)                  (basse tension)

     Réseau alternatif
            |
            v
   [Alimentation AC/DC]
   [isolée et qualifiée]
            |
      séparation de sécurité
            |
            +----> Domaine logique régulé : ATmega328P
            |                                 et périphériques
            |
            +----> Domaine modem régulé : SIM800L
                                         (selon variante)
~~~

**Figure 2.6 — Répartition fonctionnelle des alimentations.** Ce dessin n'est **pas** un schéma de branchement du secteur. Les éléments de protection, les barrières d'isolement, les conducteurs, le dimensionnement, la mise à la terre éventuelle et la réalisation physique doivent être déterminés par une personne compétente selon les normes applicables.

Une alimentation dite « isolée » comporte une barrière conçue pour séparer électriquement deux domaines. Toutefois, le niveau de sécurité réel dépend de la conception complète : une simple mention « isolé » sur un produit ne remplace pas les vérifications nécessaires.

### 2.12. Pourquoi notre logique fonctionne en 5 V

Dans ce livre, nous utilisons un ATmega328P configuré pour fonctionner sous **5 V avec une horloge de 16 MHz**. Cette configuration est familière aux utilisateurs de la carte Arduino Uno.

Le microcontrôleur et certains périphériques peuvent partager un **domaine logique de 5 V**, **seulement si** toutes leurs caractéristiques électriques sont compatibles.

Attention : une carte électronique peut présenter un connecteur marqué « VCC » sans pour autant accepter 5 V. De même, un circuit intégré alimenté en 3,3 V n'accepte pas automatiquement des signaux logiques à 5 V sur ses entrées.

Pour notre bus I2C, les modules prévus (DS3231, LCD et FRAM) devront respecter des tensions d'alimentation et des niveaux de signaux compatibles, ainsi qu'un adressage sans conflit. Ces questions seront traitées pendant la conception et les essais à basse tension, pas devinées à partir des couleurs des fils.

### 2.13. Le SIM800L nu : environ 4 V et des pointes de courant importantes

Voici une différence fondamentale entre les deux domaines d'alimentation de notre projet.

Pour un **SIM800L nu**, la documentation de la famille de modules décrit typiquement une alimentation **VBAT comprise autour de 3,4 à 4,4 V**, avec un fonctionnement visé **près de 4,0 V**. Lorsque le modem émet, il peut solliciter des **pointes de courant proches de 2 A**.

Ces nombres ne doivent pas être utilisés aveuglément pour toutes les cartes commercialisées sous le nom « SIM800L ». Certaines cartes de développement intègrent un régulateur et possèdent une entrée d'alimentation différente. **C'est la référence exacte de la carte qui fait foi.**

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.7
Type : infographie comparative des alimentations.
Contenu et annotations : Deux colonnes : domaine ATmega 5 V à 16 MHz et domaine VBAT SIM800L nu autour de 4,0 V (plage typique 3,4–4,4 V) avec pointes proches de 2 A ; ajouter une annotation sur adaptation UART bidirectionnelle.
Légende finale : Figure 2.7 — Pourquoi le microcontrôleur et le modem nu n'utilisent pas la même alimentation.
Texte alternatif : Comparaison logique ATmega à 5 V et modem SIM800L nu à environ 4 V nécessitant une alimentation dimensionnée pour les pointes et une adaptation des signaux.
Contraintes : Pas un schéma de câblage ; préciser « modem nu » et « selon fiche technique du modèle » ; ne pas montrer 5 V directement sur VBAT.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.7]** *infographie comparative des alimentations.* : Deux colonnes : domaine ATmega 5 V à 16 MHz et domaine VBAT SIM800L nu autour de 4,0 V (plage typique 3,4–4,4 V) avec pointes proches de 2 A ; ajou…


**Figure 2.7 — Pourquoi le microcontrôleur et le modem nu n'utilisent pas la même alimentation.**

Conséquences pour la conception :

1. **Ne jamais appliquer directement 5 V au VBAT d'un SIM800L nu.**
2. Prévoir une alimentation régulée dimensionnée pour les besoins réels du modem, y compris les pointes.
3. Prévoir un découplage et un câblage d'alimentation adaptés ; un simple petit condensateur ne compense pas une alimentation insuffisante.
4. Vérifier la tension pendant les phases d'émission dans un environnement basse tension sûr et sous supervision appropriée.
5. Contrôler également les **niveaux logiques** des signaux série entre le modem et le microcontrôleur.

Il faut bien comprendre le dernier point : **une alimentation correcte ne garantit pas que deux signaux de communication soient compatibles**. L'ATmega328P de notre projet utilise une logique 5 V, tandis que le modem nu emploie des niveaux plus faibles. Une adaptation logique validée peut être nécessaire **dans les deux sens**.

**Exemple de diagnostic :** si un modem redémarre au moment où il tente de transmettre, une hypothèse à examiner est la chute de tension provoquée par une alimentation insuffisante. Cela ne justifie **jamais** de monter arbitrairement VBAT à 5 V. La recherche de panne commence par la documentation, le contrôle de l'alimentation et un protocole de test basse tension adapté.

### 2.14. Le découplage : limiter les perturbations de l'alimentation

Un circuit numérique peut demander de petites variations de courant très rapides. Les connexions et les alimentations réelles ne sont pas idéales : de telles variations peuvent provoquer des perturbations.

Un **condensateur de découplage**, correctement choisi et placé près d'un circuit intégré, aide à stabiliser localement son alimentation pendant certaines variations transitoires.

Un **condensateur de réserve** peut également contribuer à absorber un appel de courant bref, par exemple près d'un modem, lorsqu'il est convenablement dimensionné. Le choix des valeurs, des tensions nominales et de l'implantation dépend de la conception.

Trois idées sont essentielles :

- le découplage améliore le comportement électrique local ;
- il ne remplace pas une alimentation correctement dimensionnée ;
- sa présence n'assure ni l'isolation électrique ni la protection contre un contact avec le secteur.

**Attention aux condensateurs polarisés** : leur sens de raccordement et leurs caractéristiques doivent être respectés. Nous n'effectuerons dans ce chapitre aucun montage alimenté par le secteur.

### 2.15. L'isolation et les protections : empêcher le contact avec une zone dangereuse

Le réseau électrique domestique peut causer une électrisation grave, une électrocution ou un incendie. L'objectif des protections est notamment d'empêcher qu'un défaut simple expose l'utilisateur ou l'électronique accessible à des tensions dangereuses.

Une conception professionnelle peut demander :

| Mesure | Pourquoi elle compte |
|---|---|
| Alimentation AC/DC correctement isolée | Séparer le domaine secteur des circuits accessibles |
| Protection contre les surintensités | Réduire certains risques liés aux défauts et aux surcharges |
| Distances d'isolement adaptées | Éviter des contacts ou amorçages entre parties dangereuses et accessibles |
| Boîtier approprié | Empêcher les contacts accidentels et protéger les composants |
| Connecteurs adaptés | Éviter les raccordements improvisés et les contacts exposés |
| Essais et contrôles qualifiés | Vérifier les caractéristiques de sécurité du montage réel |

Les protections ne se choisissent pas avec une règle universelle recopiée sur Internet. Leur dimensionnement, leur coordination et les distances nécessaires dépendent du schéma, des matériaux, des tensions et des exigences réglementaires du lieu d'installation.

Une **breadboard** (plaque d'essai sans soudure) est un outil commode pour des montages d'apprentissage **basse tension**. Elle **n'est pas destinée à recevoir directement le réseau secteur 230 V**.

Un module acheté prêt à l'emploi n'exonère pas de vérifier la conception de l'ensemble. Le fait qu'un produit soit alimenté par un câble USB ou qu'une petite carte paraisse inoffensive ne garantit pas que toutes les parties de l'installation soient sûres.

### 2.16. Les masses et les signaux : ne pas tout relier sans analyse

Dans un circuit numérique, on utilise souvent le terme **masse**, noté **GND**, pour représenter une référence électrique commune. Certaines communications nécessitent une référence adaptée entre appareils.

Mais dans un système qui contient également des circuits liés au secteur, relier des masses au hasard peut **supprimer une séparation de sécurité**, créer des courants non désirés ou mettre une partie accessible à un potentiel dangereux.

**Règle à retenir :** une masse commune entre périphériques basse tension se décide **uniquement après vérification de l'architecture, de leurs références et des barrières d'isolement**. Elle ne doit jamais être déduite du seul fait que deux modules portent une borne « GND ».

Le bus I2C, la liaison série du PZEM et celle du SIM800L seront étudiés plus tard avec leurs contraintes propres. Nous ne proposons pas de câblage opérationnel dans ce chapitre.

### 2.17. Ce qu'un débutant peut faire — et ce qu'il doit confier à une personne qualifiée

Le meilleur premier exercice n'est pas le plus impressionnant, mais celui qui permet d'apprendre **sans se mettre en danger**.

| Activités d'apprentissage adaptées au débutant | Opérations réservées à un cadre qualifié |
|---|---|
| Identifier les références de composants hors tension | Intervenir sur une installation secteur |
| Lire une documentation de module | Raccorder la partie mesure au 230 V |
| Dessiner un synoptique fonctionnel | Dimensionner et valider les protections secteur |
| Faire fonctionner une Arduino Uno par alimentation USB adaptée | Ouvrir ou modifier une alimentation secteur |
| Programmer une LED, lire un bouton, simuler des données | Vérifier l'isolation électrique d'un montage secteur |
| Étudier les unités et les conversions | Effectuer les essais de mise en service sur installation réelle |

<!-- ILLUSTRATION À PRODUIRE — FIGURE 2.8
Type : infographie de sécurité pédagogique.
Contenu et annotations : Panneau comparatif visuel : identification hors tension, Arduino USB, simulation (adaptés au débutant) opposés aux interventions secteur, essais d'isolement et protections (réservés à un professionnel qualifié).
Légende finale : Figure 2.8 — Les pratiques d'apprentissage sûres et les interventions réservées aux professionnels.
Texte alternatif : Deux colonnes illustrent les activités basse tension autorisées et les opérations dangereuses nécessitant une qualification, sans geste de raccordement montré.
Contraintes : Prévention uniquement ; ne pas fournir d'étapes pour intervenir sur le 230 V ; pictogrammes avec texte et contrastes accessibles.
Statut : À PRODUIRE. Aucun visuel final n'est encore ajouté.
-->

> **[ILLUSTRATION À INSÉRER — Figure 2.8]** *infographie de sécurité pédagogique.* : Panneau comparatif visuel : identification hors tension, Arduino USB, simulation (adaptés au débutant) opposés aux interventions secteur, essais d'…


**Figure 2.8 — Les pratiques d'apprentissage sûres et les interventions réservées aux professionnels.**

**En cas d'incertitude, ne pas brancher.** Une mesure réelle sur le secteur n'est pas nécessaire pour réussir les exercices de cette partie du livre.

### 2.18. Trois erreurs que nous devons reconnaître immédiatement

**Erreur A — « Puisque l'Arduino utilise 5 V, je peux envoyer 5 V au SIM800L nu. »**  
C'est une généralisation fausse. Le VBAT d'un SIM800L nu doit respecter sa plage propre, autour de 4 V. Il faut examiner la documentation du modèle réel et utiliser une alimentation adaptée. **Ne faites pas cet essai pour voir ce qui se passe.**

**Erreur B — « Je vais placer le secteur sur ma breadboard pour expérimenter plus vite. »**  
C'est une pratique dangereuse. La breadboard pédagogique ne fournit pas les protections et espacements exigés pour une manipulation du secteur. Les essais secteur relèvent d'une conception et d'un banc professionnels.

**Erreur C — « Les deux modules ont des broches TX et RX : je peux les relier directement. »**  
Pas nécessairement. Les tensions d'alimentation et les **niveaux électriques des entrées/sorties** peuvent différer. Il faut vérifier les seuils autorisés et prévoir une adaptation appropriée ; la présence des mêmes noms de broches ne prouve pas leur compatibilité.

Pour chacune de ces erreurs, la bonne première réponse est : **arrêter l'opération, vérifier les références et choisir une méthode sûre**.

---

## Partie C — Exercices sans secteur

### 2.19. Activité 1 — Associer un composant à son rôle

**Durée indicative :** 15 minutes.  
**Matériel :** feuille, crayon et éventuellement photographies de composants **hors tension**.

Recopiez ce tableau et indiquez la fonction principale de chaque élément :

| Élément | Sa fonction, avec vos mots | Une vérification avant utilisation |
|---|---|---|
| ATmega328P | … | … |
| PZEM-004T V3.0 | … | … |
| DS3231 | … | … |
| LCD I2C 20×4 | … | … |
| FRAM | … | … |
| SIM800L | … | … |
| LED | … | … |
| Bouton | … | … |
| Buzzer | … | … |

Complétez ensuite les deux phrases suivantes :

1. « L'horloge DS3231 indique __________, alors que la FRAM conserve __________. »
2. « Le SIM800L sert à __________ et non à mesurer directement __________. »

**Critère de réussite :** être capable de donner une explication simple des neuf éléments sans confondre leurs fonctions.

### 2.20. Activité 2 — Diagnostiquer des situations à risque

**Durée indicative :** 15 minutes.  
**Matériel :** papier uniquement. **Ne reproduisez aucune des situations suivantes.**

Un apprenant propose trois actions :

- **Situation A :** appliquer directement 5 V à l'entrée VBAT d'un SIM800L nu.
- **Situation B :** raccorder le réseau domestique 230 V à une breadboard.
- **Situation C :** connecter directement une sortie UART 5 V à un modem dont la compatibilité des niveaux logiques est inconnue.

Pour chaque situation, expliquez :

1. pourquoi l'action proposée présente un risque ;
2. quelle information il faudrait vérifier ;
3. quelle décision sûre prendre **sans effectuer le branchement dangereux**.

Enfin, choisissez l'activité la plus adaptée pour débuter :

- mesurer une phase du secteur ;
- démonter une alimentation secteur ;
- **faire clignoter la LED intégrée d'une Arduino Uno alimentée correctement par USB**.

Justifiez votre choix.

### 2.21. Quiz de vérification — Dix questions

**Consigne :** pour chaque question, choisir **une seule réponse**. Pour les questions de sécurité, une erreur doit toujours être comprise et corrigée, même avec un bon score général.

**1. Quel composant exécute le programme de notre compteur ?**  
A. Le DS3231 — B. L'ATmega328P — C. La FRAM — D. Le LCD

**2. Quel élément fournit des grandeurs électriques au microcontrôleur ?**  
A. Le SIM800L — B. Le buzzer — C. Le PZEM-004T — D. Le DS3231

**3. Pourquoi utiliser un DS3231 ?**  
A. Pour fournir la date et l'heure — B. Pour convertir le 230 V en 5 V — C. Pour émettre en GSM — D. Pour mesurer le courant

**4. Quelle tension logique caractérise notre configuration pédagogique d'ATmega328P à 16 MHz ?**  
A. 230 V alternatif — B. 12 V — C. 4 V — D. 5 V

**5. Quelle alimentation correspond à un SIM800L nu ?**  
A. Directement 5 V sur VBAT — B. Environ 4 V, capable de fournir les pointes exigées — C. 230 V alternatif — D. Une sortie GPIO

**6. Quel exercice est adapté à un débutant sans intervention secteur ?**  
A. Mettre le 230 V sur une breadboard — B. Ouvrir un bloc secteur — C. Programmer une LED sur Arduino Uno correctement alimentée par USB — D. Remplacer un fusible sous tension

**7. Le synoptique fonctionnel suffit-il pour réaliser un raccordement au secteur ?**  
A. Non, il ne remplace pas une conception et une validation qualifiées — B. Oui — C. Oui si le schéma est en couleur — D. Oui avec n'importe quel fusible

**8. Pourquoi prévoir une isolation électrique adaptée ?**  
A. Pour rendre le code plus rapide — B. Pour augmenter la mémoire — C. Pour améliorer les graphismes — D. Pour contribuer à séparer les parties dangereuses des parties accessibles

**9. Un modem redémarre à l'émission : que doit-on examiner en premier ?**  
A. La couleur du LCD — B. Une augmentation arbitraire à 5 V — C. L'alimentation, sa stabilité et les pointes de courant — D. Un branchement secteur direct

**10. Deux appareils série n'utilisent pas les mêmes niveaux logiques. Que faire ?**  
A. Vérifier et adapter les niveaux — B. Relier sans vérifier — C. Supprimer les protections — D. Remplacer la RTC

Le corrigé et les explications figurent dans **l'annexe B** du livre. Seuil conseillé : **8/10**, avec correction obligatoire des questions de sécurité.

---

## Partie D — L'essentiel à retenir

### 2.22. Huit idées à ne pas oublier

1. Notre compteur est un **système composé de plusieurs fonctions**, et chaque composant a un rôle précis.
2. L'**ATmega328P** exécute le programme ; le **PZEM** fournit des grandeurs électriques.
3. Le **DS3231** donne l'heure et la date ; la **FRAM** peut conserver des données ; le **LCD** permet leur lecture locale.
4. Le **SIM800L** sert à communiquer sur un réseau mobile compatible, pas à mesurer l'énergie.
5. Un nom de module ne suffit pas à connaître son **brochage**, ses **niveaux logiques** ou son **alimentation**.
6. Notre électronique logique utilise une configuration **5 V**, tandis que le **SIM800L nu** demande typiquement environ **4 V**, avec des pointes de courant importantes.
7. L'**isolation**, le **découplage**, les **protections** et le **boîtier** remplissent des fonctions différentes et complémentaires.
8. Le **secteur 230 V n'est pas un terrain d'expérimentation pour un débutant** : nous commencerons par une carte Arduino alimentée de manière sûre.

### 2.23. Vocabulaire de fin de chapitre

| Mot | Sens dans ce livre |
|---|---|
| **AC** | Courant alternatif |
| **DC** | Courant continu |
| **BOM** | Nomenclature ou liste de composants |
| **RTC** | Horloge temps réel |
| **I2C** | Bus de communication numérique entre circuits compatibles |
| **UART** | Interface de communication série |
| **VBAT** | Nom d'une entrée d'alimentation, notamment sur un modem |
| **Découplage** | Technique de stabilisation locale de l'alimentation |
| **Isolation** | Séparation électrique entre certains domaines |
| **ISP** | Programmation d'un microcontrôleur directement dans son circuit |
| **GND** | Référence électrique commune d'un circuit, à définir en respectant l'isolation |

### 2.24. Transition vers le chapitre 3

Nous savons maintenant à quoi servent les composants et pourquoi l'alimentation correcte est un préalable à tout programme. Nous n'avons pas encore besoin de raccorder le PZEM au secteur ou d'alimenter le modem GSM.

Au **chapitre 3**, nous installerons Arduino IDE, découvrirons le fonctionnement d'un programme Arduino et ferons clignoter une LED. Ce premier essai sera réalisé **sur Arduino Uno, avec une alimentation basse tension adaptée**. Il nous donnera un résultat visible sans exposer l'apprenant aux dangers du réseau électrique.
