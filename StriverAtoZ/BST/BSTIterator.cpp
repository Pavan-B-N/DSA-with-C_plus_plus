// https://leetcode.com/problems/binary-search-tree-iterator/
//  Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
#include "Node.h"
#include <stack>
using namespace std;

class BSTIterator
{
    stack<Node *> st;
    // inorder
    // left, root, right
    // time complexity = space complexity = O(H)
    void storeLeftNodes(Node *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(Node *root)
    {
        storeLeftNodes(root);
    }

    int next()
    {
        Node *node = st.top();
        st.pop();

        if (node->right)
        {
            storeLeftNodes(node->right);
        }
        return node->val;
    }

    bool hasNext() { return !st.empty(); }
};