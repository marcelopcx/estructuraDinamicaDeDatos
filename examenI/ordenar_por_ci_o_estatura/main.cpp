#include<iostream>
#include "./class/list/list.cpp"

using namespace std;

int main(){
    List<string> Person;
    char orden;

    string x[3]={"Marcelo","Andres","Daniel"};
    string y[3]={"31005749","30310971","28543271"};
    string z[3]={"179","182","178"};
   
    cout<<endl<<"Como quiere ordenar los datos, por CI o Tamaño (C/T): "; cin>>orden; cout<<endl;

    for (int i = 0; i <3; i++)
    {
        if (orden == 'C' || orden == 'c')
        {
            Person.insertC(x[i],y[i],z[i],orden);
        } else if (orden == 'T' || orden == 't')
        {
            Person.insertT(x[i],y[i],z[i],orden);
        }
    }

    Person.print(orden);
}