#include "Node.h"

class Solution
{
public:
    Node *insertIntoBST(Node *root, int val)
    {
        if (!root)
            return new Node(val);
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};