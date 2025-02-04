#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vec3.h"

/**
 * @brief Classe représentant une transformation 3D.
 *
 * Applique une transformation composée d'une rotation autour de l'axe Y suivie
 * d'une translation. La transformation est définie par :
 *   v_world = R_y(angle) * v_object + translation.
 */
class Transform {
public:
    /**
     * @brief Constructeur.
     * @param translation Le vecteur de translation.
     * @param angleY_deg L'angle de rotation autour de l'axe Y (en degrés).
     */
    Transform(const Vec3& translation, double angleY_deg);

    /**
     * @brief Transforme un vecteur du repère local vers le repère universel.
     * @param v_object Le vecteur dans le repère de l'objet.
     * @return Le vecteur transformé dans le repère universel.
     */
    Vec3 transform(const Vec3& v_object) const;

private:
    Vec3 translation; /**< Vecteur de translation */
    double cosAngle;  /**< Cosinus de l'angle de rotation */
    double sinAngle;  /**< Sinus de l'angle de rotation */
};

#endif // TRANSFORM_H
