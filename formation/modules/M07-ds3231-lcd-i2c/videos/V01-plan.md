# M07-V01 — Comprendre et utiliser le DS3231 (7 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Pour calculer la consommation de chaque jour, le compteur doit connaître la date, même lorsqu'il est redémarré. »
- Plan : rôle d'une horloge temps réel, bus I2C, SDA/SCL, alimentation, pile de sauvegarde et lecture de la date.
- Démonstration : lire une date de test et régler l'horloge.
- Erreurs : date initiale incorrecte, pile absente ou épuisée, mauvaise adresse I2C.
- Exercice : afficher la date au format JJ/MM/AAAA.
- Transition : rendre cette information visible sur un écran.

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
