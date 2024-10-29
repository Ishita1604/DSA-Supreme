#include <iostream>
using namespace std;

// Left Shift and Right Shift operators in C++.

// (N << a) will give result as (N * 2^a).
// (N >> a) will give result as (N / 2^a).

// If a is -ve, result is a garbage value.


int main()
{
    int left_shift, right_shift;

    left_shift = 4 << 1;  // Left operand's bits are moved left by the number of places specified by the right operand.
    right_shift = 4 >> 1; // Left operand's bits are moved right by the number of places specified by the right operand.

    cout << left_shift << endl;
    cout << right_shift << endl;

    return 0;
}