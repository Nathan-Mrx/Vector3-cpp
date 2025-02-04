#include "Utils.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

/**
 * @brief Supprime les espaces en début et fin de chaîne.
 *
 * @param s La chaîne à "trimmer".
 * @return La chaîne sans espaces en début et fin.
 */
static std::string trim(const std::string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

Vec3 parseVec3(const std::string& input) {
    std::string processed = input;
    // Remplacer les virgules par des espaces pour faciliter le parsing
    std::replace(processed.begin(), processed.end(), ',', ' ');

    std::istringstream iss(processed);
    double a, b, c;
    if (!(iss >> a >> b >> c)) {
        throw std::runtime_error("Erreur de lecture du vecteur 3D. Format attendu : x y z ou x,y,z");
    }
    // Vérifier qu'il n'y a pas de caractères supplémentaires
    std::string extra;
    if (iss >> extra) {
        throw std::runtime_error("Erreur: caractères supplémentaires après les valeurs du vecteur 3D.");
    }
    return Vec3(a, b, c);
}

double parseDouble(const std::string& input) {
    std::string processed = input;
    // Remplacer les virgules par des points pour le format décimal
    std::replace(processed.begin(), processed.end(), ',', '.');

    std::istringstream iss(processed);
    double value;
    if (!(iss >> value)) {
        throw std::runtime_error("Erreur de lecture d'un nombre. Format attendu : un nombre valide.");
    }
    // Vérifier qu'il n'y a pas de caractères supplémentaires
    std::string extra;
    if (iss >> extra) {
        throw std::runtime_error("Erreur: caractères supplémentaires après le nombre.");
    }
    return value;
}

Vec3 readVec3(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        try {
            return parseVec3(input);
        }
        catch (const std::exception& e) {
            std::cerr << "Entrée invalide: " << e.what() << " Veuillez réessayer." << std::endl;
        }
    }
}

double readDouble(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        try {
            return parseDouble(input);
        }
        catch (const std::exception& e) {
            std::cerr << "Entrée invalide: " << e.what() << " Veuillez réessayer." << std::endl;
        }
    }
}
