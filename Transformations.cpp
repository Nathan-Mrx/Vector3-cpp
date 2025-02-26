#include "Transformations.h"
#include <cmath>
#include <stdexcept>

const double PI = 3.14159265358979323846;

namespace Transformations {

Matrix4 Translation(double dx, double dy, double dz) {
    Matrix4 mat;
    mat.m[0][3] = dx;
    mat.m[1][3] = dy;
    mat.m[2][3] = dz;
    return mat;
}

Matrix4 Scaling(double sx, double sy, double sz) {
    Matrix4 mat;
    mat.m[0][0] = sx;
    mat.m[1][1] = sy;
    mat.m[2][2] = sz;
    return mat;
}

Matrix4 RotationX(double angleDeg) {
    Matrix4 mat;
    double rad = angleDeg * PI / 180.0;
    double cosA = std::cos(rad);
    double sinA = std::sin(rad);
    mat.m[1][1] = cosA;
    mat.m[1][2] = -sinA;
    mat.m[2][1] = sinA;
    mat.m[2][2] = cosA;
    return mat;
}

Matrix4 RotationY(double angleDeg) {
    Matrix4 mat;
    double rad = angleDeg * PI / 180.0;
    double cosA = std::cos(rad);
    double sinA = std::sin(rad);
    mat.m[0][0] = cosA;
    mat.m[0][2] = sinA;
    mat.m[2][0] = -sinA;
    mat.m[2][2] = cosA;
    return mat;
}

Matrix4 RotationZ(double angleDeg) {
    Matrix4 mat;
    double rad = angleDeg * PI / 180.0;
    double cosA = std::cos(rad);
    double sinA = std::sin(rad);
    mat.m[0][0] = cosA;
    mat.m[0][1] = -sinA;
    mat.m[1][0] = sinA;
    mat.m[1][1] = cosA;
    return mat;
}

Matrix4 ShearXY(double factor) {
    Matrix4 mat;
    // Cisaillement : x' = x + factor * y
    mat.m[0][1] = factor;
    return mat;
}

Matrix4 Projection(const std::string& plane) {
    Matrix4 mat;
    if (plane == "xy") {
        // Projection sur le plan xy : z = 0
        mat.m[2][2] = 0;
    } else if (plane == "xz") {
        // Projection sur le plan xz : y = 0
        mat.m[1][1] = 0;
    } else if (plane == "yz") {
        // Projection sur le plan yz : x = 0
        mat.m[0][0] = 0;
    } else {
        throw std::runtime_error("Plan de projection inconnu. Utilisez 'xy', 'xz' ou 'yz'.");
    }
    return mat;
}

Matrix4 Reflection(const std::string& plane) {
    Matrix4 mat;
    if (plane == "xy") {
        // Reflection par rapport au plan xy : inversion de z
        mat.m[2][2] = -1;
    } else if (plane == "xz") {
        // Reflection par rapport au plan xz : inversion de y
        mat.m[1][1] = -1;
    } else if (plane == "yz") {
        // Reflection par rapport au plan yz : inversion de x
        mat.m[0][0] = -1;
    } else {
        throw std::runtime_error("Plan de réflexion inconnu. Utilisez 'xy', 'xz' ou 'yz'.");
    }
    return mat;
}

} // namespace Transformations
