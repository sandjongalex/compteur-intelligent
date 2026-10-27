# M11 — Sauvegarder les relevés et synchroniser après une panne

**Durée vidéo : 16 minutes** · **2 leçons** · **État : organisation prête, production à réaliser**

## Règle obligatoire : évolution du même projet

Le résultat du module précédent est **le point de départ** : le code et le système ne sont pas recommencés de zéro. Le firmware `firmware/courant/CompteurIntelligent/` doit évoluer depuis la version précédente ; publier un snapshot Mxx et actualiser le manifeste lorsque le firmware change. Les petits programmes de cours restent des exercices, et les nouveautés doivent être intégrées au projet commun et testées sans régression.

[Contrat officiel de progression continue](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md) · [Modèle d'acceptation du module](../../../docs/formation/MODELE_MODULE_EVOLUTIF.md)

## Objectif et prérequis

Objectif : assurer la continuité des données. Prérequis : M08-M10. Durée : 16 minutes.

## Vidéos du module

- [M11-V01 — Utiliser une FRAM pour conserver les relevés (8 min)](videos/V01-plan.md) · [Script](scripts/V01-script.md) · [Diapositives](slides/V01-storyboard.md)
- [M11-V02 — Reprendre les envois sans doublons (8 min)](videos/V02-plan.md) · [Script](scripts/V02-script.md) · [Diapositives](slides/V02-storyboard.md)

## Préparer et évaluer

- [Travaux pratiques et exercices](tp/README.md)
- [Banque de quiz et objectifs de validation](quiz/README.md)
- [Supports et ressources téléchargeables](ressources/README.md)
- [Code et fichiers techniques](code/README.md)
- [Suivi de production](production/README.md)

## Indications du plan initial

**Ressources :** format d'enregistrement, simulateur réseau, diagramme de synchronisation et scénarios de panne.

**Quiz M11 :** FRAM, identifiants uniques, file d'attente, confirmation et idempotence.

**Validation :** réussir une simulation de perte réseau puis de synchronisation sans doublon.

## Documents de référence

[Plan complet de la formation 4 h](../../../docs/formation/PLAN_FORMATION_4H.md) · [Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md)

> Les fiches vidéo reprennent le plan validé. Les scripts, slides, quiz corrigés et programmes ne sont pas présentés comme terminés tant qu'ils n'ont pas été effectivement produits et vérifiés.
