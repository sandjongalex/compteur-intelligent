# Première relecture du chapitre 5 — Contrôle interne

**Date :** 28 octobre 2026.  
**Périmètre :** chapitre 5, annexe E, registre des illustrations et concordance avec les scripts/firmware M05.  
**Destination :** document de production interne, exclu du livre destiné aux lecteurs.  
**Statut :** première relecture documentaire ; essais réels, figures définitives et validation de l'auteur à effectuer.

## 1. Alignement avec les deux leçons du programme M05

| Vidéo | Contenu couvert dans le chapitre |
|---|---|
| **M05-V01 — Bouton, LED, anti-rebond** | Entrées/sorties, D2-GND, INPUT_PULLUP, LOW=appui, état maintenu vs événement, rebonds, temporisation 35 ms non bloquante |
| **M05-V02 — UART et millis()** | TX/RX, USB Uno et UART matérielle D0/D1, Serial.available/read/print, commandes 1/0/?, 9 600 bauds, différences delay/millis, tâche fictive périodique |

Les exemples progressifs sont expliqués avant le programme complet, afin que le lecteur n'ait pas à mémoriser un long listing d'emblée.

## 2. Continuité du compteur et différence de comportement réelle

**Sources internes de comparaison :**

- \`firmware/etapes/M04/Compteur_M04/Compteur_M04.ino\`
- \`firmware/etapes/M05/Compteur_M05/Compteur_M05.ino\`
- \`formation/modules/M05-entrees-sorties-uart/code/V02_03_millis_et_uart/V02_03_millis_et_uart.ino\`

### Évolutions confirmées

1. La LED du chapitre 4 **ne clignote plus automatiquement** : elle est désormais commandée par un bouton et par des caractères UART. Ce changement est **une évolution fonctionnelle volontaire** et décrite comme telle.
2. Le programme intégré M05 utilise le bouton D2–GND avec **INPUT_PULLUP**, stabilisation **35 ms** et une bascule par nouvel appui stable.
3. Le programme intégré utilise **l'UART matérielle USB**, 9 600 bauds, commandes \`'1'\`, \`'0'\`, \`'?'\`.
4. Le programme intégré affiche \`Tension SIMULEE : 230.5 V\` toutes les **2 000 ms environ** ; l'exercice UART V02-03 l'affiche toutes les **1 000 ms environ**. Le texte distingue explicitement ces valeurs.
5. \`millis()\` et une différence temporelle non signée remplacent les longues attentes de \`delay()\`.

### Point de vigilance P1 — Calcul énergétique non conservé dans la version intégrée M05

Le programme M04 comportait \`calculerEnergieKWh()\` et \`afficherCalcul()\`. **Le snapshot intégré M05 ne contient plus ces deux fonctions.** Cette disparition n'est pas justifiée explicitement dans la documentation du programme intégré M05, même si le chapitre M05 se concentre sur les entrées/sorties.

**Action technique recommandée avant une validation globale de la continuité du firmware :** choisir et documenter une solution :
- **Option privilégiée :** réintégrer le calcul théorique M04 dans le programme cumulatif M05, avec fréquence d'affichage maîtrisée, sans bloquer les tâches, puis reporter cette correction dans les snapshots suivants et les tests ;
- ou documenter explicitement une suspension temporaire de cette fonction, avec son critère et son point de réintégration dans M06–M08.

**Aucune modification du firmware n'a été faite au titre de la rédaction de ce chapitre.** Dans le manuscrit, les fonctions absentes ne sont pas décrites comme actives.

## 3. Relecture technique et sécurité

| Vérification | Résultat documentaire |
|---|---|
| Bouton entre D2 et GND, aucune résistance pull-up externe nécessaire | Conforme pour l'exercice Uno |
| Bouton à quatre broches : repérage contacts hors tension | Mention explicite |
| Lecture \`INPUT_PULLUP\` : LOW = appuyé | Conforme |
| Front stable validé au bout d'environ 35 ms | Conforme à l'exemple et au firmware |
| \`Serial.available()>0\` avant \`Serial.read()\` | Explications correctes |
| Port matériel D0/D1 utilisé en USB, futur dédié SIM800L | Distinction claire |
| Caractères \`'1'\`, \`'0'\`, \`'?'\` vs entiers | Expliqué |
| \`millis()\` : soustraction des temps non signés | Contexte et limites explicités |
| \`millis()\` n'est pas une horloge temps réel DS3231 | Expliqué |
| PZEM et secteur 230 V absents de toute manipulation débutant | Conforme |
| Tension 230,5 V | Toujours présentée comme **fictive** |
| Réussite des démonstrations physiques | **Non affirmée ; reste à vérifier** |

## 4. Exercices et corrigés

- TP 1 : simulation de deux pages (0/1), cinq appuis distincts, bascule après anti-rebond.
- TP 2 : période à **500 ms**, commandes UART toujours opérationnelles.
- Défi facultatif : conséquences de \`delay(5000)\`.
- Quiz : dix questions avec une grille de correction à vérifier contre les énoncés du manuscrit.

## 5. Illustrations requises

**Neuf figures à produire :** 5.1 schéma bouton, 5.2 état INPUT_PULLUP, 5.3 niveau vs événement, 5.4 rebond, 5.5 validation 35 ms, 5.6 UART, 5.7 moniteur série, 5.8 delay/millis et 5.9 architecture M05.

Chaque figure comporte un commentaire de production avec type, contenu attendu, légende, texte alternatif et sécurité, ainsi qu'un repère visible dans le brouillon. Le registre est \`livre/ILLUSTRATIONS_A_PRODUIRE.md\`.

**Statut : 9/9 À PRODUIRE ; 0 illustration finale validée.**

## 6. Vérifications avant publication

- [ ] Compiler les petits sketches et le programme intégré sur une vraie Arduino Uno Rev3.
- [ ] Valider cinq appuis distincts sur le bouton et observer une seule bascule par appui.
- [ ] Vérifier le débit 9 600 bauds et les commandes \`1\`, \`0\`, \`?\`.
- [ ] Distinguer dans le support tourné les périodes **1 000 ms** et **2 000 ms**.
- [ ] Effectuer les essais de changement de période à 500 ms et mesurer la réactivité.
- [ ] Résoudre ou tracer le point de continuité énergétique identifié en section 2.
- [ ] Produire, revoir et autoriser les neuf figures.
- [ ] Éliminer les marqueurs « ILLUSTRATION À INSÉRER » des exports commerciaux.
- [ ] Faire vérifier le chapitre par un débutant et obtenir l'accord éditorial de l'auteur.

**Conclusion :** chapitre rédigé, première relecture documentaire réalisée ; aucun essai matériel, compilation ou mesure secteur n'est déclaré avoir été exécuté.
