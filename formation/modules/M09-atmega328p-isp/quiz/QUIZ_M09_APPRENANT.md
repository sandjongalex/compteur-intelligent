# M09 — Quiz apprenant : ATmega328P autonome et ArduinoISP

**10 questions · quatre faciles, quatre intermédiaires, deux difficiles · une seule bonne réponse · seuil : 8/10.**

Les questions sont spécifiques à l'**ATmega328P PDIP28** et au firmware de compteur fil rouge M08→M09. Aucun exercice ne demande de manipuler le secteur.

## Q01 — Quelle différence essentielle sépare une Uno Rev3 d'un ATmega328P en boîtier DIP28 seul ?

*Facile · Microcontrôleur*

A. L'ATmega328P seul dispose de l'USB natif, l'Uno non
B. La Uno contient des éléments utiles (USB, horloge, régulation) qui doivent être prévus autour de la puce nue
C. La Uno ne peut pas programmer de microcontrôleur
D. La puce nue mesure la tension secteur directement

## Q02 — Sur un ATmega328P PDIP28, quelles pattes sont VCC et AVCC ?

*Facile · Alimentation*

A. 7 et 20
B. 1 et 2
C. 9 et 10
D. 17 et 18

## Q03 — La LED sur D13 de l'Uno correspond à quelle patte de l'ATmega328P PDIP28 ?

*Facile · Brochage*

A. Broche physique 13
B. Broche physique 4
C. Broche physique 19, PB5
D. Broche physique 28

## Q04 — Quelle action envoie le programme dans la puce cible avec une Uno qui exécute ArduinoISP ?

*Facile · ISP*

A. L'icône Upload standard, nécessairement
B. Tools → Serial Monitor
C. File → New sketch
D. Sketch → Upload Using Programmer

## Q05 — Pour exécuter le firmware compilé pour Uno 16 MHz sur une puce dont les fuses attendent un quartz externe, quelle condition matérielle faut-il respecter ?

*Intermédiaire · Horloge*

A. Ne rien brancher sur les broches XTAL
B. Prévoir une horloge externe 16 MHz fonctionnelle et compatible avec les fuses
C. Installer une pile 9 V directement sur XTAL1
D. Activer uniquement Serial.begin(9600)

## Q06 — Quel câblage Uno programmateur → ATmega328P PDIP28 cible est correct ?

*Intermédiaire · ISP*

A. D10→RESET1, D11→MOSI17, D12→MISO18, D13→SCK19
B. D10→MISO18, D11→SCK19, D12→RESET1, D13→MOSI17
C. D0→RESET1, D1→MOSI17, D2→MISO18, D3→SCK19
D. D10→VCC7, D11→GND8, D12→AVCC20, D13→XTAL9

## Q07 — Après programmation ISP, pourquoi le moniteur série de la Uno programmateur n'affiche-t-il pas automatiquement le Serial.println de la puce nue ?

*Intermédiaire · Série*

A. La puce nue n'a plus de RAM
B. Serial.println exige un LCD I2C
C. La puce cible n'a pas d'USB natif ; il faut relier son UART PD0/PD1 à un adaptateur USB–TTL compatible
D. La broche RESET de la cible devient TX

## Q08 — Pourquoi l'action Burn Bootloader doit-elle être soigneusement préparée sur un ATmega328P autonome ?

*Intermédiaire · Fuses*

A. Elle écrit toujours le programme Python Flask
B. Elle efface la mémoire RAM de la Uno uniquement
C. Elle ajoute directement un écran LCD au microcontrôleur
D. Elle peut écrire les fuses d'horloge ; un mauvais choix peut rendre la cible temporairement inaccessible

## Q09 — Le transfert ISP indique succès, mais la LED du montage cible reste éteinte. Quel diagnostic est le plus pertinent ?

*Difficile · Diagnostic*

A. Conclusion immédiate : le calcul énergétique M08 est faux
B. Vérifier la LED externe et sa résistance sur PB5/19, puis l'alimentation et l'horloge de la cible avant de conclure
C. Brancher le 230 V pour alimenter le microcontrôleur
D. Remettre l'index PZEM à zéro

## Q10 — Quelle preuve répond le mieux à la règle pédagogique de notre formation en M09 ?

*Difficile · Continuité*

A. Créer un firmware neuf qui clignote mais abandonne les six mesures et les kWh jour/mois
B. Publier uniquement un schéma ISP sans source intégrée
C. Conserver le firmware M08, publier le snapshot M09/courant synchronisés et tester les anciennes fonctions plus la nouvelle cible
D. Installer un bootloader et prétendre que les mesures ont été testées

**Consigne :** remplir le QCM avant d'ouvrir le corrigé.
