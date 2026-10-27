# Guide pédagogique et processus de production

## Promesse réaliste en 4 heures

Le contenu vidéo est un **parcours pratique accéléré guidé**. Pour les débutants absolus, la maîtrise autonome demandera du temps de pratique supplémentaire. Ne jamais supprimer une notion de sécurité pour gagner du temps.

## Processus obligatoire, module par module

1. **Vérifier les prérequis** : aucun concept ne doit être utilisé avant d'être défini ou démontré.
2. **Finaliser chaque script** : phrases naturelles, un objectif principal, exemples visuels.
3. **Préparer les slides et prises de vue** : objectif, schéma, exemple, démo, synthèse.
4. **Tester les fichiers réels** : Arduino IDE, schémas, Python, SQLite, captures selon le module.
5. **Rédiger la fiche TP et son corrigé** : consignes, prérequis, résultat, diagnostic.
6. **Rédiger le quiz et les explications** : 10 questions, score minimal 80 %.
7. **Filmer, monter et chronométrer** : respecter le quota vidéo par module.
8. **Faire relire** la conformité technique, la sécurité et le niveau débutant.
9. **Publier** les vidéos sur la plateforme de formation et lier les ressources aux leçons.

## État réel de l'organisation

| Livrable | Statut |
|---|---|
| Plan global 4 h | Disponible |
| 16 dossiers pédagogiques | Disponibles |
| 32 fiches vidéo détaillées | Disponibles, reprises du plan source |
| 32 trames de scripts oraux | Créées, à rédiger intégralement |
| 32 storyboards de diapositives | Créés, slides à réaliser |
| Fiches TP et quiz de chaque module | Objectifs classés, contenus détaillés à finaliser |
| Firmware / API / KiCad / PPTX | Non fournis à ce stade |

## Contraintes techniques invariantes

- ATmega328P programmé avec **Arduino IDE**, puis en ISP à l'aide d'une **Arduino Uno**.
- PZEM-004T, DS3231, FRAM, SIM800L, LCD 20×4.
- Affichage : **date**, **tension**, **kWh jour** et **kWh mois**.
- **Python Flask + SQLite + Jinja2 + HTML/CSS/JavaScript**, hébergement **PythonAnywhere** ; **pas de React ni MySQL**.
- Transmission GSM/GPRS à vérifier selon réseau 2G, HTTPS/TLS et compatibilité plateforme.
- Aucun essai secteur par un débutant non qualifié : simulations et montages basse tension pour les exercices.
- Ne pas confondre compteur de suivi énergétique et compteur certifié pour facturation.

## Convention de nommage

M01..M16 pour les modules, V01/V02 pour leurs vidéos. Les fichiers de production doivent garder le même identifiant que les leçons, afin de retrouver facilement scripts, slides, montages et quiz. Mettre les fichiers volumineux de travail dans un espace de production approprié, et ne committer que les ressources destinées à être versionnées.

## Protection du contenu pédagogique

Ce dépôt GitHub est public. Ne pas ajouter de secrets, clés API, vidéos payantes non destinées à la diffusion publique ou données personnelles. Protéger les ressources commerciales par un espace privé ou la plateforme de formation.
