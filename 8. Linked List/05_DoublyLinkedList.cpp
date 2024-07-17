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
// Spce: O(1)
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
// Spce: O(1)
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


// Time: O(1)
// Space: O(1)
void insertAtHeadDoubly(Node *&head, Node *&tail, int data)
{
    // 1. Create the new node to be inserted.
    // 2. Point its next to head of the linked list.
    // 3. Point head's previous back to the new node.
    // 4. Update the new node as the head of the linked list.
    Node *newNode = new Node(data);
    if (head == NULL) // When the linked list is empty.
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


// Time: O(1)
// Space: O(1)
void insertAtTailDoubly(Node *&head, Node *&tail, int data)
{
    // 1. Create the new tail node to be inserted.
    // 2. Point original linked list's tail to the new node.
    // 3. Point new node's previous back to the tail.
    // 4. Update the new node as the tail of the linked list.
    Node *newNode = new Node(data);
    if (head == NULL) // When the linked list is empty.
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}


// Time: O(N)
// Space: O(1)
void insertAtPositionDoubly(Node *&head, Node *&tail, int data, int position)
{
    Node *newNode = new Node(data);
    if (head == NULL) // When the linked list is empty.
    {
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 1) // Insert node at the head.
    {
        insertAtHeadDoubly(head, tail, data);
        return;
    }

    int len = findLength(head);
    if (position > len) // Insert node at the tail.
    {
        insertAtTailDoubly(head, tail, data);
        return;
    }

    // Insert at a middle position of the linked list.
    // 1. Create the `newNode`.
    // 2. Find the `prevNode` i.e. the node before insertion, and `currNode`, the node of insertion.
    // 3. Point prevNode's next to newNode. And newNode's previous back to prevNode.
    // 4. Point currNode's previous to newNode. And newNode's next back to prevNode.
    int i = 1;
    Node *prevNode = head;
    while (i < (position - 1))
    {
        prevNode = prevNode->next;
        i++;
    }
    Node *currNode = prevNode->next;

    prevNode->next = newNode;
    newNode->prev = prevNode;

    currNode->prev = newNode;
    newNode->next = currNode;
}


int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;

    Node *head = first;
    Node *tail = third;
    print(head);

    insertAtHeadDoubly(head, tail, 78);
    insertAtTailDoubly(head, tail, 79);
    print(head);
    insertAtPositionDoubly(head, tail, 101, 6);
    print(head);

    return 0;
}