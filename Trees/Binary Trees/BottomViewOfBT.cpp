// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "Node.h"
using namespace std;

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<vector<int>> verticalOrder = verticalTraversal(root);
        vector<int> ans;
        for (auto vec : verticalOrder)
        {
            int n = vec.size() - 1;
            ans.push_back(vec[n]);
        }
        return ans;
    }

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