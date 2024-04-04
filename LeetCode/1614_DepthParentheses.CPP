#include <bits/stdc++.h>
using namespace std;

/********* LeetCode 1614: Maximum Nesting Depth of the Parentheses *********/
// Calculating the maximum depth of the nested parentheses.
// Given that the string is a valid parentheses string as solved in [LeetCode/20_ValidParentheses.cpp] file.


// ALGORITHM:
// 1) Create a stack.
// 2) Iterate string from back.
// 3) If closing bracket, push to stack. Else if opening bracket, pop it.
// 4) Keep maintaining `count` and `max_count`.
// 5) Return `max_count`.

// Time: O(n) as iterating for loop.
// Space: O(n) as creating a stack.

int maxDepth(string s)
{
    stack<char> st;
    int n = s.length();
    int count = 0;
    int max_count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ')') // Closing bracket.
        {
            st.push(s[i]);
            count++;
        }
        else if (s[i] == '(') // Opening bracket.
        {
            st.pop();
            count--;
        }
        max_count = max(count, max_count);
    }
    return max_count;
}

int main()
{
    string s = "(((b / 3 - 8))) + ((((1 + 7))))";
    int ans = maxDepth(s);
    cout << ans;

    return 0;
}