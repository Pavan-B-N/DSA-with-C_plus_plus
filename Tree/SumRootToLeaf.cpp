// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int sumNumbers(TreeNode* root) {
    return sumNumbers(root,0);
}
int sumNumbers(TreeNode* root,int n){
    if(root==nullptr){
        return 0;
    }
    n = n*10 + root->val;
    // Check if it is a leaf node
    if(root->left == nullptr && root->right == nullptr){
        return n;
    }

    int left=sumNumbers(root->left,n);
    int right=sumNumbers(root->right,n);
    return left+right;
}