// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/pascals-triangle/description/
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
                    // res[i][j]=1;// throws runtime error, be careful
                    res[i].push_back(1);
                }
                else
                {
                    res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
                }
            }
        }

        return res;
    }
};

void printPascalsTriangle(const int n)
{
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }

    // print the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    printPascalsTriangle(5);
    return 0;
}