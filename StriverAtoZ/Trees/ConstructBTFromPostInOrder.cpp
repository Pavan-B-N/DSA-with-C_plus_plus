// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;  // {value, index} for inorder
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return constructTree(postorder, 0, postorder.size() - 1,
                             inorder, 0, inorder.size() - 1, map);
    }

private:
    TreeNode* constructTree(vector<int>& postorder, int postStart, int postEnd,
                            vector<int>& inorder, int inStart, int inEnd,
                            unordered_map<int, int>& map) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = map[rootVal];
        int leftSize = inRootIndex - inStart;

        root->left = constructTree(postorder, postStart, postStart + leftSize - 1,
                                   inorder, inStart, inRootIndex - 1, map);

        root->right = constructTree(postorder, postStart + leftSize, postEnd - 1,
                                    inorder, inRootIndex + 1, inEnd, map);

        return root;
    }
};
