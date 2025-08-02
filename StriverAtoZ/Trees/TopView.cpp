#include "Node.h"
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution
{
public:
    // Time complexity : O(n)
    vector<int> topView(Node *root)
    {
        // O(n)
        vector<vector<int>> verticalOrder = verticalTraversal(root);
        vector<int> ans;
        // O(n)
        for (auto vec : verticalOrder)
        {
            ans.push_back(vec[0]);
        }
        return ans;
    }

    // Time complexity : O(n) no sorting involved
    vector<vector<int>> verticalTraversal(Node *root)
    {
        if (!root)
            return {};

        map<int, vector<int>> verticalMap;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int levelSize = q.size();
            map<int, vector<int>> levelMap;

            // simple bfs or level order traversal
            for (int i = 0; i < levelSize; ++i)
            {
                Node *currNode = q.front().first;
                int col = q.front().second;
                q.pop();

                levelMap[col].push_back(currNode->data);

                if (currNode->left)
                    q.push({currNode->left, col - 1});
                if (currNode->right)
                    q.push({currNode->right, col + 1});
            }

            for (auto &it : levelMap)
            {
                auto &vec = it.second;
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