# Code Arduino — M06, mesure PZEM-004T V3.0

**Carte : Arduino Uno Rev3 / ATmega328P · IDE 2 · Moniteur série 9600 bauds.**

**Règle de sécurité : les cinq premiers sketches et les corrigés ne nécessitent aucun secteur, aucun PZEM et aucune bibliothèque externe.** Le dernier sketch est un **exemple destiné exclusivement à un banc de mesure mis en place et exploité par une personne qualifiée**, jamais un guide de câblage secteur pour débutants.

## Apprentissage progressif

| Ordre | Fichier | Résultat observé |
|---|---|---|
| 1 | [V01-01 · Six grandeurs fictives](V01_01_six_grandeurs_simulees/V01_01_six_grandeurs_simulees.ino) | Tension, courant, puissance, index kWh, fréquence et facteur de puissance |
| 2 | [V01-02 · Registres fictifs](V01_02_registres_decodes/V01_02_registres_decodes.ino) | Conversion des valeurs brutes avec les bonnes unités |
| 3 | [V02-01 · Source de données simulée](V02_01_lecture_simulee/V02_01_lecture_simulee.ino) | Relevés périodiques toutes les ~2 secondes |
| 4 | [V02-02 · Échec simulé](V02_02_detection_panne_simulee/V02_02_detection_panne_simulee.ino) | Alternance succès, erreur, succès ; aucune fausse mesure |
| 5 | [V02-03 · PZEM réel pour banc qualifié](V02_03_pzem_reel_qualifie/V02_03_pzem_reel_qualifie.ino) | Lecture via bibliothèque V3 et rejet des valeurs invalides |
| Corrigé | [TP01 registres fictifs](TP01_corrige_registres/TP01_corrige_registres.ino) | Mise à jour des registres et conversions |
| Corrigé | [TP02 panne fictive](TP02_corrige_panne/TP02_corrige_panne.ino) | Rejet d'une lecture absente sans inventer zéro |

## Installation

1. Avec **Arduino IDE 2**, sélectionner **Arduino Uno** et son port USB.
2. Ouvrir chaque sketch **dans son dossier homonyme**, puis **Vérifier** et **Téléverser**.
3. Pour les quatre premières étapes et les corrigés, **aucun composant externe n'est nécessaire** : ouvrir le moniteur à **9600 bauds**.
4. La lecture réelle nécessite la bibliothèque `PZEM004Tv30` de **Jakub Mandula**, adaptée aux PZEM V3.0. Utiliser le gestionnaire de bibliothèques de l'IDE et vérifier la version ainsi que l'API effectivement installées ; `SoftwareSerial` est disponible avec le cœur Arduino AVR.
5. L'interface de communication du PZEM, son alimentation, son isolation et surtout **la partie secteur** doivent être validées par une personne qualifiée. Ce cours n'enseigne aucune procédure de raccordement au 230 V. Le seul port USB ne permet pas d'obtenir une mesure secteur réelle.

## Pourquoi l'index énergie doit rester cumulatif

`pzem.energy()` renvoie l'**index d'énergie cumulée** du PZEM, en **kWh** dans la bibliothèque utilisée. Il ne s'agit **ni** de la consommation du jour **ni** de celle du mois. Les index de référence avec le DS3231 seront abordés au Module 08. **Ne pas appeler `resetEnergy()`** pour « remettre le jour à zéro », car cela détruirait le repère cumulatif et compromettrait l'historique.

## Validation attendue

- Les nombres simulés sont clairement affichés comme **fictifs**.
- On n'utilise pas `0` comme code d'erreur : une vraie mesure de puissance égale à zéro reste possible.
- Un échec de lecture n'est pas présenté comme un nouvel index.
- Le code réel vérifie les six valeurs ; en cas d'échec, affiche `LECTURE INVALIDE`.
- **Compilation IDE et essais réels non réalisés dans ce dépôt à ce stade**.

Bibliothèque et exemples : https://github.com/mandulaj/PZEM-004T-v30  
Registres et conversions dans la bibliothèque : https://github.com/mandulaj/PZEM-004T-v30/blob/master/src/PZEM004Tv30.cpp

[Scripts](../scripts/) · [Ressources et protocoles](../ressources/README.md) · [Plan de tests](../ressources/PLAN_TESTS.md)
