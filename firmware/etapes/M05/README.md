# M05 — Compteur fil rouge : bouton, LED, UART et millis()

**Base :** [M04](../M04/Compteur_M04/Compteur_M04.ino). **Snapshot M05 :** [Compteur_M05.ino](Compteur_M05/Compteur_M05.ino).

Cette version transforme intentionnellement la LED de démonstration de M04 (clignotement automatique) en **voyant commandable**. Elle conserve `setup()`, `loop()`, l'organisation du code Arduino et le moniteur série, puis introduit :

- un bouton entre **D2 et GND**, configuré en `INPUT_PULLUP`, avec anti-rebond ;
- des commandes USB série `1` (LED ON), `0` (LED OFF), `?` (aide) à 9600 bauds ;
- une tâche périodique avec `millis()`, sans blocage par `delay()` ;
- une tension **fictive**, affichée pour préparer la lecture du capteur.

**Évolution justifiée :** le clignotement automatique disparaît parce que la LED devient un indicateur contrôlé. C'est expliqué et testé, et non une régression accidentelle.

**Test attendu :** une Uno USB seule, commandes 1/0/? et bouton D2–GND ; une bascule par appui stable et affichage fictif périodique. **Aucun secteur ni PZEM.** Les essais physiques ne sont pas attestés par cette fiche.

[Guide général](../../README.md) · [Règle de continuité](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md) · [Cours M05](../../../formation/modules/M05-entrees-sorties-uart/README.md).
