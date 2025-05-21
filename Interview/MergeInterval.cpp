// https://leetcode.com/problems/merge-intervals/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int start = arr[i][0];
            int end = arr[i][1];

            // Merge intervals as long as they overlap
            while (i + 1 < n && arr[i + 1][0] <= end)
            {
                end = max(end, arr[i + 1][1]);
                i++;
            }

            res.push_back({start, end});
        }

        for (const auto &interval : res)
        {
            cout << interval[0] << ", " << interval[1] << endl;
        }

        return res;
    }
};