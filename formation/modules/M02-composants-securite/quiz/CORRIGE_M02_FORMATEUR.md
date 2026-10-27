# M02 — Corrigé du formateur

**Grille des bonnes réponses :** Q01=B · Q02=C · Q03=A · Q04=D · Q05=B · Q06=C · Q07=A · Q08=D · Q09=C · Q10=A.

## Correction détaillée

### Q01 — Quel composant exécute le programme du compteur intelligent ?

**Bonne réponse : B — L'ATmega328P**

- **A. Le DS3231** — Le DS3231 gère la date et l'heure, pas le firmware du compteur.
- **B. L'ATmega328P** — L'ATmega328P est le microcontrôleur qui exécute le firmware.
- **C. Le PZEM-004T** — Le PZEM-004T fournit des mesures électriques ; il n'exécute pas notre firmware.
- **D. Le LCD 20×4** — Le LCD sert à afficher des caractères.

**Compétence :** Identifier le microcontrôleur ; **niveau :** Facile ; **thème :** Composants.

### Q02 — Quel module fournit au microcontrôleur la tension, le courant et l'énergie mesurés ?

**Bonne réponse : C — Le PZEM-004T V3.0**

- **A. Le SIM800L** — Le SIM800L transmet des relevés par réseau mobile.
- **B. La FRAM** — La FRAM mémorise des données.
- **C. Le PZEM-004T V3.0** — Le PZEM-004T fournit les grandeurs électriques mesurées.
- **D. Le buzzer** — Le buzzer émet des signaux sonores.

**Compétence :** Identifier le module de mesure ; **niveau :** Facile ; **thème :** Composants.

### Q03 — Pourquoi ajoutons-nous un DS3231 au compteur ?

**Bonne réponse : A — Pour fournir la date et l'heure**

- **A. Pour fournir la date et l'heure** — Le DS3231 est une horloge temps réel qui fournit date et heure.
- **B. Pour transformer le 230 V en 5 V** — La conversion d'alimentation relève d'un dispositif AC/DC adapté.
- **C. Pour envoyer les données GSM** — L'envoi GSM est le rôle du SIM800L.
- **D. Pour produire une alarme sonore** — Le buzzer sert à fournir une alarme sonore.

**Compétence :** Expliquer le rôle du DS3231 ; **niveau :** Facile ; **thème :** Composants.

### Q04 — À quelle tension prévoit-on de faire fonctionner notre ATmega328P dans sa configuration de cours à 16 MHz ?

**Bonne réponse : D — 5 V continu**

- **A. 230 V alternatif** — Le secteur 230 V ne doit jamais être appliqué directement au microcontrôleur.
- **B. 12 V continu** — 12 V direct dépasse la tension admissible de la puce.
- **C. 4,0 V continu** — 4 V est la consigne retenue pour le SIM800L nu, pas l'alimentation logique prévue du cours.
- **D. 5 V continu** — La configuration du cours utilise un ATmega328P sous une alimentation régulée de 5 V.

**Compétence :** Identifier la tension logique ; **niveau :** Facile ; **thème :** Alimentation.

### Q05 — Quelle alimentation faut-il prévoir pour l'entrée VBAT d'un SIM800L nu, selon sa documentation ?

**Bonne réponse : B — Environ 4,0 V, capable de fournir des pointes proches de 2 A**

- **A. 5 V direct depuis l'Arduino Uno** — 5 V direct sur VBAT du modem nu est hors de la plage donnée dans la documentation.
- **B. Environ 4,0 V, capable de fournir des pointes proches de 2 A** — Une alimentation régulée autour de 4,0 V avec capacité de fournir les pointes de transmission est adaptée à la spécification du modem nu.
- **C. 230 V alternatif directement** — Le SIM800L est un modem électronique basse tension, pas un récepteur du secteur.
- **D. Une simple sortie GPIO de l'ATmega328P** — Une sortie GPIO n'est pas une alimentation de modem GSM.

**Compétence :** Reconnaître les contraintes du SIM800L ; **niveau :** Intermédiaire ; **thème :** Alimentation.

### Q06 — Quel exercice peut être confié sans intervention secteur à un apprenant débutant ?

**Bonne réponse : C — Faire clignoter une LED sur Arduino Uno alimentée de manière adaptée par USB**

- **A. Relier le PZEM directement au secteur en gardant les fils nus** — Le raccordement au secteur par un novice avec des conducteurs accessibles n'est pas acceptable.
- **B. Mesurer la phase secteur avec une breadboard** — Une breadboard n'est pas un support adapté aux circuits secteur.
- **C. Faire clignoter une LED sur Arduino Uno alimentée de manière adaptée par USB** — Une LED sur Arduino Uno correctement alimentée est un exercice basse tension approprié.
- **D. Remplacer un fusible secteur sous tension** — La manipulation de protections secteur sous tension est dangereuse.

