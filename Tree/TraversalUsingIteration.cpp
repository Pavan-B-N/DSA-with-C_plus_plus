#include <iostream>
#include <stack>
#include "BinarySearchTree.h"
using namespace std;
//  g++ .\TraversalUsingIteration.cpp .\BinarySearchTree.cpp

void inorderTraversal(Node* root) {
    if (!root) return;

    stack<Node*> nodes;
    Node* current = root;

    while (current != nullptr || !nodes.empty()) {
        if (current != nullptr) {
            nodes.push(current);
            current = current->left;
        } else {
            current = nodes.top();
            nodes.pop();
            cout << current->value << " ";
            current = current->right;
        }
    }
}

void preorderTraversal(Node* root) {
    if (!root) return;

    stack<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        Node* current = nodes.top();
        nodes.pop();
        cout << current->value << " ";
        if (current->right) nodes.push(current->right);
        if (current->left) nodes.push(current->left);
    }
}

void postorderTraversal(Node* root) {
    if (!root) return;

    stack<Node*> nodes;
    nodes.push(root);
    stack<int> result;

    while (!nodes.empty()) {
        Node* current = nodes.top();
        nodes.pop();
        result.push(current->value);
        if (current->left) nodes.push(current->left);
        if (current->right) nodes.push(current->right);
    }

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
}

int main(int argc, char const *argv[])
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(80);
    bst.insert(15);
    bst.insert(30);

    bst.inorder();

    cout<<endl;
    inorderTraversal(bst.root);
    cout<<endl;

    
    bst.preorder();
    cout<<endl;
    preorderTraversal(bst.root);
    cout<<endl;


    bst.postorder();
    cout<<endl;
    postorderTraversal(bst.root);
    cout<<endl;

    return 0;
}
