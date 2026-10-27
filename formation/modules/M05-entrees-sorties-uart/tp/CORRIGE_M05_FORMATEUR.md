# M05 — Corrigé des TP (document formateur)

**Ne pas diffuser avant la tentative de l'apprenant.** Les valeurs de tension du TP02 sont fictives.

## TP 01 — Corrigé

Fichier Arduino complet : [TP01_corrige_bouton_page.ino](../code/TP01_corrige_bouton_page/TP01_corrige_bouton_page.ino).

**Principe :** une variable `byte page` vaut 0 au départ ; elle est mise à jour **uniquement** lorsque l'anti-rebond confirme la transition stable vers `LOW` :

```cpp
if (stable == LOW) {
  page = (byte)(1 - page); // 0 <-> 1
  digitalWrite(LED_BUILTIN, page ? HIGH : LOW);
  Serial.print("Page : ");
  Serial.println(page);
}
```

### Sortie attendue (simulation du comportement, non preuve de carte réelle)

```text
Page initiale : 0
Page : 1
Page : 0
Page : 1
Page : 0
Page : 1
```

**Barème /10 :** bouton correctement câblé en basse tension (2), anti-rebond et événement unique par appui (3), alternance 0/1 (2), sortie série 9600 cohérente (2), explication du code (1).

**Diagnostic :** si la page change au relâchement, la bascule est probablement placée au mauvais endroit. Si elle change plusieurs fois, comparer lecture brute et état stable. Un rebond très inhabituel pourrait nécessiter un délai d'anti-rebond adapté, mais notre valeur de **35 ms** est un paramètre d'exemple.

## TP 02 — Corrigé

Fichier Arduino complet : [TP02_corrige_500ms.ino](../code/TP02_corrige_500ms/TP02_corrige_500ms.ino).

**Modification centrale :**

```cpp
const unsigned long PERIODE_MS = 500UL;
```

Les commandes sont toujours traitées dans `loop()` ; l'affichage n'est déclenché que si le temps écoulé est au moins égal à la période. Aucune pause bloquante n'est utilisée.

### Sortie attendue (exemple fictif, ordre entre commandes dépend des actions de l'apprenant)

```text
TP02: 1=ON 0=OFF ?=aide
Tension SIMULEE : 230.5 V
Tension SIMULEE : 230.5 V
LED ON
Tension SIMULEE : 230.5 V
LED OFF
Tension SIMULEE : 230.5 V
```

**Barème /10 :** compilation/téléversement et console (2), période de 500 ms (3), commandes 1/0/? sans blocage (3), interprétation de millis et de la différence des temps (2).

**Diagnostic :** si le moniteur affiche des caractères illisibles, revérifier 9600 bauds. Si aucune commande ne passe, vérifier l'envoi des caractères et que D0/D1 ne sont pas occupés par un autre circuit. Ne pas utiliser une boucle qui attend indéfiniment de nouvelles données.

## TP 03 — Réponse

`delay(5000)` empêche l'exécution de la suite de `loop()` pendant environ cinq secondes. Des octets peuvent être reçus en arrière-plan grâce aux interruptions, mais les commandes ne sont pas **traitées** immédiatement, et la mémoire tampon d'entrée peut finir par être saturée.

## Critères d'acceptation

Ne jamais appeler une vidéo, une simulation ou une capture PowerPoint « preuve de tests sur Arduino ». Le formateur validera le clignotement, les appuis et le comportement série sur matériel réel, et relèvera tout écart dans le [plan de tests](../ressources/PLAN_TESTS.md).
