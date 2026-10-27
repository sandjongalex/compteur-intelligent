# Exercices M01 — Version apprenant

**Tout est réalisable sans branchement électrique.** Les données sont simulées. Préparer une feuille et, éventuellement, une calculatrice.

## TP 01 — Retracer le parcours d'une mesure (lié à M01-V01)

**Objectif :** identifier les fonctions d'acquisition, de calcul, de communication, de stockage et de consultation.

**Matériel :** fiche du [synoptique](../ressources/SYNOPTIQUE.md), feuille ou tableau.

**Durée hors vidéo :** 10 minutes.

### Énoncé de l'apprenant

On dispose des cinq éléments suivants, volontairement présentés dans le désordre :

- Navigateur web
- Modem SIM800L
- ATmega328P
- Module PZEM-004T
- Serveur Flask avec SQLite

1. Remettre les cinq éléments dans l'ordre de circulation d'un relevé.
2. Associer à chaque élément un verbe : mesurer, traiter, transmettre, enregistrer, consulter.
3. Expliquer si le LCD appartient au trajet GSM ou à l'affichage local.
4. Citer un composant qui conserve la date et un autre qui peut enregistrer des mesures non transmises.

**Résultat attendu :** schéma comportant cinq blocs, flèches dans le bon sens et deux réponses complémentaires.

---

## TP 02 — Calculer une consommation en kWh (lié à M01-V02)

**Objectif :** convertir des watts en kilowatts, des minutes en heures, et calculer l'énergie lorsque la puissance active est constante.

**Matériel :** crayon, calculatrice facultative, [fiche des unités](../ressources/FICHE_UNITES.md).

**Durée hors vidéo :** 15 minutes.

### Énoncé de l'apprenant

Pour chaque ligne, les appareils utilisent une **puissance active constante**.

| Cas | Puissance | Durée | Énergie à trouver |
|---|---:|---:|---|
| A | 200 W | 5 h | ... kWh |
| B | 500 W | 4 h | ... kWh |
| C | 2 000 W | 30 min | ... kWh |
| D | 100 W | 15 min | ... kWh |

Questions complémentaires :

1. Expliquer pourquoi 500 W et 500 Wh ne désignent pas la même grandeur.
2. Un écran affiche « 230,5 V » : cette donnée désigne-t-elle une tension, un courant ou une énergie ?
3. Si une puissance varie au cours de la journée, peut-on toujours calculer l'énergie exacte à partir d'une seule valeur instantanée de puissance ? Expliquer.

---

Quand les deux exercices sont terminés, remplir le [quiz M01](../quiz/QUIZ_M01_APPRENANT.md). Les corrections sont mises à disposition séparément par le formateur.
