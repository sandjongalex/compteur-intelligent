# Annexe M01 — Corrigés détaillés du chapitre 1

> **À consulter après votre tentative.** Cette annexe contient les réponses aux activités du [chapitre 1](../chapitres/01-decouvrir-le-compteur-et-comprendre-l-electricite.md). Elle est distincte du chapitre afin de favoriser le travail autonome.  
> **Valeurs entièrement pédagogiques :** aucune mesure réelle du secteur n'est présentée.

## A1 — Trajet d'un relevé

Ordre des cinq cartes :

1. **PZEM-004T** — mesurer les grandeurs électriques et fournir l'index d'énergie ;
2. **ATmega328P** — traiter et organiser le relevé ;
3. **SIM800L** — transmettre les données si la liaison GSM/GPRS fonctionne ;
4. **Flask / SQLite** — recevoir, valider et enregistrer le relevé côté serveur ;
5. **Navigateur** — consulter le relevé et ses historiques.

Schéma simplifié :

`PZEM → ATmega328P → SIM800L → Flask/SQLite → navigateur`

**Composants annexes :** le DS3231 fournit la date et l'heure ; le LCD présente l'information localement ; la mémoire FRAM est destinée à la sauvegarde persistante de données et relevés en attente. Aucun de ces trois modules n'est un serveur web ou un modem GSM.

**Erreur typique :** placer le LCD entre le modem et le serveur. L'écran constitue une sortie **locale**, pas une étape de transmission distante.

**État de réalisation :** cette chaîne décrit l'architecture **visée**. Les fonctions GSM, FRAM et serveur ne sont pas à considérer comme déjà validées sur un prototype physique dans l'état M09 du firmware.

## A2 — Calculs de consommation

L'hypothèse de tous les exercices est une **puissance active constante** pendant la durée considérée.

Rappel : `E (kWh) = P (kW) × t (h)`.

| Cas | Conversion de puissance | Conversion du temps | Calcul | Résultat |
|---|---|---|---|---|
| A : 200 W pendant 5 h | 0,2 kW | 5 h | 0,2 × 5 | **1 kWh** |
| B : 500 W pendant 4 h | 0,5 kW | 4 h | 0,5 × 4 | **2 kWh** |
| C : 2 000 W pendant 30 min | 2 kW | 0,5 h | 2 × 0,5 | **1 kWh** |
| D : 100 W pendant 15 min | 0,1 kW | 0,25 h | 0,1 × 0,25 | **0,025 kWh** |

**Plus faible consommation :** le cas **D**. On peut également donner **25 Wh**, puisque 0,025 kWh = 25 Wh.

### Questions complémentaires

**Pourquoi une puissance instantanée ne suffit-elle pas ?** Les appareils peuvent s'arrêter, se mettre en marche ou changer de puissance. Une mesure prise à un instant ne décrit pas toute la journée. Il faut suivre l'énergie sur la période ou accumuler des mesures suffisamment représentatives.

**Différence entre 500 W et 500 Wh :** 500 W expriment une **puissance active** ; 500 Wh représentent une **quantité d'énergie**. Par exemple, une puissance active constante de 500 W pendant 1 h représente 500 Wh.

**Pourquoi les minutes doivent-elles être converties ?** La formule ci-dessus suppose une durée en **heures** et une puissance en **kilowatts**. Trente minutes équivalent à **0,5 h**, pas à 30 h.

## A3 — Autoévaluation en six questions

1. **PZEM / ATmega :** le PZEM-004T est chargé de la mesure ; l'ATmega328P exécute le programme qui traite les valeurs.
2. **DS3231 :** l'horloge fournit la date et l'heure nécessaires pour attribuer des relevés aux jours et aux mois concernés. Une date manquante peut rendre le total d'une période incomplet.
3. **SIM800L :** il assure la communication via un réseau GSM/GPRS compatible. L'existence du modem ne garantit ni la disponibilité du réseau ni une transmission sécurisée déjà fonctionnelle.
4. **400 W pendant 2 h 30 :** 400 W = 0,4 kW ; 2 h 30 = 2,5 h ; 0,4 × 2,5 = **1 kWh**.
5. **Unités :** tension → volt (V), courant → ampère (A), puissance active → watt (W), énergie → wattheure (Wh) ou kilowattheure (kWh).
6. **Données fictives :** une valeur affichée à l'écran peut provenir du code d'exemple plutôt que d'un capteur. Sans vérification instrumentée, on ne peut pas la présenter comme une mesure réelle.

## A4 — Pour approfondir la correction officielle de la formation

- [TP M01 — corrigé du formateur](../../formation/modules/M01-decouverte-electricite/tp/CORRIGE_M01_FORMATEUR.md)
- [Quiz M01 — questions et justifications](../../formation/modules/M01-decouverte-electricite/quiz/QUIZ_M01.md)
- [Fiche des unités et conversions](../../formation/modules/M01-decouverte-electricite/ressources/FICHE_UNITES.md)

**Vérification des acquis :** si vous avez réussi les quatre calculs et savez expliquer l'ordre du synoptique sans lire la solution, passez au chapitre 2. Sinon, relisez les sections 1.3, 1.6, 1.7 et 1.8 du chapitre 1.
