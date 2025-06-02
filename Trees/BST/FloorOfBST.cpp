// https://www.geeksforgeeks.org/problems/floor-in-bst/1

// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

#include <climits>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{

public:
    int floor(Node *root, int x)
    {
        // Code here
        int ans = -1;
        floorBST(root, x, ans);
        return ans;
    }
    void floorBST(Node *root, int x, int &ans)
    {
        if (!root)
        {
            return;
        }
        if (root->data == x)
        {
            ans = root->data;
        }
        else if (root->data < x)
        {
            ans = root->data;
            floorBST(root->right, x, ans);
        }
        else
        {
            floorBST(root->left, x, ans);
        }
    }

    // iteration
    int floor(Node *root, int x)
    {
        // Code here
        int ans = -1;
        while (root)
        {
            if (root->data == x)
            {
                return root->data;
            }
            else if (root->data < x)
            {
                ans = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return ans;
    }
};