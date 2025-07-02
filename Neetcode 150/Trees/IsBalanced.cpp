// https://leetcode.com/problems/balanced-binary-tree/
#include "TreeNode.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        int hl = height(root->left);
        int hr = height(root->right);

        if (abs(hr - hl) > 1)
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
};