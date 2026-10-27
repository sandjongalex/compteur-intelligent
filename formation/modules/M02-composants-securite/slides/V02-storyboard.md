# Storyboard M02-V02 — Alimentations et sécurité

**7 diapositives, 16:9, 5 minutes cible.**
**PowerPoint local créé, téléchargeable dans la conversation ; non présent en binaire sur GitHub.**

| N° | Temps cible | Visuel | Message pédagogique |
|---|---|---|---|
| 1 | 00:00–00:45 | Trois cartes « 230 V~ », « 5 V », « 4,0 V » | Ne pas confondre les tensions. |
| 2 | 00:45–01:30 | Comparaison AC secteur / DC régulé | Le secteur est dangereux et n'est pas une alimentation logique. |
| 3 | 01:30–01:58 | Architecture AC/DC isolé → 5 V → 4 V | Diagramme de principe, pas câblage secteur. |
| 4 | 01:58–02:25 | SIM800L nu : 4,0 V ; pointe proche de 2 A | Interdire 5 V direct sur VBAT. |
| 5 | 02:25–03:25 | Trois cartes condensateurs / isolation / protections | Découplage et sécurité complémentaires. |
| 6 | 03:25–04:20 | Zone basse tension / zone secteur | Ce qu'un débutant peut tester. |
| 7 | 04:20–05:00 | Trois erreurs à diagnostiquer | Consolider la sécurité. |

## Sources de vérification technique

- Fiche SIMCom SIM800L : tension VBAT **3,4–4,4 V**, **4,0 V recommandée**, pointe jusqu'à **2 A** : https://www.electrokit.com/upload/product/41018/41018214/SIM800L-SIMCom.pdf
- Fiche officielle Arduino Uno Rev3 : **ATmega328P**, **5 V**, **16 MHz** : https://store.arduino.cc/products/arduino-uno-rev3

**Note importante :** ces caractéristiques concernent le **modem SIM800L nu** et l'**Arduino Uno Rev3**. Les petites cartes tierces peuvent intégrer une alimentation supplémentaire et posséder des brochages différents ; vérifier la documentation du produit exact.

## Vérifications

- [x] 7 diapositives PowerPoint modifiables créées.
- [x] Notes du formateur ajoutées aux diapositives.
- [x] Test automatisé des débordements de textes : réussi.
- [ ] Répétition chronométrée (5 min cible).
- [ ] Illustrations réelles / vidéo à filmer sans secteur.
- [ ] Enregistrement et publication (assurés par le formateur).

[Script oral complet](../scripts/V02-script.md) · [Checklist sécurité](../ressources/CHECKLIST_SECURITE.md)
