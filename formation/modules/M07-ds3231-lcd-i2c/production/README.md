# M07 — Checklist de production sans PowerPoint

**14 minutes vidéo : M07-V01 = 7 min, M07-V02 = 7 min.** Le formateur effectue l'enregistrement et la publication.

## Livrables préparés

- [x] Deux plans vidéo réécrits pour la pédagogie de programmation progressive.
- [x] Deux scripts du formateur découpés en séquences minutées.
- [x] Six étapes de code Arduino, dans l'ordre des démonstrations.
- [x] Deux sketches corrigés des TP.
- [x] Guide I2C basse tension, RTC, sauvegarde/pile, LCD et mnémo.
- [x] Deux TP séparant énoncés apprenant et corrigés formateur.
- [x] Quiz de dix QCM argumentés (4 faciles, 4 intermédiaires, 2 difficiles) et JSON.
- [x] Dépannage et plan de tests T01–T10.

## Contrôles encore nécessaires

- [ ] Installer Arduino IDE 2, RTClib et hd44780 (avec dépendances) et compiler les huit sketches sur **Uno Rev3**.
- [ ] Vérifier scanner RTC `0x68`, éventuelle EEPROM `0x57`, LCD à l'adresse réelle.
- [ ] Vérifier les **cartes exactes**, leur alimentation et la pile de sauvegarde avant toute mise sous tension.
- [ ] Vérifier le réglage ponctuel et surtout le comportement après redémarrage sans `rtc.adjust()` intempestif.
- [ ] Tester les quatre lignes sur un vrai LCD 20×4 et vérifier la lisibilité.
- [ ] Vérifier le bouton de changement de page D2–GND sur le sketch TP02.
- [ ] Documenter les essais dans le [plan de tests](../ressources/PLAN_TESTS.md).
- [ ] Chronométrer la lecture et les gestes, puis adapter le montage à **7 min par vidéo**.

## À réaliser par le formateur

- [ ] Filmer matériel, Arduino IDE, moniteur série et vrai LCD.
- [ ] Enregistrer la narration des deux leçons.
- [ ] Monter, sous-titrer et publier les contenus sur la plateforme.
- [ ] Distribuer les fichiers apprenant sans révéler prématurément les corrigés.

**Statut : conception prête, matériel et compilation non encore vérifiés.** Aucun PowerPoint n'a été produit.
