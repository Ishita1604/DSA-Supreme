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


Node *reverseSingly(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;

    while (curr != NULL)
    {
        forward = curr->next;
        prev = curr->next;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}

// APPROACH 1:
// Copy the list's elements to an array, then compare values from both ends towards the center to check for a palindrome.
// Time: O(N)
// Space: O(N)


// APPROACH 2:
// Copy the list's elements to another linked list and reverse it. Then compare the original and reversed lists element by element.
// Time: O(N)
// Space: O(N)


// APPROACH 3:
// Find the middle of the list, reverse the second half, and then compare nodes from the start and the reversed second half to check for matching values.
// Time: O(N)
// Space: O(1)
bool isPalindrome(Node *head)
{
    // 1. Find the middle node.
    if (head == NULL)
        return NULL;
    
    if (head->next == NULL) // Only one node in linked list.
        return true;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    Node *mid = slow;
    // 2. Reverse linked list after middle.
    mid->next = reverseSingly(mid->next); // Head of linked list to be reversed is passed.
    // 3. Compare using two pointers, one at start and other at middle.
    Node *temp1 = head;
    Node *temp2 = mid->next;
    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
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
    Node *third = new Node(30);
    Node *fourth = new Node(20);
    Node *fifth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    print(head);

    bool res = isPalindrome(head);
    if (res)
        cout << "The Linked List represents a Palindrome!" << endl;
    else
        cout << "The Linked List does not represent a Palindrome!" << endl;

    return 0;
}