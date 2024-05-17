#include <bits/stdc++.h>
using namespace std;

// Time: O(N) where N is the number of nodes in the tree.
// Space: O(N)

// Definition for a binary tree node:
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *solve(TreeNode *node, int target)
    {
        if (node == nullptr)
            return nullptr; // In-case tree becomes empty.

        // Recursion conditions to traverse the tree's node on both sides.
        node->left = solve(node->left, target);
        node->right = solve(node->right, target);

        if (node->left == nullptr && node->right == nullptr && node->val == target)
            return nullptr; // Basically we didn't delete the leaf node, but assigned it as NULL.
        return node;        // If node != target, simply return it, no deletion.
    }

    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        root = solve(root, target); // Assigning value back to the root.
        return root;
    }
};