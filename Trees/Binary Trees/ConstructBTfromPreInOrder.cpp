/*
Construct Binary Tree from Preorder and Inorder Traversal
*/

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.empty()) {
        return nullptr;
    }

    int rootValue = preorder[0];
    TreeNode* root = new TreeNode(rootValue);

    int index = 0;
    while (inorder[index] != rootValue) {
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

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " -> ";
    inorderTraversal(root->right);
}

int main(int argc, char const *argv[])
{
    vector<int> inorder={8,4,10,9,11,2,5,1,6,3,7};
    vector<int> preorder={1,2,4,8,9,10,11,5,3,6,7};

    TreeNode *root=buildTree(preorder,inorder);
    inorderTraversal(root);


    return 0;
}
