/*
Construct Binary Tree from Preorder and Inorder Traversal
*/

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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

TreeNode* buildTree(const vector<int>& preorder,const vector<int>& inorder) {
    if (preorder.size() == 0) {
        return nullptr;
    }

    int rootValue = preorder[0];
    int index = 0;

    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == rootValue) {
            index = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(rootValue);

    // Recursive calls for left and right subtrees
    root->left = buildTree(
        vector<int>(preorder.begin() + 1, preorder.begin() + 1 + index),
        vector<int>(inorder.begin(), inorder.begin() + index)
    );

    root->right = buildTree(
        vector<int>(preorder.begin() + 1 + index, preorder.end()),
        vector<int>(inorder.begin() + index + 1, inorder.end())
    );

    return root;

}