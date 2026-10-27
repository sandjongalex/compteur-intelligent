# M09-V02 — Script du formateur : programmer le même firmware par ArduinoISP (8 min)

**Principe : Uno = programmateur ; ATmega328P DIP28 = cible ; le programme M09 conserve tous les acquis M08.**  
Le montage est limité aux circuits basse tension. Les explications entre guillemets sont à prononcer ; [ÉCRAN]/[MANIP] orientent le tournage.

## 00:00–00:50 — Le résultat que nous cherchons

[MANIP] Deux ensembles clairement séparés sur la table : Uno USB et ATmega328P externe avec son circuit minimal.

« Nous avons construit le circuit minimal de notre ATmega328P. Aujourd'hui, nous allons lui envoyer un programme en utilisant la carte Uno comme **programmateur**.

Une distinction est essentielle : le programme de diagnostic ArduinoISP s'exécute sur **la Uno**, mais le programme que nous voulons installer doit finir dans la mémoire Flash de **la puce externe**.

Puis nous remplacerons le petit diagnostic par le **même firmware de compteur** que nous avons développé jusqu'au Module 08, enrichi des réglages expliqués au Module 09. »

## 00:50–01:55 — Charger ArduinoISP dans la Uno programmateur

[ÉCRAN] Arduino IDE 2, sélectionner Arduino Uno et le port USB de cette carte.

« Je commence sans brancher les lignes de programmation de la cible. J'ouvre les exemples de l'IDE Arduino et je recherche le sketch **ArduinoISP**.

Je vérifie la carte Uno et son port, puis j'utilise le téléversement normal pour installer ArduinoISP **dans la Uno programmateur**.

Ce programme transforme la Uno en interface de programmation série ISP. Il pourra ensuite transmettre le contenu d'un sketch à une autre puce, par des broches de programmation dédiées.

Après l'opération, je coupe l'USB avant de brancher les fils. Sur certaines Uno, un condensateur entre RESET et GND côté programmateur peut éviter le redémarrage intempestif lors de l'ouverture du port ; cette précaution dépend du modèle et n'est pas à ajouter au hasard. »

## 01:55–03:15 — Câbler les six signaux ISP

[ÉCRAN] Montrer tableau des connexions, puis filmer un raccordement soigneusement contrôlé hors tension.

« La programmation ISP utilise notamment trois signaux de données : **MOSI** pour envoyer les données vers la cible, **MISO** pour recevoir sa réponse, et **SCK** pour rythmer les échanges.

Sur notre Uno programmateur, les connexions classiques sont D11 vers MOSI de la cible, D12 vers MISO, et D13 vers SCK.

Il faut également que la Uno commande la **broche RESET de la puce cible** : ici D10 du programmateur va vers la broche physique 1 du microcontrôleur externe. Enfin, la masse est commune et l'alimentation 5 volts de la cible est conforme au montage vérifié.

Retenez une phrase simple : **D10, D11, D12, D13 de la Uno parlent au microcontrôleur externe par ISP**. Sur le boîtier DIP28, les broches correspondantes sont 1, 17, 18 et 19.

[MANIP] Vérifier la connexion sans USB, puis alimenter par la source choisie. Ne pas ajouter deux sources de 5 volts en parallèle. »

## 03:15–04:30 — Horloge, fuses, bootloader et mode de téléversement

[ÉCRAN] Menu Tools → Board : Arduino Uno, Tools → Programmer : Arduino as ISP, Sketch → Upload Using Programmer.

« Maintenant, il y a trois paramètres qu'il ne faut pas confondre.

D'abord, le **profil de compilation**. Nous utilisons Arduino Uno à seize mégahertz pour notre ATmega328P, parce que notre carte externe a été préparée pour cette horloge.

Ensuite, le **programmateur**. Dans Tools, je choisis Arduino as ISP, c'est-à-dire notre Uno déjà chargée avec le programme ArduinoISP.

Enfin, la **méthode d'envoi**. Quand le microcontrôleur externe est prêt, nous utilisons **Upload Using Programmer**. Ce n'est pas le même bouton que le téléversement USB normal.

