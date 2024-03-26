// The depth of a node is a length of the path from root to that node
// max depth of a tree is a length of the longest path from root node to the leaf node which is sam as height of a binary tree
// maxDepth of binary tree == height og a bt
#include <iostream>
#include <algorithm>
#include "BinarySearchTree.h"
using namespace std;
// g++ .\BinarySearchTree.cpp .\DepthOfBT.cpp

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node
int maxDepth(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}
int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);

    int depthOfTree = maxDepth(bst.root);
    cout << "Maximum depth of a binary tree is " << depthOfTree << endl;
    return 0;
}