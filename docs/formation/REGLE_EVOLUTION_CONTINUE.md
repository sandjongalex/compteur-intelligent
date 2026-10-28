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

## Attribution des interfaces matérielles à partir de M10

**Décision actée : réserver l'UART matériel de l'ATmega328P au SIM800L (M10 et suivants).** Cette attribution concerne le firmware, l'architecture électronique, les démonstrations, les tests et la conception KiCad. **Décision complémentaire approuvée : PZEM déplacé de D10/D11 vers D6/D7 à partir de M10.** Le firmware M09 et les snapshots M03–M09 restent inchangés ; expliquer et tester cette migration dans M10.

| Élément | Interface retenue | Broches Arduino / ATmega328P PDIP28 | Règle |
|---|---|---|---|
| SIM800L GSM/GPRS | **UART matériel** `Serial` | **D0/RX = PD0 broche 2**, **D1/TX = PD1 broche 3** | Réserver cet UART au modem en mode réel ; liaison RX/TX croisée avec adaptation des niveaux logiques validée. |
| PZEM-004T V3 | **`SoftwareSerial`** | **D6/RX = PD6 broche 12**, **D7/TX = PD7 broche 13** | Migration depuis D10/D11 du M09 ; garder le PZEM hors du câblage MOSI/ISP. |
| RTC I2C DS3231 | I2C `Wire` | **A4/SDA = PC4 broche 27**, **A5/SCL = PC5 broche 28** | Horodatage par horloge RTC ; ne pas le remplacer par l'UART. |
| LCD I2C 20×4 | I2C `Wire` | **A4/SDA, A5/SCL** | Partage du bus I2C, adresse et tension à vérifier. |
| FRAM I2C (M11) | I2C `Wire` | **A4/SDA, A5/SCL** | Variante I2C retenue ; vérifier adresse, tension, pull-ups, capacité du bus. |
| Bouton | GPIO | **D2 = PD2 broche 4** | Conserver la commande locale. |
| LED de diagnostic | GPIO | **D13 = PB5 broche 19** | Conserver la LED avec résistance ; attention au SCK pendant l'ISP. |

**Référence détaillée de toutes les 28 broches PDIP28 :** [tableau d'affectation composants ↔ ATmega328P](../hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md). Les fonctions facultatives buzzer D3, PWRKEY D4 et STATUS D5 restent proposées, non obligatoires. Les broches physiques, connecteurs ISP, alimentations, niveaux et périphériques I2C sont documentés dans ce tableau.

### Contraintes obligatoires de mise en œuvre

1. **Réserver `Serial` au SIM800L lorsque la transmission réelle est activée** : aucune trace `Serial.print` non protocolaire, ni console `1/0/?`, ni USB–TTL connecté au modem simultanément. La version M09 utilise actuellement `Serial` pour le diagnostic : en M10, fournir un mode de simulation/maintenance séparé et une migration explicite, expliquée et testée de ces acquis ; ne pas les supprimer silencieusement.
2. **Câbler les voies UART en croisé :** TXD du SIM800L → D0/RX ATmega et D1/TX ATmega → RXD du SIM800L, **avec adaptation des niveaux dans les deux sens selon les seuils du module exact**. Le SIM800L nu utilise une logique différente du 5 V ATmega ; ne pas supposer une compatibilité directe, y compris dans le sens modem → AVR. Vérifier les références exactes avant KiCad.
3. **Alimenter le modem correctement :** alimentation dédiée adaptée à la version SIM800L (pour un module nu, VBAT typiquement ~4,0 V avec pointes proches de 2 A), condensateurs de proximité, masse commune et mesures de tension pendant l'émission. Ne jamais appliquer directement 5 V à VBAT d'un SIM800L nu. Ne pas généraliser cette règle d'entrée d'alimentation aux cartes intégrant un régulateur sans vérifier leur documentation.
4. **Préserver la programmabilité ISP et le diagnostic :** avec le PZEM sur D6/D7 à partir de M10, D11 reste réservé à MOSI/ISP et ne doit pas être relié au PZEM. En M09 historique, isoler l'ancien PZEM D11 lors d'une programmation ISP. Réserver un moyen sûr de déconnecter le modem de D0/D1 pour les essais et les éventuels chargements par UART ; privilégier ISP pour la puce autonome.
5. **Migration explicite M09 → M10 :** remplacer `SoftwareSerial portPzem(10, 11)` par `SoftwareSerial portPzem(6, 7)` dans le **nouveau** firmware M10 et son snapshot, adapter les schémas et tests, vérifier le RX/TX croisé et ne pas réécrire les snapshots M03–M09.
6. **Garder acquisition et communications non bloquantes autant que possible :** temporisations, réponses AT, erreurs réseau, absence de données, réessais bornés et reprise de mesure doivent être couverts par des tests. Le PZEM reste sur un seul `SoftwareSerial` ; la RTC, le LCD et la FRAM ne consomment pas de liaison série virtuelle.
7. **Conserver le mode simulation sans GSM, PZEM ni secteur.** Démontrer la compilation et les régressions sur ATmega328P avant de déclarer un essai matériel réussi. Toute réaffectation de broche doit être justifiée et synchronisée entre documentation, firmware, tests, connecteurs et PCB.

[Instructions agents](../../AGENTS.md) · [Module M10](../../formation/modules/M10-sim800l-gsm-gprs/README.md)

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
