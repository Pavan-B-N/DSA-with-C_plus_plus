// https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    char key;
    Node *left, *right;
};

Node* newNode(char key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

unordered_map<string, int> subtrees;

string serialize(Node *root) {
    if (root == nullptr)
        return "#";

    string s = "";
    s += root->key;
    s += serialize(root->left);
    s += serialize(root->right);

    subtrees[s]++;

    return s;
}

bool containsDuplicateSubtree(Node* root) {
    serialize(root);

    for (const auto& pair : subtrees) {
        if (pair.second >= 2 && pair.first.length() > 2) {
            return true;
        }
    }

    return false;
}

int main() {
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    // root->right->right = newNode('B');
    // root->right->right->right = newNode('E');
    // root->right->right->left= newNode('D');

    if (containsDuplicateSubtree(root))
        cout << "Yes, the tree contains a duplicate subtree.";
    else
        cout << "No, the tree doesn't contain a duplicate subtree.";

    return 0;
}
