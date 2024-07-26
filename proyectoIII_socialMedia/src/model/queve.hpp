#pragma once
#include "../controller/nodeCola.cpp"

template<class T>
class Queue {
private:
    NodeCola<T>* head = NULL;
    NodeCola<T>* tail = NULL;
    int length = 0;

public:
    int getLength();
    void push(T);
    T pop();
    bool isEmpty();
    void print();
    T front();
};
