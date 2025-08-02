// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
#include "TreeNode.h"
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Time complexity: O(n log n) due to sorting
// Space Complexity: O(n)
// n= number of nodes in the tree
// O(n) for traversal + O(m log k) for sorting, where:
//   - n = total nodes
//   - m = number of column entries across all levels
//   - k = max number of nodes per column per level
// Worst-case m = O(n), k = O(n) ⇒ O(n log n)

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<int>> verticalMap; //{col,values}

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int levelSize = q.size();
            map<int, vector<int>> levelMap;

            for (int i = 0; i < levelSize; i++)
            {
                auto node = q.front().first;
                auto col = q.front().second;
                q.pop();

                levelMap[col].push_back(node->val);

                if (node->left)
                {
                    q.push({node->left, col - 1});
                }

                if (node->right)
                {
                    q.push({node->right, col + 1});
                }
            }

            for (auto &it : levelMap)
            {
                int col = it.first;
                auto &vec = it.second;

                sort(vec.begin(), vec.end());

                verticalMap[col].insert(verticalMap[col].end(), vec.begin(), vec.end());
            }
        }
        vector<vector<int>> res;
        for (auto &it : verticalMap)
        {
            res.push_back(it.second);
        }
        return res;
    }
};