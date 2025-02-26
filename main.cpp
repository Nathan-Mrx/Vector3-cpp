#include <iostream>
#include <string>
#include <limits>
#include "Vec3.h"
#include "Matrix4.h"
#include "Transformations.h"
#include "Tests.h"

using namespace std;

/**
 * @brief Affiche le message d'aide sur l'utilisation du programme.
 * @param exeName Le nom de l'exécutable (argv[0]).
 */
void printHelp(const char* exeName) {
    cout << "Usage: " << exeName << " [option]" << endl;
    cout << "Options:" << endl;
    cout << "  --help, -h   Affiche ce message d'aide." << endl;
    cout << "  test         Lance les tests unitaires." << endl;
    cout << "\nSans option, le programme se lance en mode interactif." << endl;
}

/**
 * @brief Lit une chaîne de caractères de manière sûre.
 */
std::string safeReadString(const std::string &prompt) {
    std::string input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            return input;
        } else {
            cout << "Erreur de saisie. Veuillez réessayer." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

/**
 * @brief Lit un double de manière sûre.
 */
double safeReadDouble(const std::string &prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value)
            return value;
        else {
            cout << "Erreur de saisie. Veuillez entrer un nombre." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

/**
 * @brief Lit un caractère de manière sûre.
 */
char safeReadChar(const std::string &prompt) {
    std::string input;
    while (true) {
        cout << prompt;
        if (cin >> input && !input.empty())
            return input[0];
        else {
            cout << "Erreur de saisie. Veuillez réessayer." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

/**
 * @brief Demande à l'utilisateur s'il souhaite entrer le vecteur en coordonnées sphériques.
 */
bool askSphericalInput() {
    char resp = safeReadChar("Souhaitez-vous entrer le vecteur en coordonnees spherique ? (o/n) : ");
    return (resp == 'o' || resp == 'O');
}

/**
 * @brief Demande à l'utilisateur de saisir un vecteur.
 */
Vec3 getInputVector(bool spherical) {
    Vec3 v;
    if (!spherical) {
        cout << "Entrez le vecteur en coordonnees cartesiennes (x y z) : ";
        while (!(cin >> v.x >> v.y >> v.z)) {
            cout << "Erreur de saisie. Veuillez entrer trois nombres." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Entrez le vecteur en coordonnees cartesiennes (x y z) : ";
        }
    } else {
        double r = safeReadDouble("Entrez r : ");
        double theta = safeReadDouble("Entrez theta (deg) : ");
        double phi = safeReadDouble("Entrez phi (deg) : ");
        v = Vec3::fromSpherical(r, theta, phi);
    }
    return v;
}

/**
 * @brief Demande à l'utilisateur s'il souhaite afficher le résultat en coordonnées sphériques.
 */
bool askSphericalOutput() {
    char resp = safeReadChar("Afficher le resultat en coordonnees spherique ? (o/n) : ");
    return (resp == 'o' || resp == 'O');
}

/**
 * @brief Affiche le menu de transformation et retourne le choix de l'utilisateur.
 */
std::string getTransformationType() {
    cout << "\nChoisissez une transformation :" << endl;
    cout << "  R  : Rotation" << endl;
    cout << "  T  : Translation" << endl;
    cout << "  S  : Scaling (Changement d'echelle)" << endl;
    cout << "  C  : Cisaillement (Shear XY)" << endl;
    cout << "  P  : Projection orthographique" << endl;
    cout << "  RE : Reflection" << endl;
    return safeReadString("Votre choix : ");
}

/**
 * @brief Demande les paramètres pour une transformation et retourne la matrice correspondante.
 */
Matrix4 getTransformationMatrix(const std::string &type) {
    Matrix4 mat;
    try {
        if (type == "T") {
            double dx = safeReadDouble("Entrez dx (translation sur X) : ");
            double dy = safeReadDouble("Entrez dy (translation sur Y) : ");
            double dz = safeReadDouble("Entrez dz (translation sur Z) : ");
            mat = Transformations::Translation(dx, dy, dz);
        } else if (type == "S") {
            double sx = safeReadDouble("Entrez sx (echelle sur X) : ");
            double sy = safeReadDouble("Entrez sy (echelle sur Y) : ");
            double sz = safeReadDouble("Entrez sz (echelle sur Z) : ");
            mat = Transformations::Scaling(sx, sy, sz);
        } else if (type == "R") {
            char axis = safeReadChar("Rotation autour de quel axe ? (X, Y, Z) : ");
            double angle = safeReadDouble("Entrez l'angle de rotation (en degres) : ");
            if (axis == 'X' || axis == 'x')
                mat = Transformations::RotationX(angle);
            else if (axis == 'Y' || axis == 'y')
                mat = Transformations::RotationY(angle);
            else if (axis == 'Z' || axis == 'z')
                mat = Transformations::RotationZ(angle);
            else {
                cout << "Axe invalide. Utilisation de l'axe X par defaut." << endl;
                mat = Transformations::RotationX(angle);
            }
        } else if (type == "C") {
            double factor = safeReadDouble("Entrez le facteur de cisaillement (pour x en fonction de y) : ");
            mat = Transformations::ShearXY(factor);
        } else if (type == "P") {
            std::string plane = safeReadString("Projection sur quel plan ? (xy, xz, yz) : ");
            mat = Transformations::Projection(plane);
        } else if (type == "RE") {
            std::string plane = safeReadString("Reflection par rapport a quel plan ? (xy, xz, yz) : ");
            mat = Transformations::Reflection(plane);
        } else {
            cout << "Transformation inconnue, utilisation de la matrice identite." << endl;
            mat = Matrix4();
        }
    }
    catch (const std::exception &e) {
        cout << "Erreur lors de la saisie des parametres de transformation: " << e.what() << endl;
        cout << "Utilisation de la matrice identite." << endl;
        mat = Matrix4();
    }
    return mat;
}

/**
 * @brief Demande à l'utilisateur s'il souhaite effectuer une nouvelle transformation.
 */
bool askNewTransformation() {
    char resp = safeReadChar("Souhaitez-vous effectuer une nouvelle transformation ? (o/n) : ");
    return (resp == 'o' || resp == 'O');
}

/**
 * @brief Point d'entrée du programme.
 *
 * Si l'argument "test" ou "--help" / "-h" est passé en ligne de commande, les tests ou l'aide sont lancés.
 * Sinon, le mode interactif s'exécute.
 */
int main(int argc, char* argv[]) {
    // Gestion des arguments de ligne de commande
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--help" || arg == "-h") {
            printHelp(argv[0]);
            return 0;
        }
        if (arg == "test") {
            runTests();
            return 0;
        }
    }

    // Mode interactif
    bool sphericalInput = askSphericalInput();
    Vec3 currentVector = getInputVector(sphericalInput);

    cout << "\nVecteur initial : " << currentVector.toString() << endl;

    while (true) {
        std::string type = getTransformationType();
        Matrix4 t = getTransformationMatrix(type);
        currentVector = t.transform(currentVector);
        cout << "\nVecteur actuel apres transformation : " << currentVector.toString() << endl;

        if (!askNewTransformation())
            break;
    }

    cout << "\nVecteur final transformé : " << currentVector.toString() << endl;
    if (askSphericalOutput()) {
        double r, theta, phi;
        currentVector.toSpherical(r, theta, phi);
        cout << "Coordonnees spherique : (r = " << r << ", theta = " << theta
             << " deg, phi = " << phi << " deg)" << endl;
    }

    return 0;
}
