// Add two numbers represented by linked lists.

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


// TIME: O(N)
// SPACE: O(1)
Node *addNumbers(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    // 1. Reverse both the lists.
    head1 = reverseSingly(head1);
    head2 = reverseSingly(head2);

    // 2. Add both linked lists.
    int carry = 0;
    Node *sumHead = NULL;
    Node *sumTail = NULL;

    // When lengths are equal.
    while (head1 != NULL && head2 != NULL)
    {
        // Calculate sum.
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;            // Find digit to create the node.
        carry = sum / 10;                // Calculate carry.
        Node *newNode = new Node(digit); // Create a newNode for the digit.

        // Attach newNode into the sum list.
        if (sumHead == NULL)
        {
            // Insert first node.
            sumHead = newNode;
            sumTail = newNode;
        }
        else
        {
            sumTail->next = newNode;
            sumTail = sumTail->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // When length of list 1 > length of list 2.
    while (head1 != NULL)
    {
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit); // Create a newNode for the digit.

        // Attach newNode into the sum list.
        sumTail->next = newNode;
        sumTail = newNode;

        if (head1 != NULL)
            head1 = head1->next;
    }

    // When length of list 2 is greater.
    while (head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit); // Create a newNode for the digit.

        // Attach newNode into the sum list.
        sumTail->next = newNode;
        sumTail = newNode;

        if (head2 != NULL)
            head2 = head2->next;
    }

    if (carry > 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit); // Create a newNode for the carry.
        sumTail->next = newNode;
        sumTail = newNode;
    }

    // 3. Reverse the answer list and return it.
    sumHead = reverseSingly(sumHead);
    return sumHead;
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
    Node *head1 = new Node(1);
    Node *second1 = new Node(1);
    Node *third1 = new Node(1);
    head1->next = second1;
    second1->next = third1;

    Node *head2 = new Node(9);

    Node *sum = addNumbers(head1, head2);
    print(sum);

    return 0;
}