# Journal de progression du firmware fil rouge

Le but est de montrer **pourquoi et où le programme grandit**, plutôt que d'empiler des sketches sans liens.

| Passage | Code conservé | Nouveauté à expliquer à l'apprenant | Test concret |
|---|---|---|---|
| M05 → M06 | LED, bouton avec anti-rebond, `Serial.read`, timer `millis()` | Fonction `lireMesures(Mesures &m)`, six grandeurs et contrôle de validité | `1` et `0` fonctionnent toujours ; les six grandeurs s'affichent |
| M06 → M07 | Toutes les commandes et les six grandeurs | `Wire`, `RTC_DS3231`, `hd44780_I2Cexp`, date fiable et quatre lignes | Console inchangée ; écran optionnel et « JOUR/MOIS NON CALCULE » |
| M07 → M08 | Bouton, LED, UART, source de mesure, RTC/LCD optionnels | Index Wh, relevé horodaté, deltas, date changeante, doublons, `~` pour partiel | Jour/mois cohérents avec date et index simulés, pas de faux total complet |
| M08 → M09 (à réaliser) | Tous les modules précédents | Compilation et programmation d'un ATmega328P autonome, mapping des broches, alimentation | Comparaison des fonctions avant/après migration |
| M09 → M10 (à réaliser) | Firmware autonome | Modem GSM/GPRS et machine à états AT | Envoi simulé puis validé sans bloquer les mesures |
| M10 → M11 (à réaliser) | Acquisition, calendrier et modem | Sauvegarde en FRAM avec écriture sûre, reprise et renvoi idempotent | Vérification d'une vraie coupure sans perte ni double comptage |

## Règles pour les modules suivants

1. **Ne pas effacer les fonctionnalités précédentes** sans raison, test et documentation explicites.
2. Créer une nouvelle version dans `firmware/etapes/Mxx/` à la clôture d'un module.
3. Faire évoluer `firmware/courant/CompteurIntelligent/` sur la **même révision**.
4. Ne pas modifier rétroactivement les snapshots validés des modules antérieurs.
5. Actualiser cette matrice, les tests et les liens vers les scripts pédagogiques.
6. Préserver un mode **simulation sans secteur** par défaut.
7. Chaque nouvelle fonction doit être introduite d'abord dans un **petit sketch pédagogique**, puis dans le firmware fil rouge.

## Ce qui manque encore

Les sketches et scripts des modules M03–M08 étaient déjà produits séparément. La **continuité M05–M08 est maintenant matérialisée en code**, mais l'API d'acquisition brute précise du PZEM, la certification des comportements sur une Uno réelle, la persistance FRAM et l'envoi GSM sont encore hors périmètre de la présente phase.
