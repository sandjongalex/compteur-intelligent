# M04 — Quiz apprenant : bases du C/C++ (sans corrigé)

**10 questions** · **une seule bonne réponse** · **seuil de validation : 8/10 (80 %)**.

### Q01 — Quel type de variable utiliser pour compter un petit nombre entier de tentatives sur notre Arduino Uno ?

*Facile · Reconnaître un entier*

A. float
B. bool
C. int
D. char

### Q02 — Que représente la valeur false dans « bool alarme = false; » ?

*Facile · Reconnaître un booléen*

A. L'alarme est dans l'état faux/inactif.
B. Une erreur de compilation.
C. Un nombre flottant.
D. Un message à imprimer.

### Q03 — Que signifie « const » dans « const float FACTEUR = 1000.0f; » ?

*Facile · Comprendre les constantes*

A. Le programme attend 1 000 secondes.
B. La variable deviendra entière.
C. La valeur sera affichée en série.
D. Le code n'est pas censé modifier FACTEUR après sa déclaration.

### Q04 — Dans une condition C++, quel opérateur teste si deux valeurs sont égales ?

*Facile · Distinguer affectation et comparaison*

A. =
B. ==
C. ++
D. !=

### Q05 — Dans un sketch Uno Rev3, quelle valeur reçoit « int resultat = 5 / 2; » ?

*Intermédiaire · Identifier une division entière*

A. 2.5
B. 3
C. 2
D. 0

### Q06 — On définit tensionV = 245.0f et seuil fictif = 240.0f. Quelle branche est exécutée par « if (tensionV > seuil) ... else ... » ?

*Intermédiaire · Comprendre if/else*

A. La branche if.
B. Toujours la branche else.
C. Aucune branche.
D. Les deux branches.

### Q07 — Que va afficher « for (int i = 1; i <= 3; i++) Serial.println(i); » ?

*Intermédiaire · Lire une boucle for*

A. 0, 1, 2
B. 1, 2
C. 1, 2, 3
D. 3 seulement

### Q08 — Comment assurer l'arrêt de « int essais = 0; while (essais < 3) { ... } » ?

*Intermédiaire · Éviter les boucles infinies*

A. Retirer les accolades.
B. Ne jamais modifier essais.
C. Mettre une instruction delay(1000) sans changement de condition.
D. Augmenter essais dans la boucle pour que la condition devienne fausse.

### Q09 — Que renvoie la fonction « float wattsVersKilowatts(float w) { return w / 1000.0f; } » si elle reçoit 1250.0f ?

*Difficile · Lire une fonction et son résultat*

A. 1250.0
B. 1.25
C. 0.125
D. 125.0

### Q10 — Pour une puissance active constante de 200 W pendant 5 heures, quelle valeur affiche le calcul « (200.0f / 1000.0f) * 5.0f » ?

*Difficile · Calculer une énergie et vérifier les unités*

A. 1000.0 kWh
B. 0.2 kWh
C. 5.0 kWh
D. 1.0 kWh

**Consigne :** répondre avant de consulter les solutions du formateur. Le quiz est indépendant de la durée des deux vidéos.
