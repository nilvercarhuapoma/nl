#include<iostream>
#include<string>
using namespace std;
int main(){
   int a;
   string e[4];
    cout<<"ingrese 3 nombres\n";
    for(a=0;a<3;a++)
    {
        cout<<"ingrese el nombre "<<a + 1<<" : ";
        cin>>e[a];
    }
    cout<<"los estudiantes son de la FIIS\n";
    return 0;

}