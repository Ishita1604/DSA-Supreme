#include <bits/stdc++.h>
using namespace std;

// Reverse the stack.

// ALGORITHM: USING RECURSION AND BACKTRACKING
// Combination of inserting element at the bottom with recursion.
// Recursively pop elements from the stack until it is empty.
// During backtracking, insert each element at the bottom of the stack, which will reverse the stack.

// TIME: O(N^2) as each insertion at the bottom takes O(N) time, and is done N times.
// SPACE: O(N)

void insertTopAtBottom(stack<int> &st, int target)
{
    if (st.empty()) // Base case: When stack gets empty, insert target at the bottom.
    {
        st.push(target);
        return;
    }

    int temp = st.top();
    st.pop();
    insertTopAtBottom(st, target); // Recursive call.
    st.push(temp);                 // Backtrack.
}

void reverseStack(stack<int> &st)
{
    if (st.empty()) // Base case: When the stack becomes empty, there's nothing to reverse.
    {
        return;
    }

    int target = st.top();         // Get the top element.
    st.pop();                      // Remove the top element.
    reverseStack(st);              // Recursively reverse the remaining stack.
    insertTopAtBottom(st, target); // Backtrack and insert the removed top at the bottom.
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);

    reverseStack(st);
    print(st);

    return 0;
}