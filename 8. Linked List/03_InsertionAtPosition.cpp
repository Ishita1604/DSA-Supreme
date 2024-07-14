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


// Time: O(N) in average and worst case, O(1) in best case.
// Space: O(1)
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // 1. Create the new node.
    // 2. Find `prev` and `curr` nodes.
    // 3. Attach new node's next to current node. All attachments done first so that no part of list is lost.
    // 4. Remove next of previous from current, and attach to the new node.
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 0)
    {
        // insertAtHead(head, tail, data);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *prev = head;
    int i = 1;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    newNode->next = curr;
    prev->next = newNode;
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
    // Position N means insert after Nth node.
    insertAtPosition(head, tail, 20, 0);
    insertAtPosition(head, tail, 30, 1);
    insertAtPosition(head, tail, 40, 2);
    insertAtPosition(head, tail, 50, 3);
    insertAtPosition(head, tail, 101, 2);
    print(head);

    return 0;
}