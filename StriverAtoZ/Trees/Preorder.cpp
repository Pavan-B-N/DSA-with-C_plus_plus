// https://leetcode.com/problems/binary-tree-preorder-traversal/
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;

// using recursion
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};

// using iteration
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);

            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return ans;
    }
};