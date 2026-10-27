# M08 — Corrigé du quiz réservé au formateur

**Grille :** Q01=B · Q02=A · Q03=D · Q04=C · Q05=B · Q06=D · Q07=A · Q08=C · Q09=D · Q10=B.

## Q01 — Quelle formule calcule l'énergie consommée entre deux relevés valides d'un même compteur ?

**Réponse correcte : B**

- **A. Index précédent + index nouveau** — Additionner les index revient à compter l'énergie passée plusieurs fois.
- **B. Index nouveau - index précédent** — La différence des index continus fournit l'énergie supplémentaire.
- **C. Puissance instantanée × index total** — La puissance et l'index cumulé ne peuvent pas être multipliés ainsi.
- **D. Index du mois × 24** — Multipliez un index par 24 ne donne pas la consommation d'une période.

## Q02 — L'index passe de 120400 Wh à 120650 Wh. Quelle énergie supplémentaire a été mesurée ?

**Réponse correcte : A**

- **A. 250 Wh, soit 0,250 kWh** — La différence est 250 Wh, que l'on divise par 1000 pour obtenir 0,250 kWh.
- **B. 250 kWh** — Ce serait oublier la conversion Wh/kWh.
- **C. 120650 Wh de la seule période** — 120650 Wh est l'index cumulatif, pas le seul delta.
- **D. 0 Wh** — Les deux index sont différents : l'énergie a augmenté.

## Q03 — Deux relevés consécutifs identiques ont le même index. Que faut-il ajouter au cumul ?

**Réponse correcte : D**

- **A. Deux fois l'index** — Cela produirait un double comptage.
- **B. La moitié de l'index** — Aucun principe ne justifie de diviser l'index par deux.
- **C. Le dernier index** — L'index est le total historique, pas une variation.
- **D. 0 Wh** — La différence entre deux index identiques vaut zéro.

## Q04 — Quel composant fournit la date permettant de distinguer les journées dans notre projet ?

**Réponse correcte : C**

- **A. SIM800L** — Le SIM800L n'est pas notre référence de calendrier pour ce module.
- **B. PZEM-004T** — Le PZEM fournit les mesures électriques et un index, pas la date du jour.
- **C. DS3231** — Le DS3231 est notre horloge temps réel.
- **D. LCD 20×4** — Le LCD affiche des valeurs mais ne fournit pas lui-même le calendrier.

## Q05 — Que fait le logiciel lorsque la date passe du 31 janvier au 1er février ?

**Réponse correcte : B**

- **A. Il remet l'index interne du PZEM à zéro** — Réinitialiser l'index PZEM détruirait le repère historique.
- **B. Il démarre de nouvelles bases jour/mois en conservant l'index PZEM cumulatif** — Les cumuls logiciels changent de période ; l'index physique continue.
- **C. Il multiplie le dernier index par 2** — Cette opération n'a pas de sens énergétique.
- **D. Il efface la date RTC** — La RTC doit fournir la date correcte, pas être effacée.

## Q06 — Dernier relevé le 31/01 à 23:59, suivant le 01/02 à 00:05. Peut-on attribuer exactement le delta à janvier ou février ?

**Réponse correcte : D**

- **A. Oui, tout à janvier** — Une partie peut avoir été consommée après minuit.
- **B. Oui, tout à février** — Une partie peut avoir été consommée avant minuit.
- **C. Oui, moitié-moitié de façon certaine** — Une répartition égale serait une estimation non justifiée.
- **D. Non, pas sans relevé de frontière ou information supplémentaire** — Le delta traverse le changement de mois ; le détail de consommation à minuit n'est pas connu.

## Q07 — Après la mise en route du compteur le 27 octobre à midi sans état sauvegardé, que signifie le cumul jour calculé ?

**Réponse correcte : A**

- **A. La consommation calculée depuis le premier relevé de midi, pas forcément depuis 00:00** — L'absence de base à minuit impose de marquer la période incomplète.
- **B. La consommation exacte depuis minuit** — Le compteur ne connaît pas les heures précédant la première base.
- **C. Une preuve que personne n'a consommé le matin** — Ne rien observer ne signifie pas qu'il n'y a pas eu consommation.
- **D. Un index à effacer dans le PZEM** — On ne remet pas le PZEM à zéro pour reconstruire le passé.

## Q08 — L'index passe de 120740 Wh à 20 Wh. Quelle stratégie pédagogique est correcte ?

**Réponse correcte : C**

- **A. Calculer 20 - 120740 en uint32_t sans contrôle** — Une soustraction non signée peut donner un énorme faux résultat.
- **B. Afficher une consommation négative comme normale** — Un compteur cumulatif n'a normalement pas cette diminution sans événement particulier.
- **C. Signaler une réinitialisation/anomalie, réancrer et marquer les périodes incomplètes** — La nouvelle base évite de fabriquer un delta et la période doit être signalée comme partielle.
- **D. Ajouter immédiatement 120740 Wh à la journée** — Ajouter l'ancienne valeur serait injustifié et compterait le passé.

## Q09 — Le programme restaure une copie de l'état depuis une variable en RAM, puis reçoit à nouveau le dernier relevé sauvegardé. Que peut-on conclure ?

**Réponse correcte : D**

- **A. La FRAM est déjà implémentée et résiste à toutes les coupures** — Aucune FRAM n'a été écrite dans cette démonstration.
- **B. La RTC a automatiquement sauvegardé les cumuls** — La RTC garde l'heure, pas l'état des cumuls de cette classe.
- **C. Une copie en RAM est durable après débranchement de l'alimentation** — La RAM volatile perd les données lors d'une vraie coupure.
- **D. Le doublon peut être évité, mais la vraie persistance après coupure nécessite une mémoire non volatile** — La démonstration teste la logique de reprise mais pas la durabilité, traitée au M11.

## Q10 — Sur ATmega328P, pourquoi utiliser des Wh entiers dans notre moteur, plutôt que d'accumuler naïvement des grands index float de la bibliothèque ?

**Réponse correcte : B**

- **A. Parce qu'un int 16 bits peut stocker une infinité de Wh** — Un int signé AVR 16 bits est insuffisant pour un grand index.
- **B. Parce qu'un float AVR a une précision limitée ; les Wh entiers évitent les arrondis répétés, sous réserve d'une acquisition et d'une plage valides** — Les flottants AVR n'ont qu'une précision limitée. Un uint32_t en Wh donne des soustractions exactes dans sa plage ; la conversion initiale doit aussi préserver la précision.
- **C. Parce que le PZEM mesure directement les kWh du jour** — Le PZEM fournit un index cumulatif, pas le découpage calendrier.
- **D. Parce qu'un entier n'a jamais de limite de capacité** — Un uint32_t est limité à 0..4294967295, il faut gérer plage et retour éventuel.

## Validation

- Réussite à partir de **8/10**.
- En cas d'erreur aux Q06/Q07 : reprendre la notion de **période incomplète**.
- En cas d'erreur aux Q08/Q09 : revoir les anomalies d'index, l'idempotence et la différence RAM/FRAM.
- En cas d'erreur aux Q02/Q10 : reprendre les unités Wh/kWh et la précision des entiers sur AVR.
- L'intégration du quiz à AlexTech Academy est une étape ultérieure.
