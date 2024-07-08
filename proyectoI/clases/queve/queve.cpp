#include <iostream>
#include <memory>  // Include for std::unique_ptr
#include "./queve.h"
#include "../stack/stack.h"
#include "queve.h"

using namespace std;

template<class T>
bool Queue<T>::isEmpty()
{
   return this->head==NULL;
}

template <class T>
void Queue<T>::push(T data)
{       
   NodeCola <T> *node = new NodeCola<T>(data,NULL);
   if(isEmpty())
   {
      head=node;
      tail=node;
      this->length++;
      return;
   }
   tail->setNextNode(node);
   tail=node;
   this->length++;
}

template<class T>
T Queue<T>::pop(){
   T data;

   if(isEmpty())
   {
      return data;
   }

   NodeCola<T> *node = head;

   head=head->getNextNode();
   data = node->getData();

   delete node;
   this->length--;

   return data;
}

template<class T>
void Queue<T>::print()
{
   while(!isEmpty()) {

      cout<<pop()<<endl;
   }
}

template <class T>
T Queue<T>::front()
{
   while(!isEmpty())
   {
      return head->getData();
   }
   return 0;
}

template<class T>
int Queue<T>::getLength()
{
   return this->length;
}

// Metodos de Ordenamiento

template<class T>
T Queue<T>::obtenerMin(Queue<T>& colaOriginal, Queue<T>& colaAuxiliar) {
   int originalSize = colaOriginal.getLength();
   T min = colaOriginal.pop(); // Inicializamos min con el primer elemento

   // Verificamos si la cola original está vacía
   if (originalSize == 0) {
      throw runtime_error("La cola original está vacía.");
   }

   // Encuentra el mínimo en la cola original
   for (int i = 1; i < originalSize; i++) {
      T data = colaOriginal.pop();
      if (data < min) {
         colaOriginal.push(min); // Agregar el mínimo a la cola original
         min = data; // Actualizar el mínimo

      } else {
         colaOriginal.push(data); // Agregar otros elementos a la cola original
      }
   }
   return min;
}

template<class T>
Queue<T> Queue<T>::ordenarCola(Queue<T>& colaOriginal)
{
   Queue<T> colaAuxiliar;

   while (!colaOriginal.isEmpty()) 
   {
      T min = obtenerMin(colaOriginal, colaAuxiliar); // Obtén el mínimo de la cola original
      colaAuxiliar.push(min); // Agrega el mínimo a la cola auxiliar
   }

   return colaAuxiliar;
}
