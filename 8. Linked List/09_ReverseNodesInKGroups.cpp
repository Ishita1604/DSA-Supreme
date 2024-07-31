/*
LeetCode 25: Reverse Nodes in k-Group
_____________________________________

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.
`k` is a positive integer and is <= the length of the linked list.
If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

_____________________________________
*/

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

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// RECURSION APPROACH:
// Time: O(N)
// Space: O(N)
Node *reverseKGroup(Node *&head, int k)
{
    if (head == NULL)
        return head; // Linked list is empty.
    int len = getLength(head);
    if (len == 1)
        return head;
    if (k > len)
        return head; // Return linked list as it is, as invalid value of `k`.

    // Step A: Reverse first `k` nodes.
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr->next; // Save the next node.
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // Now, `prev` is the new head of the reversed part, and `head is the new tail.

    // Step B: Recursive call for next `k` nodes.
    if (forward != NULL) // There are still nodes left to reverse.
    {
        // The tail of the reversed part (current `head`) will connect to the result of the recursive call.
        head->next = reverseKGroup(forward, k);
    }

    // Step C: Return the modified linked list.
    return prev; // New `head` after reversal.
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
    int k = 2;
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    cout << "Linked List:" << endl;
    print(head);

    Node *res = reverseKGroup(head, k);
    cout << "After Reversal in Groups of K: " << endl;
    print(res);

    return 0;
}