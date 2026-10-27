# M13-V02 — Créer SQLite et sécuriser l'API de réception (8 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Pour conserver l'historique, nous avons besoin d'une base de données. Nous allons stocker chaque mesure de manière structurée. »
- Plan :
  1. Tables, colonnes, clés primaires et index.
  2. Concevoir les tables des appareils et des mesures.
  3. Utiliser SQLite avec des requêtes paramétrées.
  4. Valider les unités, types, dates et limites.
  5. Authentifier les équipements et protéger les secrets.
  6. Gérer les doublons avec une contrainte d'unicité.
  7. Enregistrer les erreurs.
- Démonstration : envoyer une mesure et la retrouver dans SQLite.
- Erreurs : insertion de données non validées, SQL construit par concaténation, clé d'appareil exposée.
- Exercice : rejeter une mesure invalide et une répétition de la même mesure.
- Transition : afficher ces données sur le tableau de bord.

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
