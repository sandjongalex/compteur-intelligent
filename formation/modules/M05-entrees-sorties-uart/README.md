# Module M05 — Entrées, sorties et communications série

**18 minutes de vidéo : deux démonstrations pratiques de 9 minutes.** Prérequis : M03–M04.

## Nouvelle méthode : apprendre en programmant, sans PowerPoint

Le module commence par un **résultat visible**, puis construit le code par étapes. À chaque étape, l'apprenant doit comprendre la ligne, prédire la sortie, tester et diagnostiquer les erreurs fréquentes.

| Vidéo | Durée | Démonstration pratique |
|---|---:|---|
| [M05-V01](videos/V01-plan.md) — Lire un bouton et commander une sortie | 9 min | Bouton sur D2, LED intégrée, résistance de rappel et anti-rebond |
| [M05-V02](videos/V02-plan.md) — UART et temporisation non bloquante | 9 min | Moniteur série, commandes et affichage périodique avec `millis()` |

## Livrables prioritaires

1. [Scripts synchronisés avec la démonstration](../../modeles/SCRIPT_DEMONSTRATION_CODE.md) : paroles, gestes à l'écran, extraits du code.
2. [Code Arduino](code/) : petits projets séparés et commentés, résultats attendus, tests sur Uno.
3. [Exercices et défis](tp/) : énoncés apprenant et corrigés formateur séparés.
4. [Quiz](quiz/) : dix questions incluant lecture de code et diagnostic, corrigé argumenté.
5. [Ressources](ressources/) : câblage basse tension, tableaux de broches, aide au dépannage.
6. [Suivi des tests et tournage](production/) : preuve des validations réelles.

**Aucun nouveau diaporama n'est prévu.** Les sous-dossiers `slides/` existants restent archivés pour ne pas supprimer de documents antérieurs.

## Critères de validation pédagogique

- Réaliser un appui bouton sûr sur Uno et expliquer `INPUT_PULLUP`.
- Comprendre qu'une entrée peut commander une sortie.
- Comprendre le principe RX/TX et le moniteur série.
- Utiliser une temporisation avec `millis()` sans bloquer les commandes.
- Modifier un programme et expliquer le résultat.
- Réussir le quiz avec **8/10** et les TP.

**Sécurité :** les démonstrations utilisent uniquement l'USB/basse tension. Aucun essai secteur pour les débutants.

[Guide pédagogique actualisé](../../GUIDE_PEDAGOGIQUE.md) · [Programme général](../../../docs/formation/PLAN_FORMATION_4H.md)
