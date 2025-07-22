// https://leetcode.com/problems/pascals-triangle/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows);

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || i == j)
                {
                    // res[i][j]=1;, this won't work due to vector dynamic allocation
                    res[i].push_back(1);
                }
                else
                {
                    int value = res[i - 1][j] + res[i - 1][j - 1];
                    // res[i][j]=value;
                    res[i].push_back(value);
                }
            }
        }

        return res;
    }
};