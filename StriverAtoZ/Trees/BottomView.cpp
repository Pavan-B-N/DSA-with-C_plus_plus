// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
#include "Node.h"
#include <vector>
#include <queue>
#include <map>
using namespace std;

// optimal
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {

        vector<vector<int>> verticalOrder = verticalTraversal(root);
        vector<int> ans;
        // O(n)
        for (auto vec : verticalOrder)
        {
            ans.push_back(vec.back());
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

// improvised space complexity
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {

        vector<int> verticalOrder = verticalTraversal(root);
        vector<int> ans;
        // O(n)
        for (auto ele : verticalOrder)
        {
            ans.push_back(ele);
        }
        return ans;
    }
    // Time complexity : O(n) no sorting involved
    vector<int> verticalTraversal(Node *root)
    {
        if (!root)
            return {};

        map<int, int> verticalMap;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int levelSize = q.size();
            map<int, int> levelMap;

            // simple bfs or level order traversal
            for (int i = 0; i < levelSize; ++i)
            {
                Node *currNode = q.front().first;
                int col = q.front().second;
                q.pop();

                levelMap[col] = (currNode->data);

                if (currNode->left)
                    q.push({currNode->left, col - 1});
                if (currNode->right)
                    q.push({currNode->right, col + 1});
            }

            for (auto &it : levelMap)
            {
                verticalMap[it.first] = it.second;
            }
        }

        vector<int> result;
        for (auto &it : verticalMap)
        {
            result.push_back(it.second);
        }

        return result;
    }
};