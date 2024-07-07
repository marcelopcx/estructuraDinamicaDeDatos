#include <iostream>
#include "./clases/queve/queve.cpp"
#include "./clases/stack/stack.cpp"

int main()
{
    // Ejemplo de uso Pila
    Stack<double> miPila;
    miPila.push(6.0);
    miPila.push(4.0);
    miPila.push(2.0);
    miPila.push(3.0);
    miPila.push(5.0);
    
    Stack<double> pilaOrdenada = miPila.ordenarPila(miPila);

    cout<<endl;
    pilaOrdenada.print();
    cout<<endl;
    
    // Ejemplo de uso Cola
    Queue<double> miCola;
    miCola.push(8.0);
    miCola.push(4.0);
    miCola.push(12.0);
    miCola.push(3.0);
    miCola.push(-2.0);
    
    Queue<double> colaOrdenada = miCola.ordenarCola(miCola);

    cout<<endl;
    colaOrdenada.print();
    cout<<endl;

    return 0;
}