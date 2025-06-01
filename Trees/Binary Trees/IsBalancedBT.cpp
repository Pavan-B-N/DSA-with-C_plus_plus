/*
https://leetcode.com/problems/balanced-binary-tree/description/

Given a binary tree, determine if it is
height-balanced

Input: root = [3,9,20,null,null,15,7]
Output: true

*/
#include "TreeNode.h"
#include <iostream>
#include <cmath>
using namespace std;

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