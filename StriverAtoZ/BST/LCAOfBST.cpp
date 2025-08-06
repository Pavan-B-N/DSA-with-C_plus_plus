// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include "Node.h"

class Solution
{
public:
    // O(n)
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        if (!root || root == p || root == q)
        {
            return root;
        }
        Node *left = lowestCommonAncestor(root->left, p, q);
        Node *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;
        return left ? left : right;
    }
};

class Solution
{
public:
    // o(logn)
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
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