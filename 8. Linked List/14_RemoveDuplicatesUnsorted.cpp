// Remove duplicate node(s) from an unsorted linked list.

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


// APPROACH 1: HASH MAP METHOD
// Store each node's data as the key and a frequency counter as the value.
// Traverse the list and increment the counter for each node. If count > 1, duplicate is found. So remove the links.
// Works for both sorted and unsorted lists.
// TIME: O(N)
// SPACE: O(N)
Node *RemoveDuplicates(Node *head)
{
    if (head == NULL)
        return head;

    if (head->next == NULL) // Linked list has single element.
        return head;

    Node *curr = head;
    Node *prev = NULL;
    unordered_map<int, int> map;
    while (curr != NULL)
    {
        Node *temp = NULL;
        map[curr->data]++;
        if (map[curr->data] > 1)
        {
            temp = curr;
            curr = curr->next;
            prev->next = curr;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
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
    Node *head = new Node(20);
    Node *second = new Node(20);
    Node *third = new Node(10);
    Node *fourth = new Node(20);
    Node *fifth = new Node(3);
    Node *sixth = new Node(40);
    Node *seventh = new Node(30);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    print(head);

    Node *res = RemoveDuplicates(head);
    print(res);

    return 0;
}