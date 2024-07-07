#pragma once
#include "../node/node.cpp"

template<class T>
class Queue {
private:
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
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
