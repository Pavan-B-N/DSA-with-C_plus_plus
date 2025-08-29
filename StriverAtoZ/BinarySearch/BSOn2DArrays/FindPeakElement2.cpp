// https://leetcode.com/problems/find-a-peak-element-ii/
#include <vector>
using namespace std;

///   m*n matrix

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int midCol = left + (right - left) / 2;

            // Find the row with max element in midCol
            int maxRow = 0;
            for (int row = 1; row < m; ++row)
            {
                if (mat[row][midCol] > mat[maxRow][midCol])
                {
                    maxRow = row;
                }
            }

            int curr = mat[maxRow][midCol];
            int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol < n - 1) ? mat[maxRow][midCol + 1] : -1;

            // Check if current is a peak
            if (curr > leftVal && curr > rightVal)
            {
                return {maxRow, midCol};
            }

            // Move to the side with greater neighbor
            if (rightVal > curr)
            {
                left = midCol + 1;
            }
            else
            {
                right = midCol - 1;
            }
        }

        return {-1, -1}; // Should never happen due to problem constraints
    }
};
