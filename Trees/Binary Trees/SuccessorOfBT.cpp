/*
input=[3,4,8,12,14,null,null,null,null,36,9]
successor of 14
ouput=36
successor is the right most element
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// definition of TreeNode is given in leetcode
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int successor(TreeNode *root, int target)
{
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        int levelSize = queue.size();
        TreeNode *currentNode = queue.front();
        queue.pop();

        if (currentNode->left != nullptr)
        {
            queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            queue.push(currentNode->right);
        }

        if (currentNode->val == target)
        {
            break;
        }
    }
    return queue.front()->val;
}