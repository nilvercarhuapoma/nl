#include <iostream>
#include <string>
using namespace std;
class Question
{
private:
    
    int var1;
    int var2;
    
public:
    Question(int _var1,int _var2) :var1(_var1),var2(_var2){}

void mostrar()
{
    cout << "el valor de var1 "<<var1<<endl;
    cout << "el valor de var2 "<<var2<<endl;
}
int getvar2()
{
    return var2;
}
void setvar2(int _var2)
{
    var2 = _var2;
}
};
int main()
{
    Question p1(4,2);
    p1.setvar2(6);
    p1.mostrar();
    
}
