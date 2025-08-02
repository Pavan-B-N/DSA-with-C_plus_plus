// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

// Time complexity: O(n²)
// Total Space Complexity = O(n²)
// creating sub-vectors (preLeft, inLeft, etc.) → This takes O(k) time per call, where k is the size of the sub-array.
// There are O(n) recursive calls in total.
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        int inorderIndex = -1;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
            {
                inorderIndex = i;
            }
        }

        vector<int> preLeft(preorder.begin() + 1, preorder.begin() + inorderIndex + 1);
        vector<int> inLeft(inorder.begin(), inorder.begin() + inorderIndex);
        root->left = buildTree(preLeft, inLeft);

        vector<int> preRight(preorder.begin() + inorderIndex + 1, preorder.end());
        vector<int> inRight(inorder.begin() + inorderIndex + 1, inorder.end());
        root->right = buildTree(preRight, inRight);

        return root;
    }
};

//  Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // preorder and inorder consist of unique values.
        unordered_map<int, int> map; // {value,index}
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        return constructTree(preorder, 0, preorder.size() - 1,
                             inorder, 0, inorder.size() - 1, map);
    }

    TreeNode *constructTree(vector<int> &preorder, int preStart, int preEnd,
                            vector<int> &inorder, int inStart, int inEnd,
                            unordered_map<int, int> &map)
    {
        if (preStart > preEnd)
        {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);

        int inRootIndex = map[rootVal];
        int leftSize = inRootIndex - inStart;

        root->left = constructTree(preorder, preStart + 1, preStart + leftSize,
                                   inorder, inStart, inRootIndex - 1, map);

        root->right = constructTree(preorder, preStart + leftSize + 1, preEnd,
                                    inorder, inRootIndex + 1, inEnd, map);

        return root;
    }
};