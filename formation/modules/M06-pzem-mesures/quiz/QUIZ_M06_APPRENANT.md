# M06 — Quiz pour apprenants (sans réponses)

**10 questions · 1 seule bonne réponse par question · validation : 8/10.**  
Aucun PZEM ni secteur n'est nécessaire pour répondre : tous les calculs reposent sur des valeurs fictives.

## Q01 — Quelle unité doit accompagner la tension renvoyée par le PZEM-004T V3 ?

*Facile · Objectif : Tension*

A. Le kilowattheure (kWh)
B. L'ampère (A)
C. Le volt (V)
D. Le hertz (Hz)

## Q02 — Quelle fonction décrit le mieux la grandeur lue par pzem.power() ?

*Facile · Objectif : Puissance*

A. La puissance active exprimée en watts
B. La date du relevé
C. Le courant exprimé en ampères
D. L'index cumulatif d'énergie

## Q03 — Dans la communication PZEM V3, à quoi sert un registre de mesure ?

*Facile · Objectif : Rôle d'un registre*

A. À alimenter le SIM800L
B. À représenter une donnée numérique identifiée par une adresse
C. À stocker des vidéos PowerPoint
D. À réinitialiser le microcontrôleur à chaque seconde

## Q04 — Le moniteur affiche 230,5 V, mais aucune mesure secteur n'est branchée. Quelle phrase est exacte ?

*Facile · Objectif : Identifier une démonstration*

A. Le résultat prouve la précision du PZEM réel.
B. Le secteur est nécessaire pour compiler ce code.
C. La lecture est forcément un défaut matériel.
D. Les valeurs sont simulées et ne prouvent pas une mesure physique.

## Q05 — Le registre 0x0000 du PZEM V3 contient la valeur brute 2305, avec un pas de 0,1 V. Quel est le résultat ?

*Intermédiaire · Objectif : Convertir une tension brute*

A. 2305 V
B. 230,5 V
C. 23,05 V
D. 2,305 V

## Q06 — Le compteur fournit une énergie brute de 12 345 Wh. Quelle énergie cumulée en kWh faut-il afficher ?

*Intermédiaire · Objectif : Convertir un index énergie*

A. 12 345 kWh
B. 123,45 kWh
C. 12,345 kWh
D. 1,2345 kWh

## Q07 — Que représentent TX/RX et Modbus RTU dans notre projet ?

*Intermédiaire · Objectif : Lire Modbus RTU*

A. UART échange des octets ; Modbus définit les requêtes, adresses, réponses et contrôles.
B. Modbus fournit directement l'énergie du mois sans horloge.
C. UART mesure la tension secteur, tandis que Modbus allume la LED.
D. Les deux termes désignent uniquement le câble d'alimentation du PZEM.

## Q08 — La fonction de lecture renvoie false. Quel comportement est correct ?

*Intermédiaire · Objectif : Valeur indisponible*

A. Afficher 0,0 kWh comme nouveau relevé réel.
B. Réutiliser l'ancien index sans indiquer son ancienneté.
C. Réinitialiser l'index PZEM par resetEnergy().
D. Afficher une erreur et ne pas publier de nouvelle mesure comme si elle était valide.

## Q09 — Un registre bas contient 0x0001 et le registre haut 0x0001. Quelle valeur entière obtient-on avec (haut << 16) | bas ?

*Difficile · Objectif : Assembler 32 bits*

A. 2
B. 65 537
C. 1 001
D. 4 096

## Q10 — Pourquoi ne faut-il pas remettre automatiquement l'index énergie PZEM à zéro chaque nuit pour calculer les kWh du jour ?

*Difficile · Objectif : Index cumulatif et périodes*

A. Parce que la puissance est toujours égale à la tension.
B. Parce que l'index total doit rester croissant comme référence, et les kWh/jour seront calculés par différence d'index sauvegardés.
C. Parce que le facteur de puissance doit toujours être zéro.
D. Parce que le modem GSM compte les secondes.

## Conseils

Répondre sans consulter le corrigé. Lorsqu'une question de diagnostic, de protocole ou de sécurité pose problème, relire les explications et reproduire les conversions sur papier avant de reprendre le quiz.
