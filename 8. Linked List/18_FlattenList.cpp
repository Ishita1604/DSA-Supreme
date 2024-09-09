/*
Given a linked list, where every node represents a sub-linked list and contains two pointers:

(i) A next pointer to the next node,
(ii) A bottom pointer to a linked list where this node is head.

Each of the sub-linked lists is in sorted order.
Flatten the linked list so all the nodes appear in a single level while maintaining the sorted order.

NOTE: The flattened list will be printed using the bottom pointer instead of the next pointer.
Ensure that the original next pointer links are not modified i.e. the main list must remain intact.

_____________________________________________________________________________________________
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->bottom = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};



// APPROACH 1: PUSH INTO VECTOR
// Start from head of list and until it isn't NULL, push to a vector.
// Simultaneously for each node, traverse its sub-nodes and push them also.
// Sort entire list.
// Convert this sorted vector to linked list.

// TIME: O(N + M) + O((N+M)log(N+M)) + O(N+M)
// SPACE: O(N + M)
Node *flatten1(Node *head)
{
    vector<int> nodes;
    while (head != NULL) // Traverse and push the main nodes.
    {
        nodes.push_back(head->data);
        Node *temp;
        if (head->bottom != NULL)
        {
            temp = head->bottom;
        }
        while (temp != NULL) // Traverse and push the sub-nodes.
        {
            nodes.push_back(temp->data);
            temp = temp->bottom;
        }
        head = head->next;
    }

    // sort the vector.
    sort(nodes.begin(), nodes.end());

    // convert vector to LL.
    int len = nodes.size();
    Node *newHead = NULL;
    Node *newTail = NULL;

    for (int i=0; i < len; i++)
    {
        Node *newNode = new Node(nodes[i]);
        if (i == 0) // head node.
        {
            newHead = newNode;
            newTail = newNode;
        }
        else
        {
            newTail->bottom = newNode;
            newTail = newNode;
        }
    }
    return newHead;
}



// APPROACH 2: USING RECURSION
// Pick two nodes from end of main list and sorted-merge their sub-linked lists.
// Repeat for entire list.
// Merging has to be done using bottom pointer, not next.

// Function to sorted-merge two lists via the bottom pointer using recursion.
// TIME: O(size(a) + size(b)) = O(M+N) where M and N are total nodes in each list.
// SPACE: O(M+N) as recursion stack used.
Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *merged = NULL;

    if (a->data < b->data)
    {
        merged = a;
        a->bottom = merge(a->bottom, b);
    }
    else
    {
        merged = b;
        b->bottom = merge(a, b->bottom);
    }
    return merged;
}

// Function to recursively sorted-merge entire list.
// TIME: O(K * N) where K is nodes in main list and N is total nodes in all sub linked lists.
// SPACE: O(K) i.e number of nodes in main list.
Node *flatten2(Node *root)
{
    if (root == NULL)
        return NULL;
    // Recursion that makes sure sorted-merge is done from tail to head node.
    // Necesaary to preserve the original next pointer links.
    // Otherwise they would change if merging is done from head to tail direction.
    Node *flattened = merge(root, flatten2(root->next));
    return flattened;
}



// Print using next to display the main linked list.
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



// Printing also done using bottom pointer. Role of next pointer was mostly to define the main list.
void printBottom(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->bottom;
    }
    cout << endl;
}



int main()
{
    Node *head = new Node(5);
    Node *second = new Node(10);
    Node *third = new Node(19);
    Node *fourth = new Node(28);
    head->next = second;
    second->next = third;
    third->next = fourth;

    Node *head_first = new Node(7);
    Node *head_second = new Node(8);
    Node *head_third = new Node(30);

    Node *second_first = new Node(20);

    Node *third_first = new Node(22);
    Node *third_second = new Node(50);

    Node *fourth_first = new Node(35);
    Node *fourth_second = new Node(40);
    Node *fourth_third = new Node(45);

    head->bottom = head_first;
    head_first->bottom = head_second;
    head_second->bottom = head_third;

    second->bottom = second_first;

    third->bottom = third_first;
    third_first->bottom = third_second;

    fourth->bottom = fourth_first;
    fourth_first->bottom = fourth_second;
    fourth_second->bottom = fourth_third;

    cout << "Main Linked List:" << endl;
    print(head);
    cout << endl;

    cout << "All the Sub-linked Lists:" << endl;
    printBottom(head);
    printBottom(second);
    printBottom(third);
    printBottom(fourth);
    cout << endl;

    cout << "Final Flattened Linked List:" << endl;
    Node *ans = flatten1(head);
    // Node *ans2 = flatten2(head);
    printBottom(ans);
    cout << endl;

    return 0;
}