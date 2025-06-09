// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include <vector>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int index = -1;
        int max1s = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int ones = arr[i].size() - (lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin());
            if (ones > max1s)
            {
                max1s = ones;
                index = i;
            }
        }

        return index;
    }
};
