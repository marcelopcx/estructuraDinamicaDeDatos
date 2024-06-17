#include<iostream>
#include "./list.h"
#include <string>

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
void List<T>::insert(T data){
    
    Node<T> *newNode =new Node<T>(data,NULL);
   // Si la lista está vacía, insertar al principio:
   if(isEmpty()) {
        insertFirst(newNode);
   }
   else {
      Node<T> *actual = head;
      Node<T> *last = NULL;
      // Buscar el nodo anterior al primer nodo con un dato mayor qur 'data'
      while(actual!=NULL && actual->getData() < data) {
         last = actual;
         actual = actual->getNextNode();
      }
      // Si no hay el nodo anterior apunta a nada, insertar al principio,
      // nuestro nuevo dato es el menor de la lista:
      if(last==NULL){
         insertFirst(newNode);
      }
      else{ // caso contrario insertar en su respectiva posicion en la lista:
        newNode->setNextNode(last->getNextNode());
        last->setNextNode(newNode);}
   }
   this->length++;
}

template<class T>
bool List<T>::deleteNode(T data){

   if(isEmpty()){
      return false;
   }

   Node<T>* NodeToDelete=head;

   Node<T>* last=NULL;

   //ubicamos el nodo a borrar
   while (NodeToDelete!=NULL && NodeToDelete->getData()!=data)
   {
      last=NodeToDelete;
      NodeToDelete=NodeToDelete->getNextNode();
   }

   //Si no se encuentra, no se elimina
   //caso contrario, si el puntero al ultimo apunta a null, entonces borraremos el apuntado por head;
   //si no apunta a NUll el siguiente al que apuntara sera el siguiente del nodo a borrar.
   if(NodeToDelete!=NULL){
      if(last==NULL){
         head=NodeToDelete->getNextNode();
      }
      else{
         last->setNextNode(NodeToDelete->getNextNode());
      }


      delete NodeToDelete;
      this->length--;
      return true;
   }
   
   return false;
}
template<class T>
bool List<T>::update(int n, T data){
   if(isEmpty() || n > this->length){
      return false;
   }
   Node<T> *nodeToUpdate = head;
   Node<T> *last = NULL;
    Node<T> *next = NULL;


   //ubicamos el nodo para actualizar
   for (int i = 0; i < n; i++)
   {
      last=nodeToUpdate;
      nodeToUpdate=nodeToUpdate->getNextNode();
   }

   //Comprobamos si al modificar el dato se altera el orden de la lista.

   T oldData= nodeToUpdate->getData();
   next=nodeToUpdate->getNextNode();
   T nextData;
   T lastData;
   if(next==NULL){
      
      lastData=last->getData();
      if(lastData>data){
         deleteNode(oldData);
         insert(data);
         
      }else{
         nodeToUpdate->setData(data);
      }
      return true;
   }

   if(last==NULL){
      nextData=next->getData();
      if(nextData<data){
         deleteNode(oldData);
         insert(data);
         
      }else{
         nodeToUpdate->setData(data);
      }

      return true;
   }

   lastData=last->getData();
   nextData=next->getData();

   if(lastData<=data && data<=nextData){
      nodeToUpdate->setData(data);
    
     
   }else{
   
      deleteNode(oldData);
      insert(data);
   
   }
  
   return true;
}
template<class T>
void List<T>::print(){
     Node <T> *actual = head;
  
      while(actual!=NULL) {
        actual->print();
        actual = actual->getNextNode();
      }
}

template <class T>
void List<T>::insertRange(T a, T b)
{
   List<float> listB;

   Node<T> *current = head;
   Node<T> *next;

    // Encuentra el primer nodo dentro del rango para eliminar
    while (current != NULL && current->getData() < a) {
        current = current->getNextNode();
    }

    // Elimina los nodos dentro del rango [a, b]
    while (current != NULL && current->getData() <= b) {
        next = current->getNextNode();
        listB.insert(current->getData());
        current = next;
    }

    listB.print();
}