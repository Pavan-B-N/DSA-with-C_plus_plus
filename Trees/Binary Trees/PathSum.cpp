// https://leetcode.com/problems/path-sum/description/
#include <iostream>
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

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==nullptr){
        return false;
    }
    if(root->val==targetSum && root->left==nullptr && root->right==nullptr){
        return true;
    }
    bool left=hasPathSum(root->left,targetSum-root->val);
    bool right=hasPathSum(root->right,targetSum-root->val);
    return left || right;
}