# M04 — Quiz corrigé : version formateur

**Réponses :** Q01=C ; Q02=A ; Q03=D ; Q04=B ; Q05=C ; Q06=A ; Q07=C ; Q08=D ; Q09=B ; Q10=D

## Q01 — Bonne réponse C

**Quel type de variable utiliser pour compter un petit nombre entier de tentatives sur notre Arduino Uno ?**

- **A. float** : float sert ici aux valeurs décimales approximatives.
- **B. bool** : bool ne peut représenter que vrai ou faux.
- **C. int** : int est un type entier, adapté à un petit compteur.
- **D. char** : char sert notamment à un caractère, pas à un compteur entier en priorité.

**Objectif évalué :** Reconnaître un entier.

## Q02 — Bonne réponse A

**Que représente la valeur false dans « bool alarme = false; » ?**

- **A. L'alarme est dans l'état faux/inactif.** : bool peut prendre true ou false : ici l'état est faux.
- **B. Une erreur de compilation.** : L'instruction est une déclaration valide.
- **C. Un nombre flottant.** : false n'est pas un nombre flottant.
- **D. Un message à imprimer.** : Aucun texte n'est envoyé par cette instruction.

**Objectif évalué :** Reconnaître un booléen.

## Q03 — Bonne réponse D

**Que signifie « const » dans « const float FACTEUR = 1000.0f; » ?**

- **A. Le programme attend 1 000 secondes.** : Une constante n'impose pas d'attente.
- **B. La variable deviendra entière.** : La déclaration reste de type float.
- **C. La valeur sera affichée en série.** : const n'affiche rien par lui-même.
- **D. Le code n'est pas censé modifier FACTEUR après sa déclaration.** : const empêche de modifier la valeur par une nouvelle affectation ordinaire.

**Objectif évalué :** Comprendre les constantes.

## Q04 — Bonne réponse B

**Dans une condition C++, quel opérateur teste si deux valeurs sont égales ?**

- **A. =** : = affecte une valeur et ne sert pas à tester directement l'égalité.
- **B. ==** : == compare les deux opérandes pour vérifier l'égalité.
- **C. ++** : ++ augmente une variable d'une unité.
- **D. !=** : != teste la différence et non l'égalité.

**Objectif évalué :** Distinguer affectation et comparaison.

## Q05 — Bonne réponse C

**Dans un sketch Uno Rev3, quelle valeur reçoit « int resultat = 5 / 2; » ?**

- **A. 2.5** : Une division entre deux entiers supprime la partie fractionnaire.
- **B. 3** : La division entière C++ tronque vers zéro : ce n'est pas un arrondi au plus proche.
- **C. 2** : 5 / 2 entre entiers vaut 2.
- **D. 0** : Le résultat n'est pas zéro.

**Objectif évalué :** Identifier une division entière.

## Q06 — Bonne réponse A

**On définit tensionV = 245.0f et seuil fictif = 240.0f. Quelle branche est exécutée par « if (tensionV > seuil) ... else ... » ?**

- **A. La branche if.** : 245 est supérieur à 240, donc la condition est vraie et la branche if s'exécute.
- **B. Toujours la branche else.** : else s'exécute si la condition if est fausse.
- **C. Aucune branche.** : Une condition if/else valide exécute l'une des branches.
- **D. Les deux branches.** : if/else choisit une branche, pas les deux.

**Objectif évalué :** Comprendre if/else.

## Q07 — Bonne réponse C

**Que va afficher « for (int i = 1; i <= 3; i++) Serial.println(i); » ?**

- **A. 0, 1, 2** : L'initialisation commence à 1, et non 0.
- **B. 1, 2** : La condition i <= 3 autorise aussi la valeur 3.
- **C. 1, 2, 3** : La boucle affiche 1, puis 2, puis 3.
- **D. 3 seulement** : Elle n'affiche pas uniquement la dernière valeur.

**Objectif évalué :** Lire une boucle for.

## Q08 — Bonne réponse D

**Comment assurer l'arrêt de « int essais = 0; while (essais < 3) { ... } » ?**

- **A. Retirer les accolades.** : Les accolades regroupent le corps de la boucle.
- **B. Ne jamais modifier essais.** : La condition resterait toujours vraie si essais restait 0.
- **C. Mettre une instruction delay(1000) sans changement de condition.** : Attendre 1 seconde ne modifie pas automatiquement essais.
- **D. Augmenter essais dans la boucle pour que la condition devienne fausse.** : Avec essais++ à chaque itération, la boucle se termine lorsque essais vaut 3.

**Objectif évalué :** Éviter les boucles infinies.

## Q09 — Bonne réponse B

**Que renvoie la fonction « float wattsVersKilowatts(float w) { return w / 1000.0f; } » si elle reçoit 1250.0f ?**

- **A. 1250.0** : Il faut diviser par 1 000 pour convertir les watts en kilowatts.
- **B. 1.25** : 1250 / 1000 = 1.25 kW.
- **C. 0.125** : 0.125 serait obtenu par une division par 10 000.
- **D. 125.0** : 125 ne correspond pas à cette division.

**Objectif évalué :** Lire une fonction et son résultat.

## Q10 — Bonne réponse D

**Pour une puissance active constante de 200 W pendant 5 heures, quelle valeur affiche le calcul « (200.0f / 1000.0f) * 5.0f » ?**

- **A. 1000.0 kWh** : Il faut diviser 200 W par 1000 avant de multiplier par 5 h.
- **B. 0.2 kWh** : 0.2 représente ici la puissance en kW, pas l'énergie totale.
- **C. 5.0 kWh** : 5 h est une durée et non l'énergie.
- **D. 1.0 kWh** : 200/1000 = 0.2 kW, puis 0.2 × 5 h = 1 kWh.

**Objectif évalué :** Calculer une énergie et vérifier les unités.

## Validation

- **8/10 minimum** pour valider les acquis.
- Reprendre les questions de calcul, de typage et de boucle si la logique n'est pas comprise.
- Le quiz doit être testé dans AlexTech Academy avant son déploiement, ce document n'est pas une intégration déjà réalisée.
