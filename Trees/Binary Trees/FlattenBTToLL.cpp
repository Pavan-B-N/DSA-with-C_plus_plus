/*
. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

#include <iostream>
#include <queue>
using namespace std;

// definition of TreeNode is given in leetcode
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using queues
void flatten(TreeNode *root)
{
    queue<TreeNode *> queue;
    getBTQueue(root, queue);

    TreeNode *dummy = new TreeNode(0);
    TreeNode *current = dummy;

    while (!queue.empty())
    {
        TreeNode *nextNode = queue.front();
        queue.pop();

        current->left = nullptr;
        current->right = nextNode;
        current = nextNode;
    }
    root = dummy->right;
}
// usig preorder traversal with queue
void getBTQueue(TreeNode *root, queue<TreeNode *> &queue)
{
    if (root == nullptr)
    {
        return;
    }
    queue.push(root);
    getBTQueue(root->left, queue);
    getBTQueue(root->right, queue);
}

// efficient solution
TreeNode *prev = nullptr;
void flatten(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    flatten(node->right);
    flatten(node->left);

    node->right = ::prev;
    node->left = nullptr;
    ::prev = node;
}