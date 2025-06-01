#include <iostream>
#include "Node.h"
using namespace std;

// time complexity = O(N)
// space complexity = O(H), where H is the max_height of BT
int countNodes(Node *root){
    if(root==nullptr){
        return  0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}
