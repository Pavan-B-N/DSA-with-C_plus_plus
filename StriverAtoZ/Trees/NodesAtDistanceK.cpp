// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
#include "TreeNode.h"
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (!root || !target)
            return {};

        // time complexity : O(n)
        // space complexity : O(n)
        unordered_map<TreeNode *, TreeNode *> parentTrack; //{node,parent}
        trackParents(root, parentTrack);

        // space complexity : O(n)
        unordered_map<TreeNode *, bool> visited; //{node,bool}

        // space complexity : O(n)
        queue<TreeNode *> q; // node
        q.push(target);
        visited[target] = true;

        int currDist = 0;
        while (!q.empty())
        {
            if (currDist == k)
                break;

            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                auto node = q.front();
                q.pop();

                if (node->left && !visited[node->left])
                {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !visited[node->right])
                {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if (parentTrack[node] && !visited[parentTrack[node]])
                {
                    visited[parentTrack[node]] = true;
                    q.push(parentTrack[node]);
                }
            }
            currDist++;
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
    // time complexity : O(n)
    // space complexity : O(n)
    void trackParents(TreeNode *root,
                      unordered_map<TreeNode *, TreeNode *> &parentTrack)
    {
        queue<TreeNode *> q; // node
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
                parentTrack[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                parentTrack[node->right] = node;
            }
        }
    }
};

// time complexity : O(n)
// space complexity : O(n)
// Call Stack (Recursive): Up to O(h) → worst-case O(n) in skewed tree, O(log n) in balanced tree.
void trackParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentTrack)
{
    if (root->left)
    {
        parentTrack[root->left] = root;
        trackParents(root->left, parentTrack);
    }
    if (root->right)
    {
        parentTrack[root->right] = root;
        trackParents(root->right, parentTrack);
    }
}
