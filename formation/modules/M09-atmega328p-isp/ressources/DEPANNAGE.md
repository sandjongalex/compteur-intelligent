# M09 — Fiche de dépannage ISP / ATmega328P autonome

| Problème | Causes à rechercher dans cet ordre | Action sûre |
|---|---|---|
| Sketch compilé, mais ISP impossible | Mauvais port de la Uno, firmware ArduinoISP absent, mauvais « Arduino as ISP », RESET/MOSI/MISO/SCK inversés | Vérifier menu, câble et connexions **hors tension** |
| Signature `0x000000` ou `0xffffff` | Cible non alimentée, mauvaise masse, lignes SPI/RESET ou horloge absente | Référence exacte, VCC/AVCC, GND, quartz/fuses, ISP |
| Puce nue « fonctionne » sans LED visible | LED de la carte Uno absente de la puce nue | Ajouter LED externe avec résistance sur PB5/pin19 |
| Horloge paraît deux fois trop lente/rapide | Discordance réelle entre F_CPU, fuses et source d'horloge | Vérifier le quartz et le profil avant de toucher aux fuses |
| Upload normal échoue vers la puce nue | Pas de passerelle USB ni de bootloader approprié | **Sketch → Upload Using Programmer** via ArduinoISP |
| Messages UART non visibles dans le moniteur de l'Uno programmateur | La liaison USB appartient au programmateur, pas à la cible | Adaptateur **USB–TTL 5V compatible** sur PD0/PD1 cible |
| Cible ne répond plus après gravure des fuses | Source d'horloge désormais externe, absente ou mauvaise | Vérifier un oscillateur conforme et procédure de récupération adaptée ; ne pas changer d'autres fuses au hasard |
| PZEM ou module SPI perturbe la programmation | Périphérique partagé sur broches ISP, notamment D11/MOSI | Débrancher périphérique basse tension hors alimentation ou revoir brochage |
| Redémarrages aléatoires | RESET flottant, alimentation bruitée, découplage absent | Résistance 10 kΩ, condensateurs 100 nF proches des alimentations, GND fiable |
| Projet M09 semble perdre ses kWh après véritable coupure | Stockage FRAM pas encore implémenté au M09 | C'est une limitation connue depuis M08, pas un défaut nouveau ; M11 |

**Ne pas interpréter une compilation réussie comme un succès de programmation ISP.** Ne pas brancher le secteur pour résoudre un problème d'ISP.
