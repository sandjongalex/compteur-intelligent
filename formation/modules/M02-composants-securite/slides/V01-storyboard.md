# Storyboard M02-V01 — Reconnaître les composants

**7 diapositives, 16:9, 5 minutes cible.**
**PowerPoint local créé, téléchargeable dans la conversation ; non présent en binaire sur GitHub.**

| N° | Temps cible | Visuel | Message pédagogique |
|---|---|---|---|
| 1 | 00:00–00:40 | Circuit intégré ATmega328P stylisé | Chaque composant a une mission. |
| 2 | 00:40–01:10 | Trois blocs PZEM → ATmega → SIM800L, DS3231/FRAM/LCD en soutien | Séparer mesure, traitement et communication. |
| 3 | 01:10–01:55 | PZEM et ATmega côte à côte | Capteur de mesures ≠ programme de traitement. |
| 4 | 01:55–02:35 | Trois cartes DS3231 / FRAM / LCD | Heure, mémoire, affichage : rôles différents. |
| 5 | 02:35–03:20 | ATmega → SIM800L → Flask → SQLite | Comprendre la transmission 2G et le stockage serveur. |
| 6 | 03:20–04:20 | Six cartes LED, buzzer, bouton, quartz, résistance, condensateur | Montrer chaque petit composant hors tension. |
| 7 | 04:20–05:00 | Association A–D à 1–4 | Tester la reconnaissance des fonctions. |

## Photos/prises de vues pour le formateur

Présenter hors tension l'ATmega328P DIP-28, la carte Arduino Uno R3, la version exacte du PZEM-004T, le DS3231, le LCD 20×4, la FRAM et le SIM800L. Ajouter LED, bouton, buzzer, résistance, condensateur, quartz. Montrer l'étiquette ou le marquage exact ; signaler les variantes.

## Vérifications

- [x] 7 diapositives PowerPoint modifiables créées.
- [x] Notes du formateur ajoutées aux diapositives.
- [x] Test automatisé des débordements de textes : réussi.
- [ ] Captures vidéo réelles des composants à filmer.
- [ ] Répétition et minutage de 5 minutes.
- [ ] Enregistrement et publication (assurés par le formateur).

[Script oral complet](../scripts/V01-script.md) · [TP du module](../tp/README.md)
