# M05 — Plan de test avant enregistrement (Arduino Uno Rev3)

**État initial : AUCUN test matériel ou compilation Arduino réelle attesté par cette documentation.** Remplir les résultats **après** les avoir effectués dans Arduino IDE 2.

## Mise en place

- IDE : Arduino IDE 2 ; carte : **Arduino Uno Rev3**, ATmega328P.
- Câble : USB de données ; bouton : D2 vers GND ; LED : intégrée.
- Moniteur : 9600 bauds ; aucun périphérique sur D0/D1.
- Couper USB avant de déplacer les fils ; aucune opération 230 V.

## Série de contrôles reproductibles

| Test | Programme | Action à effectuer | Résultat attendu | Réalisé ? |
|---|---|---|---|---|
| T01 | V01-01 | Appuyer et relâcher | LED L suit le maintien du bouton | [ ] |
| T02 | V01-02 | Appuis mécaniques distincts | LED bascule sur fronts détectés ; les rebonds **peuvent** produire plusieurs bascules (pas garanti à chaque essai) | [ ] |
| T03 | V01-03 | 5 appuis distincts | Un changement de LED par appui validé, 5 au total | [ ] |
| T04 | V01-03 | Maintenir le bouton 3 s puis relâcher | Un changement à l'appui ; aucun changement au relâchement seul | [ ] |
| T05 | V02-01 | Envoyer `A` | `Recu : A` | [ ] |
| T06 | V02-02 | Envoyer `1`, puis `0`, puis `?` | LED ON, LED OFF, aide ; pas de message parasite sur CR/LF | [ ] |
| T07 | V02-03 | Attendre quelques secondes | `Tension SIMULEE : 230.5 V` environ toutes les 1 s | [ ] |
| T08 | V02-03 | Envoyer `1` entre deux lignes | Réponse LED ON sans attendre la prochaine ligne fictive | [ ] |
| T09 | TP01 | Cinq appuis | Pages 1,0,1,0,1 après état initial 0 | [ ] |
| T10 | TP02 | Attendre quelques secondes et envoyer `0` | Lignes fictives environ toutes les 500 ms, LED OFF | [ ] |

## Validation de compilation indépendante

Si Arduino CLI est installé localement et que le cœur AVR est disponible :

```bash
arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:uno code/V01_03_bascule_antirebond
arduino-cli compile --fqbn arduino:avr:uno code/V02_03_millis_et_uart
```

Les autres sketches sont également à compiler. Ne pas confondre **compilation** (syntaxe) et **validation sur circuit réel**.

## Rapport d'essai à compléter

- Date :
- Version IDE :
- Type/référence exacte de la Uno :
- Port série :
- Photos ou journal des essais :
- Écarts observés :
- Corrections et nouvelle vérification :
- Décision finale : prêt à filmer / à corriger.

**Critère formateur :** un programme doit produire un résultat réel, reproductible et expliqué, pas simplement une compilation sans erreur.
