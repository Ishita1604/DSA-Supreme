#include <bits/stdc++.h>
using namespace std;

/********* LeetCode 155: Min Stack *********/
// Design a stack that supports push, pop, top, and retrieving the minimum element with O(1) time complexity for each function.
// Link: [https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01]

// Time: O(1) as all operations occur at the top of stack / end of the vector.
// Space: O(N) depending on size of the vector / stack.
class MinStack
{
public:
    vector<pair<int, int>> st;
    MinStack()
    {
    }
    // Push, pop, top are constant time functions as they require only adding, deleting, retrieving at the top of stack / end of the vector.
    // To implement getMin() in constant time, we keep track of minimum element at each instance.
    // Global variable would fail during pop(), hence we store minimum value alongside each element in the stack.
    void push(int val)
    {
        pair<int, int> p;
        p.first = val;
        if (st.empty())
            p.second = val;
        else
            p.second = min(val, st.back().second);
        st.push_back(p);
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack *obj = new MinStack(); // Create the MinStack object.
    obj->push(3);                   // Push elements.
    obj->push(5);
    obj->push(2);
    obj->push(1);

    cout << "Top element: " << obj->top() << endl;
    cout << "Minimum element: " << obj->getMin() << endl;
    obj->pop();
    cout << "Top element after pop: " << obj->top() << endl;
    cout << "Minimum element after pop: " << obj->getMin() << endl;
    obj->pop();
    cout << "Top element after another pop: " << obj->top() << endl;
    cout << "Minimum element after another pop: " << obj->getMin() << endl;

    delete obj;

    return 0;
}
