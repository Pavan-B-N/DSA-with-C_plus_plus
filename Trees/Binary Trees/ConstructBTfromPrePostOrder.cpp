#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition of TreeNode is given in LeetCode
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& postorder) {
    if (preorder.empty()) {
        return nullptr;
    }

    int rootValue = preorder[0];
    TreeNode* root = new TreeNode(rootValue);

    if (preorder.size() == 1) {
        return root;
    }

    int leftRootValue = preorder[1]; // Value of the left child in preorder
    int leftRootIndex = -1;

    // Find the index of the left child root in postorder
    for (int i = 0; i < postorder.size() - 1; ++i) {
        if (postorder[i] == leftRootValue) {
            leftRootIndex = i;
            break;
        }
    }

    // Partition the postorder into left and right subtrees
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftRootIndex + 1);
    vector<int> rightPostorder(postorder.begin() + leftRootIndex + 1, postorder.end() - 1);

    // Partition the preorder into left and right subtrees
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftRootIndex + 2);
    vector<int> rightPreorder(preorder.begin()  + leftRootIndex + 2, preorder.end());

    root->left = buildTree(leftPreorder, leftPostorder);
    root->right = buildTree(rightPreorder, rightPostorder);

    return root;
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " -> ";
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};

    TreeNode* root = buildTree(preorder, postorder);
    postOrderTraversal(root);

    return 0;
}
