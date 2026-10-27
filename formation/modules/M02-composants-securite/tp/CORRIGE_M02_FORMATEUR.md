# M02 — Corrigés et barèmes pour le formateur

## Correction TP 01

| Composant | Fonction attendue |
|---|---|
| ATmega328P | Exécuter le programme et traiter les relevés |
| PZEM-004T | Fournir les grandeurs électriques mesurées |
| DS3231 | Fournir la date et l'heure |
| LCD I2C 20×4 | Afficher des données sur quatre lignes |
| FRAM | Conserver des enregistrements sans alimentation |
| SIM800L | Transmettre les relevés en GSM/GPRS |
| LED | Afficher un état visuel |
| Bouton | Commander une action utilisateur |
| Buzzer | Émettre un signal sonore |

Le **SIM800L** communique, le **DS3231** indique la date, la **FRAM** conserve des valeurs.

**Barème TP 01 :** neuf associations à 1 point (9) + explication du besoin de vérifier les variantes exactes (1) = 10.

## Correction TP 02

- **A** : le VBAT du SIM800L nu ne doit pas recevoir directement 5 V. Documenter une alimentation régulée autour de 4,0 V, avec capacité de fournir les pointes de courant du modem, sans procéder à l'essai avant validation.
- **B** : la breadboard n'est pas conçue pour manipuler le secteur. Aucun essai novice ; validation de la partie secteur uniquement par une personne qualifiée avec protections adaptées.
- **C** : vérifier les niveaux UART et prévoir l'adaptation logique nécessaire ; ne pas supposer que 5 V convient aux entrées du modem nu.
- **Exercice autorisé** : faire clignoter une LED depuis une Arduino Uno alimentée de façon adaptée en basse tension.

**Barème TP 02 :** pour chaque scénario A à C, identification du risque 1 point et correction sûre 2 points (9) ; choix du TP basse tension correct (1).

## Réussite

L'apprenant vise **8/10** dans chaque TP. **Toute erreur de sécurité majeure doit être corrigée**, même si le score est bon. Proposer une reformulation orale et vérifier qu'il ne reproduit pas les scénarios dangereux.

**Important :** les indications décrivent les principes du montage, non un schéma détaillé de branchement 230 V.
