// https://leetcode.com/problems/spiral-matrix/
#include <vector>
using namespace std;

// time complexity = O(m*n)
// space complexity = O(1) excluding output
// space complexity = O(n) including output
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        vector<int> res;
        while (top <= bottom && left <= right)
        {
            // top row
            for (int j = left; j <= right; j++)
            {
                res.push_back(matrix[top][j]);
            }
            top++;

            // right col
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;

            // bottom row
            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                {
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // left col
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};