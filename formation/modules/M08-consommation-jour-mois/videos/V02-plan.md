# M08-V02 — Minuit, mois, erreurs et reprise (8 minutes)

**Statut : script et code rédigés ; essais Arduino et chronométrage encore à faire.** Aucun PowerPoint.

| Minute | Résultat montré / code construit |
|---|---|
| 00:00–00:55 | Frontière **31/01 à 23:59 → 01/02 à 00:00** |
| 00:55–02:10 | Relevé daté : date fiable + index cumulatif valide |
| 02:10–03:20 | Moteur [V02-01, janvier/février](../code/V02_01_passer_au_mois/V02_01_passer_au_mois.ino) |
| 03:20–04:30 | Expliquer indicateurs **complet/partiel**, différence jour/mois |
| 04:30–05:55 | [V02-02](../code/V02_02_reprise_et_erreurs/V02_02_reprise_et_erreurs.ino) : reprise d'état **conservé en RAM**, doublon, reset |
| 05:55–06:55 | Horloge rétrograde, remise à zéro de l'index, mesure invalide |
| 06:55–07:35 | [V02-03](../code/V02_03_ds3231_lcd_fictif/V02_03_ds3231_lcd_fictif.ino) : date RTC réelle + valeurs simulées LCD |
| 07:35–08:00 | Exercice d'attribution des deltas et transition M09/M11 |

[**Script oral intégral V02**](../scripts/V02-script.md) · [TP02 apprenant](../tp/TP_M08_APPRENANT.md).

**Points de prudence :** une reprise en RAM ne survit pas à une vraie coupure, et le LCD indique les périodes **partielles**.
