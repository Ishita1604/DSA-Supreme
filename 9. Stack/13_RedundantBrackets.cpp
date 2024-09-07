#include <bits/stdc++.h>
using namespace std;

// Check if expression contains redundant brackets or not.
// Link: [https://www.naukri.com/code360/problems/redundant-brackets_975473]
// The given string consists of brackets, operators, and lowercase English letters.
// A pair of brackets is said to be redundant when a subexpression is surrounded by unnecessary brackets.

// Example:
// ((a+b)) has a pair of redundant brackets. The pair of brackets at the first and last index is unnecessary.
// In contrast, (a + (b*c)) does not have any redundant brackets.

// ALGORITHM:
// If string's character is opening bracket / operator, simply push into stack.
// If letter, ignore it.
// If closing bracket, traverse back and keep popping until an opening bracket is found.
// During this process, if an operator is encountered, the brackets are not redundant, and the flag is set to true.
// Continue for entire string.

// TIME: O(N) for N characters in the string.
// SPACE: O(N) as a stack is used.
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char chStr = s[i];
        if (isalpha(chStr)) continue;
        else if (chStr == '(' || chStr == '+' || chStr == '-' || chStr == '*' || chStr == '/') // Opening bracket / operator.
            st.push(chStr);
        else // Closing bracket.
        {
            bool flag = false; // Initially, no operator is present.
            while (!st.empty() && st.top() != '(')
            {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') // Checking for an operator.
                    flag = true; // Operator is present between brackets, so they're NOT redundant.
                st.pop();
            }
            if (!st.empty()) st.pop(); // Opening bracket encountered.
            // At this point, the flag indicates whether this bracket pair is redundant or not.
            if (!flag) return true; // Redundant!
        }
    }
    return false; // Not redundant!
}

int main()
{
    string s = "((a+b)*c)";
    // string s = "()";

    if (findRedundantBrackets(s)) cout << "Redundant" << endl;
    else cout << "Not Redundant" << endl;

    return 0;
}