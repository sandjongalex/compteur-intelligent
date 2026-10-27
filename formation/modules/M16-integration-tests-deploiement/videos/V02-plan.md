# M16-V02 — Déployer Flask sur PythonAnywhere et valider le projet (7 min)

> **État : plan pédagogique détaillé disponible**. Script intégral et ressources de tournage à finaliser.


- Introduction : « Nous allons rendre le tableau de bord accessible en ligne et vérifier les conditions de son exploitation. »
- Plan : préparer l'application, configurer l'environnement, déployer Flask, configurer les variables secrètes, vérifier les journaux, tester SQLite et les requêtes.
- Démonstration : déploiement d'une application de test et consultation du tableau de bord.
- Points critiques : vérifier les restrictions réseau du forfait PythonAnywhere, les possibilités de connexion sortante, le HTTPS, les limites de stockage et les règles d'exécution. Ne pas supposer qu'un forfait donné autorise toutes les connexions nécessaires.
- Erreurs : dépendance manquante, mauvais chemin WSGI, secrets dans le code source, base de données inaccessible.
- Exercice : remplir une checklist de mise en production.
- Résultat final : architecture comprise, serveur de test accessible et plan de validation documenté.

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
