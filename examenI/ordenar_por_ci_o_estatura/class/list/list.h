#include "../node/node.cpp"
template<class T>
class List{
    private:
        Node<T> *head=NULL;
        int length=0;
    public:
        void insertC(T name, T ci, T tamano, char orden);
        void insertT(T name, T ci, T tamano, char orden);
        void insertFirst( Node<T> *node);
        bool deleteNode(T data);
        bool isEmpty();
        void print(char orden);
        bool update(int n, T data);

        void insertRange(T a, T b);
};