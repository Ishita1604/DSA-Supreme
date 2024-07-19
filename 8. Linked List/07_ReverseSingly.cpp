#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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


void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL) // When the linked list is empty.
    {
        tail = newNode;
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}


// Time: O(N) as each node is visited.
// Space: O(1)
Node *reverseSingly(Node *&head)
{
    // Implemented using loop.
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev; // Reverse the link.
        prev = curr;
        curr = forward;
    }
    return prev;
}


// Time: O(N) as each node is visited.
// Space: O(N) as for each node, a call is made and each call adds a new frame to the stack.
Node *reverseSingly2(Node *&prev, Node *&curr) // Changing parameters passed as arguments.
{
    // Implemented using recursion.
    // We need to take care of one case, rest recursion will handle.

    // The previous node, initially NULL, is `prev`, `curr` is current node and `forward` is the next node.
    // Each time, the next of `curr` is pointed to `prev`, until `curr` reaches NULL i.e. end of linked list.
    // The link between `curr` and `forward` is broken in above step, so `forward` is used to keep track of the succeeding linked list.

    // Base case to stop recursion:
    if (curr == NULL)
        return prev; // As linked list has been reversed so return the head.

    Node *forward = curr->next;
    curr->next = prev; // Reverse the link.

    return reverseSingly2(curr, forward);
}


void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 70);
    insertAtHead(head, tail, 90);
    cout << "Original Linked List:" << endl;
    print(head);

    cout << "Reversed Linked List:" << endl;
    Node *prev = NULL;
    Node *curr = head;
    head = reverseSingly(head);
    // head = reverseSingly2(prev, curr);
    print(head);

    return 0;
}