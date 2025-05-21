// https://leetcode.com/problems/valid-triangle-number/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int vt = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 1; i > 1; i--)
        {
            int l = 0;
            int r = i - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum > nums[i])
                {
                    vt += (r - l);
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return vt;
    }
};