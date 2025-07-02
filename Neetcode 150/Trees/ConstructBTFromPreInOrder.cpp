// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

// O(n)
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> map;
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
        if (preStart > preEnd || inStart > inEnd)
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

// O(n²) (due to repeated vector slicing)
// 	O(n²) (new vectors at each level)
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() <= 0)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        // find the index of inorder
        int index = 0;
        while (inorder[index] != preorder[0])
        {
            index++;
        }
        vector<int> preLeft(preorder.begin() + 1, preorder.begin() + index + 1);
        vector<int> InLeft(inorder.begin(), inorder.begin() + index);
        root->left = buildTree(preLeft, InLeft);

        vector<int> preRight(preorder.begin() + index + 1, preorder.end());
        vector<int> InRight(inorder.begin() + index + 1, inorder.end());
        root->right = buildTree(preRight, InRight);

        return root;
    }
};