// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    // BFS or levelorder traversal
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, unsigned long long>> q; // {node,index}
        q.push({root, 1});
        int maxWidth = 0;

        while (!q.empty())
        {
            int size = q.size();
            unsigned long long firstIndex = q.front().second;
            unsigned long long lastIndex = q.back().second;

            maxWidth =
                max(maxWidth, static_cast<int>(lastIndex - firstIndex + 1));

            for (int i = 0; i < size; ++i)
            {
                auto [node, index] = q.front();
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * index});
                if (node->right)
                    q.push({node->right, 2 * index + 1});
            }
        }

        return maxWidth;
    }
};