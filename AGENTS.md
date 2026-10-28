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

### Architecture matérielle imposée à partir de M10

**Décision du projet : le SIM800L utilise l'UART matériel de l'ATmega328P (D0/RX et D1/TX), et non une seconde liaison `SoftwareSerial`.** Le PZEM-004T conserve `SoftwareSerial` sur D10/RX et D11/TX ; l'horloge RTC DS3231, le LCD I2C 20×4 et la future FRAM I2C partagent SDA=A4 et SCL=A5, avec adresses et niveaux électriques compatibles. Bouton D2 et LED D13 sont conservés.

Règles obligatoires pour M10–M16, y compris scripts, schéma KiCad et PCB :

- `Serial` (UART0) appartient **exclusivement au SIM800L en mode GSM réel** : aucun diagnostic `Serial.print`, commandes console `1/0/?` ou adaptateur USB–TTL partagé pendant les échanges modem. Prévoir un mode de simulation/débogage séparé, et documenter/tester la migration des commandes existantes.
- Câblage croisé via **adaptation bidirectionnelle de niveaux logiques validée** : SIM800L TXD vers ATmega D0/RX, ATmega D1/TX vers SIM800L RXD. Vérifier les seuils électriques de la variante exacte ; ne pas supposer qu'une liaison directe 2,8 V ↔ 5 V est sûre ou fiable.
- SIM800L : alimentation dédiée conforme à la variante (module nu typiquement autour de 4,0 V, pointes proches de 2 A), découplage local et masse commune ; **jamais le 5 V direct sur le VBAT d'un SIM800L nu**.
- D11 est aussi MOSI/ISP : assurer l'isolation du PZEM pendant programmation/maintenance ISP. D0/D1 doivent pouvoir être isolées du modem pour le diagnostic et toute programmation qui les utilise.
- Ne pas changer silencieusement ce brochage ; toute nécessité de réaffectation exige une décision documentée, une mise à jour simultanée du firmware, des tests et du schéma/PCB.

Référence normative et tableau de câblage : [règle de progression continue](docs/formation/REGLE_EVOLUTION_CONTINUE.md#attribution-des-interfaces-matérielles-à-partir-de-m10).

**Tableau de brochage officiel M10–M16 (ATmega328P-PU DIP-28) :** [docs/hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md](docs/hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md). Consulter la carte complète des 28 broches **avant toute modification** des pilotes, connecteurs ou schémas KiCad. D3 (buzzer), D4 (PWRKEY) et D5 (STATUS) ne sont que des **réservations proposées**, non des connexions définitivement approuvées.

### Livre pédagogique (règle permanente)

Toute rédaction ou révision sous `livre/chapitres/` doit d'abord consulter `livre/PLAN_EDITORIAL.md`, `livre/PRODUCTION_INTERNE.md` et `livre/ILLUSTRATIONS_A_PRODUIRE.md` (registre interne).

**Illustrations obligatoires dans les 16 chapitres :** repérer chaque notion qui nécessite un visuel, ajouter le commentaire de production `<!-- ILLUSTRATION À PRODUIRE — FIGURE X.Y ... -->` à l'emplacement concerné, avec type, contenu, légende, texte alternatif, contraintes et statut ; enregistrer le visuel dans le registre. Ne pas qualifier de « prêt à publier » un chapitre dont des illustrations obligatoires ne sont pas réalisées et validées.

Le livre final reste autonome, **sans références GitHub**, ni renvois aux dossiers internes, commits ou scripts vidéo. Les rapports de relecture, la charte et le registre des figures ne sont jamais exportés.

### Invariants

- Simulation sans secteur disponible par défaut ; secteur 230 V réservé au personnel qualifié.
- Données fictives clairement signalées. Pas de mesure ou de réussite matérielle inventée.
- PZEM énergie cumulative, date fiable DS3231, périodes partielles signalées, reprise durable seulement si réellement implémentée.
- Pas de nouveaux PowerPoint (décision applicable depuis M05). Scripts détaillés, code progressif, deux TP corrigés et 10 QCM par module.
- L'enregistrement et la publication des vidéos sont assurés par le formateur.
