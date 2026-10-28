# Relecture M04 — Contrôle technique, pédagogique et éditorial (interne)

**Date :** 28 octobre 2026.  
**Périmètre :** chapitre 4, annexe D, registre des illustrations et correspondance avec la formation M04.  
**Usage :** document de production uniquement, **exclu de l'ouvrage distribué**.

## Correspondance avec les vidéos

| Référence | Couverture du chapitre |
|---|---|
| **M04-V01 : Variables, types et calculs en C++** | \`int\`, \`float\`, \`bool\`, \`const\` ; limites AVR ; division entière ; formule énergie constante ; \`Serial.begin(9600)\` ; moniteur série |
| **M04-V02 : Conditions, boucles et fonctions** | \`if/else\`, différence \`=\` / \`==\`, \`for\`, \`while\` terminante, paramètres et \`return\`, fonction \`wattsVersKilowatts\` |

## Contrôle technique du programme principal

**Référence interne :** \`firmware/etapes/M04/Compteur_M04/Compteur_M04.ino\`. Le **programme 4.2** du manuscrit reproduit la logique cumulative de cette étape.

- [x] \`LED_BUILTIN\` reste configurée en sortie.
- [x] Le clignotement précédent est conservé grâce à \`commanderLED(true/false)\` et deux temporisations \`delay(1000)\`.
- [x] \`calculerEnergieKWh(float,float)\` implémente \`(W / 1000.0f) × h\`.
- [x] \`afficherCalcul()\` utilise des valeurs fictives et annonce explicitement la simulation.
- [x] \`Serial.begin(9600)\` et les messages série figurent dans \`setup()\`, sans perte de la LED.
- [x] L'usage pédagogique de la liaison série USB est distingué de la **liaison matérielle réservée au SIM800L à partir de M10**.
- [x] Le chapitre explique \`F()\` pour la mémoire programme AVR et l'opérateur ternaire \`?:\`, présents dans le firmware de référence.
- [x] Les limitations du \`float\` et de l'\`int\` sur ATmega328P sont formulées sans généralisation à d'autres microcontrôleurs.
- [x] Le seuil de 240 V est explicitement **fictif** et n'est pas proposé comme seuil de sécurité.

### Calculs vérifiés sur papier

| Valeurs fictives | Énergie théorique |
|---|---|
| 500 W × 2 h | 1,000 kWh |
| 200 W × 5 h | 1,000 kWh |
| 400 W × 2,5 h | 1,000 kWh |
| 1250 W / 1000 | 1,25 kW |

\`5 / 2 = 2\` pour des opérandes entiers ; \`5.0f / 2.0f = 2.5\` pour des opérandes flottants. La boucle \`for (int i=1; i<=3; i++)\` exécute son corps trois fois ; la boucle \`while\` bornée se termine si \`essais\` est incrémentée.

**Aucun essai de compilation Arduino IDE ni téléversement réel n'a été effectué pendant cette relecture.** Les sorties affichées dans le texte restent des **résultats attendus**, et non des captures de tests déjà réalisés.

## Illustrations obligatoires

Le chapitre comporte **8 repères visibles** et **8 commentaires détaillés de préparation** :

| Figure | Objet |
|---|---|
| 4.1 | Variable : nom, type et valeur |
| 4.2 | Taille et limites des types AVR |
| 4.3 | Division entière ou décimale |
| 4.4 | Capture du moniteur série à 9600 bauds |
| 4.5 | Organigramme if/else, = et == |
| 4.6 | Boucles for et while bornées |
| 4.7 | Paramètres de fonction et return |
| 4.8 | Continuité du firmware M03 vers M04 |

Les figures sont recensées dans \`livre/ILLUSTRATIONS_A_PRODUIRE.md\`. **Statut : 8 figures à produire, 0 validée**.

Pour la **figure 4.4**, une capture ne pourra être approuvée qu'après observation réelle sur Arduino IDE. Aucun résultat simulé ne doit être présenté comme une vraie photographie de test.

## Validation avant diffusion

- [ ] Produire et relire les huit illustrations.
- [ ] Vérifier licences / droits et textes alternatifs.
- [ ] Compiler réellement les sketches sur Uno Rev3 et vérifier les impressions série.
- [ ] Contrôler la mise en page, la numérotation et l'absence des repères « ILLUSTRATION À INSÉRER » dans le PDF.
- [ ] Soumettre la version illustrée à une lecture débutant et à la validation éditoriale de l'auteur.

**Statut actuel : chapitre rédigé et première relecture documentaire effectuée, non prêt à la publication.**

## Sources internes consultées

- \`formation/modules/M04-bases-cpp/README.md\` et scripts \`V01-script.md\` et \`V02-script.md\`.
- \`formation/modules/M04-bases-cpp/code/\` : exercices, programmes et corrigés.
- \`formation/modules/M04-bases-cpp/tp/\` et \`quiz/\`.
- \`firmware/etapes/M03/Compteur_M03/Compteur_M03.ino\` puis \`firmware/etapes/M04/Compteur_M04/Compteur_M04.ino\`.
- \`livre/PLAN_EDITORIAL.md\`, \`livre/PRODUCTION_INTERNE.md\` et \`livre/ILLUSTRATIONS_A_PRODUIRE.md\`.
