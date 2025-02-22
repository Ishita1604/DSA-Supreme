#include <bits/stdc++.h>
using namespace std;

// Print factorial of a number using recursion.
// Uncomment statements to understand flow of recursion logic.

int fact(int n)
{
    // cout << "Function called for N = " << n << endl;
    // Base case:
    if (n == 1)
    {
        // cout << "Base value returned: " << n << endl;
        return 1;
    }
    // Recursive relation.
    int ans = n * fact(n-1);
    // cout << "Value returned: " << ans << endl;
    return ans;
}


int main()
{
    int n, ans;
    cout << "Enter a number to calculate factorial: ";
    cin >> n;
    
    ans = fact(n);
    cout << n << "! is = " << ans << endl;

    return 0;
}
