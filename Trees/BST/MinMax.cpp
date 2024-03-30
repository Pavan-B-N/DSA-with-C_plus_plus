/*
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.


*/
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


int minInBT(Node *root){
    int minValue=-1;
    while(root){
        minValue=root->value;
        root=root->left;
    }
    return minValue;
}
int maxInBt(Node *root){
    int maxValue=-1;
    while(root){
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
    cout<<endl;

    cout<<"Min: "<<minInBT(bst.root)<<endl;
    cout<<"Max: "<<maxInBt(bst.root)<<endl;

    return 0;
}
