// https://leetcode.com/problems/binary-tree-preorder-traversal/
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;

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
        if (root == nullptr)
        {
            return;
        }

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    // using iteration and stack
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *node = s.top();
            ans.push_back(node->val);
            s.pop();

            if (node->right)
            {
                s.push(node->right);
            }

            if (node->left)
            {
                s.push(node->left);
            }
        }

        return ans;
    }
};