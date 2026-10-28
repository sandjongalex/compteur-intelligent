# Manuscrit du livre — tableau de bord interne

**Ouvrage : « Concevez votre compteur électrique intelligent IoT » — AlexTech Academy**  
**Auteur : Sandjong Tchoungong Alex**  
**Sous-titre de travail :** *De la mesure électrique à la supervision énergétique sur Internet*  
**Langue :** français • **Public :** débutants accompagnés, techniciens et passionnés d'électronique

> **Document de production, non destiné au lecteur et exclu du PDF final.** GitHub sert seulement à organiser la rédaction, les contrôles, les codes et les vidéos. Les textes remis au public ne doivent contenir aucun lien ou renvoi GitHub. Voir la [procédure de composition du livre](PRODUCTION_INTERNE.md).

## Parcourir les textes destinés aux lecteurs

1. [Sommaire du livre](00-sommaire.md)
2. [Avant-propos](00-avant-propos.md)
3. [Chapitre 1](chapitres/01-decouvrir-le-compteur-et-comprendre-l-electricite.md)
4. [Chapitre 2](chapitres/02-composants-alimentations-securite.md)
5. [Chapitre 3](chapitres/03-arduino-ide-premier-programme.md)
6. [Chapitre 4](chapitres/04-bases-c-cpp-microcontroleurs.md)
7. [Chapitre 5](chapitres/05-entrees-sorties-communication-serie.md)
8. [Annexe A — corrigés du chapitre 1](annexes/CORRIGE_M01.md)
9. [Annexe B — corrigés du chapitre 2](annexes/CORRIGE_M02.md)
10. [Annexe C — corrigés du chapitre 3](annexes/CORRIGE_M03.md)
11. [Annexe D — corrigés du chapitre 4](annexes/CORRIGE_M04.md)
12. [Annexe E — corrigés du chapitre 5](annexes/CORRIGE_M05.md)

**Illustrations — production interne :** [Registre des figures 1.1 à 5.9](ILLUSTRATIONS_A_PRODUIRE.md) · [Gabarit obligatoire pour les nouveaux chapitres](MODELE_CHAPITRE.md). **40 figures pédagogiques identifiées, 0 figure finale validée : les cinq premiers chapitres attendent encore leurs illustrations finales.**

**Gestion interne uniquement :** [Charte éditoriale](PLAN_EDITORIAL.md) · [Relecture M01](RELECTURE_M01.md) · [Relecture M02](RELECTURE_M02.md) · [Relecture M03](RELECTURE_M03.md) · [Relecture M04](RELECTURE_M04.md) · [Relecture M05](RELECTURE_M05.md) · [Règles d'export](PRODUCTION_INTERNE.md).

## Assemblage automatique des chapitres

Le programme [`scripts/assembler_livre.py`](scripts/assembler_livre.py) et le [guide de fabrication](ASSEMBLAGE.md) permettent d'obtenir **un seul manuscrit** avec l'avant-propos, les chapitres disponibles dans l'ordre et leurs annexes. Le [workflow d'aperçu](../.github/workflows/livre-assemblage.yml) produit en complément un **PDF A4 et un Word provisoires** ; ces fichiers ne sont pas publiables tant que les images et la relecture finale manquent. Le sommaire des exports est généré à partir des chapitres réellement disponibles, sans introduire les autres chapitres annoncés dans le plan.

Commande locale : `python livre/scripts/assembler_livre.py --mode brouillon --output-dir build/livre`.

## Sommaire contractuel : 16 chapitres ↔ 16 modules ↔ 32 vidéos

| Chapitre | Intitulé | Vidéos de référence | État du livre |
|---|---|---|---|
| 01 | Découvrir le compteur et comprendre l'électricité | M01-V01 / M01-V02 | **Relecture initiale effectuée ; validation auteur et mise en page à faire** |
| 02 | Composants, alimentations et sécurité électrique | M02-V01 / M02-V02 | **Rédigé, première relecture effectuée ; validation auteur et mise en page à faire** |
| 03 | Arduino IDE et premier programme | M03-V01 / M03-V02 | **Rédigé et première relecture documentaire effectuée ; essais Arduino et mise en page à faire** |
| 04 | Bases du C/C++ embarqué | M04-V01 / M04-V02 | **Rédigé ; relecture documentaire et illustrations à valider** |
| 05 | Entrées, sorties et communication série | M05-V01 / M05-V02 | **Rédigé ; première relecture documentaire et illustrations à valider** |
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

Chaque chapitre couvre **les deux vidéos de son module**, conserve leurs objectifs et développe davantage les notions, les exemples, les erreurs fréquentes, les exercices et le diagnostic. Les codes et les procédures techniques sont vérifiés dans ce dépôt de travail, mais ces références n'apparaissent pas dans le livre destiné à la diffusion.

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

## Références de production (internes — exclues du livre)

- [Programme officiel de quatre heures](../docs/formation/PLAN_FORMATION_4H.md)
- [Guide pédagogique](../formation/GUIDE_PEDAGOGIQUE.md)
- [Règle d'évolution continue](../docs/formation/REGLE_EVOLUTION_CONTINUE.md)
- [Journal du firmware](../firmware/PROGRESSION.md)
- [Tableau d'affectation des broches](../docs/hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md)

## Limites de sécurité et de périmètre

Cet ouvrage traite d'un **prototype pédagogique de suivi énergétique** : il ne remplace pas un compteur électrique homologué destiné à la facturation. Aucun chapitre ne doit inviter un novice à intervenir sur une installation sous tension. La conception, les protections, l'isolation, les essais et les connexions au réseau 230 V exigent un cadre qualifié et les réglementations locales applicables.

Le manuscrit Markdown est conservé ici comme **source éditoriale versionnée**. Les futurs PDF et formats imprimables pourront être générés à partir de cette source après relecture et validation.

## Règle des illustrations obligatoires

Chaque chapitre M01–M16 signale **à son emplacement pédagogique** les photos, captures et schémas nécessaires via un commentaire `ILLUSTRATION À PRODUIRE`. Le registre interne note le numéro, la légende, la description et le statut de chaque figure. Une première relecture du texte **ne vaut pas validation graphique** ; l'impression et la publication sont bloquées tant que les illustrations requises ne sont pas réalisées, contrôlées et correctement intégrées.

## Composition et diffusion

L'export final inclura **uniquement** le sommaire destiné au lecteur, l'avant-propos, les chapitres et les annexes sélectionnées. Les fichiers de suivi et les liens vers la structure GitHub sont exclus. Les vidéos restent complémentaires ; le livre doit être compris seul.
