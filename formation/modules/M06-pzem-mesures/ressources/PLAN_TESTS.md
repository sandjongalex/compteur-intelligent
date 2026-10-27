# M06 — Plan de tests avant enregistrement

**Statut initial : compilation Arduino IDE, téléversement et mesures réelles NON encore vérifiés.**

## Conditions

- Uno Rev3, IDE 2, USB de données, moniteur série **9600 bauds**.
- V01-01, V01-02, V02-01, V02-02, TP01 et TP02 : **aucun PZEM ni secteur nécessaire**.
- V02-03 : réservé à un **banc sécurisé conçu, monté et utilisé par une personne qualifiée**.

| Test | Programme | Résultat attendu | Vérifié ? |
|---|---|---|---|
| T01 | V01-01 | Six valeurs explicitement simulées | [ ] |
| T02 | V01-02 | 230.5 V ; 0.500 A ; 92.2 W ; 12.345 kWh ; 50.0 Hz ; PF 0.80 | [ ] |
| T03 | V02-01 | Ligne fictive périodique ~2 s | [ ] |
| T04 | V02-02 | Succès → erreur sans mesure → succès | [ ] |
| T05 | TP01 | 231.2 V ; 0.750 A ; 138.8 W ; 15.300 kWh ; 50.1 Hz ; PF 0.80 | [ ] |
| T06 | TP02 | Lecture invalide signalée, pas de valeur inventée | [ ] |
| T07 | V02-03 | Six grandeurs plausibles ou statut INVALIDE, **banc qualifié seulement** | [ ] |

Pour la compilation, utiliser Arduino IDE 2 avec le cœur **Arduino AVR Boards / Uno**. Pour V02-03, installer **PZEM004Tv30** et vérifier la compatibilité exacte de son API. Compiler l'exemple ne prouve pas une mesure physique.

## Compte rendu formateur à compléter

- Date :
- Version de l'IDE / du cœur AVR :
- Version de la bibliothèque :
- Référence exacte du PZEM :
- Tests réussis :
- Captures des sorties série :
- Erreurs constatées :
- Personne qualifiée responsable du banc, le cas échéant :
- Décision : prêt à filmer / corrections nécessaires.

**Aucune case n'est cochée sans preuve.** Aucun apprenant novice ne doit manipuler le secteur pour passer ces tests.
