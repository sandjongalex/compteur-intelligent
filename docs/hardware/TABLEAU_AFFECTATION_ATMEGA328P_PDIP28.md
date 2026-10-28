# Tableau d'affectation des composants — Compteur intelligent ATmega328P PDIP-28

**Statut : référence d'architecture pour M10–M16 (préparation du PCB KiCad).**
**Cible : ATmega328P-PU, boîtier PDIP à 28 broches, horloge externe 16 MHz, logique microcontrôleur 5 V.**
Les broches physiques ne correspondent pas à la numérotation Arduino. Le firmware actuellement publié est M09 ; le modem GSM et la FRAM ne sont pas encore implémentés. **Migration approuvée pour M10 : le PZEM passe de D10/D11 (code historique M09) à D6/D7 (câblage cible M10–M16).** Les snapshots M03–M09 restent inchangés. **Ne pas confondre un choix de brochage avec un essai matériel réussi.**

Références : [règles permanentes](../formation/REGLE_EVOLUTION_CONTINUE.md#attribution-des-interfaces-matérielles-à-partir-de-m10), [brochage et ISP M09](../../formation/modules/M09-atmega328p-isp/ressources/BROCHAGE_ISP_PU28.md), [module M10](../../formation/modules/M10-sim800l-gsm-gprs/README.md).

## 1. Tableau fonctionnel de raccordement (affectations validées)

| Composant | Signal composant | Broche Arduino | Port ATmega328P | Broche physique PDIP28 | Liaison / observation |
|---|---|---|---|---:|---|
| **SIM800L** | **TXD** | **D0 / RX** | PD0 / RXD | **2** | Sortie modem vers entrée AVR, adaptation des niveaux à vérifier dans ce sens. UART matériel réservé au modem en mode GSM réel. |
| **SIM800L** | **RXD** | **D1 / TX** | PD1 / TXD | **3** | Sortie AVR vers entrée modem, adaptation de niveaux obligatoire selon la carte exacte. |
| **Bouton** | Signal, vers GND à l'appui | **D2** | PD2 | **4** | `INPUT_PULLUP`, conserver le comportement M09. |
| **PZEM-004T V3** | **TXD** | **D6 / RX logiciel** | PD6 | **12** | Vers RX de `SoftwareSerial(6, 7)`. Niveaux et isolation du module exact à vérifier. |
| **PZEM-004T V3** | **RXD** | **D7 / TX logiciel** | PD7 | **13** | Depuis TX de `SoftwareSerial(6, 7)`. Aucun partage de MOSI/ISP. |
| **LED témoin** | Anode via résistance | **D13** | PB5 / SCK | **19** | LED externe + résistance de limitation, ne pas perturber SCK/ISP. |
| **RTC DS3231** | SDA | **A4 / SDA** | PC4 | **27** | Bus I2C partagé. |
| **RTC DS3231** | SCL | **A5 / SCL** | PC5 | **28** | Bus I2C partagé. |
| **LCD 20×4 à adaptateur I2C** | SDA / SCL | **A4 / A5** | PC4 / PC5 | **27 / 28** | Même bus, adresse I2C à confirmer sur le module physique. |
| **FRAM à interface I2C (M11)** | SDA / SCL | **A4 / A5** | PC4 / PC5 | **27 / 28** | Référence FRAM, adresse, alimentation et pull-ups à confirmer avant achat/PCB. |

**Autres broches proposées, pas encore figées ni développées :**

| Composant / fonction potentielle | Broche proposée | Port / broche PDIP28 | Statut |
|---|---|---|---|
| Buzzer d'alerte | **D3** | PD3 / **5** | **Réservation proposée** ; choisir circuit de commande (transistor si requis), vérifier le courant. |
| Commande `PWRKEY` du SIM800L | **D4** | PD4 / **6** | **Optionnelle** selon variante GSM ; utiliser un étage adapté, jamais pilotage 5 V direct sans validation. |
| Retour `STATUS` SIM800L | **D5** | PD5 / **11** | **Optionnelle**, respecter les niveaux électriques et disponibilité des signaux. |

## 2. Affectation complète des 28 broches physiques

| Broche physique | Port / nom ATmega328P | Numérotation Arduino | Destination |
|---:|---|---|---|
| **1** | PC6 / RESET | RESET | RESET pull-up 10 kΩ vers +5 V et entrée RESET ISP |
| **2** | PD0 / RXD | D0 / RX | SIM800L TXD (UART matériel, niveaux adaptés) |
| **3** | PD1 / TXD | D1 / TX | SIM800L RXD (UART matériel, niveaux adaptés) |
| **4** | PD2 | D2 | Bouton vers GND |
| **5** | PD3 / OC2B | D3 | Réservation proposée : buzzer |
| **6** | PD4 | D4 | Réservation proposée : GSM PWRKEY |
| **7** | VCC | — | +5 V régulé + condensateur 100 nF proche |
| **8** | GND | — | Masse |
| **9** | PB6 / XTAL1 | — | Quartz externe 16 MHz |
| **10** | PB7 / XTAL2 | — | Quartz externe 16 MHz |
| **11** | PD5 / OC0B | D5 | Réservation proposée : modem STATUS |
| **12** | PD6 | D6 | RX logiciel depuis PZEM TXD (à partir de M10) |
| **13** | PD7 | D7 | TX logiciel vers PZEM RXD (à partir de M10) |
| **14** | PB0 | D8 | Libre |
| **15** | PB1 | D9 | Libre |
| **16** | PB2 / SS | D10 | Libre pour extension ; usage SPI SS à préserver si SPI utilisé |
| **17** | PB3 / MOSI | D11 | MOSI du connecteur ISP, sans liaison PZEM à partir de M10 |
| **18** | PB4 / MISO | D12 | MISO ISP, réservé à la programmation/maintenance |
| **19** | PB5 / SCK | D13 | LED avec résistance + SCK ISP, limiter la charge |
| **20** | AVCC | — | +5 V régulé et découplage |
| **21** | AREF | — | Référence analogique : condensateur vers GND selon datasheet et usage ADC, ne pas relier directement à VCC sans étude |
| **22** | GND | — | Masse |
| **23** | PC0 / ADC0 | A0 | Libre |
| **24** | PC1 / ADC1 | A1 | Libre |
| **25** | PC2 / ADC2 | A2 | Libre |
| **26** | PC3 / ADC3 | A3 | Libre |
| **27** | PC4 / SDA | A4 | SDA commun : RTC, LCD I2C, FRAM I2C |
| **28** | PC5 / SCL | A5 | SCL commun : RTC, LCD I2C, FRAM I2C |

## 3. Interfaces et câblage de maintenance

- **UART0 :** SIM800L TXD → ATmega PD0/D0/RX et ATmega PD1/D1/TX → SIM800L RXD. En mode GSM réel, `Serial` est **exclusivement** réservé au modem : déplacer/supprimer les logs et anciennes commandes de diagnostic du M09 après une migration testée ; prévoir un mode maintenance ou simulation distinct. Une liaison USB–TTL et le SIM800L ne doivent pas piloter simultanément D0/D1.
- **UART logiciel :** un seul `SoftwareSerial(6, 7)` pour le PZEM **à partir de M10** ; D6 reçoit TXD du PZEM, D7 transmet vers RXD du PZEM. Les broches D10/D11 ne sont plus câblées au PZEM ; D11 demeure MOSI pour l'ISP. Le firmware et les snapshots historiques M09 conservent `SoftwareSerial(10, 11)` jusqu'à la migration explicite M10. Respecter l'isolation électrique de l'interface PZEM et garder le connecteur ISP accessible.
- **ISP sur cible PDIP28 :** D10 du **programmateur Arduino Uno** → RESET cible broche 1 ; D11 programmateur → MOSI cible 17 ; D12 → MISO 18 ; D13 → SCK 19 ; GND commun et alimentation cible contrôlée. La broche D10 du programmateur n'est **pas** la broche D10 de la cible. Le PZEM étant déplacé sur D6/D7 à partir de M10, il ne partage plus MOSI.
- **Bus I2C :** A4 et A5 partagés : RTC DS3231 (adresse normalement 0x68), LCD I2C (souvent 0x27 ou 0x3F) et FRAM (adresse selon référence/câblage). Faire un scan I2C sur matériel avant de figer les adresses, vérifier les pull-ups cumulées et la tension de fonctionnement de chaque composant. Les modules 3,3 V ne doivent pas subir des pull-ups I2C vers 5 V s'ils ne sont pas tolérants.
- **Horloge :** quartz 16 MHz broches 9/10 et condensateurs correspondant aux spécifications du quartz et aux fuses, pas une capacité universelle.
- **Alimentation logique :** VCC broche 7 et AVCC broche 20 alimentés à 5 V régulé, GND broches 8 et 22 reliés ; découplage 100 nF près des alimentations ; RESET broche 1 avec 10 kΩ vers VCC, connecteur ISP accessible.
- **SIM800L :** pour un module nu, tension VBAT généralement 3,4 à 4,4 V (environ 4,0 V recommandé) et capacité à fournir des pointes voisines de 2 A ; ne jamais relier VBAT à 5 V. Vérifier la carte exacte car certains breakouts incluent des régulateurs. Adapter les niveaux **dans les deux sens** (le TXD modem à ~2,8 V peut être insuffisant pour un AVR 5 V). Masse commune, protection et découplage local adaptés.
- **PZEM / secteur :** toutes les manipulations sur le réseau monophasé et le raccordement des parties sous tension restent réservés à un banc qualifié et à une personne compétente. Préserver les protections et barrières d'isolation de l'interface série.
- **Buzzer / PWRKEY / STATUS :** simples suggestions pour le PCB M15, **non engagées** dans M09 ou M10 tant que schéma, disponibilité des ports et besoins ne sont pas validés. Laisser ces broches libres du firmware tant qu'il n'y a pas de composant.

## 4. Contrôle de cohérence avant KiCad/M10

- [ ] ATmega328P **PDIP28** et boîtier final confirmés ; fuses/16 MHz cohérents.
- [ ] D0/D1 pour SIM800L, niveaux et alimentation validés sur la **référence exacte**.
- [ ] D6/D7 pour PZEM en M10–M16 ; vérifier RX/TX croisés, interface et absence de conflit avec l'ISP. En M09 historique, D10/D11 restent documentés comme anciens choix.
- [ ] SDA A4 / SCL A5 compatibles entre RTC, LCD, FRAM ; scan I2C et pull-ups contrôlés.
- [ ] Aucune sortie GSM reliée simultanément à l'USB–TTL sur D0/D1.
- [ ] LED D13 et connecteur ISP ne se perturbent pas.
- [ ] Buzzer et PWRKEY/STATUS explicitement approuvés avant réservation définitive.
- [ ] Les broches attribuées sont reflétées dans firmware, documentation, tests et futur PCB.
- [ ] Aucun test physique n'est déclaré réussi sans mesures et vérifications sur la carte.
