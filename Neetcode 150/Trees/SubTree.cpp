// https://leetcode.com/problems/subtree-of-another-tree/
#include "TreeNode.h"

class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        if (root->val == subRoot->val && isSameTree(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
