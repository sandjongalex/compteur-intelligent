# Guide pédagogique — AlexTech Academy, compteur intelligent

## Contrat de formation

- **4 heures maximum de vidéo**, réparties sur 16 modules et 32 vidéos techniques, plus accueil et conclusion.
- Formation **accélérée et guidée** : un débutant peut suivre les démonstrations, mais l'autonomie exige des TP supplémentaires hors vidéo.
- **Nouvelle règle à partir de M05 : pas de production de PowerPoint**. Le cours est porté par les prises de vue du matériel, Arduino IDE, le terminal Python, les interfaces web et de courts schémas techniques seulement lorsque nécessaires.
- **L'enregistrement, le montage vidéo et la publication sont assurés par le formateur**. Le dépôt contient la conception : scripts, code, fiches d'exercices, quiz et ressources.
- Les anciens PowerPoint M01 à M04 restent des archives existantes ; cette règle n'impose pas de les retirer.

## Adapter la pédagogie à la nature du module

| Famille | Modules concernés | Méthode principale | Preuve d'apprentissage |
|---|---|---|---|
| Compréhension / matériel / sécurité | M01–M02 et segments de M15 | objet réel hors tension, analogie, schéma fonctionnel, identification | expliquer le rôle, repérer une erreur ou danger |
| Programmation embarquée | M03–M11 (et intégration M16) | **montrer le résultat → expliquer le besoin → écrire/modifier le code par étapes → exécuter → observer → diagnostiquer → faire modifier** | programme reproductible + sortie série / LED / LCD ou tests |
| Backend et interface web | M12–M14, M16 | **besoin utilisateur → fichier source → exécution locale → requête/réponse → vérification BDD / interface → erreur → correction** | code exécuté, réponse HTTP, base/écran cohérents |
| Intégration / fiabilité / déploiement | M08, M10–M11, M15–M16 | scénario réel ou simulé, chemin des données, cas de panne, journal d'essais, critères de validation | tests reproductibles et limites explicitement documentées |

Les familles se chevauchent : choisir la méthode selon le sujet de la **vidéo**, et pas seulement selon le numéro du module.

## Méthode imposée pour toute vidéo de programmation

1. **Résultat visible en ouverture (0–10 %)** : montrer l'effet attendu avec une carte, un moniteur série, une page ou un test. Dire s'il est simulé.
2. **Question pratique et prérequis (10–20 %)** : annoncer un seul objectif observable ; rappeler juste les notions nécessaires.
3. **Schéma ou flux de données minimal (20–30 %)** : identifier les broches ou entrées/sorties ; ne pas afficher un gros programme complet sans contexte.
4. **Construction du code par petites étapes (30–65 %)** : introduire 2–5 lignes cohérentes à la fois ; expliquer **pourquoi**, **ce que fait chaque nouvelle instruction**, puis **ce que l'on doit observer**. Partir de projets fichiers réellement fournis, éviter de ressaisir un long code à l'écran.
5. **Vrai essai et comparaison au résultat (65–78 %)** : vérifier/compilation, téléversement, exécution, sortie. **Ne jamais présenter une animation comme une preuve de test réel.**
6. **Une erreur volontaire et diagnostic (78–88 %)** : erreur compréhensible, message ou symptôme, cause, méthode de correction. Les erreurs doivent être sûres à démontrer.
7. **Mini-défi (88–100 %)** : demander une petite modification, montrer ce qui doit changer, orienter vers le corrigé fourni **séparément**. Transition vers la prochaine vidéo.

**Le cours est un accompagnement, pas une dictée de code**. Montrer des extraits au bon moment, zoomer dans l'IDE et donner le fichier complet en téléchargement. Le débutant doit comprendre l'algorithme **et** savoir refaire la démonstration.

## Livrables obligatoires par module pratique

- `scripts/V01-script.md` et `V02-script.md` : texte oral complet **synchronisé avec les gestes et fichiers ouverts**, minute par minute, temps cible (non présenté comme mesuré avant répétition).
- `code/` : fichiers source compilables/exécutables, un dossier par exemple, commentaires sobres, instructions de lancement et sorties attendues ; **indiquer l'état de vérification réelle**.
- `ressources/` : guide de matériel, câblage basse tension, aide à l'installation, tableau des valeurs et dépannage.
- `tp/` : **version apprenant sans réponses** + **corrigé formateur séparé**, barème et résultat observable.
- `quiz/` : 10 questions réellement rédigées, corrigés avec explications des mauvaises réponses, **4 faciles / 4 intermédiaires / 2 difficiles** ; au moins **8/10**.
- `production/` : tests réels effectués/non effectués, durée, tournage et publication. Aucun indicateur marqué « terminé » sans preuve.

Un schéma court en Markdown, Mermaid ou KiCad peut suffire : **aucun PPTX ni storyboard de diapositives à créer pour les nouveaux modules**.

## Vérification pédagogique des codes

- Les **versions** des outils, bibliothèques, cartes, ports et niveaux logiques doivent être documentées.
- Le code doit correspondre exactement au commentaire oral et aux TP.
- Tout résultat attendu doit être calculé ou explicité ; si non mesuré, l'étiqueter **attendu** ou **simulé**.
- Isoler erreur de compilation, erreur de téléversement, erreur logique, erreur de câblage et erreur réseau.
- Ne pas enseigner une solution fragile comme méthode finale : expliquer les limites de `delay()`, les ressources mémoire AVR, la synchronisation GSM, la persistance des index énergétiques et la sécurité API au moment concerné.
- Revoir les variantes de modules et l'exactitude des broches, ne jamais supposer qu'elles sont universelles.

## Sécurité et invariants techniques

- Aucun novice ne manipule le **230 V** ; essais simulés ou **basse tension**. Les essais secteur exigent personnel qualifié et protections appropriées.
- **ATmega328P, PZEM-004T, DS3231, FRAM, LCD I2C 20×4, SIM800L**, Arduino IDE et programmation ISP par Uno.
- **Python Flask + SQLite + Jinja2 + HTML/CSS/JavaScript** et PythonAnywhere, pas React ni MySQL.
- Vérifier disponibilité 2G et limite de sécurité TLS du modem GSM. Ne pas recommander le transport de secrets en clair.
- Système de suivi énergétique pédagogique **non certifié pour facturation**.

## Références, structure et statuts

Le [plan complet 4 h](../docs/formation/PLAN_FORMATION_4H.md) fixe les objectifs et durées, **pas l'obligation d'utiliser un PowerPoint**. Les contenus de M01 à M04 ne sont pas réécrits. Le formateur est responsable des prises de vue, du montage, de la publication. Ne pas placer des clés/API ou vidéos payantes dans ce dépôt public.
