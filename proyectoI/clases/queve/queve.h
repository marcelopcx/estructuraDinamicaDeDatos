#pragma once
#include "../node/nodeCola.cpp"

template<class T>
class Queue {
private:
    NodeCola<T>* head = NULL;
    NodeCola<T>* tail = NULL;
    int length = 0;

public:
    // Métodos de las Colas
    int getLength();
    void push(T);
    T pop();
    bool isEmpty();
    void print();

    // Métodos de Ordenamiento
    T obtenerMin(Queue<T>, Queue<T>, T);
    Queue<T> ordenarCola(Queue<T> colaOriginal);
};
