# Registre des illustrations du livre — Production interne

**Document de fabrication — à ne jamais exporter dans le livre commercial.** Tous les visuels ci-dessous sont **À PRODUIRE** à la dernière mise à jour du 28 octobre 2026 ; l'existence d'un dessin textuel ou Mermaid dans un chapitre ne signifie pas qu'une image imprimable ou une photo réelle existe.

## Méthode et statut

- **À PRODUIRE :** emplacement spécifié dans le chapitre, image non encore réalisée/contrôlée.
- **EN COURS :** fichier graphique en production ; provenance, autorisations et correction technique à vérifier.
- **VALIDÉE :** image créée, autorisée, lisible et revue ; associée à une légende et à un texte alternatif exacts.
- L'identifiant **X.Y** reprend le numéro de chapitre X et le numéro séquentiel Y.
- La colonne **Source / droits** est volontairement « à documenter » jusqu'à l'existence d'un fichier réel. **Aucune image externe ne doit être copiée dans le livre sans autorisation adaptée.**
- Les figures représentant des mesures fictives portent la mention **« données fictives »**. Une photo ou capture d'essai ne peut être qualifiée de réelle qu'après vérification. Les schémas « secteur » sont **conceptuels**, jamais des plans de câblage à reproduire.
- Les caractéristiques détaillées et le texte alternatif sont dans les commentaires `<!-- ILLUSTRATION À PRODUIRE — FIGURE X.Y ... -->` situés à l'emplacement de chaque figure dans les chapitres.

## Chapitre 1 — Découvrir le compteur et comprendre l'électricité

| Figure | Type | Emplacement | Contenu attendu | Statut |
|---|---|---|---|---|
| **1.1** | Maquette LCD / infographie | §1.2 | Écran 20×4 avec date, tension, consommation jour et mois ; données fictives et vingt caractères max. par ligne | À PRODUIRE |
| **1.2** | Synoptique illustré | §1.3 | Trajet PZEM → ATmega → SIM800L → Flask/SQLite → navigateur ; DS3231, LCD, FRAM en branches ; aucun raccordement secteur | À PRODUIRE |
| **1.3** | Infographie | §1.6 | Comparaison simple U/V, I/A, P/W et E/Wh-kWh, avec pictogrammes et unités | À PRODUIRE |
| **1.4** | Graphique pédagogique | §1.7 | Comparaison de puissances et durées différentes donnant 1 kWh (2 kW × 0,5 h ; 0,2 kW × 5 h) | À PRODUIRE |
| **1.5** | Frise de relevés | §1.8 | Index début/fin de journée (1 250,50/1 254,75) et différence 4,25 kWh ; nombres fictifs | À PRODUIRE |

## Chapitre 2 — Identifier les composants, alimentations et sécurité

| Figure | Type | Emplacement | Contenu attendu | Statut |
|---|---|---|---|---|
| **2.1** | Planche photos annotées | §2.1 | ATmega328P, Uno Rev3, PZEM, DS3231, LCD, FRAM, SIM800L, regroupés selon fonction ; modèles exacts à vérifier | À PRODUIRE |
| **2.2** | Photo comparée | §2.2 | Microcontrôleur ATmega328P en boîtier et carte Uno Rev3 ; distinguer puce et carte | À PRODUIRE |
| **2.3** | Photo de composants hors tension | §2.3 | PZEM-004T V3.0 et transformateur de courant compatible, sans démonstration de raccordement secteur | À PRODUIRE |
| **2.4** | Planche photos annotées | §2.6 | DS3231, LCD 20×4 I2C et FRAM : dater / afficher / sauvegarder, aucune équivalence trompeuse | À PRODUIRE |
| **2.5** | Photo annotée | §2.7 | SIM800L exact avec antenne/entrée VBAT et étiquette « vérifier variante » ; pas de montage branché | À PRODUIRE |
| **2.6** | Synoptique sécurisé | §2.11 | Zones secteur/électronique, séparation AC/DC isolée, domaine logique et modem, sans connexions secteur exploitables | À PRODUIRE |
| **2.7** | Infographie comparative | §2.13 | Logique ATmega 5 V/16 MHz vs VBAT SIM800L nu ~4 V, pics ~2 A, et niveau UART à adapter | À PRODUIRE |
| **2.8** | Infographie de sécurité | §2.17 | Activités basses tensions autorisées vs interventions secteur qualifiées ; ne pas représenter un geste dangereux réalisable | À PRODUIRE |

## Chapitre 3 — Arduino IDE et premier programme

