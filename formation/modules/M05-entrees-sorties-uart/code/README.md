# Code du Module 05 — Arduino Uno Rev3

**Statut : programmes source pédagogiques préparés ; leur compilation réelle et leur téléversement restent à vérifier sur une Arduino Uno Rev3.** Aucun sketch de ce module n'est une lecture de capteur réel : toute tension affichée est **fictive**.

## Construction progressive — vidéo 1

1. [V01-01 · Bouton maintenu](V01_01_bouton_niveau/V01_01_bouton_niveau.ino) : D2-GND, `INPUT_PULLUP`, LED L allumée tant que l'on appuie.
2. [V01-02 · Détection d'un appui sans anti-rebond](V01_02_bascule_sans_antirebond/V01_02_bascule_sans_antirebond.ino) : bascule sur front mais **exemple volontairement imparfait** (rebonds).
3. [V01-03 · Bascule avec anti-rebond](V01_03_bascule_antirebond/V01_03_bascule_antirebond.ino) : un seul changement par pression validée après 35 ms.

## Construction progressive — vidéo 2

1. [V02-01 · Écho UART](V02_01_uart_echo/V02_01_uart_echo.ino) : lire un caractère avec `Serial.available()` / `Serial.read()`.
2. [V02-02 · Commandes de LED](V02_02_commandes_uart/V02_02_commandes_uart.ino) : `1` allume, `0` éteint, `?` aide.
3. [V02-03 · Relevé périodique](V02_03_millis_et_uart/V02_03_millis_et_uart.ino) : afficher **230,5 V SIMULÉS** toutes les ~1 000 ms tout en restant réactif aux commandes.

## Corrigés des TP — séparés des fichiers de départ

- [TP01 · Simuler deux pages](TP01_corrige_bouton_page/TP01_corrige_bouton_page.ino).
- [TP02 · Mesure toutes les ~500 ms](TP02_corrige_500ms/TP02_corrige_500ms.ino).

## Conditions et test du matériel

- **Carte** : Arduino Uno R3 / ATmega328P ; **IDE** : Arduino IDE 2 ; aucune bibliothèque externe.
- **Bouton** : relier un contact du bouton poussoir entre **D2 et GND**. Si le bouton a quatre pattes, vérifier les contacts qui sont effectivement mis en contact lors de l'appui, sans se fier à une photographie générique.
- **LED** : utiliser celle intégrée à la carte Uno (D13 via `LED_BUILTIN`) ; aucun composant externe n'est requis pour la sortie.
- **Série** : utiliser le moniteur série du PC par USB à **9600 bauds** ; commande **un caractère** à la fois, puis envoyer. Le code ignore CR/LF.
- **D0/RX et D1/TX** : ne pas y brancher de modem ou d'autres fils lors de l'utilisation USB et du téléversement sur Uno.
- **Sécurité** : débrancher l'USB avant de modifier les fils. Aucun PZEM, SIM800L, ni secteur 230 V dans le module.

### À quoi s'attendre

| Fichier | Résultat attendu |
|---|---|
| V01-01 | LED allumée durant l'appui, éteinte au relâchement |
| V01-02 | LED change d'état à chaque front détecté mais peut basculer plusieurs fois à cause des rebonds |
| V01-03 | Un changement à chaque appui validé |
| V02-01 | Une ligne `Recu : x` après l'envoi du caractère x |
| V02-02 | `LED ON`, `LED OFF` ou aide |
| V02-03 | Mesure fictive environ une fois/seconde ; commandes 1/0/? sans `delay()` |

**Sources** : [Arduino built-in examples](https://docs.arduino.cc/built-in-examples/) ; [Serial.read](https://docs.arduino.cc/language-reference/en/functions/communication/serial/read/) ; [delay](https://docs.arduino.cc/language-reference/en/functions/time/delay/).

**Ne pas cocher « compilé » ou « testé sur carte » avant de disposer d'un résultat réel.**
