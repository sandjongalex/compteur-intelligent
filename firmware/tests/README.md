# Vérifications du fil rouge

**Critères de validation :** [contrat de progression continue](../../docs/formation/REGLE_EVOLUTION_CONTINUE.md).

## Tests de régression disponibles

1. **Contrat évolutif** : `python3 firmware/tests/test_contrat_evolution.py`. Vérifie le manifeste, les versions publiées, les fichiers sources du courant et du dernier snapshot et les liens du guide.
2. **Statique** : `python3 firmware/tests/test_progression.py`. Vérifie l'existence des six versions, les nouvelles capacités à chaque étape, le maintien de l'UART et du bouton, le mode sans secteur par défaut et l'identité du snapshot M08 avec le firmware courant.
3. **Algorithme énergie** : `g++ -std=c++11 -Wall -Wextra -pedantic firmware/tests/test_m08.cpp -o /tmp/test_m08 && /tmp/test_m08`. Copie des assertions de M08 : delta d'énergie, date, changement de mois, reprise RAM fictive, doublons et index descendu.
4. **Arduino Uno (à valider)** : les versions publiées doivent être compilés avec le cœur `arduino:avr:uno`. On peut les compiler par Arduino IDE 2 ou Arduino CLI.

```bash
arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M03/Compteur_M03
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M04/Compteur_M04
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M05/Compteur_M05
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M06/Compteur_M06
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M07/Compteur_M07
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M08/Compteur_M08
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M09/Compteur_M09
arduino-cli compile --fqbn arduino:avr:uno firmware/courant/CompteurIntelligent
```

**Important :** les commandes de compilation ci-dessus concernent le mode simulé (options matérielles = 0) et ne nécessitent pas les bibliothèques PZEM/RTC/LCD. Les versions avec matériel actif devront être compilées et testées **séparément** après installation des bibliothèques et câblage autorisé.

## Tests manuels sur une vraie Uno USB

| Action | Résultat attendu |
|---|---|
| M03 : téléverser le premier programme | La LED intégrée clignote toutes les ~1 s |
| M04 : téléverser le projet refactorisé | La LED clignote toujours ; calcul fictif **1,000 kWh** dans la console |
| M05+ : envoyer `1`, puis `0`, puis `?` | LED ON, LED OFF, aide |
| Brancher bouton entre D2 et GND hors USB et appuyer cinq fois | Cinq bascules après validation anti-rebond |
| Laisser passer 2 secondes | Affichage de la tension simulée (M05) ou des six mesures (M06–M08) |
| En M07, mode matériel à 0 | Aucun LCD requis ; console encore disponible |
| En M08, mode simulé | Date explicitement fictive, index Wh, jour/mois marqués partiels |
| En M08, vraie RTC+LCD si matériel vérifié | Date RTC, tension et cumuls en quatre lignes ; `~` indique partiel |

Écrire les résultats réels dans les fiches de tests de chaque module. Ne pas marquer les essais Arduino comme réussis sans exécution.


## Nouveau contrôle M09

La version `M09` du firmware est compilée pour Arduino Uno 16 MHz afin d'être ensuite programmée sur une puce ATmega328P autonome **avec le même brochage et une horloge/fuses réellement compatibles**. Le drapeau `ALEXTECH_ATMEGA_AUTONOME` vaut **0** dans les sources distribuées pour préserver la simulation sans matériel. Un essai sur cible autonome avec le drapeau à `1` doit être validé séparément ; la CI ne prouve pas le câblage, les fuses ni le succès ISP.

## Tests complémentaires de fiabilité M09

```bash
python3 firmware/tests/test_m09_safety.py
g++ -std=c++11 -Wall -Wextra -pedantic firmware/tests/test_m09.cpp -o /tmp/test_m09
/tmp/test_m09
```

Les tests valident notamment 92,2 Wh après 1 h à 92,2 W, le rebouclage de
`millis()`, la date simulée différente d'une RTC fiable, les ancrages
partiels à minuit et à la frontière de mois et la non-régression.
La CI installe `PZEM004Tv30@1.2.1`, `RTClib` et `hd44780`, puis compile
les variantes M09 RTC/LCD réels et PZEM+RTC/LCD réels sur Uno 16 MHz.
Elle confirme également qu'activer le PZEM réel sans RTC réel est refusé.

**Mesure CI (27/10/2026) :** mode PZEM+RTC+LCD = 19 456 octets Flash
et 918 octets de RAM statique, sans modem GSM. Cette occupation ne constitue
pas une preuve de marge de pile suffisante à l'exécution.
