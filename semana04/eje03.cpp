#include <iostream>
using namespace std;
int main()
{
    int a, b, c, max;
    cout << "ingrese 3 numeros:"<<endl;
    cin >> a>>b>>c;
    max = a;
    if (b > max)
        max = b;
    if (c>max){
        max = c;
    }else{
        cout<<max;
    }
    cout << "el numero maximo es:" << max;

    return 0;
}