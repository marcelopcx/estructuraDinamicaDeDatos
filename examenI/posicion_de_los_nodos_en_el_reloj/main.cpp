#include<iostream>
#include "./class/list/list.cpp"

using namespace std;


int main(){
    List<int> list;


    int x[4]={5,4,3,7};

  
   
    for (int i = 0; i < 4; i++)
    {
        list.insert(x[i]);
    }


    cout<<endl; list.print(); cout<<endl;
    cout<<"Posición de los  nodos en las 12, 3, 5, 7:"<<endl<<endl;
    list.clockPositions(); cout<<endl;
}