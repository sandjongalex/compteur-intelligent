# M09 — Programmer l'ATmega328P autonome par ISP

**Durée vidéo : 16 minutes** · **2 leçons** · **État : organisation prête, production à réaliser**

## Règle obligatoire : évolution du même projet

Le résultat du module précédent est **le point de départ** : le code et le système ne sont pas recommencés de zéro. Le firmware `firmware/courant/CompteurIntelligent/` doit évoluer depuis la version précédente ; publier un snapshot Mxx et actualiser le manifeste lorsque le firmware change. Les petits programmes de cours restent des exercices, et les nouveautés doivent être intégrées au projet commun et testées sans régression.

[Contrat officiel de progression continue](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md) · [Modèle d'acceptation du module](../../../docs/formation/MODELE_MODULE_EVOLUTIF.md)

## Objectif et prérequis

Objectif : comprendre le passage de l'Arduino Uno au microcontrôleur autonome. Prérequis : M03-M08. Durée : 16 minutes.

## Vidéos du module

- [M09-V01 — Construire le circuit minimal de l'ATmega328P (8 min)](videos/V01-plan.md) · [Script](scripts/V01-script.md) · [Diapositives](slides/V01-storyboard.md)
- [M09-V02 — Charger ArduinoISP et téléverser le firmware par ISP (8 min)](videos/V02-plan.md) · [Script](scripts/V02-script.md) · [Diapositives](slides/V02-storyboard.md)

## Préparer et évaluer

- [Travaux pratiques et exercices](tp/README.md)
- [Banque de quiz et objectifs de validation](quiz/README.md)
- [Supports et ressources téléchargeables](ressources/README.md)
- [Code et fichiers techniques](code/README.md)
- [Suivi de production](production/README.md)

## Indications du plan initial

**Ressources :** brochage exact du boîtier, schéma ISP, checklist de programmation et firmware de test.

**Quiz M09 :** rôle des broches, ArduinoISP, fusibles, horloge et bootloader.

**Validation :** programmer et tester la puce externe sans supposer que toutes les cartes Uno ont une puce amovible.

## Documents de référence

[Plan complet de la formation 4 h](../../../docs/formation/PLAN_FORMATION_4H.md) · [Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md)

> Les fiches vidéo reprennent le plan validé. Les scripts, slides, quiz corrigés et programmes ne sont pas présentés comme terminés tant qu'ils n'ont pas été effectivement produits et vérifiés.
