#include "Tests.h"
#include "Utils.h"
#include "Vec3.h"
#include "Transform.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

/**
 * @brief Exécute une série de tests unitaires pour vérifier le bon fonctionnement des classes et fonctions.
 *
 * Chaque test affiche un retour indiquant s'il a réussi ou échoué, suivi d'un résumé final.
 */
void runTests() {
    int testsPassed = 0;
    int totalTests = 0;
    double tol = 1e-6;

    // Test 1 : Addition de deux vecteurs
    totalTests++;
    {
        Vec3 v1(1, 2, 3);
        Vec3 v2(4, -1, 2);
        Vec3 sum = v1 + v2;
        if (fabs(sum.x - 5) < tol && fabs(sum.y - 1) < tol && fabs(sum.z - 5) < tol) {
            cout << "Test Vec3 addition: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Vec3 addition: FAILED (obtenu " << sum << ")" << endl;
        }
    }

    // Test 2 : Soustraction de deux vecteurs
    totalTests++;
    {
        Vec3 v1(4, 5, 6);
        Vec3 v2(1, 2, 3);
        Vec3 diff = v1 - v2;
        if (fabs(diff.x - 3) < tol && fabs(diff.y - 3) < tol && fabs(diff.z - 3) < tol) {
            cout << "Test Vec3 soustraction: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Vec3 soustraction: FAILED (obtenu " << diff << ")" << endl;
        }
    }

    // Test 3 : Transformation avec rotation de 90° et translation
    totalTests++;
    {
        Vec3 v_object(1, 0, 0);
        Transform tf(Vec3(1, 2, 3), 90);
        Vec3 result = tf.transform(v_object);
        if (fabs(result.x - 1) < tol &&
            fabs(result.y - 2) < tol &&
            fabs(result.z - 2) < tol) {
            cout << "Test Transform 90° + translation: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Transform 90° + translation: FAILED (obtenu " << result << ")" << endl;
        }
    }

    // Test 4 : Transformation avec 0° (pure translation)
    totalTests++;
    {
        Vec3 v_object(5, 5, 5);
        Transform tf(Vec3(2, 2, 2), 0);
        Vec3 result = tf.transform(v_object);
        if (fabs(result.x - 7) < tol &&
            fabs(result.y - 7) < tol &&
            fabs(result.z - 7) < tol) {
            cout << "Test Transform 0° (pure translation): PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Transform 0° (pure translation): FAILED (obtenu " << result << ")" << endl;
        }
    }

    // Test 5 : Transformation avec 180°
    totalTests++;
    {
        Vec3 v_object(1, 0, 2);
        Transform tf(Vec3(0, 0, 0), 180);
        Vec3 result = tf.transform(v_object);
        if (fabs(result.x + 1) < tol &&
            fabs(result.y - 0) < tol &&
            fabs(result.z + 2) < tol) {
            cout << "Test Transform 180°: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Transform 180°: FAILED (obtenu " << result << ")" << endl;
        }
    }

    // Test 6 : Transformation avec -90°
    totalTests++;
    {
        Vec3 v_object(0, 0, 1);
        Transform tf(Vec3(0, 0, 0), -90);
        Vec3 result = tf.transform(v_object);
        if (fabs(result.x + 1) < tol &&
            fabs(result.y - 0) < tol &&
            fabs(result.z - 0) < tol) {
            cout << "Test Transform -90°: PASSED" << endl;
            testsPassed++;
        } else {
            cout << "Test Transform -90°: FAILED (obtenu " << result << ")" << endl;
        }
    }

    // Test 7 : parseVec3 avec entrée valide
    totalTests++;
    {
        try {
            Vec3 v = parseVec3("1,2,3");
            if (fabs(v.x - 1) < tol && fabs(v.y - 2) < tol && fabs(v.z - 3) < tol) {
                cout << "Test parseVec3 valid input: PASSED" << endl;
                testsPassed++;
            } else {
                cout << "Test parseVec3 valid input: FAILED (obtenu " << v << ")" << endl;
            }
        } catch (const std::exception& e) {
            cout << "Test parseVec3 valid input: FAILED avec exception: " << e.what() << endl;
        }
    }

    // Test 8 : parseVec3 avec caractères superflus
    totalTests++;
    {
        try {
            Vec3 v = parseVec3("1, 2, 3 extra");
            cout << "Test parseVec3 extra garbage: FAILED. Une exception était attendue (obtenu " << v << ")" << endl;
        } catch (const std::exception& e) {
            cout << "Test parseVec3 extra garbage: PASSED (exception attrapée: " << e.what() << ")" << endl;
            testsPassed++;
        }
    }

    // Test 9 : parseVec3 avec valeurs insuffisantes
    totalTests++;
    {
        try {
            Vec3 v = parseVec3("1,2");
            cout << "Test parseVec3 insufficient values: FAILED. Une exception était attendue (obtenu " << v << ")" << endl;
        } catch (const std::exception& e) {
            cout << "Test parseVec3 insufficient values: PASSED (exception attrapée: " << e.what() << ")" << endl;
            testsPassed++;
        }
    }

    // Test 10 : parseDouble avec entrée valide
    totalTests++;
    {
        try {
            double d = parseDouble("3.14");
            if (fabs(d - 3.14) < tol) {
                cout << "Test parseDouble valid input: PASSED" << endl;
                testsPassed++;
            } else {
                cout << "Test parseDouble valid input: FAILED (obtenu " << d << ")" << endl;
            }
        } catch (const std::exception& e) {
            cout << "Test parseDouble valid input: FAILED avec exception: " << e.what() << endl;
        }
    }

    // Test 11 : parseDouble avec entrée invalide
    totalTests++;
    {
        try {
            double d = parseDouble("abc");
            cout << "Test parseDouble invalid input: FAILED. Une exception était attendue (obtenu " << d << ")" << endl;
        } catch (const std::exception& e) {
            cout << "Test parseDouble invalid input: PASSED (exception attrapée: " << e.what() << ")" << endl;
            testsPassed++;
        }
    }

    // Test 12 : parseDouble avec caractères superflus
    totalTests++;
    {
        try {
            double d = parseDouble("3.14abc");
            cout << "Test parseDouble extra characters: FAILED. Une exception était attendue (obtenu " << d << ")" << endl;
        } catch (const std::exception& e) {
            cout << "Test parseDouble extra characters: PASSED (exception attrapée: " << e.what() << ")" << endl;
            testsPassed++;
        }
    }

    cout << "\nRésumé des tests: " << testsPassed << " / " << totalTests << " tests réussis." << endl;
}
