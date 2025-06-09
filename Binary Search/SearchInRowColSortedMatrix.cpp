// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <vector>
using namespace std;

class Solution
{
public:
    // O(m+n)
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (target < matrix[row][col])
            {
                // matrix is sorted  in arc manner from last
                col--;
            }
            else
            {
                row++;
            }
        }

        return false;
    }
};