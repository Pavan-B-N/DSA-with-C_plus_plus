#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
#include <climits>
using namespace std;

// definition of TreeNode is given in leetcode
class TreeNode{
public:
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// inorder of a binary tree is always in ascending order so bst can be validated using inorder
void inorder(Node *root,vector<int> &nums){
    if(root==nullptr){
        return;
    }
    inorder(root->left,nums);
    nums.push_back(root->value);
    inorder(root->right,nums);
}

// o(n) space complexity
bool isValidBST(Node *root){
    vector<int> nums;
    inorder(root,nums);
    for(int i=0;i<(nums.size()-1);i++){
        if(nums[i]>=nums[i+1]){
            return false;
        }
    }
    return true;
}

//o(1) space complexity
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root);
}
bool isValidBSTHelper(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (root == nullptr) {
        return true;
    }

    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }

    return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
}