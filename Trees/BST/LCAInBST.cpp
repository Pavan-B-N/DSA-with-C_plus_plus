// Lowest Common Ancesstor
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include "TreeNode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }

        // check if both goes to left, so common path so ancesstor
        int rootVal=root->val;
        int pVal=p->val;
        int qVal=q->val;
        if(rootVal > pVal && rootVal > qVal){
            return lowestCommonAncestor(root->left,p,q);
        }
        // check if both goes to right, common path
        if(rootVal < pVal && rootVal < qVal){
            return lowestCommonAncestor(root->right,p,q);
        }

        // path splits, so they cannot be common ancesstors anymore so root is the LCA

        // root can be common ancesstor
        // this logic is optional because we are returning root anyhow, but this is just for understanding all 4 cases correctly
        if(root==p || root==q){
            return root;
        }
        // split means the root itself is the last lowest common ancesstor
        return root;
    }
};