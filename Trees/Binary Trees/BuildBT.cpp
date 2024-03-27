#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to create a binary tree
TreeNode *createTree(vector<int> &values, int idx)
{
    if (idx >= values.size() || values[idx] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(values[idx]);
    root->left = createTree(values, 2 * idx + 1);
    root->right = createTree(values, 2 * idx + 2);
    return root;
}

// Helper function to deallocate memory of the binary tree
void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    // Example usage
    vector<int> values = {3, 9, 20, -1, -1, 15, 7}; // Example binary tree
    TreeNode *root = createTree(values, 0);

    // Deallocate memory
    deleteTree(root);

    return 0;
}