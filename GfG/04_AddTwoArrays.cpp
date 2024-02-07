#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string calc_Sum(int *a, int n, int *b, int m)
    {
        string ans;
        int i = n - 1;
        int j = m - 1;
        int carry = 0;

        while ((i >= 0) && (j >= 0))
        {
            // Equal number of digits in both arrays.
            int add = a[i] + b[j] + carry;
            int digit = add % 10;
            carry = add / 10;
            ans.push_back(digit + '0');
            i--;
            j--;
        }

        while (i >= 0)
        {
            // More number of digits in first array.
            int add = a[i] + 0 + carry;
            int digit = add % 10;
            carry = add / 10;
            ans.push_back(digit + '0');
            i--;
        }

        while (j >= 0)
        {
            // More number of digits in second array.
            int add = 0 + b[j] + carry;
            int digit = add % 10;
            carry = add / 10;
            ans.push_back(digit + '0');
            j--;
        }

        if (carry)
            ans.push_back(carry + '0');

        // Before reversing, there might be zero at the end of the answer string.
        // After reversing, that 0 comes at beginning & has no significance.
        // Pop the trailing 0's:
        while (ans[ans.size() - 1] == '0')
            ans.pop_back();

        // Reverse the answer string:
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    Solution ob;
    cout << ob.calc_Sum(a, n, b, m) << endl;

    return 0;
}