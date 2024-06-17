#include<iostream>
#include "./class/list/list.cpp"

using namespace std;

int main(){
    List<int> listA;
    int a, b;


    int x[6]={5,4,3,7,8,6};

  
   
    for (int i = 0; i <6; i++)
    {
        listA.insert(x[i]);
    }

    cout<<endl<<"Elementos del lista original:"<<endl<<endl;
    listA.print(); cout<<endl;

    cout<<"Eligue el rango en que quieres que se guarden los nodos en la nueva lista:"<<endl<<endl;
    cout<<"Desde: "; cin>>a;
    cout<<"Hasta: "; cin>>b;
    cout<<endl;

    listA.insertRange(a, b); cout<<endl;
}