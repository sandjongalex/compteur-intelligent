# Quiz M05 — Corrigé expliqué (formateur)

**Grille des réponses :** Q01: B · Q02: A · Q03: C · Q04: D · Q05: B · Q06: C · Q07: A · Q08: D · Q09: C · Q10: B.

## Q01 — Quel rôle donne cette instruction : pinMode(2, INPUT_PULLUP); ?

**Réponse : B**

- **A. La broche D2 devient une sortie analogique** — Cette instruction ne configure pas une sortie.
- **B. La broche D2 est une entrée avec résistance de rappel interne vers HIGH** — INPUT_PULLUP active l'entrée et sa résistance de rappel interne.
- **C. La LED intégrée clignote automatiquement** — Elle ne commande pas automatiquement la LED.
- **D. La broche D2 est alimentée directement par le secteur** — Le secteur n'a aucune place sur une broche numérique Arduino.

Compétence : Identifier une entrée.

## Q02 — Avec un bouton correctement connecté entre D2 et GND, que renvoie digitalRead(2) quand le bouton est pressé avec INPUT_PULLUP ?

**Réponse : A**

- **A. LOW** — L'appui relie l'entrée à GND : elle est lue LOW.
- **B. HIGH** — HIGH correspond à l'état relâché dans ce montage.
- **C. Toujours 5 V comme valeur flottante** — L'entrée est polarisée par la résistance de rappel, donc elle n'est pas flottante.
- **D. Un nombre en kWh** — Une entrée numérique lit un niveau HIGH/LOW, pas une énergie.

Compétence : Lire la logique inversée.

## Q03 — Que fait la version V01-01 du programme bouton/LED ?

**Réponse : C**

- **A. Elle lit une tension secteur réelle** — Le secteur n'est pas raccordé dans ce TP.
- **B. Elle conserve la LED allumée après un seul appui** — La bascule est enseignée après cette première version.
- **C. Elle allume la LED seulement tant que le bouton est maintenu** — La LED suit directement l'état instantané du bouton.
- **D. Elle transmet les mesures par GSM** — Aucun modem GSM n'est utilisé.

Compétence : Distinguer action maintenue et bascule.

## Q04 — Quel est le rôle de Serial.begin(9600) sur notre Uno Rev3 ?

**Réponse : D**

- **A. Définir l'anti-rebond à 9 600 ms** — L'anti-rebond est une autre partie du code.
- **B. Redémarrer la carte toutes les secondes** — Serial.begin ne programme pas de redémarrage.
- **C. Choisir la broche D2 comme sortie** — Le réglage D2 est fait par pinMode.
- **D. Initialiser la liaison série à 9 600 bauds** — Serial.begin règle la vitesse série au débit indiqué.

Compétence : Reconnaître Serial.begin.

## Q05 — Pourquoi la bascule de la LED sans anti-rebond peut-elle changer plusieurs fois lors d'un appui physique ?

**Réponse : B**

- **A. Parce que la LED intégrée se connecte au 230 V** — Aucun secteur n'est raccordé.
- **B. Parce que le contact mécanique peut produire plusieurs transitions rapides** — Le rebond crée de brefs changements HIGH/LOW pouvant être pris pour plusieurs appuis.
- **C. Parce que Serial.begin n'est pas appelé** — Serial.begin n'est pas requis pour faire basculer une LED.
- **D. Parce que la broche D2 est toujours une sortie** — D2 est une entrée configurée avec INPUT_PULLUP.

Compétence : Identifier le rebond mécanique.

## Q06 — Dans la version anti-rebond, à quel moment doit-on inverser l'état de la LED ?

**Réponse : C**

- **A. Dès que la lecture brute passe très brièvement à LOW** — Une brève impulsion peut être un rebond.
- **B. Chaque tour de loop pendant LOW** — Changer à chaque tour de loop ferait clignoter ou basculer trop vite.
- **C. Lorsque le niveau est stabilisé à LOW après la période d'anti-rebond** — Le front d'appui stable LOW déclenche une seule bascule.
- **D. À chaque relâchement et chaque appui** — On doit choisir un seul événement par appui : pas les deux transitions.

Compétence : Comprendre une pression validée.

## Q07 — Quelle séquence lit correctement un caractère seulement s'il est disponible ?

**Réponse : A**

- **A. if (Serial.available() > 0) { char c = (char)Serial.read(); }** — Le test available vérifie qu'une donnée est prête avant de la lire.
- **B. while (Serial.available() == 0) { } sans autre traitement** — Une attente vide tant qu'il n'y a rien bloque le reste du programme.
- **C. delay(5000); puis lire systématiquement** — Une pause fixe ne garantit pas l'arrivée d'un caractère.
- **D. digitalRead(13) pour recevoir un caractère USB** — digitalRead lit une entrée numérique, pas un octet du port série.

Compétence : Lire un caractère sans blocage.

## Q08 — Dans notre exemple, quel caractère envoyé depuis le moniteur série éteint la LED intégrée ?

**Réponse : D**

- **A. 1** — 1 allume la LED.
- **B. ?** — ? affiche l'aide.
- **C. L** — L n'est pas une commande reconnue par cet exemple.
- **D. 0** — 0 éteint la LED.

Compétence : Interpréter les commandes.

## Q09 — Pourquoi utiliser (unsigned long)(maintenant - precedentMs) >= 1000UL avec millis() ?

**Réponse : C**

- **A. Pour forcer le programme à attendre bloqué une seconde** — La comparaison s'effectue sans delay et laisse tourner loop.
- **B. Pour supprimer définitivement l'overflow de toutes les variables** — Le débordement existe toujours ; la soustraction en arithmétique non signée en gère le retour pour des intervalles adaptés.
- **C. Pour déclencher une tâche environ chaque seconde sans bloquer et gérer correctement le retour de millis à zéro** — La soustraction non signée fonctionne au retour de millis à zéro, pour une période bien inférieure à sa plage.
- **D. Pour transformer 9600 bauds en 1 kWh** — Il n'existe aucune conversion directe entre des bauds et de l'énergie.

Compétence : Comprendre le calcul du temps écoulé.

## Q10 — La carte doit afficher une donnée fictive toutes les secondes et répondre à la commande « 1 » entre deux affichages. Quelle approche répond le mieux au besoin ?

**Réponse : B**

- **A. Appeler delay(1000) avant de lire le port série** — delay(1000) retarde la prise en compte des commandes dans loop.
- **B. Lire les commandes dans chaque loop puis vérifier le temps écoulé avec millis()** — Lire les caractères disponibles puis comparer millis permet d'accomplir les deux tâches sans attente bloquante.
- **C. Attendre dans while (Serial.available() == 0) avant chaque relevé** — Une boucle d'attente bloque les relevés en l'absence de commandes.
- **D. Raccorder D0/RX au secteur pour accélérer l'UART** — Raccorder D0 au secteur est dangereux et ne résout aucun problème de temporisation.

Compétence : Prédire la réactivité.

## Barème et remédiation

- 1 point par bonne réponse ; seuil **8/10**.
- Si une question de sécurité est manquée, corriger avant la prochaine manipulation.
- Si l'apprenant rate **Q05/Q06**, revoir le passage `V01_02` → `V01_03`.
- S'il rate **Q09/Q10**, comparer les deux pratiques `delay()` et `millis()` dans les sketches du Module 05.
- Ce quiz n'est pas encore importé dans AlexTech Academy ; le JSON est un format de travail.
