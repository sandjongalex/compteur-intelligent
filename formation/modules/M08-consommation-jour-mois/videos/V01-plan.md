# M08-V01 — Calculer l'énergie et comprendre les index (8 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Une mesure instantanée ne suffit pas pour connaître l'énergie consommée pendant une journée. Il faut exploiter un index énergétique et ses variations. »
- Plan :
  1. Différence entre puissance instantanée et énergie cumulée.
  2. Lire l'index énergétique du PZEM.
  3. Calculer un delta entre deux index successifs.
  4. Cumuler les deltas pour la journée et le mois.
  5. Éviter les doubles comptages.
  6. Détecter un index réinitialisé ou devenu incohérent.
- Exemple : index initial de 120,400 kWh, puis 120,650 kWh : différence de 0,250 kWh.
- Démonstration : calcul sur des relevés fictifs.
- Erreurs : additionner plusieurs fois l'index total, accepter aveuglément un index qui diminue.
- Exercice : calculer les deltas sur cinq relevés.
- Transition : traiter les changements de date et les interruptions.

## Préparation et fichiers liés

- [Texte du formateur](../scripts/V01-script.md)
- [Storyboard des diapositives](../slides/V01-storyboard.md)
- [Travaux pratiques](../tp/README.md)
- [Quiz](../quiz/README.md)

## Critères de qualité

- [ ] La vidéo tient dans le créneau prévu du module.
- [ ] Chaque terme technique nouveau est expliqué.
- [ ] Les captures, illustrations et démonstrations correspondent au plan.
- [ ] Le résultat attendu et une erreur fréquente sont montrés.
- [ ] L'exercice est faisable avec les ressources fournies.
- [ ] La sécurité est validée avant les manipulations matérielles.
