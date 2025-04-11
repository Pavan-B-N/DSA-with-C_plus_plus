/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {}; 
    
    map<int, vector<int>> verticalMap; // col, list of node values
    queue<pair<TreeNode*, int>> q; // Node, col = horizontal size
    q.push({root, 0}); // Push the root node along with its vertical level
    
    while (!q.empty()) {
        int levelSize = q.size();
        map<int, vector<int>> levelMap; // Map to store nodes at each level
        
        // Traverse nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();
            
            levelMap[col].push_back(node->val); // Store the node value at the current level
            
            // Push left child with updated column (col - 1)
            if (node->left) q.push({node->left, col - 1});
            // Push right child with updated column (col + 1)
            if (node->right) q.push({node->right, col + 1});
        }
        
        // Merge nodes from the levelMap into verticalMap
        for (auto& it : levelMap) {
            auto& vec = it.second;
            sort(vec.begin(), vec.end()); // Sort the nodes at the current level
            verticalMap[it.first].insert(verticalMap[it.first].end(), vec.begin(), vec.end()); // Merge nodes into verticalMap
        }
    }
    
    vector<vector<int>> result;
    // Construct the result from verticalMap
    for (auto& it : verticalMap) {
        result.push_back(it.second); // Push nodes from verticalMap into the result
    }
    
    return result;
}


// Helper function to create a binary tree
TreeNode *createTree(vector<int> &values, int idx)
{
    if (idx >= values.size() || values[idx] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(values[idx]);
    root->left = createTree(values, 2 * idx + 1);
    root->right = createTree(values, 2 * idx + 2);
    return root;
}

// Helper function to deallocate memory of the binary tree
void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    // Example usage
    vector<int> values = {3, 9, 20, -1, -1, 15, 7}; // Example binary tree
    TreeNode *root = createTree(values, 0);

    vector<vector<int>> result = verticalTraversal(root);
    /*
        9 3 15 20 7 
    */

    // Output the result
    for (auto &col : result)
    {
        for (int val : col)
        {
            cout << val << " ";
        }
    }

    // Deallocate memory
    deleteTree(root);

    return 0;
}