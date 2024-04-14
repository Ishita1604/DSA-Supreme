#include <bits/stdc++.h>
using namespace std;

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
    int sum;
    void dfs(TreeNode *node)
    {
        if (node->left != nullptr)
        {
            // Left child exists.
            TreeNode *childNode = node->left;
            if (childNode->left == nullptr && childNode->right == nullptr)
            {
                // It is left leaf node.
                sum += childNode->val;
            }
            dfs(node->left);
        }
        if (node->right != nullptr)
        {
            // Right child exists.
            dfs(node->right);
        }
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        sum = 0;
        dfs(root);
        return sum;
    }
};

int main()
{
    // Input:
    // root = [3,9,20,null,null,15,7]:
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Sum of left leaves is: " << solution.sumOfLeftLeaves(root) << endl;

    // Deallocate memory.
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}