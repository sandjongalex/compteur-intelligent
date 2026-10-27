# Script formateur — M05-V02 : UART et tâches périodiques avec millis (9 min)

**Format : Arduino IDE 2 + moniteur série USB + LED L intégrée, aucune diapositive.**  
**Cible : 9 minutes de vidéo, à répéter et chronométrer.** Les textes entre « » sont prononcés. Les annotations **[ÉCRAN]** / **[MANIP]** ne sont pas prononcées.

## 00:00–00:55 · Montrer le résultat

[MANIP] Si une Uno réelle est disponible, ouvrir le moniteur série à 9600 bauds avec `V02_03_millis_et_uart.ino` téléversé.

« Regardez le moniteur série. La carte affiche une tension de démonstration environ une fois par seconde. Et pendant que les lignes s'affichent, je peux envoyer le caractère un pour allumer la LED ou zéro pour l'éteindre.

Voilà une idée essentielle pour notre compteur : il doit pouvoir transmettre des informations régulièrement, tout en restant disponible pour les autres tâches. Nous allons apprendre à faire cela avec la communication série et la fonction `millis`.

Aujourd'hui, nous utilisons une tension **entièrement fictive**, deux cent trente virgule cinq volts. Il n'y a aucun branchement au réseau électrique. »

## 00:55–02:05 · Comprendre l'UART

[ÉCRAN] Montrer un schéma simple « TX → RX, RX ← TX », et la liaison USB de la Uno vers le PC.

« UART est une manière d'échanger des données série, c'est-à-dire des bits transmis les uns après les autres. Sur deux appareils compatibles, une sortie TX transmet et une entrée RX reçoit. Lorsqu'on relie deux dispositifs UART, on relie normalement TX de l'un au RX de l'autre, et inversement, avec des références électriques compatibles.

Les deux côtés doivent convenir du débit, exprimé en bauds, et du format de communication. Dans nos exemples, nous utilisons neuf mille six cents bauds, avec une trame courante de huit bits de données, sans parité et avec un bit d'arrêt.

Sur notre Uno Rev3, le port matériel `Serial` est lié à la connexion USB de programmation. Nous utiliserons seulement le moniteur série du PC : n'ajoutez aucun périphérique sur les broches D0 et D1 pendant cette démonstration. Et plus tard, lorsque nous connecterons d'autres modules, nous vérifierons les niveaux électriques avant tout raccordement. »

## 02:05–03:15 · Étape 1 : recevoir un caractère

[ÉCRAN] Ouvrir `V02_01_uart_echo.ino` ; zoom sur `Serial.begin`, `available`, `read`.

« Ouvrons le premier fichier. Dans `setup`, `Serial.begin(9600)` initialise la communication série. Nous réglons le moniteur série sur la même vitesse.

Dans `loop`, nous demandons si `Serial.available()` est supérieur à zéro. Cela signifie : est-ce qu'au moins un caractère est arrivé ? Si oui, `Serial.read()` lit le prochain caractère reçu.

Nous avons prévu d'ignorer les caractères spéciaux de fin de ligne, car certains réglages du moniteur série en ajoutent automatiquement.

[MANIP] Envoyer la lettre A depuis le moniteur ; afficher `Recu : A`.

Important : `Serial.read` lit un caractère à la fois. Une mesure complète envoyée sous forme de texte peut donc arriver en plusieurs caractères. Il faudra les regrouper si nous voulons traiter des messages plus complexes. Pour l'instant, un seul caractère suffit. »

## 03:15–04:30 · Étape 2 : une commande devient une action

[ÉCRAN] Ouvrir `V02_02_commandes_uart.ino` ; montrer les cas `'1'`, `'0'`, `'?'`.

« Maintenant, nous voulons que le texte reçu déclenche une action. Si l'ordinateur envoie le caractère un, la LED intégrée s'allume. S'il envoie zéro, elle s'éteint. Et le point d'interrogation affiche une aide.

Nous allons lire les caractères disponibles avec une boucle `while`. Mais remarquez que notre boucle s'exécute uniquement tant qu'il reste des caractères déjà reçus : nous n'attendons pas indéfiniment qu'un nouveau message arrive.

Nous comparons le caractère à un, zéro ou point d'interrogation. Le programme met la LED à jour et répond par le moniteur série : LED ON ou LED OFF.

[MANIP] Envoyer un, puis zéro, puis point d'interrogation ; montrer la LED et le texte correspondant.

C'est déjà un protocole très simple : nous avons défini des messages et le sens de chacun d'eux. Ce n'est pas encore une connexion avec notre SIM800L ou notre PZEM. »

## 04:30–05:25 · Pourquoi abandonner delay ?

