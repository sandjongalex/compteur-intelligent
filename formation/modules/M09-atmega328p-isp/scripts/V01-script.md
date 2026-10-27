# M09-V01 — Script du formateur : construire le circuit minimal ATmega328P (8 min)

**Pédagogie : résultat → ancien firmware M08 → puce autonome → broches → alimentation → horloge → vérification → défi.**  
**Matériel de démonstration :** Uno Rev3, ATmega328P **PDIP28** sur breadboard, 5 V régulé, quartz 16 MHz compatible et deux condensateurs de charge calculés/adaptés, 100 nF de découplage, résistance RESET 10 kΩ, LED avec résistance série, matériel USB. **Aucun secteur**.  
Ce qui est entre guillemets est prononcé ; [ÉCRAN] et [MANIP] décrivent les plans à tourner. Durées indicatives : répéter avant enregistrement.

## 00:00–00:55 — Montrer où nous en sommes

[ÉCRAN] Ouvrir `firmware/etapes/M08/Compteur_M08/Compteur_M08.ino` puis la version M09. Sur l'Uno, montrer les commandes série et les cumuls fictifs, si l'essai a réellement été exécuté.

« Notre compteur intelligent possède déjà son programme : il gère la LED et le bouton, affiche six valeurs électriques, lit une date et calcule les consommations du jour et du mois. Jusqu'à présent, nous avons développé et testé sa version simulée sur Arduino Uno.

Aujourd'hui, nous n'allons **pas recréer ce compteur**. Nous allons apprendre à faire exécuter **le même firmware** par un microcontrôleur ATmega328P installé sur notre propre petit circuit.

Vous allez découvrir pourquoi une puce ne fonctionne pas à elle seule dès qu'on la pose sur une breadboard, même lorsque son programme est correct. »

## 00:55–02:05 — La carte Uno versus le microcontrôleur

[MANIP] Présenter Uno complète et puce PDIP28 avec encoche visible, tous les montages **hors tension**.

« Regardez notre Arduino Uno. Elle nous simplifie le travail : la carte contient une alimentation adaptée, une horloge, un système de programmation USB et des connecteurs faciles à utiliser.

Notre ATmega328P, en revanche, est le cerveau du système sans tous ces éléments autour. Nous devons lui fournir au minimum une alimentation correcte, une référence d'horloge compatible avec sa configuration, et un moyen de le reprogrammer.

Dans ce cours, nous choisissons volontairement un **ATmega328P en boîtier DIP à 28 broches**, afin de pouvoir le placer sur une breadboard. Attention : certains modèles d'Uno ont leur ATmega soudé ; nous n'avons pas besoin de retirer la puce d'une Uno pour apprendre la programmation ISP. »

## 02:05–03:15 — Orienter le boîtier et repérer VCC/GND/RESET

[ÉCRAN] Afficher le tableau PDIP28 et un zoom de l'encoche.

« Avant de connecter quoi que ce soit, nous orientons la puce avec son encoche vers le haut. Les numéros sont ensuite comptés autour du boîtier. Une erreur d'orientation inverse très vite les connexions.

Sur notre ATmega328P DIP28, **VCC est la broche 7**, **AVCC la 20**, et les masses sont les broches **8 et 22**. Nous devons connecter correctement les deux alimentations prévues par la documentation.

La **broche 1 est RESET**. Nous prévoyons une résistance de tirage, par exemple dix kilo-ohms vers le 5 volts, pour empêcher les réinitialisations intempestives lorsque rien ne la commande.

Nous allons travailler avec une alimentation **5 volts régulée et vérifiée**. Aucun appareil ne sera raccordé au secteur dans cette expérience. »

## 03:15–04:35 — Découplage et horloge 16 MHz

[MANIP] Positionner les condensateurs céramiques de 100 nF au plus près des alimentations et, sous tension coupée, montrer le quartz entre les broches 9 et 10.

« Une puce numérique fait varier rapidement son courant interne. Les condensateurs de découplage, notamment cent nanofarads proches des broches d'alimentation, limitent les perturbations de la tension.

Notre firmware a été compilé jusqu'ici comme un programme pour Arduino Uno, à seize mégahertz. Pour garder les mêmes temporisations et les mêmes broches, nous préparons ici un ATmega328P **à seize mégahertz**.

