// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include "TreeNode.h"

// for BST
// Time: O(h) where h is the height of the tree
// Space: O(1) for iterative version, O(h) for recursive stack
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;

        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        return left ? left : right;
    }
};