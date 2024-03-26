/*
Given the root of a binary tree, invert the tree, and return its root.
*/

//https://leetcode.com/problems/invert-binary-tree/description/

/*
Input:
        5
       / \
      3   6
     / \
    2   4
Output:
Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2
Mirror tree will be:
  5
 / \
6   3
   / \
  4   2
  
*/
#include <iostream>
#include <algorithm>
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

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return root;
    }

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;

    return root;
}