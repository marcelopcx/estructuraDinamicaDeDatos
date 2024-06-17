#include<iostream>
#include "./list.h"
#include <string>

using namespace std;

template<class T>
bool List<T>::isEmpty(){
    return this->head==NULL;
}
template<class T>
void List<T>::insertFirst(Node<T> *node){
        Node <T> *temp = head;
        head=node;
        head->setNextNode(temp);
}

template<class T>
void List<T>::insertC(T name, T ci, T tamano, char orden){
    
    Node<T> *newNode =new Node<T>(name,ci,tamano,NULL);
   // Si la lista está vacía, insertar al principio:
      if(isEmpty()) {
         insertFirst(newNode);
      }
      else {
         Node<T> *actual = head;
         Node<T> *last = NULL;
         // Buscar el nodo anterior al primer nodo con un dato mayor qur 'data'
         while(actual!=NULL && actual->getData(orden) < ci) {
            last = actual;
            actual = actual->getNextNode(orden);
         }
         // Si no hay el nodo anterior apunta a nada, insertar al principio,
         // nuestro nuevo dato es el menor de la lista:
         if(last==NULL){
            insertFirst(newNode);
         }
         else{ // caso contrario insertar en su respectiva posicion en la lista:
         newNode->setNextNode(last->getNextNode(orden));
         last->setNextNode(newNode);}
      }
      this->length++;
}

template<class T>
void List<T>::insertT(T name, T ci, T tamano, char orden){
    
    Node<T> *newNode =new Node<T>(name,ci,tamano,NULL);
   // Si la lista está vacía, insertar al principio:
      if(isEmpty()) {
         insertFirst(newNode);
      }
      else {
         Node<T> *actual = head;
         Node<T> *last = NULL;
         // Buscar el nodo anterior al primer nodo con un dato mayor qur 'data'
         while(actual!=NULL && actual->getData(orden) < tamano) {
            last = actual;
            actual = actual->getNextNode(orden);
         }
         // Si no hay el nodo anterior apunta a nada, insertar al principio,
         // nuestro nuevo dato es el menor de la lista:
         if(last==NULL){
            insertFirst(newNode);
         }
         else{ // caso contrario insertar en su respectiva posicion en la lista:
         newNode->setNextNode(last->getNextNode(orden));
         last->setNextNode(newNode);}
      }
      this->length++;
}

template<class T>
void List<T>::print(char orden){
     Node <T> *actual = head;
  
      for (size_t i = 0; i < length; i++)
      {
        actual->print();
        actual = actual->getNextNode(orden);
      }
}