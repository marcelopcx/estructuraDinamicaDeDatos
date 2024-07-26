#pragma once

template<class T>
class NodeCola {
private:
    T data;
    NodeCola<T>* next = NULL;

public:
    NodeCola(T, NodeCola<T>*);
    ~NodeCola();
    NodeCola<T>* getNextNode();
    void setData(T);
    T getData();
    void setNextNode(NodeCola<T>*);
    void print();
};
