# M06 — Compteur fil rouge : six grandeurs du PZEM

**Base :** [M05](../M05/Compteur_M05/Compteur_M05.ino). **Snapshot M06 :** [Compteur_M06.ino](Compteur_M06/Compteur_M06.ino).

Cette version **conserve** la LED commandée, le bouton D2–GND, l'anti-rebond, le moniteur USB et les commandes `1/0/?`, ainsi que le rythme périodique basé sur `millis()`.

Elle **ajoute** :
- une structure `Mesures` qui regroupe les **six valeurs** du PZEM-004T V3 ;
- une fonction `lireMesures()` séparée de `afficherMesures()` ;
- la simulation par défaut, sans secteur ni matériel de mesure ;
- un statut **lecture invalide**, sans inventer de nouvelles valeurs ;
- l'option de lecture avec `PZEM004Tv30`, **réservée à un banc secteur protégé exploité par une personne qualifiée**.

**Validation attendue :** les commandes et le bouton du M05 fonctionnent toujours tandis que les six grandeurs fictives s'affichent. Compiler d'abord sur Uno en simulation ; tout essai matériel réel est à documenter séparément.

[Guide général](../../README.md) · [Règle de continuité](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md) · [Cours M06](../../../formation/modules/M06-pzem-mesures/README.md).
