# M08 — Plan de tests : index, calendrier, anomalies et reprise

**Aucun essai réel de PZEM ni compilation Arduino n'est encore revendiqué dans cette livraison.**

## Matériel minimal

- Sketches V01/V02 simulés : Arduino Uno Rev3 (ou compilateur C++ pour les tests de moteur), USB, moniteur série 9600 bauds.
- Démonstration finale : DS3231 et LCD I2C 20×4 compatibles en **basse tension**, bibliothèque RTClib + hd44780. **Aucun PZEM secteur**.

## Tests du moteur

| Test | Entrées fictives | Résultat attendu | Statut |
|---|---|---|---|
| T01 | 120400 → 120650 Wh | **250 Wh** | [ ] |
| T02 | 120650 → 120650 | **0 Wh**, pas de double comptage | [ ] |
| T03 | 120900 → 121100 | **200 Wh** | [ ] |
| T04 | 31/01 23:59 → 01/02 00:00 | Nouvelle base jour/mois à 00:00 | [ ] |
| T05 | 01/02 00:00 120660 → 00:05 120700 | **40 Wh** jour et mois | [ ] |
| T06 | Restaurer un **état conservé en RAM**, puis répéter même relevé | Doublon ignoré | [ ] |
| T07 | 01/02 00:06 120740 → 00:07 20 | **INDEX RÉINITIALISÉ**, périodes partielles | [ ] |
| T08 | 00:07 20 → 00:08 35 | Nouvelle progression **15 Wh** | [ ] |
| T09 | Date invalide (30 février) ou horloge qui recule | Relevé rejeté | [ ] |
| T10 | Février 2028 → 29/02 → 01/03 | Bissextile et changement de mois correctement traités | [ ] |
| T11 | 1er→2 février, delta 30 Wh traversant minuit | Jour partiel, mois conserve le delta | [ ] |
| T12 | RTC DS3231 + LCD + index **SIMULÉ** | Date vraie si fiable, valeurs simulées et symbole `~` si partiel | [ ] |

## Tester le noyau C++ sur ordinateur

Les tests C++ sont disponibles dans `code/tests/`. Exemple :

```bash
cd formation/modules/M08-consommation-jour-mois/code/tests
g++ -std=c++11 -Wall -Wextra -pedantic test_m08.cpp -o test_m08
./test_m08
```

**Les assertions sont présentes, mais elles ne sont pas annoncées comme réussies avant exécution vérifiée.** Cela ne remplace pas les essais des sketches dans Arduino IDE 2.

## Journal de résultats à compléter

- Date de vérification :
- Environnement C++ et Arduino :
- RTC/écran (référence exacte) :
- Sortie des tests automatiques :
- Résultats T01–T12 :
- Problèmes et corrections :
- Décision : à corriger / prêt à filmer.

**Ne pas confondre un redémarrage simulé en RAM avec une coupure matérielle réelle.**
