/*
https://leetcode.com/problems/balanced-binary-tree/description/

Given a binary tree, determine if it is
height-balanced

Input: root = [3,9,20,null,null,15,7]
Output: true

*/
#include <iostream>
#include <cmath>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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