//  find all duplicate subtrees in a binary tree
/*
Given a binary tree, find all duplicate subtrees. For each duplicate subtree, we only need to return the root node of any one of them. 

Input :
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4

Output : 
   2           
  /    and    4
 4
Explanation: Above Trees are two duplicate subtrees. 
Therefore, you need to return above trees root in the 
form of a list.


*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    struct Node* left, *right;
};

// data serialization technieque
string inorder(Node* node, unordered_map<string, int>& m)
{
    if (!node)
        return "#";
 
    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";
 
    if (m[str] == 1)
        cout <<str<<" -> "<<  node->data << endl;
 
    m[str]++;
 
    return str;
}
 
/*
Time Complexity: O(N^2)  Since string copying takes O(n) extra time.
Auxiliary Space: O(N^2) Since we are hashing a string for each node and length of this string can be of the order N.
*/
void printAllDups(Node* root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}
 
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver code
int main()
{
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);
    return 0;
}