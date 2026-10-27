# Mémo pédagogique — PZEM-004T version 3.0

## Six valeurs principales

| Méthode de la bibliothèque `PZEM004Tv30` | Grandeur | Unité |
|---|---|---|
| `voltage()` | Tension | V |
| `current()` | Courant | A |
| `power()` | Puissance **active** | W |
| `energy()` | Index énergie **cumulée** | kWh |
| `frequency()` | Fréquence | Hz |
| `pf()` | Facteur de puissance | sans unité, généralement de 0 à 1 |

## Carte des registres d'entrée (V3.0)

| Registre | Donnée | Transformation |
|---|---|---|
| `0x0000` | Tension | Brut / 10 = V |
| `0x0001`, `0x0002` | Courant : mot bas et haut | 32 bits / 1000 = A |
| `0x0003`, `0x0004` | Puissance : mot bas et haut | 32 bits / 10 = W |
| `0x0005`, `0x0006` | Énergie : mot bas et haut | 32 bits en Wh / 1000 = kWh |
| `0x0007` | Fréquence | Brut / 10 = Hz |
| `0x0008` | Facteur de puissance | Brut / 100 |
| `0x0009` | État d'alarme | `0x0000` normal ; `0xFFFF` alarme |

Assemblage : `((uint32_t)haut << 16) | bas`. L'ordre des mots **bas, haut** est celui de cette version.

## Comprendre Modbus RTU

La liaison série UART transporte les octets. Modbus RTU donne du sens aux octets : adresse de l'appareil, code fonction, registre, nombre de registres, données et CRC.

Pour lire les dix registres d'entrée à partir de zéro, la requête utilise la fonction **0x04**. Le CRC n'est **pas** inventé dans les exemples : la bibliothèque s'en charge.

**Architecture fonctionnelle :** `ATmega328P ⇄ UART/Modbus ⇄ PZEM V3`. Ceci n'est **pas un schéma secteur ni un guide de raccordement physique**.

## Exemple chiffré fictif

| Brut | Décodage |
|---|---|
| tension 2305 | 230,5 V |
| courant 500 (haut 0) | 0,500 A |
| puissance 922 (haut 0) | 92,2 W |
| énergie 12345 Wh (haut 0) | 12,345 kWh |
| fréquence 500 | 50,0 Hz |
| facteur de puissance 80 | 0,80 |

Ces valeurs viennent du **code simulé**, pas d'une mesure réalisée.

L'index énergie est cumulatif : il ne donne **pas** directement les kWh du jour ou du mois. Ces périodes seront calculées aux M08/M11 avec la date et la persistance, sans `resetEnergy()` quotidien.

Sources techniques :
- https://github.com/mandulaj/PZEM-004T-v30
- https://github.com/mandulaj/PZEM-004T-v30/blob/master/src/PZEM004Tv30.cpp
