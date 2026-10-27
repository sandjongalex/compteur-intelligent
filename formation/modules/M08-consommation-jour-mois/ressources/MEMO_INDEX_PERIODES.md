# Mémo M08 — Index d'énergie et périodes

## Formule fondamentale

`deltaWh = indexWh[N] - indexWh[N-1]` pour **deux lectures valides**, index croissant et date cohérente.

`kWh = Wh / 1000`. Exemple : **120650 − 120400 = 250 Wh = 0,250 kWh**.

## Interpréter le cumul

- **Index PZEM** : cumul d'énergie depuis sa remise à zéro précédente. Ne pas appeler `resetEnergy()` à minuit.
- **Cumul du jour** : addition des deltas attribuables avec certitude à la journée.
- **Cumul du mois** : addition des deltas attribuables avec certitude au mois.
- **Complet** : on dispose d'une base fiable au début exact de la période (00:00:00) et d'une chaîne cohérente de relevés.
- **Partiel** : la base commence après minuit ou des événements inconnus traversent la période. Ne pas appeler le chiffre « total exact depuis minuit ».

## Les décisions à prendre dans `EnergieM08.h`

| Événement | Action |
|---|---|
| Même jour/mois, index plus grand | Calculer le delta et l'ajouter aux deux compteurs |
| Même horodatage et même index | Ignorer le doublon |
| Jour différent, **même mois** | Nouvelle base jour, mais delta inter-journalier peut contribuer au mois |
| Mois différent | Nouvelle base jour ET mois, ne pas attribuer arbitrairement le delta qui franchit la frontière |
| Pas de lecture valide | Ne pas inventer zéro ni recycler une ancienne mesure en la datant à nouveau |
| Horloge recule ou date invalide | Rejeter le relevé ; corriger le DS3231 et rétablir une chronologie cohérente |
| Index baisse | Stopper l'ancienne chaîne, réancrer et marquer les périodes incomplètes |
| Relevé après reboot | Restaurer **un état préalablement sauvegardé de manière durable** ; sinon commencer une période **partielle** |

## Attention aux limites réelles

1. Si l'index est réinitialisé puis remonte au-dessus de l'ancien entre deux lectures, un algorithme utilisant uniquement deux index ne peut pas toujours détecter le problème. Une surveillance complémentaire et un journal de redémarrage seront nécessaires.
2. Les fonctions de bibliothèque renvoyant l'énergie en **`float`** peuvent perdre des Wh lorsque le cumul devient grand ; le moteur utilise un entier `uint32_t` en **Wh** pour ses opérations, mais l'acquisition doit préserver cette précision.
3. `uint32_t` est limité à environ **4,29 milliards de Wh** ; gérer les limites de compteur et l'éventuel dépassement dans une version industrielle.
4. La méthode ne connaît pas la distribution de l'énergie **à l'intérieur** d'un intervalle qui traverse minuit. La précision du total dépend des repères disponibles.
5. Le DS3231 doit être réglé de façon cohérente en heure locale ou UTC, mais **sans reculer arbitrairement l'heure** en exploitation.

### Pourquoi le mois peut rester correct si le jour est incomplet

Du **27/10 à 23:59** au **28/10 à 00:05**, le delta reste **entièrement dans octobre**. Il peut donc alimenter le mois sans que l'on sache répartir les Wh entre les deux journées.

### Pourquoi la démonstration ne couvre pas la FRAM

Le moteur expose un état pouvant être copié/restauré en RAM. La **persistance véritable** impose d'écrire cet état dans une mémoire non volatile, de protéger les mises à jour et de résister aux écritures interrompues. Ce travail relève du **Module 11**.

Références :
- [Code de la bibliothèque PZEM V3 — index kWh](https://github.com/mandulaj/PZEM-004T-v30/blob/master/src/PZEM004Tv30.cpp)
- [Adafruit RTClib — API DS3231](https://adafruit.github.io/RTClib/html/class_r_t_c___d_s3231.html)
