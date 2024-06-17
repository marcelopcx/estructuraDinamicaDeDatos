#include<iostream>
#include "./node.h"
using namespace std;

template <class T>
Node<T>::Node(T name,T ci,T tamano,Node<T>* next){
    this->name=name;
    this->ci=ci;
    this->tamano=tamano;
    if(next!=NULL){
        this->next=next;
    }
}
template <class T>
Node<T>* Node<T>::getNextNode(char orden){
    return this->next;
}

template <class T>
void Node<T>::setNextNode(Node<T>* next){
     if(next!=NULL){
        this->next=next;
    }
}

template <class T>
void Node<T>::setData(T name,T ci,T tamano){

    this->name=name;
    this->ci=ci;
    this->tamano=tamano;
}


template <class T>
T Node<T>::getData(char orden){
    if (orden == 'C' || orden == 'c')
    {
        return this->ci;
    } else if (orden == 'T' || orden == 't')
    {
        return this->tamano;
    } else
    {
        return this->name;
    }
    
}

template<class T>
void Node<T>::print(){
    cout<<this->name<<endl;
    cout<<this->ci<<endl;
    cout<<this->tamano<<endl<<endl;
}
template <class T>
Node<T>::~Node(){
    next=NULL;
}