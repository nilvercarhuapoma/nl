// 1-	Manejo de Arreglos
#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int num[n];
    double average;
    int sum = 0;
    int greater = 0;
    cout << "enter 10 numbers:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "number:" << i + 1 << " : ";
        cin >> num[i];
        sum += num[i];
    }
    average = static_cast<float>(sum) / n;
    cout << "the average is:" << average<<endl;
    
    for (int i = 0; i < n; ++i)
        
    {
        if (num[i] > average)
            
        {
            greater++;
        }
    }
    cout << "the number of numbers greater than the average:" << greater;
    return 0;
}