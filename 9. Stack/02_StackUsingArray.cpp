#include <bits/stdc++.h>
using namespace std;

// Implement stack class from scratch.
// APPROACH 1: USING ARRAYS
// APPROACH 2: USING LINKED LIST

class Stack
{
public:
    // Behaviour of the stack.
    int *arr; // Pointer for storing elements in an array.
    int top;  // Index of top element.
    int size; // Size of the dynamic array.

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    // Functions of the stack.
    void push(int data)
    {
        if (top == size - 1) // Space not available.
            cout << "Stack overflow error!" << endl;
        else
        {
            // Space available for insertion.
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack underflow error!" << endl;
        else
            top--;
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
            return arr[top];
    }
    int getSize()
    {
        // Number of valid elements present in the stack.
        return (top + 1);
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

void print(Stack st)
{
    while (!st.isEmpty())
    {
        cout << st.getTop() << " ";
        st.pop();
    }
    cout << "\n\n";
}

int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);

    st.pop();
    print(st);

    int el = st.getTop();
    cout << "Top-most element is " << el << endl;

    int size = st.getSize();
    cout << "Size of the stack is " << size << endl;

    if (st.isEmpty())
        cout << "Stack is empty!" << endl;
    else
        cout << "Stack is non-empty!" << endl;

    return 0;
}
