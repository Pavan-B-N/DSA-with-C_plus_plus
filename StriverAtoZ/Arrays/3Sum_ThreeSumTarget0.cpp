// https://leetcode.com/problems/3sum/
#include <vector>
#include <algorithm>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3)
        {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // skip duplicate left
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    // skip duplicate right
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
        return ans;
    }
};