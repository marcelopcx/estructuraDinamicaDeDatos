#include <iostream>
#include "./clases/queve/queve.cpp"

int main()
{
    // Ejemplo de uso
    Queue<double> miCola;
    miCola.push(6.0);
    miCola.push(4.0);
    miCola.push(2.0);
    miCola.push(3.0);
    miCola.push(5.0);
    
    Queue<double> colaOrdenada = miCola.ordenarCola(miCola);

    cout<<endl;
    colaOrdenada.print();
    cout<<endl;

    return 0;
}