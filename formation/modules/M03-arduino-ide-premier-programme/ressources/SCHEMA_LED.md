# M03 — Schéma pédagogique de la LED externe

**Basse tension uniquement : Arduino Uno Rev3 alimentée par USB.**

```text
              Broche numérique D8
                      │
                  [330 Ω]
                      │
                Anode LED (+)
                     |>|  (LED)
                Cathode LED (-)
                      │
                   GND Uno
```

**Recommandations :**

- Débrancher l'USB avant de placer les fils, puis vérifier les connexions et rebrancher.
- Utiliser **une résistance de limitation de courant** en série ; 330 Ω est une valeur d'exemple pour une LED standard typique sur Uno 5 V.
- Vérifier l'anode et la cathode : la patte longue est généralement l'anode sur une LED neuve, mais les repères physiques et la fiche composant prévalent.
- Ne pas relier la LED directement à la sortie D8 sans résistance.
- Ne pas connecter le PZEM ni le secteur pendant ce module.

**LED_BUILTIN :** pour la Uno R3, la LED « L » de la carte est pilotée sur D13 ; elle fonctionne avec le sketch `01_blink_interne` et ne nécessite aucun câble externe.
