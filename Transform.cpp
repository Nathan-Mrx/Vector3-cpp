#include "Transform.h"
#include <cmath>

const double PI = 3.14159265358979323846;

Transform::Transform(const Vec3& translation, double angleY_deg)
    : translation(translation)
{
    double angleY_rad = angleY_deg * PI / 180.0;
    cosAngle = std::cos(angleY_rad);
    sinAngle = std::sin(angleY_rad);
}

Vec3 Transform::transform(const Vec3& v_object) const {
    // Matrice de rotation autour de Y :
    // [ cos(θ)   0   sin(θ) ]
    // [   0      1     0    ]
    // [ -sin(θ)  0   cos(θ) ]
    double x_rot = cosAngle * v_object.x + sinAngle * v_object.z;
    double y_rot = v_object.y;
    double z_rot = -sinAngle * v_object.x + cosAngle * v_object.z;
    return Vec3(x_rot, y_rot, z_rot) + translation;
}
