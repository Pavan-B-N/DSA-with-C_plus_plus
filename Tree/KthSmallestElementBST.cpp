/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/
#include <iostream>
#include <vector>
using namespace std;

// definition of TreeNode is given in leetcode
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    if(root==nullptr){
        return 0;
    }
    vector<int> nums;
    inorder(root,nums);
    return nums[k-1];
}
// inorder is in sorted form
void inorder(TreeNode* root,vector<int> &nums){
    if(root==nullptr){
        return;
    }
    inorder(root->left,nums);
    nums.push_back(root->val);
    inorder(root->right,nums);
}