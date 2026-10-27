# M01-V01 — Du réseau électrique au tableau de bord IoT (5 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Objectif pédagogique : comprendre le trajet d'une mesure depuis le circuit électrique jusqu'au navigateur.
- Introduction à prononcer : « Imaginez que vous puissiez consulter à distance la consommation électrique d'une installation, connaître son historique et détecter une anomalie. Nous allons construire un système qui rend cela possible. »
- Plan détaillé :
  1. Définir un compteur et un système de supervision.
  2. Distinguer mesure, calcul, stockage et affichage.
  3. Présenter le rôle du PZEM, de l'ATmega328P, du SIM800L et du serveur.
  4. Montrer le parcours des données : mesure → microcontrôleur → réseau → base de données → navigateur.
- Analogie : le PZEM est le capteur, l'ATmega328P est le gestionnaire, le réseau est le transporteur et le serveur est l'archiviste.
- Visuels : synoptique animé et photo des principaux modules.
- Démonstration : afficher une mesure fictive de 230,5 V et suivre son parcours jusqu'à une page web.
- Erreurs à expliquer : confondre capteur, calculateur et serveur.
- Résultat attendu : l'apprenant peut expliquer le rôle de chaque bloc.
- Mini-exercice : remettre les cinq blocs du système dans le bon ordre.
- Transition : avant de mesurer, il faut comprendre ce que signifient les valeurs électriques.

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
