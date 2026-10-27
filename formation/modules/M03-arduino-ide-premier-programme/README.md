# M03 — Installer Arduino IDE et programmer sa première LED

**AlexTech Academy : 14 minutes de vidéo (2 × 7 minutes)** · **Arduino Uno Rev3** · **Débutant après M01 et M02**.

## Objectif

À la fin du module, l'apprenant peut installer Arduino IDE 2, choisir une Uno/son port, vérifier et téléverser un programme, comprendre `setup()` et `loop()`, faire clignoter une LED interne et externe, puis modifier les durées ON/OFF.

## Leçons et préparation

| Leçon | Vidéo cible | Script oral | Storyboard |
|---|---:|---|---|
| M03-V01 — Installer Arduino IDE et comprendre la compilation | 7 min | [Script](scripts/V01-script.md) | [Slides](slides/V01-storyboard.md) |
| M03-V02 — Faire clignoter une LED avec Arduino Uno | 7 min | [Script](scripts/V02-script.md) | [Slides](slides/V02-storyboard.md) |

## Ressources pour débutants

- [Guide installation Arduino IDE 2](ressources/INSTALLATION_ARDUINO_IDE.md).
- [Schéma LED sur D8 avec résistance](ressources/SCHEMA_LED.md).
- [Guide de dépannage](ressources/DEPANNAGE.md).
- [Quatre sketches Arduino de démonstration](code/README.md).
- [Énoncés des deux TP](tp/TP_M03_APPRENANT.md).
- [Quiz apprenant de 10 questions](quiz/QUIZ_M03_APPRENANT.md).

## Documents formateur

- [Corrigés et barèmes des TP](tp/CORRIGE_M03_FORMATEUR.md).
- [Corrigé expliqué du quiz](quiz/CORRIGE_M03_FORMATEUR.md).
- [QCM JSON](quiz/quiz_m03.json).
- [Suivi de production](production/README.md).

## Présentations PowerPoint

- [Suivi des deux PowerPoint réalisés](slides/PRESENTATIONS_MODULE03.md) : 8 diapositives par vidéo, binaires fournis séparément dans la conversation.

## Statut réel

Scripts, exercices, quiz et code pédagogique **rédigés** ; les PowerPoint ont été contrôlés au rendu ; les programmes doivent encore être compilés et téléversés sur une vraie carte. **Tu assures l'enregistrement et la publication**.

La LED externe est un montage **basse tension uniquement**, sans secteur, PZEM ni SIM800L.

[Retour à la formation](../../README.md) · [Plan global](../../../docs/formation/PLAN_FORMATION_4H.md)


## Développement continu du même compteur

[**Ouvrir le firmware fil rouge**](../../../firmware/etapes/M03/Compteur_M03/Compteur_M03.ino) : cette **première version du projet principal** fait clignoter la LED intégrée. C'est ce même programme qui sera ensuite structuré en M04, puis enrichi à chaque module. Les petits sketches restent disponibles comme exercices complémentaires.
