// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
#include "Node.h"
#include <vector>
#include <stack>
using namespace std;

// Time complexity: O(N + M)
// Space complexity: O(H1 + H2)
class Solution
{
public:
    vector<int> merge(Node *root1, Node *root2)
    {
        stack<Node *> s1, s2;
        vector<int> result;

        while (root1 || root2 || !s1.empty() || !s2.empty())
        {
            // Push all left nodes of root1
            while (root1)
            {
                s1.push(root1);
                root1 = root1->left;
            }
            // Push all left nodes of root2
            while (root2)
            {
                s2.push(root2);
                root2 = root2->left;
            }

            // Decide which node to process
            Node *top1 = s1.empty() ? nullptr : s1.top();
            Node *top2 = s2.empty() ? nullptr : s2.top();

            if (top2==nullptr || (top1 && top1->data <= top2->data))
            {
                result.push_back(top1->data);
                s1.pop();
                root1 = top1->right;
            }
            else
            {
                result.push_back(top2->data);
                s2.pop();
                root2 = top2->right;
            }
        }

        return result;
    }
};

// inorder traversal  O(N + M)
// Merge two sorted arrays → O(N + M) time.
// Time complexity: O(N + M)
// Space complexity: O(N + M) (due to storing entire inorder arrays)
class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> arr1;
        vector<int> arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);

        return mergeArray(arr1, arr2);
    }

    vector<int> mergeArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> res;
        int i = 0;
        int j = 0;
        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] < arr2[j])
            {
                res.push_back(arr1[i++]);
            }
            else
            {
                res.push_back(arr2[j++]);
            }
        }
        while (i < arr1.size())
        {
            res.push_back(arr1[i++]);
        }
        while (j < arr2.size())
        {
            res.push_back(arr2[j++]);
        }
        return res;
    }

    void inorder(Node *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
};