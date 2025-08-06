// https://leetcode.com/problems/recover-binary-search-tree/
#include "Node.h"
#include <algorithm>
#include <vector>
using namespace std;

// optimal
class Solution
{
public:
    Node *first = nullptr;
    Node *second = nullptr;
    Node *prev = nullptr;

    void recoverTree(Node *root)
    {
        inorder(root);
        if (first && second)
        {
            swap(first->val, second->val);
        }
    }

    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);

        // Detect swapped nodes
        if (prev && prev->val > root->val)
        {
            if (!first)
            {
                first = prev;
            }
            second = root;
        }

        prev = root;

        inorder(root->right);
    }
};

//  Time: O(n log n)
// Space: O(n)
// Not optimal
class Solution
{
public:
    void recoverTree(Node *root)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        sort(inorder.begin(), inorder.end());
        int index = 0;
        recoverTree(root, index, inorder);
    }
    // inorderTraversal
    void recoverTree(Node *root, int &index, vector<int> &inorder)
    {
        if (!root)
            return;
        recoverTree(root->left, index, inorder);

        int value = inorder[index++];
        if (root->val != value)
        {
            root->val = value;
        }

        recoverTree(root->right, index, inorder);
    }
    void inorderTraversal(Node *root, vector<int> &inorder)
    {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
};