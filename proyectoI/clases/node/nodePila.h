#pragma once

template<class T>
class NodePila {
private:
    T data;
    NodePila<T>* next = NULL;

public:
    NodePila(T, NodePila<T>*);
    ~NodePila();
    NodePila<T>* getNextNode();
    void setData(T);
    T getData();
    void setNextNode(NodePila<T>*);
    void print();
};
