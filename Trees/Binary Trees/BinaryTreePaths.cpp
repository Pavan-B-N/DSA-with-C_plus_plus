// https://leetcode.com/problems/binary-tree-paths/description/
/*
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        BTP(root, ans, path);
        return ans;
    }

    void BTP(TreeNode* root, vector<string> &ans, string &path) {
        if (!root) return;

        int len = path.length();

        if (isLeaf(root)) {
            path += to_string(root->val);
            ans.push_back(path);
            path.resize(len); // ✅ backtrack after leaf
            return;
        }

        path += to_string(root->val) + "->";
        BTP(root->left, ans, path);
        BTP(root->right, ans, path);

        path.resize(len); // ✅ backtrack after internal node
    }

    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
};