Dans cette configuration, les entrées du quartz sont les broches **9 et 10** du boîtier DIP28. Le quartz doit être choisi avec des condensateurs de charge adaptés à sa référence ; les valeurs d'environ vingt-deux picofarads souvent montrées sont des exemples, pas une règle universelle.

Très important : **l'horloge configurée dans les fuses et l'horloge réellement présente sur la carte doivent correspondre**. Si la puce attend un quartz externe et qu'il manque, elle peut sembler ne plus répondre à la programmation. »

## 04:35–05:45 — Retrouver les broches du programme précédent

[ÉCRAN] Comparer `PIN_BOUTON = 2` et `LED_BUILTIN` dans le firmware M08/M09 ; montrer PD2 et PB5 dans le tableau.

« Notre bouton utilisait la broche Arduino D2 ; sur la puce DIP28, il s'agit de **PD2, broche physique 4**. Notre LED utilisait D13 ; dans le boîtier DIP28, c'est **PB5, broche physique 19**.

Ces numéros différents ne signifient pas que notre programme change entièrement. D2 et D13 sont des noms de la plateforme Arduino ; PD2 et PB5 sont des noms internes du microcontrôleur, et quatre et dix-neuf sont des numéros de pattes physiques.

La puce nue ne contient pas la petite LED L de la carte Uno. Nous devons donc prévoir **une LED externe et une résistance série**, si nous voulons voir le résultat. Notre bouton reste raccordé vers GND et utilise `INPUT_PULLUP`, comme au module 05.

[MANIP] Montrer que ce sont bien des éléments du **même compteur**, sans manipuler les fils tant que l'USB est branché. »

## 05:45–06:55 — Introduire la nouveauté dans le firmware M09

[ÉCRAN] Ouvrir `firmware/etapes/M09/Compteur_M09/Compteur_M09.ino` et afficher le diff des premières lignes avec M08.

« Maintenant, voyons la nouveauté en programmation. Dans notre fichier principal, nous avons ajouté l'option `ALEXTECH_ATMEGA_AUTONOME`.

Par défaut, elle vaut zéro : c'est toujours la démonstration classique sur Uno. Lorsque le montage externe est prêt, nous pouvons la passer à un. Le code vérifie alors que la cible choisie est bien l'ATmega328P et que la configuration de compilation utilise seize mégahertz.

Nous avons aussi ajouté une fonction de diagnostic qui explique les broches utilisées. Mais regardez : la fonction qui lit les mesures, celle qui gère les boutons et le calcul des consommations sont toujours là.

Cette modification n'alimente pas la puce, ne change pas ses fuses à distance et ne remplace pas le montage d'horloge. **La configuration logicielle et les composants physiques doivent être cohérents.** »

## 06:55–07:35 — Erreur fréquente et méthode de contrôle

[ÉCRAN] Présenter une liste : orientation — 5 V — masses — RESET — quartz — LED.

« Première erreur classique : sélectionner Arduino Uno dans l'IDE et en conclure que le microcontrôleur externe fonctionnera sans quartz. La compilation ne crée pas un oscillateur physique.

Deuxième erreur : oublier que la LED intégrée se trouve sur la carte Uno, pas dans l'ATmega328P seul.

Troisième erreur : connecter l'alimentation ou les fils alors que le montage est sous tension. Nous vérifions toujours les connexions hors USB et nous utilisons une seule alimentation adaptée. »

## 07:35–08:00 — Défi et transition ISP

[ÉCRAN] Masquer quatre cases d'une table DIP28 à compléter.

« Votre exercice : retrouvez sur le boîtier les broches RESET, VCC, AVCC, GND, D2 et D13. Puis expliquez pourquoi nous utilisons encore le code du M08.

Dans la prochaine vidéo, nous allons utiliser **une Arduino Uno comme programmateur ISP** pour envoyer d'abord un petit diagnostic, puis **notre véritable firmware du compteur** à cette puce autonome. »

## À vérifier avant tournage

- [ ] Référence PDIP28, quartz et consommation de la carte de démonstration validés.
- [ ] Aucune manipulation secteur ; circuit 5 V vérifié.
- [ ] Le formateur distingue D13 Arduino et broche physique 19, D2 et broche physique 4.
- [ ] Le code M08 est montré avant les changements M09.
- [ ] La durée réelle de la vidéo a été répétée et chronométrée.
