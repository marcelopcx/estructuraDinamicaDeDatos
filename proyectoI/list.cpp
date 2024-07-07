#include <iostream>
#include "clases/queve/queve.h"
#include "clases/stack/stack.h"

using namespace std;

template <class T>
int printPilas(const Queue<Stack<T> >& lista)
{
    int num = 0;
    Queue<Stack<T> > copia = lista;
    while (!copia.isEmpty())
    {
        imprimirPila(copia.pop());
        num++;
    }
    return num;
}

template <class T>
int printColas(const Queue<Queue<T> >& lista)
{
    int num = 0;
    Queue<Queue<T> > copia = lista; 
    while (!copia.isEmpty())
    {
        imprimirCola(copia.pop());
        num++;
    }
    return num;
}

template <class T>
void imprimirPila(const Stack<T>& pila)
{
    Stack<T> copia = pila;
    while (!copia.isEmpty())
    {
        cout << copia.pop() << " ";
    }
    cout << endl;
}

template <class T>
void imprimirCola(const Queue<T>& cola)
{
    Queue<T> copia = cola;
    while (!copia.isEmpty())
    {
        cout << copia.pop() << " ";
    }
    cout << endl;
}