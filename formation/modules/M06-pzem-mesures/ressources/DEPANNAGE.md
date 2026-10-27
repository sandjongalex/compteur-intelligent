# M06 — Guide de diagnostic

| Symptôme | Cause possible | Vérification sûre |
|---|---|---|
| Le sketch simulé ne compile pas | Mauvaise carte ou syntaxe | Choisir Uno Rev3 et lire les messages de l'IDE |
| Console illisible | Débit différent | Moniteur série à **9600 bauds** |
| Tension brute « 2305 V » | Conversion absente | Diviser le registre tension par 10 |
| Énergie « 12345 kWh » | Confusion Wh/kWh | Diviser les Wh par 1000 |
| Six nombres incorrects | Mots bas/haut mal assemblés | Revoir l'assemblage en 32 bits |
| Échec simulé affiché comme « 0 V » | Statut de lecture confondu avec valeur | Tester le booléen succès avant d'afficher |
| Ancien relevé présenté comme nouveau | Données antérieures réutilisées sans statut | Afficher « INDISPONIBLE », ne pas actualiser comme une mesure valide |
| Mesure réelle non disponible | Version de module ou bibliothèque incompatible, liaison ou banc défaillants | Vérifier les références logicielles ; **confier les vérifications physiques au professionnel qualifié** |
| Essai réel avec seulement l'USB de la Uno | Partie mesure du PZEM non opérationnelle | Revenir à la simulation, ne pas improviser de secteur |

Un retour `NaN` ou une réponse invalide doit être signalé ; **zéro courant ou zéro puissance peut être physiquement valide**. Les contrôles de plausibilité ne remplacent pas un étalonnage.

**Interdits :** essayer le 230 V sur une breadboard, ouvrir une installation sous tension, effacer l'index avec `resetEnergy()` pour masquer une panne, ou présenter une simulation comme une mesure réelle.
