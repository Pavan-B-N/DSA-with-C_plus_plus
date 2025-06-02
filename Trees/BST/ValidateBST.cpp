#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <climits>
using namespace std;

// efficient
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        // using long because root value can be upto INT_MAX
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode *root, long long minValue, long long maxValue)
    {
        if (!root)
        {
            return true;
        }

        return (root->val < maxValue && root->val > minValue) && isValidBST(root->left, minValue, root->val) && isValidBST(root->right, root->val, maxValue);
    }
};

// less efficient, but good one
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        vector<int> inorder;
        getInorder(root, inorder);
        for (int i = 0; i < inorder.size() - 1; i++)
        {
            if (inorder[i] >= inorder[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void getInorder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;
        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
};