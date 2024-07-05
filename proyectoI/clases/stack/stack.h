#include "../node/node.cpp"
template<class T>
class Stack{
    private:
        Node<T> *head=NULL;
        int length=0;
    public:
        void push(T);
        T pop();
        bool isEmpty();
        void print();
};