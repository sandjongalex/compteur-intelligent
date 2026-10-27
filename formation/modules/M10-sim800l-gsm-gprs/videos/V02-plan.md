# M10-V02 — Transmettre une mesure par GPRS et traiter les erreurs (7 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Une connexion mobile peut échouer ou disparaître. Nous allons organiser la transmission pour que l'application détecte les erreurs. »
- Plan : APN, session GPRS, requête HTTP de laboratoire, code de réponse, délai d'attente, nouvelle tentative et fermeture de session.
- Démonstration : requête vers un serveur de test et lecture de la réponse.
- Sécurité : HTTP non chiffré uniquement dans un environnement de laboratoire isolé. Ne jamais transmettre de secrets par HTTP sur Internet en production.
- Limites : le SIM800L est un modem 2G ancien ; la disponibilité du réseau dépend de l'opérateur. Ses capacités TLS sont limitées et doivent être vérifiées.
- Exercice : interpréter un échec de connexion.
- Transition : préparer une transmission qui ne perde pas les relevés.

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
