// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include <climits>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN; // tree can contains -ve values os we need cannot initialize to zero
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode *root, int &ans)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        left = max(0, left); // replacing INT_MIN with 0
        right = max(0, right);
        int pathsum = left + right + root->val;
        ans = max(ans, pathsum);
        return max(left, right) + root->val;
    }
};