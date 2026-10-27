# M09 — Référence de brochage : ATmega328P **PDIP28 uniquement**

**Attention à la géométrie :** vue du composant **par-dessus**, encoche de repérage vers le haut, numérotation dans le sens antihoraire. Ce tableau ne s'applique pas directement aux boîtiers CMS TQFP/MLF.

| Fonction | Arduino Uno | Broche physique PDIP28 | Broche µC | Observation |
|---|---|---:|---|---|
| RESET cible | — | **1** | PC6/RESET | Pull-up **10 kΩ** vers VCC ; D10 du programmateur pendant ISP |
| RX série cible | **D0** | **2** | PD0/RXD | Depuis TX de l'adaptateur USB–TTL compatible 5 V |
| TX série cible | **D1** | **3** | PD1/TXD | Vers RX de l'adaptateur USB–TTL |
| Bouton | **D2** | **4** | PD2 | Bouton vers GND avec `INPUT_PULLUP` |
| VCC | — | **7** | VCC | +5 V régulé et découplage |
| Masse | — | **8** | GND | 0 V |
| Quartz | — | **9** | PB6/XTAL1 | Quartz 16 MHz si fuses configurés externe |
| Quartz | — | **10** | PB7/XTAL2 | Quartz 16 MHz si fuses configurés externe |
| ISP MOSI | **D11** | **17** | PB3/MOSI | Du D11 programmer Uno |
| ISP MISO | **D12** | **18** | PB4/MISO | Vers D12 programmer Uno |
| ISP SCK et LED | **D13** | **19** | PB5/SCK | Du D13 programmer Uno ; LED externe avec résistance |
| AVCC | — | **20** | AVCC | À alimenter correctement à +5 V |
| AREF | — | **21** | AREF | Condensateur conseillé selon référence analogique ; ne pas relier aveuglément au 5 V |
| Masse | — | **22** | GND | 0 V |
| SDA I2C | **A4** | **27** | PC4/SDA | DS3231 et LCD I2C compatibles |
| SCL I2C | **A5** | **28** | PC5/SCL | DS3231 et LCD I2C compatibles |

## Circuit minimal 16 MHz : contrôles

- **VCC 7 + AVCC 20** alimentés à 5 V régulé, **GND 8 et 22** sur masse commune, au moins **100 nF de découplage près de chaque paire alimentation/masse**, plus condensateur de réservoir adapté au banc.
- RESET broche 1 avec **10 kΩ vers +5 V**, et accès RESET au connecteur ISP.
- Quartz **16 MHz** entre broches **9 et 10** avec condensateurs de charge **adaptés au quartz**, souvent de l'ordre de 18–22 pF vers GND, sans les prendre pour une valeur universelle.
- **LED D13** : la puce n'a pas de LED intégrée ; **PB5 broche 19 → résistance ~330 Ω → LED → GND** avec polarité correcte. Attention, cette même broche sert aussi de **SCK ISP** ; ne pas la charger excessivement.
- **Bouton D2** : broche **4** → bouton → GND. Aucun pull-up externe requis pour le sketch, car `INPUT_PULLUP` est activé.
- Éventuel affichage : les modules I2C doivent avoir tensions/niveaux logiques et résistances de tirage compatibles avant raccordement.

## Liaisons Arduino Uno programmateur → cible DIP28

| Programmateur Uno | ATmega328P cible |
|---|---|
| **D10** | RESET **1** |
| **D11 (MOSI)** | MOSI **17** |
| **D12 (MISO)** | MISO **18** |
| **D13 (SCK)** | SCK **19** |
| **GND** | GND **8 ou 22** et rail commun |
| **5 V** | VCC **7**, AVCC **20** (banc basse consommation validé) |

**Deux alimentations 5 V en parallèle sont interdites sans circuit prévu pour cela.** Dans les démonstrations basse consommation, on choisit une seule source 5 V et on vérifie sa capacité.

## Limite à connaître depuis M06

Le mode PZEM de notre code existant utilise par défaut **D10/D11** en `SoftwareSerial`. Or ces broches ont une utilisation particulière pendant l'ISP (**D11/MOSI**, D10/SS côté Arduino). **Pour programmer la puce, déconnecter les périphériques extérieurs pouvant perturber MOSI/SCK/RESET ou repenser l'allocation des broches avant le PCB final.** Le PZEM reste désactivé par défaut dans la démonstration M09 ; ce module n'est pas encore un câblage final de toutes les fonctions.

## Références

- <https://content.arduino.cc/assets/ATmega328P_Datasheet.pdf> — données constructeur et brochages, **sélectionner la figure PDIP28 et non la TQFP32**.
- <https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoISP/> — programmation ArduinoISP (la disponibilité du chemin peut évoluer).
- <https://support.arduino.cc/hc/en-us/articles/6125080065820-Select-programmer-in-Arduino-IDE> — sélection du programmeur.
