// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track; //{node,parentNode}
        markParents(root, parent_track); // using regular bfs traversal

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!queue.empty())
        {
            int size = queue.size(); // helps to traverse in the same distance
            // so when curr_level reaches to k , it means that we got all the nodes from the target at distance k which are in queue right node.
            if (curr_level == k)
                break;

            // process all the nodes at distance i at same time by increasing distance to i+1
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = queue.front();
                queue.pop();

                if (current->left && !visited[current->left])
                {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]])
                {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            curr_level++;
        }

        vector<int> result;
        while (!queue.empty())
        {
            TreeNode *current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }

        return result;
    }

    // use of bfs for traversal
    // regular bfs, without caring level
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left)
            {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right)
            {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
};
