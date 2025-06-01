/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

*/

// https://leetcode.com/problems/symmetric-tree/description/

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

// Recursive Solution (DFS – Depth First Search)
// T.C = O(N) – where N is the number of nodes.
// S.C
// O(H) due to the recursion call stack, where H = height of tree
// Worst case: O(N) for a skewed tree.
// Average/Balanced case: O(log N)
// No extra space is used aside from the call stack – so sometimes it's referred to as O(1) extra space.
class Solution
{
public:
    // using recursion
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        // using subtree concepts
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *r1, TreeNode *r2)
    {
        // r1 = root,left,right
        // r2 = root,right,left
        if (r1 == nullptr || r2 == nullptr)
        {
            return r1 == r2;
        }

        return r1->val == r2->val && isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
    }
};

// bfs
// T.C = O(N) – every node is visited.
// S.C
// O(N) – because:
// You store all nodes level-by-level, including nullptr children, in the vector<vector<TreeNode*>> result.
// So this clearly uses more memory than the recursive DFS version.
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        vector<vector<TreeNode *>> result = levelOrderTraversal(root);

        // two pointer method
        for (auto &list : result)
        {
            // compare start and end pointer elements
            int i = 0;
            int j = list.size() - 1;
            while (i < j)
            {
                // since elements are pointer so we cannot directly compare it
                if ((list[i] == nullptr && list[j] != nullptr) ||
                    (list[i] != nullptr && list[j] == nullptr))
                {
                    return false;
                }
                if ((list[i] != nullptr && list[j] != nullptr) &&
                    list[i]->val != list[j]->val)
                {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
    vector<vector<TreeNode *>> levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode *> queue;
        vector<vector<TreeNode *>> result;
        queue.push(root);

        while (!queue.empty())
        {
            int levelSize = queue.size();
            vector<TreeNode *> currentLevelList;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = queue.front();
                queue.pop();

                currentLevelList.push_back(currentNode);
                if (currentNode == nullptr)
                {
                    // if we are allowed to store integer then we can store the
                    // negative number less that 100 so we can identify the
                    // nullptr
                    continue;
                }
                queue.push(currentNode->left);
                queue.push(currentNode->right);
            }
            result.push_back(currentLevelList);
        }

        return result;
    }
};
