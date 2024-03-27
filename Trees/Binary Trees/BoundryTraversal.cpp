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

struct Node
{
    int data;
    struct Node *left, *right;
};

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
    stack<int> stk;
    while (root)
    {
        if (!isLeaf(root))
            stk.push(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
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

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data); 
    addLeftBound(root, ans);
    addLeaves(root, ans);
    addRightBound(root, ans);

    return ans;
}
