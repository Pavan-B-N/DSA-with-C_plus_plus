#include <iostream>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to construct binary tree from string
TreeNode* constructTree(string str, int& index) {
    if (index >= str.length() || str[index] == ')') {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(str[index]);
    index++;

    // Check if next character is '('
    if (index < str.length() && str[index] == '(') {
        index++;
        root->left = constructTree(str, index);
    }

    // Check if next character is ')'
    if (index < str.length() && str[index] == ')') {
        index++;
        return root;
    }

    // Check if next character is '('
    if (index < str.length() && str[index] == '(') {
        index++;
        root->right = constructTree(str, index);
    }

    // Check if next character is ')'
    if (index < str.length() && str[index] == ')') {
        index++;
        return root;
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    string str = "4(2(3)(1))(6(5))"; // Example string bracket representation
    int index = 0;
    TreeNode* root = constructTree(str, index);

    cout << "Inorder Traversal of Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}
