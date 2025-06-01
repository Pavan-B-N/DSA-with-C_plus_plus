/*
Given two Binary Trees, write a function that returns true if two trees are mirror of each other, else false

Their root node’s key must be same
Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
Right subtree of ‘a’ and left subtree of ‘b’ are mirror.

*/

// https://www.geeksforgeeks.org/problems/two-mirror-trees/1

#include <iostream>
#include "Node.h"
using namespace std;
class Solution
{
public:
    int areMirror(Node *root1, Node *root2)
    {
        if (root1 == nullptr || root2 == nullptr)
            return root1 == root2;

        return (root1->data == root2->data) &&
               areMirror(root1->left, root2->right) &&
               areMirror(root1->right, root2->left);
    }
};