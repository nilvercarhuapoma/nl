#include <iostream>
using namespace std;
float num(float);
int main(void)
{

    float x = 4.0;

    cout << "la multiplicacion es:" << x;
}
float num(float x)
{
    float result;
    result = x * x;
    return result;
}