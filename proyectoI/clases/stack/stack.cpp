#include<iostream>
#include "./stack.h"

using namespace std;

template<class T>
bool Stack<T>::isEmpty(){
    return this->head==NULL;
}

template <class T>
void Stack<T>::push(T data)
{
   NodePila<T>* node = new NodePila<T>(data, head);
   head = node;
}

template <class T>
T Stack<T>::pop()
{
   T data;
   if (isEmpty())
   {
      return data;
   }

   NodePila<T>* node = head;

   head = head->getNextNode();
   data = node->getData();

   delete node;
   return data;
}

template <class T>
T Stack<T>::top()
{
   while(!isEmpty())
   {
      return head->getData();
   }
   return 0;
}

template<class T>
void Stack<T>::print()
{ 
   while(!isEmpty())
   {
      cout<< pop() <<endl;
   }
}

template<class T>
Stack<T> Stack<T>::ordenarPila(Stack<T> pilaOriginal)
{
    Stack<T> pilaAuxiliar;

    while (!pilaOriginal.isEmpty())
    {
        T min = pilaOriginal.pop();

        while (!pilaAuxiliar.isEmpty() && pilaAuxiliar.top() < min)
        {
            pilaOriginal.push(pilaAuxiliar.pop());
        }

        pilaAuxiliar.push(min);
    }

    return pilaAuxiliar;
}
