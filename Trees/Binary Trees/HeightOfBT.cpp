// The depth of a node is a length of the path from root to that node
// max depth of a tree is a length of the longest path from root node to the leaf node which is same as height of a binary tree
// maxDepth of binary tree == height og a bt
#include "TreeNode.h"
#include <algorithm>
using namespace std;

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}
