# Firmware M09 — même compteur sur ATmega328P autonome

Ce fichier **est obtenu depuis M08**, pas réécrit de zéro. Toutes les fonctions M05–M08 subsistent : bouton D2, LED D13, UART `1/0/?`, mesures, DS3231/LCD optionnels, calcul jour/mois, période partielle et refus des lectures invalides.

## Changement de M09

- `ALEXTECH_ATMEGA_AUTONOME 0` (défaut) : Uno Rev3 USB et simulations des données, comme en M08.
- `ALEXTECH_ATMEGA_AUTONOME 1` : destiné à un **ATmega328P PDIP28**, utilisé avec **profil de compilation Uno / 16 MHz** et **quartz externe 16 MHz effectivement présent** sur les broches 9–10, si les fuses de la puce correspondent à cette configuration.
- Nouveau `afficherBrochageCible()` : diagnostic série indiquant horloge et broches. L'option 1 ne configure PAS automatiquement les fuses, l'alimentation, le quartz ou les broches ; ces opérations sont matérielles et réalisées séparément.
- Le code est transmis par **ArduinoISP → Upload Using Programmer**, à la place de la voie USB/bootloader de la carte Uno. Sur puce autonome, la communication `Serial` nécessite un **adaptateur USB–TTL compatible 5 V**, câblé sur PD0/PD1, pas la liaison du programmateur ISP.
- `LED_BUILTIN` sur DIP28 = **PB5, broche 19** : pas de LED intégrée à une puce nue ; ajouter LED **avec résistance série** ou le firmware s'exécute sans voyant physique.
- D2 = PD2, broche 4, bouton vers GND en `INPUT_PULLUP`.

## Continuité prouvable

Le snapshot M09 `Compteur_M09.ino` et `EnergieM08.h` sont identiques au dossier `firmware/courant/CompteurIntelligent/` (le .ino porte seulement un nom de fichier différent). Les tests automatiques contrôlent cette égalité. Le moteur `EnergieM08.h` n'a pas été modifié.

**Précaution :** l'Arduino Uno *programmateur* ne doit pas être confondue avec la puce *cible*. Sur une cible alimentée par l'Uno (faible charge), ne pas ajouter une seconde source d'alimentation 5 V en parallèle. Les composants basse tension doivent être câblés après vérification des références exactes.

**Une compilation réussie ne prouve pas que le microcontrôleur externe a été programmé.** Seul un vrai essai ISP, sur cible adéquatement préparée, peut le confirmer.

[Plan de câblage ISP M09](../../../formation/modules/M09-atmega328p-isp/ressources/BROCHAGE_ISP_PU28.md) · [Tests de production M09](../../../formation/modules/M09-atmega328p-isp/ressources/PLAN_TESTS.md)


### Vérifier la configuration autonome

L'option peut être activée dans le sketch (0 vers 1) ou en compilation par `-DALEXTECH_ATMEGA_AUTONOME=1`, le mode simulé restant le défaut. La CI contrôle les deux compilations, pas le fonctionnement matériel ni les fuses de la cible.

## Erratum correctif P1/P2 — maintenance M09

La version M09 n'avait pas été validée physiquement : ce correctif contrôlé
synchronise M09 et le dossier courant, sans toucher aux snapshots M03–M08.
Toute formation filmée sur l'ancienne version doit signaler cette correction.

- **P1 simulation :** les Wh simulés suivent 92,2 W (1 Wh toutes ~39,05 s),
  au lieu d'un index accéléré de 1 Wh / 200 ms non indiqué.
- **P1 horodatage :** provenance `DATE_SIMULEE` / `DATE_DS3231` / `DATE_INDISPONIBLE` ;
  compiler un PZEM réel sans DS3231 réel devient une erreur.
- **P2 période :** le relevé suivant minuit sans observation à 00:00:00 reste
  partiel ; aucun partage artificiel de l'énergie à cheval sur deux jours.
  Refus d'une saturation silencieuse des sommes `uint32_t`.
- **P2 UART :** le PZEM reste sur `SoftwareSerial` D10/D11, `Serial` reste
  la console M09 *uniquement* ; le firmware M10 migrera D0/D1 au SIM800L.
- **P2 tests :** les compilations avec les bibliothèques réelles sont requises
  en complément des tests de simulation, mais ne prouvent pas le matériel.

Les périodes restent en RAM jusqu'à M11 FRAM. Le présent correctif ne contient
ni pilotage GSM ni validation électrique réelle.
