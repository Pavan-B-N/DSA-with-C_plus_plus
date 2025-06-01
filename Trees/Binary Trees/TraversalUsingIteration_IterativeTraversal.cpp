#include <stack>
#include <vector>
#include "TreeNode.h"
using namespace std;

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
