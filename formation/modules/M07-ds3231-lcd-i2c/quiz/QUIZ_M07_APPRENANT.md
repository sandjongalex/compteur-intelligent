# Quiz M07 — Version apprenant (sans réponses)

**10 QCM (4 faciles / 4 intermédiaires / 2 difficiles)** · 1 seule réponse correcte par question · **8/10 pour valider**.

Ces questions portent sur le code et les situations réellement rencontrées avec l'Arduino Uno, la RTC DS3231 et le LCD I2C. Aucun secteur n'est nécessaire.

## Q01 — Sur l'Arduino Uno Rev3, quelles broches portent les signaux I2C SDA et SCL ?

*Facile · I2C*

A. D0 et D1
B. A4 et A5
C. D8 et D9
D. 5 V et GND

## Q02 — Quel est le rôle principal du DS3231 dans notre compteur ?

*Facile · RTC*

A. Mesurer le courant secteur
B. Transmettre les données GSM
C. Fournir date et heure
D. Afficher les caractères sur LCD

## Q03 — Que signifie un écran LCD « 20×4 » ?

*Facile · LCD*

A. 20 caractères par ligne et 4 lignes
B. 20 volts et 4 ampères
C. 20 lignes et 4 caractères
D. 20 adresses I2C et 4 broches

## Q04 — Quelle adresse I2C est normalement associée au DS3231 ?

*Facile · RTC*

A. 0x27
B. 0x3F
C. 0x57
D. 0x68

## Q05 — Le programme signale rtc.lostPower() après le branchement. Quelle action est la plus correcte ?

*Intermédiaire · RTC*

A. Accepter la date comme valide sans vérification
B. Afficher une date fictive en la présentant comme réelle
C. Signaler une heure non fiable, vérifier le module puis régler volontairement une seule fois
D. Remettre le PZEM à zéro

## Q06 — Une carte DS3231 et un LCD avec adaptateur I2C peuvent-ils partager SDA et SCL ?

*Intermédiaire · I2C*

A. Oui, si leurs adresses et les caractéristiques électriques sont compatibles
B. Non, l'I2C exige un seul appareil
C. Oui, même si leurs niveaux logiques sont incompatibles
D. Seulement si la tension secteur est branchée

## Q07 — Que produit lcd.setCursor(0, 2) sur un LCD 20×4 ?

*Intermédiaire · LCD*

A. Il efface la deuxième ligne
B. Il positionne le curseur à la colonne 0 de la troisième ligne
C. Il règle automatiquement l'heure de la RTC
D. Il choisit l'adresse I2C 0x02

## Q08 — Pourquoi éviter lcd.clear() à chaque passage de loop() quand une ligne seulement change ?

*Intermédiaire · LCD*

A. Car cela éteint définitivement le rétroéclairage
B. Car cela réinitialise aussi la date du DS3231
C. Car cela efface la mémoire EEPROM
D. Car l'effacement fréquent peut créer un scintillement ; mieux vaut modifier la zone utile

## Q09 — Pourquoi ne faut-il pas appeler rtc.adjust(DateTime(F(__DATE__), F(__TIME__))) à chaque démarrage du compteur ?

*Difficile · RTC*

A. Cela remplace automatiquement une mesure du PZEM
B. Cela supprime toutes les adresses I2C
C. Cela peut reculer l'horloge à une ancienne date de compilation et fausser les périodes
D. Cela convertit la date en tension

## Q10 — Que doit afficher le compteur si la DS3231 est absente, tandis que les kWh jour et mois restent de simples valeurs d'exemple ?

*Difficile · Fiabilité*

A. Une date aléatoire et les kWh comme mesures réelles
B. « DATE: A REGLER » (ou erreur), en indiquant que les autres valeurs sont fictives
C. La date d'hier systématiquement
D. Un écran vide sans message

---

Répondre **avant** de consulter le corrigé. Les TP sont disponibles séparément.
