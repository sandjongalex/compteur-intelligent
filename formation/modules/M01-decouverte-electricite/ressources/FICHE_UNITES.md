# Fiche mémoire — Grandeurs électriques (M01)

## Les quatre notions à retenir

| Grandeur | Symbole de grandeur | Unité | Symbole de l'unité | Ce que cela représente |
|---|---|---|---|---|
| Tension | U | Volt | V | Différence de potentiel électrique |
| Courant | I | Ampère | A | Débit de charges électriques |
| Puissance active | P | Watt | W | Énergie transférée par unité de temps |
| Énergie | E | Wattheure / kilowattheure | Wh / kWh | Quantité d'énergie cumulée |

La tension n'est pas le courant ; la puissance n'est pas l'énergie.

## Conversions

- **1 kW = 1 000 W**.
- **1 kWh = 1 000 Wh**.
- **30 minutes = 0,5 heure**.
- **15 minutes = 0,25 heure**.

## Calcul de consommation

Si la **puissance active reste constante** :

**E (kWh) = P (kW) × t (h)**.

Exemples :

- 1 000 W pendant 2 h : 1 × 2 = **2 kWh**.
- 500 W pendant 4 h : 0,5 × 4 = **2 kWh**.
- 2 000 W pendant 30 min : 2 × 0,5 = **1 kWh**.
- 200 W pendant 5 h : 0,2 × 5 = **1 kWh**.

Sur un système en courant alternatif, ne pas confondre la puissance apparente Ueff × Ieff (en VA) et la puissance active (en W). Un facteur de puissance peut intervenir. Le PZEM-004T communique directement la puissance active mesurée.

## Erreurs fréquentes

- « 500 W pendant 1 h donne 500 kWh » : **faux**, cela donne 500 Wh = 0,5 kWh.
- « 1 kW et 1 kWh, c'est pareil » : **faux**, le premier est une puissance, le second une énergie.
- « Une puissance instantanée suffit toujours pour connaître l'énergie du jour » : **faux** si elle varie au cours de la journée.
- « Le PZEM doit être réinitialisé à minuit » : **faux** ; les cumuls journaliers et mensuels se calculent sans remettre à zéro l'index total.

## Exercice

Un appareil développe une puissance active constante de 400 W pendant 2 h 30. Calculer l'énergie.

**Correction :** 400 W = 0,4 kW ; 2 h 30 = 2,5 h ; 0,4 × 2,5 = **1 kWh**.

Toutes les données et puissances ci-dessus sont des exemples pédagogiques.
