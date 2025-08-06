#include "Node.h"

class Solution
{
public:
    // BST is in sorted order if we perfrom inorder
    // we are using separate function because k should be reference
    // Best Case: O(log n)
    // Worst Case: O(n), Unbalanced BST or k == n
    int kthSmallestUsingInorder(Node *root, int &k)
    {
        if (root == nullptr)
            return -1;

        int left = kthSmallestUsingInorder(root->left, k);
        if (left != -1)
            return left;

        k--;
        if (k == 0)
            return root->val;

        return kthSmallestUsingInorder(root->right, k);
    }

    int kthSmallest(Node *root, int k)
    {
        return kthSmallestUsingInorder(root, k);
    }
};