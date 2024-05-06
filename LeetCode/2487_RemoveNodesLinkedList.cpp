#include <bits/stdc++.h>
using namespace std;

// Time: O(N) as reversing the linked list and traversing it to remove nodes.
// Space: O(1)


// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p = head, *q = head->next, *r;
        if (q == nullptr)
            return p;
        p->next = nullptr;

        while (q != nullptr)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }

    ListNode *removeNodes(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *newHead = reverseList(head); // Reverse the linked list.

        int max = newHead->val;
        ListNode *p = newHead, *q = newHead->next, *r;

        while (q != nullptr)
        {
            r = q->next;
            if (q->val < max) // Remove node q.
            {
                p->next = r;
                q = r;
            }
            else // Keep moving forward and update max.
            {
                max = q->val;
                p = q;
                q = r;
            }
        }
        newHead = reverseList(newHead); // Again reverse the linked list.
        return newHead;
    }
};


int main()
{
    // Create the linked list as head = [5,2,13,3,8]:
    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    Solution solution;
    ListNode *newHead = solution.removeNodes(head);
    cout << "Output: ";
    while (newHead != nullptr)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}