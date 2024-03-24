/****    LeetCode 2864: Maximum Odd Binary Number    ****/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int n = s.length();
        string ans(n, '0');
        ans[n - 1] = '1'; // As input string always contains one '1'.
        int count = 0;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                count++;
        }
        while (count > 1)
        {
            ans[j] = '1';
            j++;
            count--;
        }
        return ans;
    }
};


int main()
{
    string s = "11100";
    Solution obj;
    string ans = obj.maximumOddBinaryNumber(s);
    cout << ans;

    return 0;
}