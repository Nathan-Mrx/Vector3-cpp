#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vec3.h"
#include <string>

/**
 * @brief Classe représentant une matrice 4x4 pour les transformations 3D.
 */
class Matrix4 {
public:
    double m[4][4]; ///< Les éléments de la matrice.

    /**
     * @brief Constructeur par défaut. Crée une matrice identité.
     */
    Matrix4();

    /**
     * @brief Opérateur de multiplication matricielle.
     * @param other La matrice à multiplier.
     * @return Le produit de la matrice courante par 'other'.
     */
    Matrix4 operator*(const Matrix4 &other) const;

    /**
     * @brief Applique la transformation de la matrice à un vecteur 3D.
     * @param v Le vecteur à transformer.
     * @return Le vecteur transformé.
     */
    Vec3 transform(const Vec3 &v) const;

    /**
     * @brief Retourne une représentation en chaîne de caractères de la matrice.
     * @return La matrice sous forme de chaîne.
     */
    std::string toString() const;
};

#endif // MATRIX4_H
