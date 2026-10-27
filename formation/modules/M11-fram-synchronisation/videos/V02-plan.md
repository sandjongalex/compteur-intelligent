# M11-V02 — Reprendre les envois sans doublons (8 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Une réponse du serveur peut être perdue alors que la mesure a bien été enregistrée. Il faut donc rendre les envois répétables sans créer de doublons. »
- Plan :
  1. Créer une file d'attente locale.
  2. Marquer les relevés en attente, envoyés ou confirmés.
  3. Retenter une transmission avec temporisation.
  4. Utiliser un identifiant unique de mesure.
  5. Faire vérifier cet identifiant par le serveur.
  6. Supprimer ou libérer un enregistrement seulement après confirmation.
- Démonstration : couper artificiellement la connexion dans un simulateur.
- Erreurs : effacer un relevé avant l'accusé de réception, confondre succès HTTP et insertion effective.
- Exercice : prévoir le résultat de trois tentatives de transmission.
- Transition : développer le serveur qui reçoit ces données.

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
