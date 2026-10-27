# M02 — Fiches pédagogiques des composants

Ces descriptions servent à identifier et comprendre chaque élément, **sans constituer des instructions de raccordement secteur**.

| Composant | En langage simple | Points à retenir / erreur courante |
|---|---|---|
| **ATmega328P** | Petit ordinateur intégré à programmer | Le firmware s'exécute ici ; la carte Arduino Uno facilite l'apprentissage et la programmation |
| **PZEM-004T V3.0** | Module spécialisé dans les mesures électriques | Ne remplace pas l'ATmega ; vérifier la version et sa documentation |
| **DS3231** | Horloge avec maintien de l'heure | Il donne une date ; il n'est pas une mémoire des consommations |
| **FRAM** | Mémoire réinscriptible conservant les données hors tension | La FRAM mémorise des valeurs, mais ne sait pas seule quelle heure il est |
| **LCD I2C 20×4** | Écran affichant des caractères sur quatre lignes | Affichage local, distinct de l'application web |
| **SIM800L** | Modem pour envoyer des données sur réseau mobile 2G compatible | VBAT du modem nu ≠ 5 V ; vérifier l'alimentation et les niveaux UART |
| **LED** | Voyant lumineux | Nécessite une limitation de courant adaptée |
| **Buzzer** | Émet un signal sonore | Son alimentation ou commande dépend de sa référence |
| **Bouton** | Permet une interaction avec l'utilisateur | Entrées à polariser correctement et anti-rebond possible |
| **Quartz** | Référence de fréquence pour le microcontrôleur | Notre configuration pédagogique utilise 16 MHz |
| **Résistance** | Freine ou ajuste les courants et potentiels | Expliquer les valeurs en ohms et le rôle des résistances |
| **Condensateur** | Peut stocker temporairement de l'énergie électrique | Utilisé ici pour découplage, filtrage ou réserve transitoire |

## Démonstration pour M02-V01

1. Installer les composants sur un plan de travail, **sans câble secteur**.
2. Prendre un gros plan du marquage de chaque module.
3. Faire apparaître son nom puis une seule phrase sur son rôle.
4. Terminer par un exercice d'association composant/fonction.

## Précision technique

- Le bus I2C, la communication UART et les registres seront enseignés dans des modules ultérieurs.
- Ne pas prendre un nom générique de carte SIM800L, FRAM, LCD ou PZEM pour une garantie de brochage identique sur tous les modèles.
