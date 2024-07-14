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
    ~Node()
    {
        cout << "Node with value " << data << " is being deleted ..." << endl;
    }
};


int findLength(Node *&head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}


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


// Time: O(N) in average and worst case, O(1) in best case.
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
        Node *temp = head; // Store current head.
        head = head->next; // Update head to next node.
        temp->next = NULL; // Break the link.
        delete temp;       // Free memory by calling destructor.
        return;
    }

    // Delete the last node.
    int len = findLength(head);
    if (position == len)
    {
        Node *temp = tail; // Store current tail.
        Node *prev = head; // Pointer to the node before tail.
        int i = 1;
        while (i != (len - 1)) // Find `prev` node.
        {
            prev = prev->next;
            i++;
        }
        tail = prev;       // Update the tail.
        prev->next = NULL; // Break the link.
        delete temp;       // Free memory by calling destructor.
        return;
    }

    // Delete the middle nodes.
    // 1. Find `prev` and `curr` nodes.
    // 2. Point prev's next directly to curr's next.
    // 3. Point curr's next to NULL.
    // 4. Delete the `curr` node.
    Node *prev = head;
    int i = 1;
    while (i != (position - 1))
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
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
    insertAtHead(head, tail, 98);
    print(head);

    // Position N means delete the Nth node.
    // deletion(head, tail, 1);
    // deletion(head, tail, 4);
    deletion(head, tail, 3);
    print(head);

    return 0;
}