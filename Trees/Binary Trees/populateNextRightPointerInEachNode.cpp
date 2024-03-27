/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
};

Node* connect(Node* root) {
    if(root==nullptr){
        return root;
    }
    queue<Node*> queue;
    queue.push(root);

    while(!queue.empty()){
        int levelSize=queue.size();
        Node* levelEndNode;
        for(int i=0;i<levelSize;i++){
            Node* currentNode=queue.front();
            queue.pop();
            levelEndNode=currentNode;
            if(!queue.empty()){
                currentNode->next=queue.front();
            }
            if(currentNode->left!=nullptr){
                queue.push(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                queue.push(currentNode->right);
            }
        }
        if(levelEndNode){
            levelEndNode->next=nullptr;
        }
    }
    return root;
}