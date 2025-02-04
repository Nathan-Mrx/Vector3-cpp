#ifndef VEC3_H
#define VEC3_H

#include <iostream>

/**
 * @brief Classe représentant un vecteur en 3D.
 *
 * Cette classe stocke trois coordonnées (x, y, z) et fournit des opérations
 * de base telles que l'addition et la soustraction de vecteurs.
 */
class Vec3 {
public:
    double x; /**< Coordonnée x */
    double y; /**< Coordonnée y */
    double z; /**< Coordonnée z */

    /**
     * @brief Constructeur par défaut.
     *
     * Initialise le vecteur à (0, 0, 0).
     */
    Vec3();

    /**
     * @brief Constructeur paramétré.
     * @param x La coordonnée x.
     * @param y La coordonnée y.
     * @param z La coordonnée z.
     */
    Vec3(double x, double y, double z);

    /**
     * @brief Additionne deux vecteurs.
     * @param other Le vecteur à ajouter.
     * @return Un nouveau vecteur résultant de l'addition.
     */
    Vec3 operator+(const Vec3& other) const;

    /**
     * @brief Soustrait deux vecteurs.
     * @param other Le vecteur à soustraire.
     * @return Un nouveau vecteur résultant de la soustraction.
     */
    Vec3 operator-(const Vec3& other) const;

    /**
     * @brief Surcharge de l'opérateur << pour l'affichage du vecteur.
     * @param os Le flux de sortie.
     * @param v Le vecteur à afficher.
     * @return Le flux de sortie.
     */
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v);
};

#endif // VEC3_H
