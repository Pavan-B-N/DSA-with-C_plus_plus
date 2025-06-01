// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;

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

    // iterative inorder
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        stack<TreeNode *> s;
        TreeNode *currNode = root;

        while (currNode != nullptr || !s.empty())
        {
            if (currNode)
            {
                s.push(currNode);
                currNode = currNode->left;
            }
            else
            {
                if (s.empty())
                    break;
                currNode = s.top();
                s.pop();
                ans.push_back(currNode->val);
                currNode = currNode->right;
            }
        }

        return ans;
    }
};