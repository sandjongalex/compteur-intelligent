# Instructions permanentes pour les agents de développement

Ce dépôt héberge une **formation de conception d'un seul compteur électrique intelligent**. Lire avant toute modification le document obligatoire :

**[docs/formation/REGLE_EVOLUTION_CONTINUE.md](docs/formation/REGLE_EVOLUTION_CONTINUE.md)**

## Règle prioritaire

Chaque module fait évoluer **le même projet** en partant du résultat du module précédent. Ne créez pas un nouveau projet final indépendant à chaque module. Gardez les mini-sketches autonomes uniquement pour apprendre une notion, puis intégrez la nouveauté au programme commun.

### Pour les changements de firmware (M03–M11 et intégration pertinente)

1. Partir de `firmware/courant/CompteurIntelligent/`, le programme précédent.
2. Préserver ses fonctions, sauf évolution délibérée documentée et testée.
3. Créer un snapshot `firmware/etapes/Mxx/Compteur_Mxx/`.
4. Synchroniser **tous les fichiers sources** du snapshot et du dossier courant, en renommant seulement le fichier principal `.ino`.
5. Actualiser `firmware/manifest.json`, `firmware/PROGRESSION.md`, les scripts/TP/quiz et les tests.
6. Passer `python3 firmware/tests/test_progression.py` et `python3 firmware/tests/test_contrat_evolution.py`, puis les compilations Uno en simulation et tests pertinents.
7. Ne pas annoncer de fonctionnement réel sans test sur le matériel.

### Pour Python/API, UI et KiCad (M12–M16)

Faire évoluer les **mêmes composants du système** et conserver la compatibilité des échanges d'informations. Une nouvelle étape backend ou de PCB ne nécessite pas un changement Arduino artificiel.

### Invariants

- Simulation sans secteur disponible par défaut ; secteur 230 V réservé au personnel qualifié.
- Données fictives clairement signalées. Pas de mesure ou de réussite matérielle inventée.
- PZEM énergie cumulative, date fiable DS3231, périodes partielles signalées, reprise durable seulement si réellement implémentée.
- Pas de nouveaux PowerPoint (décision applicable depuis M05). Scripts détaillés, code progressif, deux TP corrigés et 10 QCM par module.
- L'enregistrement et la publication des vidéos sont assurés par le formateur.
