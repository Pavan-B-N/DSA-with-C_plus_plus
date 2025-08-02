// https://www.geeksforgeeks.org/problems/children-sum-parent/1
#include "Node.h"

class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    int isSumProperty(Node *root)
    {
        if (!root || isLeaf(root))
        {
            return true;
        }

        int sum = 0;
        if (root->left)
            sum += root->left->data;
        if (root->right)
            sum += root->right->data;

        return root->data == sum && isSumProperty(root->left) && isSumProperty(root->right);
    }
};