# M03-V02 — Storyboard : Première LED clignotante

**Cible : 7 minutes, 8 diapositives 16:9 + plans macro du montage.** **PowerPoint natif modifiable créé et contrôlé au rendu ; PPTX téléchargeable dans la conversation et pas encore ajouté sur GitHub.**

| Diapo | Temps | Affichage minimal | Action vidéo |
|---|---|---|---|
| 1 | 00:00–00:45 | « Une LED qui clignote : notre premier programme » | Montrer LED intégrée |
| 2 | 00:45–01:15 | « LED = anode + cathode » | Zoom sur LED et repères |
| 3 | 01:15–01:40 | « Résistance = limitation du courant » | Montrer une résistance 330 Ω |
| 4 | 01:40–02:45 | « setup, loop, HIGH, LOW, delay » | Code LED_BUILTIN et états |
| 5 | 02:45–03:35 | « 250 ms ON · 750 ms OFF » | Démo cadence modifiée |
| 6 | 03:35–04:40 | « D8 → R 330 Ω → LED → GND » | Schéma basse tension et montage USB débranché |
| 7 | 04:40–05:45 | « LED_PIN = 8 » | Code externe, vérifier puis téléverser |
| 8 | 05:45–07:00 | « Exercice : changez le rythme » | Question puis correction différée |

## Schéma pédagogique

```text
Arduino Uno R3 (USB basse tension)
D8 --- [résistance 330 ohms] --- anode LED |>| cathode --- GND
```

Vérifier toujours le sens anode/cathode sur la LED réelle ; `330 Ω` est un exemple de limitation approprié pour une LED standard typique sur Uno 5 V, pas une valeur universelle.

## Captures et démonstrations

- Plans de la LED interne « L », de la LED externe et des repères D8/GND.
- Code `01_blink_interne.ino`, `02_blink_externe.ino`, `03_exercice_correction.ino`.
- Montrer une **vraie** LED qui clignote après vérification et téléversement.
- Aucune prise ou câble secteur dans le montage.

## Contrôle

- [ ] Essai réel sur une Uno R3 + LED + résistance.
- [ ] Rien de connecté pendant que le câble USB est branché.
- [ ] Script répété et durée tenue sur 7 minutes.
- [ ] Ne pas filmer de manipulations dangereuses.
