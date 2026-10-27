# M09 — Corrections et barèmes des TP (formateur)

## TP01 — Schéma minimal DIP28

Correspondances attendues :

| Élément | Broche ATmega328P PDIP28 | Complément |
|---|---:|---|
| RESET | **1** | Pull-up 10 kΩ au +5 V |
| RX/TX | **2 et 3** | UART TTL compatible avec la cible |
| D2/PD2 | **4** | Bouton vers GND, `INPUT_PULLUP` |
| VCC et GND | **7 et 8** | 5 V régulé + 100 nF proche |
| XTAL1 / XTAL2 | **9 et 10** | Quartz externe 16 MHz, charges adaptées |
| MOSI | **17** | D11 de la Uno programmateur |
| MISO | **18** | D12 de la Uno programmateur |
| SCK / D13 / PB5 | **19** | D13 de la Uno programmateur, LED externe avec résistance |
| AVCC | **20** | +5 V propre |
| AREF | **21** | Référence ADC, ne pas relier à +5 V par automatisme |
| GND | **22** | Masse |
| SDA/SCL | **27 et 28** | A4/A5 Arduino pour DS3231/LCD I2C |

**Barème TP01 /10 :** orientation et broche 1 (1), alimentation VCC/AVCC/GND (2), RESET (1), découplage (2), quartz et fuses 16 MHz (2), D2/D13 et ISP (2). Toute inversion d'alimentation interdit de valider le circuit, quelle que soit la note.

**Commentaire pédagogique :** « 16 MHz » dans l'IDE est un paramètre de compilation ; la présence et la conformité du quartz sont des conditions du banc matériel.

## TP02 — ArduinoISP puis même firmware M09

**Code de test :** [diagnostic LED](../code/V01_01_diagnostic_led/V01_01_diagnostic_led.ino). **Projet principal :** [snapshot M09](../../../../firmware/etapes/M09/Compteur_M09/Compteur_M09.ino).

Schéma de câblage correct : `Uno D10 → RESET pin1`, `Uno D11 → MOSI pin17`, `Uno D12 → MISO pin18`, `Uno D13 → SCK pin19`, GND commun, 5 V régulé compatible et sans double source. **Uno programmateur ≠ cible ATmega328P.**

**Séquence :** téléverser ArduinoISP **sur la Uno** → couper alimentation pour câbler → configurer profil cible Uno 16 MHz et programmateur **Arduino as ISP** → configurer les fuses si nécessaire et avec l'horloge compatible déjà installée → **Upload Using Programmer** sur la cible → démontrer une LED réellement reliée à PB5 et **alimentée par la cible autonome**. Après diagnostic, transférer le **snapshot M09**, pas un nouveau Blink de remplacement.

**Fonctions M08 à conserver :** bouton D2, LED commandée, UART 1/0/?, six mesures (simulation par défaut), date RTC simulée ou réelle selon option, cumuls jour/mois, validation des relevés, indication des périodes partielles. **Différence M09 :** option de cible autonome, contrôle F_CPU et fonction de diagnostic des broches ; aucun algorithme énergétique n'est supprimé.

**Barème TP02 /10 :** connexion ISP correcte (3), bon choix programmateur/téléversement (2), lecture des résultats diagnostiques (2), continuité firmware M08 (2), présentation honnête des tests (1). Une procédure de compilation seule, faute de matériel, doit être explicitement notée **partielle**.

## Diagnostic du mini-défi

Une compilation Arduino prouve la cohérence du **code source pour une cible configurée**, mais n'interroge pas la puce réelle. En cas d'erreur ISP, vérifier :
1. RESET cible et les trois lignes MOSI/MISO/SCK (sens correct) ;
2. masse commune, niveau et alimentation 5 V régulée, absence de court-circuit ;
3. horloge effectivement disponible et concordance fuses/quartz ;
4. Uno chargée avec **ArduinoISP**, sélection **Arduino as ISP**, port et reset de programmateur ;
5. référence réelle de la cible (**ATmega328P**, pas autre signature).

La compilation du firmware sur Uno n'est pas une preuve d'upload ISP ni d'essai de la puce autonome.

**Seuil : 8/10 par TP + absence d'erreur électrique critique.**
