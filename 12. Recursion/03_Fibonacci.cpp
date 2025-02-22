#include <bits/stdc++.h>
using namespace std;

// Program to print Nth Fibonacci number using recursion.

int fib(int n)
{
    // Base case.
    if (n == 1) return 0;
    if (n == 2) return 1;
    // Recursive call.
    int ans = fib(n-1) + fib(n-2);
    // Processing.
    return ans;
}

int main()
{
    int n;
    cout << "Enter the term you want to see in Fibonacci: ";
    cin >> n;
    cout << n << "th Fibonacci number is: " << fib(n);

    return 0;
}
