#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
int main()
{
    vector<int> A = {1, 2, 5, 6, 3, 12, 4, 16, 0, 7, 9};
    
    if (A.empty())
    {
        cout << "el valor vacio.";
        return 1;
    }
    int mayor = A[0];
    for (size_t i= 1; i < A.size(); i++)
    {
        if (A[i] >mayor)
        {
            mayor = A[i];
        }
    }
    cout << "el numero mayor del vector es:" << mayor;
    return 0;
}
