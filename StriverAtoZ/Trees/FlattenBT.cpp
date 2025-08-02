// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#include "TreeNode.h"

class Solution
{
public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        // reversed preorder
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};