#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << "Factorial of " << n << " is " << fact << endl;

    return 0;
}
