#include "Vec3.h"
#include <sstream>
#include <cmath>

const double PI = 3.14159265358979323846;

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

std::string Vec3::toString() const {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ", " << z << ")";
    return oss.str();
}

void Vec3::toSpherical(double &r, double &theta, double &phi) const {
    r = std::sqrt(x*x + y*y + z*z);
    theta = (r == 0) ? 0 : std::acos(z / r) * 180.0 / PI;
    phi = std::atan2(y, x) * 180.0 / PI;
}

Vec3 Vec3::fromSpherical(double r, double theta, double phi) {
    double thetaRad = theta * PI / 180.0;
    double phiRad = phi * PI / 180.0;
    double x = r * std::sin(thetaRad) * std::cos(phiRad);
    double y = r * std::sin(thetaRad) * std::sin(phiRad);
    double z = r * std::cos(thetaRad);
    return Vec3(x, y, z);
}
