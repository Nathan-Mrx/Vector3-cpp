#include "Vec3.h"

// Constructeur par défaut : initialise le vecteur à (0, 0, 0)
Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}

// Constructeur paramétré
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

// Addition de deux vecteurs
Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

// Soustraction de deux vecteurs
Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

// Surcharge de l'opérateur << pour l'affichage
std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
