#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 5;
using namespace std;

void mostrar(int x[])
{
    int y = x;
    for (const auto &elemento : v)
    {
        cout << elememnto << endl;
    }
    void llenar()
    {
    }
    void ordenarburbuja(int v[])
    {
        bool band = true;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                if (v[i] > v[j])
                    ;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    int main()
    {
        int v[] = {1, 2, 3, 4, 5};
        mostrar(v);
    }