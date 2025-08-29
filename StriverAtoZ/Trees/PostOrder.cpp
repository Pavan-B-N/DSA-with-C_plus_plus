// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;
// using postorder
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
    void postorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
};

// iterative way
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        
        while (!s1.empty())
        {
            TreeNode *node = s1.top();
            s1.pop();

            s2.push(node);

            if (node->left)
                s1.push(node->left);

            if (node->right)
                s1.push(node->right);
        }

        while (!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};