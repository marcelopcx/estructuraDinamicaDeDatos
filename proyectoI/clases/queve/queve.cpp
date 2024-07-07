#include<iostream>
#include "./queve.h"
#include "../stack/stack.h"

using namespace std;

template<class T>
bool Queue<T>::isEmpty()
{
   return this->head==NULL;
}
template<class T>
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

template<class T>
int Queue<T>::getLength()
{
   return this->length;
}

template<class T>
T Queue<T>::obtenerMin(Queue<T> colaOriginal, Queue<T> colaAuxiliar, T min)
{
   int originalSize = colaOriginal.getLength(); // Guarda el tamaño original de la cola
   T data;

   // Encuentra el mínimo en la cola original
   for (int i = 0; i < originalSize; i++)
   {
      data = colaOriginal.pop();
      if (data < min)
      {
         colaAuxiliar.push(min); // Agregar el mínimo a la cola auxiliar
         min = data; // Actualizar el mínimo
      } else 
      {
         colaAuxiliar.push(data); // Agregar otros elementos a la cola auxiliar
      }
   }
   
   return min;
}

template <class T>
Queue<T> Queue<T>::ordenarCola(Queue<T> colaOriginal)
{
   Queue<T> colaAuxiliar;
   T min;

   while (!colaOriginal.isEmpty())
   {
      min = colaOriginal.pop();
      colaAuxiliar.push(obtenerMin(colaOriginal, colaAuxiliar, min));
   }
   
   return colaAuxiliar;
}