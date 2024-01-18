// 4-	Sucesión de Collatz:
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "ingrese un numero entero positivo:";
    cin >> n;
    cout << " la sucesion de collatz es:\n";
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n * 3 + 1;
        }

        cout << "\t" << n;
    }

    return 0;
}
