# M02 — Quiz apprenant (sans corrigé)

**10 questions** · **1 seule bonne réponse** par question · **Seuil visé : 8/10 (80 %)**.

**Consigne de sécurité :** toute erreur relative au 230 V, à l'isolation ou à l'alimentation du modem doit être étudiée dans le corrigé avant toute manipulation pratique.

### Q01 — Quel composant exécute le programme du compteur intelligent ?

*Facile · Identifier le microcontrôleur*

A. Le DS3231
B. L'ATmega328P
C. Le PZEM-004T
D. Le LCD 20×4

### Q02 — Quel module fournit au microcontrôleur la tension, le courant et l'énergie mesurés ?

*Facile · Identifier le module de mesure*

A. Le SIM800L
B. La FRAM
C. Le PZEM-004T V3.0
D. Le buzzer

### Q03 — Pourquoi ajoutons-nous un DS3231 au compteur ?

*Facile · Expliquer le rôle du DS3231*

A. Pour fournir la date et l'heure
B. Pour transformer le 230 V en 5 V
C. Pour envoyer les données GSM
D. Pour produire une alarme sonore

### Q04 — À quelle tension prévoit-on de faire fonctionner notre ATmega328P dans sa configuration de cours à 16 MHz ?

*Facile · Identifier la tension logique*

A. 230 V alternatif
B. 12 V continu
C. 4,0 V continu
D. 5 V continu

### Q05 — Quelle alimentation faut-il prévoir pour l'entrée VBAT d'un SIM800L nu, selon sa documentation ?

*Intermédiaire · Reconnaître les contraintes du SIM800L*

A. 5 V direct depuis l'Arduino Uno
B. Environ 4,0 V, capable de fournir des pointes proches de 2 A
C. 230 V alternatif directement
D. Une simple sortie GPIO de l'ATmega328P

### Q06 — Quel exercice peut être confié sans intervention secteur à un apprenant débutant ?

*Intermédiaire · Choisir une pratique sûre*

A. Relier le PZEM directement au secteur en gardant les fils nus
B. Mesurer la phase secteur avec une breadboard
C. Faire clignoter une LED sur Arduino Uno alimentée de manière adaptée par USB
D. Remplacer un fusible secteur sous tension

### Q07 — Quel énoncé est correct à propos du synoptique d'alimentation de notre formation ?

*Intermédiaire · Distinguer schéma fonctionnel et câblage*

A. Il montre les fonctions, mais ne remplace pas un schéma secteur professionnel validé
B. Il suffit pour brancher directement le 230 V sur une carte Arduino
C. Il autorise l'usage d'une breadboard pour le 230 V
D. Il dispense des protections et de l'isolation

### Q08 — Pourquoi notre architecture prévoit-elle une alimentation AC/DC isolée et un boîtier adapté ?

*Intermédiaire · Reconnaître l'intérêt de l'isolation*

A. Pour accélérer le code C++
B. Pour remplacer la FRAM
C. Pour assurer le réseau GSM
D. Pour séparer et protéger les parties électroniques accessibles de la zone secteur dangereuse

### Q09 — Le SIM800L nu redémarre dès qu'il tente d'émettre, alors que la carte ATmega fonctionne. Quelle vérification est la plus pertinente avant tout autre essai ?

*Difficile · Diagnostiquer une défaillance de communication liée à l'alimentation*

A. Remplacer immédiatement le LCD
B. Augmenter arbitrairement VBAT à 5 V
C. Vérifier une alimentation 4 V stable, ses pointes de courant et son découplage
D. Relier le modem au 230 V

### Q10 — Un ATmega328P fonctionne en logique 5 V et un SIM800L nu utilise des niveaux UART plus bas. Avant de connecter les lignes série, quelle action est correcte ?

*Difficile · Diagnostiquer un risque d'interface logique*

A. Vérifier les niveaux de tension et utiliser une adaptation logique adaptée
B. Connecter directement toutes les broches sans vérifier
C. Supprimer les masses et les protections au hasard
D. Changer la pile du DS3231

---

Répondre sans regarder le corrigé. Le formateur fournira le corrigé après la tentative.