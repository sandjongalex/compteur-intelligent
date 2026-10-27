# Livrables PowerPoint — Module 01

Deux présentations PowerPoint **16:9** ont été produites lors de la conception pédagogique du M01. Elles comprennent **7 diapositives chacune**, avec **notes du présentateur** et des illustrations vectorielles majoritairement modifiables.

> **Synchronisation GitHub :** les fichiers binaires `.pptx` ne sont **pas encore versés dans ce dépôt**. Ils sont disponibles comme fichiers téléchargeables dans la conversation de conception ; leur transfert vers ce répertoire reste à effectuer. Les plans, storyboards et scripts sont déjà versionnés ici.

## Fichiers à placer dans ce dossier

| Fichier | Leçon | Nombre de diapositives | État |
|---|---|---:|---|
| `AlexTech_M01_V01_Compteur_Intelligent.pptx` | [M01-V01](../videos/V01-plan.md) | 7 | Créé et testé localement ; import GitHub à faire |
| `AlexTech_M01_V02_Grandeurs_Electriques.pptx` | [M01-V02](../videos/V02-plan.md) | 7 | Créé et testé localement ; import GitHub à faire |

Les deux fichiers possèdent **7 jeux de notes orateur** ; l'export et le rendu ont été testés, sans débordement détecté.

## Cohérence pédagogique

### V01 — Du réseau électrique au tableau de bord IoT

1. Suivre sa consommation partout.
2. Notre objectif — date, tension, kWh jour/mois.
3. Mesurer avec PZEM, traiter avec ATmega328P.
4. Ajouter DS3231, FRAM, LCD 20×4 et SIM800L.
5. Chaîne jusqu'à Flask, SQLite et navigateur.
6. Simuler le LCD et un tableau de bord hors ligne.
7. Exercice d'ordonnancement des blocs.

### V02 — Volts, ampères, watts et kWh

1. Puissance et énergie sont différentes.
2. Tension — volts (V).
3. Courant — ampères (A).
4. Puissance active — watts (W), conversion en kW.
5. Énergie — Wh/kWh et calcul à puissance active constante.
6. Exemple de conversion 2 000 W pendant 30 min.
7. Exercice 200 W pendant 5 h ; réponse dans les notes.

## Sources et vérification

- [Script V01](../scripts/V01-script.md) et [storyboard V01](V01-storyboard.md).
- [Script V02](../scripts/V02-script.md) et [storyboard V02](V02-storyboard.md).
- Export : diapositives **éditables**, ratio **16:9**, format **.pptx**.
- Contrôle rendu automatique : **aucun débordement détecté**.
- **Révision orale, répétition et montage vidéo : non réalisés**.

## Import dans GitHub

Depuis l'interface GitHub, ouvrir le dossier `formation/modules/M01-decouverte-electricite/slides/`, sélectionner **Add file → Upload files** et importer les deux `.pptx` après les avoir téléchargés. Ne pas télécharger ni committer des secrets, contacts personnels ou vidéos premium non destinées au public.

La mise à disposition en GitHub de ce manifeste **ne constitue pas** l'import des fichiers binaires eux-mêmes.
