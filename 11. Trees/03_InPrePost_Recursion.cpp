#include <bits/stdc++.h>
using namespace std;

// Implement In-Order, Pre-Order and Post-Order-Traversals in Binary Tree.
// Recursion approach is used.

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node *buildTree()
{
    int data;
    cout << "Enter the node's data ";
    cin >> data;

    if (data == -1) return NULL; // Base case for recursion.
    else
    {
        Node *root = new Node(data);
        cout << "Enter data of left child of node " << root->data << endl;
        root->left = buildTree();
        cout << "Enter data of right child of node " << root->data << endl;
        root->right = buildTree();
        return root;
    }
}





// ------- Binary Tree Inorder Traversal -------
void inorderTraversal(Node *root)
{
    if (root == NULL) return;
    // Left-Node-Right or LNR.
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


// ------- Binary Tree Preorder Traversal -------
void preorderTraversal(Node *root)
{
    if (root == NULL) return;
    // Node-Left-Right or NLR.
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


// ------- Binary Tree Postorder Traversal -------
void postorderTraversal(Node *root)
{
    if (root == NULL) return;
    // Left-Right-Node or LRN.
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}


int main()
{
    Node *root = NULL;
    root = buildTree();
    cout << endl << "In-Order ";
    inorderTraversal(root);
    cout << endl << "Pre-Order ";
    preorderTraversal(root);
    cout << endl << "Post-Order ";
    postorderTraversal(root);

    return 0;
}