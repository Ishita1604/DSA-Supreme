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
// The head and tail are passed by reference so that changes reflect in the original list.
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // 1. Create the new node to be inserted.
    // 2. Point its next to head of the linked list.
    // 3. Update the new node as the head of the linked list.
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


// Time: O(1) as directly updating the tail pointer, no traversal needed.
// Space: O(1)
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // 1. Create the new tail node to be inserted.
    // 2. Point original linked list's tail to the new node.
    // 3. Update the new node as the tail of the linked list.
    Node *newNode = new Node(data);
    if (head == NULL) // When the linked list is empty.
    {
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


// Time: O(N) in average and worst case, O(1) in best case when the linked list is empty.
// Space: O(1)
// Insertion at end of the linked list, without passing the tail element as argument.
void insertAtTail2(Node *&head, int data)
{
    // 1. Create the new tail node to be inserted.
    // 2. Traverse to the end of linked list.
    // 3. Point end element to the new node.
    // 4. Update the new node as the tail of the linked list.
    Node *newNode = new Node(data);
    if (head == NULL) // When the linked list is empty.
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
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
    insertAtTail2(head, 32);
    print(head);

    return 0;
}