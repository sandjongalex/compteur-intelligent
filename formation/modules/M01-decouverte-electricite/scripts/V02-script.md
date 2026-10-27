# M01-V02 — Script intégral : Comprendre volts, ampères, watts et kilowattheures

**Durée cible : 5 minutes** · **Format : diapositives animées + calculs expliqués** · **Statut : rédigé, à chronométrer à l'enregistrement**

> Les textes entre guillemets sont à prononcer. Les indications **[VISUEL]** sont réservées au montage vidéo.

## 00:00–00:35 — Accroche : puissance ou énergie ?

[VISUEL : deux appareils fictifs, l'un puissant pendant peu de temps et l'autre moins puissant pendant longtemps.]

« Un appareil peut être très puissant, mais fonctionner seulement quelques minutes. Un autre peut être moins puissant et rester allumé plusieurs heures. Lequel consomme le plus d'énergie ?

Pour répondre, il faut comprendre quatre mots que nous rencontrerons tout au long du projet : tension, courant, puissance et énergie. Nous allons les découvrir avec des exemples simples. À la fin de cette vidéo, vous saurez calculer une consommation en kilowattheures. »

## 00:35–01:35 — Tension et courant

[VISUEL : image pédagogique d'un circuit basse tension, puis analogie du circuit d'eau.]

« Commençons avec la tension. Elle s'exprime en volts, avec la lettre V. Vous avez sans doute déjà vu l'indication cinq volts sur un appareil électronique ou deux cent trente volts sur une installation domestique. La tension correspond à une différence de potentiel électrique entre deux points. Elle joue un rôle dans la circulation du courant.

Le courant électrique, lui, correspond au débit de charges électriques qui traversent un conducteur. Il s'exprime en ampères, avec la lettre A.

Pour vous aider à retenir, imaginez un circuit d'eau : une différence de pression peut faire circuler l'eau, et son débit représente la quantité d'eau qui passe chaque seconde. C'est une analogie imparfaite, mais utile pour distinguer tension et courant.

Attention : un volt n'est pas un ampère. Ces deux unités ne décrivent pas la même chose. »

## 01:35–02:25 — La puissance

[VISUEL : wattmètre fictif montrant 500 W ; afficher « puissance = rythme de consommation d'énergie ».]

« La puissance nous indique à quel rythme un appareil transforme ou utilise de l'énergie. Son unité est le watt, noté W. Mille watts correspondent à un kilowatt, noté kW.

Par exemple, lorsqu'un appareil utilise une puissance active constante de cinq cents watts, nous pouvons dire que sa puissance est de zéro virgule cinq kilowatt.

Dans un circuit électrique continu très simple, on rencontre souvent la relation puissance égale tension multipliée par courant. Mais sur notre réseau alternatif, il faut également tenir compte du facteur de puissance pour calculer la puissance active à partir de la tension et du courant. Heureusement, le module PZEM nous fournira directement cette mesure.

Et surtout : la puissance n'est pas encore la quantité totale d'énergie consommée. »

## 02:25–03:25 — L'énergie électrique

[VISUEL : une horloge avance pendant que la puissance reste constante.]

« Pour connaître l'énergie, nous devons ajouter la durée de fonctionnement. L'énergie s'exprime par exemple en wattheures, Wh, ou en kilowattheures, kWh.

Si la puissance active reste constante, la règle est simple : énergie en kilowattheures égale puissance en kilowatts multipliée par durée en heures.

Prenons un appareil qui consomme une puissance active de mille watts, donc un kilowatt. S'il fonctionne pendant deux heures, il consomme deux kilowattheures.

Maintenant, imaginons une charge de cinq cents watts pendant quatre heures. Cinq cents watts, c'est zéro virgule cinq kilowatt. Zéro virgule cinq multiplié par quatre donne deux kilowattheures. L'énergie tient compte du temps : c'est la différence essentielle avec la puissance. »

## 03:25–04:20 — Deuxième calcul et lecture du compteur

[VISUEL : afficher « 2 000 W × 30 min » ; faire apparaître chaque étape.]

« Autre exemple : un appareil utilise deux mille watts de puissance active pendant trente minutes. Nous convertissons d'abord : deux mille watts égale deux kilowatts. Trente minutes, c'est une demi-heure, donc zéro virgule cinq heure.

Nous multiplions deux par zéro virgule cinq et obtenons un kilowattheure.

Notre compteur mesurera justement une énergie cumulée. Nous utiliserons cet index pour calculer combien de kilowattheures ont été consommés pendant une journée ou pendant un mois. Nous verrons le détail du calcul dans un module ultérieur.

Retenez qu'une valeur en watts décrit une puissance à un instant donné, alors qu'une valeur en kilowattheures décrit une quantité d'énergie accumulée. »

## 04:20–05:00 — Exercice et conclusion

[VISUEL : afficher 200 W pendant 5 h avec quatre réponses possibles ; laisser du temps de réflexion.]

« C'est à votre tour. Un appareil utilise deux cents watts de puissance active constante pendant cinq heures. Combien d'énergie consomme-t-il ?

Mettez la vidéo en pause et essayez. Deux cents watts correspondent à zéro virgule deux kilowatt. En multipliant zéro virgule deux par cinq heures, nous trouvons un kilowattheure.

Si vous avez trouvé ce résultat, félicitations ! Si vous avez hésité, reprenez simplement la conversion des watts en kilowatts, puis celle du temps en heures.

Nous savons désormais distinguer volts, ampères, watts et kilowattheures. Dans le prochain module, nous examinerons les composants de notre compteur ainsi que les règles de sécurité indispensables avant tout montage. »

---

## Vérification pédagogique

- L'hypothèse « puissance active constante pendant la durée » est explicite pour tous les calculs.
- Ne jamais assimiler systématiquement la puissance active alternative à U × I sans facteur de puissance.
- Toutes les valeurs de la démonstration sont fictives, sans manipulation du secteur.
- Durée cible à contrôler à voix haute et au montage.
