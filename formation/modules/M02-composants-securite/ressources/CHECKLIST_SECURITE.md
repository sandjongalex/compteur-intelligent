# M02 — Checklist de sécurité et d'alimentation

**Public : débutants absolus.** Ce document est une **checklist pédagogique de prévention**, non un dossier d'habilitation électrique ou un schéma secteur certifié.

## Avant une manipulation basse tension

- [ ] Les composants sont identifiés, la référence et la polarité sont vérifiées.
- [ ] L'alimentation utilisée est sûre, adaptée au montage pédagogique et fonctionne à la tension prévue.
- [ ] Aucun conducteur ou connecteur de secteur n'est exposé sur la table d'essai.
- [ ] Les connexions et les masses sont vérifiées hors tension.
- [ ] Les sorties Arduino et les composants ont une limitation de courant appropriée.
- [ ] Les niveaux des interfaces logiques sont compatibles (notamment vers le modem GSM).
- [ ] Aucun court-circuit apparent ou fil abîmé.
- [ ] L'adulte/formateur contrôle le montage avant mise sous tension si nécessaire.

## SIM800L nu : précautions particulières

- [ ] Alimentation régulée **autour de 4,0 V**, conformément à la fiche technique du composant nu.
- [ ] Source capable de fournir les **pointes de courant proches de 2 A**.
- [ ] Condensateurs appropriés proches de l'alimentation, selon les documents constructeur.
- [ ] Pas de connexion **5 V directe sur VBAT** du modem nu.
- [ ] Contrôle des **niveaux UART** avant toute connexion au microcontrôleur 5 V.
- [ ] Vérification de la compatibilité de la version exacte de la carte commerciale (régulateur intégré ou non).

## Partie secteur / PZEM : réservée à une personne qualifiée

- [ ] Alimentation AC/DC correctement isolée et conforme à l'application.
- [ ] Protections, câbles, connecteurs, boîtier et distances d'isolement étudiés.
- [ ] Accès aux parties dangereuses empêché par l'enveloppe.
- [ ] Essais réalisés avec des équipements et procédures de test adaptés.
- [ ] Documentation de la version exacte du module de mesure et de ses limites.
- [ ] Aucune manipulation du secteur demandée aux débutants.
- [ ] Aucun essai 230 V sur breadboard.

**Stop immédiat :** présence de fils secteur accessibles, fumée, odeur anormale, échauffement, protection qui déclenche ou montage dont la sécurité n'est pas connue. Ne pas rechercher une panne sur un circuit secteur sous tension sans qualification.

## Pour le formateur

Expliquer que le cours présente un **compteur de suivi énergétique** ; il n'est pas destiné à remplacer un compteur de facturation réglementé ni à prouver une conformité électrique officielle.

### Références à vérifier

- https://www.electrokit.com/upload/product/41018/41018214/SIM800L-SIMCom.pdf
- https://store.arduino.cc/products/arduino-uno-rev3
- https://www.microchip.com/en-us/product/ATMEGA328P
