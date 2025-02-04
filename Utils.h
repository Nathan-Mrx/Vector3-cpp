#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Vec3.h"

/**
 * @brief Lit une ligne de saisie et convertit les valeurs en un vecteur 3D.
 *
 * @param prompt Le message à afficher pour inviter l'utilisateur.
 * @return Un objet Vec3 construit à partir des valeurs saisies.
 */
Vec3 readVec3(const std::string& prompt);

/**
 * @brief Lit une ligne de saisie et convertit la valeur en double.
 *
 * @param prompt Le message à afficher pour inviter l'utilisateur.
 * @return La valeur lue en double.
 */
double readDouble(const std::string& prompt);

/**
 * @brief Analyse une chaîne de caractères pour en extraire un vecteur 3D.
 *
 * La chaîne peut contenir des valeurs séparées par des espaces ou des virgules.
 * La fonction vérifie que la chaîne contient exactement trois nombres et rien d'autre.
 *
 * @param input La chaîne à analyser.
 * @return Un objet Vec3 avec les valeurs extraites.
 * @throws std::runtime_error Si le format n'est pas correct.
 */
Vec3 parseVec3(const std::string& input);

/**
 * @brief Analyse une chaîne de caractères pour en extraire un double.
 *
 * La fonction accepte le séparateur décimal sous forme de virgule ou de point.
 * Elle vérifie que la chaîne contient exactement un nombre et rien d'autre.
 *
 * @param input La chaîne à analyser.
 * @return La valeur en double extraite.
 * @throws std::runtime_error Si le format n'est pas correct.
 */
double parseDouble(const std::string& input);

#endif // UTILS_H
