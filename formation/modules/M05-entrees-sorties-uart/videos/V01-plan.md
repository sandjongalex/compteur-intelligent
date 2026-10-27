# M05-V01 — Un bouton, une LED, puis l'anti-rebond (9 minutes)

**État : script complet et 3 sketches progressifs rédigés. Essais matériels et tournage non encore effectués.**

## Objectif observable

Avec un bouton **entre D2 et GND** et la LED intégrée à l'Uno Rev3 : faire changer la LED **une seule fois par appui validé**, en corrigeant les rebonds mécaniques.

## Progression minute par minute

| Temps | Ce que le formateur montre | Fichier |
|---|---|---|
| 00:00–00:55 | Résultat final : 1 appui = 1 bascule | [V01-03](../code/V01_03_bascule_antirebond/V01_03_bascule_antirebond.ino) |
| 00:55–02:10 | Câblage USB débranché, `INPUT_PULLUP` : HIGH relâché/LOW pressé | [Câblage](../ressources/CABLAGE_BASSE_TENSION.md) |
| 02:10–03:20 | Lire l'état du bouton : LED allumée pendant l'appui | [V01-01](../code/V01_01_bouton_niveau/V01_01_bouton_niveau.ino) |
| 03:20–04:45 | Détecter le début de l'appui et inverser l'état | [V01-02](../code/V01_02_bascule_sans_antirebond/V01_02_bascule_sans_antirebond.ino) |
| 04:45–06:25 | Visualiser le rebond, comprendre l'intérêt d'une fenêtre stable | [Mémo](../ressources/MEMO_M05.md) |
| 06:25–07:45 | Ajouter `millis`, validation 35 ms, bascule sur front stable LOW | [V01-03](../code/V01_03_bascule_antirebond/V01_03_bascule_antirebond.ino) |
| 07:45–08:25 | Tester cinq pressions et diagnostiquer un résultat inattendu | [Plan de tests](../ressources/PLAN_TESTS.md) |
| 08:25–09:00 | Mini-défi : alterner les pages 0/1 | [TP01](../tp/TP_M05_APPRENANT.md) |

[Lire le script intégral du formateur](../scripts/V01-script.md). Les durées sont des **cibles de montage**.

## Validation

- [ ] Les trois sketches compilent sur Uno Rev3.
- [ ] Une pression tenue ne provoque pas plusieurs bascules avec la version finale.
- [ ] Le public comprend pourquoi la version sans anti-rebond est volontairement imparfaite.
- [ ] Pas de secteur, ni de câblage sous tension.
