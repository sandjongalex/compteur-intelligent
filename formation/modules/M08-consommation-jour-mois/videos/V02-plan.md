# M08-V02 — Gérer minuit, les mois, les années et les redémarrages (8 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Un compteur fiable doit continuer à calculer correctement après une coupure de courant ou un changement de mois. »
- Plan :
  1. Associer chaque relevé à un horodatage.
  2. Détecter le changement de jour et de mois.
  3. Clôturer une période sans effacer l'index global du PZEM.
  4. Sauvegarder les derniers index et les cumuls.
  5. Traiter une coupure où aucune mesure n'est disponible.
  6. Repartir d'un état sauvegardé après redémarrage.
- Démonstration : simulation du passage du 31 janvier au 1er février.
- Erreurs : remise à zéro de l'index total, confusion entre absence de mesure et consommation nulle.
- Exercice : compléter une table de consommation quotidienne.
- Transition : conserver cette logique sur un microcontrôleur autonome.

## Préparation et fichiers liés

- [Texte du formateur](../scripts/V02-script.md)
- [Storyboard des diapositives](../slides/V02-storyboard.md)
- [Travaux pratiques](../tp/README.md)
- [Quiz](../quiz/README.md)

## Critères de qualité

- [ ] La vidéo tient dans le créneau prévu du module.
- [ ] Chaque terme technique nouveau est expliqué.
- [ ] Les captures, illustrations et démonstrations correspondent au plan.
- [ ] Le résultat attendu et une erreur fréquente sont montrés.
- [ ] L'exercice est faisable avec les ressources fournies.
- [ ] La sécurité est validée avant les manipulations matérielles.
