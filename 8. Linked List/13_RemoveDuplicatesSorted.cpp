// Remove duplicate node(s) from a sorted linked list.

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


// APPROACH: ADJACENT COMPARE METHOD
// Traverse the list and compare the current node with its next node.
// If they match, a duplicate exists. Then remove it by adjusting the pointers to skip the duplicate node.

// TIME: O(N)
// SPACE: O(1) as linked list is modified in-place.
Node *RemoveDuplicatesSorted(Node *head)
{
    if (head == NULL)
        return head;

    if (head->next == NULL) // Linked list has single element.
        return head;

    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data != curr->next->data) // Not a duplicate.
            curr = curr->next;              // So move to the next node.
        else
        {
            Node *duplicateNode = curr->next;
            curr->next = curr->next->next;
            delete duplicateNode;
        }
    }
    return head;
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
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(20);
    Node *fourth = new Node(20);
    Node *fifth = new Node(40);
    Node *sixth = new Node(40);
    Node *seventh = new Node(30);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    print(head);

    Node *res = RemoveDuplicatesSorted(head);
    print(res);

    return 0;
}