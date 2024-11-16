#include <iostream>
using namespace std;

int binaryToDecimal1(int N)
{
    // Division Method
    cout << "(Calling 1 ...)" << endl;
    int decimal = 0;
    int placeValue = 1; // As place value starts from 2 raised to power 0, which is 1.
    while (N > 0)
    {
        int bit = N % 10;
        decimal = decimal + bit * placeValue;
        N /= 10;
        placeValue *= 2;
    }
    return decimal;
}

int binaryToDecimal2(int N)
{
    // Bitwise Method
    cout << "(Calling 2 ...)" << endl;
    int decimal = 0;
    int placeValue = 1;
    while (N > 0)
    {
        int bit = N & 1;
        N = N >> 1;
        decimal = decimal + bit * placeValue;
        placeValue *= 2;
    }
    return decimal;
}

int main()
{
    int N;
    cout << "Enter a Binary Number: ";
    cin >> N;
    int decimal = binaryToDecimal1(N);
    // int decimal = binaryToDecimal2(N);
    cout << "Decimal Equivalent: " << decimal << endl;

    return 0;
}