#include <bits/stdc++.h>
using namespace std;

/*
What is a Linked List?
_____________________

A data structure that consists of collection of nodes.
Node contains the data and a reference to the address of the next node.

- Non-contiguous memory allocation prevents memory wastage, unlike arrays, vectors, etc.
- Insertion and deletion operations are faster as only pointers need to be adjusted.
- Dynamic, as it can grow and shrink during runtime.
- Linear data structure, as each node is connected sequentially, forming a single line of elements.
- No element can be accessed directly in the middle without accessing its predecessors first.

- It is further used to make complex non-linear data structures.
- Graph is one such example where a node can have more than one descendant.


Types?
1) SINGLY: Each node points to the next node in the sequence.
2) SINGLY CIRCULAR: The last node points back to the first node, forming a circle. While a loop is formed, traversal still follows linear order.
3) DOUBLY: Each node points to both, the previous and next nodes, allowing traversal in both directions.
// Traversal is still linear, as we can't jump from any node to another. Each node has exactly one previous and next node.
// The next of first node points to a second node, while previous of second node points back to first, preserving the linear order.
4) DOUBLY CIRCULAR: Last node points back to first node, forming a circle, and each node has pointers to both its previous and next nodes.

_____________________
*/

class Node
{
public:
    int data;
    Node *next; // Pointer of `Node` type to store address of next node.

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    // 1. Print the data.
    // 2. Move pointer forward.
    // 3. Stop when next is NULL.
    Node *temp = head; // Pointer to traverse the linked list.
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

int main()
{
    // Dynamically creating new nodes. Basically these are objects of class `Node`.
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Printing the Linked List ..." << endl;
    print(first);

    return 0;
}
