/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
*/
#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

// this is known as level order traversal or bfs of a binary tree
vector<double> averageOfLevels(TreeNode *root){    
    vector<double> result;
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()){
        int levelSize=queue.size();
        double levelSum=0;
        for(int i=0;i<levelSize;i++){
            TreeNode* currentNode=queue.front();
            queue.pop();
            levelSum+=currentNode->val;

            if(currentNode->left!=nullptr){
                queue.push(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                queue.push(currentNode->right);
            }
        }
        result.push_back(levelSum/levelSize);
    }
    return result;

}