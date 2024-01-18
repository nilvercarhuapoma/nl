// 5-	Cifrado Cesar:
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int main()
{

    void cifrado();
    cifrado();
    return 0;
}
void cifrado()
{
    int clave;
    char text[100];
    cout << "ingrese un texto:";
    cin.ignore();
    cin.getline(text, 100);

    cout << "ingrse la clave:";
    cin >> clave;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + clave) % 26 + base;
        }
    }

    cout << "el cifrado es :" << text;
    getch();
}
