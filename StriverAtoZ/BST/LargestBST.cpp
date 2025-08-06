#include "Node.h"
#include <climits>
#include <algorithm>
using namespace std;

// optimal
class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution
{

public:
    int largestBst(Node *root)
    {
        return largestBSTSubtreeHelper(root).maxSize;
    }

private:
    NodeValue largestBSTSubtreeHelper(Node *root)
    {
        // An empty tree is a BST of size 0.
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree of current tree.
        // postorder traversal
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right, it's a BST
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1);
        }

        // Otherwise, it's not a BST, return invalid range
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
};
