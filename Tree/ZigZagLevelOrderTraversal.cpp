/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

*/

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// definition of TreeNode is given in leetcode
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
we can also modify the queue itself 
normal = add in front and remove from back
reverse = add in back and remove from front

so we need to use deque
*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root==nullptr){
        return result;
    }

    queue<TreeNode*> queue;
    queue.push(root);
    //bfs
    while(!queue.empty()){
        vector<int> currentLevelList;
        int levelSize=queue.size();
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
    for(int i=1;i<result.size();i+=2){
        //reverse the list
        vector<int> list=result[i];
        int j=0;
        int k=list.size()-1;
        while(j<k){
            int temp=list[j];
            list[j]=list[k];
            list[k]=temp;
            j++;
            k--;
        }
    }
    return result;
}