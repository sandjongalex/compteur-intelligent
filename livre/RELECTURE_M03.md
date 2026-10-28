# Première relecture du chapitre 3 — Rapport interne

**Date :** 28 octobre 2026.  
**Périmètre :** chapitre 3, annexe C, correspondance M03-V01/V02 et code pédagogique existant.  
**Statut :** rédaction terminée, première relecture documentaire effectuée ; la relecture de mise en page, la validation finale de l'auteur et les essais physiques demeurent distincts.

> **Exclure ce document du livre vendu ou distribué.** Les sources de production, rapports, scripts vidéo et historiques de version n'appartiennent pas au livre autonome.

## 1. Concordance avec les deux vidéos M03

| Vidéo | Couverture éditoriale |
|---|---|
| **M03-V01 — Installer Arduino IDE et comprendre la compilation** | Arduino IDE 2, Uno Rev3, câble USB de données, sélection de la carte et du port, sketch minimal, \`setup()\`, \`loop()\`, comparaison Vérifier/Téléverser, erreur de syntaxe volontaire |
| **M03-V02 — Faire clignoter une LED avec Arduino Uno** | LED intégrée \`LED_BUILTIN\` sur Uno Rev3, \`pinMode()\`, \`digitalWrite()\`, \`delay()\`, changements de durées 1000/1000 puis 250/750 ms, LED externe D8 avec 330 Ω, dépannage et introduction à la limite des attentes bloquantes |

## 2. Vérification de la continuité du projet fil rouge

Le **programme 3.1**, qui utilise \`pinMode(LED_BUILTIN, OUTPUT)\`, puis \`digitalWrite\` et deux attentes de 1000 ms dans \`loop()\`, reflète la **première étape M03 du firmware cumulatif**.

Le sketch minimal (fonctions vides), le montage LED externe sur D8 et les modifications de cadence sont des **exercices d'apprentissage**. Ils ne remplacent pas silencieusement le firmware fil rouge : ils sont explicitement différenciés dans le chapitre.

**Transition M04 :** l'évolution conserve la fonction LED et introduit les bases C/C++ ; le futur compteur ne doit pas être reconstruit de zéro.

## 3. Contrôles techniques du contenu

| Sujet | Contrôle |
|---|---|
| \`setup()\` / \`loop()\` | Initialisation puis répétition correctement expliquées |
| Vérifier / Téléverser | Vérifier compile ; téléverser transfère à la carte réelle |
| Programmes C++ | Extraits conformes à la syntaxe courante des sketches Arduino et aux exemples de M03 |
| LED intégrée | Uno Rev3, LED « L » associée à D13/\`LED_BUILTIN\` |
| LED externe | D8 → résistance 330 Ω → anode → cathode → GND |
| Temporisations | 1000 ms = 1 s, 250 + 750 = 1000 ms ; mini-défi 500 + 1500 = 2000 ms |
| Sécurité | USB débranché avant toute modification du circuit externe ; aucune intervention 230 V |
| Dépannage | Compilation, téléversement et observation du comportement différenciés |
| Quiz | Dix questions présentes ; dix réponses expliquées dans l'annexe C |
| Diffusion | Aucun renvoi à GitHub ni à un état temporaire du dépôt dans les pages destinées au lecteur |

## 4. Réserves et vérifications restant à effectuer

- [ ] Compiler effectivement les exemples sur la version Arduino IDE utilisée pour filmer.
- [ ] Téléverser les deux sketches sur **une vraie Arduino Uno Rev3** et consigner les résultats matériels.
- [ ] Photographier les montages en basse tension pour la version imprimée.
- [ ] Vérifier la qualité de la mise en page et des blocs de code sur le format final.
- [ ] Faire relire les explications \`setup()\` / \`loop()\` à une personne novice.
- [ ] Faire valider le ton et les contenus du livre par l'auteur.

**Cette relecture porte sur les textes et leur conformité au programme ; elle ne constitue ni une compilation réalisée ni une validation de l'essai matériel.**

## 5. Références de production consultées

- [Présentation et objectifs M03](../formation/modules/M03-arduino-ide-premier-programme/README.md)
- [Scripts vidéo M03-V01](../formation/modules/M03-arduino-ide-premier-programme/scripts/V01-script.md) et [M03-V02](../formation/modules/M03-arduino-ide-premier-programme/scripts/V02-script.md)
- [Codes pédagogiques de M03](../formation/modules/M03-arduino-ide-premier-programme/code/README.md)
- [Snapshot cumulatif du firmware M03](../firmware/etapes/M03/Compteur_M03/Compteur_M03.ino)
- [Plan de formation](../docs/formation/PLAN_FORMATION_4H.md)

## Nouvelle règle de production graphique — ajoutée après retour de l'auteur

**Chapitre 3 : 10 illustrations pédagogiques nécessaires ont désormais été repérées à leur emplacement exact**, chacune avec un commentaire de production indiquant type, contenu, légende, texte alternatif, contraintes et statut **À PRODUIRE**. Les figures sont référencées dans le [registre des illustrations](ILLUSTRATIONS_A_PRODUIRE.md), qui est strictement interne.

- [x] Emplacements repérés et figures numérotées dans l'ordre.
- [x] Description pédagogique, légende et texte alternatif rédigés.
- [ ] Figures effectivement dessinées, photographiées ou capturées.
- [ ] Origine et droits commerciaux contrôlés.
- [ ] Lisibilité A4/PDF et validation technique et éditoriale obtenues.

**Conséquence :** le chapitre reste au statut *texte rédigé et première relecture documentaire effectuée*. Il n'est **pas bon à composer ni à publier** avant ces validations graphiques.
