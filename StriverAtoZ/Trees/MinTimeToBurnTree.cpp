// https://www.geeksforgeeks.org/problems/burning-tree/1

#include "Node.h"
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int minTime(Node *root, int target)
    {
        if (!root)
        {
            return 0;
        }
        // code here
        Node *targetNode = findNode(root, target);
        if (!targetNode)
        {
            return 0;
        }
        unordered_map<Node *, Node *> parentTrack; //{node,parentNode}
        markParents(root, parentTrack);
        // burning means visit
        unordered_map<Node *, bool> visited;

        queue<Node *> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int miniBurnTime = 0;
        // level by level
        while (!q.empty())
        {
            int levelSize = q.size();
            bool anyNewBurn = false;

            //. In one second, the fire spreads from a node to its left child, right child, and parent.
            for (int i = 0; i < levelSize; i++)
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
                miniBurnTime++;
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