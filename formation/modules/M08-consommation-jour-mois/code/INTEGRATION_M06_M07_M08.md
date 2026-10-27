# Relier les Modules M06, M07 et M08

## Vue d'ensemble

- **M06** fournit un index énergétique cumulatif du PZEM V3 (bibliothèque `energy()` en kWh).
- **M07** fournit la date/heure du DS3231, après vérification `begin()`, `lostPower()` et `now().isValid()`.
- **M08** traite uniquement un couple **{date locale fiable, index Wh valide}** et expose les cumuls jour/mois accompagnés du statut **complet / partiel**.
- **M11** ajoutera la persistance réelle FRAM avec reprise sûre, validation CRC et sauvegarde des compteurs.

## Démonstration réalisable sans secteur

Le sketch [V02-03 DS3231 + LCD fictif](V02_03_ds3231_lcd_fictif/V02_03_ds3231_lcd_fictif.ino) utilise une **RTC réelle** et un **index PZEM entièrement inventé** qui progresse de 10 Wh toutes les 5 secondes. Il montre les quatre lignes LCD `DATE`, `TENSION`, `JOUR` et `MOIS` ; les trois valeurs électriques ne sont pas des mesures.

Un caractère **`~`** à la fin du cumul signifie **période incomplète** (par exemple appareil démarré après minuit, passage de date sans lecture exactement à la frontière). Ne pas afficher « zéro consommé depuis minuit » si le suivi commence à midi.

## Adaptation future au vrai PZEM, réservée aux essais qualifiés

Pseudocode pédagogique, **ne décrit aucun câblage secteur** :

```cpp
if (!rtc.begin() || rtc.lostPower()) { /* date invalide : stopper */ }
DateTime t = rtc.now();
float kWh = pzem.energy();
if (!t.isValid() || !isfinite(kWh) || kWh < 0.0f) {
  /* lecture invalide : ne pas inventer zero */
} else {
  // IMPORTANT : la conversion suivante n'est convenable que
  // si la precision du float est suffisante dans la plage du projet.
  uint32_t Wh = (uint32_t)(kWh * 1000.0f + 0.5f);
  ReleveM08 r={{t.year(),t.month(),t.day(),
    t.hour(),t.minute(),t.second()},Wh,true};
  suivi.ajouter(r);
}
```

**Précision :** sur AVR/ATmega328P `float` ne dispose que d'environ **6–7 chiffres significatifs**. Sur un grand index cumulatif, convertir `energy()` de kWh en Wh peut provoquer des erreurs de quelques Wh ou plus. Pour une application exigeante, privilégier la lecture **des registres bruts 32 bits en Wh** et une stratégie anti-débordement, plutôt que promettre une précision au Wh à partir d'un `float`. Vérifier aussi la capacité `uint32_t` et l'événement de réinitialisation du module.

**Sécurité :** ne pas relier le PZEM au secteur pour les exercices débutants. Toute démonstration réelle exige un banc et une personne qualifiés.
