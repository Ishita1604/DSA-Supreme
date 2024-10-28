#include <iostream>
using namespace std;

// Check if given number is an Armstrong number, or not.

int main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    int sum = 0;

    while (n > 0)
    {
        int last_digit = n % 10;
        int cube = last_digit * last_digit * last_digit;
        sum = sum + cube;
        n = n / 10;
    }
    cout << sum << endl;
    if (n == sum) cout << "Armstrong number!";
    else out << "Not Armstrong number!";

    return 0;
}