[ÉCRAN] Afficher les deux situations : `delay(1000)` et « vérification de l'heure ».

« Dans les premiers projets, nous utilisions `delay(1000)` pour attendre une seconde. C'est facile à comprendre, mais pendant cette attente le code de notre boucle principale ne peut pas aller exécuter une autre tâche.

Imaginez un compteur qui attend longtemps après chaque mesure. S'il doit répondre rapidement à une commande ou réagir à un bouton, il risque de le faire trop tard.

Nous allons remplacer cette attente par une question répétée très souvent : « Est-ce qu'une seconde s'est écoulée depuis le dernier relevé ? »

Et surtout, si la seconde n'est pas encore passée, le programme **continue à écouter les commandes** au lieu de rester bloqué. »

## 05:25–07:35 · Étape 3 : millis, sans blocage

[ÉCRAN] Ouvrir `V02_03_millis_et_uart.ino`, surligner une section à la fois.

« Dans notre fichier final, nous créons `PERIODE_MS = 1000UL`. Cela veut dire une période de mille millisecondes : environ une seconde. Le suffixe UL indique une constante entière non signée de type long sur l'architecture ciblée.

Nous gardons aussi une variable appelée `dernierEnvoiMs` pour mémoriser le moment du dernier affichage.

Dans `loop`, nous appelons d'abord `traiterCommandes()` : nous continuons donc à lire les caractères un, zéro et point d'interrogation.

Ensuite, nous demandons la valeur actuelle de `millis()`. Nous calculons le temps écoulé en soustrayant `dernierEnvoiMs` à cette valeur. Si au moins mille millisecondes se sont écoulées, nous affichons une nouvelle ligne et mémorisons le nouvel instant.

Le fait d'utiliser un `unsigned long` et de calculer une différence entre les deux instants est également la bonne manière de gérer le retour à zéro de `millis()) sur cette carte.

Regardez la différence : il n'y a **pas de `delay` dans cette boucle**. Nous pouvons donc demander un état de la LED entre deux affichages de notre tension fictive.

[MANIP] Vérifier et téléverser. Ouvrir le moniteur à 9600 bauds. Envoyer `1` entre deux mesures ; vérifier que la LED réagit et que l'affichage périodique continue.

La durée sera approximative, pas un chronométrage industriel garanti : d'autres traitements et les impressions série consomment aussi du temps. Mais pour notre démonstration, c'est exactement le principe attendu. »

## 07:35–08:25 · Diagnostic simple

[ÉCRAN] Montrer les trois erreurs sur une copie de texte : débit différent, mauvaise borne TX/RX future, `delay` ajouté.

« Que faire si le moniteur affiche des caractères illisibles ? Vérifiez que la vitesse du moniteur correspond à `Serial.begin(9600)`.

Si les commandes ne fonctionnent pas, vérifiez que vous envoyez vraiment les caractères un ou zéro, et que le téléversement a réussi. Le programme ignore normalement les fins de ligne.

Et si les mesures s'arrêtent chaque fois que vous ajoutez une pause de plusieurs secondes, relisez votre code : vous avez peut-être réintroduit un `delay` qui bloque la boucle.

Dernier rappel : sur la Uno, les broches D0 et D1 utilisent l'UART matériel. Nous ne les connectons pas à un autre module pendant notre exercice USB. »

## 08:25–09:00 · Défi et transition

« Pour votre mini-défi, modifiez la fréquence d'affichage. Au lieu d'envoyer une mesure toutes les mille millisecondes, faites-le toutes les cinq cents millisecondes, sans utiliser `delay`.

Le corrigé est fourni séparément dans les travaux pratiques. Vérifiez surtout que les commandes pour allumer et éteindre la LED restent disponibles entre deux relevés.

Nous avons maintenant les outils indispensables : les entrées et sorties, la communication série et la gestion du temps sans blocage. Dans le prochain module, nous commencerons à remplacer la valeur fictive par une mesure obtenue du PZEM-004T, dans un cadre électrique sécurisé. »

---

## Contrôles du formateur

- [ ] Montrer un vrai moniteur série / une vraie LED, avec la source de la mesure clairement marquée « SIMULÉE ».
- [ ] Utiliser les sketches `V02_01`, `V02_02`, `V02_03` dans l'ordre ; ne pas saisir d'un seul coup un programme long.
- [ ] Ouvrir le moniteur à **9600 bauds** et vérifier les commandes `1`, `0`, `?`.
- [ ] Ne pas brancher le PZEM ni le SIM800L dans ce module ; aucun circuit 230 V.
- [ ] Chronométrer le montage final sur 9 minutes.
