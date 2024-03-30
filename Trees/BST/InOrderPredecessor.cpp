#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


int InOrderPredecessor(Node *root){
    if(!root){
        return -1;
    }
    int maxValue=-1;
    root=root->left;
    while(root!=nullptr){
        maxValue=root->value;
        root=root->right;
    }
    return maxValue;
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

    cout<<"\nInOrderPredecessor: "<<InOrderPredecessor(bst.root)<<endl;

    return 0;
}
