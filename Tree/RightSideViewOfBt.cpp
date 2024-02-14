/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

// https://leetcode.com/problems/binary-tree-right-side-view/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// definition of TreeNode is given in leetcode
class TreeNode{
public:
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// bfs
vector<int> rightSideView(TreeNode *root){
    vector<int> result;
    if(root==nullptr){
        return result;
    }
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()){
        int levelSize=queue.size();
        TreeNode* levelEndNode;
        for(int i=0;i<levelSize;i++){
            TreeNode* currentNode=queue.front();
            queue.pop();
            if(currentNode->left!=nullptr){
                queue.push(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                queue.push(currentNode->right);
            }
            levelEndNode=currentNode;
        }
        result.push_back(levelEndNode->val);
    }
    return result;
}