/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

*/
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <string>
#include "TreeNode.h"
using namespace std;

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string result = "";
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            TreeNode *currentNode = queue.front();
            queue.pop();
            // add values to string
            if (currentNode != nullptr)
            {
                result += to_string(currentNode->val) + " "; // space as delimiter to separate the values
                queue.push(currentNode->left);
                queue.push(currentNode->right);
            }
            else
            {
                result += "n ";// null node
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        vector<int> nums;
        int i = 0;
        while (i < data.length())
        {
            // Skip space
            while (data[i] == ' ')
            {
                i++;
            }

            // handle null case
            if (data[i] == 'n')
            {
                nums.push_back(INT_MIN); // null will be stored as INT_MIN
                i++;
                continue;
            }

            // get the sign of a number
            int sign = 1;
            if (data[i] == '-')
            {
                sign = -1;
                i++;
            }

            int n = 0;
            while (i < data.length() && data[i] != ' ')
            {
                n = n * 10 + (data[i] - '0'); // Convert char to int
                i++;
            }

            nums.push_back(sign * n);
        }

        return buildTree(nums);
    }
    TreeNode *buildTree(vector<int> &nums)
    {
        int n = nums.size();
        // INT_MIN = null node
        if (n == 0 || nums[0] == INT_MIN)
        {
            return nullptr;
        }

        queue<TreeNode *> queue;
        TreeNode *root = new TreeNode(nums[0]);
        queue.push(root);
        int i = 0; // zero based indexing
        // left = 2 * i + 1
        // right = 2 * i + 2

        while (!queue.empty())
        {
            TreeNode *currentNode = queue.front();
            queue.pop();

            if (currentNode != nullptr && (2 * i + 1) < n)
            {
                int lc = nums[2 * i + 1]; // 2k
                int rc = (2 * i + 2) < n ? nums[(2 * i + 2)] : INT_MIN;
                // INT_MIN = null node
                if (lc != INT_MIN)
                {
                    currentNode->left = new TreeNode(lc);
                    queue.push(currentNode->left);
                }
                if (rc != INT_MIN)
                {
                    currentNode->right = new TreeNode(rc);
                    queue.push(currentNode->right);
                }
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));