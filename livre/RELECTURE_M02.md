# Relecture du chapitre 2 — Contrôle interne de production

**Périmètre :** rédaction du chapitre 2, annexe B, sommaire du lecteur et index interne.  
**Date de contrôle initial :** 28 octobre 2026.  
**Statut :** rédaction et première relecture technique/pédagogique effectuées ; à valider lors de la composition du livre et après avis de l'auteur.

> Ce rapport est un document interne de suivi. **Il ne doit pas être inclus dans le livre diffusé.**

## 1. Alignement avec le programme vidéo officiel

Le chapitre respecte la progression du module M02 :

| Vidéo du programme | Contenu repris et approfondi dans le chapitre |
|---|---|
| **M02-V01 : Reconnaître les composants du compteur intelligent** | ATmega328P, Arduino Uno, PZEM-004T V3.0, DS3231, LCD I2C 20×4, FRAM, SIM800L, LED, bouton, buzzer, quartz, résistances, condensateurs et nomenclature |
| **M02-V02 : Alimentations, protections et sécurité du 230 V** | Domaines AC/DC, configuration logique 5 V, SIM800L nu environ 4 V et pointes de courant, découplage, compatibilité des niveaux UART, isolation secteur, boîtier, vérifications hors tension et situations dangereuses |

**Périmètre volontairement exclu :** câblage secteur exploitable, méthode d'essai sous tension pour novices, valeurs de fusibles ou distances d'isolement inventées, référencement commercial de composants non vérifiés.

## 2. Relecture technique et sécurité

| Point contrôlé | Résultat |
|---|---|
| Distinction fonctionnelle des composants | Conforme à la structure du projet |
| Configuration pédagogique ATmega328P : 5 V / 16 MHz | Présentée comme un choix de conception, non une règle universelle |
| SIM800L **nu** : alimentation autour de 4,0 V, plage approximative 3,4–4,4 V | Accompagnée de la nécessité de vérifier la carte exacte |
| SIM800L : pointes de courant proches de 2 A | Mentionnées avec exigence d'alimentation et de découplage adaptés |
| UART 5 V ↔ niveaux modem | Compatibilité et adaptation **dans les deux sens** explicitement demandées |
| RTC DS3231 | Distinction de la mémoire FRAM ; point d'attention sur pile et circuit de recharge de la carte |
| Bus I2C partagé | Compatibilité de tension et d'adresse à vérifier, sans câblage détaillé précoce |
| Secteur et PZEM | Pas de procédure de raccordement 230 V pour débutants ; intervention qualifiée |
| Protection | Isolation, boîtier, distances, fusibles et tests renvoyés à une conception qualifiée |
| Breadboard | Explicitement interdite pour les essais secteur |
| Simulations / mesures réelles | Les valeurs fictives sont signalées |
| Quiz M02 | 10 réponses A–D avec justifications dans l'annexe B |

La grille de réponse de l'annexe B est : **1 B, 2 C, 3 A, 4 D, 5 B, 6 C, 7 A, 8 D, 9 C, 10 A**, conforme aux questions rédigées dans le chapitre et à l'intention du quiz du module.

## 3. Contrôle de diffusion hors GitHub

La version destinée au lecteur se compose des fichiers suivants, sans renvois à GitHub :

- [Chapitre 2](chapitres/02-composants-alimentations-securite.md)
- [Annexe B — Corrigés](annexes/CORRIGE_M02.md)
- [Sommaire pour le lecteur](00-sommaire.md)

Leurs renvois sont éditoriaux et pérennes (« chapitre 3 », « annexe B », « figure 2.1 »). Les scripts vidéo, la nomenclature interne et les rapports de production restent des sources **internes**, non distribuées avec le livre.

## 4. Points éditoriaux à reprendre à la mise en page

- [ ] Faire remplacer ou composer proprement le synoptique textuel de la figure 2.1 dans le format imprimé.
- [ ] Vérifier la lisibilité des tableaux et des questions du quiz sur pages mobiles et papier.
- [ ] Vérifier la pagination définitive et le renvoi à l'annexe B.
- [ ] Tester le chapitre auprès d'un débutant, en particulier la distinction **tension d'alimentation / capacité en courant / niveau logique**.
- [ ] Effectuer une validation finale de l'auteur sur le style et les exemples.
- [ ] Vérifier à nouveau les spécifications matérielles sur les références effectivement utilisées lorsque le prototype final sera figé.

## 5. Règles pour la suite

Le chapitre 3 devra introduire Arduino IDE, \`setup()\`, \`loop()\` et le clignotement d'une LED **en basse tension**, sans supposer que le modem, la FRAM ou le PZEM sont nécessaires au premier programme.

**Aucun test sur matériel ni essai secteur n'a été réalisé pour cette relecture.**
