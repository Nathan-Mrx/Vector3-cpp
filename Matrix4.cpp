#include "Matrix4.h"
#include <sstream>
#include <iomanip>

Matrix4::Matrix4() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            m[i][j] = (i == j) ? 1 : 0;
}

Matrix4 Matrix4::operator*(const Matrix4 &other) const {
    Matrix4 result;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            result.m[i][j] = 0;
            for (int k = 0; k < 4; k++){
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}

Vec3 Matrix4::transform(const Vec3 &v) const {
    double x = m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z + m[0][3];
    double y = m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z + m[1][3];
    double z = m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z + m[2][3];
    double w = m[3][0]*v.x + m[3][1]*v.y + m[3][2]*v.z + m[3][3];
    if (w != 0 && w != 1) {
        x /= w;
        y /= w;
        z /= w;
    }
    return Vec3(x, y, z);
}

std::string Matrix4::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            oss << m[i][j] << "\t";
        }
        oss << "\n";
    }
    return oss.str();
}
