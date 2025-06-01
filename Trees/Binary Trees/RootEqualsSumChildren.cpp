// https://leetcode.com/problems/root-equals-sum-of-children/

#include "TreeNode.h"
class Solution
{
public:
    // tree contains exactly 3 nodes
    bool checkTree(TreeNode *root)
    {
        return root->val == root->left->val + root->right->val;
    }
};