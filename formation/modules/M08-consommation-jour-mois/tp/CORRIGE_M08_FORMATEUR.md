# M08 — Corrigés des TP et barèmes (réservé au formateur)

## TP01 — Deltas exacts

| Transition | Delta |
|---|---:|
| 120400 → 120650 | **250 Wh** |
| 120650 → 120650 | **0 Wh** |
| 120650 → 120900 | **250 Wh** |
| 120900 → 121100 | **200 Wh** |
| **Total** | **700 Wh = 0,700 kWh** |

Vérification : `121100 - 120400 = 700 Wh`. Le troisième relevé d'index identique ne doit rien ajouter. Dans une vraie acquisition, on distingue **doublon strict** (même horodatage ET index) d'une nouvelle lecture avec index stable.

**Code de référence :** [V01-02](../code/V01_02_cumul_jour/V01_02_cumul_jour.ino) et fonction `ajouter()` du moteur [V02-01](../code/V02_01_passer_au_mois/EnergieM08.h) pour reconnaître un doublon strict.

**Barème /10 :** deltas (4), total Wh/kWh (2), contrôle index final/départ (1), explication du doublon (2), interprétation de l'index cumulatif (1).

## TP02 — Événements et comptages

| Événement | Résultat moteur | Jour | Mois | Qualité |
|---|---|---:|---:|---|
| 31/01 23:58 / 120400 | Première base | 0 Wh | 0 Wh | Janvier partiel (base tardive) |
| 31/01 23:59 / 120650 | Ajouter 250 Wh | 250 Wh | 250 Wh | Janvier partiel |
| 01/02 00:00 / 120660 | Nouveau mois | 0 Wh | 0 Wh | Février complet *si suivi continu dans ce scénario* |
| 01/02 00:05 / 120700 | Ajouter 40 Wh | 40 Wh | 40 Wh | Février complet |
| Redémarrage avec **copie RAM conservée** | Restaurer état | 40 Wh | 40 Wh | Pas de changement |
| 01/02 00:05 / 120700 répété | Doublon ignoré | 40 Wh | 40 Wh | Pas de changement |
| 01/02 00:06 / 120740 | Ajouter 40 Wh | 80 Wh | 80 Wh | Février complet |
| 01/02 00:07 / 20 | **Index réinitialisé** | 0 Wh | 0 Wh | Février maintenant **partiel** |
| 01/02 00:08 / 35 | Nouvelle progression 15 Wh | 15 Wh | 15 Wh | Toujours partiel |

**10 Wh non attribués :** `120660 - 120650` traverse la frontière entre la dernière lecture de janvier et celle de février à minuit. Le logiciel ne les affecte pas arbitrairement à janvier ou à février. Cela ne remet pas en cause le suivi **depuis** l'index pris exactement à minuit pour février.

**Reprise :** une copie sauvegardée dans une variable RAM pendant l'exécution sert uniquement de simulation d'un redémarrage. **La vraie coupure secteur efface la RAM.** La FRAM avec protection des écritures, reprise atomique et contrôle de l'état sera abordée au M11.

**Index réinitialisé :** aucune soustraction `20 - 120740` en `uint32_t` ; le moteur ré-ancre à 20 et marque les périodes incomplètes. Le prochain delta valide est `35 - 20 = 15 Wh`.

**Barème /10 :** dates/frontières (2), 250/40/80 Wh (3), doublon (1), reprise RAM ≠ FRAM (2), index réinitialisé (1), qualité des périodes (1).

## Mini-défi autour de minuit (même mois)

Le delta **30 Wh** appartient nécessairement au mois d'octobre si le compteur et la RTC sont continus sur les deux lectures, mais sa répartition entre **le 27 et le 28 octobre** est inconnue. Le nouveau jour est **partiel** ; le mois peut conserver ce delta si la continuité de l'index est fiable.

**Seuil recommandé : 8/10 par TP** et correction obligatoire de toute confusion sur les bases de période ou la persistance.
