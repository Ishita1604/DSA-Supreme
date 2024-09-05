#include <bits/stdc++.h>
using namespace std;

// Sort a stack using recursion and backtracking.

// ALGORITHM:
// 1. Remove elements from the stack one-by-one and store temporarily.
// 2. Recursively sort remaining elements of the stack.
// 3. Insert the removed elements back into stack in sorted order.

// TIME: O(N^2) as each element might be moved and inserted multiple times.
// SPACE: O(N) as recursion stack uses space proportional to the number of elements.

void insertSorted(stack<int> &st, int target) // Function to insert an element into a sorted stack.
{
    if (st.empty())
    {
        st.push(target);
        return;
    }
    if (st.top() >= target) // Base case: If top element is greater than or equal to the target, push the target.
    {
        st.push(target);
        return;
    }
    // Temporarily remove elements until the correct position for the target is found.
    int topEl = st.top();
    st.pop();
    // Recursively insert the target element into the sorted stack.
    insertSorted(st, target);
    // Backtrack and restore the removed elements back to the stack.
    st.push(topEl);
}

void sortStack(stack<int> &st) // Function to sort the stack.
{
    if (st.empty())
        return; // Base case: If the stack is empty, do nothing.

    // Temporarily remove the top element.
    int topEl = st.top();
    st.pop();
    // Recursively sort the remaining stack.
    sortStack(st);
    // Backtrack and insert removed element into sorted stack.
    insertSorted(st, topEl);
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
    st.push(3);
    st.push(2);
    st.push(9);
    st.push(64);
    st.push(15);
    print(st);

    sortStack(st);
    print(st);

    return 0;
}