# M06-V01 — Comprendre le PZEM et Modbus RTU (8 minutes)

**Statut : script complet, deux programmes de simulation et mémo de registres rédigés ; essais Uno et enregistrement à réaliser.**

## Progression : résultat → comprendre → décoder → vérifier

| Moment | Action à l'écran | Ressource |
|---|---|---|
| 00:00–00:55 | Ouvrir la console : six valeurs **SIMULÉES** | [V01-01](../code/V01_01_six_grandeurs_simulees/V01_01_six_grandeurs_simulees.ino) |
| 00:55–02:05 | Montrer hors tension le PZEM, six grandeurs et unités | [Mémo V3](../ressources/MEMO_PZEM_V3.md) |
| 02:05–03:15 | Schéma fonctionnel UART / Modbus, requête et réponse | [Protocole](../ressources/MEMO_PZEM_V3.md) |
| 03:15–04:35 | Registres 0x0000 à 0x0009, conversions d'échelle | [Mémo V3](../ressources/MEMO_PZEM_V3.md) |
| 04:35–05:55 | Ouvrir et expliquer les structures puis les registres fictifs | [V01-01](../code/V01_01_six_grandeurs_simulees/V01_01_six_grandeurs_simulees.ino), [V01-02](../code/V01_02_registres_decodes/V01_02_registres_decodes.ino) |
| 05:55–06:55 | Prédire la sortie, compiler sur Uno et observer la console | [Plan de tests](../ressources/PLAN_TESTS.md) |
| 06:55–08:00 | Mini-défi : 2305 → 2312, expliquer la conversion | [TP01](../tp/TP_M06_APPRENANT.md) |

**[Lire le script oral intégral](../scripts/V01-script.md).** Le temps est une cible de montage et doit être chronométré.

**Compétence attendue :** l'apprenant explique pourquoi 2305 devient **230,5 V**, pourquoi 12345 Wh deviennent **12,345 kWh**, et pourquoi deux registres peuvent former un entier 32 bits. Le PZEM n'est **pas branché** durant cette leçon.
