/*
Given two Binary Trees, write a function that returns true if two trees are mirror of each other, else false

Their root node’s key must be same
Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
Right subtree of ‘a’ and left subtree of ‘b’ are mirror.

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    bool areMirror(Node* root1, Node* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;

        if (root1 == nullptr || root2 == nullptr)
            return false;

        return (root1->data == root2->data) &&
               areMirror(root1->left, root2->right) &&
               areMirror(root1->right, root2->left);
    }
};

int main() {
    BinaryTree tree;
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    // root2->right->left = new Node(5);
    root2->right->right = new Node(4);

    if (tree.areMirror(root1, root2))
        cout << "Yes, the trees are mirrors of each other.";
    else
        cout << "No, the trees are not mirrors of each other.";

    return 0;
}
