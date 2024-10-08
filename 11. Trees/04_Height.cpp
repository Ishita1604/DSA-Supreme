#include <bits/stdc++.h>
using namespace std;

/* __________________________________________________________________________________________
LeetCode 104: Maximum Depth of Binary Tree
Link: [https://leetcode.com/problems/maximum-depth-of-binary-tree/]

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3, 9, 20, null, null, 15, 7]
Output: 3

Example 2:
Input: root = [1, null, 2]
Output: 2

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


int maxDepth(TreeNode *root)
{
    // Maximum depth or longest path is the deeper of left and right subtrees + 1 for the current node.
    // Formula: H = max(lh, rh) + 1 is used.

    // Time: O(N)
    // Space: O(N)

    if (root == NULL) return 0; // Base case for recursion.

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return max(lh, rh) + 1;
}


int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum depth of the tree: " << maxDepth(root) << endl;

    return 0;
}