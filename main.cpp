#include <iostream>
#include <stdexcept>
#include "Vec3.h"
#include "Transform.h"
#include "Utils.h"
#include "Tests.h"

using namespace std;

/**
 * @brief Affiche un message d'aide sur l'utilisation du programme.
 *
 * @param exeName Le nom de l'exécutable (argv[0]).
 */
void printHelp(const char* exeName) {
    cout << "Usage: " << exeName << " [options]" << endl;
    cout << "Options:" << endl;
    cout << "  --help, -h         Affiche ce message d'aide." << endl;
    cout << "  test               Lance les tests unitaires." << endl;
    cout << endl;
    cout << "Sans option, le programme se lance en mode interactif." << endl;
}

/**
 * @brief Point d'entrée du programme.
 *
 * Le programme fonctionne en mode interactif ou en mode test, ou affiche l'aide si demandé.
 *
 * @param argc Le nombre d'arguments de la ligne de commande.
 * @param argv Les arguments de la ligne de commande.
 * @return int 0 en cas de succès, un code d'erreur sinon.
 */
int main(int argc, char* argv[]) {
    try {
        // Gestion des arguments de la ligne de commande
        if (argc > 1) {
            string arg1 = argv[1];
            if (arg1 == "--help" || arg1 == "-h") {
                printHelp(argv[0]);
                return 0;
            }
            if (arg1 == "test") {
                runTests();
                return 0;
            }
        }

        // Mode interactif
        cout << "=== Transformation d'un vecteur 3D ===" << endl;

        // Saisie du vecteur dans le repère de l'objet
        Vec3 v_object = readVec3("Entrez les coordonnees du vecteur objet (x y z): ");

        // Saisie de la translation
        Vec3 translation = readVec3("Entrez la translation (x y z): ");

        // Saisie de l'angle de rotation (en degrés) autour de l'axe Y
        double angle_deg = readDouble("Entrez l'angle de rotation en degres (autour de l'axe Y): ");

        // Création et application de la transformation
        Transform tf(translation, angle_deg);
        Vec3 v_world = tf.transform(v_object);

        cout << "Le vecteur dans le repere universel est: " << v_world << endl;
    }
    catch (const exception& ex) {
        cerr << "Exception attrapée: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
