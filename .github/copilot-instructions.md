# Instructions de contribution — compteur intelligent AlexTech Academy

La règle pédagogique ET technique prioritaire se trouve dans
[REGLE_EVOLUTION_CONTINUE.md](../docs/formation/REGLE_EVOLUTION_CONTINUE.md).

Le compteur est **un seul projet fil rouge** : chaque module réutilise le précédent, ajoute une capacité, conserve et revalide les acquis. Le code de travail est `firmware/courant/CompteurIntelligent/`, les versions pédagogiques sont `firmware/etapes/Mxx/` et l'état officiel est `firmware/manifest.json`.

Pour une modification firmware : snapshot nouveau + courant identique, progression, manifeste, tests, compilation Uno en simulation, sécurité basse tension. Ne pas remplacer le firmware final par un simple sketch de démonstration. Les exercices séparés sont complémentaires. Voir [AGENTS.md](../AGENTS.md) pour les consignes complètes.

Pour Python/web ou KiCad, faire évoluer le même système et ses interfaces sans créer un snapshot firmware vide. Ne pas revendiquer un essai matériel sans preuve.
