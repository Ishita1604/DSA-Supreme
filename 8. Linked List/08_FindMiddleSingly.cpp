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
    if (head == NULL)
    {
        tail = newNode;
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}


// EVEN ODD APPROACH:
// Time: O(N)
// Space: O(1)
Node *getMiddle(Node *&head)
{
    // Find the length of linked list.
    // Then middle is N/2 for even nodes, and (N+1)/2 for odd nodes.
    int length = 0;
    Node *middleNode = head;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return head;
    }

    if (head->next == NULL)
        return head;

    int i = 1;
    if (length % 2 != 0) // Even length.
    {
        while (i != (length + 1) / 2)
        {
            middleNode = middleNode->next;
            i++;
        }
    }
    else // Odd length.
    {
        while (i != length / 2)
        {
            middleNode = middleNode->next;
            i++;
        }
    }
    return middleNode;
}


// TWO POINTER / SLOW AND FAST POINTER / TORTOISE APPROACH:
// Time: O(N/2) or O(N) as `slow` goes till the middle, and `fast` moves by 2 steps.
// Space: O(1)
Node *getMiddle2(Node *&head)
{
    // In total, `fast` moves 2 steps but not in one go.
    // As `fast` might be at second last node, but moving 2 steps forward would go out of linked list.
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return head;
    }

    if (head->next == NULL) // Only one node in linked list.
        return head;

    // Nodes > 1 in linked list.
    Node *slow = head;
    Node *fast = head->next;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next; // Moved 1 step.
        if (fast != NULL)
        {
            fast = fast->next; // Moved another 1 step.
            slow = slow->next; // Moves 1 step only.
        }
    }
    return slow;
}


// TWO POINTER / SLOW AND FAST POINTER / TORTOISE APPROACH:
// Time: O(N/2) or O(N) as `slow` goes till the middle, and `fast` moves by 2 steps.
// Space: O(1)
Node *getMiddle2(Node *&head)
{
    // In total, `fast` moves 2 steps but not in one go.
    // As `fast` might be at second last node, but moving 2 steps forward would go out of linked list.
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return head;
    }

    if (head->next == NULL) // Only one node in linked list.
        return head;

    // Nodes > 1 in linked list.
    Node *slow = head;
    Node *fast = head->next;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next; // Moved 1 step.
        if (fast != NULL)
        {
            fast = fast->next; // Moved another 1 step.
            slow = slow->next; // Moves 1 step only.
        }
    }
    return slow;
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
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 35);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    cout << "Linked List:" << endl;
    print(head);

    Node *res = getMiddle(head);
    // Node *res = getMiddle2(head);
    cout << "Middle Element of Linked List is: " << res->data << endl;

    return 0;
}