# M07-V01 — Lire et régler l'horloge DS3231 (7 min)

**État : script et 3 sketches rédigés, tests réels/chronométrage encore à faire. Aucun PowerPoint.**

## Fil pédagogique : résultat → scanner → lire → régler une seule fois

| Temps | Manipulation | Fichier |
|---|---|---|
| 00:00–00:45 | Montrer une date/heure **vraiment issue de la RTC**, si testée | [V01-02](../code/V01_02_lire_ds3231/V01_02_lire_ds3231.ino) |
| 00:45–01:55 | Comprendre SDA/SCL et le bus partagé | [Guide I2C](../ressources/BUS_I2C_SECURITE.md) |
| 01:55–02:55 | Scanner et observer une réponse 0x68 | [V01-01](../code/V01_01_scanner_i2c/V01_01_scanner_i2c.ino) |
| 02:55–04:15 | `rtc.begin()`, `lostPower()`, `rtc.now()`, DateTime | [V01-02](../code/V01_02_lire_ds3231/V01_02_lire_ds3231.ino) |
| 04:15–05:20 | Réglage délibéré avec verrou `false` par défaut | [V01-03](../code/V01_03_regler_ds3231_une_fois/V01_03_regler_ds3231_une_fois.ino) |
| 05:20–06:10 | Erreurs : module absent, date fausse, pile incompatible | [Dépannage](../ressources/DEPANNAGE.md) |
| 06:10–07:00 | Défi : date et heure complètes formatées | [TP01](../tp/TP_M07_APPRENANT.md) |

[**Script du formateur à prononcer et manipulations détaillées**](../scripts/V01-script.md).

**Critère de réussite :** une date fiable n'est jamais inventée ; l'horloge n'est pas réinitialisée à chaque boot. Le réglage n'est effectué qu'après vérification des valeurs et du module.
