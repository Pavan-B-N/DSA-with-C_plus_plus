/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include <iostream>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

// time complexity = o(n)
// space complexity = o(n) = auxillary stack space
int maxDepth(TreeNode* root) {
    if(root==nullptr){
        return 0;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);

    return 1+max(left,right);
}