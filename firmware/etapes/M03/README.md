# M03 — Le début du firmware fil rouge

Ce programme **est le point de départ du même compteur intelligent** qui grandit ensuite dans les modules M04 à M16.

**Nouveauté du M03 :** `setup()`, `loop()`, `pinMode()`, `digitalWrite()`, `delay()` et la LED L intégrée. Le clignotement permet de confirmer que le firmware a été téléversé.

[Ouvrir `Compteur_M03.ino`](Compteur_M03/Compteur_M03.ino) · [Lire le cours M03](../../../formation/modules/M03-arduino-ide-premier-programme/README.md).

**Exécution :** Uno Rev3 + câble USB seulement. L'écran, le PZEM, la RTC, le GSM et les calculs d'énergie n'existent pas encore dans ce programme.

**Transition M04 :** on conserve la LED, mais on introduit les fonctions, les constantes, des valeurs simulées et l'affichage série. Le module M05 fera ensuite évoluer le clignotement bloquant en commande de LED réactive.
