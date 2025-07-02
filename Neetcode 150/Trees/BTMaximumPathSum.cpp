// https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include "TreeNode.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0;

        // Only take positive paths, else take 0
        int left = max(0, dfs(root->left, maxSum));
        int right = max(0, dfs(root->right, maxSum));

        int currentPathSum = root->val + left + right;
        maxSum = max(maxSum, currentPathSum);

        return root->val + max(left, right);
    }
};
