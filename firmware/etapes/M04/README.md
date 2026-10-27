# M04 — Le même firmware, maintenant structuré en fonctions

Cette version **part directement de M03**. Elle conserve la sortie `LED_BUILTIN` et son clignotement, tout en ajoutant des concepts C/C++ indispensables au compteur.

**Apports M04 :**
- Constantes et variables typées : `TEMPS_ALLUME_MS`, `PUISSANCE_SIMULEE_W`, `DUREE_SIMULEE_H`.
- Fonction paramétrée `calculerEnergieKWh(float puissanceW, float heures)` avec `return`.
- Fonction réutilisable `commanderLED(bool)`.
- Communication série `Serial.begin(9600)`, `Serial.print`.
- Calcul pédagogique théorique **500 W pendant 2 h = 1,000 kWh**, basé sur des données fictives.

[Ouvrir `Compteur_M04.ino`](Compteur_M04/Compteur_M04.ino) · [Lire le cours M04](../../../formation/modules/M04-bases-cpp/README.md).

**Transition M05 :** la LED cesse d'être un clignotant automatique pour devenir **un voyant commandable** par bouton et UART. Les attentes `delay()` sont remplacées par le contrôle de `millis()`. Il s'agit d'une évolution fonctionnelle expliquée, pas de la disparition accidentelle d'une fonctionnalité.

**Aucun PZEM ni secteur**, Uno USB seulement.
