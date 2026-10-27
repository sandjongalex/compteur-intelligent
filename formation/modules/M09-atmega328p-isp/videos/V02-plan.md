# M09-V02 — Charger ArduinoISP et téléverser le firmware par ISP (8 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Nous allons utiliser une Arduino Uno comme programmateur pour envoyer un programme à un ATmega328P externe. »
- Plan :
  1. Charger l'exemple ArduinoISP sur la carte programmateur.
  2. Câbler MOSI, MISO, SCK, RESET, alimentation et masse.
  3. Sélectionner la cible, le programmateur et la configuration d'horloge.
  4. Expliquer les options de bootloader et les fusibles.
  5. Programmer le microcontrôleur par ISP.
  6. Retirer la carte de développement du montage cible.
  7. Tester le programme autonome.
  8. Distinguer cette méthode du retrait d'une puce DIP amovible d'une Uno compatible.
- Démonstration : programmer un firmware LED.
- Erreurs : mauvais RESET, configuration d'horloge incorrecte, mauvaise sélection du programmateur.
- Exercice : diagnostiquer un échec ISP.
- Transition : ajouter la communication distante.

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
