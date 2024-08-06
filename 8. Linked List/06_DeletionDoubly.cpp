#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};


// Time: O(N)
// Space: O(1)
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}


// Time: O(N)
// Space: O(1)
int findLength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}


// Time: O(N)
// Space: O(1)
void deletion(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Cannot delete node, as Linked List is empty!" << endl;
    }

    // Delete the first node.
    if (position == 1)
    {
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        Node *temp = head; // Store current head.
        head = head->next; // Update head to next node.
        head->prev = NULL; // Break the link.
        temp->next = NULL; // Break the link.
        delete temp;       // Free memory by calling destructor.
        return;
    }

    // Delete the last node.
    int len = findLength(head);
    if (position == len)
    {
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        Node *temp = tail; // Store current tail.
        tail = tail->prev; // Update the tail.
        temp->prev = NULL; // Break the link.
        tail->next = NULL; // Break the link.
        delete temp;       // Free memory by calling the destructor.
        return;
    }

    // Delete the middle nodes.
    // 1. Find `left`, `curr` and `right` nodes.
    // 2. Point left's next directly to right.
    // 3. Point back right's prev to left.
    // 4. Point curr's next to NULL.
    // 5. Point curr's prev to NULL.
    // 6. Delete the `curr` node.
    Node *left = head;
    int i = 1;
    while (i != (position - 1))
    {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;

    left->next = right;
    right->prev = left;

    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
    return;
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    head = first;
    tail = fourth;
    print(head);

    deletion(head, tail, 4);
    print(head);

    return 0;
}
