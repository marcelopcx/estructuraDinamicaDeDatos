#include <iostream>
#include <fstream>
#include <sstream>
#include "list.cpp"
#include "./clases/queve/queve.cpp"
#include "./clases/stack/stack.cpp"

int main()
{
    //Lectura de archivos
    fstream archivoPilas;
    fstream archivoColas;

    archivoPilas.open("assets/stack.csv", fstream::in);
    archivoColas.open("assets/queue.csv", fstream::in);


    if (!archivoPilas.is_open() && !archivoColas.is_open())
    {
        cerr << "[ERROR] No se ha podido abrir el archivo correctamente." << endl << endl;
        return 1;
    }

    //Variables a utilizar
    int option = 0;
    string line;

    //Menú de opciones
    cout<<endl<<endl;
    cout<< "   //////////   ¿Qué operación desea ralizar?   //////////" <<endl<<endl;
    cout<< "      1. Imprimir y ordenar las Pilas del archivo" <<endl;
    cout<< "      2. Imprimir y ordenar las Colas del archivo" <<endl<<endl;

    cout<< "   [OPCION] --> ";cin >> option; cout<<endl;

    //Operaciones a realizar
    switch (option){
    case 1: // Pilas 
    {
        Queue<Stack<double> > listaPilas;
         int numPila = 0;

        while (getline(archivoPilas, line, '\n'))
        {
            stringstream stream(line);
            string dato;

            // Crea una nueva pila para cada línea
            Stack<double> miPila;

            while (getline(stream, dato, ';'))
            {
                miPila.push(stof(dato));
            }

            // Ordena la pila y agrégala a la cola
            Stack<double> pilaOrdenada = miPila.ordenarPila(miPila);
            listaPilas.push(pilaOrdenada);
            numPila++;
        }

        // Imprime las pilas en la lista
        cout << "Pilas en orden ascendente:" << endl<<endl;
        printPilas(listaPilas); cout<< endl<<endl;
        cout<<"El numero de pilas impresas en patalla fueron: " << numPila <<endl<<endl;
    }
    break;
    
    case 2: // Colas
    {
        Queue<Queue<double> > listaColas;
        int numCola = 0;

        while (getline(archivoColas, line, '\n'))
        {
            stringstream stream(line);
            string dato;

            // Crea una nueva cola para cada línea
            Queue<double> miCola;

            while (getline(stream, dato, ';'))
            {
                miCola.push(stof(dato));
            }

            // Ordena la cola y agrégala a la cola
            Queue<double> colaOrdenada = miCola.ordenarCola(miCola);
            listaColas.push(colaOrdenada);
            numCola++;
        }

        // Imprime las cola en la lista
        cout << "Colas en orden ascendente:" << endl<<endl;
        printColas(listaColas); cout<< endl<<endl;
        cout<<"El numero de colas impresas en patalla fueron: " << numCola <<endl<<endl;
    }
    break;

    default:
        cerr << "[ERROR] Se eligio una opción no valida." << endl << endl;
        return 1; 
    break;
    }

    return 0;
}