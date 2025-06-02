// https://leetcode.com/problems/binary-search-tree-iterator/
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;

class BSTIterator
{
    stack<TreeNode *> st;
    // inorder
    // left, root, right
    // time complexity = space complexity = O(H)
    void storeLeftNodes(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        storeLeftNodes(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();

        if (node->right)
        {
            storeLeftNodes(node->right);
        }
        return node->val;
    }

    bool hasNext() { return !st.empty(); }
};

// space complexity = o(N)
class BSTIterator
{
    int index;
    vector<int> inorder;

public:
    BSTIterator(TreeNode *root)
    {
        if (!root)
        {
            index = -1;
            return;
        }
        getInorder(root);
        index = 0;
    }
    int next()
    {
        return inorder[index++];
    }

    bool hasNext()
    {
        return index < inorder.size();
    }
    void getInorder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        getInorder(root->left);
        inorder.push_back(root->val);
        getInorder(root->right);
    }
};