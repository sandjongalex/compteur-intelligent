# Instructions de contribution — compteur intelligent AlexTech Academy

La règle pédagogique ET technique prioritaire se trouve dans
[REGLE_EVOLUTION_CONTINUE.md](../docs/formation/REGLE_EVOLUTION_CONTINUE.md).

Le compteur est **un seul projet fil rouge** : chaque module réutilise le précédent, ajoute une capacité, conserve et revalide les acquis. Le code de travail est `firmware/courant/CompteurIntelligent/`, les versions pédagogiques sont `firmware/etapes/Mxx/` et l'état officiel est `firmware/manifest.json`.

Pour une modification firmware : snapshot nouveau + courant identique, progression, manifeste, tests, compilation Uno en simulation, sécurité basse tension. Ne pas remplacer le firmware final par un simple sketch de démonstration. Les exercices séparés sont complémentaires. Voir [AGENTS.md](../AGENTS.md) pour les consignes complètes.

**Décision matérielle M10 obligatoire :** UART matériel D0/D1 réservé au SIM800L ; PZEM sur SoftwareSerial D10/D11 ; DS3231, LCD et FRAM sur I2C A4/A5. Vérifier l'adaptation des niveaux, l'alimentation GSM et la séparation du débogage. Voir la section dédiée dans [la règle permanente](../docs/formation/REGLE_EVOLUTION_CONTINUE.md#attribution-des-interfaces-matérielles-à-partir-de-m10) et [AGENTS.md](../AGENTS.md).

Pour Python/web ou KiCad, faire évoluer le même système et ses interfaces sans créer un snapshot firmware vide. Ne pas revendiquer un essai matériel sans preuve.
