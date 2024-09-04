#include <bits/stdc++.h>
using namespace std;

// ALGORITHM:
// If string's character is opening bracket, simply push in stack.
// Else it's closing bracket, check if stack's top and the string's character form a valid open-close pair.
// If yes, pop the top, making sure stack wasn't empty. Else return false.
// At end if stack becomes empty, parentheses are valid, else not.

// TIME: O(N) for N characters in the string.
// SPACE: O(N) as stack is created.

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char chStr = s[i];
        if (chStr == '(' || chStr == '{' || chStr == '[') // The string's character is opening bracket.
        {
            st.push(chStr);
        }
        else // The string's character is closing bracket.
        {
            if (st.empty()) return false;
            char chTop = st.top();
            if (chTop == '(' && chStr == ')' || chTop == '{' && chStr == '}' || chTop == '[' && chStr == ']')
            {
                // Valid open-close pair exists.
                st.pop();
            }
            else return false;
        }
    }
    if (st.empty()) return true;
    else return false;
}

int main()
{
    string s = "{([a+b])}";

    if (isValid(s)) cout << "Valid" << endl;
    else cout << "Invalid" << endl;

    return 0;
}