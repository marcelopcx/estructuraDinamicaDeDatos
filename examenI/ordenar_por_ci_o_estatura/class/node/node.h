template<class T>
class Node{
    private:
        T name;
        T ci;
        T tamano;
        Node<T> *next=NULL;
    public:
        Node(T,T,T,Node<T>*);
        ~Node();
        Node<T>* getNextNode(char orden);
        void setData(T name,T ci,T tamano);
        T getData(char orden);
        void setNextNode(Node<T>*);
        void print();
};