#include <bits/stdc++.h>
using namespace std;

// Print the nodes using Level-Order-Traversal with each level in a new line.

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

    if (data == -1)
        return NULL; // Base case for recursion.
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




// LEVEL-ORDER-TRAVERSAL IN NEW LINE:
// Intuition: We need some sort of marking to keep track of end of level, such as a NULL value.
// It is safe to assume that NULL will be inserted at end of a level. And also when all children of that level would have been inserted in queue.
// Algorithm: Initially insert the root followed by a NULL.
// Append node's all children, and insert NULL. And repeat till empty queue.

// Time: O(N)
// Space: O(N)

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // Initially, push root node to queue.
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL); // Insert NULL only when queue is non-empty because if its empty we would keep on inserting more NULLs and "endl" statements leading to infinite loop.
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}


int main()
{
    Node *root = NULL;
    root = buildTree();
    levelOrderTraversal(root);

    return 0;
}