/*
Input:
1 2 3
4 5 6
7 8 9

After transpose:
1 4 7
2 5 8
3 6 9

After reversing each row:
7 4 1
8 5 2
9 6 3

*/
// https://leetcode.com/problems/rotate-image/description/
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // Step 1: Transpose the matrix
        // row becomes column
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (auto &row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};