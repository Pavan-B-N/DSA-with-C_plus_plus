// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
#include <iostream>
#include <vector>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }

        int rootValue = preorder[0];
        TreeNode *root = new TreeNode(rootValue);

        if (preorder.size() == 1)
        {
            return root;
        }

        int leftRootValue = preorder[1]; // left child in preorder
        int leftRootIndex = 0;

        // Find the index of the left child root in postorder
        while (postorder[leftRootIndex] != leftRootValue)
        {
            leftRootIndex++;
        }

        // left part
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftRootIndex + 2);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftRootIndex + 1);
        root->left = constructFromPrePost(leftPreorder, leftPostorder);

        // right part
        vector<int> rightPreorder(preorder.begin() + leftRootIndex + 2, preorder.end());
        vector<int> rightPostorder(postorder.begin() + leftRootIndex + 1, postorder.end() - 1);
        root->right = constructFromPrePost(rightPreorder, rightPostorder);

        return root;
    }
};