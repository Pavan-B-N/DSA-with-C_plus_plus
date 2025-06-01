/*
https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.

 The boundary includes

left boundary (nodes on left excluding leaf nodes)
leaves (consist of only the leaf nodes)
right boundary in reverse direction(nodes on right excluding leaf nodes)

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    // time complexity = o(H) + o(H) + o(N) = o(N)
    // space complexity= o(N)
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if (root == NULL) 
            return ans;
        if (!isLeaf(root))
            ans.push_back(root->data);
        addLeftBound(root, ans);  // o(H)
        addLeaves(root, ans);     // o(N)
        addRightBound(root, ans); // o(H)

        return ans;
    }

    bool isLeaf(Node *node)
    {
        if (node->left == NULL && node->right == NULL)
        {
            return true;
        }
        return false;
    }

    void addLeftBound(Node *root, vector<int> &ans)
    {
        root = root->left;
        while (root)
        {
            if (!isLeaf(root))
                ans.push_back(root->data);
            if (root->left)
                root = root->left;
            else
                root = root->right;
        }
    }

    void addRightBound(Node *root, vector<int> &ans)
    {
        root = root->right;
        stack<int> st;
        while (root)
        {
            if (!isLeaf(root))
                st.push(root->data);
            if (root->right)
                root = root->right;
            else
                root = root->left;
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }

    void addLeaves(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
};