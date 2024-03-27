/*
https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0

*/
class Node{
public:
    Node *left,*right;
    int data;
};
int toSumTree(Node *root){
    if(!root){
        return 0;
    }

    int oldValue=root->data;
    root->data=toSumTree(root->left) + toSumTree(root->right);

    return root->data + oldValue;
}