// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
#include "TreeNode.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        return dfs(root, INT_MIN);
    }

private:
    // Helper DFS function to count good nodes
    int dfs(TreeNode *node, int maxSoFar)
    {
        if (!node)
            return 0;

        // Check if the current node is "good"
        int isGood = (node->val >= maxSoFar) ? 1 : 0;

        // Update max value for the path
        maxSoFar = max(maxSoFar, node->val);

        int leftCount = dfs(node->left, maxSoFar);
        int rightCount = dfs(node->right, maxSoFar);

        return isGood + leftCount + rightCount;
    }
};
