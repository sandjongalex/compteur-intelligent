# Quiz M01 — Version apprenant (sans réponses)

**10 QCM, une seule réponse par question.** Seuil de réussite : **8/10**.


### Q01 — Quelle grandeur électrique s'exprime en volts ?

*Difficulté : Facile · Compétence : Reconnaître l'unité de tension*

A. La puissance
B. La tension
C. L'énergie
D. La fréquence

### Q02 — Quelle unité mesure le courant électrique ?

*Difficulté : Facile · Compétence : Reconnaître l'unité du courant*

A. Le watt
B. Le volt
C. L'ampère
D. Le kilowattheure

### Q03 — Une puissance de 1 000 W correspond à :

*Difficulté : Facile · Compétence : Convertir W en kW*

A. 1 kW
B. 1 kWh
C. 1 kV
D. 1 Wh

### Q04 — Un appareil utilise une puissance active constante de 500 W pendant 2 heures. Quelle énergie consomme-t-il ?

*Difficulté : Intermédiaire · Compétence : Calculer une énergie sur deux heures*

A. 0,25 kWh
B. 2 kWh
C. 0,5 kWh
D. 1 kWh

### Q05 — Quel est le rôle principal du PZEM-004T dans notre projet ?

*Difficulté : Facile · Compétence : Identifier le module d'acquisition*

A. Afficher le tableau de bord web
B. Mesurer les grandeurs électriques
C. Stocker les utilisateurs dans SQLite
D. Conserver la date lors d'une coupure

### Q06 — Quel composant exécute le programme de traitement des mesures dans le compteur ?

*Difficulté : Intermédiaire · Compétence : Identifier l'unité de traitement embarqué*

A. Le SIM800L
B. Le LCD I2C
C. Le PZEM-004T
D. L'ATmega328P

### Q07 — Dans notre architecture, à quoi sert principalement le serveur Python Flask ?

*Difficulté : Intermédiaire · Compétence : Comprendre la fonction du backend*

A. Recevoir et traiter les relevés envoyés
B. Alimenter le SIM800L en 4 V
C. Mesurer la tension secteur directement
D. Remplacer le microcontrôleur ATmega328P

### Q08 — Quelle affirmation décrit correctement le kilowattheure (kWh) ?

*Difficulté : Intermédiaire · Compétence : Différencier les unités d'énergie et de puissance*

A. C'est une unité de courant électrique
B. C'est une unité de tension
C. C'est une unité d'énergie électrique
D. C'est une unité de fréquence

### Q09 — Un appareil utilise une puissance active constante de 2 kW pendant 30 minutes. Quelle énergie consomme-t-il ?

*Difficulté : Difficile · Compétence : Calculer avec conversion des minutes en heures*

A. 0,5 kWh
B. 2 kWh
C. 1 kWh
D. 4 kWh

### Q10 — Quel trajet décrit correctement une mesure, depuis son acquisition jusqu'à sa consultation sur le web ?

*Difficulté : Difficile · Compétence : Ordonner le parcours de la donnée*

A. SQLite → ATmega328P → PZEM → navigateur
B. PZEM → navigateur → SIM800L → SQLite
C. LCD → SIM800L → PZEM → navigateur
D. PZEM → ATmega328P → SIM800L → Flask/SQLite → navigateur
