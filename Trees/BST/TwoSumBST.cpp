// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;
// Time Complexity: O(N)
// In the worst case, every node of the tree is visited at most once
// by next() and before(), so total work is linear in the number of nodes.

// Space Complexity: O(H)
// H is the height of the tree; each stack (s1, s2) holds at most H nodes at any time.

class Solution
{
    stack<TreeNode *> s1; // stores left nodes , next, ascending
    stack<TreeNode *> s2; // stores right node, before , descending

    void storeLeftNodes(TreeNode *node)
    {
        while (node)
        {
            s1.push(node);
            node = node->left;
        }
    }
    void storeRightNodes(TreeNode *node)
    {
        while (node)
        {
            s2.push(node);
            node = node->right;
        }
    }

    int next()
    {
        TreeNode *node = s1.top();
        s1.pop();
        storeLeftNodes(node->right);
        return node->val;
    }

    // return greater element
    int before()
    {
        TreeNode *node = s2.top();
        s2.pop();

        storeRightNodes(node->left);
        return node->val;
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        storeLeftNodes(root);
        storeRightNodes(root);

        int i = next();
        int j = before();

        while (i != j)
        {
            int sum = i + j;
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                i = next();
            }
            else
            {
                j = before();
            }
        }

        return false;
    }
};