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

TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
    if (postorder.empty()) {
        return nullptr;
    }

    int rootValue = postorder.back();
    TreeNode* root = new TreeNode(rootValue);

    int index = 0;
    while (inorder[index] != rootValue) {
        index++;
    }

    vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + index);
    root->left = buildTree(leftInorder, leftPostorder);

    vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
    vector<int> rightPostorder(postorder.begin() + index, postorder.end() - 1);
    root->right = buildTree(rightInorder, rightPostorder);

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
    vector<int> inorder={9,5,1,7,2,12,8,4,3,11};
    vector<int> postorder={9,1,2,12,7,5,3,11,4,8};

    TreeNode *root=buildTree(inorder,postorder);
    inorderTraversal(root);


    return 0;
}
