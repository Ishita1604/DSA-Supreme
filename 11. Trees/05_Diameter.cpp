#include <bits/stdc++.h>
using namespace std;

/* __________________________________________________________________________________________
LeetCode 543: Diameter of Binary Tree
Link: [https://leetcode.com/problems/diameter-of-binary-tree/]

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

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
    // FORMULA: H = (max(height(left) + height(right)) + 1) is used.
    if (root == NULL)
        return 0; // Base case for recursion.

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    int height = max(leftHeight, rightHeight) + 1;
    return height;
}


// Intuition: The diameter is the longest path between two leaf nodes, either passing through the current node or entirely within the left or right subtree.
// Algorithm: Calculate the height of left and right subtrees, and sum these heights for the diameter through the current node.
// Compare it with the diameters of left and right subtrees to return the maximum diameter, incase it doesn't pass through the root.
// Formula: D = lh + rh + 1 is used.

// TIME: O(N^2) as diameter is called for each node, which further calls the height function for each node.
// SPACE: O(N) worst case (skewed tree), O(log N) best case (balanced tree).

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL) return 0;

    int d1 = maxDepth(root->left) + maxDepth(root->right) + 1; // Longest path through the root.
    int d2 = diameterOfBinaryTree(root->left);                 // Longest path through left sub-tree excluding root.
    int d3 = diameterOfBinaryTree(root->right);                // Longest path through right sub-tree excluding root.

    // Return the maximum of the three, subtracting 1 to convert nodes to edges.
    return max(max(d1, d2), d3) - 1;
}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
