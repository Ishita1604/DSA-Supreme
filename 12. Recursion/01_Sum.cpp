#include <bits/stdc++.h>
using namespace std;

// Print the sum of the first n natural numbers using recursion.
// ∑(n) = ∑(n-1) + n

int printSum(int n)
{
    if (n == 1) return 1;
    return printSum(n-1) + n;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers is: " << printSum(n);

    return 0;
}
