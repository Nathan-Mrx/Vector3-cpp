#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "Matrix4.h"
#include <string>

/**
 * @brief Espace de noms regroupant les fonctions de création de matrices de transformation.
 */
namespace Transformations {

/**
 * @brief Crée une matrice de translation.
 * @param dx Translation sur l'axe X.
 * @param dy Translation sur l'axe Y.
 * @param dz Translation sur l'axe Z.
 * @return La matrice de translation.
 */
Matrix4 Translation(double dx, double dy, double dz);

/**
 * @brief Crée une matrice de changement d'échelle.
 * @param sx Facteur d'échelle sur X.
 * @param sy Facteur d'échelle sur Y.
 * @param sz Facteur d'échelle sur Z.
 * @return La matrice d'échelle.
 */
Matrix4 Scaling(double sx, double sy, double sz);

/**
 * @brief Crée une matrice de rotation autour de l'axe X.
 * @param angleDeg Angle de rotation en degrés.
 * @return La matrice de rotation.
 */
Matrix4 RotationX(double angleDeg);

/**
 * @brief Crée une matrice de rotation autour de l'axe Y.
 * @param angleDeg Angle de rotation en degrés.
 * @return La matrice de rotation.
 */
Matrix4 RotationY(double angleDeg);

/**
 * @brief Crée une matrice de rotation autour de l'axe Z.
 * @param angleDeg Angle de rotation en degrés.
 * @return La matrice de rotation.
 */
Matrix4 RotationZ(double angleDeg);

/**
 * @brief Crée une matrice de cisaillement modifiant X en fonction de Y.
 * @param factor Facteur de cisaillement.
 * @return La matrice de cisaillement.
 */
Matrix4 ShearXY(double factor);

/**
 * @brief Crée une matrice de projection orthographique sur un plan.
 * @param plane Le plan de projection ("xy", "xz" ou "yz").
 * @return La matrice de projection.
 * @throws std::runtime_error Si le plan n'est pas reconnu.
 */
Matrix4 Projection(const std::string& plane);

/**
 * @brief Crée une matrice de réflexion par rapport à un plan.
 * @param plane Le plan de réflexion ("xy", "xz" ou "yz").
 * @return La matrice de réflexion.
 * @throws std::runtime_error Si le plan n'est pas reconnu.
 */
Matrix4 Reflection(const std::string& plane);

} // namespace Transformations

#endif // TRANSFORMATIONS_H
