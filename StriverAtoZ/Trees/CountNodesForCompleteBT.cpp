// https://leetcode.com/problems/count-complete-tree-nodes/description/
#include "TreeNode.h"
// Design an algorithm that runs in less than O(n) time complexity
// A complete binary tree is a type of binary tree where all levels are fully filled, except possibly for the last level. If the last level is not entirely filled, the nodes in that level are arranged from left to right, leaving no gaps in between them.

// O(n)
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return 1 + left + right;
    }
};

// time complexity is o((logN)^2)
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        // O(log N) to find left height
        int lh = findHeightLeft(root);

        // O(log N) to find right height
        int rh = findHeightRight(root);

        if (lh == rh)
        {
            // If left and right heights are equal, it's a perfect binary tree means all levels are completely filled
            // Node count = 2^h - 1 → O(1)
            return (1 << lh) - 1;
        }

        // Otherwise, recursively count left and right subtree nodes
        // Each recursive call takes O(log N) time for height computation
        // and at most O(log N) levels → Total time: O((log N)^2)
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Computes height by going down the left-most path
    int findHeightLeft(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++; // O(1) per level
            node = node->left;
        }
        // Total time = O(log N) for a complete binary tree
        return height;
    }

    // Computes height by going down the right-most path
    int findHeightRight(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++; // O(1) per level
            node = node->right;
        }
        // Total time = O(log N) for a complete binary tree
        return height;
    }
};
