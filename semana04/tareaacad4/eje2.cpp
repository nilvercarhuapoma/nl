// Palíndromos
#include <iostream>
#include <string>
using namespace std;

   bool palindromo(string palabra)
    {
        int inicio = 0;
        int fin = palabra.length() - 1;
        while (inicio < fin)
        {
            if (palabra[inicio] != palabra[fin])
            {
                return false;
            };
            inicio++;
            fin--;
        }
        return true;
    }
    int main()
    {
        string palabra;
        cout << "ingresa una palabra:";
        getline(cin, palabra);
        if (palindromo(palabra))
        {
            cout << " " << palabra << " :es un palindromo";
        }
        else
        {
            cout << " " << palabra << " no es palindromo";
        }

       return 0; 
    }
   

