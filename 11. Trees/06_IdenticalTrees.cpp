#include <bits/stdc++.h>
using namespace std;

/* __________________________________________________________________________________________
LeetCode 100: Same Tree
Link: [https://leetcode.com/problems/same-tree/]

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1, 2, 3], q = [1,2, 3]
Output: true

Example 2:
Input: p = [1, 2], q = [1, null, 2]
Output: false

_____________________________________________________________________________________________
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// If the nodes, their left subtree, and right subtree are equal, the trees are identical.
// TIME: O(N) where N is number of nodes.
// SPACE: O(N) worst case (skewed tree), O(log N) average case.
bool isSameTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    if (root1->val == root2->val) // If the current node's value is equal.
    {
        // Check if left and right sub-trees are also equal.
        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }

    return false;
}



int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    // root2->right->right->right = new TreeNode(71);

    bool ans = isSameTree(root1, root2);
    cout << ans << endl;

    return 0;
}