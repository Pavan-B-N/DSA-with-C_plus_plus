// https://leetcode.com/problems/rotate-image/
#include <vector>
using namespace std;

// time complexity = O(n^2)
// space complexity = O(1)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        //  transpose matrix
        for (int i = 0; i < n; i++)
        {
            // we can start j from i or i+1, because matrix[i][i] never changes
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Observation: each row is placed at (n-1-i)th column
class Solution
{
public:
    // time complexity = O(n^2)
    // Space complexity = O(n^2)
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        // process and store
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[j][n - i - 1] = matrix[i][j];
            }
        }

        // rewrite matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = ans[i][j];
            }
        }
    }
};