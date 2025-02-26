#include "Tests.h"
#include "Vec3.h"
#include "Matrix4.h"
#include "Transformations.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

const double tol = 1e-6;

void runTests() {
    int testsPassed = 0;
    int totalTests = 0;

    // Test : Translation
    totalTests++;
    {
        Matrix4 t = Transformations::Translation(3, -2, 5);
        Vec3 v(1, 1, 1);
        Vec3 vt = t.transform(v);
        if (fabs(vt.x - 4) < tol && fabs(vt.y - (-1)) < tol && fabs(vt.z - 6) < tol) {
            cout << "Test Translation: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Translation: FAILED (obtenu " << vt.toString() << ")" << endl;
        }
    }

    // Test : Scaling
    totalTests++;
    {
        Matrix4 s = Transformations::Scaling(2, 3, 4);
        Vec3 v(1, 1, 1);
        Vec3 vs = s.transform(v);
        if (fabs(vs.x - 2) < tol && fabs(vs.y - 3) < tol && fabs(vs.z - 4) < tol) {
            cout << "Test Scaling: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Scaling: FAILED (obtenu " << vs.toString() << ")" << endl;
        }
    }

    // Test : Rotation autour de Y (90 deg)
    totalTests++;
    {
        Matrix4 r = Transformations::RotationY(90);
        Vec3 v(1, 0, 0);
        Vec3 vr = r.transform(v);
        if (fabs(vr.x) < tol && fabs(vr.y) < tol && fabs(vr.z + 1) < tol) {
            cout << "Test Rotation Y 90 deg: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Rotation Y 90 deg: FAILED (obtenu " << vr.toString() << ")" << endl;
        }
    }

    // Test : Shear XY
    totalTests++;
    {
        Matrix4 c = Transformations::ShearXY(2);
        Vec3 v(1, 1, 1);
        Vec3 vc = c.transform(v);
        if (fabs(vc.x - (1 + 2*1)) < tol) {
            cout << "Test ShearXY: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test ShearXY: FAILED (obtenu " << vc.toString() << ")" << endl;
        }
    }

    // Test : Projection sur le plan xy
    totalTests++;
    {
        Matrix4 p = Transformations::Projection("xy");
        Vec3 v(1, 2, 3);
        Vec3 vp = p.transform(v);
        if (fabs(vp.z) < tol) {
            cout << "Test Projection (xy): PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Projection (xy): FAILED (obtenu " << vp.toString() << ")" << endl;
        }
    }

    // Test : Reflection par rapport au plan yz
    totalTests++;
    {
        Matrix4 rfl = Transformations::Reflection("yz");
        Vec3 v(1, 2, 3);
        Vec3 vrfl = rfl.transform(v);
        if (fabs(vrfl.x + 1) < tol) {
            cout << "Test Reflection (yz): PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Reflection (yz): FAILED (obtenu " << vrfl.toString() << ")" << endl;
        }
    }

    cout << "\nRésumé des tests: " << testsPassed << " / " << totalTests << " tests réussis." << endl;
}