**Compétence :** Choisir une pratique sûre ; **niveau :** Intermédiaire ; **thème :** Sécurité.

### Q07 — Quel énoncé est correct à propos du synoptique d'alimentation de notre formation ?

**Bonne réponse : A — Il montre les fonctions, mais ne remplace pas un schéma secteur professionnel validé**

- **A. Il montre les fonctions, mais ne remplace pas un schéma secteur professionnel validé** — Un synoptique explique l'architecture et ne sert pas de notice de raccordement secteur.
- **B. Il suffit pour brancher directement le 230 V sur une carte Arduino** — Il est dangereux de raccorder le secteur à une carte logique sans conception validée.
- **C. Il autorise l'usage d'une breadboard pour le 230 V** — La breadboard ne convient pas à des essais secteur.
- **D. Il dispense des protections et de l'isolation** — Les protections et l'isolation restent nécessaires.

**Compétence :** Distinguer schéma fonctionnel et câblage ; **niveau :** Intermédiaire ; **thème :** Sécurité.

### Q08 — Pourquoi notre architecture prévoit-elle une alimentation AC/DC isolée et un boîtier adapté ?

**Bonne réponse : D — Pour séparer et protéger les parties électroniques accessibles de la zone secteur dangereuse**

- **A. Pour accélérer le code C++** — Le traitement logiciel est indépendant de la protection électrique.
- **B. Pour remplacer la FRAM** — La FRAM garde les données, pas les protections secteur.
- **C. Pour assurer le réseau GSM** — La couverture GSM ne dépend pas de l'isolation secteur.
- **D. Pour séparer et protéger les parties électroniques accessibles de la zone secteur dangereuse** — L'isolation et le boîtier contribuent à réduire les risques d'accès à une tension dangereuse.

**Compétence :** Reconnaître l'intérêt de l'isolation ; **niveau :** Intermédiaire ; **thème :** Sécurité.

### Q09 — Le SIM800L nu redémarre dès qu'il tente d'émettre, alors que la carte ATmega fonctionne. Quelle vérification est la plus pertinente avant tout autre essai ?

**Bonne réponse : C — Vérifier une alimentation 4 V stable, ses pointes de courant et son découplage**

- **A. Remplacer immédiatement le LCD** — Le LCD n'explique pas directement un redémarrage radio du modem.
- **B. Augmenter arbitrairement VBAT à 5 V** — 5 V dépasse la plage VBAT du SIM800L nu.
- **C. Vérifier une alimentation 4 V stable, ses pointes de courant et son découplage** — Les pointes proches de 2 A peuvent provoquer une chute de tension et des redémarrages si l'alimentation est inadéquate.
- **D. Relier le modem au 230 V** — Relier un modem GSM au secteur est dangereux et destructeur.

**Compétence :** Diagnostiquer une défaillance de communication liée à l'alimentation ; **niveau :** Difficile ; **thème :** Diagnostic.

### Q10 — Un ATmega328P fonctionne en logique 5 V et un SIM800L nu utilise des niveaux UART plus bas. Avant de connecter les lignes série, quelle action est correcte ?

**Bonne réponse : A — Vérifier les niveaux de tension et utiliser une adaptation logique adaptée**

- **A. Vérifier les niveaux de tension et utiliser une adaptation logique adaptée** — La compatibilité des niveaux UART doit être vérifiée et une adaptation mise en place si nécessaire.
- **B. Connecter directement toutes les broches sans vérifier** — Un niveau logique 5 V peut être incompatible avec l'entrée du modem nu.
- **C. Supprimer les masses et les protections au hasard** — On ne corrige pas un problème de niveaux de tension en improvisant les retours et les protections.
- **D. Changer la pile du DS3231** — La pile du DS3231 n'a aucun rapport avec l'interface UART du modem.

**Compétence :** Diagnostiquer un risque d'interface logique ; **niveau :** Difficile ; **thème :** Diagnostic.

## Règle de validation

- Au moins **8/10**.
- Pour les erreurs de sécurité et d'alimentation (**Q05, Q06, Q07, Q08**), le formateur doit fournir la correction et l'apprenant doit reformuler la pratique sûre ; **le score global seul ne dispense pas de cette correction**.
- Les questions sont conçues pour être intégrées ultérieurement dans AlexTech Academy, sans affirmer que cette intégration est déjà effective.