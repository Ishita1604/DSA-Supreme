// If exists, remove the cycle from the given linked list.

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

// Time: O(N)
// Space: O(1)
Node *removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == fast) // Both pointers will meet somewhere inside the cycle.
            break;
    }

    if (fast == NULL || fast->next == NULL) // No cycle.
    {
        cout << "Cycle not present!" << endl;
        return NULL;
    }

    slow = head;
    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }
    prev->next = NULL; // Cycle removed.
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fifth;

    // List with cycle.
    // print(head);

    Node *res = removeCycle(head);
    print(res); // Modified linked list.

    return 0;
}