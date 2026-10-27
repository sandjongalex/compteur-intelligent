# Quiz M03 — Corrigé formateur

**Grille :** Q01=B · Q02=D · Q03=A · Q04=C · Q05=B · Q06=A · Q07=D · Q08=C · Q09=B · Q10=A

## Q01 — Réponse B

**À quoi sert principalement Arduino IDE ?**

- **A. Calculer des factures d'énergie** — Arduino IDE n'est pas un logiciel de facturation.
- **B. Écrire, vérifier et téléverser des sketches** — L'IDE fournit l'éditeur, les outils de compilation et de téléversement.
- **C. Alimenter la LED sans carte** — Le logiciel n'alimente aucun composant à lui seul.
- **D. Remplacer le microcontrôleur** — Le code préparé est exécuté par le microcontrôleur, pas par le logiciel IDE seul.

## Q02 — Réponse D

**Quelle carte utilisons-nous pour les démonstrations du Module 03 ?**

- **A. Arduino Mega** — Une Mega a un microcontrôleur et des broches différents de la cible.
- **B. ESP32** — L'ESP32 n'est pas la carte du cours à ce stade.
- **C. Raspberry Pi** — Un Raspberry Pi est un autre type d'ordinateur.
- **D. Arduino Uno Rev3** — La Uno Rev3 est la carte retenue pour l'apprentissage de l'ATmega328P.

## Q03 — Réponse A

**Avant le téléversement, quel réglage faut-il vérifier avec la carte ?**

- **A. La carte sélectionnée et son port USB série** — La sélection de la bonne carte et du bon port est indispensable pour l'envoi.
- **B. La couleur de l'éditeur** — La couleur de l'interface n'affecte pas le téléversement.
- **C. Le navigateur par défaut** — Le navigateur n'envoie pas le sketch dans la Uno.
- **D. La date de création du fichier** — La date du fichier ne sélectionne pas le périphérique.

## Q04 — Réponse C

**Quelle fonction d'un sketch Arduino s'exécute de façon répétée après setup() ?**

- **A. install()** — Cette fonction n'est pas une fonction standard du sketch.
- **B. compile()** — Compiler est une étape de l'IDE, pas une fonction de sketch appelée automatiquement.
- **C. loop()** — loop() est rappelée continuellement tant que la carte fonctionne.
- **D. resetBoard()** — Ce n'est pas la fonction répétitive du programme Arduino.

## Q05 — Réponse B

**Que fait le bouton Vérifier (✓) dans Arduino IDE 2 ?**

- **A. Il charge toujours le sketch sur la carte** — Le bouton de téléversement réalise l'envoi du programme.
- **B. Il contrôle et compile le sketch sans devoir le téléverser** — Vérifier contrôle et compile, sans imposer un transfert vers la carte.
- **C. Il déclenche le modem GSM** — Le GSM ne fait pas partie du Module 03.
- **D. Il mesure le courant de la LED** — L'IDE n'est pas un ampèremètre.

## Q06 — Réponse A

**Quel problème peut arrêter une compilation, même sans carte connectée ?**

- **A. Une accolade manquante dans le code** — La syntaxe doit être correcte pour compiler : une accolade oubliée peut provoquer une erreur.
- **B. Une LED externe inversée** — Une LED inversée peut gêner le montage réel mais n'est pas une erreur de compilation.
- **C. Une prise GND libre** — Une broche GND libre n'est pas analysée par le compilateur.
- **D. L'absence de résistor connecté à D8** — L'IDE compile du code, sans inspecter physiquement la résistance.

## Q07 — Réponse D

**Le programme compile sans erreur, mais ne peut pas être envoyé sur la Uno. Que vérifier en priorité ?**

- **A. Le nombre de prises du tableau électrique** — Le tableau électrique n'a aucun rôle pour la liaison USB de test.
- **B. Le facteur de puissance** — Le facteur de puissance ne détermine pas la liaison USB.
- **C. La valeur kWh du PZEM** — Le PZEM n'est pas impliqué dans ce module.
- **D. Le câble USB de données, la carte et le port sélectionnés** — Le câble USB, la sélection de carte et de port sont les premières vérifications.

## Q08 — Réponse C

**Pourquoi le sketch minimal de V01 ne fait-il rien de visible après un téléversement réussi ?**

- **A. Parce que tous les téléversements échouent sans LED externe** — Le programme minimal peut se téléverser sans LED externe.
- **B. Parce que loop() est interdite** — loop() est une fonction normale et requise du sketch Arduino.
- **C. Parce que setup() et loop() sont volontairement vides** — Les deux fonctions vides ne commandent aucun voyant : c'est attendu.
- **D. Parce que la carte doit être reliée au 230 V** — L'Arduino fonctionne sur alimentation basse tension, pas sur le secteur direct.

## Q09 — Réponse B

**Dans le montage LED externe sur D8, pourquoi utilise-t-on une résistance en série ?**

- **A. Pour convertir l'USB en GSM** — Une résistance seule ne crée pas de liaison GSM.
- **B. Pour limiter le courant et protéger la LED et la sortie** — La résistance limite le courant dans la LED ; une valeur appropriée protège le montage.
- **C. Pour empêcher toute compilation** — La présence d'une résistance physique n'empêche pas de compiler.
- **D. Pour transformer la carte en PZEM** — Le PZEM est un module de mesure distinct.

## Q10 — Réponse A

**Une LED externe reliée correctement sur D8 doit rester allumée 250 ms puis éteinte 750 ms. Quelle modification est la bonne ?**

- **A. Utiliser delay(250) après HIGH, puis delay(750) après LOW** — La durée de HIGH est 250 ms, puis celle de LOW 750 ms.
- **B. Supprimer la résistance** — Supprimer la résistance risque d'endommager le circuit.
- **C. Connecter D8 à la phase 230 V** — Le secteur ne doit jamais être relié à une sortie numérique.
- **D. Laisser delay(1000) après chaque état** — Deux pauses de 1 000 ms donneraient 1 s allumée et 1 s éteinte.

## Validation

- Seuil : **8/10**.
- Toute confusion dangereuse sur le secteur ou la résistance de la LED doit être corrigée avant un nouveau TP.
- L'intégration à la plateforme AlexTech Academy reste à effectuer.
