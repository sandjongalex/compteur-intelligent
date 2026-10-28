# Concevez votre compteur électrique intelligent IoT

**AlexTech Academy — Manuscrit pédagogique en cours de rédaction**  
**Auteur : Sandjong Tchoungong Alex**  
**Sous-titre de travail :** *De la mesure électrique à la supervision énergétique sur Internet*  
**Langue :** français • **Public :** débutants accompagnés, techniciens et passionnés d'électronique

> **État éditorial : manuscrit non finalisé.** Le livre accompagne la formation vidéo de quatre heures, mais peut être lu indépendamment. Les exemples illustratifs ne prouvent ni la conformité métrologique ni le succès d'essais réels. Les chapitres non écrits sont indiqués « à rédiger ».

## Commencer à lire

1. [Avant-propos — Pourquoi ce livre ?](00-avant-propos.md)
2. [Chapitre 1 — Découvrir le compteur et comprendre l'électricité](chapitres/01-decouvrir-le-compteur-et-comprendre-l-electricite.md)
3. [Règles éditoriales et correspondance livre/vidéos](PLAN_EDITORIAL.md)

## Sommaire contractuel : 16 chapitres ↔ 16 modules ↔ 32 vidéos

| Chapitre | Intitulé | Vidéos de référence | État du livre |
|---|---|---|---|
| 01 | Découvrir le compteur et comprendre l'électricité | M01-V01 / M01-V02 | **Première rédaction disponible, relecture à faire** |
| 02 | Composants, alimentations et sécurité électrique | M02-V01 / M02-V02 | À rédiger |
| 03 | Arduino IDE et premier programme | M03-V01 / M03-V02 | À rédiger |
| 04 | Bases du C/C++ embarqué | M04-V01 / M04-V02 | À rédiger |
| 05 | Entrées, sorties et communication série | M05-V01 / M05-V02 | À rédiger |
| 06 | Mesures électriques avec le PZEM-004T V3.0 | M06-V01 / M06-V02 | À rédiger |
| 07 | Horloge DS3231 et afficheur LCD I2C 20×4 | M07-V01 / M07-V02 | À rédiger |
| 08 | Consommations journalières et mensuelles | M08-V01 / M08-V02 | À rédiger |
| 09 | ATmega328P autonome et programmation ISP | M09-V01 / M09-V02 | À rédiger |
| 10 | SIM800L, commandes AT et GSM/GPRS | M10-V01 / M10-V02 | À rédiger |
| 11 | FRAM, conservation des relevés et synchronisation | M11-V01 / M11-V02 | À rédiger |
| 12 | Bases de Python | M12-V01 / M12-V02 | À rédiger |
| 13 | Flask, SQLite et API de réception | M13-V01 / M13-V02 | À rédiger |
| 14 | Tableau de bord web et graphiques | M14-V01 / M14-V02 | À rédiger |
| 15 | Schéma électronique et PCB avec KiCad | M15-V01 / M15-V02 | À rédiger |
| 16 | Intégration, tests et déploiement sur PythonAnywhere | M16-V01 / M16-V02 | À rédiger |

Chaque chapitre couvre **les deux vidéos de son module**, conserve leurs objectifs et développe davantage les notions, les exemples, les erreurs fréquentes, les exercices et le diagnostic. Les codes et les procédures techniques doivent rester alignés sur l'état réel du dépôt.

## Le projet technique commun

- **ATmega328P** programmé en C/C++ via Arduino IDE ; passage à une puce autonome par ISP.
- **PZEM-004T V3.0** pour l'acquisition ; **DS3231** pour l'horodatage.
- **LCD I2C 20×4** pour la date, la tension et les énergies du jour et du mois.
- **FRAM I2C** pour la future conservation durable des relevés.
- **SIM800L** pour la future communication GSM/GPRS.
- **Python Flask + SQLite** pour recevoir et enregistrer les mesures ; **Jinja2, HTML, CSS et JavaScript** pour leur consultation sur le web.

**Interfaces retenues à partir de M10 :** SIM800L sur UART matériel D0/D1 ; PZEM sur `SoftwareSerial` D10/D11 ; DS3231, LCD et FRAM sur I2C A4/A5. Cette décision est documentée, mais **le firmware GSM/FRAM ne doit pas être présenté comme déjà réalisé**.

Le **firmware fil rouge est actuellement au stade M09**, en simulation par défaut, avec des essais matériels restant à vérifier. Les modules M10–M16 ne doivent pas être décrits au passé tant que leurs développements et validations ne sont pas publiés.

## Comment lire et utiliser cet ouvrage

- Lire le chapitre correspondant au module vidéo étudié.
- Effectuer les expériences **sans secteur** ou en environnement de simulation lorsqu'on débute.
- Consulter les ressources pédagogiques et les mini-exercices du module.
- Pour la programmation, partir du **même projet cumulatif** et comparer les changements d'une étape à l'autre.
- Ne pas confondre un résultat simulé, une compilation réussie, un essai en laboratoire et un dispositif de mesure certifié.

## Références du dépôt (sources de vérité)

- [Programme officiel de quatre heures](../docs/formation/PLAN_FORMATION_4H.md)
- [Guide pédagogique](../formation/GUIDE_PEDAGOGIQUE.md)
- [Règle d'évolution continue](../docs/formation/REGLE_EVOLUTION_CONTINUE.md)
- [Journal du firmware](../firmware/PROGRESSION.md)
- [Tableau d'affectation des broches](../docs/hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md)

## Limites de sécurité et de périmètre

Cet ouvrage traite d'un **prototype pédagogique de suivi énergétique** : il ne remplace pas un compteur électrique homologué destiné à la facturation. Aucun chapitre ne doit inviter un novice à intervenir sur une installation sous tension. La conception, les protections, l'isolation, les essais et les connexions au réseau 230 V exigent un cadre qualifié et les réglementations locales applicables.

Le manuscrit Markdown est conservé ici comme **source éditoriale versionnée**. Les futurs PDF et formats imprimables pourront être générés à partir de cette source après relecture et validation.
