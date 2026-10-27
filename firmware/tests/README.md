# Vérifications du fil rouge

## Tests de régression disponibles

1. **Statique** : `python3 firmware/tests/test_progression.py`. Vérifie l'existence des quatre versions, les nouvelles capacités à chaque étape, le maintien de l'UART et du bouton, le mode sans secteur par défaut et l'identité du snapshot M08 avec le firmware courant.
2. **Algorithme énergie** : `g++ -std=c++11 -Wall -Wextra -pedantic firmware/tests/test_m08.cpp -o /tmp/test_m08 && /tmp/test_m08`. Copie des assertions de M08 : delta d'énergie, date, changement de mois, reprise RAM fictive, doublons et index descendu.
3. **Arduino Uno (à valider)** : les quatre projets doivent être compilés avec le cœur `arduino:avr:uno`. On peut les compiler par Arduino IDE 2 ou Arduino CLI.

```bash
arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M05/Compteur_M05
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M06/Compteur_M06
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M07/Compteur_M07
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M08/Compteur_M08
arduino-cli compile --fqbn arduino:avr:uno firmware/courant/CompteurIntelligent
```

**Important :** les cinq commandes ci-dessus concernent le mode simulé (options matérielles = 0) et ne nécessitent pas les bibliothèques PZEM/RTC/LCD. Les versions avec matériel actif devront être compilées et testées **séparément** après installation des bibliothèques et câblage autorisé.

## Tests manuels sur une vraie Uno USB

| Action | Résultat attendu |
|---|---|
| Envoyer `1`, puis `0`, puis `?` | LED ON, LED OFF, aide |
| Brancher bouton entre D2 et GND hors USB et appuyer cinq fois | Cinq bascules après validation anti-rebond |
| Laisser passer 2 secondes | Affichage de la tension simulée (M05) ou des six mesures (M06–M08) |
| En M07, mode matériel à 0 | Aucun LCD requis ; console encore disponible |
| En M08, mode simulé | Date explicitement fictive, index Wh, jour/mois marqués partiels |
| En M08, vraie RTC+LCD si matériel vérifié | Date RTC, tension et cumuls en quatre lignes ; `~` indique partiel |

Écrire les résultats réels dans les fiches de tests de chaque module. Ne pas marquer les essais Arduino comme réussis sans exécution.
