// Do...while first executes.
// Then checks condition.
// No counter, only condition.
// DIFFERENCE - Loop executes once even before checking condition!
#include <iostream>
#include <string>
using namespace std;

// Take input until a negative number is entered.

int main()
{
    cout << "Enter a number: ";
    int n;
    cin >> n;

    do
    {
        cout << n << endl;
        cin >> n;
    } while (n > 0);

    return 0;
}