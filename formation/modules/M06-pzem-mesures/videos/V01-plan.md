# M06-V01 — Comprendre le PZEM et Modbus RTU (8 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Plutôt que de construire nous-mêmes un circuit de mesure du secteur, nous utilisons un module spécialisé qui fournit des valeurs numériques. »
- Plan :
  1. Présenter le PZEM-004T V3.0 et son transformateur de courant compatible.
  2. Expliquer mesure de tension, courant, puissance, fréquence, facteur de puissance et énergie.
  3. Présenter UART et Modbus RTU.
  4. Expliquer requête, adresse, registre et réponse.
  5. Distinguer la mesure physique de son interprétation logicielle.
- Visuels : architecture Modbus et exemple de trame.
- Démonstration : lecture d'une trame simulée.
- Erreurs : utiliser la documentation d'une autre version du PZEM, confondre données brutes et unités.
- Exercice : associer chaque registre documenté à sa grandeur.
- Transition : lire les valeurs avec le firmware.

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
