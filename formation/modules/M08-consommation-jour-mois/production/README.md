# M08 — Suivi de production

**Durée vidéo cible : 16 min (deux leçons de 8 min).** Enregistrement et publication gérés par le formateur. **Aucun PowerPoint.**

## Réalisé

- [x] Deux scripts oraux complets avec étapes de programmation chronologiques.
- [x] Cinq sketches de cours : deux V01, trois V02 (dont RTC+LCD avec index fictif).
- [x] Moteur C++11 autonome `EnergieM08.h`, partagé sous forme de copies identiques dans les projets avancés.
- [x] 32 assertions de scénarios dans `code/tests/test_m08.cpp` (non exécutées par l'IDE).
- [x] Deux TP apprenant et corrigés formateur séparés.
- [x] Quiz de 10 QCM corrigés avec explication de chaque choix et données JSON.
- [x] Mémo des index, calculs, doublons et périodes partielles.
- [x] Dépannage, consignes de sécurité et plan de tests.
- [x] Documentation d'intégration des modules M06/M07/M08 et limites des `float` AVR.

## À vérifier avant tournage

- [ ] **Exécuter** les tests C++ : `g++ -std=c++11 -Wall -Wextra -pedantic test_m08.cpp -o test_m08 && ./test_m08`.
- [ ] Compiler et téléverser les cinq sketches sur Arduino Uno Rev3 avec les bibliothèques nécessaires au LCD/RTC.
- [ ] Vérifier les sorties **250/0/250/200 Wh**, total **700 Wh**.
- [ ] Vérifier passage janvier/février et **80 Wh** au 01/02 00:06.
- [ ] Tester rejets de doublon, RTC rétrograde, index qui diminue.
- [ ] Vérifier la **simulation** du redémarrage en RAM sans la confondre avec une vraie coupure.
- [ ] Tester l'affichage DS3231/LCD, date réelle versus valeurs fictives, symbole `~` pour partiel.
- [ ] Marquer les résultats dans le [plan de tests](../ressources/PLAN_TESTS.md).
- [ ] Répéter et chronométrer chaque vidéo pour huit minutes.

## Travaux assurés par le formateur

- [ ] Filmer les résultats réels du moniteur et du LCD **basse tension**.
- [ ] Enregistrer et monter les deux vidéos.
- [ ] Ajouter les sous-titres et publier sur AlexTech Academy.
- [ ] Distribuer le quiz apprenant sans diffuser immédiatement le corrigé.

**Statut : supports prêts pour validation technique. Ni compilation officielle Arduino, ni exécution attestée des tests C++, ni fonctionnement matériel ne sont déclarés acquis.**
