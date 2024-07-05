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
   Node<T>* node = new Node<T>(data, head);
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

   Node<T>* node = head;

   head = head->getNextNode();
   data = node->getData();

   delete node;
   return data;
}

template<class T>
void Stack<T>::print()
{ 
   while(!isEmpty())
   {
      cout<< pop() <<endl;
   }
}