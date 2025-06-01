// https://leetcode.com/problems/binary-tree-right-side-view/
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

// BFS - level order traversal
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
            TreeNode *endNode;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = q.front();
                endNode = currentNode; // we can also make use of currentLevelList and grab the last one but we can just store the last one as endNode
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