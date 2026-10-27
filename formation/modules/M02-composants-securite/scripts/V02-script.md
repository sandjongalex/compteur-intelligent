# M02-V02 — Script intégral : Alimentations, protections et sécurité du 230 V

**Objectif :** distinguer les domaines d'alimentation et reconnaître les situations électriques dangereuses.
**Durée vidéo cible : 5 min.**
**Statut : texte prêt pour répétition et chronométrage.**
Les indications **[À l'écran]** sont des consignes de mise en scène, non prononcées.

## 00:00–00:45 — Pourquoi parler de sécurité ?
[À l'écran : symbole de danger ; trois étiquettes « 230 V alternatif », « 5 V continu », « 4,0 V continu ».]

« Avant de réaliser notre compteur intelligent, parlons de l'alimentation électrique. C'est un point essentiel, car notre projet associe un réseau domestique dangereux et de petits circuits électroniques sensibles.

Le secteur deux cent trente volts peut provoquer une électrocution ou un incendie. Cette formation ne demande jamais à un débutant de travailler sur une installation secteur sous tension. Les premières manipulations se feront avec des alimentations basse tension adaptées ou avec des données simulées.

Nous devons surtout retenir que tous nos composants ne s'alimentent pas avec la même tension. »

## 00:45–01:30 — Alternatif et continu
[À l'écran : diagramme explicatif AC vers alimentation isolée ; aucune borne secteur de câblage.]

« Dans une installation domestique monophasée, la tension est généralement alternative. On parle de courant alternatif, ou AC. Dans nos circuits électroniques, les alimentations sont continues : on parle de DC.

Pour passer d'une alimentation secteur à une alimentation électronique, notre système utilisera un module d'alimentation AC/DC **isolé, adapté et correctement protégé**. Sa sélection et son intégration dans le boîtier doivent respecter les règles électriques applicables et être validées par une personne qualifiée.

Sur le schéma de principe, retenez surtout qu'il existe une frontière de sécurité entre le secteur et la basse tension accessible. Un schéma fonctionnel n'est pas une invitation à faire un raccordement secteur. »

## 01:30–02:25 — Les tensions 5 V et 4 V
[À l'écran : branche « logique 5 V » et branche « SIM800L 4,0 V ».]

« Notre ATmega328P sera utilisé dans une configuration à cinq volts et seize mégahertz. D'autres composants logiques peuvent fonctionner sur la même alimentation, à condition de vérifier les caractéristiques exactes de chaque carte et de chaque adaptateur.

Le SIM800L nu est différent. Sa documentation recommande une alimentation autour de quatre volts, avec une plage d'environ trois virgule quatre à quatre virgule quatre volts. Pendant les émissions radio, le modem peut demander des pointes de courant proches de deux ampères. Il faut donc une alimentation régulée capable de les fournir sans chute de tension importante.

Attention : on ne branche pas directement les cinq volts sur l'entrée VBAT d'un SIM800L nu. Certains modules commerciaux ajoutent des régulateurs, mais il faut identifier leur modèle avant toute connexion. Les niveaux logiques entre l'ATmega à cinq volts et le modem doivent eux aussi être adaptés. »

## 02:25–03:25 — Condensateurs et protections
[À l'écran : icônes condensateur, isolation, protection, boîtier fermé.]

« Pourquoi parle-t-on de condensateurs ? Parce que lorsqu'un circuit change rapidement d'état, son courant peut varier. Des condensateurs de découplage placés près des composants contribuent à réduire certaines perturbations. Pour le modem, une réserve locale bien dimensionnée aide également à supporter les pointes de courant.

Mais les condensateurs ne remplacent pas une alimentation convenable.

Nous devons aussi prévoir des protections adaptées : isolation, fusibles appropriés, séparation physique des parties dangereuses, distances d'isolement sur le circuit imprimé et boîtier fermé.

Ces décisions demandent une vraie conception. Une breadboard n'est pas faite pour accueillir le secteur deux cent trente volts. Nous ne montrerons donc aucun montage secteur sous tension à reproduire par un débutant. »

## 03:25–04:20 — Tester sans risque
[À l'écran : colonne « autorisé en basse tension » et colonne « réservé à une personne qualifiée ».]

« Concrètement, que peut faire un débutant ? Il peut vérifier visuellement un montage hors tension. Il peut programmer une carte Arduino, utiliser une alimentation basse tension prévue pour l'apprentissage, faire clignoter une LED, lire un bouton et afficher des mesures simulées.

En revanche, il ne doit pas raccorder le secteur sur une breadboard, manipuler les parties dangereuses sous tension ou improviser un fusible et un boîtier.

La mise en service et la validation du circuit de mesure raccordé au secteur seront réservées à un banc approprié et à un professionnel qualifié. Même lorsqu'un module est vendu comme prêt à l'emploi, cela ne prouve pas que toutes ses installations sont sûres. »

## 04:20–05:00 — Trois erreurs à repérer
[À l'écran : schéma pédagogique explicitement étiqueté « FAUX — À NE PAS REPRODUIRE ».]

« Pour terminer, voici trois erreurs. Première erreur : relier cinq volts directement au VBAT du SIM800L nu. Deuxième erreur : amener le secteur sur une breadboard. Troisième erreur : connecter des signaux cinq volts aux broches du modem sans vérifier la compatibilité des niveaux logiques.

Pouvez-vous dire pourquoi chacune est dangereuse ? Faites une pause et consultez l'exercice corrigé.

Dans la prochaine vidéo, nous installerons Arduino IDE et nous réaliserons notre premier programme : une LED qui clignote, uniquement en basse tension. »

### Notes au formateur
- Aucune démonstration de raccordement secteur pour les débutants.
- Références à vérifier pour les caractéristiques : documentation SIMCom du SIM800L nu et fiche de la carte Arduino utilisée.
- Les durées sont des cibles ; chronométrer avant tournage.
