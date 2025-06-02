/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/
#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

// efficient with o(1) space
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        return kthSmallestUsingInorder(root, k);
    }

    int kthSmallestUsingInorder(TreeNode *root, int &k)
    {
        if (root == nullptr)
            return -1;

        int left = kthSmallestUsingInorder(root->left, k);
        if (left != -1)
            return left;

        k--;
        if (k == 0)
            return root->val;

        return kthSmallestUsingInorder(root->right, k);
    }
};

class Solution
{
public:
    // time complexity = O(N)
    // space complexity = auxilary stack space = O(N)
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return 0;
        }
        vector<int> nums;
        inorder(root, nums);
        return nums[k - 1];
    }
    void inorder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};