# M10-V01 — Tester le SIM800L et comprendre les commandes AT (7 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Le SIM800L est un modem : il reçoit des commandes, communique avec le réseau mobile et retourne des réponses. »
- Plan : GSM, GPRS, carte SIM, antenne, UART, commandes AT, réponses et états du modem.
- Démonstration : simulation de AT, AT+CPIN?, AT+CSQ et AT+CREG?.
- Point critique : le SIM800L nécessite une alimentation adaptée, généralement autour de 4 V selon le module, avec une capacité suffisante pour ses pointes de courant pouvant approcher 2 A. Vérifier la fiche exacte du fabricant.
- Erreurs : alimentation 5 V directe non autorisée, mauvais débit série, SIM verrouillée.
- Exercice : interpréter une réponse réseau.
- Transition : préparer l'envoi de données au serveur.

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
