#include <bits/stdc++.h>
using namespace std;

// Implement stack class from scratch.
// APPROACH 2: USING LINKED LIST

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    // Behaviour of the stack.
    Node *top;
    Stack()
    {
        this->top = NULL;
    }

    // Functions of the stack.
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (newNode == NULL) // Memory allocation failed, thus stack is full.
            cout << "Stack overflow error!" << endl;
        else
        {
            // Space available for insertion.
            newNode->next = top;
            top = newNode;
        }
    }
    void pop()
    {
        if (top == NULL) // Stack is empty, so can't delete element.
            cout << "Stack underflow error!" << endl;
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    int getTop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
            return top->data;
    }
    int getSize()
    {
        // Number of valid elements present in the stack.
        int size = 0;
        Node *curr = top;
        while (curr != NULL)
        {
            size++;
            curr = curr->next;
        }
        return size;
    }
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        Node *newNode = new Node(0);
        if (newNode == NULL) // Memory allocation for the new node failed, means stack is full.
            return true;
        return false;
    }
    void print()
    {
        // The print and pop method doesn't work here.
        // Because by using linked list implementation, stack's actual elements get modified.
        Node *temp = top;
        if (getTop() == -1)
            cout << "Stack is empty, can't print elements ..." << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n\n";
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.print();

    st.pop();
    st.print();

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