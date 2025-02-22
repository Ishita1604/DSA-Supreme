#include <bits/stdc++.h>
using namespace std;

// Print x^n recursively, ensuring the height of the stack is n.
// TIME: O(N)
// SPACE: O(N)

int calcPower(int x, int n)
{
    if (n == 0) return 1;
    if (x == 0) return 0;
    int xPown = x * calcPower(x, n - 1);
    return xPown;
}

int main()
{
    int x = 3;
    int n = 4;
    cout << x << "^" << n << " = " << calcPower(x, n);

    return 0;
}