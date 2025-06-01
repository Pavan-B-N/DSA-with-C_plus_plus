// Check if all leaf nodes are at same level or not
// Given a Binary Tree, check if all leaves are at same level or not.

#include <iostream>
#include <queue>
#include "Node.h"
using namespace std;
// https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
class Solution
{
public:
    bool check(Node *root)
    {
        int leafLevel = -1;                  
        return checkUtil(root, 1, leafLevel);
    }

    bool checkUtil(Node *root, int level, int &leafLevel)
    {
        if (root == NULL)
            return true;

        // isLeaf
        if (root->left == NULL && root->right == NULL)
        {
            if (leafLevel == -1)
            {
                leafLevel = level;
                return true;
            }
            return (level == leafLevel);
        }

        return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
    }
};
