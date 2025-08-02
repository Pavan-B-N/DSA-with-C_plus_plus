// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
#include "Node.h"
#include "TreeNode.h"
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> path;
        getPaths(root, ans, path);
        return ans;
    }

    bool isLeaf(Node *node)
    {
        return node && !node->left && !node->right;
    }

    void getPaths(Node *root, vector<vector<int>> &ans, vector<int> &path)
    {
        if (!root)
            return;

        path.push_back(root->data);

        if (isLeaf(root))
        {
            ans.push_back(path);
        }
        else
        {
            getPaths(root->left, ans, path);
            getPaths(root->right, ans, path);
        }

        path.pop_back(); // Backtrack
    }
};

// https://leetcode.com/problems/binary-tree-paths/
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string path;
        getPaths(root, ans, path);
        return ans;
    }
    bool isLeaf(TreeNode *node)
    {
        return node && !node->left && !node->right;
    }

    void getPaths(TreeNode *root, vector<string> &ans, string &path)
    {
        if (!root)
        {
            return;
        }
        int len = path.size();

        path += to_string(root->val);

        if (isLeaf(root))
        {
            ans.push_back(path);
        }
        else
        {
            path += "->";
            getPaths(root->left, ans, path);
            getPaths(root->right, ans, path);
        }
        path.resize(len);
    }
};