// https://www.geeksforgeeks.org/problems/burning-tree/1

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "Node.h"
using namespace std;

// problem is based on bfs and \NodesAtDistanceK.cpp

// time complexity
// markParents = O(N)
// BFS = O(N)
// So O(N) total.

// space complexity
// parentTrack, visited = O(2N)
// queue = O(W) where W is the max width
// So O(N + W)
// In the worst case, W = N/2 (in a complete binary tree), so:
// so  O(N)
class Solution
{
public:
    int minTime(Node *root, int target)
    {
        if (!root)
        {
            return 0;
        }
        Node *targetNode = findNode(root, target);

        unordered_map<Node *, Node *> parentTrack; //{node,parentNode}
        markParents(root, parentTrack);

        // to prevent revisitng the same node which is already fired up
        unordered_map<Node *, bool> visited;

        queue<Node *> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int miniBurnTime = 0;
        // level by level
        while (!q.empty())
        {
            int size = q.size();
            bool anyNewBurn = false; // track if any node is burned in this second

            //. In one second, the fire spreads from a node to its left child, right child, and parent.
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                // left
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                    anyNewBurn = true;
                }

                // right
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                    anyNewBurn = true;
                }

                // parent or top
                if (parentTrack[node] && !visited[parentTrack[node]])
                {
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]] = true;
                    anyNewBurn = true;
                }
            }
            if (anyNewBurn)
                miniBurnTime++; //  Only increment if fire spread this second
        }

        return miniBurnTime;
    }

    void markParents(Node *root, unordered_map<Node *, Node *> &parentTrack)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *currNode = q.front();
            q.pop();

            if (currNode->left)
            {
                parentTrack[currNode->left] = currNode;
                q.push(currNode->left);
            }
            if (currNode->right)
            {
                parentTrack[currNode->right] = currNode;
                q.push(currNode->right);
            }
        }
    }

    Node *findNode(Node *root, int target)
    {
        if (root == nullptr || root->data == target)
        {
            return root;
        }

        Node *left = findNode(root->left, target);
        if (left != nullptr)
        {
            return left;
        }
        Node *right = findNode(root->right, target);

        return right;
    }
};