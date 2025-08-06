// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
#include "Node.h"
#include <vector>
using namespace std;

class Solution
{
    // inorder = [1,2,3,4,5,6,7,8.9]
    // key = 5
    // predecessor  = 4
    // successor  = 6
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pre = NULL;
        Node *suc = NULL;
        findPreSucHelper(root, pre, suc, key);
        return {pre, suc};
    }

private:
    void findPreSucHelper(Node *root, Node *&pre, Node *&suc, int key)
    {
        if (!root)
            return;

        if (root->data == key)
        {
            // Predecessor: max in left subtree
            if (root->left)
            {
                Node *temp = root->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }
            // Successor: min in right subtree
            if (root->right)
            {
                Node *temp = root->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
        }
        else if (key < root->data)
        {
            suc = root;// potential successor
            findPreSucHelper(root->left, pre, suc, key);
        }
        else
        {
            pre = root;// potential predeccesor
            findPreSucHelper(root->right, pre, suc, key);
        }
    }
};
