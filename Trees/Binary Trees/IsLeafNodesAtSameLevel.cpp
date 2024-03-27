// Check if all leaf nodes are at same level or not
// Given a Binary Tree, check if all leaves are at same level or not.

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// using level order traversal
bool checkLeavesSameLevel(Node *root)
{
    if (root == NULL)
        return true;

    queue<Node *> q;
    q.push(root);
    int level = -1, leafLevel = 0;

    while (!q.empty())
    {
        int size = q.size();
        level++;

        while (size--)
        {
            Node *current = q.front();
            q.pop();

            if (current->left == NULL && current->right == NULL)
            {
                if (leafLevel == 0)
                {
                    leafLevel = level;
                }
                else if (level != leafLevel)
                {
                    return false;
                }
            }

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    return true;
}

// approach 2
bool checkUtil(Node *root, int level, int &leafLevel) {
    if (root == NULL) return true;

    if (root->left == NULL && root->right == NULL) {
        if (leafLevel == 0) {
            leafLevel = level;
            return true;
        }
        return (level == leafLevel);
    }

    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}

bool check(Node *root) {
    int leafLevel = 1; // 
    return checkUtil(root, 0, leafLevel); // Start from level 0
}
