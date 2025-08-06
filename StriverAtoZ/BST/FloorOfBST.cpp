// https://www.geeksforgeeks.org/problems/floor-in-bst/1
#include "Node.h"

class Solution
{
public:
    int floor(Node *root, int x)
    {
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
};