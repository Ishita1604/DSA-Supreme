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

// Time: O(1)
// Space: O(1)
void insertAtHead(Node *&head, Node *&tail, int data) // Make sure to pass the head and tail of original linked list by reference.
{
    // 1. Create the new node to be inserted.
    // 2. Point its next to head of the linked list.
    // 3. Update the new node as the head of the linked list.
    if (head == NULL) // When the linked list is empty.
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Time: O(1)
// Space: O(1)
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // 1. Create the new tail node to be inserted.
    // 2. Point original linked list's tail to the new node.
    // 3. Update the new node as the tail of the linked list.
    if (head == NULL) // When the linked list is empty.
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 70);
    insertAtHead(head, tail, 98);
    insertAtTail(head, tail, 31);
    print(head);

    return 0;
}