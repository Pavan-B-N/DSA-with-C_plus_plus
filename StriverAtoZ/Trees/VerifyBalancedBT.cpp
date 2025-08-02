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
            return true;
        int hl = height(root->left);
        int hr = height(root->right);

        if (abs(hl - hr) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
};