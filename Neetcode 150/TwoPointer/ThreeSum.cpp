// https://leetcode.com/problems/3sum/description/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3)
        {
            return res;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue; // Skip duplicates to avoid duplicate triplets
            }
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // skip duplicates
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return res;
    }
};