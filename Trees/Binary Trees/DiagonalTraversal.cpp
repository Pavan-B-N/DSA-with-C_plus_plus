#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Tree node
struct Node {
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node* root) {
    vector<int> diagonalVals;
    if (!root)
        return diagonalVals;

    queue<Node*> leftQueue;
    Node* node = root;

    while (node) {

        // Add current node to output
        diagonalVals.push_back(node->data);
        // If left child available, add it to queue
        if (node->left)
            leftQueue.push(node->left);

        // if right child, transfer the node to right
        if (node->right)
            node = node->right;

        else {
            // If left child Queue is not empty, utilize it
            // to traverse further
            if (!leftQueue.empty()) {
                node = leftQueue.front();
                leftQueue.pop();
            }
            else {
                // All the right childs traversed and no
                // left child left
                node = nullptr;
            }
        }
    }
    return diagonalVals;
}