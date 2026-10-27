# M09 — Travaux pratiques (version apprenant)

**Deux TP, durée hors vidéo : 45 à 75 minutes.** Matériel exclusivement **basse tension 5 V**, jamais secteur. Ne pas modifier le câblage USB branché. Énoncés à distribuer sans corrigés.

## TP01 — Identifier et préparer le circuit minimal ATmega328P PDIP28

**Objectif :** produire un schéma annoté et une checklist électrique que le formateur peut valider **avant** toute alimentation.

Matériel : documentation du boîtier ATmega328P **PDIP28**, breadboard (optionnelle), alimentation 5 V régulée, résistances et condensateurs conformes au banc, quartz 16 MHz et réseau de charge adapté, LED avec résistance série. Ne pas manipuler des fils sous tension.

1. Dessiner l'encoche, la broche 1 et le sens de numérotation du boîtier **28 pattes**.
2. Placer et étiqueter **RESET, VCC, AVCC, GND ×2, XTAL1, XTAL2** sur le schéma.
3. Reproduire les connexions d'alimentation et les **100 nF de découplage au voisinage des alimentations**.
4. Prévoir RESET vers +5 V avec résistance **10 kΩ**, tout en laissant le signal RESET accessible à l'ISP.
5. Dessiner le quartz **16 MHz** entre XTAL1/XTAL2 avec les condensateurs adaptés à sa référence.
6. Repérer la LED **D13/PB5** et le bouton **D2/PD2**. Ajouter la résistance LED et le bouton vers GND.
7. Placer un connecteur ISP : SCK, MOSI, MISO, RESET, GND, VCC.
8. Avant toute alimentation, demander au formateur de vérifier l'orientation, les polarités, le brochage, les tensions, la masse et l'absence de court-circuit.
9. Facultatif : expliquer pourquoi le fait de choisir « Arduino Uno » dans l'IDE **n'installe pas physiquement** le quartz.

**Livrables :** schéma de câblage lisible + tableau « fonction / broche DIP / numéro Arduino » + checklist de vérification signée.

**Critère de réussite :** zéro confusion sur VCC/AVCC/GND/RESET et aucune manipulation à risque.

## TP02 — Programmer la cible, puis conserver le firmware M08

**Objectif :** utiliser l'Uno comme programmateur ISP puis constater que les fonctions du **même firmware** continuent sur la puce autonome.

*Le TP matériel se fait uniquement avec un formateur ou une personne compétente en électronique.* Si le matériel n'est pas disponible, réaliser une étude de câblage/diagnostic et le **contrôle de compilation seulement**, puis indiquer que la validation physique est non effectuée.

1. Compiler le [diagnostic LED](../code/V01_01_diagnostic_led/V01_01_diagnostic_led.ino) pour Uno/16 MHz.
2. Télécharger **ArduinoISP dans la Uno programmateur** (téléversement normal, port USB Uno).
3. Hors alimentation, câbler la Uno à l'ATmega328P externe par les **six signaux ISP** indiqués dans [le guide](../ressources/BROCHAGE_ISP_PU28.md). Préparer l'horloge cible et les fuses selon la documentation.
4. Sélectionner **Arduino Uno** comme profil de la *cible* et **Arduino as ISP** comme programmateur, puis choisir **Upload Using Programmer** pour le diagnostic LED.
5. Vérifier si la **LED externe reliée à PB5/19** clignote sur le microcontrôleur cible lorsqu'il est alimenté seul.
6. Ouvrir le [firmware fil rouge M09](../../../../firmware/etapes/M09/Compteur_M09/Compteur_M09.ino) et relever ce qui **reste** du M08 : gestion bouton, UART, lecture simulée, date, énergie journalière/mensuelle.
7. Sur banc réellement préparé, modifier uniquement `ALEXTECH_ATMEGA_AUTONOME` à `1`, laisser les options de matériel de mesure à `0`, compiler puis charger par ISP. Si seul le code de référence doit rester identique dans GitHub, utiliser une copie locale de travail pour la bascule.
8. En option, raccorder un **USB–TTL compatible** sur PD0/PD1 de la cible et tester `1/0/?`. Expliquer pourquoi la connexion USB de la Uno programmateur ne fait pas ce travail automatiquement.
9. Comparer le comportement et les sources M08 / M09. Ne pas prétendre que le PZEM réel, le GSM ou la FRAM ont été testés.
10. En cas de défaut, noter message exact, étape d'échec et hypothèse avant modification du câblage **hors tension**.

**Livrables :** tableau ISP câblé, capture de compilation, sortie du téléversement ISP si réellement effectué, photo de la LED externe en fonctionnement si observée, comparaison des fonctions M08/M09, diagnostic argumenté d'un échec.

## Mini-défi

Pourquoi un sketch peut-il **compiler correctement** alors que la puce externe ne répond à aucune opération ISP ? Répondre en donnant trois causes matérielles/paramètres possibles.

**Validation :** le seul succès de compilation ne vaut pas preuve de fonctionnement physique. [Corrigés réservés au formateur](CORRIGE_M09_FORMATEUR.md).
