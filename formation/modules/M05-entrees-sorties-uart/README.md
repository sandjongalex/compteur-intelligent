# M05 — Entrées, sorties et communications série

**AlexTech Academy · 18 minutes vidéo (2 × 9 min) · Prérequis M03–M04 · Arduino Uno Rev3 et IDE 2.**

**État : kit pédagogique rédigé et organisé, prêt pour les vérifications pré-tournage.** Les essais Arduino réels, l'enregistrement et la publication ne sont pas déclarés terminés.

## Notre méthode : on montre, on code, on teste, on améliore

Pas de PowerPoint dans ce module. Chaque vidéo démarre par un **résultat visible**, puis repart d'un premier programme très court. L'apprenant explique le comportement de chaque étape avant de passer à la suivante, découvre une erreur courante et réalise son propre défi.

| Vidéo | Durée cible | Script | Étapes Arduino |
|---|---:|---|---|
| [M05-V01 — Bouton, LED, anti-rebond](videos/V01-plan.md) | 9 min | [Script complet](scripts/V01-script.md) | [V01-01](code/V01_01_bouton_niveau/V01_01_bouton_niveau.ino) → [V01-02](code/V01_02_bascule_sans_antirebond/V01_02_bascule_sans_antirebond.ino) → [V01-03](code/V01_03_bascule_antirebond/V01_03_bascule_antirebond.ino) |
| [M05-V02 — UART et millis](videos/V02-plan.md) | 9 min | [Script complet](scripts/V02-script.md) | [V02-01](code/V02_01_uart_echo/V02_01_uart_echo.ino) → [V02-02](code/V02_02_commandes_uart/V02_02_commandes_uart.ino) → [V02-03](code/V02_03_millis_et_uart/V02_03_millis_et_uart.ino) |

## Ce que l'apprenant saura faire

1. Lire un bouton **D2–GND** avec `INPUT_PULLUP` et expliquer pourquoi **LOW = appuyé**.
2. Commander la LED intégrée et comprendre la différence entre **état maintenu** et **événement d'appui**.
3. Réduire les rebonds mécaniques grâce à `millis()` et à une fenêtre de **35 ms**.
4. Échanger un caractère par **UART via USB**, à **9600 bauds**, avec `Serial.available()` et `Serial.read()`.
5. Recevoir les commandes `1`, `0`, `?` et afficher une **tension fictive** toutes les secondes sans `delay()`.
6. Modifier le programme, prévoir le nouveau résultat et expliquer une erreur.

## Documents apprenant

- [Guide des 8 programmes Arduino, versions de départ, étapes finales et corrigés](code/README.md)
- [Schéma bouton et conseils UART en basse tension](ressources/CABLAGE_BASSE_TENSION.md)
- [Mémo des nouvelles fonctions](ressources/MEMO_M05.md)
- [Exercices TP01 et TP02 (sans réponses)](tp/TP_M05_APPRENANT.md)
- [Quiz de 10 QCM sans réponses](quiz/QUIZ_M05_APPRENANT.md)
- [Guide de dépannage](ressources/DEPANNAGE.md)

## Documents réservés au formateur

- [Corrigés des TP, exemples de sorties et barèmes](tp/CORRIGE_M05_FORMATEUR.md)
- [Corrigé détaillé du quiz](quiz/CORRIGE_M05_FORMATEUR.md)
- [QCM JSON pour une intégration ultérieure](quiz/quiz_m05.json)
- [Plan des tests physiques à exécuter](ressources/PLAN_TESTS.md)
- [Suivi de production et checklist](production/README.md)

**Évaluation :** 8/10 au quiz, avec correction des erreurs critiques ; réalisation des TP **en dehors des 18 minutes de vidéo**.

## Sécurité et limitations

Les seules connexions matérielles de ce module sont un **bouton D2–GND**, la LED intégrée et le PC par USB. Ne connecter **ni PZEM, ni SIM800L, ni secteur 230 V**. Les valeurs 230,5 V affichées par les sketches sont **SIMULÉES**.

[Plan général de formation](../../../docs/formation/PLAN_FORMATION_4H.md) · [Guide pédagogique](../../GUIDE_PEDAGOGIQUE.md)
