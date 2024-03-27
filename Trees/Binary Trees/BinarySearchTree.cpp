#include "BinarySearchTree.h"
using namespace std;

Node::Node(int value) : value(value), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

void BST::insert(int value) {
    root = insert(root, value);
}

void BST::deleteNode(int key) {
    root = deleteNode(root, key);
}

void BST::preorder() {
    cout << "preorder:" << endl;
    preorder(root);
}

void BST::inorder() {
    cout << "inorder:" << endl;
    inorder(root);
}

void BST::postorder() {
    cout << "postorder:" << endl;
    postorder(root);
}

void BST::display() {
    cout << "Right is above and left is below" << endl;
    prettyDisplay(root, 0);
}

Node* BST::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    return node;
}

Node* BST::deleteNode(Node* node, int key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->value) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->value) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr) {
            return node->right;
        } else if (node->right == nullptr) {
            return node->left;
        }
        node->value = inorderSuccessor(node);
        node->right = deleteNode(node->right, node->value);
    }
    return node;
}

int BST::inorderSuccessor(Node* node) {
    node = node->right;
    int minValue = -1;
    while (node != nullptr) {
        minValue = node->value;
        node = node->left;
    }
    return minValue;
}

void BST::preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->value << " -> ";
    preorder(root->left);
    preorder(root->right);
}

void BST::inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->value << " -> ";
    inorder(root->right);
}

void BST::postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " -> ";
}

void BST::prettyDisplay(Node* node, int level) {
    if (node == nullptr) {
        return;
    }
    prettyDisplay(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
    cout << "|-----------" << node->value << endl;
    prettyDisplay(node->left, level + 1);
}
