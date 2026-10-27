# M04 — Présentations PowerPoint réalisées

**Deux fichiers PPTX modifiables (format 16:9), 8 diapositives chacun, avec 8 notes formateur dans chaque présentation.**

| Vidéo | Fichier | Contenu |
|---|---|---|
| M04-V01, 7 min | `AlexTech_M04_V01_Variables_Calculs.pptx` | Variables, types, constantes, mémoire AVR, énergie simulée, moniteur série, division entière, exercice |
| M04-V02, 7 min | `AlexTech_M04_V02_Conditions_Boucles_Fonctions.pptx` | Conditions, `=` / `==`, boucles `for` et `while`, fonction de conversion, exercice |

Les PowerPoint ont été **générés et livrés en téléchargement dans la conversation ChatGPT**, avec leur **script de génération JavaScript**, leurs aperçus et une archive ZIP. **Les binaires ne sont pas encore hébergés dans GitHub** : cet inventaire n'est pas un lien de téléchargement direct des `.pptx`.

## Liens GitHub utiles

- [Storyboard M04-V01](V01-storyboard.md) et [script formateur](../scripts/V01-script.md)
- [Storyboard M04-V02](V02-storyboard.md) et [script formateur](../scripts/V02-script.md)
- [Exemples Arduino `.ino`](../code/README.md)
- [Mémo C++](../ressources/MEMO_CPP.md)
- [Quiz et corrigés](../quiz/README.md)
- [TP et corrigés](../tp/README.md)

## Contrôles réalisés

- [x] Présentations 16:9, 8 diapositives par cours, texte modifiable.
- [x] Notes du formateur dans les 16 diapositives.
- [x] Rendu vérifié dans LibreOffice et ajustement de la police de code.
- [x] Analyse des débordements : **aucun débordement détecté** pour les deux présentations.
- [x] Vérification basique de la syntaxe C++ de cinq exemples sous un compilateur générique avec **simulacre d'interface Arduino** ; ce contrôle **n'est pas** une compilation Arduino officielle.
- [ ] Compiler et téléverser dans un véritable Arduino IDE 2 sur Uno Rev3, tester les sorties.
- [ ] Confirmer les deux durées de 7 minutes après répétition à voix haute.
- [ ] Ajouter les `.pptx` dans `slides/` via « Add file > Upload files » si souhaité.
- [ ] Enregistrer, monter et publier les cours (formateur).

## Précautions

Les valeurs de tension et d'énergie dans ce module sont **fictives**. Les `int` 16 bits et `float` 32 bits sont caractéristiques de la **Uno Rev3 avec AVR ATmega328P**, pas nécessairement de toutes les autres cartes Arduino.
