#ifndef VEC3_H
#define VEC3_H

#include <string>

/**
 * @brief Classe représentant un vecteur 3D.
 */
class Vec3 {
public:
    double x; ///< Coordonnée x
    double y; ///< Coordonnée y
    double z; ///< Coordonnée z

    /**
     * @brief Constructeur par défaut.
     */
    Vec3();

    /**
     * @brief Constructeur paramétré.
     * @param x Coordonnée x.
     * @param y Coordonnée y.
     * @param z Coordonnée z.
     */
    Vec3(double x, double y, double z);

    /**
     * @brief Retourne une représentation sous forme de chaîne de caractères.
     * @return La chaîne représentant le vecteur.
     */
    std::string toString() const;

    /**
     * @brief Convertit le vecteur en coordonnées sphériques.
     *
     * @param r (out) Distance.
     * @param theta (out) Angle polaire (en degrés, mesuré depuis l'axe Z positif).
     * @param phi (out) Angle azimutal (en degrés, dans le plan XY, mesuré depuis l'axe X positif).
     */
    void toSpherical(double &r, double &theta, double &phi) const;

    /**
     * @brief Crée un vecteur à partir de coordonnées sphériques.
     *
     * @param r Distance.
     * @param theta Angle polaire (en degrés).
     * @param phi Angle azimutal (en degrés).
     * @return Un vecteur en coordonnées cartésiennes.
     */
    static Vec3 fromSpherical(double r, double theta, double phi);
};

#endif // VEC3_H
