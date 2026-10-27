# M02 — Nomenclature préliminaire (BOM)

**Statut : liste pédagogique indicative, références exactes, quantités finales, coûts et fournisseurs à valider avant achat.** Le circuit final n'est pas considéré comme testé ou certifié.

| Élément | Quantité pédagogique | Rôle | Vérification avant montage |
|---|---:|---|---|
| ATmega328P DIP-28 | 1 | Microcontrôleur autonome | Référence, support, horloge et brochage |
| Arduino Uno Rev3 | 1 | Apprentissage et programmateur ISP | Version de carte, connecteur ISP, alimentation 5 V |
| PZEM-004T V3.0 + transformateur de courant compatible | 1 ensemble | Mesure des grandeurs électriques | Variante exacte, plage de mesure, documentation de pose qualifiée |
| DS3231 + pile de sauvegarde appropriée | 1 | Date/heure | Type de module, compatibilité pile/recharge, adressage I2C |
| LCD 20×4 + interface I2C | 1 | Affichage local | Tension de l'ensemble, adresse et backpack I2C |
| Mémoire FRAM non volatile (par exemple carte 256 Kbit compatible I2C) | 1 | État et file des mesures | Référence et compatibilité 5 V/I2C ; vérifier les niveaux |
| SIM800L + antenne + SIM appropriée | 1 | Transmission GSM/GPRS | Modem nu ou carte avec régulateur ; couverture 2G ; tensions UART |
| Régulateur DC/DC réglé à environ 4,0 V, dimensionné pour les pointes | 1 | Alimenter le modem | Exigences réelles de VBAT, pointe jusqu'à ~2 A, qualité de régulation |
| Alimentation AC/DC **isolée et adaptée** au secteur | 1 | Fournir la basse tension depuis une source appropriée | Certification, puissance, isolation, protections, installation qualifiée |
| Quartz 16 MHz + condensateurs adaptés | 1 jeu | Cadence de l'ATmega | Type exact, configuration d'horloge et caractéristiques du quartz |
| Résistances, condensateurs de découplage, adaptation UART | Selon schéma validé | Interfaces et stabilité des tensions | Dimensionnement et compatibilité |
| Bouton, LED, buzzer avec commande adaptée | Selon interface | Interaction et signalisation | Courants, résistances et composants de commande |
| Connecteur ISP, connecteurs, circuit imprimé, boîtier | Selon conception | Programmation et réalisation physique | Encombrement, isolement, robustesse, accès |
| Fusibles et protections secteur | Selon étude qualifiée | Sécurité électrique | Dimensionnement, norme, coordination et essais qualifiés |

## Ordre conseillé de disponibilité du matériel

Pour le **Module 03**, l'apprenant n'a besoin que d'une **Arduino Uno Rev3, d'une LED et d'une résistance adaptée**, avec un ordinateur et un câble USB de données. Il n'a pas besoin de connecter le secteur pour débuter.

Le PZEM et les alimentations de l'installation finale doivent être présentés hors tension dans cette formation ; toute manipulation du 230 V sera conduite uniquement par une personne qualifiée.

## Références documentaires

- [Arduino Uno Rev3, spécifications officielles](https://store.arduino.cc/products/arduino-uno-rev3)
- [ATmega328P, page Microchip](https://www.microchip.com/en-us/product/ATMEGA328P)
- [SIM800L Hardware Design, spécifications de VBAT](https://www.electrokit.com/upload/product/41018/41018214/SIM800L-SIMCom.pdf)

**Important :** Microchip indique désormais l'ATmega328P comme *Not Recommended for new designs*. Il est conservé ici comme plateforme pédagogique décidée pour ce cours, sans le présenter comme une recommandation universelle pour de nouveaux produits industriels.
