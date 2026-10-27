# Quiz complet M01 — Bases électriques et architecture du compteur

**Statut : 10 questions rédigées et corrigées ; quiz non encore intégré dans une plateforme d'e-learning.**

- Niveau : débutant (4 faciles, 4 intermédiaires, 2 difficiles).
- Format : 10 QCM, une seule bonne réponse par question.
- Barème : 1 point par bonne réponse, sur 10 points.
- **Seuil de validation : 8/10 (80 %).**
- Durée conseillée hors vidéo : 10 à 15 minutes.
- Objectifs : reconnaître les unités et les composants, calculer une énergie, comprendre le trajet des données.
- Les questions portant sur la sécurité électrique nécessitent une correction explicative obligatoire lorsqu'elles seront ajoutées dans les modules concernés.

## Version apprenant — ne pas consulter le corrigé avant de répondre

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

---

## Corrigé formateur et explications

**Grille des réponses :** Q01: B, Q02: C, Q03: A, Q04: D, Q05: B, Q06: D, Q07: A, Q08: C, Q09: C, Q10: D

### Q01 — Réponse B

**Justification :** Le volt (V) mesure la tension, c'est-à-dire une différence de potentiel électrique.

- **A. La puissance** — La puissance s'exprime en watts (W), pas en volts.
- **B. La tension** — Le volt (V) mesure la tension, c'est-à-dire une différence de potentiel électrique.
- **C. L'énergie** — L'énergie s'exprime notamment en wattheures (Wh) ou kilowattheures (kWh).
- **D. La fréquence** — La fréquence s'exprime en hertz (Hz).

### Q02 — Réponse C

**Justification :** L'ampère (A) est l'unité du courant électrique.

- **A. Le watt** — Le watt mesure la puissance active.
- **B. Le volt** — Le volt mesure la tension électrique.
- **C. L'ampère** — L'ampère (A) est l'unité du courant électrique.
- **D. Le kilowattheure** — Le kilowattheure est une unité d'énergie, pas de courant.

### Q03 — Réponse A

**Justification :** Mille watts constituent un kilowatt : 1 000 W = 1 kW.

- **A. 1 kW** — Mille watts constituent un kilowatt : 1 000 W = 1 kW.
- **B. 1 kWh** — Le kWh exprime une énergie ; il manque une durée pour passer de la puissance à l'énergie.
- **C. 1 kV** — Le kilovolt est une unité de tension, pas de puissance.
- **D. 1 Wh** — Le Wh est une unité d'énergie et ne correspond pas à une puissance de 1 000 W.

### Q04 — Réponse D

**Justification :** 500 W = 0,5 kW ; 0,5 kW × 2 h = 1 kWh.

- **A. 0,25 kWh** — 0,25 kWh correspondrait à 500 W pendant 0,5 heure, pas 2 heures.
- **B. 2 kWh** — 2 kWh correspondrait à 1 kW pendant 2 heures.
- **C. 0,5 kWh** — 0,5 kWh correspond à 500 W pendant 1 heure.
- **D. 1 kWh** — 500 W = 0,5 kW ; 0,5 kW × 2 h = 1 kWh.

### Q05 — Réponse B

**Justification :** Le PZEM-004T fournit notamment tension, courant, puissance et énergie électrique.

- **A. Afficher le tableau de bord web** — Le tableau de bord est produit par l'application web et son navigateur.
- **B. Mesurer les grandeurs électriques** — Le PZEM-004T fournit notamment tension, courant, puissance et énergie électrique.
- **C. Stocker les utilisateurs dans SQLite** — Le stockage SQLite s'effectue du côté du serveur Flask.
- **D. Conserver la date lors d'une coupure** — La date est fournie par l'horloge RTC DS3231, pas par le PZEM.

### Q06 — Réponse D

**Justification :** L'ATmega328P exécute le firmware et calcule les consommations journalières et mensuelles.

- **A. Le SIM800L** — Le SIM800L assure la communication GSM/GPRS.
- **B. Le LCD I2C** — Le LCD affiche des caractères à l'utilisateur.
- **C. Le PZEM-004T** — Le PZEM effectue les mesures, mais le firmware du compteur tourne sur le microcontrôleur.
- **D. L'ATmega328P** — L'ATmega328P exécute le firmware et calcule les consommations journalières et mensuelles.

### Q07 — Réponse A

**Justification :** Flask fournit l'API de réception, vérifie les données puis permet leur stockage et leur consultation.

- **A. Recevoir et traiter les relevés envoyés** — Flask fournit l'API de réception, vérifie les données puis permet leur stockage et leur consultation.
- **B. Alimenter le SIM800L en 4 V** — L'alimentation du SIM800L relève du circuit d'alimentation, pas du serveur.
- **C. Mesurer la tension secteur directement** — La tension secteur est mesurée au niveau du PZEM.
- **D. Remplacer le microcontrôleur ATmega328P** — L'ATmega328P reste nécessaire pour traiter localement les mesures et piloter les périphériques.

### Q08 — Réponse C

**Justification :** Le kWh exprime une quantité d'énergie, par exemple 1 kW utilisé pendant 1 h.

- **A. C'est une unité de courant électrique** — Le courant se mesure en ampères (A).
- **B. C'est une unité de tension** — La tension se mesure en volts (V).
- **C. C'est une unité d'énergie électrique** — Le kWh exprime une quantité d'énergie, par exemple 1 kW utilisé pendant 1 h.
- **D. C'est une unité de fréquence** — La fréquence se mesure en hertz (Hz).

### Q09 — Réponse C

**Justification :** 30 min = 0,5 h ; 2 kW × 0,5 h = 1 kWh.

- **A. 0,5 kWh** — 0,5 kWh correspondrait à 1 kW pendant 30 minutes.
- **B. 2 kWh** — 2 kWh correspondrait à une heure entière d'utilisation à 2 kW.
- **C. 1 kWh** — 30 min = 0,5 h ; 2 kW × 0,5 h = 1 kWh.
- **D. 4 kWh** — 4 kWh correspondrait à deux heures d'utilisation à 2 kW.

### Q10 — Réponse D

**Justification :** Le PZEM mesure ; l'ATmega traite ; le SIM800L transmet ; Flask/SQLite stocke ; le navigateur affiche.

- **A. SQLite → ATmega328P → PZEM → navigateur** — SQLite est du côté serveur et ne commande pas directement le PZEM par l'ATmega.
- **B. PZEM → navigateur → SIM800L → SQLite** — Le navigateur ne reçoit pas directement les mesures brutes avant le modem et le serveur.
- **C. LCD → SIM800L → PZEM → navigateur** — Le LCD est un écran local, pas la source de la mesure.
- **D. PZEM → ATmega328P → SIM800L → Flask/SQLite → navigateur** — Le PZEM mesure ; l'ATmega traite ; le SIM800L transmet ; Flask/SQLite stocke ; le navigateur affiche.

## Contrôle du quiz

- [x] Dix questions rédigées, quatre choix distincts et une seule bonne réponse.
- [x] Un corrigé argumenté est présent pour chaque proposition.
- [x] Les deux calculs sont vérifiés (500 W × 2 h = 1 kWh ; 2 kW × 0,5 h = 1 kWh).
- [x] Les contenus correspondent aux objectifs pédagogiques du module M01.
- [ ] Quiz importé dans la plateforme et parcours apprenant testé.
