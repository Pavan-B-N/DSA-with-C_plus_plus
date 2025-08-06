// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
#include "Node.h"
#include <vector>
using namespace std;

class Solution
{
public:
    Node *bstFromPreorder(vector<int> &preorder)
    {
        int index = 0;
        return build(preorder, index, INT_MAX);
    }

    Node *build(vector<int> &preorder, int &index, int upperBound)
    {
        // index should be reference
        // preorder[index]>upperbound, only to check if i can go left
        if (index >= preorder.size() || preorder[index] > upperBound)
            return nullptr;

        Node *root = new Node(preorder[index++]);

        root->left = build(preorder, index, root->val);

        root->right = build(preorder, index, upperBound);

        return root;
    }
};