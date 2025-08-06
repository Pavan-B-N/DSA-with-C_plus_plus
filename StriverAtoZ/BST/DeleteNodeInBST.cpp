// https://leetcode.com/problems/delete-node-in-a-bst/
#include "Node.h"

class Solution
{
public:
    Node *deleteNode(Node *root, int key)
    {
        if (!root)
            return nullptr;

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // they are equal
            // no child
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }

            // 1 child
            if (root->left == nullptr)
            {
                return root->right;
            }
            else if (root->right == nullptr)
            {
                return root->left;
            }

            // two children
            root->val = inorderSuccesor(root);
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
    int inorderSuccesor(Node *node)
    {
        node = node->right;
        int value = -1;
        while (node)
        {
            value = node->val;
            node = node->left;
        }
        return value;
    }
};