#include <iostream>
using namespace std;

// Reverse the digits of given number.

int main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    int reverse = 0;

    while (n > 0)
    {
        int last_digit = n % 10;
        reverse = reverse * 10 + last_digit;
        n = n / 10;
    }
    cout << reverse << endl;

    return 0;
}