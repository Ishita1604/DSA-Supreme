#include <bits/stdc++.h>
using namespace std;

// Reverse a given string using stack.
// Implemented using the print and pop logic.

int main()
{
    string str = "Ishita";
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
        st.push(str[i]);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}