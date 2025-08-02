// https://www.naukri.com/code360/problems/row-with-maximum-1-s_1112656?leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxOnesRow = -1;
    int maxOnes = 0;
    for (int row = 0; row < n; row++)
    {
        int idx = lower_bound(matrix[row].begin(), matrix[row].end(), 1) - matrix[row].begin();
        int onesCount = matrix[row].size() - idx;
        if (onesCount > maxOnes)
        {
            maxOnes = onesCount;
            maxOnesRow = row;
        }
    }
    return maxOnesRow;
}