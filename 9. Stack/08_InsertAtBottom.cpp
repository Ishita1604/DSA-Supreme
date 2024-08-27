#include <bits/stdc++.h>
using namespace std;

// Insert an element at the bottom of the stack.

// ALGORITHM: USING RECURSION AND BACKTRACKING
// Recursively pop elements until the stack is empty, then insert the new element.
// Backtrack by pushing the previously removed elements back.

// TIME: O(N)
// SPACE: O(N)

void insertAtBottom(stack<int> &st, int el)
{
    int size = st.size();
    if (size == 0) // Base case: Insert the element when the stack becomes empty.
    {
        st.push(el);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, el);
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

    int el = 16;
    insertAtBottom(st, el);
    print(st);

    return 0;
}