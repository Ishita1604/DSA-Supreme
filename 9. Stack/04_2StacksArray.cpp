#include <bits/stdc++.h>
using namespace std;

// Implement two stacks in a single array.

// Approach 1) Divide the array in two halves, but that wastes memory.
// Approach 2) Stack 1 starts at beginning while other starts at end. Elements are added until the pointers meet, avoiding memory wastage.

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // Functions for each stack.
    void push1(int data)
    {
        if (top2 - top1 == 1)
            cout << "Stack overflow error!" << endl; // Stack is full, as both pointers are present side-by-side.
        else
        {
            // Space is available.
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data)
    {
        if (top2 - top1 == 1)
            cout << "Stack overflow error!" << endl; // Stack is full, as both pointers are present side-by-side.
        else
        {
            // Space is available.
            top2--;
            arr[top2] = data;
        }
    }
    void pop1()
    {
        if (top1 == -1)
            cout << "Stack underflow error!" << endl; // 1st stack is empty so can't delete elements.
        else
            top1--;
    }
    void pop2()
    {
        if (top2 == size)
            cout << "Stack underflow error!" << endl; // 2nd stack is empty so can't delete elements.
        else
            top2--;
    }

    void print() // Function to visualize the array content and stack pointers.
    {
        cout << endl;
        cout << "Top 1: " << top1 << endl;
        cout << "Top 2: " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(10);
    st.pop1();
    st.print();

    st.push1(1);
    st.print();
    st.push1(2);
    st.print();
    st.push1(3);
    st.print();
    st.push1(4);
    st.print();
    st.push1(5);
    st.print();
    st.push1(6);
    st.print();

    st.push2(10);
    st.print();
    st.push2(20);
    st.print();
    st.push2(30);
    st.print();
    st.push2(40);
    st.print();

    st.push2(50);
    st.print();

    return 0;
}