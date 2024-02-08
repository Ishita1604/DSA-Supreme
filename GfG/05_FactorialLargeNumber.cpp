// Time Complexity : O(N^2)
// Auxilliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] << "";
}

class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;

        for (int i = 2; i <= N; i++) // Outer loop to iterate from 2 to that number.
        {
            for (int j = 0; j < ans.size(); j++) // Inner loop to multiply each digit in `ans` with current `i`.
            {
                int x = ans[j] * i + carry;
                ans[j] = x % 10;
                carry = x / 10;
            }

            while (carry) // If exists.
            {
                // It could be large and we will store it digit-wise.
                ans.push_back(carry % 10);
                carry = carry / 10;
            }
            carry = 0; // Before it goes to the next iteration of `i`, reset `carry` to 0.
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    cout << "Enter the Number: ";
    int n;
    cin >> n;
    vector<int> ans;
    Solution obj;
    ans = obj.factorial(n);

    printVector(ans);

    return 0;
}