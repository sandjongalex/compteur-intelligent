# Quiz M05 — Version apprenant (sans réponses)

**10 QCM**, une seule réponse correcte par question ; **validation à 8/10**.  
**Répartition :** 3 GPIO, 2 anti-rebond, 3 UART, 2 temporisation ; 4 faciles, 4 intermédiaires, 2 difficiles.

Vous n'avez pas besoin du secteur pour répondre à ce quiz. Les programmes de référence se trouvent dans [code/](../code/README.md).

## Q01 — Quel rôle donne cette instruction : pinMode(2, INPUT_PULLUP); ?

*Facile · Identifier une entrée*

A. La broche D2 devient une sortie analogique
B. La broche D2 est une entrée avec résistance de rappel interne vers HIGH
C. La LED intégrée clignote automatiquement
D. La broche D2 est alimentée directement par le secteur

## Q02 — Avec un bouton correctement connecté entre D2 et GND, que renvoie digitalRead(2) quand le bouton est pressé avec INPUT_PULLUP ?

*Facile · Lire la logique inversée*

A. LOW
B. HIGH
C. Toujours 5 V comme valeur flottante
D. Un nombre en kWh

## Q03 — Que fait la version V01-01 du programme bouton/LED ?

*Facile · Distinguer action maintenue et bascule*

A. Elle lit une tension secteur réelle
B. Elle conserve la LED allumée après un seul appui
C. Elle allume la LED seulement tant que le bouton est maintenu
D. Elle transmet les mesures par GSM

## Q04 — Quel est le rôle de Serial.begin(9600) sur notre Uno Rev3 ?

*Facile · Reconnaître Serial.begin*

A. Définir l'anti-rebond à 9 600 ms
B. Redémarrer la carte toutes les secondes
C. Choisir la broche D2 comme sortie
D. Initialiser la liaison série à 9 600 bauds

## Q05 — Pourquoi la bascule de la LED sans anti-rebond peut-elle changer plusieurs fois lors d'un appui physique ?

*Intermédiaire · Identifier le rebond mécanique*

A. Parce que la LED intégrée se connecte au 230 V
B. Parce que le contact mécanique peut produire plusieurs transitions rapides
C. Parce que Serial.begin n'est pas appelé
D. Parce que la broche D2 est toujours une sortie

## Q06 — Dans la version anti-rebond, à quel moment doit-on inverser l'état de la LED ?

*Intermédiaire · Comprendre une pression validée*

A. Dès que la lecture brute passe très brièvement à LOW
B. Chaque tour de loop pendant LOW
C. Lorsque le niveau est stabilisé à LOW après la période d'anti-rebond
D. À chaque relâchement et chaque appui

## Q07 — Quelle séquence lit correctement un caractère seulement s'il est disponible ?

*Intermédiaire · Lire un caractère sans blocage*

A. if (Serial.available() > 0) { char c = (char)Serial.read(); }
B. while (Serial.available() == 0) { } sans autre traitement
C. delay(5000); puis lire systématiquement
D. digitalRead(13) pour recevoir un caractère USB

## Q08 — Dans notre exemple, quel caractère envoyé depuis le moniteur série éteint la LED intégrée ?

*Intermédiaire · Interpréter les commandes*

A. 1
B. ?
C. L
D. 0

## Q09 — Pourquoi utiliser (unsigned long)(maintenant - precedentMs) >= 1000UL avec millis() ?

*Difficile · Comprendre le calcul du temps écoulé*

A. Pour forcer le programme à attendre bloqué une seconde
B. Pour supprimer définitivement l'overflow de toutes les variables
C. Pour déclencher une tâche environ chaque seconde sans bloquer et gérer correctement le retour de millis à zéro
D. Pour transformer 9600 bauds en 1 kWh

## Q10 — La carte doit afficher une donnée fictive toutes les secondes et répondre à la commande « 1 » entre deux affichages. Quelle approche répond le mieux au besoin ?

*Difficile · Prédire la réactivité*

A. Appeler delay(1000) avant de lire le port série
B. Lire les commandes dans chaque loop puis vérifier le temps écoulé avec millis()
C. Attendre dans while (Serial.available() == 0) avant chaque relevé
D. Raccorder D0/RX au secteur pour accélérer l'UART

---

Répondre sans consulter le corrigé. Les questions de dépannage doivent être justifiées oralement si l'apprenant se trompe.
