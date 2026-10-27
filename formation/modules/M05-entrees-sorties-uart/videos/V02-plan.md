# M05-V02 — Comprendre l'UART et les temporisations non bloquantes (9 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Le microcontrôleur doit communiquer avec plusieurs modules. Nous allons découvrir comment les appareils échangent des caractères et des données. »
- Plan :
  1. Communication série et transmission bit par bit.
  2. TX, RX, débit en bauds et format des trames.
  3. Serial.begin(), Serial.print() et Serial.available().
  4. Lecture progressive des caractères.
  5. Limites de delay() et principe de millis().
  6. Gestion du temps et des tâches périodiques.
- Démonstration : envoyer une valeur simulée et la lire sur le moniteur série.
- Erreurs : TX/RX inversés, débits différents, attente bloquante.
- Exercice : afficher une mesure toutes les secondes sans bloquer le programme.
- Transition : remplacer la mesure fictive par une mesure du PZEM.

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
