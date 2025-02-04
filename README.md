# Transformation 3D - Vector3

Ce projet implémente un système de transformation de vecteurs 3D. Le programme permet de convertir un vecteur exprimé dans le repère local d'un objet vers le repère universel en appliquant une rotation (autour de l'axe Y) suivie d'une translation.

## Fonctionnalités

- **Saisie interactive** : L'utilisateur saisit le vecteur local, la translation et l'angle de rotation.
- **Robustesse** : Chaque saisie est validée dans une boucle pour éviter les plantages en cas d'erreur de format.
- **Gestion des erreurs** : Les erreurs de saisie sont gérées par des exceptions avec messages d'erreur explicites.
- **Tests unitaires** : Un ensemble de tests exhaustifs (opérations sur les vecteurs, transformations, parsing des entrées) est disponible et peut être lancé via la ligne de commande.
- **Aide en ligne de commande** : L'option `--help` affiche un message d'aide détaillé.

## Structure du Projet

```
project/ 
├── CMakeLists.txt # Fichier de configuration CMake
├── README.md # Ce fichier 
├── main.cpp # Point d'entrée du programme (mode interactif et option --help/test) 
├── Vec3.h / Vec3.cpp # Définition et implémentation de la classe Vec3 ├── Transform.h / Transform.cpp # Définition et implémentation de la transformation 3D 
├── Utils.h / Utils.cpp # Fonctions utilitaires pour la saisie et le parsing 
├── Tests.h / Tests.cpp # Tests unitaires et exhaustifs
```

## Compilation

### Avec CMake (CLion ou en ligne de commande)

Assurez-vous que `CMakeLists.txt` liste tous les fichiers sources. Par exemple :

```cmake
cmake_minimum_required(VERSION 3.15)
project(Vector3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector3 
    main.cpp 
    Vec3.cpp 
    Transform.cpp 
    Utils.cpp 
    Tests.cpp
)
```
Ensuite, compilez le projet via CLion ou en ligne de commande :

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Utilisation
### Mode Interactif
Lancez l'exécutable sans argument pour entrer en mode interactif :

```bash
./Vector3
```
Le programme vous demandera d'entrer :

1. Les coordonnées du vecteur dans le repère de l'objet (exemple : 1 2 3 ou 1,2,3)
2. La translation (exemple : -3 5 -1)
3. L'angle de rotation (en degrés)

### Mode Test
Pour lancer les tests unitaires :

```bash
./Vector3 test
```
Le programme affichera le résultat de chaque test et un résumé final.

### Affichage de l'Aide
Pour afficher le message d'aide :

```bash
./Vector3 --help
```
ou

```bash
./Vector3 -h
```

## Auteur
Nathan Merieux
nathan.merieux@outlook.fr

## Licence
Ce projet est sous licence MIT.
