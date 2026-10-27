# M07-V02 — Écran LCD I2C 20×4 (7 min)

**État : script et 3 sketches rédigés ; rendu LCD réel/chronométrage à confirmer. Aucun PowerPoint.**

## Fil pédagogique : voir les 4 lignes → coder → combiner RTC → diagnostiquer

| Temps | Manipulation | Fichier |
|---|---|---|
| 00:00–00:45 | Montrer les quatre lignes de la maquette (énergies **simulées**) | [V02-02](../code/V02_02_lcd_4_lignes_simulees/V02_02_lcd_4_lignes_simulees.ino) |
| 00:45–01:50 | Comprendre 20 colonnes, 4 lignes, adresse/adaptateur I2C | [Guide I2C](../ressources/BUS_I2C_SECURITE.md) |
| 01:50–02:50 | Afficher un premier texte avec `lcd.begin(20,4)` | [V02-01](../code/V02_01_lcd_bonjour/V02_01_lcd_bonjour.ino) |
| 02:50–04:00 | Écrire quatre lignes de 20 caractères sans anciens résidus | [V02-02](../code/V02_02_lcd_4_lignes_simulees/V02_02_lcd_4_lignes_simulees.ino) |
| 04:00–05:25 | Réunir RTC et LCD sur I2C ; date fiable | [V02-03](../code/V02_03_rtc_lcd_integres/V02_03_rtc_lcd_integres.ino) |
| 05:25–06:15 | Diagnostiquer écran vide, mauvais contraste, `lcd.clear()` répété | [Dépannage](../ressources/DEPANNAGE.md) |
| 06:15–07:00 | Défi : une seconde page courant/puissance fictifs | [TP02](../tp/TP_M07_APPRENANT.md) |

[**Script oral complet et étapes de démonstration**](../scripts/V02-script.md).

**Critère de réussite :** les quatre informations sont lisibles, aucune ligne ne déborde, le LCD ne clignote pas excessivement et les données fictives sont distinguées des mesures réelles. Les calculs des kWh par période viendront au **Module 08**.
