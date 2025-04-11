//Time complexity of all operations is o(logn)
#include <iostream>
using namespace std;

class Node{
public:
    Node *left,*right;
    int value;
    Node(int value):value(value),left(nullptr),right(nullptr){}
};
class BST{
    Node *root;
public:
    BST():root(nullptr){}

    void insert(int value){
        root=insert(root,value);
    }
    void deleteNode(int key){
        root=deleteNode(root,key);     
    }
    void preorder(){
        cout<<"preorder:"<<endl;
        preorder(root);
    }
    void preorder(Node *root){
        if(root==nullptr){
            return;
        }
        cout<<root->value<<" -> ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(){
        cout<<"inorder:"<<endl;
        inorder(root);
    }
    void inorder(Node *root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->value<<" -> ";
        inorder(root->right);
    }
    void postorder(){
        cout<<"postorder:"<<endl;
        postorder(root);
    }
    void postorder(Node *root){
        if(root==nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<" -> ";
    }
    
    void display(){
        cout<<"Right is above and left is below"<<endl;
        prettyDisplay(root,0);
    }
private:
    Node* insert(Node *node,int value){
        if(node==nullptr){
            return new Node(value);
        }   
        if(value<node->value){
            node->left=insert(node->left,value);
        }else if(value>node->value){
            node->right=insert(node->right,value);
        }
        return node;
    }
    Node* deleteNode(Node *node,int key){
        if(node==nullptr){
            return node;
        }
        //find the node to be deleted
        if(key<node->value){
            node->left=deleteNode(node->left,key);
        }else if(key>node->value){
            node->right=deleteNode(node->right,key);
        }else{
            //we got the key
            // no children
            if(node->left==nullptr && node->right==nullptr){
                return nullptr;
            }

            //1 child
            if(node->left==nullptr){
                return node->right;
            }else if(node->right==nullptr){
                return node->left;
            }

            //2 children
            //inorder successor is the right subtree
            node->value=inorderSuccessor(node);
            //delete inorder successor
            node->right=deleteNode(node->right,node->value);
        }
        return node;
    }
    // inorderSuccessor is the minimum value from right subtree of the node
    int inorderSuccessor(Node *node){
        if(node==nullptr){
            return -1;
        }
        node=node->right;
        int minValue=-1;
        while(node!=nullptr){
            minValue=node->value;
            node=node->left;
        }
        return minValue;
    }
    void prettyDisplay(Node *node,int level){
        if(node==nullptr){
            return;
        }
        prettyDisplay(node->right,level+1);
        for(int i=0;i<level;i++){
            cout<<"   ";
        }
        cout<<"|-----------"<<(node->value)<<endl;
        prettyDisplay(node->left,level+1);
    }

};

int main(){
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(80);
    bst.insert(15);
    bst.insert(30);

    bst.display();

    // bst.deleteNode(15);// no child
    // bst.deleteNode(80);// 1 child
    bst.deleteNode(20);// 2 child

    bst.display();

    bst.preorder();
    cout<<endl;
    bst.inorder();
    cout<<endl;
    bst.postorder();

    return 0;
}