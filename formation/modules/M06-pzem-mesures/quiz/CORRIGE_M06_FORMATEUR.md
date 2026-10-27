# M06 — Corrigé détaillé réservé au formateur

**Grille des bonnes réponses :** Q01=C · Q02=A · Q03=B · Q04=D · Q05=B · Q06=C · Q07=A · Q08=D · Q09=B · Q10=B.

## Q01 — Quelle unité doit accompagner la tension renvoyée par le PZEM-004T V3 ?

**Bonne réponse : C**

- **A. Le kilowattheure (kWh)** — Le kWh mesure l'énergie cumulée.
- **B. L'ampère (A)** — L'ampère mesure le courant.
- **C. Le volt (V)** — Le volt est l'unité de tension.
- **D. Le hertz (Hz)** — Le hertz mesure la fréquence.

Objectif évalué : Tension.

## Q02 — Quelle fonction décrit le mieux la grandeur lue par pzem.power() ?

**Bonne réponse : A**

- **A. La puissance active exprimée en watts** — La bibliothèque retourne la puissance active en watts.
- **B. La date du relevé** — La date viendra plus tard de la RTC DS3231.
- **C. Le courant exprimé en ampères** — pzem.current() correspond au courant.
- **D. L'index cumulatif d'énergie** — pzem.energy() renvoie l'index cumulatif.

Objectif évalué : Puissance.

## Q03 — Dans la communication PZEM V3, à quoi sert un registre de mesure ?

**Bonne réponse : B**

- **A. À alimenter le SIM800L** — Le registre ne fournit pas d'alimentation au modem.
- **B. À représenter une donnée numérique identifiée par une adresse** — Un registre numéroté contient un mot de données qu'il faut interpréter.
- **C. À stocker des vidéos PowerPoint** — Les registres de mesure ne stockent pas de documents.
- **D. À réinitialiser le microcontrôleur à chaque seconde** — Lire un registre ne commande pas un redémarrage.

Objectif évalué : Rôle d'un registre.

## Q04 — Le moniteur affiche 230,5 V, mais aucune mesure secteur n'est branchée. Quelle phrase est exacte ?

**Bonne réponse : D**

- **A. Le résultat prouve la précision du PZEM réel.** — Une constante fictive ne valide pas la métrologie.
- **B. Le secteur est nécessaire pour compiler ce code.** — Le sketch de simulation fonctionne par USB uniquement.
- **C. La lecture est forcément un défaut matériel.** — L'absence de capteur est voulue dans la simulation.
- **D. Les valeurs sont simulées et ne prouvent pas une mesure physique.** — Le nombre imprimé est tiré du programme et étiqueté fictif.

Objectif évalué : Identifier une démonstration.

## Q05 — Le registre 0x0000 du PZEM V3 contient la valeur brute 2305, avec un pas de 0,1 V. Quel est le résultat ?

**Bonne réponse : B**

- **A. 2305 V** — 2305 est la valeur brute, pas les volts.
- **B. 230,5 V** — 2305 multiplié par 0,1 vaut 230,5 V.
- **C. 23,05 V** — Il faudrait un facteur 0,01 pour obtenir cette valeur.
- **D. 2,305 V** — Il faudrait un facteur 0,001 pour obtenir cette valeur.

Objectif évalué : Convertir une tension brute.

## Q06 — Le compteur fournit une énergie brute de 12 345 Wh. Quelle énergie cumulée en kWh faut-il afficher ?

**Bonne réponse : C**

- **A. 12 345 kWh** — Ce serait oublier la conversion Wh vers kWh.
- **B. 123,45 kWh** — 123,45 est obtenu avec un diviseur de 100.
- **C. 12,345 kWh** — 12 345 Wh / 1 000 = 12,345 kWh.
- **D. 1,2345 kWh** — Le diviseur 10 000 ne convient pas à l'unité donnée.

Objectif évalué : Convertir un index énergie.

## Q07 — Que représentent TX/RX et Modbus RTU dans notre projet ?

**Bonne réponse : A**

- **A. UART échange des octets ; Modbus définit les requêtes, adresses, réponses et contrôles.** — Le transport série et le protocole applicatif ont des rôles complémentaires.
- **B. Modbus fournit directement l'énergie du mois sans horloge.** — La consommation du mois sera calculée à partir de l'index avec une RTC.
- **C. UART mesure la tension secteur, tandis que Modbus allume la LED.** — Aucun des deux ne mesure physiquement la tension.
- **D. Les deux termes désignent uniquement le câble d'alimentation du PZEM.** — Ils concernent la communication, pas l'alimentation seule.

Objectif évalué : Lire Modbus RTU.

## Q08 — La fonction de lecture renvoie false. Quel comportement est correct ?

**Bonne réponse : D**

- **A. Afficher 0,0 kWh comme nouveau relevé réel.** — Zéro peut être une vraie valeur physique et ne doit pas désigner une erreur.
- **B. Réutiliser l'ancien index sans indiquer son ancienneté.** — Une valeur ancienne ne peut pas être présentée comme une nouvelle mesure.
- **C. Réinitialiser l'index PZEM par resetEnergy().** — ResetEnergy détruit l'index cumulatif ; ce n'est pas une solution aux pannes.
- **D. Afficher une erreur et ne pas publier de nouvelle mesure comme si elle était valide.** — L'état d'erreur est séparé des valeurs, qui ne sont pas actualisées.

Objectif évalué : Valeur indisponible.

## Q09 — Un registre bas contient 0x0001 et le registre haut 0x0001. Quelle valeur entière obtient-on avec (haut << 16) | bas ?

**Bonne réponse : B**

- **A. 2** — Les mots haut et bas ne s'additionnent pas simplement en 1+1.
- **B. 65 537** — 0x0001 << 16 = 65 536 ; puis OR 1 donne 65 537.
- **C. 1 001** — Cette valeur ne provient pas de l'assemblage 32 bits.
- **D. 4 096** — Cette valeur ne correspond pas au décalage de 16 bits.

Objectif évalué : Assembler 32 bits.

## Q10 — Pourquoi ne faut-il pas remettre automatiquement l'index énergie PZEM à zéro chaque nuit pour calculer les kWh du jour ?

**Bonne réponse : B**

- **A. Parce que la puissance est toujours égale à la tension.** — Ce n'est pas une égalité générale en AC.
- **B. Parce que l'index total doit rester croissant comme référence, et les kWh/jour seront calculés par différence d'index sauvegardés.** — La consommation par période se calcule à partir d'un index cumulatif de référence ; la remise à zéro casse ce repère.
- **C. Parce que le facteur de puissance doit toujours être zéro.** — Le facteur de puissance dépend de la charge et ne doit pas forcément être zéro.
- **D. Parce que le modem GSM compte les secondes.** — Le modem ne remplace pas l'index énergétique ni la RTC.

Objectif évalué : Index cumulatif et périodes.

## Remédiation

- En dessous de **8/10**, reprendre le module et ses exercices.
- Échec sur **Q05/Q06/Q09** : revoir l'échelle des registres et l'assemblage 32 bits.
- Échec sur **Q08/Q10** : revoir la distinction « valeur absente / zéro réel / index historique ».
- Corriger systématiquement toute affirmation qui conduirait à manipuler le secteur sans qualification.
- Les questions et le barème sont rédigés, mais **pas encore importés** dans la plateforme de formation.
