/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

*/

// https://leetcode.com/problems/symmetric-tree/description/

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
bool isSymmetric(TreeNode* root){
    queue<TreeNode*> queue;
    vector<vector<TreeNode*>> result;
    queue.push(root);

    while(!queue.empty()){
        int levelSize=queue.size();
        vector<TreeNode*> currentLevelList;

        for(int i=0;i<levelSize;i++){
            TreeNode* currentNode=queue.front();
            queue.pop();
            
            currentLevelList.push_back(currentNode);
            if(currentNode==nullptr){
                // if we are allowed to store integer then we can store the negative number less that 100 so we can identify the nullptr
                continue;
            }
            queue.push(currentNode->left);
            queue.push(currentNode->right);
        }
        result.push_back(currentLevelList);
    }

    // two pointer method
    for(auto &list:result){
        //compare start and end pointer elements
        int i=0;
        int j=list.size()-1;
        while(i<j){
            if((list[i]==nullptr && list[j]!=nullptr) || (list[i]!=nullptr && list[j]==nullptr)){
                return false;
            }
            if((list[i]!=nullptr && list[j]!=nullptr) && list[i]->val!=list[j]->val){
                return false;
            }
            i++;
            j--;
        }
    }
    return true;
}
