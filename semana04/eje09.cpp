#include <iostream>
using namespace std;
int main()
{
    // lower(continuar)

    int n1, n2, answer;
    char op;
    do
    {
        cout << "write 2 numebers:" << endl;
        cin >> n1 >> n2;
        answer = n1 + n2;
        cout << " tha sum of " << n1 << " + " << n2 << " is iqual to " << answer;

        cout << " do you witch to continue?(s/n):";
        cin >> op;
        op = tolower(op);
    } while (op == ' s ');
    cout << "ok,see you soon";

    return 0;
}