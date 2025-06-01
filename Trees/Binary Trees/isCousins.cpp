/*
given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth(level) with different parents.
i.e same level but different parent
*/

// https://leetcode.com/problems/cousins-in-binary-tree/

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        TreeNode *xNode = findNode(root, x);
        TreeNode *yNode = findNode(root, y);

        return (
            (level(root, xNode, 0) == level(root, yNode, 0)) && !isSibling(root, xNode, yNode));
    }

    bool isSibling(TreeNode *node, TreeNode *x, TreeNode *y)
    {
        if (node == nullptr)
        {
            return false;
        }
        return ((node->left == x && node->right == y) ||
                (node->left == y && node->right == x) ||
                isSibling(node->left, x, y) || isSibling(node->right, x, y));
    }

    TreeNode *findNode(TreeNode *root, int x)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == x)
        {
            return root;
        }
        TreeNode *node = findNode(root->left, x);
        if (node == nullptr)
        {
            node = findNode(root->right, x);
        }
        return node;
    }

    int level(TreeNode *root, TreeNode *x, int lev)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root == x)
        {
            return lev;
        }
        int left = level(root->left, x, lev + 1);
        if (left)
        {
            return left;
        }
        return level(root->right, x, lev + 1);
        ;
    }
};