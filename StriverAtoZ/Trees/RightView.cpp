// https://leetcode.com/problems/binary-tree-right-side-view/
#include "TreeNode.h"
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            TreeNode *endNode = q.back();
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = q.front();
                q.pop();
                if (currentNode->left != nullptr)
                {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    q.push(currentNode->right);
                }
            }
            result.push_back(endNode->val);
        }
        return result;
    }
};