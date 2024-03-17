/**** Division of Two Numbers using Binary Search ****/
// Works for both negative and positive numbers!

#include <bits/stdc++.h>
using namespace std;

long long division(int D, int d)
{
    // D = d * q + r
    // D >= d * q
    long long start = 0;
    long long end = abs(D);
    long long mid = (start + end) / 2;
    long long ans = 0;

    while (start <= end)
    {
        if (abs(d) * mid == abs(D))
        {
            ans = mid;
            break;
        }
        else if (abs(d) * mid > abs(D))
            end = mid - 1; // Search in left.
        else
        {
            ans = mid;
            start = mid + 1; // Search in right.
        }
        mid = (start + end) / 2;
    }

    if ((d < 0 && D < 0) || (d > 0 && D > 0))
        return ans;
    else
        return (ans * -1);
}

int main()
{
    long long D = 23; // Dividend
    long long d = -3; // Divisor
    if (d == 0)
        cout << "Division by zero is undefined!\n\n";
    else
    {
        long long q = division(D, d); // Quotient
        cout << q << endl;
    }

    return 0;
}