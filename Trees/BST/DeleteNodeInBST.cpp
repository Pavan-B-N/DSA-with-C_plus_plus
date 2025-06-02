// https://leetcode.com/problems/delete-node-in-a-bst/

#include "TreeNode.h"

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }

        // search key
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
            // we found  a key

            // no children
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

            // 2 children
            root->val = inorderSuccessor(root);

            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
    // minValue from right sub tree
    int inorderSuccessor(TreeNode *root)
    {
        root = root->right;

        int minVal = -1;
        while (root)
        {
            minVal = root->val;
            root = root->left;
        }

        return minVal;
    }
};