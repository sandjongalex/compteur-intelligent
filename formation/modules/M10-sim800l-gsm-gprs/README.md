# M10 — Communiquer avec le SIM800L par GSM/GPRS

**Durée vidéo : 14 minutes** · **2 leçons** · **État : organisation prête, production à réaliser**

## Règle obligatoire : évolution du même projet

Le résultat du module précédent est **le point de départ** : le code et le système ne sont pas recommencés de zéro. Le firmware `firmware/courant/CompteurIntelligent/` doit évoluer depuis la version précédente ; publier un snapshot Mxx et actualiser le manifeste lorsque le firmware change. Les petits programmes de cours restent des exercices, et les nouveautés doivent être intégrées au projet commun et testées sans régression.

[Contrat officiel de progression continue](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md) · [Modèle d'acceptation du module](../../../docs/formation/MODELE_MODULE_EVOLUTIF.md)

## Affectation matérielle M10 — décision obligatoire

Le **SIM800L sera piloté par l'UART matériel** (`Serial`) de l'ATmega328P autonome ; **aucun deuxième `SoftwareSerial` ne sera utilisé pour le GSM**. Le firmware devra partir du dossier courant M09, intégrer la communication modem et préserver les acquis mesurables.

| Périphérique | Bus | Connexion retenue |
|---|---|---|
| SIM800L | UART matériel | Modem TXD → ATmega D0/RX (PD0, pin 2) ; ATmega D1/TX (PD1, pin 3) → modem RXD, avec adaptation de niveaux validée dans les deux sens |
| PZEM-004T | SoftwareSerial | D6/RX (PD6, pin 12), D7/TX (PD7, pin 13), à partir du firmware M10 |
| DS3231, LCD 20×4, FRAM I2C (M11) | I2C | SDA=A4 (PC4, pin 27), SCL=A5 (PC5, pin 28) ; adresses, alimentation et pull-ups compatibles |
| Bouton et LED | GPIO | D2 bouton, D13 LED (avec résistance) |

**Contraintes d'intégration :** l'UART `Serial` n'est plus une console de débogage en mode GSM réel. Les diagnostics et anciennes commandes `1/0/?` du M09 doivent être transférés vers un mode de simulation/maintenance clairement séparé ou remplacés par un mécanisme documenté et testé. Éviter tout octet parasite transmis au modem. Prévoir une isolation du GSM pendant les essais/programmation UART. Le PZEM migre sur D6/D7, laissant D11/MOSI disponible pour l'ISP. Pendant l'utilisation du sketch M09 historique, isoler l'ancien PZEM de D11 lors de la programmation.

**Sécurité :** alimentation SIM800L adaptée à la carte exacte (module nu : typiquement ~4,0 V et pointes proches de 2 A, jamais 5 V direct sur VBAT), masse commune, découplage, adaptation de niveau logique **dans les deux sens** entre modem et ATmega 5 V. Maintenir le mode simulation par défaut, sans modem ni secteur. Vérifier la compatibilité des cartes avant réalisation du PCB.

**Recette attendue :** commandes AT et réponses interprétées sans bloquer les relevés ; gestion des délais, absence de réseau et réessais bornés ; tests de non-régression M09, compilation en simulation, puis essais physiques consignés. La présente règle ne signifie pas que M10 est déjà implémenté.

[Décision permanente — attribution des interfaces](../../../docs/formation/REGLE_EVOLUTION_CONTINUE.md#attribution-des-interfaces-matérielles-à-partir-de-m10)

**Migration M09 → M10 requise :** le code historique contient `SoftwareSerial portPzem(10, 11)`. Dans le nouveau firmware M10 uniquement, passer à `SoftwareSerial portPzem(6, 7)` (RX=D6, TX=D7), mettre à jour le snapshot M10, le manifeste, les tests et les schémas ; conserver M03–M09 intacts.

**Avant d'implémenter M10 :** consulter le [tableau officiel d'affectation des 28 broches ATmega328P-PU](../../../docs/hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md) pour confirmer les UART, l'ISP et les interfaces I2C. Les réservations facultatives D3/D4/D5 ne doivent pas être activées sans validation préalable.

## Objectif et prérequis

Objectif : comprendre le modem et les commandes AT. Prérequis : M05 et M09. Durée : 14 minutes.

## Vidéos du module

- [M10-V01 — Tester le SIM800L et comprendre les commandes AT (7 min)](videos/V01-plan.md) · [Script](scripts/V01-script.md) · [Diapositives](slides/V01-storyboard.md)
- [M10-V02 — Transmettre une mesure par GPRS et traiter les erreurs (7 min)](videos/V02-plan.md) · [Script](scripts/V02-script.md) · [Diapositives](slides/V02-storyboard.md)

## Préparer et évaluer

- [Travaux pratiques et exercices](tp/README.md)
- [Banque de quiz et objectifs de validation](quiz/README.md)
- [Supports et ressources téléchargeables](ressources/README.md)
- [Code et fichiers techniques](code/README.md)
- [Suivi de production](production/README.md)

## Indications du plan initial

**Ressources :** catalogue de commandes AT, fiche d'alimentation, APN fictif de test et scripts de simulation.

**Quiz M10 :** UART, SIM, APN, réponses AT, GPRS et sécurité.

**Validation :** expliquer le cycle de connexion et identifier une panne sans mettre le modem en danger.

## Documents de référence

[Plan complet de la formation 4 h](../../../docs/formation/PLAN_FORMATION_4H.md) · [Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md)

> Les fiches vidéo reprennent le plan validé. Les scripts, slides, quiz corrigés et programmes ne sont pas présentés comme terminés tant qu'ils n'ont pas été effectivement produits et vérifiés.
