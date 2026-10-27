# M06-V02 — Lire et vérifier les mesures avec Arduino IDE (8 minutes)

**Statut : script complet et trois étapes de code rédigés ; les essais réels sont encore à effectuer.**

## Progression : lire → simuler une panne → valider → préparer un banc

| Moment | Action à l'écran | Ressource |
|---|---|---|
| 00:00–00:55 | Montrer le résultat « OK → ERREUR → OK » simulé | [V02-02](../code/V02_02_detection_panne_simulee/V02_02_detection_panne_simulee.ino) |
| 00:55–02:10 | Construire une structure, `lireSimulation`, afficher périodiquement | [V02-01](../code/V02_01_lecture_simulee/V02_01_lecture_simulee.ino) |
| 02:10–03:25 | Démontrer `return false`, ne publier aucune valeur fictive en échec | [V02-02](../code/V02_02_detection_panne_simulee/V02_02_detection_panne_simulee.ino) |
| 03:25–04:40 | Comprendre `PZEM004Tv30`, ses méthodes et les limites de l'Uno | [Bibliothèque V3](https://github.com/mandulaj/PZEM-004T-v30) |
| 04:40–06:10 | Expliquer les appels et la validation des six mesures | [V02-03, banc qualifié seulement](../code/V02_03_pzem_reel_qualifie/V02_03_pzem_reel_qualifie.ino) |
| 06:10–07:05 | Diagnostiquer une absence de réponse sans manipuler le secteur | [Dépannage](../ressources/DEPANNAGE.md) |
| 07:05–08:00 | Mini-défi : distinguer zéro réel et lecture manquante | [TP02](../tp/TP_M06_APPRENANT.md) |

**[Lire le script oral intégral](../scripts/V02-script.md).** Le temps est une cible de montage.

**Sécurité :** la première partie se fait sans PZEM. La lecture physique V02-03 **n'est pas un tutoriel de branchement secteur** : elle est optionnelle pour les apprenants et réservée à une personne qualifiée qui exploite un banc sécurisé.

Le résultat de `pzem.energy()` est **l'index cumulé**, pas l'énergie d'une journée.
