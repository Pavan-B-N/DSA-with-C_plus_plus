/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
*/
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include "TreeNode.h"|

using namespace std;
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        map<int, vector<int>> verticalMap;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int levelSize = q.size();
            map<int, vector<int>> levelMap;

            // simple bfs or level order traversal
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *currNode = q.front().first;
                int col = q.front().second;
                q.pop();

                levelMap[col].push_back(currNode->val);

                if (currNode->left)
                    q.push({currNode->left, col - 1});
                if (currNode->right)
                    q.push({currNode->right, col + 1});
            }

            for (auto &it : levelMap)
            {
                auto &vec = it.second;
                sort(vec.begin(), vec.end());
                verticalMap[it.first].insert(verticalMap[it.first].end(), vec.begin(), vec.end());
            }
        }

        vector<vector<int>> result;
        for (auto &it : verticalMap)
        {
            result.push_back(it.second);
        }

        return result;
    }
};