// https://leetcode.com/problems/same-tree/
#include "TreeNode.h"

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((p == nullptr && q == nullptr))
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // evolution
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};