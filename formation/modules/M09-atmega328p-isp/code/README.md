# M09 — Code pédagogique, puis même firmware fil rouge

**Séquence vidéo :** circuit minimal → diagnostic basse tension → ArduinoISP → programmation par ISP → **firmware du M08 adapté au même ATmega328P**.

1. [Diagnostic LED avec `millis()`](V01_01_diagnostic_led/V01_01_diagnostic_led.ino) : reconnaissance du brochage D13/PB5 et vérification de l'horloge quand le téléversement a réussi.
2. [Diagnostic UART cible](V02_01_uart_cible/V02_01_uart_cible.ino) : reconnaître la différence entre Uno programmateur et port série de l'ATmega328P autonome.
3. [**Firmware cumulatif M09**](../../../../firmware/etapes/M09/Compteur_M09/Compteur_M09.ino) : reprendre **tous** les acquis M03–M08, activer la cible externe avec `ALEXTECH_ATMEGA_AUTONOME 1` lorsque le banc est prêt, puis programmer avec ISP.

## Compilation sur Arduino Uno

```bash
arduino-cli compile --fqbn arduino:avr:uno formation/modules/M09-atmega328p-isp/code/V01_01_diagnostic_led
arduino-cli compile --fqbn arduino:avr:uno formation/modules/M09-atmega328p-isp/code/V02_01_uart_cible
arduino-cli compile --fqbn arduino:avr:uno firmware/etapes/M09/Compteur_M09
```

**Une compilation réussie n'indique pas la présence d'une horloge réelle ni une programmation ISP réussie.** Les fuses du microcontrôleur cible doivent correspondre au profil 16 MHz configuré dans l'IDE ; le circuit à quartz doit être installé et vérifié avant toute configuration exigeant une horloge externe.

Pour programmer, utiliser d'abord une **Uno programmateur** avec le sketch ArduinoISP chargé, puis brancher la cible à l'aide des six signaux ISP. Ne pas téléverser ces deux sketches diagnostiques comme remplacement permanent du firmware fil rouge : ils sont des exercices ponctuels.

Le modèle choisi est **ATmega328P PDIP28**, pas n'importe quel microcontrôleur à 28 broches. Une Uno à ATmega328P soudé en CMS convient aussi comme **programmateur ISP** ; ne pas supposer que sa puce est amovible.

Le code M09 utilise **Arduino Uno / ATmega328P à 16 MHz** pour rester cohérent avec les broches et la temporisation du firmware précédent. Les configurations 8 MHz interne, MiniCore, fuse CKDIV8 et BOD appartiennent à une autre variante qu'il ne faut pas activer sans tests et documentation propres.

[Brochage DIP28 et ISP](../ressources/BROCHAGE_ISP_PU28.md) · [Procédure Arduino IDE et ISP](../ressources/PROGRAMMATION_ISP.md) · [Fiche de tests](../ressources/PLAN_TESTS.md)
