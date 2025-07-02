// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        if (!root)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr != nullptr)
            {
                res += to_string(curr->val) + " ";
                q.push(curr->left);
                q.push(curr->right);
            }
            else
            {
                res += "n ";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return nullptr;
        }
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while (ss >> token)
        {
            tokens.push_back(token);
        }

        TreeNode *root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode *> q;
        q.push(root);
        int i = 1; // root is at 0th index
        while (i < tokens.size())
        {
            TreeNode *curr = q.front();
            q.pop();
            // left child
            if (tokens[i] != "n")
            {
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
            // right child
            if (i < tokens.size() && tokens[i] != "n")
            {
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};
