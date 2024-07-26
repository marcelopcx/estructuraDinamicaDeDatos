#include<iostream>
#include "./nodePila.h"
using namespace std;

template <class T>
NodePila<T>::NodePila(T data, NodePila<T>* next){
    this->data=data;
    if(next!=NULL){
        this->next=next;
    }
}

template <class T>
NodePila<T>* NodePila<T>::getNextNode(){
    return this->next;
}

template <class T>
void NodePila<T>::setNextNode(NodePila<T>* next){
     if(next!=NULL){
        this->next=next;
    }
}

template <class T>
void NodePila<T>::setData(T data){
    this->data=data;
}


template <class T>
T NodePila<T>::getData(){
   return this->data;
}

template<class T>
void NodePila<T>::print(){
    cout<<this->data<<endl; //solo para datos simples
}

template <class T>
NodePila<T>::~NodePila(){
    next=NULL;
}