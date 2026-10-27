# M10 — Communiquer avec le SIM800L par GSM/GPRS

**Durée vidéo : 14 minutes** · **2 leçons** · **État : organisation prête, production à réaliser**

## Règle obligatoire : évolution du même projet

Le résultat du module précédent est **le point de départ** : le code et le système ne sont pas recommencés de zéro. Le firmware `firmware/courant/CompteurIntelligent/` doit évoluer depuis la version précédente ; publier un snapshot Mxx et actualiser le manifeste lorsque le firmware change. Les petits programmes de cours restent des exercices, et les nouveautés doivent être intégrées au projet commun et testées sans régression.

[Contrat officiel de progression continue](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md) · [Modèle d'acceptation du module](../../../docs/formation/MODELE_MODULE_EVOLUTIF.md)

## Objectif et prérequis

Objectif : comprendre le modem et les commandes AT. Prérequis : M05 et M09. Durée : 14 minutes.

## Vidéos du module

- [M10-V01 — Tester le SIM800L et comprendre les commandes AT (7 min)](videos/V01-plan.md) · [Script](scripts/V01-script.md) · [Diapositives](slides/V01-storyboard.md)
- [M10-V02 — Transmettre une mesure par GPRS et traiter les erreurs (7 min)](videos/V02-plan.md) · [Script](scripts/V02-script.md) · [Diapositives](slides/V02-storyboard.md)

## Préparer et évaluer

- [Travaux pratiques et exercices](tp/README.md)
- [Banque de quiz et objectifs de validation](quiz/README.md)
- [Supports et ressources téléchargeables](ressources/README.md)
- [Code et fichiers techniques](code/README.md)
- [Suivi de production](production/README.md)

## Indications du plan initial

**Ressources :** catalogue de commandes AT, fiche d'alimentation, APN fictif de test et scripts de simulation.

**Quiz M10 :** UART, SIM, APN, réponses AT, GPRS et sécurité.

**Validation :** expliquer le cycle de connexion et identifier une panne sans mettre le modem en danger.

## Documents de référence

[Plan complet de la formation 4 h](../../../docs/formation/PLAN_FORMATION_4H.md) · [Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md)

> Les fiches vidéo reprennent le plan validé. Les scripts, slides, quiz corrigés et programmes ne sont pas présentés comme terminés tant qu'ils n'ont pas été effectivement produits et vérifiés.
