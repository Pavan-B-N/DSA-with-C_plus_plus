// https://leetcode.com/problems/maximum-depth-of-binary-tree/
#include "TreeNode.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};