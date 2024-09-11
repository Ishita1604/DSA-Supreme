#include <bits/stdc++.h>
using namespace std;

// ALGORITHM:
// If the character is opening bracket, simply push its index.
// If the character is closing bracket, pop the topmost element.
// If stack becomes empty, push current index.
// Else, calculate current valid length i.e. the difference between current index and the topmost.

// TIME: O(N) where N is length of string.
// SPACE: O(N) due to stack.

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1); // Initialize stack with -1.
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char chStr = s[i];
        if (chStr == '(')
            st.push(i);
        else if (chStr == ')')
        {
            if (!st.empty()) st.pop();
            // If stack becomes empty after popping top-most, push current index instead of -1.
            // As no valid opening bracket left to pair with current closing bracket.
            // Next valid pair(s) would start from subsequent characters, so push current index as "new reference".
            if (st.empty()) st.push(i);
            else
            {
                int len = i - st.top();    // Calculate current length.
                maxLen = max(len, maxLen); // Store the maximum length so far.
            }
        }
        else continue;
    }
    return maxLen;
}

int main()
{
    // string s = "()()()(()(()())";
    string s = "))))";
    int res = longestValidParentheses(s);
    cout << res << endl;

    return 0;
}