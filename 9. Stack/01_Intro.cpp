#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Initialize the stack.
    stack<int> st;
    // Inserting elements.
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // Remove elements.
    st.pop();
    // Peek top-most element.
    cout << "Top-most element is " << st.top() << endl;
    if (st.empty()) cout << "Stack is empty!";
    else cout << "Stack is non-empty and contains " << st.size() << " elements!" << endl;

    // Print the stack elements.
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    // The nature of stack is, the order in which elements are pushed is reversed when they are popped.
    // It follows LIFO (Last-In-First-Out) principle i.e. the element pushed last is popped first.

    return 0;
}
