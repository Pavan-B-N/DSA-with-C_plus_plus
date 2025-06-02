// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
#include "TreeNode.h"
#include <vector>
#include <algorithm>
using namespace std;

// time complexity is O(N)
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return build(preorder, index, INT_MAX);
}

TreeNode *build(vector<int> &preorder, int &index, int upperBound)
{
    // preorder[index]>upperbound, only to check if i can go left
    if (index >= preorder.size() || preorder[index] > upperBound)
        return nullptr;

    TreeNode *root = new TreeNode(preorder[index++]);
    // for left, upperbound is just a parent value
    // For the left child, valid values are:
    // Less than the current node’s value.
    root->left = build(preorder, index, root->val);
    // for right, upperbound is a parent -> parent value
    //     For the right child, valid values are:
    // Greater than the current node’s value but still within the upperBound given by its parent.
    root->right = build(preorder, index, upperBound);
    return root;
}

// time complexity = O(NlogN + N)
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        return buildTree(preorder, inorder);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        int index = 0;
        while (inorder[index] != preorder[0])
        {
            index++;
        }

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + index + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightPreorder(preorder.begin() + index + 1, preorder.end());
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};

// time complexity = o(N*N)
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            root = insert(root, preorder[i]);
        }

        return root;
    }
    TreeNode *insert(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }

        if (root->val > val)
        {
            root->left = insert(root->left, val);
        }
        else if (root->val < val)
        {
            root->right = insert(root->right, val);
        }

        return root;
    }
};