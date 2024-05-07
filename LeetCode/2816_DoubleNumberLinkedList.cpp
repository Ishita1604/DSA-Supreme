#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list:
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
    ListNode *doubleIt(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *cur = head, *prev = nullptr;
        while (cur != nullptr)
        {
            int product = cur->val * 2;
            if (product < 10)
                cur->val = product; // Carry doesn't appears.
            else
            {
                cur->val = product % 10;
                // Now let's handle the carry which is always 1.
                if (prev == nullptr) // Create a new node to insert carry.
                {
                    ListNode *newNode = new ListNode(1);
                    head = newNode;
                    head->next = cur;
                }
                else // Node already exists.
                {
                    prev->val += 1;
                }
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};

int main()
{
    // Create the linked list as head = [1, 8, 9]:
    ListNode *head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    Solution solution;
    ListNode *newHead = solution.doubleIt(head);
    cout << "Output: ";
    while (newHead != nullptr)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}