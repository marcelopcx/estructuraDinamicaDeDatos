#include <iostream>
#include "vista/operations.cpp"
#include "vista/menu.cpp"

using namespace std;

int main() {
    system("clear");
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                agregarUsuario();
                break;
            case 2:
                realizarFollow();
                break;
            case 3:
                eliminarFollow();
                break;
            case 4:
                mostrarCaminoMasCorto();
                break;
            case 5:
                system("clear");
                break;
            default:
                cout << endl << "Opción no válida. Intente de nuevo." << endl;
                limpiarPantalla();
        }
    } while (opcion != 5);

    return 0;
}