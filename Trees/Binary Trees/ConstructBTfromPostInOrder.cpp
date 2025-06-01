// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.empty())
        {
            return nullptr;
        }

        int rootValue = postorder.back();
        TreeNode *root = new TreeNode(rootValue);

        int index = 0;
        while (inorder[index] != rootValue)
        {
            index++;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + index);
        root->left = buildTree(leftInorder, leftPostorder);

        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        vector<int> rightPostorder(postorder.begin() + index,
                                   postorder.end() - 1);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};