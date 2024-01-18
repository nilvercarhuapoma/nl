// 6-	Juego de Preguntas y Respuestas:
#include <iostream>
#include <string>
using namespace std;
int main()
{   
    int correcto = 0, incorrecto = 0;
    string respuesta = "";
    cout << "responda las siguientes preguntas:\n";
    cout << "1._el rio mas grande del mundo es el amazonas(si/no)?\n";
    cin >> respuesta;
    for (char &c : respuesta) {
        c = tolower(c);
    }
    if (respuesta == "si")
    {
        correcto++;
    }
    else
        incorrecto++;
    cout << "2._este -8+2=6 (si/no)?\n ";
    cin >> respuesta;
    for (char &c : respuesta) {
        c = tolower(c);
    }
    if (respuesta == "no")
    {
        correcto++;
    }
    else
        incorrecto++;
    cout << "3._H2O es el agua(si/no)?\n ";
    cin >> respuesta;
    for (char &c : respuesta) {
        c = tolower(c);
    }
    if (respuesta == "si")
    {
        correcto++;
    }
    else
        incorrecto++;
    cout << "tienes\t" << correcto << "\tcorrectas y\t" << incorrecto << "\tincorrectas";
    return 0;
}