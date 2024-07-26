#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include "../controller/graphs.cpp"
#include "../controller/queve.cpp"

using namespace std;

Graph<string> g(100);
unordered_map<string, int> personas;
int personaCount = 0;

void limpiarPantalla() {
    cout << endl << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
    if (cin) {
        system("clear");
    }
}

void agregarPersona() {
    system("clear");
    string nombre;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre; cout << endl;
    g.addVertex(nombre);
    personas[nombre] = personaCount++;
    cout << nombre << " ha sido agregada." << endl;
    limpiarPantalla();
}

void realizarFollow() {
    system("clear");
    string seguidor, seguido;
    cout << "Ingrese el nombre de la persona que sigue: ";
    cin >> seguidor;
    cout << "Ingrese el nombre de la persona a la que sigue: ";
    cin >> seguido; cout << endl;
    if (personas.find(seguidor) != personas.end() && personas.find(seguido) != personas.end()) {
        g.addEdge(personas[seguidor], personas[seguido], 1);
        cout << seguidor << " ahora sigue a " << seguido << "." << endl;
    } else {
        cout << "Una o ambas personas no existen." << endl;
    }
    limpiarPantalla();
}

void eliminarFollow() {
    system("clear");
    string seguidor, seguido;
    cout << "Ingrese el nombre de la persona que deja de seguir: ";
    cin >> seguidor;
    cout << "Ingrese el nombre de la persona a la que deja de seguir: ";
    cin >> seguido; cout << endl;
    if (personas.find(seguidor) != personas.end() && personas.find(seguido) != personas.end()) {
        g.removeEdge(personas[seguidor], personas[seguido]);
        cout << seguidor << " ha dejado de seguir a " << seguido << "." << endl;
    } else {
        cout << "Una o ambas personas no existen." << endl;
    }
    limpiarPantalla();
}

void mostrarCaminoMasCorto() {
    system("clear");
    string origen, destino;
    cout << "Ingrese el nombre de la persona de origen: ";
    cin >> origen;
    cout << "Ingrese el nombre de la persona de destino: ";
    cin >> destino; cout << endl;
    if (personas.find(origen) != personas.end() && personas.find(destino) != personas.end()) {
        int pathLength;
        int* path = g.shortestPath(personas[origen], personas[destino], pathLength);
        cout << "Camino más corto de " << origen << " a " << destino << ": ";
        for (int i = 0; i < pathLength; i++) {
            if (i == pathLength - 1) {
                cout << g.getVertex(path[i]) << " ";
            } else {
                cout << g.getVertex(path[i]) << ", ";
            }
        }
        cout << endl;
        delete[] path; // Liberar la memoria del camino
    } else {
        cout << "Una o ambas personas no existen." << endl;
    }
    limpiarPantalla();
}