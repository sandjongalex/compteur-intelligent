# M13 — Construire le backend Flask et la base SQLite

**Durée vidéo : 16 minutes** · **2 leçons** · **État : organisation prête, production à réaliser**

## Règle obligatoire : évolution du même projet

Le résultat du module précédent est **le point de départ** : le code et le système ne sont pas recommencés de zéro. Faire évoluer la **même application Python/Flask** et préserver le format des données et les échanges avec le compteur ; ne pas créer un faux changement Arduino. Les petits programmes de cours restent des exercices, et les nouveautés doivent être intégrées au projet commun et testées sans régression.

[Contrat officiel de progression continue](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md) · [Modèle d'acceptation du module](../../../docs/formation/MODELE_MODULE_EVOLUTIF.md)

## Objectif et prérequis

Objectif : créer une API de réception et enregistrer les mesures. Prérequis : M12. Durée : 16 minutes.

## Vidéos du module

- [M13-V01 — Créer une application Flask et comprendre HTTP (8 min)](videos/V01-plan.md) · [Script](scripts/V01-script.md) · [Diapositives](slides/V01-storyboard.md)
- [M13-V02 — Créer SQLite et sécuriser l'API de réception (8 min)](videos/V02-plan.md) · [Script](scripts/V02-script.md) · [Diapositives](slides/V02-storyboard.md)

## Préparer et évaluer

- [Travaux pratiques et exercices](tp/README.md)
- [Banque de quiz et objectifs de validation](quiz/README.md)
- [Supports et ressources téléchargeables](ressources/README.md)
- [Code et fichiers techniques](code/README.md)
- [Suivi de production](production/README.md)

## Indications du plan initial

**Ressources :** squelette Flask, script SQL, exemple JSON, guide d'authentification.

**Quiz M13 :** routes, HTTP, schéma SQL, validation, authentification et idempotence.

**Validation :** recevoir et stocker une mesure, puis traiter correctement une requête répétée.

## Documents de référence

[Plan complet de la formation 4 h](../../../docs/formation/PLAN_FORMATION_4H.md) · [Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md)

> Les fiches vidéo reprennent le plan validé. Les scripts, slides, quiz corrigés et programmes ne sont pas présentés comme terminés tant qu'ils n'ont pas été effectivement produits et vérifiés.
