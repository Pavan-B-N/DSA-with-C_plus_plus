// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include <climits>
#include <algorithm>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = INT_MIN;
int maxPathSum(TreeNode *root)
{
    helper(root);
    return ans;
}

int helper(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = helper(root->left);
    int right = helper(root->right);
    left = max(0, left);
    right = max(0, right);
    int pathsum = left + right + root->val;

    ans = max(ans, pathsum);
    return max(left, right) + root->val;
}