#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary1(int N)
{
    // Division Approach:
    cout << "(Calling 1 ...)" << endl;
    int binary = 0;
    int placeValue = 1;
    while (N > 0)
    {
        int bit = N % 2;
        N = N / 2;
        binary = binary + bit * placeValue;
        placeValue *= 10;
    }
    return binary;
}


int decimalToBinary2(int N)
{
    // Bitwise Approach:
    // Better as it is faster.
    cout << "(Calling 2 ...)" << endl;
    int binary = 0;
    int placeValue = 1;
    while (N > 0)
    {
        int bit = N & 1;
        N = N >> 1;

        binary = binary + bit * placeValue;
        placeValue *= 10;
    }
    return binary;
}


int main()
{
    int N;
    cout << "Enter a Decimal Number: ";
    cin >> N;
    int binary = decimalToBinary1(N);
    // int binary = decimalToBinary2(N);
    cout << "Binary Equivalent: " << binary << endl;
    return 0;
}