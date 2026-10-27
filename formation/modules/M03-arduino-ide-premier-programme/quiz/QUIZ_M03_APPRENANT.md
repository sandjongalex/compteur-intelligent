# Quiz M03 — Apprenant

**10 QCM**, une seule bonne réponse par question. **Validation : 8/10 minimum.**

## Q01 — À quoi sert principalement Arduino IDE ?

*Facile · Reconnaître le logiciel*

A. Calculer des factures d'énergie
B. Écrire, vérifier et téléverser des sketches
C. Alimenter la LED sans carte
D. Remplacer le microcontrôleur

## Q02 — Quelle carte utilisons-nous pour les démonstrations du Module 03 ?

*Facile · Identifier le matériel du cours*

A. Arduino Mega
B. ESP32
C. Raspberry Pi
D. Arduino Uno Rev3

## Q03 — Avant le téléversement, quel réglage faut-il vérifier avec la carte ?

*Facile · Choisir le port*

A. La carte sélectionnée et son port USB série
B. La couleur de l'éditeur
C. Le navigateur par défaut
D. La date de création du fichier

## Q04 — Quelle fonction d'un sketch Arduino s'exécute de façon répétée après setup() ?

*Facile · Distinguer setup et loop*

A. install()
B. compile()
C. loop()
D. resetBoard()

## Q05 — Que fait le bouton Vérifier (✓) dans Arduino IDE 2 ?

*Intermédiaire · Comprendre Vérifier*

A. Il charge toujours le sketch sur la carte
B. Il contrôle et compile le sketch sans devoir le téléverser
C. Il déclenche le modem GSM
D. Il mesure le courant de la LED

## Q06 — Quel problème peut arrêter une compilation, même sans carte connectée ?

*Intermédiaire · Comprendre les erreurs de syntaxe*

A. Une accolade manquante dans le code
B. Une LED externe inversée
C. Une prise GND libre
D. L'absence de résistor connecté à D8

## Q07 — Le programme compile sans erreur, mais ne peut pas être envoyé sur la Uno. Que vérifier en priorité ?

*Intermédiaire · Comprendre la différence compilation/téléversement*

A. Le nombre de prises du tableau électrique
B. Le facteur de puissance
C. La valeur kWh du PZEM
D. Le câble USB de données, la carte et le port sélectionnés

## Q08 — Pourquoi le sketch minimal de V01 ne fait-il rien de visible après un téléversement réussi ?

*Intermédiaire · Différencier les programmes*

A. Parce que tous les téléversements échouent sans LED externe
B. Parce que loop() est interdite
C. Parce que setup() et loop() sont volontairement vides
D. Parce que la carte doit être reliée au 230 V

## Q09 — Dans le montage LED externe sur D8, pourquoi utilise-t-on une résistance en série ?

*Difficile · Comprendre l'utilité de la résistance*

A. Pour convertir l'USB en GSM
B. Pour limiter le courant et protéger la LED et la sortie
C. Pour empêcher toute compilation
D. Pour transformer la carte en PZEM

## Q10 — Une LED externe reliée correctement sur D8 doit rester allumée 250 ms puis éteinte 750 ms. Quelle modification est la bonne ?

*Difficile · Diagnostiquer la cadence et la sécurité*

A. Utiliser delay(250) après HIGH, puis delay(750) après LOW
B. Supprimer la résistance
C. Connecter D8 à la phase 230 V
D. Laisser delay(1000) après chaque état

Ne consultez le corrigé qu'après votre première tentative. Les questions relatives à la sécurité basse tension doivent être comprises avant de refaire le montage.
