#include <bits/stdc++.h>
using namespace std;

// Time: 0(n) as the for loop.
// Space: O(n) for the stack.


string makeGood(string s)
{
    stack<char> st;
    int n = s.length();
    string good_string = "";

    if (s == "")
        return s;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }
        if ((s[i] == st.top() + 32) || (s[i] == st.top() - 32)) // Uppercase-lowercase or vice-versa pair found.
            st.pop();
        else
            st.push(s[i]);
    }
    while (!st.empty())
    {
        good_string += st.top();
        st.pop();
    }
    reverse(good_string.begin(), good_string.end());
    return good_string;
}


int main()
{
    string s = "leEeetcode";
    string good_string = makeGood(s);
    cout << good_string;
    return 0;
}