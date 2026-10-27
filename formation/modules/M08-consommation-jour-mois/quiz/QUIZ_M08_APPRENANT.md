# Quiz M08 — Consommations du jour et du mois (apprenant)

**10 QCM (4 faciles, 4 intermédiaires, 2 difficiles) · une seule réponse correcte · seuil de réussite 8/10.** Aucune manipulation secteur.

## Q01 — Quelle formule calcule l'énergie consommée entre deux relevés valides d'un même compteur ?

*Facile · Index et delta*

A. Index précédent + index nouveau
B. Index nouveau - index précédent
C. Puissance instantanée × index total
D. Index du mois × 24

## Q02 — L'index passe de 120400 Wh à 120650 Wh. Quelle énergie supplémentaire a été mesurée ?

*Facile · Unités*

A. 250 Wh, soit 0,250 kWh
B. 250 kWh
C. 120650 Wh de la seule période
D. 0 Wh

## Q03 — Deux relevés consécutifs identiques ont le même index. Que faut-il ajouter au cumul ?

*Facile · Doublon*

A. Deux fois l'index
B. La moitié de l'index
C. Le dernier index
D. 0 Wh

## Q04 — Quel composant fournit la date permettant de distinguer les journées dans notre projet ?

*Facile · Calendrier*

A. SIM800L
B. PZEM-004T
C. DS3231
D. LCD 20×4

## Q05 — Que fait le logiciel lorsque la date passe du 31 janvier au 1er février ?

*Intermédiaire · Périodes*

A. Il remet l'index interne du PZEM à zéro
B. Il démarre de nouvelles bases jour/mois en conservant l'index PZEM cumulatif
C. Il multiplie le dernier index par 2
D. Il efface la date RTC

## Q06 — Dernier relevé le 31/01 à 23:59, suivant le 01/02 à 00:05. Peut-on attribuer exactement le delta à janvier ou février ?

*Intermédiaire · Périodes*

A. Oui, tout à janvier
B. Oui, tout à février
C. Oui, moitié-moitié de façon certaine
D. Non, pas sans relevé de frontière ou information supplémentaire

## Q07 — Après la mise en route du compteur le 27 octobre à midi sans état sauvegardé, que signifie le cumul jour calculé ?

*Intermédiaire · Validité*

A. La consommation calculée depuis le premier relevé de midi, pas forcément depuis 00:00
B. La consommation exacte depuis minuit
C. Une preuve que personne n'a consommé le matin
D. Un index à effacer dans le PZEM

## Q08 — L'index passe de 120740 Wh à 20 Wh. Quelle stratégie pédagogique est correcte ?

*Intermédiaire · Fiabilité*

A. Calculer 20 - 120740 en uint32_t sans contrôle
B. Afficher une consommation négative comme normale
C. Signaler une réinitialisation/anomalie, réancrer et marquer les périodes incomplètes
D. Ajouter immédiatement 120740 Wh à la journée

## Q09 — Le programme restaure une copie de l'état depuis une variable en RAM, puis reçoit à nouveau le dernier relevé sauvegardé. Que peut-on conclure ?

*Difficile · Reprise*

A. La FRAM est déjà implémentée et résiste à toutes les coupures
B. La RTC a automatiquement sauvegardé les cumuls
C. Une copie en RAM est durable après débranchement de l'alimentation
D. Le doublon peut être évité, mais la vraie persistance après coupure nécessite une mémoire non volatile

## Q10 — Sur ATmega328P, pourquoi utiliser des Wh entiers dans notre moteur, plutôt que d'accumuler naïvement des grands index float de la bibliothèque ?

*Difficile · Précision*

A. Parce qu'un int 16 bits peut stocker une infinité de Wh
B. Parce qu'un float AVR a une précision limitée ; les Wh entiers évitent les arrondis répétés, sous réserve d'une acquisition et d'une plage valides
C. Parce que le PZEM mesure directement les kWh du jour
D. Parce qu'un entier n'a jamais de limite de capacité

---

**Consigne :** prévoir les résultats du code et les limites des données avant d'ouvrir le corrigé.
