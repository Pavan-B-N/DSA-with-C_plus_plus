// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
#include <vector>
#include <queue>
#include "Node.h"
using namespace std;

// BFS - level order traversal
class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            Node *startNode = nullptr;
            for (int i = 0; i < levelSize; i++)
            {
                Node *currentNode = q.front();
                q.pop();
                if (startNode == nullptr)
                {
                    startNode = currentNode;
                }
                if (currentNode->left != nullptr)
                {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    q.push(currentNode->right);
                }
            }
            result.push_back(startNode->data);
        }
        return result;
    }
};