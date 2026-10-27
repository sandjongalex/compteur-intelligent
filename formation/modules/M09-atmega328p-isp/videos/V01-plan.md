# M09-V01 — Construire le circuit minimal ATmega328P (8 min)

**Méthode pratique sans PowerPoint : résultat → comparaison Uno/puce nue → identification DIP28 → alimentation/horloge → correspondance firmware → contrôle.**

| Temps | Démonstration | Ressource |
|---|---|---|
| 00:00–00:55 | Montrer l'ancien firmware M08 sur Uno et la cible M09 | [Firmware M08](../../../../firmware/etapes/M08/Compteur_M08/Compteur_M08.ino) |
| 00:55–02:05 | Distinguer carte Uno et ATmega328P PDIP28 autonome | [Brochage](../ressources/BROCHAGE_ISP_PU28.md) |
| 02:05–03:15 | Encoche, VCC 7, AVCC 20, GND 8/22, RESET 1 | [Table DIP28](../ressources/BROCHAGE_ISP_PU28.md) |
| 03:15–04:35 | Découplage, quartz 16 MHz broches 9/10, relation fuses/F_CPU | [Montage minimal](../ressources/BROCHAGE_ISP_PU28.md) |
| 04:35–05:45 | D2=PD2 broche4, D13=PB5 broche19 ; LED externe + résistance | [Exercice TP01](../tp/TP_M09_APPRENANT.md) |
| 05:45–06:55 | Montrer changements minimes dans M09 ; préserver M08 | [Firmware M09](../../../../firmware/etapes/M09/Compteur_M09/Compteur_M09.ino) |
| 06:55–07:35 | Détecter mauvais câblage, alimentation ou horloge | [Dépannage](../ressources/DEPANNAGE.md) |
| 07:35–08:00 | Défi : annoter boîtier et expliquer le rôle du quartz | [TP01](../tp/TP_M09_APPRENANT.md) |

[**Lire le script oral complet M09-V01**](../scripts/V01-script.md).

Le montage physique est **hors tension pendant les modifications**, puis testé uniquement à 5 V régulé sur un banc vérifié. Chronométrage et validations réelles à renseigner dans la fiche de production.
