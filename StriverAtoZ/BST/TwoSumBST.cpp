// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include "Node.h"
#include <stack>
using namespace std;

class Solution
{
    stack<Node *> s1; // stores left nodes , next, ascending
    stack<Node *> s2; // stores right node, before , descending

    void storeLeftNodes(Node *node)
    {
        while (node)
        {
            s1.push(node);
            node = node->left;
        }
    }
    void storeRightNodes(Node *node)
    {
        while (node)
        {
            s2.push(node);
            node = node->right;
        }
    }

    int next()
    {
        Node *node = s1.top();
        s1.pop();
        storeLeftNodes(node->right);
        return node->val;
    }

    // return greater element
    int before()
    {
        Node *node = s2.top();
        s2.pop();

        storeRightNodes(node->left);
        return node->val;
    }

public:
    bool findTarget(Node *root, int k)
    {
        storeLeftNodes(root);
        storeRightNodes(root);

        int i = next();
        int j = before();

        while (i < j)
        {
            int sum = i + j;
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                i = next();
            }
            else
            {
                j = before();
            }
        }

        return false;
    }
};