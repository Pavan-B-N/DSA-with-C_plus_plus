// https://leetcode.com/problems/diameter-of-binary-tree/
#include "TreeNode.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        findDiameter(root, diameter);
        return diameter;
    }
    int findDiameter(TreeNode *root, int &diameter)
    {
        if (!root)
        {
            return 0;
        }
        // find maxHeight
        int left = findDiameter(root->left, diameter);
        int right = findDiameter(root->right, diameter);
        int dia = left + right;
        diameter = max(dia, diameter);
        return 1 + max(left, right);
    }
};