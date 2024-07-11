#include <bits/stdc++.h>
using namespace std;

// Time: O(N) in for loop and reverse string function.
// Space: O(N) for stack and string.
string reverseParentheses(string s)
{
    stack<char> st;
    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        vector<char> ch;
        if (s[i] != ')')
            st.push(s[i]);
        else
        {
            while (st.top() != '(')
            {
                ch.push_back(st.top());
                st.pop();
            }
            st.pop(); // To remove the '(' from stack.
            for (char c : ch)
                st.push(c);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "(ed(et(oc))el)";
    string ans = reverseParentheses(s);
    cout << ans << endl;

    return 0;
}