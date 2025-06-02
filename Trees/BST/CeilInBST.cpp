// Given a BST and a number X, find Ceil of X.
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

// If Ceil could not be found, return -1.
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

    int findCeil(Node *root, int input)
    {
        int ans = INT_MAX;
        ceilOfBST(root, input, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void ceilOfBST(Node *root, int input, int &ans)
    {
        if (!root)
        {
            return;
        }

        if (root->data == input)
        {
            ans = root->data;
            return;
        }
        else if (input < root->data)
        {
            // root->val > input so it can be my ceil
            ans = min(ans, root->data);
            ceilOfBST(root->left, input, ans);
        }
        else
        {
            ceilOfBST(root->right, input, ans);
        }
    }

    // iterative way
    int findCeil(Node *root, int input)
    {
        // Your code here
        int ans = -1;
        while (root)
        {
            if (root->data == input)
            {
                return root->data;
            }
            else if (root->data > input)
            {
                ans = root->data; // evrytime goes down so its always minimum only
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        return ans;
    }
};