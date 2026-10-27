# M08 — Code Arduino : du relevé cumulatif au jour/mois

**Sans PowerPoint. Première moitié entièrement en simulation : aucune prise secteur, aucun PZEM, aucune RTC requise.**

## Quatre étapes de programmation

1. [V01-01 — calculer les deltas Wh](V01_01_index_delta/V01_01_index_delta.ino) : `120650 - 120400 = 250 Wh`.
2. [V01-02 — cumul de la journée](V01_02_cumul_jour/V01_02_cumul_jour.ino) : éviter d'ajouter l'index total ou de compter deux fois une ligne identique.
3. [V02-01 — passer de janvier à février](V02_01_passer_au_mois/V02_01_passer_au_mois.ino) : date fictive + état journalier/mensuel + base prise à minuit.
4. [V02-02 — simuler un redémarrage et des erreurs](V02_02_reprise_et_erreurs/V02_02_reprise_et_erreurs.ino) : copier/restaurer **un état conservé uniquement en RAM pendant la démonstration**, ignorer doublons, détecter retour du compteur ou date incohérente.

Chaque projet `.ino` est dans son dossier **homonyme**, compilable sur **Arduino Uno Rev3**. Les trois programmes avancés contiennent **leur propre copie du moteur `EnergieM08.h`** afin d'éviter les chemins de compilation ambigus dans Arduino IDE. Les trois copies sont identiques ; les changements au moteur doivent être reportés dans les deux et dans la suite de tests.

5. [V02-03 — DS3231 + LCD, index fictif](V02_03_ds3231_lcd_fictif/V02_03_ds3231_lcd_fictif.ino) : date d'une RTC réelle (si fiable), tension/index simulés, cumuls LCD avec `~` pour « partiel ».

[Guide de jonction M06 / M07 / M08](INTEGRATION_M06_M07_M08.md).

## En-tête `EnergieM08.h` : règles de base

- Index PZEM = **Wh entiers cumulés**, pas puissance en W ni énergie du jour.
- Si un relevé est valide et arrive **dans le même jour**, on ajoute `delta = indexNouveau - indexAncien` à la journée et au mois.
- Si le jour change mais **pas** le mois, on démarre un nouveau compteur du jour. Le delta qui traverse minuit n'est **pas** attribué à l'un des deux jours faute d'heure exacte de consommation ; on peut l'ajouter au mois puisque les deux relevés sont dans **le même mois**, tant que l'index est continu.
- Si le mois change, on démarre jour et mois sur une nouvelle base. Sans relevé à **00:00:00**, les consommations affichées sont **partielles** et non de vrais totaux depuis minuit.
- Si la RTC recule, le relevé est rejeté. Si l'index descend, on **ré-ancre à la nouvelle valeur, en marquant la période incomplète**, sans inventer la consommation perdue.
- Un doublon avec même horodatage et même index est **ignoré**.
- Au tout premier relevé de la période à **00:00:00** : le compteur peut être marqué complet (si les index suivent correctement ensuite). Sinon, **partiel**.
- L'absence de lecture est distincte d'une consommation nulle.
- Ce module **ne réalise pas de sauvegarde durable** ; la persistance avec FRAM et sécurité contre double comptage sera développée au **M11**.

## Tests hors Arduino

Le moteur est écrit en C++11 sans dépendances Arduino. Un test reproductible est disponible :

```bash
cd formation/modules/M08-consommation-jour-mois/code/tests
g++ -std=c++11 -Wall -Wextra -pedantic test_m08.cpp -o test_m08
./test_m08
```

Ces tests vérifient janvier/février, redémarrage simulé en RAM, doublon, diminution d'index, février bissextile, date invalide et traversée de minuit. **Ils ne prouvent pas un test matériel Uno ni une reprise après coupure d'alimentation réelle.**

## Précision et intégration

Le code pédagogique stocke les index dans un **entier `uint32_t` en Wh**, pour éviter les erreurs d'arrondi répétées avec les `float` de l'Uno AVR. La bibliothèque PZEM004Tv30 utilisée au M06 retourne un **`float` d'énergie cumulée en kWh** ; la reconversion en Wh peut perdre une partie de sa précision sur un grand index. L'intégration de production devra tenir compte de cette limite et, si nécessaire, décoder directement les registres d'énergie 32 bits ou adopter une méthode d'acquisition adaptée. Ne pas prétendre à une précision de 1 Wh en utilisant aveuglément un grand index `float`.

**Ne jamais appeler `pzem.resetEnergy()` pour remettre à zéro la journée ou le mois.**

[Scripts](../scripts/V01-script.md) · [Plan de tests](../ressources/PLAN_TESTS.md)
