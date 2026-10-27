# M06 — Corrigés et barèmes formateur

## TP01 — Registres fictifs décodés

Code : [TP01_corrige_registres.ino](../code/TP01_corrige_registres/TP01_corrige_registres.ino).

| Grandeur | Brut et calcul | Résultat |
|---|---|---|
| Tension | 2312 / 10 | **231,2 V** |
| Courant | mots 750 et 0, puis /1000 | **0,750 A** |
| Puissance active | mots 1388 et 0, puis /10 | **138,8 W** |
| Énergie cumulée | mots 15300 Wh et 0, puis /1000 | **15,300 kWh** |
| Fréquence | 501 / 10 | **50,1 Hz** |
| Facteur de puissance | 80 / 100 | **0,80** |

Le registre bas et le registre haut ne représentent pas deux mesures différentes : ils constituent un nombre de 32 bits. Exemple : `(1UL << 16) | 1 = 65537`.

**Barème /10 :** six valeurs et unités (6), assemblage 32 bits (2), sketch modifié correctement (1), sortie série commentée (1).

## TP02 — Échec de lecture

Code de référence : [TP02_corrige_panne.ino](../code/TP02_corrige_panne/TP02_corrige_panne.ino). Le comportement attendu suit **OK → ERREUR → OK**. Lors de l'échec, le logiciel ne publie pas de nouveau relevé, et une variable peut compter les erreurs.

Exemple d'extrait (à intégrer au code de l'apprenant) :

```cpp
unsigned int erreurs = 0;
// ...
if (!lectureValide) {
  ++erreurs;
  Serial.print(F("Nombre d'erreurs : "));
  Serial.println(erreurs);
  return;
}
```

**Barème /10 :** détection d'échec (2), absence de fausse mesure (3), récupération au prochain essai (2), compteur d'échecs (2), explication zéro/absence (1).

## Mini-défi

L'énergie lue par `pzem.energy()` est **cumulative**. Les consommations journalières et mensuelles sont calculées plus tard grâce aux différences d'index et à la RTC ; les remises à zéro quotidiennes feraient perdre un repère.

**Seuil recommandé : 8/10 pour chaque TP.** Toute incompréhension de sécurité doit être corrigée.
