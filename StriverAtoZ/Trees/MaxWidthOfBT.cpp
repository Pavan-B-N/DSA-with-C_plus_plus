// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include "TreeNode.h"
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        queue<pair<TreeNode *, unsigned long long>> q; //{node,index}
        q.push({root, 1});
        unsigned long long maxWidth = 0;
        while (!q.empty())
        {
            int levelSize = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            unsigned long long width = right - left + 1;
            maxWidth = max(maxWidth, width);

            for (int i = 0; i < levelSize; i++)
            {
                auto node = q.front().first;
                auto index = q.front().second;
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * index});
                if (node->right)
                    q.push({node->right, 2 * index + 1});
            }
        }
        return (int)maxWidth;
    }
};