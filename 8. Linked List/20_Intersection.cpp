/**** LeetCode 160: Intersection of Two Linked Lists ****/

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return NULL.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
}


int getLength(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}


// HASHMAP APPROACH:
// Store nodes of first list in hash map.
// Then check presence of each node of second list in hash map, identifying the intersection point.

// TIME: O(N + M)
// SPACE: O(N)
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode *, int> umap;
    ListNode *curr = headA;
    while (curr != NULL)
    {
        umap[curr] = 1;
        curr = curr->next;
    }
    curr = headB;
    while (curr != NULL)
    {
        if (umap[curr])
            return curr;
        curr = curr->next;
    }
    return NULL;
}


// 2 POINTER APPROACH:
// Maintain two pointers for each list, and find the difference in lengths.
// Move the longer list's pointer by the difference in steps.
// Now, if we move both one-by-one, we'll encounter the intersection node somewhere.

// TIME: O(N) + O(M) + O(|N-M|) + O(K)=> O(N + M)
// SPACE: O(1)
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    if (headA == headB)
        return headA;

    ListNode *tempA = headA;
    ListNode *tempB = headB;

    int lenA = getLength(headA); // O(N)
    int lenB = getLength(headB); // O(M)
    int diff = abs(lenA - lenB);

    if (lenA > lenB)
    {
        while (diff--) // O(|N-M|)
            tempA = tempA->next;
    }
    else
    {
        while (diff--) // O(|M-N|)
            tempB = tempB->next;
    }
    // Both pointers are equally aligned.
    while (tempA != tempB) // O(K) where K is the distance from the starting point to the intersection.
    {
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return tempA;
}


// OPTIMIZED 2-POINTER APPROACH:
// Start by moving both pointers simultaneously from the heads of the two lists.
// When either pointer reaches the end of its list, redirect it to the head of the other list.
// This effectively equalizes the distance traveled by both pointers.
// After traversing both lists, the pointers will either meet at the intersection node or both reach NULL.
// This approach avoids the need to calculate the length of both lists or their difference.

// TIME: O(2*max(N, M))
// SPACE: O(1)
ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB)
{
    ListNode *tempA = headA;
    ListNode *tempB = headB;

    // Traverse both lists to find the end.
    while (tempA != NULL && tempB != NULL) // O(min(N, M))
    {
        tempA = tempA->next;
        tempB = tempB->next;
    }

    // Re-assign pointer to the head of linked list.
    if (tempA == NULL)
    {
        tempA = headB;
        while (tempB != NULL) // O(|M-N|)
        {
            tempB = tempB->next;
            tempA = tempA->next;
        }
        tempB = headA;
    }
    else
    {
        tempB = headA;
        while (tempA != NULL) // O(|N-M|)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        tempA = headB;
    }

    // Traverse until intersection or end.
    while (tempA != tempB) // O(K) where K is the distance from the starting point to the intersection.
    {
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return tempA;
}


int main()
{
    ListNode *head1 = new ListNode(1);
    ListNode *second1 = new ListNode(9);
    ListNode *third1 = new ListNode(1);
    ListNode *fourth1 = new ListNode(3);
    ListNode *fifth1 = new ListNode(4);
    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;

    ListNode *head2 = new ListNode(2);
    head2->next = third1; // Intersection of both lists.

    print(head1);
    print(head2);

    // ListNode *res = getIntersectionNode1(head1, head2);
    // ListNode *res = getIntersectionNode2(head1, head2);
    ListNode *res = getIntersectionNode3(head1, head2);
    cout << "Node of Intersection is " << res->val << endl;

    return 0;
}