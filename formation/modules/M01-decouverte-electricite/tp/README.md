# Travaux pratiques — Module 01

**Statut : deux exercices guidés, leurs corrigés et critères d'évaluation disponibles.**

Ces exercices se réalisent **sans matériel électrique et sans branchement secteur**. Une feuille, un crayon et un navigateur suffisent. Les données sont fictives.

## TP 01 — Retracer le parcours d'une mesure (lié à M01-V01)

**Objectif :** identifier les fonctions d'acquisition, de calcul, de communication, de stockage et de consultation.

**Matériel :** fiche du [synoptique](../ressources/SYNOPTIQUE.md), feuille ou tableau.

**Durée hors vidéo :** 10 minutes.

### Énoncé de l'apprenant

On dispose des cinq éléments suivants, volontairement présentés dans le désordre :

- Navigateur web
- Modem SIM800L
- ATmega328P
- Module PZEM-004T
- Serveur Flask avec SQLite

1. Remettre les cinq éléments dans l'ordre de circulation d'un relevé.
2. Associer à chaque élément un verbe : mesurer, traiter, transmettre, enregistrer, consulter.
3. Expliquer si le LCD appartient au trajet GSM ou à l'affichage local.
4. Citer un composant qui conserve la date et un autre qui peut enregistrer des mesures non transmises.

**Résultat attendu :** schéma comportant cinq blocs, flèches dans le bon sens et deux réponses complémentaires.

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

## TP 02 — Calculer une consommation en kWh (lié à M01-V02)

**Objectif :** convertir des watts en kilowatts, des minutes en heures, et calculer l'énergie lorsque la puissance active est constante.

**Matériel :** crayon, calculatrice facultative, [fiche des unités](../ressources/FICHE_UNITES.md).

**Durée hors vidéo :** 15 minutes.

### Énoncé de l'apprenant

Pour chaque ligne, les appareils utilisent une **puissance active constante**.

| Cas | Puissance | Durée | Énergie à trouver |
|---|---:|---:|---|
| A | 200 W | 5 h | ... kWh |
| B | 500 W | 4 h | ... kWh |
| C | 2 000 W | 30 min | ... kWh |
| D | 100 W | 15 min | ... kWh |

Questions complémentaires :

1. Expliquer pourquoi 500 W et 500 Wh ne désignent pas la même grandeur.
2. Un écran affiche « 230,5 V » : cette donnée désigne-t-elle une tension, un courant ou une énergie ?
3. Si une puissance varie au cours de la journée, peut-on toujours calculer l'énergie exacte à partir d'une seule valeur instantanée de puissance ? Expliquer.

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

## Conditions de validation du module

- Réussir les exercices avec **au moins 8/10** et consulter les corrections des erreurs.
- Réussir le [quiz M01](../quiz/README.md) avec **8/10 minimum**.
- Être capable d'expliquer oralement la différence entre une mesure électrique, le calcul embarqué et la supervision web.

> **Note de sécurité :** les calculs utilisent des données fictives. Aucune manipulation du secteur 230 V n'est demandée.
