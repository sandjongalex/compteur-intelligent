# Journal de progression du firmware fil rouge

**Règle obligatoire :** [REGLE_EVOLUTION_CONTINUE.md](../docs/formation/REGLE_EVOLUTION_CONTINUE.md). Toute nouvelle étape firmware met à jour le [manifeste](manifest.json), les snapshots, le courant et ses tests.

Le but est de montrer **pourquoi et où le programme grandit**, plutôt que d'empiler des sketches sans liens.

| Passage | Code conservé | Nouveauté à expliquer à l'apprenant | Test concret |
|---|---|---|---|
| M03 → M04 | LED intégrée, `setup()` et `loop()` | Variables typées, fonction `commanderLED()`, calcul fictif de kWh et affichage série | La LED continue à clignoter ; 500 W × 2 h donne 1,000 kWh fictif |
| M04 → M05 | LED intégrée, organisation en fonctions et console série | Le voyant passe du clignotement automatique à la commande par bouton/UART, `millis()` remplace les `delay()` bloquants | Bouton et commandes `1/0/?` ; sortie périodique |
| M05 → M06 | LED, bouton avec anti-rebond, `Serial.read`, timer `millis()` | Fonction `lireMesures(Mesures &m)`, six grandeurs et contrôle de validité | `1` et `0` fonctionnent toujours ; les six grandeurs s'affichent |
| M06 → M07 | Toutes les commandes et les six grandeurs | `Wire`, `RTC_DS3231`, `hd44780_I2Cexp`, date fiable et quatre lignes | Console inchangée ; écran optionnel et « JOUR/MOIS NON CALCULE » |
| M07 → M08 | Bouton, LED, UART, source de mesure, RTC/LCD optionnels | Index Wh, relevé horodaté, deltas, date changeante, doublons, `~` pour partiel | Jour/mois cohérents avec date et index simulés, pas de faux total complet |
| M08 → M09 | Bouton, LED, UART, six mesures, date/RTC, écran LCD, cumuls et alertes inchangés | `ALEXTECH_ATMEGA_AUTONOME`, profil 16 MHz, diagnostic broches DIP28, câblage ISP pour exécuter le même code sur puce autonome | Compiler snapshot et courant ; mêmes commandes série et cumuls en simulation ; tester ISP sur cible physique séparément |
| M09 → M10 (à réaliser) | Firmware autonome | Modem GSM/GPRS et machine à états AT | Envoi simulé puis validé sans bloquer les mesures |
| M10 → M11 (à réaliser) | Acquisition, calendrier et modem | Sauvegarde en FRAM avec écriture sûre, reprise et renvoi idempotent | Vérification d'une vraie coupure sans perte ni double comptage |

## Règles pour les modules suivants

1. **Ne pas effacer les fonctionnalités précédentes** sans raison, test et documentation explicites ; une transformation intentionnelle (clignotement automatique M04 → commande M05) doit être expliquée.
2. Créer une nouvelle version dans `firmware/etapes/Mxx/` à la clôture d'un module.
3. Faire évoluer `firmware/courant/CompteurIntelligent/` sur la **même révision**.
4. Ne pas modifier rétroactivement les snapshots validés des modules antérieurs.
5. Actualiser cette matrice, les tests et les liens vers les scripts pédagogiques.
6. Préserver un mode **simulation sans secteur** par défaut.
7. Chaque nouvelle fonction doit être introduite d'abord dans un **petit sketch pédagogique**, puis dans le firmware fil rouge.

## Ce qui manque encore

Les sketches et scripts des modules M03–M08 étaient déjà produits séparément. La **continuité M03–M08 est maintenant matérialisée en code**, mais l'API d'acquisition brute précise du PZEM, la certification des comportements sur une Uno réelle, la persistance FRAM et l'envoi GSM sont encore hors périmètre de la présente phase.

## Correctifs de fiabilité M09 (P1/P2, avant M10)

Maintenance corrective de la **dernière étape M09 non encore validée sur matériel** :
- source simulée 92,2 W : index Wh calculé en entier et testé sur rollover de `millis()` ;
- origine explicite de l'heure (DS3231 / simulation / indisponible), impossibilité de
  compiler le PZEM réel sans activer une RTC réelle ;
- passages de minuit et de mois : aucun découpage fictif d'un delta entre jours ;
  période marquée PARTIELLE si la base exacte de minuit manque ;
- calcul défensif contre les cumuls `uint32_t` saturés et les index réinitialisés ;
- vérifications de compilation des branches réelles PZEM/RTC/LCD et des modes
  simulateur ; `test_m09.cpp` et `test_m09_safety.py` ajoutés.

**Exception tracée :** le correctif synchronise le snapshot M09 et le firmware courant
parce que M09 était encore non validé physiquement, sans toucher à M03–M08.
Si des copies de M09 antérieures sont distribuées, fournir cet erratum.

**UART :** ne pas attribuer `Serial` au GSM dans M09 ; la migration de la console vers
le pilote SIM800L sur D0/D1 a lieu en M10, comme établi dans les règles permanentes.
