# M05 — Travaux pratiques pour l'apprenant

**À réaliser après les 18 minutes de vidéo. Temps suggéré : 30 à 50 minutes.**  
Matériel : Arduino Uno Rev3, câble USB de données, bouton-poussoir, fils pour basse tension, Arduino IDE 2. Utiliser **uniquement la LED « L » intégrée**, pas de raccordement secteur.

## TP 01 — Un bouton pour changer de page

**Contexte :** notre futur compteur doit changer de page LCD à chaque appui. Nous n'utilisons pas encore le LCD : la LED intégrée et le moniteur série simulent les deux pages.

**Point de départ :** [V01-03, LED avec anti-rebond](../code/V01_03_bascule_antirebond/V01_03_bascule_antirebond.ino).

**Votre mission :**

1. Débrancher l'USB et vérifier le bouton : **D2 ↔ contact ↔ GND**.
2. Téléverser la version V01-03 puis tester cinq pressions distinctes : la LED doit changer cinq fois.
3. Ajouter une variable `byte page = 0` ; utiliser **0** pour la page « tension » et **1** pour la page « énergie ».
4. À chaque appui **validé** par l'anti-rebond, faire alterner 0 → 1 → 0.
5. Afficher `Page : 0` ou `Page : 1` sur le moniteur série à **9600 bauds**.
6. Utiliser la LED « L » comme témoin : allumée si page 1, éteinte si page 0.

**Résultat attendu :** une pression validée produit **un seul changement de page**. Une pression maintenue ne produit pas plusieurs changements. Le relâchement seul ne change pas la page.

**Livrables :** sketch, courte capture des messages série et explication de `INPUT_PULLUP`, `LOW`, front validé et `millis()`. **Ne pas joindre le corrigé au rendu.**

**Indices si bloqué :** le moment où l'on bascule `ledAllumee` dans le sketch fourni est le bon endroit pour modifier `page`. Ne pas mettre le changement de page dans une instruction exécutée à chaque passage dans `loop()`.

## TP 02 — Lire l'UART sans bloquer le relevé

**Contexte :** le compteur doit publier une tension **fictive** régulièrement et accepter en même temps des commandes de LED.

**Point de départ :** [V02-03, UART et millis](../code/V02_03_millis_et_uart/V02_03_millis_et_uart.ino).

**Votre mission :**

1. Vérifier et téléverser le sketch fourni sur une Uno Rev3.
2. Régler le moniteur série sur **9600 bauds** et envoyer successivement `1`, `0`, `?`.
3. Observer l'affichage `Tension SIMULEE : 230.5 V` environ toutes les **1 000 ms**.
4. Modifier **seulement** `PERIODE_MS` pour obtenir environ **500 ms**.
5. Garder les commandes `1`, `0`, `?` utilisables entre les lignes périodiques.
6. Vérifier que votre version ne contient **aucun `delay()`** dans `loop()`.

**Résultat attendu :** deux lignes fictives environ par seconde, commande `1` → LED ON, `0` → LED OFF et `?` → aide. Le programme ignore la fin de ligne ajoutée par le moniteur.

**Livrables :** code modifié, sortie du moniteur série, explication de la différence entre `Serial.available()` et `Serial.read()`.

**Indices :** repérez la constante de période ; ne modifiez pas le débit en bauds pour accélérer l'affichage.

## TP 03 — Défi de réflexion (facultatif)

Quel risque apparaît lorsqu'on insère un `delay(5000)` au début de `loop()` ? Expliquer pourquoi, pendant cette pause, la carte ne traite pas immédiatement une nouvelle commande envoyée depuis le PC.

## Validation

- **TP 01 :** une pression = un changement ; cinq pressions = cinq changements attendus.
- **TP 02 :** messages fictifs ~500 ms et commandes LED toujours réactives, sans `delay`.
- Revoir la [fiche de câblage](../ressources/CABLAGE_BASSE_TENSION.md) et le [guide de dépannage](../ressources/DEPANNAGE.md) avant d'intervenir sur un montage.

Le résultat de chaque TP doit être vérifié sur une **vraie Uno** avant validation finale de l'apprenant.