Parlons des fuses. Ces bits particuliers définissent notamment la source d'horloge. Sur une puce qui ne dispose pas encore de la bonne configuration, l'action Burn Bootloader de l'IDE peut servir à écrire une configuration de fuses cohérente avec le profil choisi. Mais elle doit être employée avec précaution et avec le **quartz externe déjà présent** si cette configuration l'exige.

Le chargement par ISP **n'exige pas** de conserver un bootloader dans la puce cible. »

## 04:30–05:30 — Vérifier d'abord un petit programme diagnostic

[ÉCRAN] Ouvrir `V01_01_diagnostic_led.ino` : LED D13/PB5 basculant grâce à `millis()`.

« Avant d'envoyer notre compteur complet, je vérifie le montage avec un programme très simple : une LED externe sur la sortie PB5, qui correspond à D13.

J'examine les connexions, puis j'envoie ce diagnostic avec **Upload Using Programmer**.

Si le transfert réussit et que l'horloge et l'alimentation sont présentes, je dois voir la LED de la **puce cible** clignoter, pas seulement une LED sur la Uno programmateur.

Cet exercice ne remplace pas notre compteur : c'est une vérification du banc, que nous pouvons supprimer ensuite en chargeant le firmware M09. »

## 05:30–06:50 — Charger le vrai firmware fil rouge M09

[ÉCRAN] Ouvrir d'abord `Compteur_M08.ino`, puis `Compteur_M09.ino`, surligner `ALEXTECH_ATMEGA_AUTONOME`.

« Passons maintenant au projet principal. Je reprends le **même compteur** qui calcule déjà les consommations.

Je montre les quelques lignes ajoutées pour déclarer la cible autonome. Je n'efface ni les fonctions des six mesures, ni les commandes série, ni les calculs du jour et du mois.

Quand le montage est vérifié, je mets l'option de puce autonome à un. Je conserve le PZEM réel et les périphériques supplémentaires **désactivés** pour cet essai basse tension : nos valeurs restent fictives, comme pendant les premiers modules.

Ensuite, je compile et j'envoie avec **Upload Using Programmer**.

Pour lire les messages provenant de la **puce cible**, je n'utilise pas automatiquement le moniteur série de l'Uno programmateur. La cible autonome n'a pas d'USB intégré : il me faut, si je veux afficher les messages, un **adaptateur USB–TTL aux niveaux compatibles**, raccordé sur RX et TX de la cible avec masse commune.

L'exercice consiste à retrouver les commandes `1`, `0`, `?` et les valeurs fictives issues du logiciel. »

## 06:50–07:30 — Diagnostiquer trois problèmes typiques

[ÉCRAN] Afficher les erreurs, sans forcer le matériel : `device signature`, horloge absente, absence de messages.

« Si l'IDE ne reconnaît pas la signature de la puce, je vérifie la référence et les fils MOSI, MISO, SCK, RESET, puis l'alimentation et l'horloge.

Si le programme est envoyé mais ne démarre pas, je m'interroge sur la concordance entre les fuses et le quartz.

Et si la puce fonctionne mais que mon ordinateur n'affiche aucun message, je vérifie si j'ai réellement connecté un adaptateur USB–TTL sur la cible. La Uno programmateur n'est pas automatiquement le port série du firmware cible. »

## 07:30–08:00 — Exercice et transition

« À vous de jouer : dessinez les six fils ISP entre une Uno programmateur et un ATmega328P DIP28, puis justifiez le choix **Upload Using Programmer**.

L'essentiel de ce module tient en une idée : **nous avons changé le support matériel, pas redémarré le logiciel**. Notre compteur continuera à gagner des fonctionnalités.

Dans le Module 10, nous pourrons ajouter la communication GSM/GPRS avec le SIM800L tout en conservant le cœur de notre firmware. »

## Checklist de tournage

- [ ] Le premier sketch ArduinoISP est téléversé **dans la Uno**, puis les sketches cibles dans la puce externe.
- [ ] Les six signaux sont vérifiés et filmés **hors tension** lors des modifications.
- [ ] La différence entre bootloader, fuses et ISP est expliquée sans raccourci.
- [ ] L'horloge 16 MHz et le port série externe sont présentés correctement.
- [ ] Les actions ISP et le fonctionnement physique sont montrés comme tests réels **uniquement s'ils ont effectivement réussi**.
- [ ] Deux vidéos de 8 min après répétition.
