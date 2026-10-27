# M08 — Diagnostic des calculs d'énergie

| Symptôme | Cause possible | Première correction |
|---|---|---|
| Un total devient gigantesque après une diminution d'index | Soustraction `uint32_t` dans le mauvais sens | Tester `nouveau < precedent` **avant** de soustraire |
| Le total croît à chaque même relevé reçu | Index total ajouté au lieu du delta | Calculer `delta = indexNouveau - indexPrecedent` |
| Le total du jour apparaît à zéro après démarrage à 12 h | Première base à midi, pas à minuit | Afficher **partiel** plutôt que « consommation 0 depuis minuit » |
| Énergie de passage à minuit attribuée arbitrairement | Delta traverse deux jours | Ne pas prétendre connaître la répartition ; nouveau jour partiel |
| Cumul mensuel perdu à chaque nouveau jour | Les deux cumuls sont remis à zéro à minuit | Réinitialiser le jour ; préserver le mois si mois inchangé |
| Compteur repart à zéro lors du passage au mois | `pzem.resetEnergy()` utilisé | Ne pas remettre l'index PZEM à zéro pour le calendrier |
| Après reboot physique, état absent | Copie RAM non persistante | FRAM et récupération durable au M11 ; pour l'instant annoncer suivi partiel |
| Même relevé compté après restauration | Pas de contrôle de l'horodatage/index | Ignorer même temps + même index |
| Horloge DS3231 revient en arrière | Date non fiable ou reconfiguration | Ne pas attribuer les nouveaux deltas ; diagnostiquer et régler RTC |
| Erreurs d'un ou plusieurs Wh sur grand index | `float` AVR insuffisamment précis | Préférer le registre brut d'index en Wh avec une plage contrôlée |

Les exemples ne raccordent **aucun secteur**. Le LCD M08 utilise un **index fictif** et une date RTC réelle uniquement si le DS3231 fonctionne.
