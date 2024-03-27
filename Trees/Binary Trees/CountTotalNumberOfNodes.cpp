#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

// g++ .\CountTotalNumberOfNodes.cpp .\BinarySearchTree.cpp
int countNodes(Node *root){
    if(root==nullptr){
        return  0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

int main(){
    BST bst;// from the header
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);

    int nodes=countNodes(bst.root);
    cout<<"Total Number of Nodes is "<<nodes<<endl;
    return 0;
}