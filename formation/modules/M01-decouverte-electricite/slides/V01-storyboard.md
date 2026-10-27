# Storyboard finalisé — M01-V01 : Du réseau électrique au tableau de bord IoT

**7 diapositives, format 16:9, durée cible 5 min.** Le texte « À afficher » doit rester très court ; les explications complètes sont dans le [script oral](../scripts/V01-script.md). **Statut : contenu prêt pour conception PowerPoint ; fichier PPTX et animations non créés.**

| Diapo | Temps | Titre à l'écran | Contenu visible | Animation et mise en scène |
|---|---|---|---|---|
| 1 | 00:00–00:40 | « Suivre sa consommation partout » | Maison → téléphone, « Compteur intelligent IoT » | Titre + fondu, formateur face caméra |
| 2 | 00:40–01:25 | « Notre objectif » | Date · Tension · kWh du jour · kWh du mois · Historique web | Apparition des cinq objectifs, maquette LCD |
| 3 | 01:25–02:10 | « Mesurer et traiter » | PZEM-004T → ATmega328P ; « acquisition » → « calcul » | Gros plan des composants hors tension |
| 4 | 02:10–02:45 | « Afficher et transmettre » | DS3231 / FRAM / LCD / SIM800L autour du microcontrôleur | Animation des flèches fonctionnelles |
| 5 | 02:45–03:40 | « Du capteur au navigateur » | PZEM → ATmega328P → SIM800L → Flask → SQLite → HTML/Jinja2 | Flèches successives, explicitation de « serveur » |
| 6 | 03:40–04:25 | « Résultat attendu — simulation » | LCD date, 230,5 V, 4,250 kWh jour, 125,480 kWh mois + page web identique | Démonstration navigateur locale, gros bandeau « DONNÉES FICTIVES » |
| 7 | 04:25–05:00 | « À vous de jouer ! » | Cartes mélangées PZEM / ATmega / GSM / Flask + SQLite / Navigateur | Pause de réflexion puis révélation de l'ordre |

## Écran LCD de référence (données fictives)

```text
DATE:    27/10/2026
TENSION:    230.5 V
JOUR:      4.250 kWh
MOIS:    125.480 kWh
```

Chaque ligne doit rester dans les limites de l'écran de 20 caractères.

## Visuels à produire

1. Illustration de maison + téléphone, droits vérifiés ou dessin original.
2. Photos réelles hors tension des modules PZEM-004T, ATmega328P, LCD, DS3231, FRAM, SIM800L, avec références vérifiées.
3. Diagramme propre basé sur [SYNOPTIQUE.md](../ressources/SYNOPTIQUE.md).
4. Enregistrement de l'ouverture du fichier [demo_dashboard_fictif.html](../ressources/demo_dashboard_fictif.html) dans un navigateur, **hors ligne**.
5. Animation de correction de la chaîne de données.

## Contraintes graphiques

- Fond clair ou sombre constant ; grand contraste.
- 16:9 (1920 × 1080 recommandé pour la capture), titres lisibles sur smartphone.
- Une idée par diapositive, pas de pavés de texte.
- Pas de démonstration sur 230 V ; les valeurs du tableau sont simulées.
- Vérifier l'alignement de la progression avec les temps prévus, puis tester la durée réelle.
