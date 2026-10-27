# M08 — Deux travaux pratiques pour l'apprenant (sans corrections)

**Durée hors vidéo : 40 à 60 minutes.** Les exemples sont **entièrement simulés** et utilisables avec Arduino Uno branchée en USB ou sur papier, sans DS3231 ni PZEM secteur.

## TP01 — Calculer les deltas d'un index cumulé

**Départ :** [V01-01](../code/V01_01_index_delta/V01_01_index_delta.ino) et [V01-02](../code/V01_02_cumul_jour/V01_02_cumul_jour.ino).

On dispose de cinq index fictifs du **27/10/2026**, avec la première lecture exactement à 00:00 :

| Heure | Index PZEM (Wh) |
|---|---:|
| 00:00 | 120 400 |
| 01:00 | 120 650 |
| 01:00, relevé répété | 120 650 |
| 02:00 | 120 900 |
| 03:00 | 121 100 |

**À faire :**

1. Calculer chaque delta `indexN - indexPrécédent`, en **Wh**.
2. Additionner les deltas et convertir le total en **kWh**.
3. Vérifier que `indexFinal - indexInitial` donne le même résultat.
4. Modifier le sketch pour montrer explicitement un message **DOUBLON** lorsque le même horodatage et le même index sont reçus.
5. Expliquer pourquoi additionner `120400 + 120650 + ...` serait faux.

**Livrable :** tableau des quatre deltas, code annoté et résultat série. Attention : deux relevés identiques d'index peuvent également correspondre à une consommation nulle ; le **doublon strict** exige **même horodatage et même index**.

## TP02 — Janvier → février avec reprise simulée et anomalie

**Départ :** [V02-01](../code/V02_01_passer_au_mois/V02_01_passer_au_mois.ino), puis [V02-02](../code/V02_02_reprise_et_erreurs/V02_02_reprise_et_erreurs.ino).

| Date et heure | Index fictif (Wh) |
|---|---:|
| 31/01/2026 23:58 | 120 400 |
| 31/01/2026 23:59 | 120 650 |
| 01/02/2026 00:00 | 120 660 |
| 01/02/2026 00:05 | 120 700 |
| **Reprise simulée avec copie d'état en RAM** | — |
| 01/02/2026 00:05 (répété) | 120 700 |
| 01/02/2026 00:06 | 120 740 |
| 01/02/2026 00:07 (index réinitialisé) | 20 |
| 01/02/2026 00:08 | 35 |

**À faire :**

1. Indiquer à quel événement la journée ET le mois changent.
2. Calculer le cumul observé du **31 janvier** entre 23:58 et 23:59.
3. Calculer les valeurs **jour** et **mois** du 1er février à 00:05, puis à 00:06.
4. Expliquer pourquoi la période du 31 janvier est **partielle**, tandis qu'une nouvelle base exacte à 00:00 peut rendre la période de février **complète dans la simulation**.
5. Expliquer la différence entre une simple copie d'état **en RAM** et la vraie persistance après coupure.
6. Vérifier que le doublon de 00:05 ne change pas les compteurs.
7. Expliquer ce qu'il faut faire lorsque l'index passe de 120 740 à 20, puis calculer la nouvelle progression jusqu'à 35.
8. Facultatif : modifier le simulateur pour passer du **28/02/2028 au 29/02/2028**, puis au **01/03/2028**.

**Livrable :** tableau des états (événement, index, jourWh, moisWh, complet/partiel), copie du résultat série et explication de la stratégie de reprise.

## Mini-défi : coupure autour de minuit

Un relevé est effectué le **27/10 23:59**, le suivant le **28/10 00:05**. L'index a progressé de **30 Wh**. Peut-on savoir combien ont été consommés le 27 et combien le 28 sans information supplémentaire ? Quelles conséquences pour les kWh du **mois d'octobre** ?

## Critères de validation

- Bon calcul des différences Wh et conversion en kWh.
- Aucun double comptage.
- Traitement honnête des frontières de dates et des périodes incomplètes.
- Aucune fausse promesse de persistance pendant une coupure.
- **Aucune manipulation du secteur**.
