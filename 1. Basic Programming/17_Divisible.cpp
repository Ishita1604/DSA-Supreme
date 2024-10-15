#include <iostream>
using namespace std;

// Check if a number is divisible by 2 and 3 or by only one of them.

int main()
{
    int num;
    cin >> num;
    if (num % 2 == 0 && num % 3 == 0)
        cout << "Divisible by both" << endl;
    else if (num % 2 == 0 || num % 3 == 0)
        cout << "Divisible by only one" << endl;
    else
        cout << "Divisible by none" << endl;

    return 0;
}
