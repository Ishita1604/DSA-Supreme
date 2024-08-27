#include <bits/stdc++.h>
using namespace std;

// Insert the top element of the stack at its bottom.

// ALGORITHM: USING RECURSION AND BACKTRACKING
// Recursively pop elements to empty the stack, insert the top element at the bottom, and then backtrack to push the elements back.

// TIME: O(N)
// SPACE: O(N)

void insertTopAtBottom(stack<int> &st, int el)
{
    int size = st.size();
    if (size == 0) // Base case: Insert the element when the stack becomes empty.
    {
        st.push(el);
        return;
    }

    int temp = st.top();
    st.pop();
    insertTopAtBottom(st, el);
    st.push(temp);
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
    int total_size = st.size();
    print(st);

    int el = st.top();         // Find the target, which is the top element.
    st.pop();                  // Remove the top element.
    insertTopAtBottom(st, el); // Insert it at the bottom.
    print(st);

    return 0;
}
