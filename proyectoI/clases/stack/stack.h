#pragma once
#include "../node/nodePila.cpp"

template<class T>
class Stack {
private:
    NodePila<T>* head = NULL;
    int length = 0;

public:
    void push(T);
    T pop();
    T top();
    bool isEmpty();
    void print();

    Stack<T> ordenarPila(Stack<T>);
};