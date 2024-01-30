# Journal de bord

1. [Introduction](#introduction)
2. [Séance 1](#séance-1)
3. [Séance 2](#séance-2)
4. [Séance 3](#séance-3)
5. [Séance 4](#séance-4)
6. [Séance 5](#séance-5)
7. [Séance 6](#séance-6)
8. [Séance 7](#séance-7)
9. [Séance 8](#séance-8)
10. [Séance 9](#séance-9)
11. [Séance 10](#séance-10)
12. [Séance 11](#séance-11)
12. [Séance 12](#séance-12)


## Introduction

Journal de bord du projet Robourt - 2023.

## Séance 1

### Contenu (19/09/23)

* Démonter le robot pour explorer ses entrailles
* Mise en place du dépot GitHub
* Mise en place de ROS sur certains ordinateurs
* Début de compréhension pour le fonctionnement de Github (et de Git)
* Début de compréhension pour le fonctionnement de ROS

### A faire

* Continuer de comprendre ROS & Github
* Commencer à réfléchir sur le cahier des charges (en collaboration avec les autres étudiants)
* Contacter les MSC & EVE

## Séance 2

### Contenu (26/09/23)

* Comprendre le fonctionnement Git
* Préparation de ROS sur certains PC & tests
* Contact avec les MSC pour avoir une idée des servomoteurs & idée générale du robot (Servomoteurs : AX12 & XL-320)
* Moteurs pas à pas : TMC2225 => Compréhension de fonctionnement
* Tests pour démarrer le TMC2225 avec l'UART ou STEP/DIR (STEP/DIR actuellement) non fonctionnel
* Début diagramme de Gantt

### A faire

* Faire fonctionner ce stepper
* Commencer réflexion PCB
* Etre au point ROS
* Réflechir cahier des charges


## Séance 3

### Contenu (03/10/2023)

* Continuation sur l'apprentissage de ROS
* Communication avec le stepper par l'intermédiaire du TMC2225 avec STEP/DIR
* Diagramme d'architecture ( == Schéma synoptique) et cahier des charges/matériel
* Début du schematic pour le PCB

### A faire

* Continuer ROS (notions serveur/action, créer son propre topic ?)
* Diagramme d'architecture
* Cahier des charges

## Séance 4 

### Contenu (10/10/2023)

* Présentation N°1
* Commande de matériel
* Mise en page Github
* Bilan de puissance (presque fini)
* Recherche sur SPI
* Choix des MOSFET
* Correction diagramme d'architecture
* Révision KiCad

### A faire

* ROS2 : continuation service/client et se renseigner sur la boite noire
* Continuer Kicad
* Continuer SPI
* Continuer bilan Présentation n°1
* Continuer Mise en page Github
* Se renseigner sur le protocole DYNAMIXEL, protocol 2.0

## Séance 5

### Contenu (17/10/2023)
* ROS2 : Recherche sur la fameuse boite noire et des alternatives
* Avancées sur le Kicad
* Fin du bilan de présentation n°1
* Avancées Github
* Avancées contrôle SPI
* Recherche sur le protocole DYNAMIXEL 2.0

### A faire

* Continuer le PCB

## Séance 6

### Contenu (17/10/2023)

* Réflexion sur le Microprocesseur avec les fonctionnalités désirées
* Avancées sur la connexion SPI avec les steppers (Tableau de sin & code)
* Continuer le PCB

### A faire

* Rédiger les avancées
* Commencer la documentation sur la connexion SPI
* Finir schematic pour le PCB
* Réflexion sur le ROS et penser au schéma
* Préparer la présentation n°2

## Séance 7

### Contenu (07/11/2023)

* Mise au point n°2
* Continuation sur le SPI : le problème vient du code

### A faire

* Faire tourner le moteur à l'aide du SPI
* Commencer routage
* Appliquer les modifications

## Séance 8

### Contenu (14/11/2023)

* Continuation sur le SPI : le problème vient du code
* Configuration des empreintes du PCB
* Progression sur Dynamixel 2.0 pour communication avec servos
### A faire

* Faire tourner le moteur à l'aide du SPI
* Commencer routage
* Commander composants
* Faire tourner XL430 avec dynamixel 2.0


## Séance 9

### Contenu (28/11/2023)

* Moteur tourne en SPI, dans les deux sens avec un ordre en angle donné
* Routage en cours
* Transmission en Dynamixel
### A faire

* Préparer la présentation
* Documenter le tout
* Récupérer la position du stepper & utiliser DMA

## Séance 10

### Contenu (05/12/2023)

* Présentation 

### A faire

* Continuer/Finir le routage
* Ajouter les capteurs de fin de course pour le SPI et une manière de récupérer la position initiale

## Séance 11

### Contenu (12/12/2023)

* SPI : Code pour récupérer la position initiale
* Kicad : Restructuration du schematic et du routage

### A faire

* Régler les problèmes de code et continuer d'implémenter les structures de Stepper

## Séance 12

### Contenu (16/01/2024)

* Avancement du code pour récupérer la position initiale
* Kicad : Le routage a été finalisé avant cette séance. Inventaire des composants nécessaires

### A faire

* Régler les problèmes de code et continuer d'implémenter les structures de Stepper
* Soudage PCB
