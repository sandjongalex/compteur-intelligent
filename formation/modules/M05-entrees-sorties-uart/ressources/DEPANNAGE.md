# M05 — Diagnostic guidé des erreurs

| Symptôme | Diagnostic probable | Première action de l'apprenant |
|---|---|---|
| LED reste allumée ou éteinte en V01-01 | Deux pattes de même côté du bouton 4 broches ; D2 non reliée au bon contact | Débrancher USB et contrôler la continuité du bouton/câble |
| LED allumée seulement pendant appui | Version V01-01 chargée au lieu de V01-03 | Vérifier le nom du sketch téléversé |
| LED bascule plusieurs fois sur un appui | Rebonds dans le code V01-02 (sans filtrage) | Téléverser V01-03 avec anti-rebond |
| LED ne bascule pas au relâchement | Ce n'est **pas** une erreur de V01-03 : la bascule se fait sur l'appui stable | Contrôler cinq pressions distinctes |
| Moniteur série illisible | Débits différents entre `Serial.begin(9600)` et le moniteur | Choisir 9600 bauds des deux côtés |
| Aucune ligne série | Mauvais port/carte, échec téléversement, moniteur non ouvert | Vérifier la carte Uno et la console IDE |
| Deux lignes pour un envoi | Caractères de fin de ligne non filtrés dans une variante du code | Ignorer `'\r'` et `'\n'` |
| Commandes `1`/`0` sans effet | Mauvais caractère, ancien sketch, D0/D1 occupés | Vérifier V02-02/V02-03, envoyer un seul caractère |
| Mesures toutes les cinq secondes sans réaction immédiate | Un `delay(5000)` a été ajouté | Retirer l'attente bloquante, comparer `millis()` |
| Mesures « 230.5 V » mais pas de PZEM | **C'est normal : simulation volontaire** | Ne pas présenter ce nombre comme une vraie mesure électrique |

## Erreurs sûres à filmer

1. Envoyer une mauvaise commande : afficher « Commande inconnue ».
2. Mettre le moniteur sur un **débit différent** : montrer l'anomalie, puis revenir à 9600.
3. Montrer **dans le texte du code**, sans branchement dangereux, ce qui se passerait avec `delay(5000)`.
4. Montrer V01-02 comme une version volontairement incomplète, puis passer à V01-03.

**Ne pas fabriquer une erreur dangereuse** en reliant le secteur à la carte, en court-circuitant 5 V/GND ou en branchant un modem non adapté.
