# Quiz M07 — Corrigé du formateur

**Réponses :** Q01=B · Q02=C · Q03=A · Q04=D · Q05=C · Q06=A · Q07=B · Q08=D · Q09=C · Q10=B.

## Q01 — Sur l'Arduino Uno Rev3, quelles broches portent les signaux I2C SDA et SCL ?

**Réponse correcte : B**

- **A. D0 et D1** — D0/D1 portent l'UART matériel, pas SDA/SCL sur Uno.
- **B. A4 et A5** — SDA = A4 et SCL = A5 sur Uno Rev3.
- **C. D8 et D9** — D8/D9 ne sont pas les broches du bus I2C matériel de la Uno.
- **D. 5 V et GND** — 5 V et GND fournissent l'alimentation, pas les deux signaux I2C.

## Q02 — Quel est le rôle principal du DS3231 dans notre compteur ?

**Réponse correcte : C**

- **A. Mesurer le courant secteur** — Le courant viendra du module PZEM.
- **B. Transmettre les données GSM** — La communication mobile sera traitée par le SIM800L.
- **C. Fournir date et heure** — Le DS3231 est une horloge temps réel.
- **D. Afficher les caractères sur LCD** — L'affichage est pris en charge par le LCD 20×4.

## Q03 — Que signifie un écran LCD « 20×4 » ?

**Réponse correcte : A**

- **A. 20 caractères par ligne et 4 lignes** — C'est bien le nombre de colonnes et de lignes de caractères.
- **B. 20 volts et 4 ampères** — Les valeurs ne décrivent pas la tension ni le courant.
- **C. 20 lignes et 4 caractères** — Les dimensions sont inversées dans cette réponse.
- **D. 20 adresses I2C et 4 broches** — La taille d'un écran n'est pas un nombre d'adresses I2C.

## Q04 — Quelle adresse I2C est normalement associée au DS3231 ?

**Réponse correcte : D**

- **A. 0x27** — 0x27 est fréquente sur certains adaptateurs LCD I2C, pas le DS3231.
- **B. 0x3F** — 0x3F apparaît sur certaines variantes de backpack LCD.
- **C. 0x57** — 0x57 peut appartenir à une EEPROM additionnelle sur certains modules RTC.
- **D. 0x68** — 0x68 est l'adresse I2C du DS3231.

## Q05 — Le programme signale rtc.lostPower() après le branchement. Quelle action est la plus correcte ?

**Réponse correcte : C**

- **A. Accepter la date comme valide sans vérification** — L'arrêt de l'oscillateur peut rendre l'heure invalide.
- **B. Afficher une date fictive en la présentant comme réelle** — Les données inventées ne doivent pas être présentées comme réelles.
- **C. Signaler une heure non fiable, vérifier le module puis régler volontairement une seule fois** — La date doit être vérifiée puis réglée volontairement avant de servir aux calculs.
- **D. Remettre le PZEM à zéro** — La remise à zéro du PZEM n'a aucun rapport avec la fiabilité de l'horloge.

## Q06 — Une carte DS3231 et un LCD avec adaptateur I2C peuvent-ils partager SDA et SCL ?

**Réponse correcte : A**

- **A. Oui, si leurs adresses et les caractéristiques électriques sont compatibles** — I2C est un bus partagé, sous réserve d'adresses et de niveaux compatibles.
- **B. Non, l'I2C exige un seul appareil** — L'I2C permet précisément plusieurs périphériques.
- **C. Oui, même si leurs niveaux logiques sont incompatibles** — Des niveaux incompatibles peuvent endommager les composants.
- **D. Seulement si la tension secteur est branchée** — Un bus I2C fonctionne en basse tension et n'exige pas le secteur.

## Q07 — Que produit lcd.setCursor(0, 2) sur un LCD 20×4 ?

**Réponse correcte : B**

- **A. Il efface la deuxième ligne** — setCursor positionne le curseur, n'efface pas une ligne.
- **B. Il positionne le curseur à la colonne 0 de la troisième ligne** — Le numéro de ligne commence à zéro : 2 désigne la troisième ligne.
- **C. Il règle automatiquement l'heure de la RTC** — Un LCD ne règle pas automatiquement la RTC.
- **D. Il choisit l'adresse I2C 0x02** — Les paramètres sont colonne et ligne, pas adresse I2C.

## Q08 — Pourquoi éviter lcd.clear() à chaque passage de loop() quand une ligne seulement change ?

**Réponse correcte : D**

- **A. Car cela éteint définitivement le rétroéclairage** — Le rétroéclairage et clear() ont des fonctions distinctes.
- **B. Car cela réinitialise aussi la date du DS3231** — Le LCD n'efface pas la RTC via clear().
- **C. Car cela efface la mémoire EEPROM** — clear() efface l'affichage LCD, pas une EEPROM externe.
- **D. Car l'effacement fréquent peut créer un scintillement ; mieux vaut modifier la zone utile** — Mettre à jour seulement la ligne modifiée réduit l'effacement et le scintillement.

## Q09 — Pourquoi ne faut-il pas appeler rtc.adjust(DateTime(F(__DATE__), F(__TIME__))) à chaque démarrage du compteur ?

**Réponse correcte : C**

- **A. Cela remplace automatiquement une mesure du PZEM** — Une fonction de réglage de la RTC ne remplace pas une lecture PZEM.
- **B. Cela supprime toutes les adresses I2C** — Les adresses I2C ne sont pas effacées par rtc.adjust().
- **C. Cela peut reculer l'horloge à une ancienne date de compilation et fausser les périodes** — __DATE__ et __TIME__ contiennent le moment de compilation, qui peut être ancien lors d'un redémarrage.
- **D. Cela convertit la date en tension** — Une date et une tension sont des données différentes.

## Q10 — Que doit afficher le compteur si la DS3231 est absente, tandis que les kWh jour et mois restent de simples valeurs d'exemple ?

**Réponse correcte : B**

- **A. Une date aléatoire et les kWh comme mesures réelles** — Ce comportement cache un défaut et fait passer une simulation pour du réel.
- **B. « DATE: A REGLER » (ou erreur), en indiquant que les autres valeurs sont fictives** — Il distingue date indisponible et mesures simulées, évitant les données mensongères.
- **C. La date d'hier systématiquement** — La date d'hier n'est pas une donnée fiable par défaut.
- **D. Un écran vide sans message** — Un message explicatif est plus utile qu'un silence complet.

## Barème et remédiation

- Une bonne réponse = 1 point ; **seuil de validation 8/10**.
- Erreur aux Q05, Q09 ou Q10 : reprendre le thème de la **date fiable**, qui sera crucial pour les consommations journalières et mensuelles.
- Erreur aux Q06, Q07 ou Q08 : vérifier les adresses du bus I2C et les comportements du LCD avec les sketches du module.
- Le QCM en JSON est un support d'intégration future, **pas encore importé dans AlexTech Academy**.
