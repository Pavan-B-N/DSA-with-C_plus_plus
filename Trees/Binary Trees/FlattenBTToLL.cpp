/*
. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }

        // reversed preorder
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev=root;

    }
};