# Compte rendu de relecture — Chapitre M01 (production interne)

**Document interne, exclu de la composition du livre**  
**Date de la première relecture :** 28 octobre 2026  
**Ouvrage :** *Concevez votre compteur électrique intelligent IoT* — AlexTech Academy  
**Périmètre :** [chapitre 1](chapitres/01-decouvrir-le-compteur-et-comprendre-l-electricite.md), [annexe des corrigés](annexes/CORRIGE_M01.md) et correspondance avec les ressources M01.

## Synthèse

La relecture initiale du chapitre M01 a été effectuée **dans le dépôt GitHub**, avec vérification de la cohérence par rapport au plan de la formation, aux scripts vidéo, aux supports de débutant et aux règles techniques du projet.

**Conclusion :** le chapitre conserve les deux parties M01-V01 et M01-V02, les calculs didactiques et le parcours du relevé. Des corrections de mise en forme, de cohérence matérielle et de présentation des exercices ont été enregistrées. Il reste à obtenir la validation éditoriale finale de l'auteur, à contrôler la mise en page des figures et à faire relire le texte par un apprenant débutant.

## Points examinés et résultats

| Axe | Vérification | Résultat |
|---|---|---|
| Programme | Deux vidéos M01-V01 et M01-V02 représentées dans l'ordre | Conforme au programme officiel |
| Pédagogie | Départ par un objectif concret, architecture expliquée, exemples guidés, activités et autoévaluation | Conforme pour une première rédaction |
| Mesures | Distinction entre V, A, W, Wh, kWh ; hypothèse de puissance active constante | Conforme |
| Calculs | 500 W × 4 h = 2 kWh ; 2 000 W × 0,5 h = 1 kWh ; 200 W × 5 h = 1 kWh ; 100 W × 0,25 h = 0,025 kWh | Résultats cohérents |
| Index d'énergie | 1 254,75 − 1 250,50 = 4,25 kWh ; 1 254,75 − 1 129,27 = 125,48 kWh | Résultats cohérents |
| Matériel | Architecture PZEM, ATmega328P, RTC, LCD, FRAM, modem et serveur correctement distinguée | Conforme au synoptique prévu |
| Statut des travaux | GSM/FRAM/serveur décrits comme objectifs et non comme fonctions déjà réalisées | Conforme au firmware M09 |
| Sécurité | Pas de TP de raccordement au secteur ; réserves sur le prototype pédagogique | Conforme au périmètre M01 |
| Présentation LCD | Quatre lignes de **20 caractères** entre les bordures | Corrigé |
| Exercices | Solutions déplacées hors du chapitre vers une annexe accessible après la tentative | Corrigé |
| Titres | Hiérarchie structurée : chapitre → parties → sections → sous-sections | Corrigé |
| Transmission | Clarification : le GPRS seul ne garantit pas la sécurité des données | Corrigé |

## Changements apportés

### 1. Maquette LCD 20×4

La première version comportait **21 caractères par ligne**, bien que l'illustration soit annoncée comme un afficheur 20×4. Les quatre chaînes ont été ajustées à **20 caractères utiles par ligne**, plus les deux bordures du dessin.

### 2. Corrigés des travaux pratiques

Le chapitre montrait directement les solutions sous une section déroulante. Pour ne pas perturber l'apprentissage, les réponses ont été déplacées dans [une annexe distincte](annexes/CORRIGE_M01.md), avec les calculs intermédiaires, les causes d'erreur typiques et les réponses à l'autoévaluation.

L'annexe est publique comme le dépôt ; « distincte » ne signifie pas « inaccessible » ou « protégée contre les consultations anticipées ».

### 3. Sécurité des communications

Le synoptique GSM → Flask est un **trajet logique** : il ne valide pas la disponibilité du réseau, les réglages du modem ni la sécurité du canal. Le chapitre indique maintenant explicitement que la confidentialité et l'authenticité de la transmission exigent un mécanisme protégé à valider, éventuellement une passerelle.

### 4. Distinction FRAM et réalisation effective

La FRAM est expliquée comme une mémoire non volatile, mais la conservation correcte des relevés dépend de l'écriture et de la gestion des interruptions d'alimentation par le firmware. Le texte n'annonce pas une fonction M11 déjà opérationnelle.

### 5. Navigation et hiérarchie

Les titres ont été normalisés. Après retour de l'auteur, les liens de développement et les statuts temporaires ont été retirés des pages destinées au lecteur. Les renvois techniques demeurent uniquement dans les documents de contrôle internes.

## Modification après retour de l'auteur : diffusion hors GitHub

Le dépôt ne sert qu'à la production. Le livre et les vidéos seront distribués ailleurs. L'avant-propos, le chapitre 1 et l'annexe A sont désormais rédigés sans liens GitHub ni références à l'état temporaire du dépôt. Le sommaire du livre et le manifeste de production différencient clairement les pages à publier des documents de travail.

## Points nécessitant encore une validation

- [ ] **Auteur :** confirmer le style final, le niveau de vulgarisation et le choix des termes de l'ouvrage.
- [ ] **Illustrations :** produire et vérifier le schéma éditorial final, au-delà du diagramme Mermaid.
- [ ] **Mise en page :** contrôler le rendu A4 et/ou du format imprimé, les tableaux, les légendes et les renvois.
- [ ] **Test pédagogique :** faire lire le chapitre à une personne débutante et consigner les incompréhensions éventuelles.
- [ ] **Avant publication commerciale :** effectuer la vérification finale des informations réglementaires et des droits des images ajoutées.

**Aucun test matériel, compilation de firmware ou essai sur le réseau 230 V n'a été réalisé pendant cette relecture : seules des modifications de documentation sont concernées.**

## Sources de référence

- [Programme officiel 4 h et vidéos M01](../docs/formation/PLAN_FORMATION_4H.md)
- [Guide de conception pédagogique](../formation/GUIDE_PEDAGOGIQUE.md)
- [Scripts et ressources du module M01](../formation/modules/M01-decouverte-electricite/README.md)
- [Règle du projet fil rouge](../docs/formation/REGLE_EVOLUTION_CONTINUE.md)
- [État du firmware](../firmware/PROGRESSION.md)

[← Revenir au sommaire](README.md)
