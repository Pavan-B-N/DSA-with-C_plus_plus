#include "Node.h"

class Solution
{
public:
    int findCeil(Node *root, int input)
    {
        int ans = -1;
        ceilOfBST(root, input, ans);
        return ans;
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
            ans = root->data;
            ceilOfBST(root->left, input, ans);
        }
        else
        {
            ceilOfBST(root->right, input, ans);
        }
    }
};