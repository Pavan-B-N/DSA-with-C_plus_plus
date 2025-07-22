// https://leetcode.com/problems/4sum/
#include <vector>
#include <algorithm>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            // skip duplicates of i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                // skip duplicates of j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right)
                {
                    // total sum could overflow the signed integer so always use long long
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // skip duplicate of left
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        // skip duplicate of right
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

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
        }
        return ans;
    }
};