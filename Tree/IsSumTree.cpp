struct node {
    int data;
    struct node* left;
    struct node* right;
};

int sumSubtree(node* root) {
    if (root == nullptr)
        return 0;
    return root->data + sumSubtree(root->left) + sumSubtree(root->right);
}

bool isSumTree(node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;

    int leftSum = sumSubtree(root->left);
    int rightSum = sumSubtree(root->right);
    
    return (root->data == leftSum + rightSum) && isSumTree(root->left) && isSumTree(root->right);
}