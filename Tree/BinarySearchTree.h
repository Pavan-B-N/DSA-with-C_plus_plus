#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

class Node {
public:
    Node* left;
    Node* right;
    int value;
    Node(int value);
};

class BST {
public:
    Node* root;
    BST();
    void insert(int value);
    void deleteNode(int key);
    void preorder();
    void inorder();
    void postorder();
    void display();
private:
    Node* insert(Node* node, int value);
    Node* deleteNode(Node* node, int key);
    int inorderSuccessor(Node* node);
    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    void prettyDisplay(Node* node, int level);
};

#endif // BINARYSEARCHTREE_H
