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

// Using Recursion:
// Time: O(N)
// Space: O(N)
int sumNodes(TreeNode *root, int currentSum)
{
    if (root == NULL)
        return 0;
    currentSum = currentSum * 10 + root->val; // As we go, keep on updating `currentSum`.

    if (root->left == NULL && root->right == NULL)
        return currentSum; // Reached leaf node, so return `currentSum` and add it to `totalSum`.

    int leftSum = sumNodes(root->left, currentSum);
    int rightSum = sumNodes(root->right, currentSum);
    return leftSum + rightSum;
}

int sumNumbers1(TreeNode *root)
{
    int currentSum = 0;
    return sumNodes(root, currentSum);
}

int main()
{
    // Input:
    // root = [4,9,0,5,1]:
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    cout << "Total sum of all root-to-leaf numbers is: " << sumNumbers1(root) << endl;

    // Deallocate memory.
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}