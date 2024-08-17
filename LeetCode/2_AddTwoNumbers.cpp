/**** LeetCode 2: Add Two Numbers ****/

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int sum = 0;
    int carry = 0;

    while (l1 != NULL && l2 != NULL)
    {
        sum = l1->val + l2->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *digNode = new ListNode(digit);
        temp->next = digNode;
        temp = digNode;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        sum = l1->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *digNode = new ListNode(digit);
        temp->next = digNode;
        temp = digNode;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        sum = l2->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *digNode = new ListNode(digit);
        temp->next = digNode;
        temp = digNode;
        l2 = l2->next;
    }
    while (carry > 0)
    {
        sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *digNode = new ListNode(digit);
        temp->next = digNode;
        temp = digNode;
    }
    return dummy->next;
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
    ListNode *head1 = new ListNode(1);
    ListNode *second1 = new ListNode(1);
    ListNode *third1 = new ListNode(1);
    head1->next = second1;
    second1->next = third1;

    ListNode *head2 = new ListNode(9);
    ListNode *second2 = new ListNode(9);
    head2->next = second2;

    print(head1);
    print(head2);
    cout << "_____" << endl;

    ListNode *res = addTwoNumbers(head1, head2);
    print(res);

    return 0;
}
