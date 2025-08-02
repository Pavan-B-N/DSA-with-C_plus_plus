// https://www.naukri.com/code360/problems/path-in-a-tree_3843990?leftPanelTabValue=PROBLEM
#include "TreeNode.h"
#include <vector>
using namespace std;

vector<int> pathInATree(TreeNode *root, int x)
{
    vector<int> path;
    getPaths(root, path, x);
    return path;
}

bool getPaths(TreeNode *root, vector<int> &path, int x)
{
    if (!root)
        return false;

    path.push_back(root->val);

    if (root->val == x)
        return true;

    // Recurse left and right
    if (getPaths(root->left, path, x) || getPaths(root->right, path, x))
    {
        return true;
    }

    // Backtrack if not found
    path.pop_back();
    return false;
}
