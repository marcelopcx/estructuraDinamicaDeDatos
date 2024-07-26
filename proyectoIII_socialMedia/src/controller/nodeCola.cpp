#include<iostream>
#include "../model/nodeCola.hpp"
using namespace std;

template <class T>
NodeCola<T>::NodeCola(T data, NodeCola<T>* next){
    this->data=data;
    if(next!=NULL){
        this->next=next;
    }
}

template <class T>
NodeCola<T>* NodeCola<T>::getNextNode(){
    return this->next;
}

template <class T>
void NodeCola<T>::setNextNode(NodeCola<T>* next){
     if(next!=NULL){
        this->next=next;
    }
}

template <class T>
void NodeCola<T>::setData(T data){
    this->data=data;
}


template <class T>
T NodeCola<T>::getData(){
   return this->data;
}

template<class T>
void NodeCola<T>::print(){
    cout<<this->data<<endl;
}

template <class T>
NodeCola<T>::~NodeCola(){
    next=NULL;
}