# GeometricTransformations

Ce projet implémente un système complet de transformations géométriques en 3D.  
Il permet d'effectuer et de composer de multiples transformations sur un vecteur, telles que :

- **Rotation (R)** autour de l'axe X, Y ou Z
- **Translation (T)**
- **Changement d'échelle (Scaling, S)**
- **Cisaillement (Shear, C)** – ici, un cisaillement de X en fonction de Y
- **Projection (P)** – projection orthographique sur un plan (xy, xz ou yz)
- **Réflexion (RE)** – réflexion par rapport à un plan (xy, xz ou yz)

De plus, le programme offre la possibilité (bonus) d'entrer et d'afficher les vecteurs en coordonnées sphériques.

## Caractéristiques principales

- **Interface interactive robuste :**  
  Après chaque transformation, le vecteur courant est affiché et l'utilisateur peut choisir d'enchaîner une nouvelle transformation.

- **Gestion sécurisée des saisies :**  
  Les fonctions de saisie (« safeRead ») redemandent l'entrée en cas d'erreur, évitant ainsi tout crash du programme.

- **Options en ligne de commande :**
    - `--help` ou `-h` : Affiche un message d'aide détaillé.
    - `test` : Lance la suite des tests unitaires pour valider le bon fonctionnement du module de transformations.

- **Documentation Doxygen :**  
  Le code est commenté avec des annotations Doxygen, ce qui permet de générer facilement une documentation technique complète.

## Structure du Projet

```
GeometricTransformations/
├── CMakeLists.txt           # Fichier de configuration CMake
├── README.md                # Ce fichier
├── main.cpp                 # Point d'entrée du programme (mode interactif, test, aide)
├── Vec3.h / Vec3.cpp        # Classe représentant un vecteur 3D et ses conversions (cartésien/sphérique)
├── Matrix4.h / Matrix4.cpp  # Classe de matrice 4x4 pour les transformations
├── Transformations.h / Transformations.cpp  
                             # Fonctions de création de matrices pour chaque transformation géométrique
├── Tests.h / Tests.cpp      # Module de tests unitaires
```

## Compilation

### Avec CMake

1. Ouvrez une invite de commandes ou un terminal à la racine du projet.
2. Créez un dossier de build et compilez :

   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

## Utilisation

### Mode Interactif

Lancez l'exécutable sans aucun argument :

```bash
./GeometricTransformations
```

Le programme vous guidera dans les étapes suivantes :
1. Choix du mode de saisie du vecteur (cartésien ou sphérique).
2. Saisie du vecteur à transformer.
3. Transformation itérative :  
   Après chaque transformation (rotation, translation, scaling, cisaillement, projection, réflexion), le vecteur courant est affiché. Vous pourrez ensuite choisir d'appliquer une nouvelle transformation ou de terminer.
4. Optionnel : Affichage du vecteur final en coordonnées sphériques.

### Ligne de commande

- **Afficher l'aide :**

  ```bash
  ./GeometricTransformations --help
  ```
  ou
  ```bash
  ./GeometricTransformations -h
  ```

- **Lancer les tests unitaires :**

  ```bash
  ./GeometricTransformations test
  ```

### Exemple d'utilisation

Après avoir lancé le programme en mode interactif, vous pourriez voir un déroulement comme suit :

```
Souhaitez-vous entrer le vecteur en coordonnees spherique ? (o/n) : n
Entrez le vecteur en coordonnees cartesiennes (x y z) : 1 2 3

Vecteur initial : (1, 2, 3)

Choisissez une transformation :
  R  : Rotation
  T  : Translation
  S  : Scaling (Changement d'echelle)
  C  : Cisaillement (Shear XY)
  P  : Projection orthographique
  RE : Reflection
Votre choix : T
Entrez dx (translation sur X) : 3
Entrez dy (translation sur Y) : -2
Entrez dz (translation sur Z) : 1

Vecteur actuel apres transformation : (4, 0, 4)
Souhaitez-vous effectuer une nouvelle transformation ? (o/n) : n

Vecteur final transformé : (4, 0, 4)
Afficher le resultat en coordonnees spherique ? (o/n) : o
Coordonnees spherique : (r = 5.657, theta = 57.994 deg, phi = 0 deg)
```

## Documentation

Pour générer la documentation technique à l'aide de Doxygen, créez un fichier de configuration (par exemple, via la commande `doxygen -g`) et exécutez Doxygen dans le dossier du projet. Les commentaires présents dans le code permettront de générer une documentation complète.

## Auteur

*Nathan Merieux*  
*nathan.merieux@outlook.fr*

*Romain Monney*  
*romainmny@gmail.com*

## Licence

Ce projet est sous licence MIT.