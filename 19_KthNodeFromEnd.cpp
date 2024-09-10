#include <bits/stdc++.h>
using namespace std;

// Find Nth node from the end of a linked list.

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


// APPROACH 1: BRUTE FORCE APPROACH
// Calculate the length of the list.
// Then the desired node will be at index (len - k + 1).
// Maintain count till this index and return the node.

// Time: O(N), it traverses the list twice.
// Space: O(1)
Node* kthNode1(Node *head, int k)
{
    int len = 0;
    int idx = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout << len << " is length" << endl;
    // Calculate required index.
    idx = len - k + 1;
    cout << idx << " is idx" << endl;

    temp = head;
    // Traverse list till required index and return its value.
    while (idx > 1)
    {
        temp = temp->next;
        idx--;
    }
    return temp;
}


// APPROACH 2: RECURSION APPROACH
// Reach the end of the linked list and then come back by k number of nodes.
// Use recursion to come back in the linked list.

// Time: O(N)
// Space: O(N)
Node *fun(Node *head, int &k, Node *&temp)
{
    if (head == NULL)
        return NULL;
    fun(head->next, k, temp);

    if (k == 1)
        temp = head;
    k--;
    return temp;
}

Node *kthNode2(Node *head, int k)
{
    Node *temp = NULL;
    fun(head, k, temp);
    return temp;
}


// APPROACH 3: 2 POINTER APPROACH
// 2 pointers p1 and p2 at the beginning of linked list.
// Already move the p2 pointer by k steps. Now move both till p2 reaches NULL.
// Pointer p1 gives the required node.

// Time: O(N), but in a single pass itself.
// Space: O(1)
Node *kthNode3(Node *head, int k)
{
    Node *p1 = head;
    Node *p2 = head;

    while (k--)
        p2 = p2->next;

    while (p2 != NULL)
    {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p1;
}


int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Node *res = kthNode1(head, 5);
    // cout << res->data << endl;

    // Node *res = kthNode2(head, 2);
    // cout << res->data << endl;

    Node *res = kthNode3(head, 2);
    cout << res->data << endl;

    return 0;
}