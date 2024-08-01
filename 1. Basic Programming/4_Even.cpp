// Print all even numbers from 1 to N.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    for (int i = 2; i <= n; i = i + 2)
        cout << i << "  " << endl;

    return 0;
}