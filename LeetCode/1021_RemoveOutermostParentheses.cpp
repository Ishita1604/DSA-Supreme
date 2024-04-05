#include <bits/stdc++.h>
using namespace std;

// APPROACH:
// 1. Opening bracket - Check non-empty, then push.
// 2. Closing bracket - Pop first, then check non-empty.
// If stack gets empty it means that bracket was outermost!

// Time: O(n) as iterating for loop.
// Space: O(n) as creating a stack.


string removeOuterParentheses(string s)
{
    stack<char> st;
    string ans = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(') // Opening bracket.
        {
            if (!st.empty()) // Non-empty means it is innermost opening bracket.
                ans.push_back(s[i]);
            st.push(s[i]); // Push into stack.
        }
        else // Closing bracket.
        {
            st.pop();
            if (!st.empty()) // Innermost closing bracket.
                ans.push_back(s[i]);
        }
    }
    return ans;
}


int main()
{
    string s = "(()())(())";
    string ans = removeOuterParentheses(s);
    cout << ans;

    return 0;
}