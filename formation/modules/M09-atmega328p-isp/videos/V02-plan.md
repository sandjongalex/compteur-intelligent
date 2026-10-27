# M09-V02 — Programmer par ArduinoISP et préserver le firmware (8 min)

**Méthode pratique sans PowerPoint : Uno programmateur → six signaux ISP → cible → test minimal → firmware cumulatif M09 → dépannage.**

| Temps | Démonstration | Ressource |
|---|---|---|
| 00:00–00:50 | Présenter Uno programmateur versus puce cible | [Guide ISP](../ressources/PROGRAMMATION_ISP.md) |
| 00:50–01:55 | Télécharger **ArduinoISP dans la Uno** | [Procédure](../ressources/PROGRAMMATION_ISP.md) |
| 01:55–03:15 | Connecter D10/11/12/13 vers RESET1/MOSI17/MISO18/SCK19 | [Table ISP](../ressources/BROCHAGE_ISP_PU28.md) |
| 03:15–04:30 | Board Uno 16 MHz, Arduino as ISP, fuses/horloge, Upload Using Programmer | [Guide ISP](../ressources/PROGRAMMATION_ISP.md) |
| 04:30–05:30 | Test diagnostic LED externe | [Sketch diagnostic](../code/V01_01_diagnostic_led/V01_01_diagnostic_led.ino) |
| 05:30–06:50 | Reprendre **M08** et téléverser **le firmware M09** | [Snapshot M09](../../../../firmware/etapes/M09/Compteur_M09/Compteur_M09.ino) |
| 06:50–07:30 | Diagnostiquer signature/RESET/horloge et UART de la cible | [Dépannage](../ressources/DEPANNAGE.md) |
| 07:30–08:00 | TP : justifier toutes les broches et test de non-régression | [TP02](../tp/TP_M09_APPRENANT.md) |

[**Lire le script oral complet M09-V02**](../scripts/V02-script.md).

Aucun essai secteur ; une réussite de compilation seule n'est pas présentée comme un transfert ISP physique réussi. La Uno programmateur ne fournit pas automatiquement le moniteur série de l'ATmega328P externe.
