# Bilan des présentations

Le but de ce document est de synthétiser chaque mise au point au cours du projet.

## Etat du projet n°1

### Problèmes mis en avant

Il __manque un moteur__ pour la pince : l'année dernière, ils avaient utilisé un _XL320_, quid de cette année ? => A demander aux MSC.

__Problème avec le XL320__ : Penser à prendre un autre moteur car le protocole de communication (quand bien même c'est du UART) est différent que celui du AX12 (bien plus vieux). Il faudrait réfléchir à un nouveau moteur => Nous allons donc prendre les __XL430 w250__.

Sur le diagramme d'architecture, il manquait des informations supplémentaires sur les flèches d'alimentation (__tension, courant, conso__).
Attention au 5.1V pour la tension d'alimentation de la Raspberry

Il faut aussi faire un __bilan de puissance__ et organiser le Github.

Deux types de régulateur à utiliser dans notre circuit : 
* Régulation à découpage (Montage Buck ?)
* Régulation linéaire (uniquement pour les faibles tensions)
* Gros condensateurs qu'on va nous donner pour réguler les steppers

### Tâches pour la prochaine fois (dans 3 semaines)

* Avoir un schéma fonctionnel pour révision
* Avoir un schéma pour le ROS2
* Choisir MOSFET et commandes

## Etat du projet n°2

### Problèmes/Constats

A faire cf Charlotte

### Tâches pour la prochaines fois (dans 3 semaines)

* SPI : le plus vite possible !!!
* Bien avancer sur le Dynamixel
* PCB fini ?
* Protocole de communication entre MP et Raspberry à bien définir


