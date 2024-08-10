#include <bits/stdc++.h>
using namespace std;

// Sort a linked list of 0s, 1s and 2s.

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


// APPROACH 1: COUNT THE 0s, 1s, 2s
// Count the number of 0s, 1s, and 2s in the given list.
// Then overwrite the original list by placing the counted number of 0s, followed by 1s, and finally 2s.
// Not optimal as it involves replacement of the node values.

// TIME: O(N)
// SPACE: O(1)
Node *sort1(Node *head)
{
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
            zero_count++;
        else if (curr->data == 1)
            one_count++;
        else
            two_count++;
        curr = curr->next;
    }
    curr = head;
    while (zero_count--)
    {
        curr->data = 0;
        curr = curr->next;
    }
    while (one_count--)
    {
        curr->data = 1;
        curr = curr->next;
    }
    while (two_count--)
    {
        curr->data = 2;
        curr = curr->next;
    }
    return head;
}


// APPROACH 2: WITHOUT REPLACEMENT METHOD
// Create three new linked lists for nodes with values 0, 1, and 2.
// Traverse the original list, distribute nodes to respective lists, and then concatenate them to form the sorted list.

// TIME: O(N)
// SPACE: O(1)

Node *sort2(Node *head)
{
    // Create three dummy nodes to make three separate linked lists for 0s, 1s, and 2s.
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // Separate each node from the original list and append it to the respective list based on its value.
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // Separate the node.
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // Now, append the node.
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            oneTail->next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            twoTail->next = temp;
            twoTail = temp;
        }
    }
    // Once all the three lists are ready, we need to join them.

    // Remove dummy nodes from the heads of the 1s and 2s lists.
    // If lists are right now, we'd have to remove the dummy nodes later.
    // So it's better to shift the pointers, i.e., adjust the oneHead and twoHead pointers.

    // Adjust the `oneHead` first.
    Node *dummy1 = oneHead;
    oneHead = oneHead->next;
    dummy1->next = NULL;
    delete dummy1;

    // Now adjust the `twoHead`.
    Node *dummy2 = twoHead;
    twoHead = twoHead->next;
    dummy2->next = NULL;
    delete dummy2;

    // Join the lists.
    // If the list of 0s is empty, it doesn't matter as `zeroHead` is just a dummy node, and further insertion will be at the `zeroTail` position.

    // So, check if the lists of 1s and 2s are empty.
    if (oneHead != NULL)
    {
        zeroTail->next = oneHead;
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
        // If the list of 2s is empty, it doesn't matter since the list of 1s will end with NULL.
    }
    else // The list of 1s is empty.
    {
        if (twoHead != NULL)
            zeroTail->next = twoHead;
    }

    // Remove the dummy node from zeroHead.
    Node *dummy0 = zeroHead;
    zeroHead = zeroHead->next;
    dummy0->next = NULL;
    delete dummy0;

    // Return the new head of the sorted list.
    return zeroHead;
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
    Node *head = new Node(2);
    Node *second = new Node(1);
    Node *third = new Node(1);
    Node *fourth = new Node(0);
    Node *fifth = new Node(2);
    Node *sixth = new Node(0);
    Node *seventh = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    print(head);

    // Node *res = sort1(head);
    Node *res = sort2(head);
    print(res);

    return 0;
}