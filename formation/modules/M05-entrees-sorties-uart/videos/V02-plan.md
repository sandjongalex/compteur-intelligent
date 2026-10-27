# M05-V02 — UART et périodicité non bloquante avec millis (9 minutes)

**État : script complet et 3 sketches progressifs rédigés. Essais matériels et tournage non encore effectués.**

## Objectif observable

Recevoir `1`, `0`, `?` depuis le moniteur série à **9600 bauds**, commander la LED et émettre **230,5 V SIMULÉS** environ une fois par seconde **sans `delay()`**.

## Progression minute par minute

| Temps | Ce que le formateur montre | Fichier |
|---|---|---|
| 00:00–00:55 | Résultat final : relevés périodiques + commandes réactives | [V02-03](../code/V02_03_millis_et_uart/V02_03_millis_et_uart.ino) |
| 00:55–02:05 | TX/RX, trame UART, USB de l'Uno, 9600 bauds | [Mémo](../ressources/MEMO_M05.md) |
| 02:05–03:15 | `Serial.available()`, `Serial.read()`, écho d'un caractère | [V02-01](../code/V02_01_uart_echo/V02_01_uart_echo.ino) |
| 03:15–04:30 | Commandes `1` ON, `0` OFF, `?` aide | [V02-02](../code/V02_02_commandes_uart/V02_02_commandes_uart.ino) |
| 04:30–05:25 | Pourquoi `delay()` gêne les commandes | [Mémo](../ressources/MEMO_M05.md) |
| 05:25–07:35 | `millis`, `unsigned long`, calcul du temps écoulé ; tâche toutes les ~1 000 ms | [V02-03](../code/V02_03_millis_et_uart/V02_03_millis_et_uart.ino) |
| 07:35–08:25 | Dépanner une mauvaise vitesse série, une commande inconnue, une attente bloquante | [Dépannage](../ressources/DEPANNAGE.md) |
| 08:25–09:00 | Mini-défi : période ~500 ms, UART toujours disponible | [TP02](../tp/TP_M05_APPRENANT.md) |

[Lire le script intégral du formateur](../scripts/V02-script.md). Les durées sont des **cibles de montage**.

## Précautions

- La tension est une **valeur simulée**, pas une mesure du secteur.
- Ne pas brancher d'équipement externe sur D0/D1 quand on utilise le port matériel/USB de la Uno dans cette démonstration.
- [ ] Les trois sketches compilent, puis les messages sont observés sur la véritable carte.
- [ ] Le formateur teste réellement les commandes et la fréquence d'affichage.
