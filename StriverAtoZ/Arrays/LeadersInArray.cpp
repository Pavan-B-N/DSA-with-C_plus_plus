// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// https://www.naukri.com/code360/problems/leaders-in-an-array_873144?leftPanelTabValue=PROBLEM
// leaders in an array
/*
{7, 10, 4, 3, 6, 5, 2}
10 6 5 2 are said to be leaders because they are greatest from their right side
*/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        int n = arr.size();
        int maxRight = INT_MIN;
        vector<int> res;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= maxRight)
            {
                maxRight = arr[i];
                res.push_back(maxRight);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};