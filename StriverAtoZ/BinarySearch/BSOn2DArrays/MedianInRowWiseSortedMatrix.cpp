// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
#include <vector>
#include <algorithm>
using namespace std;

// Time = O(32 × R × log C) → simplified as O(R × log C)
// log₂(1e9) ≈ log₂(2³⁰) ≈ 30 to 32 constant
class Solution
{
public:
    // Helper to count elements <= target in the entire matrix
    int countLessEqual(const vector<vector<int>> &mat, int target)
    {
        int count = 0;
        for (const auto &row : mat)
        {
            count += upper_bound(row.begin(), row.end(), target) - row.begin();
        }
        return count;
    }

    int median(vector<vector<int>> &mat)
    {
        int R = mat.size();
        int C = mat[0].size();
        int start = 1, end = 1e9;
        int desired = (R * C + 1) / 2;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            int count = countLessEqual(mat, mid);

            if (count < desired)
                start = mid + 1;
            else
                end = mid;
        }

        return start;
    }
};
