# M04-V02 — Script intégral : Conditions, boucles et fonctions

**Durée cible : 7 minutes** · **Public : débutant ayant suivi M04-V01** · **Support : Arduino IDE 2 + moniteur série**.
**Statut : texte intégral rédigé, à chronométrer avant tournage.** Les notes [ÉCRAN] ne sont pas prononcées.

## 00:00–00:55 — Un programme qui réagit

[ÉCRAN : jauge « tension fictive 245 V », étiquette « alerte ? ».]

« Dans le cours précédent, nous avons appris à conserver des valeurs et à effectuer des calculs. Mais un compteur intelligent ne doit pas seulement calculer. Il doit parfois décider, répéter certaines opérations et réutiliser le même calcul à plusieurs endroits.

Prenons une tension fictive. Si elle dépasse une limite choisie pour notre exercice, nous voulons afficher un message d'avertissement sur le moniteur série. Pour cela, nous allons utiliser une condition.

Nous allons aussi rencontrer les boucles for et while, puis écrire une fonction capable de convertir automatiquement des watts en kilowatts. »

## 00:55–02:20 — Décider avec if et else

[ÉCRAN : `if (tensionV > 240.0f) { ... } else { ... }`.]

« Une condition permet d'exécuter une partie du code seulement si une expression est vraie. Dans notre exemple, nous avons float tensionV égale deux cent quarante-cinq. Nous écrivons if, puis entre parenthèses : tensionV supérieur à deux cent quarante.

Si cette expression est vraie, le programme affiche le texte Alerte : tension fictive élevée. Sinon, grâce au mot else, il affiche Tension fictive dans la plage de l'exercice.

Attention : nous utilisons une limite fictive pour apprendre la syntaxe. Ce n'est pas une consigne de sécurité ni un seuil réglementaire destiné à protéger une installation électrique.

Il faut aussi distinguer deux symboles. Un seul signe égal sert à affecter une valeur à une variable. Deux signes égal servent à comparer deux valeurs. Dans une condition, utiliser le mauvais signe peut provoquer un comportement inattendu. »

## 02:20–03:25 — Répéter avec for

[ÉCRAN : `for (int i = 1; i <= 3; i++) { Serial.println(i); }`.]

« Maintenant, imaginons que nous voulions afficher trois relevés numérotés. Nous pourrions écrire trois fois la même instruction, mais ce serait répétitif.

Une boucle for est plus pratique. Nous créons un entier i qui commence à un. Tant que i est inférieur ou égal à trois, la boucle exécute ses instructions. À chaque passage, i augmente de un.

Nous voyons alors apparaître un, deux, trois sur le moniteur série.

Utilisez for lorsque vous connaissez le nombre de répétitions à effectuer, par exemple pour parcourir quelques mesures déjà enregistrées. Nous étudierons plus tard les limites de la mémoire et les tableaux. »

## 03:25–04:20 — Répéter avec while

[ÉCRAN : `int essais = 0; while (essais < 3) { essais++; }` ; jauge 0 → 3.]

« Une autre boucle s'appelle while. Elle répète des instructions tant qu'une condition reste vraie. Par exemple, tant que le nombre d'essais est inférieur à trois, nous ajoutons un à cette valeur.

Il faut absolument modifier ce qui permet à la condition de devenir fausse. Si le nombre d'essais ne change jamais, la boucle peut tourner sans fin et bloquer le reste du programme.

Sur un microcontrôleur, ce comportement peut être gênant, surtout lorsqu'il faut continuer à surveiller les mesures ou communiquer. Pour notre démonstration, le nombre d'itérations reste limité. »

## 04:20–05:45 — Créer une fonction réutilisable

[ÉCRAN : `float wattsVersKilowatts(float watts) { return watts / 1000.0f; }`.]

« Passons à une fonction. Une fonction est une partie de code que l'on nomme pour pouvoir l'appeler quand on en a besoin.

Nous allons écrire une fonction appelée wattsVersKilowatts. Entre ses parenthèses, nous indiquons un paramètre nommé watts. C'est la valeur que nous lui fournirons. Devant le nom de la fonction, nous écrivons float, car elle renverra un nombre décimal.

À l'intérieur des accolades, nous écrivons return watts divisé par mille point zéro. Le mot return renvoie le résultat.

Pour utiliser cette fonction, il suffit d'écrire wattsVersKilowatts, puis cinq cents entre parenthèses. Le résultat est zéro virgule cinq.

Cette approche est utile dans notre compteur. Au lieu de recopier le même calcul, nous pouvons l'effectuer en un seul endroit. Et lorsqu'une correction est nécessaire, nous modifions une seule fonction. »

## 05:45–07:00 — Exercice et synthèse

[ÉCRAN : consigne « 1 250 W → combien de kW ? ».]

« Voici votre exercice. Modifiez la fonction et appelez-la avec une puissance fictive de mille deux cent cinquante watts. Quel résultat doit apparaître ?

Mettez la vidéo en pause et réfléchissez. Mille deux cent cinquante divisés par mille donnent un virgule deux cinq kilowatt.

Vous pouvez ensuite modifier notre exemple de condition : essayez une tension fictive de deux cent trente volts au lieu de deux cent quarante-cinq. Vous devrez voir le message indiquant que la tension est dans la plage de l'exercice.

Retenez les trois outils du jour. if et else permettent de décider. Les boucles for et while répètent des opérations. Les fonctions regroupent du code réutilisable avec des paramètres et, si nécessaire, une valeur de retour.

Notre compteur est encore simulé, mais nous disposons maintenant des principales constructions du programme. Dans le module suivant, nous allons les appliquer aux entrées et sorties et aux communications série pour dialoguer avec nos futurs périphériques. »

## Note au formateur

- **245 V** et **240 V** sont des nombres purement pédagogiques ; ne pas les présenter comme des limites de sécurité.
- Le code de démonstration doit produire une sortie limitée, sans boucle `while` bloquante infinie.
- Ne jamais confondre `=` et `==`.
- S'assurer que les impressions de nombres utilisent `Serial.begin(9600)` et le moniteur réglé à **9600 bauds**.
- Chronométrer et vérifier sur une Uno Rev3 réelle avant tournage.
