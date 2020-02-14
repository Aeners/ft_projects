# RED TETRIS
Tetris Réseau à la Sauce de Pélicans Rouges
## BOILERPLATE
[GitHub - redpelicans/red_tetris_boilerplate](https://github.com/redpelicans/red_tetris_boilerplate)

## Languages
Node.js
React.js
Redux.js

## Conditions
Should be written in ES6

### Client
No call to 'this' => Can help lodash or ramda
Pure functions
"This" peut etre utilisé pour définir ses propres sous classes d'ERROR
React & Redux obligatoire
Code HTML ne doit pas utilisé <Table/> mais FLEXBOX (obligatoire)
Interdiction de :
. Utilisation de librairie de manipulation de DOM comme JQUERY
. Des Canvas
. SVG
Le client s’exécute au sein d’un navigateur dans une architecture de type Single Page Application :
• A la première requête, le navigateur récupère du serveur un fichier index.html qui fait référence via une balise "script" à un fichier Javascript (bundle.js) qui contient l’ensemble du code de l’application cliente.
• Le navigateur exécute bundle.js et dès lors il n’y a plus d’échanges de fichiers HTML entre serveur et client, ce dernier est totalement autonome pour le rendu graphique et pour la gestion de la logique applicative. Seules des données seront échangées avec le serveur, échanges bi-directionnels dans notre cas via socket.io.

### Server
Programmation orientée objet (prototype)
3 Classes minimum: : Player, Piece et Game

Client et serveur communique via Socket.io

Dans le jeu, le serveur est en charge de la gestion des parties, de la distribution des pièces et de la diffusion les spectres des terrains des joueurs. Nous vous in- vitons à identifier dès le début très précisément le partage de responsabilités entre clients et serveur afin de spécifier le protocole réseau du jeu.

Techniquement, le serveur est une [boucle asynchrone] (https://nodejs.org/en/about/) en charge du traitement des évé- nements émis par les clients. Socket.io permet de recevoir et d’emettre les événements vers un ou plusieurs joueurs simultanément pour une même partie.

Il offre un service HTTP (en plus de socket.io) dont la seule finalité est de fournir, au lancement de la connexion du client, les fichiers index.html et bundle.js, voire quelques ressources supplémentaires.

### Test Unitaire
Cover 70% des statements, functions, lines and 50% of branches

test
src
src/client
  /actions
  /components
  /containers
  /middlewares
  /reducers
src/server

## THE GAME

Dès lors qu’un joueur détruit des lignes sur son terrain, les joueurs adverses recoivent en malus n - 1 lignes, alors indestructibles, qui s’insèrent en bas de leur terrain.

Un terrain est formé de 10 colonnes et 20 lignes

Chaque joueur peut observer graphiquement la liste de ses adversaires (nom) et le spectre de leur terrain

Sauf en cas de chute, une piéce ne s’intègre au tas (cesse d’être mobile) non pas au contact de ce dernier mais au pas suivant, cela permet d’ajuster sa position en contact du tas.

#### Controlers
Flèches gauche et droite : Déplacement horizontal à droite ou gauche
Flèche du haut : Rotation (un seul sens est suffisant)
Flèche du bas : Chute en direction du tas
Barre d’espace : Déplacement vertical afin de positionner une piéce dans un trou du tas

Il n’y a pas de score, le dernier joueur d’une partie est le gagnant. Le jeu doit être multi parties, mais doit aussi permettre de jouer en solitaire. 
http://<server_name_or_ip>:<port>/#<room>[<player_name>]

Aucun système de persistance n’est nécessaire.
Le client implémente une architecture de type Single Page Application.

Le premier à rejoindre une partie, en sera le responsable, il en aura le contrôle, il pourra la lancer à sa guise.
A la fin, il sera le seul à pourvoir la relancer. En cas de départ, un des joueurs restant prendra ce rôle.

Un joueur ne peut rejoindre une partie en cours de jeu. Il doit attendre sa fin, il pourra dès lors la rejoindre et y participer quand le responsable décidera de la lancer.

Une partie est terminée lorsqu’il ne reste plus qu’un seul jouer, c’est alors le gagnant. Une partie peut se jouer avec un seul joueur.
Plusieurs parties peuvent être organisées simultanément.