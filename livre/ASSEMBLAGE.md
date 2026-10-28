# Assemblage automatique du livre — utilisation interne

> **Ce document est réservé à l'auteur et à la production.** Il ne fait pas partie du livre commercialisé. GitHub sert à construire le livre, pas à le distribuer aux lecteurs.

## Principe

Les chapitres restent **séparés** dans `livre/chapitres/` : cela simplifie les corrections et les ajouts. Le script `livre/scripts/assembler_livre.py` lit exclusivement, dans cet ordre :

1. `livre/00-avant-propos.md` ;
2. les chapitres `livre/chapitres/01-*.md` à `16-*.md`, **numérotés sans trou** ;
3. les corrigés `livre/annexes/CORRIGE_M01.md` à `CORRIGE_M16.md`, correspondant **seulement** aux chapitres présents.

Les documents `README.md`, `PLAN_EDITORIAL.md`, `RELECTURE_M*.md`, `ILLUSTRATIONS_A_PRODUIRE.md`, le code source, les scripts des vidéos et les fichiers de production ne sont **jamais inclus**.

**Le fichier de plan `livre/00-sommaire.md` n'est volontairement pas ajouté au manuscrit provisoire :** il annonce déjà 16 chapitres alors que seuls les premiers sont disponibles. Le programme crée un `sommaire-dynamique.md` correspondant aux chapitres réellement présents ; les versions Word et PDF reçoivent une **table des matières automatique** par Pandoc.

## Générer le manuscrit aujourd'hui

Depuis la racine du dépôt :

```bash
python livre/scripts/assembler_livre.py --mode brouillon --output-dir build/livre
```

Ce programme utilise uniquement la bibliothèque standard de Python 3.10+ et fonctionne même sans Pandoc.

Il crée :

| Fichier | Usage |
|---|---|
| `build/livre/compteur-intelligent-brouillon.md` | **Un seul manuscrit** rassemblant les chapitres et corrigés |
| `build/livre/sommaire-dynamique.md` | Sommaire provisoire des chapitres effectivement rédigés |
| `build/livre/rapport-assemblage.json` | Nombre de chapitres, corrigés, figures et fichiers inclus |
| `build/livre/assets/` | Copies des images locales lorsqu'elles existent |

Le manuscrit provisoire inclut les repères visibles `[ILLUSTRATION À INSÉRER]` : cela aide la relecture de l'auteur. Les longs commentaires de fabrication Markdown sont retirés. La mention **BROUILLON DE TRAVAIL — NON DESTINÉ À LA VENTE** indique que ce n'est pas une édition finale.

Le script ne modifie **jamais** les fichiers sources des chapitres.

## PDF et Word provisoires sur GitHub Actions

Le workflow `.github/workflows/livre-assemblage.yml` réalise les étapes suivantes :

- exécute les tests unitaires de l'assembleur ;
- assemble le livre en un seul fichier Markdown ;
- installe Pandoc et le moteur XeLaTeX ;
- génère un **document Word DOCX** et un **PDF A4** avec table des matières ;
- place les fichiers dans l'artefact téléchargeable **`livre-compteur-intelligent-brouillon`**, conservé 14 jours.

Le workflow s'exécute lors des modifications sous `livre/` sur **main**, lors des Pull Requests visant main, ou manuellement depuis **Actions → Livre - assemblage et apercus → Run workflow**.

Il ne publie **aucune version commerciale** et ne crée pas de release. L'artefact est un outil de relecture de l'auteur.

L'affichage final dépend de Pandoc, des polices et du moteur PDF utilisés. Une relecture visuelle du PDF/Word reste obligatoire : il faut notamment vérifier les codes, tableaux, caractères accentués, légendes et sauts de page.

## Exports sur ordinateur

Avec Pandoc installé, une génération manuelle équivalente est possible après l'assemblage :

```bash
pandoc build/livre/compteur-intelligent-brouillon.md --standalone --toc --toc-depth=1 --metadata=lang:fr-FR -o build/livre/compteur-intelligent-brouillon.docx

pandoc build/livre/compteur-intelligent-brouillon.md --standalone --toc --toc-depth=1 --pdf-engine=xelatex -V documentclass=report -V papersize=a4 -V geometry:margin=25mm -V mainfont="DejaVu Serif" -V monofont="DejaVu Sans Mono" -o build/livre/compteur-intelligent-brouillon.pdf
```

Le moteur `xelatex` et les polices mentionnées doivent être installés pour le PDF. **L'exécution de Pandoc n'est pas nécessaire pour créer le fichier Markdown unique.**

## Passage au livre définitif

La commande suivante sert seulement au **contrôle du processus de publication** :

```bash
python livre/scripts/assembler_livre.py --mode publication --output-dir build/livre
```

À ce stade, **elle doit échouer** : les 16 chapitres ne sont pas encore tous rédigés et les illustrations sont à produire.

Les conditions minimales contrôlées automatiquement seront :

1. présence des **16 chapitres**, dans le bon ordre ;
2. présence des **16 corrigés** correspondants ;
3. aucune mention **`ILLUSTRATION À INSÉRER`** restant dans les pages ;
4. toutes les figures du registre interne au statut **`VALIDÉE`** ;
5. autant d'images locales intégrées que de figures déclarées au registre ;
6. aucune référence à GitHub, aux PR ou aux documents de production dans les textes.

Ces vérifications ne peuvent **pas remplacer** la validation humaine des licences d'images, de la sécurité électrique, des essais, de la lisibilité, de la table des matières ou de l'auteur. Le mode « publication » ne doit être utilisé qu'après cette validation éditoriale.

**Les placeholders et les commentaires sont des éléments du brouillon, à remplacer par les vraies images**. Une illustration ajoutée dans le chapitre doit être insérée sous forme d'image Markdown avec un texte alternatif, par exemple :

```markdown
![Schéma du compteur, avec composants annotés](../assets/schema-compteur.svg)
```

Les fichiers image peuvent être organisés sous `livre/assets/` ou dans des sous-dossiers du livre ; l'assembleur en fait une copie dans `build/livre/assets/` et corrige les chemins. Les références à des images sur des sites externes ne sont pas acceptées.

## Vérifier les garde-fous avant toute modification

```bash
python -m unittest discover -s livre/scripts/tests -v
```

Le projet dispose de tests pour l'ordre des chapitres et annexes, les exclusions internes, les trous de numérotation, la validation des images et les blocages de publication.

## Mise à jour incrémentale

À chaque nouveau chapitre :

1. écrire son `livre/chapitres/NN-*.md` et son corrigé `livre/annexes/CORRIGE_MNN.md` ;
2. actualiser le registre interne des illustrations ;
3. fusionner le chapitre validé au niveau rédactionnel sur `main` ;
4. télécharger le **nouvel aperçu complet** dans les artefacts de GitHub Actions ;
5. vérifier les numéros, figures, équations, codes et tableaux.

**Les chapitres restent indépendants pour le travail ; le lecteur reçoit un seul ouvrage assemblé.**
