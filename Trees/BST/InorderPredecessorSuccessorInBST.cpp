// https://www.naukri.com/code360/problems/predecessor-and-successor_920476?leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;

class binaryTreeNode
{
public:
    int data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//  efficient (O(h)),
vector<int> findPreSuc(binaryTreeNode *root, int key)
{
    int predecessor = -1, successor = -1;

    while (root)
    {
        // This handles nearest smaller/larger values even when the key isn’t found.
        // Case 1: Key is NOT present in the BST
        if (root->data < key)
        {
            predecessor = root->data; // potential predecessor
            root = root->right;
        }
        else if (root->data > key)
        {
            successor = root->data; // potential successor
            root = root->left;
        }
        // Case 2: Key is FOUND in the BST
        else
        {
            // Found key, check left for predecessor
            // Predecessor is the maximum value in the left subtree
            binaryTreeNode *temp = root->left;
            while (temp)
            {
                predecessor = temp->data;
                temp = temp->right;
            }

            // Check right for successor
            // Successor is the minimum value in the right subtree
            temp = root->right;
            while (temp)
            {
                successor = temp->data;
                temp = temp->left;
            }

            break;
        }
    }

    return {predecessor, successor};
}
