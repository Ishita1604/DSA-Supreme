/**** LeetCode 19: Remove Nth Node From End of List ****/
// Given the head of a linked list, remove the `nth` node from the end of the list and return its head.

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *getNode(ListNode *head, int n)
{
    ListNode *p1 = head;
    ListNode *p2 = head;
    while (n--)
        p2 = p2->next;
    while (p2 != NULL)
    {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p1;
}


ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return NULL;

    ListNode *toDelete = getNode(head, n);
    ListNode *prev = new ListNode(-1);
    ListNode *curr = head;

    while (curr != toDelete)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if (toDelete == head)
        head = head->next;
    ListNode *temp = curr;
    curr = curr->next;
    delete temp;

    return head;
}


void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    print(head);

    ListNode *res = removeNthFromEnd(head, 5);
    print(res);

    return 0;
}