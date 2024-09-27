// While loop:
// "n" as well as "counter" not defined .
// Keep executing till the condition is true.
// First check condition true or false, then execute
#include <iostream>
#include <string>
using namespace std;

// Input a number until user enters a negative number.

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    while (n >= 0)
    {
        cout << n << endl;
        cin >> n;
    }

    return 0;
}