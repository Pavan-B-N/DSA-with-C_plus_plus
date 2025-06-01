// https://leetcode.com/problems/path-sum/description/
#include <iostream>
#include "TreeNode.h"
using namespace std;

// makes use of preorder traversal
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==nullptr){
        return false;
    }
    if(root->val==targetSum && root->left==nullptr && root->right==nullptr){
        return true;
    }
    bool left=hasPathSum(root->left,targetSum-root->val);
    bool right=hasPathSum(root->right,targetSum-root->val);
    return left || right;
}