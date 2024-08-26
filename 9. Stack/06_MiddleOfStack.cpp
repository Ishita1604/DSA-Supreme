#include <bits/stdc++.h>
using namespace std;

// Find the middle element of the stack.

// ALGORITHM: USING RECURSION AND BACKTRACKING
// Recursively pop elements until reaching half the stack size. Print the middle element, then restore the stack by pushing the elements back.
// TIME: O(N) as function is called recursively N times, where N is total number of elements in stack.
// SPACE: O(N) as each recursive call adds a new frame to the call stack.

//  Original stack ➜ Recursively perform operations [Get the top, store and pop it] ➜ Base case reached (Size = Stack's size / 2)
//             ⮤                                                                                                 ⤸
//                 ⭦ Backtrack and perform reverse operations [Push each top back] 🡐 Print the middle element


void middleElement(stack<int> st, int total_size)
{
    int size = st.size();
    if (st.empty())
    {
        cout << "Empty stack!" << endl;
        return;
    }

    // Base-case condition.
    if (size == (total_size / 2) + 1)
    {
        cout << "Element present at the middle of the stack is " << st.top() << endl;
        return; // After getting the middle element, simply print it and return.
    }

    int temp = st.top();
    st.pop();

    // Recursion to call modified stack.
    middleElement(st, total_size);
    // Backtrack and push top back.
    st.push(temp);
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
    st.push(70);
    int total_size = st.size();

    middleElement(st, total_size);

    return 0;
}