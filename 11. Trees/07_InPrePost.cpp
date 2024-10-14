#include <bits/stdc++.h>
using namespace std;

// Implement In-Order, Pre-Order and Post-Order-Traversals in Binary Tree.
// Without the use of recursion.

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




// ------- LeetCode 94: Binary Tree Inorder Traversal -------
// Link: [https://leetcode.com/problems/binary-tree-inorder-traversal/]
vector<int> inorderTraversal(Node *root)
{
    vector<int> output;
    if (root == NULL) return output;
    stack<Node*> st;
    Node* node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            // TOP - POP - PRINT:
            if (st.empty()) break;
            node = st.top();
            st.pop();
            output.push_back(node->data);
            node = node->right;
        }
    }
    return output;
}




// ------- LeetCode 144: Binary Tree Preorder Traversal -------
// Link: [https://leetcode.com/problems/binary-tree-preorder-traversal/]

// Visit node, push to stack and output its value. 
// Keep moving left until NULL for left children. 
// When NULL reached, use stack's top to backtrack to the previous node. 
// Then go right and repeat.


vector<int> preorderTraversal(Node *root)
{
    vector<int> output;
    if (root == NULL) return output;
    stack<Node*> st;
    Node* node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            output.push_back(node->data);
            node = node->left;
        }
        else
        {
            if (st.empty()) break;
            node = st.top();
            st.pop();
            node = node->right;
        }
    }
    return output;
}





// ------- LeetCode 145: Binary Tree Postorder Traversal -------
// Link: [https://leetcode.com/problems/binary-tree-postorder-traversal/]

// ---- Approach 1: Using 2 Stacks ----
// In inorder and preorder, we return to the parent node from only one direction, either left or right, allowing the stack to pop linearly in one direction. 
// So one stack is enough.
// In postorder, we must visit both the left and right children before returning to the parent, requiring tracking of both.
// Hence, 2 stacks are needed.

// TIME: O(N)
// SPACE: O(2N)

vector<int> postorderTraversal(Node *root)
{
	vector<int> output;
	if (root == NULL) return output;
	stack<Node *> st1, st2;
	st1.push(root); // Initially push the root to stack 1.

	while (!st1.empty())
	{
		// TOP - POP - PUSH:
		root = st1.top();
		st1.pop();
		st2.push(root);
		// Then insert its left and right children respectively.
		if (root->left) st1.push(root->left);
        if (root->right) st1.push(root->right);
	}

	while (!st2.empty()) // Consists nodes in reverse post-order, so pop out using LIFO.
	{
		output.push_back(st2.top()->data);
		st2.pop();
	}
	return output;
}




// ---- Approach 2: Using 1 Stack ----
// TIME: O(2N)
// SPACE: O(N)

vector<int> postorderTraversal2(Node *root)
{
	vector<int> output;
	if (root == NULL) return output;
	stack<Node *> st;
    Node* curr = root;

	while (curr != NULL || !st.empty())
	{
		if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right; // Move to the right subtree.
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                output.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    output.push_back(temp->data);
                }
            }
            else curr = temp;
        }
	}
	return output;
}




int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    
    vector<int> output1 = inorderTraversal(root);
    cout << endl << "In-Order ";
    for (int x : output1)
        cout << x << " ";

    vector<int> output2 = preorderTraversal(root);
        cout << endl << "Pre-Order ";
        for (int x : output2)
            cout << x << " ";

    vector<int> output3 = postorderTraversal(root);
        cout << endl << "Post-Order (Approach 1) ";
        for (int x : output3)
            cout << x << " ";

    vector<int> output4 = postorderTraversal2(root);
        cout << endl << "Post-Order (Approach 2) ";
        for (int x : output4)
            cout << x << " ";

    return 0;
}