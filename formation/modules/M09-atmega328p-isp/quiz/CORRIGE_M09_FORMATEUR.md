# M09 — Corrigé du quiz et explications

**Réponses :** Q01=B · Q02=A · Q03=C · Q04=D · Q05=B · Q06=A · Q07=C · Q08=D · Q09=B · Q10=C.

## Q01 — Quelle différence essentielle sépare une Uno Rev3 d'un ATmega328P en boîtier DIP28 seul ?

**Bonne réponse : B**

- **A. L'ATmega328P seul dispose de l'USB natif, l'Uno non** — L'ATmega328P PDIP28 n'a pas de contrôleur USB natif.
- **B. La Uno contient des éléments utiles (USB, horloge, régulation) qui doivent être prévus autour de la puce nue** — Une carte Uno intègre un environnement pratique autour du microcontrôleur.
- **C. La Uno ne peut pas programmer de microcontrôleur** — Une Uno peut servir de programmateur ISP en utilisant ArduinoISP.
- **D. La puce nue mesure la tension secteur directement** — Aucun ATmega328P nu ne mesure directement une tension secteur en toute sécurité.

## Q02 — Sur un ATmega328P PDIP28, quelles pattes sont VCC et AVCC ?

**Bonne réponse : A**

- **A. 7 et 20** — VCC = 7 et AVCC = 20 pour le boîtier PDIP28.
- **B. 1 et 2** — 1 = RESET et 2 = PD0/RXD.
- **C. 9 et 10** — 9 et 10 sont les broches XTAL du quartz.
- **D. 17 et 18** — 17 et 18 sont MOSI et MISO.

## Q03 — La LED sur D13 de l'Uno correspond à quelle patte de l'ATmega328P PDIP28 ?

**Bonne réponse : C**

- **A. Broche physique 13** — Le numéro Arduino D13 n'est pas le numéro de patte DIP.
- **B. Broche physique 4** — Broche 4 correspond à D2/PD2.
- **C. Broche physique 19, PB5** — D13 = PB5 = broche physique 19 en PDIP28, avec LED externe et résistance.
- **D. Broche physique 28** — Broche 28 correspond à PC5/SCL.

## Q04 — Quelle action envoie le programme dans la puce cible avec une Uno qui exécute ArduinoISP ?

**Bonne réponse : D**

- **A. L'icône Upload standard, nécessairement** — Le téléversement normal utilise habituellement la voie USB/bootloader, pas la cible ISP.
- **B. Tools → Serial Monitor** — Le moniteur ne programme pas une puce.
- **C. File → New sketch** — Un nouveau fichier ne transfère rien dans une puce.
- **D. Sketch → Upload Using Programmer** — Upload Using Programmer emploie le programmateur choisi et la liaison ISP.

## Q05 — Pour exécuter le firmware compilé pour Uno 16 MHz sur une puce dont les fuses attendent un quartz externe, quelle condition matérielle faut-il respecter ?

**Bonne réponse : B**

- **A. Ne rien brancher sur les broches XTAL** — Une configuration fuses demandant une horloge externe nécessite l'horloge adaptée.
- **B. Prévoir une horloge externe 16 MHz fonctionnelle et compatible avec les fuses** — Le quartz/oscillateur doit correspondre au profil et aux fuses configurés.
- **C. Installer une pile 9 V directement sur XTAL1** — Une pile 9 V sur l'entrée d'horloge est incorrecte et dangereuse pour la puce.
- **D. Activer uniquement Serial.begin(9600)** — Le débit UART ne génère pas l'horloge physique du microcontrôleur.

## Q06 — Quel câblage Uno programmateur → ATmega328P PDIP28 cible est correct ?

**Bonne réponse : A**

- **A. D10→RESET1, D11→MOSI17, D12→MISO18, D13→SCK19** — Ces correspondances ISP sont correctes pour la Uno et la cible PDIP28.
- **B. D10→MISO18, D11→SCK19, D12→RESET1, D13→MOSI17** — Les rôles sont inversés, la communication ISP échouera.
- **C. D0→RESET1, D1→MOSI17, D2→MISO18, D3→SCK19** — D0/D1 sont les broches UART de la Uno, pas les signaux ISP du tableau.
- **D. D10→VCC7, D11→GND8, D12→AVCC20, D13→XTAL9** — Cette proposition relie des signaux à des alimentations/horloge de façon incorrecte.