| Figure | Type | Emplacement | Contenu attendu | Statut |
|---|---|---|---|---|
| **3.1** | Capture d'écran réelle | §3.3 | Arduino IDE 2 avec éditeur, Vérifier, Téléverser, sélecteur carte/port et zone de messages | À PRODUIRE |
| **3.2** | Infographie de processus | §3.3 | Code → compilation → correction erreur éventuelle → téléversement → LED observée | À PRODUIRE |
| **3.3** | Photo + capture | §3.4 | Uno Rev3 reliée par câble USB données et sélection du port observé ; aucune capture fictive non signalée | À PRODUIRE |
| **3.4** | Organigramme | §3.5 | setup() une fois puis loop() répétée | À PRODUIRE |
| **3.5** | Double capture réelle | §3.7 | Comparer message « Vérifier » et confirmation « Téléverser » sur IDE 2, sans succès inventé | À PRODUIRE |
| **3.6** | Capture d'erreur contrôlée | §3.8 | Accolade manquante dans une copie du sketch, message réel du compilateur et correction | À PRODUIRE |
| **3.7** | Photo annotée de carte | §3.9 | Arduino Uno Rev3, LED intégrée « L », broche D13, alimentation USB uniquement | À PRODUIRE |
| **3.8** | Chronogramme | §3.15 | HIGH 250 ms puis LOW 750 ms, cycle de 1 s, temps à l'échelle | À PRODUIRE |
| **3.9** | Schéma basse tension | §3.16 | D8 → résistance 330 Ω → anode/cathode LED → GND, polarité et sécurité visibles | À PRODUIRE |
| **3.10** | Photo du montage validé | §3.16–3.17 | LED externe sur breadboard, D8 et GND identifiables ; circuit USB débranché pendant câblage | À PRODUIRE |

## Chapitre 4 — Les bases du C/C++ embarqué

| Figure | Type | Emplacement | Contenu attendu | Statut |
|---|---|---|---|---|
| **4.1** | Infographie « variable » | §4.1 | Boîtes pour int, float, bool ; nom, type, valeur explicités | À PRODUIRE |
| **4.2** | Comparaison des types | §4.2 | int 16 bits sur Uno AVR, float 32 bits et bool, avec portée des valeurs | À PRODUIRE |
| **4.3** | Infographie de calcul | §4.4 | Comparaison 5 / 2 = 2 vs 5.0f / 2.0f = 2.5 | À PRODUIRE |
| **4.4** | Capture Arduino IDE réelle | §4.6 | Moniteur série réglé sur 9 600 bauds ; énergie fictive 1.000 kWh | À PRODUIRE |
| **4.5** | Organigramme if/else | §4.8 | Choix de branche pour tensions fictives 245/230 V et seuil fictif 240 V ; = vs == | À PRODUIRE |
| **4.6** | Organigramme de boucles | §4.10 | Boucles for et while bornées ; repérage d'un cas infini | À PRODUIRE |
| **4.7** | Flux de fonction | §4.11 | 400 W, 2,5 h → calculerEnergieKWh() → return 1 kWh | À PRODUIRE |
| **4.8** | Infographie de progression | §4.12 | M03 LED conservée → M04 LED + constantes + fonction de calcul fictif + série | À PRODUIRE |

## Suivi de production

| Chapitre | Figures nécessaires | À produire | En cours | Validées |
|---|---:|---:|---:|---:|
| 1 | 5 | 5 | 0 | 0 |
| 2 | 8 | 8 | 0 | 0 |
| 3 | 10 | 10 | 0 | 0 |
| 4 | 8 | 8 | 0 | 0 |
| **Total** | **31** | **31** | **0** | **0** |

## Données à compléter quand un visuel existe

Pour chaque image créée, ajouter au registre (sous son identifiant) :

- **Fichier source** : chemin vers l'original graphique (SVG, fichier de dessin, photo ou capture), et version/export imprimable ;
- **Provenance et droits** : création originale, photographie de l'auteur ou licence permettant l'usage commercial ;
- **Matériel/version** : modèle vérifié et conditions de capture ;
- **Revue technique** : personne/date et conformité au contenu du chapitre ;
- **Accessibilité** : texte alternatif inclus ;
- **Validation éditoriale** : accord de l'auteur avant passage à « VALIDÉE ».

**Blocage de publication :** tant qu'une illustration indispensable reste « À PRODUIRE » ou « EN COURS », la version commerciale du chapitre ne peut pas recevoir le statut « prêt à publier ».
