#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
using namespace std;
// inorder of a binary tree is always in ascending order so bst can be validated using inorder
void inorder(Node *root,vector<int> &nums){
    if(root==nullptr){
        return;
    }
    inorder(root->left,nums);
    nums.push_back(root->value);
    inorder(root->right,nums);
}

bool isValidBST(Node *root){
    vector<int> nums;
    inorder(root,nums);
    for(int i=0;i<(nums.size()-1);i++){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }
    return true;
}