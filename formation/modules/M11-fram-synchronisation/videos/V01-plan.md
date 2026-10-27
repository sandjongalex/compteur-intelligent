# M11-V01 — Utiliser une FRAM pour conserver les relevés (8 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Si le réseau disparaît, le compteur doit continuer à enregistrer les relevés au lieu de les perdre. »
- Plan :
  1. Différence entre RAM et mémoire non volatile.
  2. Présenter la FRAM externe et son interface.
  3. Expliquer les adresses, enregistrements et versions de données.
  4. Définir un identifiant unique pour chaque relevé.
  5. Prévoir capacité, durée de conservation et stratégie de mémoire pleine.
- Démonstration : écrire puis relire des relevés simulés.
- Erreurs : débordement de mémoire, format de données instable, écrasement d'enregistrements non envoyés.
- Exercice : estimer l'espace nécessaire pour une journée de relevés.
- Transition : retransmettre les enregistrements en attente.

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
