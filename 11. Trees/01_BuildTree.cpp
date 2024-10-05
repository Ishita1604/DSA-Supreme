#include <bits/stdc++.h>
using namespace std;

// Implement a Binary Tree from scratch.
// Print the nodes using Level-Order-Traversal.
// In Level-Order-Traversal, nodes are visited level by level i.e. top to down, in left to right direction.

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to create node with "value" as the data.
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
        // Step A: Build that node.
        Node *root = new Node(data);
        // Step B: Add its left child.
        cout << "Enter data of left child of node " << root->data << endl;
        root->left = buildTree();
        // Step C: Add its right child.
        cout << "Enter data of right child of node " << root->data << endl;
        root->right = buildTree();
        return root;
    }
}




// LEVEL-ORDER-TRAVERSAL: Each node is visited in the order it appears at each level from left to right.
// Queue data structure to hold the nodes as it offers FIFO, so we move level-by-level from left to right.
// Intuition: Visit a node, then insert its children. When this level gets over, their children get visited, forming level 2, and so on.
// Algorithm: Node is checked from queue, stored in a temporary pointer, then popped and printed.
// Then insert all its children into the queue, first left child, then right child.
// Now next element is checked from queue, and gets printed then children appended, this level gets over, moving on to next level.

// Time: O(N)
// Space: O(N)

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // Initially, push root node to queue.
    q.push(root);
    while (!q.empty())
    {
        // Step A: Store node temporarily.
        Node *temp = q.front();
        // Step B: Pop the front.
        q.pop();
        // Step C: Print visited or stored node.
        cout << temp->data << " ";
        // Step D: Insert its children to queue.
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}


int main()
{
    Node *root = NULL;
    root = buildTree();
    levelOrderTraversal(root);

    return 0;
}
