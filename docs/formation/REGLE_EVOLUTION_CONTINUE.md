# Règle obligatoire — Un seul projet qui évolue à chaque module

**Statut : décision pédagogique et technique de référence pour AlexTech Academy.** Ce document s'applique à toute la suite de la formation « Compteur intelligent » (M03 à M16), sans changer le programme, les durées ni la répartition des TP. M01 et M02 sont les prérequis de compréhension et de sécurité.

> **L'apprenant ne recommence pas un projet de zéro à chaque module : il reprend le résultat du module précédent, le comprend, lui ajoute une capacité et démontre que les capacités acquises continuent de fonctionner.**

## Deux supports complémentaires, jamais confondus

1. **Micro-sketch ou mini-exercice du module** : introduire isolément une instruction ou un composant, avec un exemple facile à expliquer. Ces exercices ne remplacent jamais le projet principal.
2. **Projet fil rouge cumulatif** : même compteur, mêmes données et fonctions utiles, nouvelles capacités clairement identifiées et tests de non-régression. Le code final du module N est **le code de départ du module N+1**.

**Une transformation volontaire reste possible :** par exemple la LED clignotante du M04 devient une LED commandée en M05. Toute substitution doit être annoncée, expliquée et testée ; aucune suppression silencieuse.

## Procédure obligatoire pour créer un module N

**Avant d'écrire les scripts et le code :**
1. Examiner l'état de référence du module précédent et la [matrice de progression](../../firmware/PROGRESSION.md).
2. Décrire une seule nouvelle capacité visible à l'apprenant et les éléments précédents à préserver.
3. Séparer **simulation débutant** et **matériel réel** ; ne jamais exiger de manipuler le secteur 230 V.

**Pendant la conception :**
4. Expliquer par petits changements de code (2–5 lignes cohérentes à la fois) : résultat recherché → code d'avant → modification → vérification → diagnostic → mini-défi.
5. Fournir le mini-exercice ET l'intégration de sa fonction dans le **même projet principal**.
6. Réutiliser les noms, structures et interfaces établis autant que possible. Toute migration d'interface est documentée avec un avant/après.
7. Préserver la compilation et le **mode simulation sans secteur par défaut**. Ne pas marquer une compilation ou un essai matériel comme « réussi » sans l'avoir exécuté.

**Avant de dire le module terminé :**
8. Publier un snapshot dans `firmware/etapes/Mxx/` **si le firmware embarqué change**, et mettre à jour `firmware/courant/CompteurIntelligent/` avec **les mêmes sources**. Ne pas réécrire rétroactivement les snapshots historiques.
9. Mettre à jour `firmware/manifest.json`, `firmware/PROGRESSION.md`, la documentation du module et les tests de non-régression, si le firmware évolue.
10. Pour un module Python/web, faire évoluer **la même application serveur**, ses interfaces de données et ses tests ; ne pas inventer un changement firmware artificiel. Préserver la compatibilité avec les données déjà produites par le compteur.
11. Pour le module KiCad, faire évoluer les schémas et le PCB du **même appareil** ; documenter toute modification de brochage et ses conséquences sur le firmware.
12. Exécuter les tests disponibles, compiler les cibles concernées, vérifier les fonctions héritées, consigner les limites, puis préparer script, deux TP, corrections et quiz avec la pédagogie de programmation.

**La vidéo et la publication sont réalisées par le formateur.** Les contrôles automatisés n'attestent pas les essais sur les matériels réels.

## Contrat de non-régression

Un changement est admissible uniquement lorsque :
- la nouveauté du module est observable ou testable ;
- la compilation, les acquis pertinents du module précédent et les interfaces existantes sont préservés **ou** remplacés par une migration explicitement approuvée ;
- les mesures factices restent signalées « simulées », aucune valeur absente n'est inventée et les périodes incomplètes ne deviennent pas des totaux prétendument exacts ;
- les validations de sécurité, mémoire, RTC et alimentation nécessaires ont été effectuées ou signalées en attente ;
- les documents, corrigés et scripts enseignent **le même code** que celui remis à l'apprenant.

### Critères d'acceptation d'un module embarqué

- [ ] Je pars du firmware courant et non d'un nouveau sketch final indépendant.
- [ ] Je montre au moins un changement **avant → après**.
- [ ] Les exercices isolés n'interrompent pas la continuité du firmware.
- [ ] Le snapshot Mxx et le firmware courant sont identiques sur leurs fichiers source.
- [ ] La matrice, le manifeste et les liens du module sont synchronisés.
- [ ] La compilation et les tests de régression sont exécutés et consignés.
- [ ] Les fonctions précédentes sont testées (ou leur transformation est justifiée).
- [ ] Les tests physiques et les limites sont indiqués honnêtement.

## Application par domaine

| Modules | Projet enrichi | Source de continuité |
|---|---|---|
| M03–M08 | Firmware embarqué du compteur | [Versions et programme courant](../../firmware/README.md) |
| M09–M11 | **Même firmware**, désormais autonome, GSM, puis persistant | Snapshot du module précédent puis `firmware/courant/` |
| M12–M14 | **Même système connecté** : acquisition → Python → API Flask/SQLite → interface Jinja2 | Contrat des données, application serveur commune et tests |
| M15 | **Même appareil** : alimentation, schéma et PCB KiCad | Brochage, schéma, firmware et tests d'intégration |
| M16 | **Même solution de bout en bout**, déploiement et validation | Firmware + API + interface + matériel, sans réinitialiser le projet |

Une étape de documentation, de backend ou de PCB **ne nécessite pas** de créer un faux snapshot Arduino s'il n'y a pas de changement du firmware ; la continuité porte sur le **projet global**.

## Maintenance et automatisation

- `firmware/manifest.json` : liste des snapshots publiés et version active.
- `firmware/tests/test_contrat_evolution.py` : contrôle structurel des snapshots et de la synchronisation du projet actif.
- `firmware/tests/test_progression.py` : vérification des acquis pédagogiques M03–M08.
- `.github/workflows/firmware-fil-rouge.yml` : exécution des tests et compilations Arduino en mode simulation.

**Important :** un test statique ne prouve pas à lui seul qu'une fonctionnalité physique continue à marcher. Chaque nouveau composant aura son propre protocole d'essai.
