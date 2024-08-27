#include <bits/stdc++.h>
using namespace std;

// Insert an element at the middle of the stack.

// ALGORITHM: USING RECURSION AND BACKTRACKING
// Similar to finding the middle element.
// Recursively pop elements until reaching half the stack size, insert the new element, then push the previously removed elements back.

// TIME: O(N)
// SPACE: O(N)

void insertAtMiddle(stack<int> &st, int total_size, int el) // Make sure to pass stack by reference.
{
    if (st.empty())
    {
        cout << "Empty stack!" << endl;
        st.push(el);
        return;
    }

    int size = st.size();
    // Base-case condition.
    if (size == total_size / 2)
    {
        st.push(el);
        return;
    }

    int temp = st.top();
    st.pop();

    // Recursion to call modified stack.
    insertAtMiddle(st, total_size, el);
    // Backtrack and push top back.
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
    st.push(60);
    int total_size = st.size();
    print(st);

    int el = 16;
    insertAtMiddle(st, total_size, el);
    print(st);

    return 0;
}