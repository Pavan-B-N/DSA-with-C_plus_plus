// AVL tree is a self balancing tree in which balance factor lies between {-1,0,1}
/*
insert the element normally
follow bottom up approach to find the balance factor and restructure the tree using rotations
*/
#include <iostream>
using namespace std;

class Node{
public:
    Node *left,*right;
    int value,height;
    Node(int value):value(value),height(0),left(nullptr),right(nullptr){}
};

class AVLTree{
public:
    Node *root;
    AVLTree():root(nullptr){}

    int height(Node *node){
        if(node==nullptr){
            return 0;
        }
        return node->height;
    }
    int balanceFactor(Node *node){
        if(node==nullptr){
            return 0;
        }
        return (height(node->left)-height(node->right));
    }
    Node* leftRotate(Node *node){
        Node *rightNode=node->right;
        Node *centreNode=rightNode->left;

        rightNode->left=node;
        node->right=centreNode;

        // update the height of the node once the rotation is done
        node->height=max(height(node->left),height(node->right))+1;
        rightNode->height=max(height(rightNode->left),height(rightNode->right))+1;
        return rightNode;
    }
    Node* rightRotate(Node *node){
        Node *leftNode=node->left;
        Node* centreNode=leftNode->right;

        leftNode->right=node;
        node->left=centreNode;
        // update the height of the node once the rotation is done
        node->height=max(height(node->left),height(node->right))+1;
        leftNode->height=max(height(leftNode->left),height(leftNode->right))+1;

        return leftNode;
    }

    Node* balance(Node *node){
        int bf=balanceFactor(node);
        // bf>1 means left is heavy
        if(bf>1){
            if(balanceFactor(node->left)<0){
                node->left=leftRotate(node->left);
            }
            return rightRotate(node);
        }
        // bf<-1 means right is heavy
        if(bf<-1){
            if(balanceFactor(node->right)>0){
                node->right=rightRotate(node->right);
            }
            return leftRotate(node);
        }
        return node;
    }

    void insert(int value){
        root=insert(root,value);
    }
    Node* insert(Node *node,int value){
        if(node==nullptr){
            return new Node(value);
        }
        if(value<(node->value)){
            node->left=insert(node->left,value);
        }
        else if(value>(node->value)){
            node->right=insert(node->right,value);
        }
        else{
            //duplicate don't insert simply return the found node
            return node;
        }
        // Update the balance factor of each node
        // And, balance the tree
        node->height=max(height(node->left),height(node->right))+1;
        return balance(node);
    }
    void deleteNode(int value){
        root=deleteNode(root,value);
    }
    // it is the least element from the right subtree
    int inorderSuccessor(Node* node){
        if(node==nullptr){
            return -1;
        }
        int min=-1;
        node=node->right;
        while(node!=nullptr){
            min=node->value;
            node=node->left;
        }
        return min;
    }
    Node* deleteNode(Node* node,int value){
        if(node==nullptr){
            return nullptr;
        }
        if(value<(node->value)){
            node->left=deleteNode(node->left,value);
        }
        else if(value>(node->value)){
            node->right=deleteNode(node->right,value);
        }
        else{
            //equal case
            // 0 child = simply unlink
            // 1 child = swap
            // 2 child = inordersuccessor

            //no child
            if(node->left==nullptr && node->right==nullptr){
                return nullptr;
            }
            //1 child
            if(node->left==nullptr){
                return node->right;
            }else if(node->right==nullptr){
                return node->left;
            }

            // child 2
            // inorder successor is the right subtree least element
            node->value=inorderSuccessor(node);
            node->right=deleteNode(node->right,node->value);
        }

        // Update the balance factor of each node and balance the tree
        node->height=max(height(node->left),height(node->right))+1;
        return balance(node);
    }

    void display(){
        cout<<"Right is above and left is below"<<endl;
        prettyDisplay(root,0);
    }
    void prettyDisplay(Node *node,int level){
        if(node==nullptr){
            return;
        }
        prettyDisplay(node->right,level+1);
        for(int i=0;i<level;i++){
            cout<<"\t";
        }
        cout<<"|-----------"<<(node->value)<<endl;
        prettyDisplay(node->left,level+1);
    }


};
int main(){
    AVLTree avl;
    for(int i=0;i<10;i++){
        avl.insert(i);
    }

    cout<<"Height of a self balancing avl tree is "<<avl.height(avl.root)<<endl;
    avl.display();
    return 0;
}