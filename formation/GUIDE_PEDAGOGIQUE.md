# Guide pédagogique — AlexTech Academy, compteur intelligent

## Principe non négociable : progression du même projet

Lire le [**contrat de progression continue**](../docs/formation/REGLE_EVOLUTION_CONTINUE.md) avant toute production. **Le code final d'un module est la base du module suivant** : montrer le résultat précédent, introduire la nouveauté, préserver ou justifier les changements et vérifier la non-régression. Les exercices isolés enseignent une notion puis l'intègrent au **projet principal unique**.

Les modules Python/web et KiCad doivent eux aussi prolonger le même système sans ajouter de faux changements au firmware. Voir le [modèle de module évolutif](../docs/formation/MODELE_MODULE_EVOLUTIF.md) et les [instructions des agents](../AGENTS.md).

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


---

## Nouvelle règle de conception — à partir du Module 05

**Décision pédagogique : ne plus produire de PowerPoint pour les modules suivants.** Les supports des Modules 01 à 04 restent conservés. L'enregistrement et la publication des vidéos sont assurés par le formateur.

### Modules conceptuels : expliquer et illustrer

1. Formuler un objectif observable.
2. Expliquer un concept avec une analogie limitée et un schéma.
3. Montrer un exemple concret.
4. Faire reformuler l'idée.
5. Faire un petit quiz ou exercice de compréhension.

### Modules de programmation : observer, coder, tester, modifier, expliquer

1. **Problème concret** : montrer ce que l'on cherche à réaliser.
2. **Résultat attendu** : afficher le comportement final avant le code.
3. **Préparation** : expliquer prérequis, matériels, câblage basse tension et fichiers.
4. **Codage progressif** : avancer par étapes exécutables et expliquer les nouvelles instructions.
5. **Exécution** : compiler/lancer et comparer avec le résultat attendu ; ne jamais présenter une simulation comme un test réel.
6. **Diagnostic** : montrer une erreur courante, son symptôme, puis sa correction.
7. **Variation** : demander à l'apprenant de modifier un paramètre et prédire le comportement.
8. **Travail autonome** : proposer un TP hors durée vidéo et fournir un corrigé distinct.
9. **Validation** : questions de lecture de code, sorties prédites, sécurité et pratique réelle.

### Organisation des ressources

Chaque module technique doit comporter un script oral minuté, du **code de départ**, les **étapes de construction**, le **code final**, des **résultats attendus**, des **tests reproductibles**, un **guide de dépannage**, des **TP corrigés** et un **quiz de dix questions** avec explications. Les sections `slides/` préexistantes peuvent rester en archives ; aucun nouveau PPTX n'est exigé.

**Priorité : pédagogie et reproductibilité plutôt que quantité de diapositives.** Préserver le plafond global de **4 heures de vidéo** et mettre les longues pratiques à part. Pour les parties secteur, réserver tout essai sur 230 V à du personnel qualifié ; les novices travaillent en simulation ou basse tension.


## Projet fil rouge cumulatif (décision complémentaire)

En plus des petits sketches de chaque leçon, un **programme Arduino commun** progresse de M05 jusqu'au compteur final : [firmware/README.md](../firmware/README.md). Le formateur commence par la démonstration minimale, puis ouvre le snapshot du module, montre les fonctions ajoutées et reteste celles des modules précédents. Il conserve les versions historiques à disposition. Le programme `firmware/courant/` sert de base au module suivant. Les TP et corrigés de chaque module ne sont pas supprimés.

Les mesures et dates simulées doivent être étiquetées comme telles. Les connexions au secteur n'ont pas leur place dans les séances débutants. La sauvegarde FRAM, le GSM/GPRS et la partie serveur ne seront marqués « réalisés » que lorsque du code vérifié aura été ajouté.
