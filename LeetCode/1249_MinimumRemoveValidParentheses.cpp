#include <bits/stdc++.h>
using namespace std;

// APPROACH:
// 1. Opening bracket -
// 2. Closing bracket and pair found - Pop.
// If stack gets empty it means that bracket was outermost!

// Time: O(n) as iterating for loop.
// Space: O(n) as creating a stack.


string minRemoveToMakeValid(string s)
{
    stack<int> st; // We store indices in stack, for later deletion.
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i); // Push opening bracket.
        else if (s[i] == ')')
        {
            if (!st.empty() && s[st.top()] == '(')
                st.pop(); // Pop as pair found.
            else
                st.push(i); // Character on top of stack, so simply push the closing bracket.
        }
    }
    while (!st.empty())
    {
        s.erase(st.top(), 1);
        st.pop();
    }
    return s;
}


int main()
{
    string s = "lee(t(c)o)de)";
    string ans = minRemoveToMakeValid(s);
    cout << ans;

    return 0;
}