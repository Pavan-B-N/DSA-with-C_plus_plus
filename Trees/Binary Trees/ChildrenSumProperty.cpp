// https://www.naukri.com/code360/problems/children-sum-property_8357239?leftPanelTabValue=PROBLEM
#include "Node.h"

class Solution
{
public:
    bool isParentSum(Node *root)
    {
        if (!root || isLeaf(root))
        {
            return true;
        }

        int sum = 0;
        if (root->left)
        {
            sum += root->left->data;
        }
        if (root->right)
        {
            sum += root->right->data;
        }

        if (root->data != sum)
        {
            return false;
        }

        return isParentSum(root->left) && isParentSum(root->right);
    }

    bool isLeaf(Node *root)
    {
        return root->left == nullptr && root->right == nullptr;
    }
};


// convert the given tree to satify the ChildSumProperty
// o(N)
class Solution {
    void changeTree(Node* root) {
        if (root == nullptr) return;
        
        int childSum = 0;
        if (root->left) {
            childSum += root->left->data;
        }
        if (root->right) {
            childSum += root->right->data;
        }

        if (childSum >= root->data) {
            root->data = childSum;
        } else {
            if (root->left) {
                root->left->data = root->data;
            } else if (root->right) {
                root->right->data = root->data;
            }
        }

        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;
        if (root->left) tot += root->left->data;
        if (root->right) tot += root->right->data;
        if (root->left || root->right) root->data = tot;
    }
};
