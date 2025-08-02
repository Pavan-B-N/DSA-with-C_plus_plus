// https://leetcode.com/problems/same-tree/
#include "TreeNode.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
        {
            return p == q;
        }
        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};