// https://leetcode.com/problems/binary-tree-inorder-traversal/
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;

// using recursion
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};

// using iteration
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr != nullptr || !st.empty())
        {
            // Go as left as possible
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            ans.push_back(curr->val); // Visit the node

            // Now go right
            curr = curr->right;
        }

        return ans;
    }
};
