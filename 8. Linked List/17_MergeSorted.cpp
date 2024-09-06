// Merge two sorted linked lists to produce a combined sorted linked list.

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


// APPROACH 1: APPEND TO ARRAY AND SORT
// Append both lists' elements to an array, then sort the array, and convert the array back to a list.

// TIME: O(N) + O(N*logN)
// SPACE: O(N) + O(N) for both the array and the list.


// APPROACH 2: USING 2 POINTERS AND SORTED PROPERTY
// Start from a dummy node for the final merged list.
// Traverse both lists with two pointers, compare elements and attach the smaller one to the merged list.
// Update the dummy node to point to the newly added element.

// TIME: O(N)
// SPACE: O(1)
Node *mergeSorted(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    // Create the temp nodes and dummy node.
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Compare temp1 with temp2 and point temp to the lower value.
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            temp->next = temp1; // Attach dummy node's temp to list 1's node.
            temp = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2; // Attach dummy node's temp to list 2's node.
            temp = temp2;
            temp2 = temp2->next;
        }
    }
    // Exiting this loop means one of the lists has been fully traversed.
    // We need to attach the remaining nodes from the other list (which is still non-empty) to the merged list.


    if (temp1 == NULL) // List 1 got over.
    {
        temp->next = temp2;
    }
    else // List 2 got over.
    {
        temp->next = temp1;
    }

    // Return head of the final list.
    return dummyNode->next;
}


int main()
{
    Node *head1 = new Node(8);
    Node *second1 = new Node(19);
    Node *third1 = new Node(30);
    head1->next = second1;
    second1->next = third1;

    Node *head2 = new Node(1);
    Node *second2 = new Node(3);
    Node *third2 = new Node(65);
    head2->next = second2;
    second2->next = third2;

    print(head1);
    print(head2);

    Node *mergedHead = mergeSorted(head1, head2);
    print(mergedHead);

    return 0;
}