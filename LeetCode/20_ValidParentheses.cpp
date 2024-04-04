#include <bits/stdc++.h>
using namespace std;

// Time: O(n) as iterating for loop.
// Space: O(n) as creating a stack.


bool isValid(string s)
{
    stack<int> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') // Opening bracket.
            st.push(s[i]);
        else // Closing bracket.
        {
            if (!st.empty())
            {
                char c = st.top();
                st.pop();
                if ((c == '(' && s[i] == ')') || (c == '{' && s[i] == '}') || (c == '[' && s[i] == ']')) // Check if opening-closing pair.
                    continue;
                else
                    return false;
            }
            return false; // No bracket exists for that closing bracket.
        }
    }
    // Out of loop without returning false.
    if (st.empty())
        return true; // And stack is empty, means the string is a valid parentheses.
    else
        return false;
}



int main()
{
    string s = "[()]{}[";
    bool ans = isValid(s);
    if (ans)
        cout << "True";
    else
        cout << "False";

    return 0;
}