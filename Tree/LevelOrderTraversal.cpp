/*
given a root of a  binary tree, return the level order traversal of its node's values

input=[3,9,20,null,null,15,7]
output=[[3],[9,20],[15,7]]
*/

// https://leetcode.com/problems/binary-tree-level-order-traversal/

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

// Time Complexity: O(n), where n is the number of nodes in the binary tree. 
// Auxiliary Space: O(n),
vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> result;
    if(root==nullptr){
        return result;
    }
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()){
        int levelSize=queue.size();
        vector<int> currentLevelList;
        for(int i=0;i<levelSize;i++){
            TreeNode* currentNode=queue.front();
            queue.pop();
            currentLevelList.push_back(currentNode->val);

            if(currentNode->left!=nullptr){
                queue.push(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                queue.push(currentNode->right);
            }
        }
        result.push_back(currentLevelList);
    }
    return result;
}


