/*
Construct Binary Tree from Preorder and Inorder Traversal
*/

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(const vector<int> preorder, const vector<int> inorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }

        int rootValue = preorder[0];
        TreeNode *root = new TreeNode(rootValue);

        int index = 0;
        while (inorder[index] != rootValue)
        {
            index++;
        }

        vector<int> leftPreorder(preorder.begin() + 1,
                                 preorder.begin() + index + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightPreorder(preorder.begin() + index + 1, preorder.end());
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};