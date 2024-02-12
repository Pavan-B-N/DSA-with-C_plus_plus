// The depth of a node in a binary tree is the number of edges on the path from the root to that particular node
// depth of binary tree == height og a bt
// The height of a node in a binary tree is the number of edges on the longest path from that node to a leaf node.
#include <iostream>
#include <algorithm>
#include "BinarySearchTree.h"
using namespace std;
// g++ .\BinarySearchTree.cpp .\DepthOfBT.cpp

// the same algorithm works for finding the height of a binary tree as well
int maxDepth(Node *root){
    if(root==nullptr){
        return -1;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
int main(){
    BST bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);

    int depthOfTree=maxDepth(bst.root);
    cout<<"Maximum depth of a binary tree is "<<depthOfTree<<endl;
    return 0;
}