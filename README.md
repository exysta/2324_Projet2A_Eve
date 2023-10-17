# Project Eve

<div align="center">


<img src="PP.jpeg"  width=300><br>

[Code](Code/) 
| [Documentation](Documents/) 
| [Liens utiles](Documents/Liens_utiles.md) 
| [Journal](Journal/ReadMe.md)
| [Bilan des présentations](Présentation/ReadMe.md)

</div>



## Introduction

Vous vous situez sur le Github d'Eve (anciennement Robourt). C'est un projet de bras robotique six axes réalisé par des étudiants de l'ENSEA. Vous pourrez trouver ici la documentation, le guide d'utilisation, le journal de bord (et autres documents connexes) pour comprendre notre projet. Nous vous souhaitons une bonne lecture !

> You are in the Github of Eve (formely Robourt). This is a project of a six-axis robot arm project by students at ENSEA. Here you can find here documentation, user guide, logbook (and other related documents) to help you understand our project. We hope you enjoy reading! The rest of the text will be in French exclusively.





### Table des matières


1. [Partie Software](#partie-software)
2. [Partie Hardware et intégration](#partie-hardware-et-intégration)
3. [Guide d'utilisation](#guide-dutilisation)
4. [Annexes](#annexes)


## Partie-Software


### ROS 2

Il y a deux manières de faire avec ROS2 :
* ROS2 fait tout : le contrôle, la gestion des ressources et les calculs (Méthode 1)
* ROS2 ne fait presque rien : Il transmet simplement les données d'un point A à un point B (Méthode 2)

Le problème avec la méthode 1, c'est que comme tout est géré par ROS, on n'utilise pas la STM32 et donc notre projet d'électronique n'a plus de sens. Donc il faudrait plutôt opter pour la méthode 2 qui demande très peu côté ROS/Raspberry mais par contre demande faire tous les calculs et l'asservissement par la STM32. On doit donc faire notre propre "boite noire" => Trouver des solutions alternatives

Pour la méthode 1 : 
<div align="center">
<br>
<img src="components_architecture.png" width="400">
</div>
WIP

## Partie Hardware et intégration

### Cahier des charges - Matériel


* TMC2590
* 17hs19-2004s
* XL320 (x2)
* XL430 w250 (x2)
* 23HS8430
* 23hS2442B Nema 23
* STM32 L3L4 ?
* Quel régulateur ?


<div align="center">
<img src="/Présentation/Diag archi.drawio.png"  width=600 legend="Rouge : Supply | Bleu : Données" title="Diagramme d'architecture">
</div>

WIP

## Guide d'utilisation

WIP

## Annexes

WIP
