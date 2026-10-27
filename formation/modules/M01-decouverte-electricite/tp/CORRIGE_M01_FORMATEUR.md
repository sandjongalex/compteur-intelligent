# Exercices M01 — Corrigé du formateur

**Objectif :** permettre une correction explicative, pas seulement fournir les résultats.

### Correction du TP 01

```text
PZEM-004T --mesure--> ATmega328P --prépare les données--> SIM800L
                                                       |
                                                       v
                                                   GSM/GPRS
                                                       |
                                                       v
                                               Flask + SQLite
                                                       |
                                                       v
                                                Navigateur web
```

Le PZEM **mesure**, l'ATmega328P **traite**, le SIM800L **transmet**, le backend Flask/SQLite **reçoit et enregistre**, le navigateur **consulte** les données. Le LCD est branché **localement** au microcontrôleur, sans être le modem ni le serveur. Le **DS3231** fournit date et heure ; la **FRAM** conserve les enregistrements locaux lorsque nécessaire.

**Barème sur 10 :** ordre correct 5 points ; fonctions 3 points ; LCD 1 point ; DS3231/FRAM 1 point.

**Dépannage pédagogique :** si l'apprenant place SQLite avant le GSM, lui rappeler que le serveur n'a pas de moyen direct de lire le PZEM : il reçoit d'abord une transmission de l'appareil.

---

### Correction du TP 02

Formule dans ces exemples : **Énergie (kWh) = Puissance active (kW) × Durée (h).**

- **A :** 200 W = 0,2 kW ; 0,2 × 5 = **1 kWh**.
- **B :** 500 W = 0,5 kW ; 0,5 × 4 = **2 kWh**.
- **C :** 2 000 W = 2 kW ; 30 min = 0,5 h ; 2 × 0,5 = **1 kWh**.
- **D :** 100 W = 0,1 kW ; 15 min = 0,25 h ; 0,1 × 0,25 = **0,025 kWh**.

1. **W** est une unité de puissance ; **Wh** une unité d'énergie.
2. **230,5 V** est une tension.
3. **Non** : une valeur de puissance instantanée ne suffit pas si la puissance change ; il faut connaître son évolution dans le temps ou utiliser un index de mesure d'énergie comme celui du PZEM.

**Barème sur 10 :** 1,5 point pour chaque calcul A à D (6 points), 1 point par réponse complémentaire (3 points), unités correctement notées (1 point).

**Erreurs fréquentes :** oublier de diviser les watts par 1 000 ; multiplier 2 kW par 30 au lieu de 0,5 ; confondre W, Wh et kWh ; inférer une consommation réelle à partir d'une valeur fictive isolée.

---

## Validation

- TP 01 : au moins 8/10, ordre et rôles expliqués.
- TP 02 : au moins 8/10, conversions et unités comprises.
- [Corrigé du quiz](../quiz/CORRIGE_M01_FORMATEUR.md).
