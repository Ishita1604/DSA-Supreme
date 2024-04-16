#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// ALGORITHM:
// Traverse the tree using BFS or DFS.
// Maintain depth.
// Stop at depth - 1.
// Insert the given nodes and make existing nodes its children.
// Rest levels remain the same.


void dfs(TreeNode *root, int val, int depth, int curDepth)
{
    if (root == nullptr)
        return;
    if (curDepth < depth - 1)
    {
        dfs(root->left, val, depth, curDepth + 1);
        dfs(root->right, val, depth, curDepth + 1);
    }
    if (curDepth == depth - 1)
    {
        // Extracting the existing left and right children.
        TreeNode *curLeftChild = root->left;
        TreeNode *curRightChild = root->right;

        // Creating the nodes that need to be added.
        TreeNode *newLeftChild = new TreeNode(val);
        TreeNode *newRightChild = new TreeNode(val);

        // Now connect the existing and new nodes.
        root->left = newLeftChild;
        root->right = newRightChild;
        newLeftChild->left = curLeftChild;
        newRightChild->right = curRightChild;
    }
}

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *newRootNode = new TreeNode(val);
        newRootNode->left = root;
        return newRootNode;
    }
    dfs(root, val, depth, 1);
    return root;
}