/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the longest path between any two nodes in a tree. This path may or may not pass through the root.

*/
// https://leetcode.com/problems/diameter-of-binary-tree/description/

#include <iostream>
#include <algorithm>
#include <TreeNode.h>
using namespace std;

//dfs
int height(TreeNode *node,int &diameter){
    if(node==nullptr){
        return 0;
    }
    int leftHeight=height(node->left,diameter);
    int rightHeight=height(node->right,diameter);

    int dia=leftHeight+rightHeight;
    diameter=max(dia,diameter);

    return 1+max(leftHeight,rightHeight);
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter=0;
    height(root,diameter);
    return diameter;
}