// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
#include "Node.h"
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> res;
        if (!root)
        {
            return res;
        }
        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBounds(root->left, res);
        addLeafNodes(root, res);
        addRightBounds(root->right, res);

        return res;
    }
    bool isLeaf(Node *root)
    {
        return root->left == nullptr && root->right == nullptr;
    }
    void addLeftBounds(Node *root, vector<int> &res)
    {
        while (root)
        {
            if (!isLeaf(root))
                res.push_back(root->data);
            if (root->left)
                root = root->left;
            else
                root = root->right;
        }
    }
    void addRightBounds(Node *root, vector<int> &res)
    {
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
            res.push_back(st.top());
            st.pop();
        }
    }

    void addLeafNodes(Node *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        addLeafNodes(root->left, res);
        if (isLeaf(root))
        {
            res.push_back(root->data);
        }
        addLeafNodes(root->right, res);
    }
};