/*
array represents the binary tree in the form of level order traversal
arr=[1,2,3,4,null,null,5] Note: null is represented as -1 in the array
preorder=[1,2,4,null,3,null,5] or [1,2,4,3,5]
*/
#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode *buildTree(vector<int> &nums)
{
    int n = nums.size();
    // INT_MIN = null node
    if (n == 0 || nums[0] == INT_MIN)
    {
        return nullptr;
    }

    queue<TreeNode *> queue;
    TreeNode *root = new TreeNode(nums[0]);
    queue.push(root);
    int i = 0; // zero based indexing because vec is zero based storage
    // left = 2 * i + 1
    // right = 2 * i + 2

    while (!queue.empty())
    {
        TreeNode *currentNode = queue.front();
        queue.pop();

        if (currentNode != nullptr && (2 * i + 1) < n)
        {
            int lc = nums[2 * i + 1]; // 2k
            int rc = (2 * i + 2) < n ? nums[(2 * i + 2)] : INT_MIN;
            // INT_MIN = null node
            if (lc != INT_MIN)
            {
                currentNode->left = new TreeNode(lc);
                queue.push(currentNode->left);
            }
            if (rc != INT_MIN)
            {
                currentNode->right = new TreeNode(rc);
                queue.push(currentNode->right);
            }
        }
        i++;
    }
    return root;
}
