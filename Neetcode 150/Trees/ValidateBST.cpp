// https://leetcode.com/problems/validate-binary-search-tree/
#include "TreeNode.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    bool validate(TreeNode *node, long minVal, long maxVal)
    {
        if (!node)
        {
            return true;
        }
        if (node->val <= minVal || node->val >= maxVal)
        {
            return false;
        }
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};