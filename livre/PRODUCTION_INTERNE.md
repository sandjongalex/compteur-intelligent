# Production interne du livre — ne pas inclure dans les exports

Ce fichier documente la procédure de travail de l'équipe AlexTech Academy. **Il ne fait pas partie du livre destiné au lecteur.**

## Règle de diffusion

**GitHub ne sert que pour construire et réviser la formation.** Le livre et les vidéos seront distribués ailleurs, selon le mode choisi par l'auteur. Les étudiants et lecteurs ne doivent pas avoir besoin d'un compte GitHub, ni de consulter les fichiers internes du projet, pour comprendre les leçons du livre.

On distingue deux catégories de fichiers :

### A. Contenu éditorial à composer dans le livre

- `livre/00-sommaire.md`
- `livre/00-avant-propos.md`
- `livre/chapitres/01-*.md` puis `02-*.md` … `16-*.md`
- `livre/annexes/` pour les corrigés, lexiques et annexes retenus.

Ces fichiers doivent rester **autonomes et lisibles hors connexion**, à l'exception des éventuelles ressources numériques explicitement facultatives.

### B. Documents de production à exclure du livre

- `livre/README.md` : tableau de bord interne de rédaction ;
- `livre/PLAN_EDITORIAL.md` : charte et correspondance avec les vidéos ;
- `livre/RELECTURE_M01.md` et les futures relectures ;
- `livre/PRODUCTION_INTERNE.md` : présent document ;
- `livre/ILLUSTRATIONS_A_PRODUIRE.md` : registre des illustrations à réaliser ;
- `livre/MODELE_CHAPITRE.md` : gabarit de rédaction, commentaires et figures ;
- les fichiers internes situés dans `docs/`, `formation/`, `firmware/`, `.github/` et `AGENTS.md` ;
- les commits, branches, pull requests, tests de développement et historiques de bugs.

Les références aux sources GitHub **sont autorisées dans les documents internes de contrôle**, mais **interdites dans les pages éditoriales du livre**.

## Règles de relecture des futurs chapitres

1. Un chapitre correspond à un module vidéo (deux leçons), sans faire dépendre la lecture des vidéos.
2. L'introduction, le corps et les annexes ne contiennent pas de liens vers les fichiers GitHub ni d'URL de travail.
3. Aucun texte du lecteur ne parle du `main`, des commits, de la PR, de l'état temporaire des modules ou de fonctions « actuellement dans le dépôt ».
4. Les exemples, figures, tableaux et procédures nécessaires sont dans le livre ; les fichiers sources intégraux volumineux peuvent être fournis en complément **sans rendre la compréhension dépendante d'un accès externe**.
5. Les renvois éditoriaux utilisent des références pérennes, par exemple « voir chapitre 8 », « figure 6.2 » ou « annexe A ».
6. Les références aux vidéos restent possibles comme **complément facultatif** (« vidéo du module 1 »), sans lier un site de développement.
7. La plateforme de distribution, les URL publiques, les QR codes et le format commercial ne sont ajoutés qu'une fois décidés et vérifiés, jamais inventés.
8. Les statuts de validation technique et les réserves de sécurité indispensables restent explicités, sans conserver d'informations périmées sur l'avancement du dépôt.
9. À chaque endroit où une image est indispensable ou pédagogiquement pertinente, insérer une **fiche d'illustration sous forme de commentaire Markdown** (`<!-- ILLUSTRATION À PRODUIRE — FIGURE X.Y ... -->`) et lui associer sa légende et son texte alternatif.
10. Inscrire chaque illustration dans le [registre interne](ILLUSTRATIONS_A_PRODUIRE.md), actualiser son statut `À PRODUIRE → EN COURS → VALIDÉE` et conserver la preuve des droits et de la validation technique.
11. **Bloquer l'export commercial tant qu'une figure nécessaire reste au statut À PRODUIRE**. Les figures textuelles/Mermaid ne dispensent pas de leur préparation graphique finale.
12. Les commentaires de production ne doivent pas devenir du texte visible pour le lecteur ; ils sont retirés ou remplacés par les figures approuvées au moment de composer le livre.

## Contrôle avant export

- [ ] Table des matières complète et cohérente.
- [ ] Tous les chapitres nécessaires sont rédigés, validés et à jour.
- [ ] Aucun lien vers `github.com`, `raw.githubusercontent.com`, fichier Markdown relatif, branche ou script de tournage dans les pages composées.
- [ ] Les figures, codes et tableaux sont lisibles en PDF et en impression.
- [ ] Toutes les figures identifiées dans le texte figurent au registre et leur numérotation/citation est cohérente.
- [ ] Aucun marqueur `ILLUSTRATION À PRODUIRE`, commentaire de maquettage ou figure obligatoire manquante ne subsiste dans les pages publiées.
- [ ] Photos et captures originales ou sous licence adaptée, légendes exactes, texte alternatif renseigné, versions logicielles vérifiées.
- [ ] Les éléments secteur, mesures fictives et résultats d'essais sont présentés sans risque ni confusion.
- [ ] Les exemples fictifs et les mesures réellement vérifiées sont distingués.
- [ ] Les annexes citées existent dans le contenu livré.
- [ ] Aucun fichier interne n'est inséré dans le PDF final.

Ce manifeste guide le futur processus d'export. **Aucun PDF de livre complet n'est encore produit à ce stade.**