## Q07 — Après programmation ISP, pourquoi le moniteur série de la Uno programmateur n'affiche-t-il pas automatiquement le Serial.println de la puce nue ?

**Bonne réponse : C**

- **A. La puce nue n'a plus de RAM** — La programmation ISP ne supprime pas la RAM.
- **B. Serial.println exige un LCD I2C** — Serial.println passe par UART, pas par un écran LCD.
- **C. La puce cible n'a pas d'USB natif ; il faut relier son UART PD0/PD1 à un adaptateur USB–TTL compatible** — L'adaptateur assure la liaison UART de la cible vers l'ordinateur, avec niveaux compatibles et masse commune.
- **D. La broche RESET de la cible devient TX** — RESET ne transporte pas les messages série du firmware.

## Q08 — Pourquoi l'action Burn Bootloader doit-elle être soigneusement préparée sur un ATmega328P autonome ?

**Bonne réponse : D**

- **A. Elle écrit toujours le programme Python Flask** — La programmation d'un bootloader ne déploie pas un serveur Python.
- **B. Elle efface la mémoire RAM de la Uno uniquement** — La conséquence importante concerne la configuration Flash/fuses de la cible.
- **C. Elle ajoute directement un écran LCD au microcontrôleur** — L'opération ne crée aucun périphérique matériel.
- **D. Elle peut écrire les fuses d'horloge ; un mauvais choix peut rendre la cible temporairement inaccessible** — La configuration d'horloge doit correspondre au quartz/oscillateur réellement installé.

## Q09 — Le transfert ISP indique succès, mais la LED du montage cible reste éteinte. Quel diagnostic est le plus pertinent ?

**Bonne réponse : B**

- **A. Conclusion immédiate : le calcul énergétique M08 est faux** — Le clignotement LED concerne d'abord la sortie physique et l'horloge, pas la consommation jour/mois.
- **B. Vérifier la LED externe et sa résistance sur PB5/19, puis l'alimentation et l'horloge de la cible avant de conclure** — Une puce nue n'a pas la LED L de la carte Uno ; vérifier câblage, alimentation et horloge.
- **C. Brancher le 230 V pour alimenter le microcontrôleur** — Aucun essai de M09 n'exige du secteur et cela introduirait un risque grave.
- **D. Remettre l'index PZEM à zéro** — L'index PZEM n'a aucun rôle dans un diagnostic de clignotement.

## Q10 — Quelle preuve répond le mieux à la règle pédagogique de notre formation en M09 ?

**Bonne réponse : C**

- **A. Créer un firmware neuf qui clignote mais abandonne les six mesures et les kWh jour/mois** — Le mini Blink est un diagnostic, pas une nouvelle base de compteur.
- **B. Publier uniquement un schéma ISP sans source intégrée** — Le schéma matériel seul ne démontre pas la continuité logicielle.
- **C. Conserver le firmware M08, publier le snapshot M09/courant synchronisés et tester les anciennes fonctions plus la nouvelle cible** — Le même compteur évolue et la non-régression est vérifiée avec les tests appropriés.
- **D. Installer un bootloader et prétendre que les mesures ont été testées** — Un bootloader et un transfert ne prouvent pas le fonctionnement physique des mesures.

## Validation

- Une bonne réponse = 1 point ; **validation à partir de 8/10**.
- Une erreur de sécurité (secteur, alimentation contradictoire, mauvais niveaux électriques) exige une **correction explicite** même en cas de bon score.
- Si erreur Q03/Q06 : revoir la correspondance Arduino ↔ PDIP28.
- Si erreur Q05/Q08 : reprendre différence horloge réelle / profil IDE / fuses.
- Si erreur Q09/Q10 : répéter le diagnostic de transfert puis les tests du **firmware fil rouge**, qui reste identique sur ses fonctions précédentes.

Le JSON constitue un fichier d'import ultérieur, pas une preuve d'intégration à la plateforme.
