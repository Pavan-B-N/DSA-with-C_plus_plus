/*
array represents the binary tree in the form of level order traversal
arr=[1,2,3,4,null,null,5] Note: null is represented as -1 in the array
preorder=[1,2,4,null,3,null,5] or [1,2,4,3,5]
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node{
public:
    int val;
    Node *left,*right;
    Node(int x):val(x),left(nullptr),right(nullptr){}
};

Node* buildTree(vector<int> &nums){
    int i=1;
    int n=nums.size();
    if (n == 0 || nums[0] == -1) {
            return nullptr;
    }
    queue<Node*> queue;
    Node* root=new Node(nums[0]);
    queue.push(root);

    while(!queue.empty()){
        Node* currentNode=queue.front();
        queue.pop();

        if(currentNode!=nullptr && (2*i-1)<n){
            int lc = nums[2 * i - 1];//2k
            int rc = (2 * i) < n ? nums[2 * i] : -1;

            if(lc!=-1){
                currentNode->left=new Node(lc);
                queue.push(currentNode->left);
            }
            if(rc!=-1){
                currentNode->right=new Node(rc);
                    queue.push(currentNode->right);
            }
        }
        i++;
    }
    return root;
}

void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int> nums={1,2,3,4,-1,-1,5};
    Node *root=buildTree(nums);
    preorder(root);
    return 0;
}