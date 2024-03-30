#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

// inorderSuccessor is the minimum value from right subtree
int inorderSuccessor(Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    node = node->right;
    int minValue = -1;
    while (node != nullptr)
    {
        minValue = node->value;
        node = node->left;
    }
    return minValue;
}