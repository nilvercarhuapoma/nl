#include <iostream>
#include <ctime>
#include <string>

using namespace std;

string obtenerFechaActual() {
    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

string obtenerFechaVencimiento(int diasLaborales) {
    time_t now = time(0);
    tm *timeinfo = localtime(&now);

    // Sumar los días laborales a la fecha actual
    int diasSumados = 0;
    while (diasSumados < diasLaborales) {
        timeinfo->tm_mday++;
        mktime(timeinfo);
        // Asegurarse de no contar los fines de semana
        if (timeinfo->tm_wday != 0 && timeinfo->tm_wday != 6) {
            diasSumados++;
        }
    }

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

int main() {
    cout << "Fecha actual: " << obtenerFechaActual() << endl;

    int diasLaborales;
    cout << "Ingrese la cantidad de días laborales deseados: ";
    cin >> diasLaborales;

    cout << "Fecha de vencimiento: " << obtenerFechaVencimiento(diasLaborales) << endl;

    return 0;
}
