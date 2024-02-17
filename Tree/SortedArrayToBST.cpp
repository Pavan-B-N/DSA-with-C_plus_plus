/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

*/
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

#include <iostream>
#include <vector>
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


TreeNode* sortedArrayToBST(vector<int>& nums) {
    // Base case: if the array is empty, return nullptr
    if (nums.empty()) {
        return nullptr;
    }

    // Find the middle index of the array
    int mid = nums.size() / 2;

    // Create a new TreeNode with the middle value as the root
    TreeNode* root = new TreeNode(nums[mid]);

    // Recursively build the left and right subtrees
    vector<int> leftSubarray(nums.begin(), nums.begin() + mid);
    vector<int> rightSubarray(nums.begin() + mid + 1, nums.end());

    root->left = sortedArrayToBST(leftSubarray);
    root->right = sortedArrayToBST(rightSubarray);

    return root;
}