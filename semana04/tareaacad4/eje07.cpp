// 7-	Eliminación de Duplicados:
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
void eliminarelementos(int A[], int *n)
{
    int i, j, k;
    for (i = 0; i < *n; i++)
    {
        j = i + 1;
        while (j < *n)
        {
            if (A[i] == A[j])
            {
                for (k = j; k < *n - 1; k++)
                {
                    A[k] = A[k + 1];
                }
                (*n)--;
            }
            else
            {
                j++;
            }
        }
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 4, 3, 7, 6, 2, 4, 6, 9};
    int n = sizeof(A) / sizeof(A[0]);
    int i;
    cout<<"arreglo original:\t"<<endl;
    for (i = 0; i < n; i++)
    {
                cout<< A[i]<<"\t";
    }
    eliminarelementos(A, &n);
    cout<<"\narreglos sin elementos repetidos:"<<endl;
    for (i = 0; i < n; i++)
    {
        cout<< A[i]<<"\t";
    }
    cout<<"\n";
    return 0;
}
