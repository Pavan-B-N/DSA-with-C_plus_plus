/*
Given a BST, the task is to search a node in this BST.

g++ .\BinarySearchTree.cpp .\SearchBST.cpp
*/
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


Node* search(Node *root,int key){
    if(!root){
        return root;
    }
    if(root->value == key){
        return root;
    }else if(key < root->value){
        return search(root->left,key);
    }else{
        return search(root->right,key);
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

    Node* ans=search(bst.root,15);

    cout<<" \n"<< ans<<" "<<endl;
    ans && cout<< ans->value<<endl;

    return 0;
}
