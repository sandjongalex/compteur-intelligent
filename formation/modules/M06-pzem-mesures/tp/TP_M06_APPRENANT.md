# M06 — Travaux pratiques (apprenant, sans solutions)

**30 à 45 min hors vidéo.** Une Arduino Uno Rev3 et son câble USB suffisent. **Aucun PZEM et aucun raccordement secteur ne sont nécessaires.**

## TP01 : convertir les registres fictifs

Départ : [V01-02 · registres décodés](../code/V01_02_registres_decodes/V01_02_registres_decodes.ino).

1. Lire le tableau de 10 registres et identifier les six grandeurs mesurées.
2. Modifier les valeurs brutes : tension **2312** ; courant bas **750**, haut **0** ; puissance bas **1388**, haut **0** ; énergie bas **15300**, haut **0** ; fréquence **501** ; facteur de puissance **80**.
3. Prévoir les résultats en V, A, W, kWh, Hz et facteur de puissance avant de téléverser.
4. Compiler, téléverser sur Uno, ouvrir le moniteur série à 9600 bauds.
5. Expliquer le rôle des mots haut/bas et pourquoi l'énergie est un index cumulatif.

**Livrable :** sketch modifié et tableau de six conversions accompagnées des unités.

## TP02 : ne pas inventer de mesures lors d'une panne

Départ : [V02-02 · panne simulée](../code/V02_02_detection_panne_simulee/V02_02_detection_panne_simulee.ino).

1. Prédire le résultat des trois premières tentatives : succès, échec, succès.
2. Vérifier que l'échec n'affiche ni une mesure égale à zéro inventée, ni une ancienne mesure comme nouvelle.
3. Modifier le texte d'erreur en « CAPTEUR INDISPONIBLE - PAS DE NOUVEAU RELEVE ».
4. Ajouter un compteur d'échecs et l'afficher lors des lectures invalides.
5. Vérifier à nouveau le programme sur la Uno et expliquer la différence entre **0 W valide** et **lecture indisponible**.

**Livrable :** sketch corrigé et exemples de messages du moniteur.

## Mini-défi facultatif

Pourquoi faut-il éviter `pzem.resetEnergy()` lorsque le jour change ? Réfléchir au rôle des index cumulés et de leur différence entre deux dates.

**Critères :** conversions comprises, aucune valeur fabriquée lors d'un échec, explications reproductibles. [Corrigés réservés au formateur](CORRIGE_M06_FORMATEUR.md).
