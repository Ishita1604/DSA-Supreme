// Find whether a cycle or loop is present in the given singly linked list.
// Also find the starting point of the loop.

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



// APPROACH 1: HASH MAP METHOD
// TIME: O(N) to traverse the entire list.
// SPACE: O(N) to store the values in the hashmap.

// Maintain a hashmap with each node's address as the key and a boolean indicating if the node has been visited as the value.
// Set the value to true when a node is encountered.
// If a node is revisited (value is already true), a cycle is present.
// If the list ends, no cycle is present.
bool hasCycle(Node *head)
{
    if (head == NULL)
        return false; // Linked list is empty.

    unordered_map<Node *, bool> map;
    Node *temp = head;
    while (temp != NULL)
    {
        if (map.find(temp) != map.end()) // Check if the current node's address is already in the map.
        {
            // cout << "Starting point of loop is: " << temp->data << endl;
            return true; // If found, a cycle is present.
        }
        map[temp] = true; // Mark the node as visited.
        temp = temp->next;
    }
    return false; // No cycle present.
}



// APPROACH 2: FLOYD'S CYCLE DETECTION
// Time: O(N)
// Space: O(1)

// Maintain two pointers, slow (moves 1 step) and fast (moves 2 steps).
// At each pass, distance between slow and fast reduces by one. If they meet, distance will be zero, indicating a cycle.
// If fast->next is NULL, move only one step; else, move two steps.
bool hasCycle2(Node *head)
{
    if (head == NULL)
        return false; // Linked list is empty.

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next; // Move fast by 1 step.
        if (fast != NULL)  // Check if there is space for another step.
        {
            fast = fast->next; // Move fast by another step.
        }

        slow = slow->next; // Move slow by 1 step.
        if (slow == fast)
            return true; // Cycle is present.
    }
    return false; // No cycle.
}



// Uses Floyd's Cycle Detection approach.
// When slow and fast meet inside the cycle, the total distance traveled is a multiple of the cycle length.
// After resetting, slow travels the same distance to the start of the cycle as fast.
// Fast travels (cycle length - distance already traveled by fast), which equals the distance slow needs to travel.

// Time: O(N)
// Space: O(1)
Node *startingPoint(Node *head)
{
    // 1. Make slow and fast pointers meet.
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
        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return NULL; // No cycle.

    // 2. Then set slow back to head.
    slow = head;
    // 3. Move both by one step each until they meet at desired starting point of the cycle.
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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

    // Avoid printing as linked list has a cycle. So we get stuck in infinite loop as no termination.
    // print(head);

    // if (hasCycle(head))
    //     cout << "Cycle present!" << endl;
    // else
    //     cout << "Cycle not present!" << endl;


    if (hasCycle2(head))
        cout << "Cycle present!" << endl;
    else
        cout << "Cycle not present!" << endl;


    Node *start_pt = startingPoint(head);
    if (start_pt != NULL)
        cout << "Starting point of loop is: " << start_pt->data << endl;
    else
        cout << "No starting point!" << endl;


    return 0;
}